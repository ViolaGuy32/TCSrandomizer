#include <wx/wx.h>
#include <array>
#include <sstream>
#include "Functions.h"
#include "App.h"
#include "Defines.h"

extern std::string out;

void getfile(std::string file, std::vector<std::string>& contents) {

	std::ifstream reader(file);
	std::string s;

	if (reader.fail()) {
		wxGetApp().CallAfter([file]() {
			wxString err = "File not found: " + file;
		wxLogStatus(err);
			});
	}
	while (getline(reader, s)) {
		contents.push_back(s);
	}
	return;
}

//void rgbTemp(std::string file, rgb color, int ID) {
//	int address = 0x31CC40 + (0x2c4 * ID) + 0x54;
//
//	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
//	fs.seekp(address);
//	fs << (float)color.r;
//	fs.seekp(address + 2);
//	fs << (float)color.g;
//	fs.seekp(address + 4);
//	fs << (float)color.b;
//
//}


void rgbWrite(std::string file, rgb color, int address) {
	std::fstream fs(file, std::ios::in | std::ios::binary);
	std::fstream lg;

	lg.open("files/logger", std::ios::in | std::ios::app);

	char temp;
	fs.seekg(address);
	fs.get(temp);
	lg << std::hex << temp;

	fs.seekg(address + 1);
	fs.get(temp);
	lg << std::hex << temp;


	fs.seekg(address + 2);
	fs.get(temp);
	lg << std::hex << temp;


	//fs.seekp(address+1);
	//lg << ((char*)fs.get());

	//fs.seekp(address+2);
	//lg << ((char*)fs.get());

	lg << '\0' << '\0' << '\0' << '\0' << '\0';
	fs.close();
	lg.close();
}

void rXgbWrite(std::string file, rgb color, int address) {
	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
	fs.seekp(address);
	fs << color.r;
	//fs.seekp(address + 1);
	fs << color.g;
	//fs.seekp(address + 2);
	fs << color.b;
	fs.close();
}

void binaryWrite(std::string file, char bin, int address) {
	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
	fs.seekp(address);
	fs << bin;
	fs.close();
}

void rgbBatch(std::string file, rgb color, std::vector<int> IDs) {
	for (int x : IDs) rgbWrite(file, color, x);
}

void rgbFloat(std::string file, rgb color, int address) {
	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
	fs.seekp(address);
	fs.write((char*)&color.rF, 4);
	//fs.seekp(address + 4);
	fs.write((char*)&color.gF, 4);
	//fs.seekp(address + 8);
	fs.write((char*)&color.bF, 4);
	fs.close();
}

void hexWrite(std::string file, std::string newWrite, int address, int len, bool trailingNull) {
#ifdef _DEBUG
	wxGetApp().CallAfter([&file, &newWrite, &address]() {
		wxString log = file + " " + newWrite + " " + std::to_string(address);
	wxLogStatus(log);
		});
#endif

	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
	unsigned int i = 0;
	while (i < newWrite.length()) {
		fs.seekp(address + i);
		fs << char(newWrite[i]);
		i++;
	}
	while (i < len) {
		fs.seekp(address + i);
		fs << char('\0');
		i++;
	}
	if (trailingNull) {
		fs.seekp(address + i);
		fs << char('\0');
	}
	fs.close();
}

//for hex longer than 1 byte
void binaryWrite(std::string file, std::string bin, int address) {
	std::basic_string<uint8_t> bytes;
	for (int i = 0; i < bin.length(); i += 2) {
		uint16_t cByte;
		std::string nextByte = bin.substr(i, 2);
		std::istringstream(nextByte) >> std::hex >> cByte;
		bytes.push_back(static_cast<uint8_t>(cByte));
	}
	std::string result(begin(bytes), end(bytes));
	hexWrite(file, result, address, 0, false);
}

int readEXE(int address) {
	std::ifstream is(EXE, std::ios::in | std::ios::binary);
	is.seekg(address);
	int val = 0;
	is.read((char*)&val, sizeof(val));
	//is.get(val, 4);
	return val;
}

void numWrite(std::string file, int newWrite, int address) {
	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);

	fs.seekp(address);
	fs.write((char*)&newWrite, sizeof(newWrite));
	fs.close();
}

void deleteLines(std::string file, std::vector<int> lines) {

	std::vector<std::string> contents;
	getfile(file, contents);
	for (int x : lines) {
	#ifdef _DEBUG
		wxGetApp().CallAfter([&file, &x]() {
			wxString log = "deleting " + file + " " + std::to_string(x).c_str();
		wxLogStatus(log);
			});
	#endif

		contents[x - 1] = "";

	}

	std::ofstream fileout(file);
	for (std::string y : contents) {
		fileout << y + "\n";
	}
	fileout.close();

}

void txtIns(std::string file, std::string newC, std::vector<coord> lnCol, int len) {
#ifdef _DEBUG
	wxGetApp().CallAfter([&file, &newC, &len]() {
		wxString log = file + " " + newC + " " + std::to_string(len).c_str();
	wxLogStatus(log);
		});
#endif

	std::vector<std::string> contents;
	getfile(file, contents);
	for (coord x : lnCol) {
		contents[x.ln - 1].replace(x.col - 1, len, newC);

	}

	std::ofstream fileout(file);
	for (std::string y : contents) {
		fileout << y + "\n";
	}
	fileout.close();

}

void appendFile(std::string file, std::string appendix) {
#ifdef _DEBUG
	wxGetApp().CallAfter([file]() {
		wxString log = "appending" + file;
	wxLogStatus(log);
		});
#endif

	std::vector<std::string> contents;
	getfile(file, contents);
	contents.push_back(appendix);

	std::ofstream fileout(file);
	for (std::string y : contents) {
		fileout << y + "\n";
	}
	fileout.close();

}



//void OLDtxtIns(std::string file, std::string newC, std::vector<coord> lnCol, int len = 0) {
//	//lnCol must be in order
//
//	std::ifstream filein(file);
//
//	//switch to arrays
//	std::vector<std::string> contents = getfile(file);
//	std::vector<std::string> output;
//	unsigned int i = 1;
//	unsigned int j = 0;
//	for (std::string x : contents) {
//
//
//		if (i < contents.size()) {
//			//wxstd::string temp = (wxstd::string) file + " " + to_std::string(i) + ", " + to_std::string(j) + " " + newC;
//			//wxLogStatus(temp);
//			while (j < lnCol.size() && i == lnCol[j].ln) {
//				x.replace(lnCol[j].col - 1, len, newC);
//
//				j++;
//			}
//		}
//		output.push_back(x + "\n");
//		i++;
//	}
//	filein.close();
//
//	ofstream fileout(file);
//	for (std::string y : output) {
//		fileout << y;
//	}
//	fileout.close();
//
//}
//void txtIns(std::string file, std::string newC, int* coord, int len = 0) {
//	//coord must be in order
//	wxLogStatus("txtIns");
//
//	std::ifstream filein(file);
//
//	//switch to arrays
//	std::vector<std::string> contents = getfile(file);
//	std::vector<std::string> output;
//	unsigned int i = 1;
//	unsigned int j = 0;
//	for (std::string x : contents) {
//		wxstd::string temp = to_std::string(i);
//		wxLogStatus(temp);
//
//		if (i < contents.size()) {
//			if (i == coord[j]) {
//				x.replace(0, len, newC);
//				j++;
//
//			}
//		}
//		output.push_back(x + "\n");
//		i++;
//	}
//	filein.close();
//
//	ofstream fileout(file);
//	for (std::string y : output) {
//		fileout << y;
//	}
//	fileout.close();
//
//}

rgb::rgb() {
	r = rand() % 0xFF;
	g = rand() % 0xFF;
	b = rand() % 0xFF;

	rF = (float)r / 255.0f;
	gF = (float)g / 255.0f;
	bF = (float)b / 255.0f;
}

coord::coord() {}

coord::coord(int myLn) : ln(myLn) {}

coord::coord(int myLn, int myCol) : ln(myLn), col(myCol) {}

