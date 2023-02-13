#include <wx/wx.h>
#include <array>
#include <sstream>
#include <filesystem>
#include "OtherStuff.h"
#include "App.h"
#include "Defines.h"
#include "Characters.h"

extern Level* currentLev;
extern std::string out;

void getfile(const std::string& file, std::vector<std::string>& contents) {

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

writeSingle::writeSingle(const std::string myStr, const unsigned int myLen, const coord myLnCol)
	: newStr(myStr), len(myLen), lnCol(myLnCol) {
}
writeSingle::writeSingle(const int chNum, const coord myLnCol, const std::vector<Playable*> Level::* chType)
	: newStr(getName(chNum, chType)), len(getVanilla(chNum, chType).length()), lnCol(myLnCol) {
}
writeSingle::writeSingle(const int chNum, const unsigned int line, const std::vector<Playable*> Level::* chType)
	: newStr(getName(chNum, chType)), len(getVanilla(chNum, chType).length()), lnCol({line, 1}) {
}

writeSet::writeSet(const std::string myStr, const unsigned int myLen, const std::initializer_list<const coord> myLnCol)
	: newStr(myStr), len(myLen), lnCol(myLnCol) {
}

writeSet::writeSet(const int chNum, const std::initializer_list<const coord> myLnCol, const std::vector<Playable*> Level::* chType)
	: newStr(getName(chNum, chType)), len(getVanilla(chNum, chType).length()), lnCol(myLnCol) {
};
//
////void rgbTemp(std::string file, rgb color, int ID) {
////	int address = 0x31CC40 + (0x2c4 * ID) + 0x54;
////
////	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
////	fs.seekp(address);
////	fs << (float)color.r;
////	fs.seekp(address + 2);
////	fs << (float)color.g;
////	fs.seekp(address + 4);
////	fs << (float)color.b;
////
////}
//
//void rgbWrite(const std::string& file, const rgb color, const int address) {
//	std::fstream fs(file, std::ios::in | std::ios::binary);
//	std::fstream lg;
//
//	lg.open("files/logger", std::ios::in | std::ios::app);
//
//	char temp;
//	fs.seekg(address);
//	fs.get(temp);
//	lg << std::hex << temp;
//
//	fs.seekg(address + 1);
//	fs.get(temp);
//	lg << std::hex << temp;
//
//
//	fs.seekg(address + 2);
//	fs.get(temp);
//	lg << std::hex << temp;
//
//
//	//fs.seekp(address+1);
//	//lg << ((char*)fs.get());
//
//	//fs.seekp(address+2);
//	//lg << ((char*)fs.get());
//
//	lg << '\0' << '\0' << '\0' << '\0' << '\0';
//	fs.close();
//	lg.close();
//}
//
//void rXgbWrite(const std::string& file, rgb color, int address) {
//	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
//	fs.seekp(address);
//	fs << color.r;
//	//fs.seekp(address + 1);
//	fs << color.g;
//	//fs.seekp(address + 2);
//	fs << color.b;
//	fs.close();
//}
//
//void binaryWrite(const std::string& file, const char bin, const int address) {
//	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
//	fs.seekp(address);
//	fs << bin;
//	fs.close();
//}
//
//void rgbBatch(const std::string& file, const rgb color, const std::vector<int>& IDs) {
//	for (int x : IDs) rgbWrite(file, color, x);
//}
//
//void rgbFloat(const std::string& file, const rgb color, const int address) {
//	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
//	fs.seekp(address);
//	fs.write((char*)&color.rF, 4);
//	//fs.seekp(address + 4);
//	fs.write((char*)&color.gF, 4);
//	//fs.seekp(address + 8);
//	fs.write((char*)&color.bF, 4);
//	fs.close();
//}
//
//void hexWrite(const std::string& file, const std::string& newWrite, const int address, const int len, const bool trailingNull) {
//#ifdef _DEBUG
//	wxGetApp().CallAfter([&file, &newWrite, &address]() {
//		wxString log = file + " " + newWrite + " " + std::to_string(address);
//	wxLogStatus(log);
//	});
//#endif
//
//	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
//	unsigned int i = 0;
//	while (i < newWrite.length()) {
//		fs.seekp(address + i);
//		fs << char(newWrite[i]);
//		i++;
//	}
//	while (i < len) {
//		fs.seekp(address + i);
//		fs << char('\0');
//		i++;
//	}
//	if (trailingNull) {
//		fs.seekp(address + i);
//		fs << char('\0');
//	}
//	fs.close();
//}
//
////for hex longer than 1 byte
//void binaryWrite(const std::string& file, const std::string& bin, const int address) {
//	std::basic_string<uint8_t> bytes;
//	std::string nextByte;
//	for (int i = 0; i < bin.length(); i += 2) {
//		uint16_t cByte;
//		nextByte = bin.substr(i, 2);
//		std::istringstream(nextByte) >> std::hex >> cByte;
//		bytes.push_back(static_cast<uint8_t>(cByte));
//	}
//	const std::string result(begin(bytes), end(bytes));
//	hexWrite(file, result, address, 0, false);
//}
//
//int readEXE(const int address) {
//	std::ifstream is(EXE, std::ios::in | std::ios::binary);
//	is.seekg(address);
//	int val = 0;
//	is.read((char*)&val, sizeof(val));
//	//is.get(val, 4);
//	return val;
//}
//
//void numWrite(const std::string& file, const int newWrite, const int address) {
//	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
//
//	fs.seekp(address);
//	fs.write((char*)&newWrite, sizeof(newWrite));
//	fs.close();
//}


//void deleteLines(const std::string& file, const std::initializer_list<const unsigned int>& lines) {
//	//deletes lines from file
//	std::vector<std::string> contents;
//	getfile(file, contents);
//
//	for (int x : lines) {
//	#ifdef _DEBUG
//		wxGetApp().CallAfter([&file, &x]() {
//			wxString log = "deleting " + file + " " + std::to_string(x).c_str();
//		wxLogStatus(log);
//		});
//	#endif
//
//		contents[x - 1] = "";
//
//	}
//
//	std::ofstream fileout(file);
//	for (const std::string y : contents) {
//		fileout << y + "\n";
//	}
//	fileout.close();
//}
//
//void txtIns(const std::string& file, const std::string& newC, const std::initializer_list<coord>& lnCol, const int len) {
//#ifdef _DEBUG
//	wxGetApp().CallAfter([&file, &newC, &len]() {
//		wxString log = file + " " + newC + " " + std::to_string(len).c_str();
//	wxLogStatus(log);
//	});
//#endif
//
//	std::vector<std::string> contents;
//	getfile(file, contents);
//	for (coord x : lnCol)
//		contents[x.ln - 1].replace(x.col - 1, len, newC);
//
//
//	std::ofstream fileout(file);
//	for (const std::string y : contents)
//		fileout << y + "\n";
//
//	fileout.close();
//
//}
//void txtIns(const std::string& file, const std::string& newC, const coord lnCol, const int len) {
//	txtIns(file, newC, {lnCol}, len);
//}
//
//void batchTxt(const std::string& file, const std::initializer_list<writeSet> stuff) {
//	//this one is faster
//	std::vector<std::string> contents;
//	getfile(file, contents);
//
//	for (writeSet thing : stuff)
//		for (coord x : thing.lnCol)
//			contents[x.ln - 1].replace(x.col - 1, thing.len, thing.newStr);
//
//
//	std::ofstream fileout(file);
//	for (const std::string y : contents)
//		fileout << y + "\n";
//
//	fileout.close();
//}
//
//void batchPlayerTxt(const std::string& file, const std::initializer_list<writePlayerSet> stuff) {
//
//	std::vector<std::string> contents;
//	getfile(file, contents);
//
//	for (writePlayerSet thing : stuff) {
//		for (coord x : thing.lnCol) {
//			contents[x.ln - 1].replace(x.col - 1, currentLev->vanillaMap[currentLev->*thing.chType][thing.characterNum]->name.length(),
//				(currentLev->*thing.chType)[thing.characterNum]->name);
//		}
//	}
//
//	std::ofstream fileout(file);
//	for (const std::string y : contents)
//		fileout << y + "\n";
//
//	fileout.close();
//}
//
//void batchSinglePlayerTxt(const std::string& file, const std::initializer_list<writePlayerSingle> stuff) {
//	//this one is faster
//	std::vector<std::string> contents;
//	getfile(file, contents);
//
//	for (writePlayerSingle thing : stuff) {
//		contents[thing.lnCol.ln - 1].replace(thing.lnCol.col - 1, currentLev->vanillaMap[currentLev->*thing.chType][thing.characterNum]->name.length(),
//			(currentLev->*thing.chType)[thing.characterNum]->name);
//	}
//
//	std::ofstream fileout(file);
//	for (const std::string y : contents)
//		fileout << y + "\n";
//
//	fileout.close();
//}

//template <typename C, typename W>
//void writer(void(*fun)(std::initializer_list<C>&, std::vector<std::string>&),
//	const std::string& file, const std::initializer_list<W> stuff) {
//
//	std::vector<std::string> contents;
//	getfile(file, contents);
//
//	fun(stuff, contents);
//
//	std::ofstream fileout(file);
//	for (const std::string y : contents)
//		fileout << y + "\n";
//
//	fileout.close();
//}

template <typename FUN, typename W>
void writer(const FUN fun, const std::string& file, const W stuff) {

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (const std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void fileDeleter(const char scene, const int characterNum, std::vector<Playable*> Level::* chType) {
	//deletes file
	std::remove(getSCP(currentLev, scene, getVanilla(characterNum, chType)).c_str());
};

void oneWrite(const writeSingle& wrt, std::vector<std::string>& contents) {
	//alters one line in file
	contents[wrt.lnCol.ln - 1].replace(wrt.lnCol.ln - 1, wrt.len, wrt.newStr);
}

void multiWrite(std::initializer_list<writeSingle>& stuff, std::vector<std::string>& contents) {
	//alters multiple parts of file without repeats
	for (writeSingle thing : stuff)
		contents[thing.lnCol.ln - 1].replace(thing.lnCol.col - 1, thing.len, thing.newStr);

}

void manyWrite(std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents) {
	//alters multiple parts of file with repeats
	for (writeSet thing : stuff) {
		for (coord lc : thing.lnCol) {
			contents[lc.ln - 1].replace(lc.col - 1, thing.len, thing.newStr);
		}
	}
}

void appender(const std::string& appendix, std::vector<std::string>& contents) {
	//appends file with more text
	contents.push_back(appendix);

};

void lineDel(const std::initializer_list<const unsigned int>lines, std::vector<std::string>& contents) {
	//sets line to empty string; actually deleting them would offset coordinates
	for (const unsigned int& ln : lines) contents[ln - 1] = "";
}

//
//void appendFile(const std::string& file, const std::string& appendix) {
//#ifdef _DEBUG
//	wxGetApp().CallAfter([file]() {
//		wxString log = "appending" + file;
//	wxLogStatus(log);
//	});
//#endif
//
//	std::vector<std::string> contents;
//	getfile(file, contents);
//	contents.push_back(appendix);
//
//	std::ofstream fileout(file);
//	for (std::string& y : contents) {
//		fileout << y + "\n";
//	}
//	fileout.close();
//
//}

//gets path for various types of files

std::string getBasePath(const Level* lev, const char scene, const std::string& fileType) {
	return out + lev->path + lev->shortName + '_' + scene + '/' + lev->shortName + '_' + scene + "." + fileType;
}

std::string getMainTxt(const Level* lev) {
	return out + lev->path + lev->name + ".TXT";
}

std::string getGiz(const Level* lev, const char scene) {
	return out + lev->path + lev->shortName + '_' + scene + '/' + lev->shortName + '_' + scene + ".GIZ";
}

std::string getGit(const Level* lev, const const char scene) {
	return out + lev->path + lev->shortName + '_' + scene + '/' + lev->shortName + '_' + scene + ".GIT";
}

std::string getSceneTxt(const Level* lev, const const char scene) {
	return out + lev->path + lev->shortName + '_' + scene + '/' + lev->shortName + '_' + scene + ".TXT";
}

std::string getSCP(const Level* lev, const char scene, const std::string& script) {
	return out + lev->path + lev->shortName + '_' + scene + "/AI/" + script + ".SCP";
}

std::string getScriptTxt(const Level* lev, const char scene) {
	return out + lev->path + lev->shortName + '_' + scene + "/AI/" + lev->shortName + '_' + scene + ".TXT";
}

void renamer(const std::string& oldName, const std::string& newName) {
	//renames file
	int test = rename(oldName.c_str(), newName.c_str());
	if (test == -1) {
		wxString err = "File name override failed: " + oldName + " -> " + newName;
		wxGetApp().CallAfter([err]() {
			wxLogError(err);
		});
	}
}

std::string getName(const unsigned int characterNum, const std::vector<Playable*> Level::* chType) {
	//gets name of character
	return (currentLev->*chType)[characterNum]->name;
}

std::string getVanilla(const unsigned int characterNum, const std::vector<Playable*> Level::* chType) {
	//gets name of character to be replaced
	return currentLev->vanillaMap[currentLev->*chType][characterNum]->name;
}

void playerInit(std::initializer_list<writeSingle> writers) {
	//replaces characters in the main level txt
	//std::vector<writeSingle> writ;
	/*for (basicCh w : writers) {
		writ.push_back(writeSingle{getName(w.chNum, w.chType), getVanilla(w.chNum, w.chType).length(), {w.line, 12}});
	}*/

	for (writeSingle& x : writers) x.lnCol.col = 12;

	writer(multiWrite, getMainTxt(currentLev), writers);
};

void mainTxtIns(const std::string& txt, const unsigned int len, const coord lnCol) {
	writer(oneWrite, getMainTxt(currentLev), writeSingle(txt, len, lnCol));
}

void scpIns(const char scene, const std::string& script, const unsigned int chNum, const coord lnCol,
	const std::vector<Playable*> Level::* chType) {
	//replaces character in scp file

	writer(oneWrite, getSCP(currentLev, scene, script), writeSingle(chNum, lnCol, chType));
};

void scpRep(const char scene, const std::string& script, const std::string txt, const unsigned int len, const coord lnCol) {
	//replaces text in scp file
	writer(oneWrite, getSCP(currentLev, scene, script), writeSingle(txt, len, lnCol));
};

void scpRepMulti(const char scene, const std::string& script, const std::string txt, const unsigned int len,
	const std::initializer_list<const coord> lnCol) {
	//replaces text in scp file multiple times
	writer(oneWrite, getSCP(currentLev, scene, script), writeSet(txt, len, lnCol));
};

void scpRepMany(const char scene, const std::string& script, const std::initializer_list<const writeSet> writ) {
	writer(manyWrite, getSCP(currentLev, scene, script), writ);
}

void scpMulti(const char scene, const std::string& script, const unsigned int chNum, const std::initializer_list<const coord> lnCol,
	const std::vector<Playable*> Level::* chType) {
	//replaces character with multiple instances in same scp file
	writeSet writ(getName(chNum, chType), getVanilla(chNum, chType).length(), lnCol);
	writer(oneWrite, getSCP(currentLev, scene, script), writ);
};

void scpMany(const char scene, const std::string& script, std::initializer_list<advancedCh> writers) {
	//replaces multiple characters which each have multiple instances in scp file
	std::vector<writeSet> writ;
	for (advancedCh w : writers) {
		writ.push_back(writeSet{getName(w.chNum, w.chType), getVanilla(w.chNum, w.chType).length(), w.lnCol});
	}
	writer(manyWrite, getSCP(currentLev, scene, script), writ);
};

void scpName(const char scene, const unsigned int characterNum, const std::vector<Playable*> Level::* chType = &Level::party) {
	//renames scp file
	renamer(getSCP(currentLev, scene, getVanilla(characterNum, chType)),
		getSCP(currentLev, scene, getName(characterNum, chType)));
};

void scpAppend(const char scene, const std::string& script, const std::string& appendix) {
	//appends scp file
	writer(appender, getSCP(currentLev, scene, script), appendix);
}

void scriptTxtAppend(const char scene, const std::string& appendix) {
	//appends script.txt
	writer(appender, getScriptTxt(currentLev, scene), appendix);
}

void scriptTxt(const char scene, const int characterNum, const unsigned int line,
	std::vector<Playable*> Level::* chType) {
	//updates script.txt
	writer(oneWrite, getScriptTxt(currentLev, scene), writeSingle(characterNum, {line, 1}, chType));

	scpName(scene, characterNum);
};

void multiScriptTxt(const char scene, const std::initializer_list<const basicCh> write) {
	//updates script.txt
	std::vector<writeSet> writ;
	for (basicCh w : write) {
		writ.push_back(writeSet{getName(w.chNum, w.chType), getVanilla(w.chNum, w.chType).length(), {w.line, 1}});
		scpName(scene, w.chNum);
	}
	writer(manyWrite, getScriptTxt(currentLev, scene), writ);

};

void scriptTxtRep(const char scene, const std::string newStr, const std::string oldStr, const unsigned int line) {
	//replaces text in script.txt
	writer(oneWrite, getScriptTxt(currentLev, scene), writeSingle(newStr, oldStr.length(), {line, 1}));
	renamer(getSCP(currentLev, scene, oldStr),
		getSCP(currentLev, scene, newStr));
};

void lineDeleterScp(const char scene, const std::string& script, std::initializer_list<const unsigned int> lines) {
	writer(lineDel, getSCP(currentLev, scene, script), lines);
}

void scpDeleter(const char scene, const std::string& script) {
	std::remove(getSCP(currentLev, scene, script).c_str());
}

void baseFile(const char scene, const std::string& fileType, const unsigned int chNum, const coord lnCol,
	const std::vector<Playable*> Level::* chType) {
	writer(oneWrite, getBasePath(currentLev, scene, fileType), lnCol);
}

/*

void Level::rename(std::string newText, std::string oldText, char scene) {
	std::string file = episode + firstName + '/' + name + '_' + scene + "/AI/";
	renamer(file + oldText, file + newText);

}

void Level::rename(int characterNumber, char scene) {
	rename(party[characterNumber]->name + ".SCP", vanillaParty[characterNumber]->name + ".SCP", scene); //FIX
}
*/

//void OLDtxtIns(const std::string file, std::string newC, std::vector<coord> lnCol, int len = 0) {
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

//coord::coord() {}
//
//coord::coord(const unsigned int myLn) : ln(myLn) {}
//
//coord::coord(const unsigned int myLn, const unsigned int myCol) : ln(myLn), col(myCol) {}
