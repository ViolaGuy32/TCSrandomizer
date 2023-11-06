#include "pch.h"

//#ifdef WXWIN
//#include "App.h"
//#endif
#include "Characters.h"
#include "Defines.h"
#include "OtherStuff.h"
#include "externData.h"

extern Level* currentLev;
extern std::string out;

//extern std::unique_ptr<std::ofstream> loggingIt;

bool CIcompare(std::string first, std::string second) {
	transform(first.begin(), first.end(), first.begin(), ::tolower);
	transform(second.begin(), second.end(), second.begin(), ::tolower);

	return first == second;
}

void logR(std::string lg) {
	std::cout << lg << std::endl;
#ifdef _DEBUG
	//(*loggingIt) << lg << '\n';

	std::ofstream log2("files/log2.txt", std::ios_base::out | std::ios_base::app);
	log2 << lg << '\n';
	//wxLogStatus(lg.c_str());
#endif
}

void writer(void (*fun)(writeSingle, std::vector<std::string>&), std::string file, writeSingle stuff) {

#ifdef _DEBUG
	logR(file);
#endif

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void writer(void (*fun)(std::string, std::vector<std::string>&), std::string file, std::string stuff) {
#ifdef _DEBUG
	logR(file);
#endif

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void writer(void (*fun)(writeSet, std::vector<std::string>&), std::string file, writeSet stuff) {
#ifdef _DEBUG
	logR(file);
#endif

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void writer(void (*fun)(coord, std::vector<std::string>&), std::string file, coord stuff) {
#ifdef _DEBUG
	logR(file);
#endif

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void writer(void (*fun)(unsigned int, std::vector<std::string>&), std::string file, unsigned int stuff) {
#ifdef _DEBUG
	logR(file);
#endif

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void writer(void (*fun)(std::vector<unsigned int>, std::vector<std::string>&), std::string file,
	std::vector<unsigned int> stuff) {
#ifdef _DEBUG
	logR(file);
#endif

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void writer(
	void (*fun)(std::vector<writeSet>, std::vector<std::string>&), std::string file, std::vector<writeSet> stuff) {
#ifdef _DEBUG
	logR(file);
#endif

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void writer(void (*fun)(std::vector<coord>, std::vector<std::string>&), std::string file, std::vector<coord> stuff) {
#ifdef _DEBUG
	logR(file);
#endif

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void writer(void (*fun)(std::vector<writeSingle>, std::vector<std::string>&), std::string file,
	std::vector<writeSingle> stuff) {
#ifdef _DEBUG
	logR(file);
#endif

	std::vector<std::string> contents;
	getfile(file, contents);

	fun(stuff, contents);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void getfile(std::string file, std::vector<std::string>& contents) {

	std::ifstream reader(file);
	std::string s;

	if (reader.fail()) {
		logR("File not found: " + file);
	}
	while (getline(reader, s)) {
		contents.push_back(s);
	}
	reader.close();
	return;
}

std::string cdstr(coord cd) {
	return ("(" + std::to_string(cd.ln) + ", " + std::to_string(cd.col) + ")");
}

//
//std::ostream operator<<(coord lncol, std::ostream& os) {
//	os << "(" + std::to_string(lncol.ln) + ", " + std::to_string(lncol.col) + ")";
//}

writeSingle::writeSingle(std::string myStr, size_t myLen, coord myLnCol) : newStr(myStr), len(myLen), lnCol(myLnCol) {}

writeSingle::writeSingle(int chNum, coord myLnCol, std::vector<Playable*> Level::* chType)
	: newStr(getName(chNum, chType)), len(getVanilla(chNum, chType).length()), lnCol(myLnCol) {}

writeSingle::writeSingle(int chNum, unsigned int line, std::vector<Playable*> Level::* chType)
	: newStr(getName(chNum, chType)), len(getVanilla(chNum, chType).length()), lnCol({ line, 1 }) {}

writeSet::writeSet(std::string myStr, unsigned int myLen, std::vector<coord> myLnCol)
	: newStr(myStr), len(myLen), lnCol(myLnCol) {}

writeSet::writeSet(int chNum, std::vector<coord> myLnCol, std::vector<Playable*> Level::* chType)
	: newStr(getName(chNum, chType)), len(getVanilla(chNum, chType).length()), lnCol(myLnCol) {};

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
//void rgbWrite( std::string file,  rgb color,  int address) {
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
//void rXgbWrite( std::string file, rgb color, int address) {
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
//void rgbBatch( std::string file,  rgb color,  std::vector<int>& IDs) {
//	for (int x : IDs) rgbWrite(file, color, x);
//}
//
//void rgbFloat( std::string file,  rgb color,  int address) {
//	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
//	fs.seekp(address);
//	fs.write((char*)&color.rF, 4);
//	//fs.seekp(address + 4);
//	fs.write((char*)&color.gF, 4);
//	//fs.seekp(address + 8);
//	fs.write((char*)&color.bF, 4);
//	fs.close();
//}

void binaryWrite(std::string file, char bin, int address) {
	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
	fs.seekp(address);
	fs << bin;
	fs.close();
}

void hexWrite(std::string file, std::string newWrite, int address, int len, bool trailingNull) {
#ifdef _DEBUG
	if (trailingNull) logR(file + " " + newWrite + " " + std::to_string(address));
#endif

	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
	int i = 0;
	while (i < newWrite.length()) {
		fs.seekp(address + i);
		fs << char(newWrite[i]);
		i++;
	}
	if (trailingNull) {
		fs.seekp(address + i);
		fs << char('\0');
		i++;
	}
	while (i < len) {
		fs.seekp(address + i);
		fs << char('\0');
		i++;
	}
	fs.close();
}

//for hex longer than 1 byte
void binaryWrite(std::string file, std::string bin, int address) {
#ifdef _DEBUG
	logR(file + " 0x" + bin + " " + std::to_string(address));
#endif
	std::basic_string<uint8_t> bytes;
	std::string nextByte;
	for (int i = 0; i < bin.length(); i += 2) {
		uint16_t cByte;
		nextByte = bin.substr(i, 2);
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
	is.close();
	return val;
}

void numWrite(std::string file, int newWrite, int address) {
	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);

	fs.seekp(address);
	fs.write((char*)&newWrite, sizeof(newWrite));
	fs.close();
}

void ai2Write(char scene, std::string writ, std::initializer_list<int> address) {
	for (int a : address)
		hexWrite(getAI2(currentLev, scene), writ, a);
}

void ai2Write(char scene, int chNum, std::initializer_list<int> address, std::vector<Playable*> Level::* chType) {
	for (int a : address)
		hexWrite(getAI2(currentLev, scene), getName(chNum, chType), a);
}

//0xca35a
extern size_t addressPointer;
extern size_t junkCharacters;

//int junkCharacters = 0x3f1b74;

void characterPointer(Playable* play, int address) {
	if (play->address != 0x0) {
		numWrite(EXE, readEXE(play->address - 0x400000 + 0x4), address);
		//numWrite(EXE, play->address + 0x4, address);
	}
	else {
		hexWrite(EXE, play->name, addressPointer);
		numWrite(EXE, addressPointer + 0x400000, junkCharacters - 0x4);
		play->address = junkCharacters + 0x400000 - 0x4;

		numWrite(EXE, readEXE(play->address - 0x400000 + 0x4), address);
		//numWrite(EXE, play->address + 0x4, address);

		addressPointer += play->name.length() + 1;
		junkCharacters += 0x8;
		while (junkCharacters == 0x3f1bb4 || junkCharacters == 0x3f1b84 || junkCharacters == 0x3f1bac)
			junkCharacters += 0x8; //"whip" might not be unused and others are weird
	}
}

void multiPointer(Playable* play, std::vector<int> address) {
	if (play->address != 0x0) {
		for (int ad : address)
			numWrite(EXE, readEXE(play->address - 0x400000 + 0x4), ad);
	}
	else {
		hexWrite(EXE, play->name, addressPointer);
		numWrite(EXE, addressPointer + 0x400000, junkCharacters - 0x4);
		play->address = junkCharacters + 0x400000 - 0x4;

		for (int ad : address)
			numWrite(EXE, readEXE(play->address - 0x400000 + 0x4), ad);

		addressPointer += play->name.length() + 1;
		junkCharacters += 0x8;
		while (junkCharacters == 0x3f1bb4 || junkCharacters == 0x3f1b84 || junkCharacters == 0x3f1bac)
			junkCharacters += 0x8; //"whip" might not be unused and others are weird
	}
}

//void deleteLines( std::string file,  std::initializer_list<  int>& lines) {
//	//deletes lines from file
//	std::vector<std::string> contents;
//	getfile(file, contents);
//
//	for (int x : lines) {
//	#ifdef _DEBUG
//		wxGetApp().CallAfter([&file, &x]() {
//			wxString log = "deleting " + file + " " + std::to_string(x).c_str();
//		logR(log);
//		});
//	#endif
//
//		contents[x - 1] = "";
//
//	}
//
//	std::ofstream fileout(file);
//	for ( std::string y : contents) {
//		fileout << y + "\n";
//	}
//	fileout.close();
//}

void txtIns(std::string file, std::string newC, const std::initializer_list<coord>& lnCol, const int len) {
#ifdef _DEBUG
	logR(file + " " + newC + " " + std::to_string(len).c_str());
#endif

	std::vector<std::string> contents;
	getfile(file, contents);
	for (coord x : lnCol)
		contents[x.ln - 1].replace(x.col - 1, len, newC);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void txtIns(std::string file, std::string newC, const std::initializer_list<int>& lnCol, const int len) {
#ifdef _DEBUG

	logR(file + " " + newC + " " + std::to_string(len).c_str());

#endif

	std::vector<std::string> contents;
	getfile(file, contents);
	for (int x : lnCol)
		contents[x - 1].replace(0, len, newC);

	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();
}

void oneWrite(writeSingle wrt, std::vector<std::string>& contents) {
	//alters one line in file
#ifdef _DEBUG
	logR(wrt.newStr + ' ' + cdstr(wrt.lnCol) + ' ' + contents[wrt.lnCol.ln - 1]);
#endif

	contents[wrt.lnCol.ln - 1].replace(wrt.lnCol.col - 1, wrt.len, wrt.newStr);
}

void multiWrite(std::vector<writeSingle> stuff, std::vector<std::string>& contents) {
	//alters multiple parts of file without repeats
	for (writeSingle thing : stuff) {
#ifdef _DEBUG
		logR(thing.newStr + ' ' + cdstr(thing.lnCol) + ' ' + contents[thing.lnCol.ln - 1]);
#endif

		contents[thing.lnCol.ln - 1].replace(thing.lnCol.col - 1, thing.len, thing.newStr);
	}
}

void weirdWrite(writeSet stuff, std::vector<std::string>& contents) {
	//alters multiple parts of file without repeats
	for (coord lc : stuff.lnCol) {
#ifdef _DEBUG
		logR(stuff.newStr + ' ' + cdstr(lc) + ' ' + contents[lc.ln - 1]);
#endif

		contents[lc.ln - 1].replace(lc.col - 1, stuff.len, stuff.newStr);
	}
}

void manyWrite(std::vector<writeSet> stuff, std::vector<std::string>& contents) {
	//alters multiple parts of file with repeats
	for (writeSet thing : stuff) {
		for (coord lc : thing.lnCol) {
#ifdef _DEBUG
			logR(thing.newStr + ' ' + cdstr(lc) + ' ' + contents[lc.ln - 1]);
#endif

			contents[lc.ln - 1].replace(lc.col - 1, thing.len, thing.newStr);
		}
	}
}

void appender(std::string appendix, std::vector<std::string>& contents) {
	//appends file with more text
#ifdef _DEBUG
	logR(appendix + " appended");
#endif

	contents.push_back(appendix);
};

void lineDel(std::vector<unsigned int> lines, std::vector<std::string>& contents) {
	//sets line to empty string; actually deleting them would offset coordinates
	for (int ln : lines) {
#ifdef _DEBUG
		logR(std::to_string(ln) + ' ' + contents[ln - 1] + ' ' + " deleted.");
#endif

		contents[ln - 1] = "";
	}
}

void fileDeleter(char scene, int characterNum, std::vector<Playable*> Level::* chType) {
	//deletes file

	std::remove(getSCP(currentLev, scene, getVanilla(characterNum, chType)).c_str());
};

void appendFile(std::string file, std::string appendix) {
	//#ifdef _DEBUG
	//	wxGetApp().CallAfter([file]() {
	//		wxString log = "appending" + file;
	//	logR(log);
	//	});
	//#endif

	std::vector<std::string> contents;
	getfile(file, contents);
	contents.push_back(appendix);

	std::ofstream fileout(file);
	for (std::string y : contents) {
		fileout << y + "\n";
	}
	fileout.close();
}

//gets path for various types of files

std::string getBasePath(Level* lev, char scene, std::string fileType) {
	if (scene != '\0')
		return out + lev->path + lev->shortName + '_' + scene + '/' + lev->shortName + '_' + scene + "." + fileType;

	return out + lev->path + lev->shortName + '/' + lev->shortName + "." + fileType;
}

std::string getMainTxt(Level* lev) {
	return out + lev->path + lev->name + ".TXT";
}

std::string getSCP(Level* lev, char scene, std::string script) {
	return out + lev->path + lev->shortName + '_' + scene + "/AI/" + script + ".SCP";
}

std::string getAI2(Level* lev, char scene) {
	return out + lev->path + lev->shortName + '_' + scene + "/AI/" + lev->shortName + '_' + scene + ".AI2";
}

std::string getScriptTxt(Level* lev, char scene) {
	return out + lev->path + lev->shortName + '_' + scene + "/AI/SCRIPT.TXT";
}

void renamer(std::string oldName, std::string newName) {
	//renames file
	int test = rename(oldName.c_str(), newName.c_str());
	if (test == -1) {
		//wxString err = "File name override failed: " + oldName + " -> " + newName;
		std::cout << "File name override failed: " + oldName + " -> " + newName + '\n';
		//wxLogError(err);
	}
}

std::string getName(int characterNum, std::vector<Playable*> Level::* chType) {
	//gets name of character
	return (*currentLev.*chType)[characterNum]->name;
}

std::string getVanilla(int characterNum, std::vector<Playable*> Level::* chType) {
	//gets name of character to be replaced
	if (chType == &Level::bonusCharacters) {
		return currentLev->vanillaBonusCharacters[characterNum]->name;
	}
	else {
		return currentLev->vanillaParty[characterNum]->name;
	}
}

void playerInit(std::vector<writeSingle> writ) {
	//replaces characters in the main level txt
	//std::vector<writeSingle> writ;
	/*for (basicCh w : writers) {
		writ.push_back(writeSingle{getName(w.chNum, w.chType), getVanilla(w.chNum,
	w.chType).length(), {w.line, 12}});
	}*/
	writ[0].lnCol.col = 5;

	for (writeSingle& x : writ)
		x.lnCol.col = 12;

	writer(multiWrite, getMainTxt(currentLev), writ);
};

void mainTxtIns(std::string txt, int len, coord lnCol) {
	writer(oneWrite, getMainTxt(currentLev), writeSingle(txt, len, lnCol));
}

void scpIns(char scene, std::string script, int chNum, coord lnCol, std::vector<Playable*> Level::* chType) {
	//replaces string in scp file
	writer(oneWrite, getSCP(currentLev, scene, script), writeSingle(chNum, lnCol, chType));
};

void scpRep(char scene, std::string script, std::string txt, int len, coord lnCol) {
	//replaces text in scp file
	writer(oneWrite, getSCP(currentLev, scene, script), writeSingle(txt, len, lnCol));
};

//void scpRepMulti( char scene,  std::string script,  std::string txt,   int len,
//	 std::initializer_list< coord> lnCol) {
//	//replaces text in scp file multiple times
//	writer(oneWrite, getSCP(currentLev, scene, script), writeSet(txt, len, lnCol));
//};
//
//void scpRepMany( char scene,  std::string script,  std::initializer_list< writeSet> writ) {
//	writer(manyWrite, getSCP(currentLev, scene, script), writ);
//}

void scpMulti(char scene, std::string script, writeSet writ) {
	//replaces string with multiple instances in same scp file
	writer(weirdWrite, getSCP(currentLev, scene, script), writ);
};

void scpMany(char scene, std::string script, std::vector<writeSet> writers) {
	//replaces multiple strings which each have multiple instances in scp file
	//std::vector<writeSet> writ;
	//for (advancedCh w : writers) {
	//	writ.push_back(writeSet{getName(w.chNum, w.chType), getVanilla(w.chNum, w.chType).length(),
	//w.lnCol});
	//}
	writer(manyWrite, getSCP(currentLev, scene, script), writers);
};

void batchAnywhere(std::string file, std::vector<writeSet> writers) {

	writer(manyWrite, file, writers);
};

void scpName(char scene, int characterNum, std::vector<Playable*> Level::* chType) {
	//renames scp file
	//std::string temp = getSCP(currentLev, scene, getVanilla(characterNum, chType));
	//std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
	//renamer(temp, getSCP(currentLev, scene, getName(characterNum, chType)));
	std::string temp = getVanilla(characterNum, chType);
	std::transform(temp.begin(), temp.end(), temp.begin(), toupper);
	renamer(getSCP(currentLev, scene, temp), getSCP(currentLev, scene, getName(characterNum, chType)));
};

void scpAppend(char scene, std::string script, std::string appendix) {
	//appends scp file
	writer(appender, getSCP(currentLev, scene, script), appendix);
}

void scriptTxtAppend(char scene, std::string appendix) {
	//appends script.txt
	writer(appender, getScriptTxt(currentLev, scene), appendix);
}

void scriptTxt(char scene, int characterNum, unsigned int line, std::vector<Playable*> Level::* chType) {
	//updates script.txt
	writer(oneWrite, getScriptTxt(currentLev, scene), writeSingle(characterNum, { line, 1 }, chType));

	scpName(scene, characterNum);
};

void multiScriptTxt(char scene, std::vector<twoNum> pairs) {
	//updates script.txt
	//std::vector<writeSet> writ;
	//for (basicCh w : write) {
	//	writ.push_back(writeSet{getName(w.chNum, w.chType), getVanilla(w.chNum, w.chType).length(),
	//{w.line, 1}}); 	scpName(scene, w.chNum);
	//}
	std::vector<writeSingle> writ;
	for (twoNum p : pairs)
		writ.push_back({ p.chNum, p.line });

	writer(multiWrite, getScriptTxt(currentLev, scene), writ);

	for (twoNum w : pairs) {
		scpName(scene, w.chNum);
	}
};

void scriptTxtRep(char scene, std::string newStr, std::string oldStr, unsigned int line) {
	//replaces text in script.txt
	writer(oneWrite, getScriptTxt(currentLev, scene), writeSingle(newStr, oldStr.length(), { line, 1 }));
	renamer(getSCP(currentLev, scene, oldStr), getSCP(currentLev, scene, newStr));
};

void lineDeleterScp(char scene, std::string script, std::vector<unsigned int> lines) {
	writer(lineDel, getSCP(currentLev, scene, script), lines);
}

void lineDeleter(std::string file, std::vector<unsigned int> lines) {
	writer(lineDel, file, lines);
}

void lineDeleter(std::string file, unsigned int start, unsigned int end) {
	std::vector<unsigned int> v;
	for (unsigned int i = start; i <= end; i++)
		v.push_back(i);

	writer(lineDel, file, v);
}

void scpDeleter(char scene, std::string script) {
	std::remove(getSCP(currentLev, scene, script).c_str());
}

void baseFile(char scene, std::string fileType, int chNum, coord lnCol, std::vector<Playable*> Level::* chType) {
	writer(oneWrite, getBasePath(currentLev, scene, fileType), { chNum, lnCol, chType });
}

rgb::rgb() {
	r = rand() % 0xFF;
	g = rand() % 0xFF;
	b = rand() % 0xFF;

	rF = (float)r / 255.0f;
	gF = (float)g / 255.0f;
	bF = (float)b / 255.0f;
}

////change to not always use nAttackInfo
//void fixScript(std::string oldFunName, std::vector<Playable*> spEnemyTypes, std::string attackPattern,
//	std::string extraConditions, coord lnCol, std::string tf) {
//
//	std::string redirect;
//	std::string ending;
//	for (int i = 0; i < spEnemyTypes.size(); i++) {
//		if (spEnemyTypes[i]->nAttackInfo.actions != attackPattern) {
//			redirect += "\t\tif iAm \"" + spEnemyTypes[i]->name + "\" == 1 goto " + oldFunName +
//				    std::to_string(i) + "\n";
//
//			ending += "state " + oldFunName + std::to_string(i) + " {\n";
//			if (SpecialScripts.find(spEnemyTypes[i]) != std::string::npos) {
//				ending += "\tReferenceScript {\n"
//					  "\t\tScript=";
//
//				ending += SpecialScripts[spEnemyTypes[i]];
//
//				ending += "\n\t\tSource=Global\n"
//					  "\t\tReturnState=" +
//					  oldFunName + std::to_string(i) +
//					  "\n"
//					  "\t\tConditions {\n"
//					  "\t\t}\n"
//					  "\t}\n";
//			}
//			ending += "\tConditions {\n"
//				  "\t\t" +
//				  //spEnemyTypes[i]->conditions + "\n\t\t" +
//				  extraConditions +
//				  "\n\t}\n"
//				  "\tActions {\n"
//				  "\t\t" +
//				  spEnemyTypes[i]->nAttackInfo.actions +
//				  "\n\t}\n"
//				  "}\n";
//			std::string temp = std::vformat(
//				spEnemyTypes[i]->nAttackInfo.appendix, std::make_format_args(i, extraConditions));
//			appendFile(tf, temp);
//		}
//	}
//
//	txtIns(tf, redirect, {lnCol}, 0);
//	appendFile(tf, ending);
//}

//void redirrector(Level* lev, SpecialScp& sp) {
//
//	std::string tf = getSCP(lev, sp.scene, sp.fileName);
//	//lineDeleter(tf, sp.linesToDelete);
//	std::string redirect;
//	std::string ending;
//
//	for (int i = 0; i < sp.spEnemyTypes.size(); i++) {
//		if (SpecialScripts.find(sp.spEnemyTypes[i]) != std::string::npos) {
//			redirect += "\t\tif iAm \"" + sp.spEnemyTypes[i]->name + "\" == 1 goto " + sp.oldFunName +
//				    std::to_string(i) + "\n";
//			ending += std::vformat(sp.fun, std::make_format_args(i, SpecialScripts[sp.spEnemyTypes[i]]));
//		}
//	}
//
//	redirect += "\t\tif AlwaysTrue == 1 goto " + sp.oldFunName + "vanilla" + "\n";
//	txtIns(tf, "vanilla", {sp.lnCol}, 0);
//	appendFile(tf, "state " + sp.oldFunName +
//			       " {\n"
//			       "\tConditions {\n" +
//			       redirect +
//			       "\t}\n"
//			       "\tActions {\n"
//			       "\t}\n"
//			       "}\n");
//	appendFile(tf, ending);
//}j

std::array<unsigned int, 55> getLevPtr(unsigned int first) {
	std::array<unsigned int, 55> out;
	for (unsigned int i = 0; i < 55; i++) {
		out[i] = first + 0x4 * i;
	}
	return out;
}

std::string littleEnd(unsigned int num) {
	unsigned int swapped = (unsigned int)_byteswap_ulong(num);
	std::ostringstream oss;
	oss << std::hex << swapped;
	std::string output = oss.str();
	output = output.substr(0, output.length() - 2);
	while (output.length() < 6)
		output = "0" + output;
	return output;
}

std::string littleEndSigned(int num /*, int numBytes*/) {
	int swapped = (unsigned int)_byteswap_ulong(num);
	std::ostringstream oss;
	oss << std::hex << swapped;
	std::string output = oss.str();
	//while (out.length() < numBytes * 2)
	//out += "00";
	//output = output.substr(0, output.length() - 2);
	return output;
}

std::string unlockAsm(unsigned int levelptr) {
	return "a1" + littleEnd(levelptr) +
		"00"
		"3bc3"
		"740f"
		"0fb6407c"
		"8d1440"
		"c6049514e1860001";
}

void regexFile(std::string file, std::regex reg, std::string replacement) {
	std::fstream filestr(file, std::ios::in | std::ios::out);
	//std::string contents;
	std::vector<std::string> contents;
	getfile(file, contents);
	//std::vector<std::string> parts;

	bool inState = false;
	std::string current;
	std::string wholePart;
	int counter = 0;
	for (std::string line : contents) {
		wholePart += line + '\n';
		current = line + '\n';
		if (current.substr(0, 5) == "state" || current.substr(0,5) == "Refer") {
			inState = true;
			counter = 0;
		}
		if (inState) {
			if (current.find("{") != std::string::npos) counter++;
			else if (current.find("}") != std::string::npos) counter--;
			if (counter == 0) {
				//parts.push_back(wholePart);
				//std::cout << "------NEW-PART------" << std::endl;
				//std::cout << wholePart << std::endl;
				std::string temp;

				// >:(
				if (wholePart.find("EngageOpponent") != std::string::npos || wholePart.find("ReferenceScript") != std::string::npos) temp = std::regex_replace(wholePart, reg, replacement);
				else temp = wholePart;

				//std::cout << "------REPLACEMENT------" << std::endl;
				//std::cout << temp << std::endl;
				filestr << temp;

				wholePart = "";
				inState = false;
			}
		}
	}

	filestr.close();
}

void regexTest(std::string file, std::string pattern, std::string replacement) {
	std::fstream filestr(file, std::fstream::in, std::fstream::out);
	//std::string contents;
	std::vector<std::string> contents;
	getfile(file, contents);
	std::vector<std::string> parts;

	bool inState = false;
	std::string current;
	int counter = 0;
	for (std::string line : contents) {
		current += line + '\n';
		if (current.substr(0, 5) == "state") {
			inState = true;
			counter = 0;
		}
		if (inState) {
			if (current.find("{") != std::string::npos) counter++;
			else if (current.find("}") != std::string::npos) counter--;
			if (counter == 0) {
				parts.push_back(current);
				current = "";
			}
		}
	}

	//std::getline(filestr, contents, '\0');

	std::regex reg(pattern, std::regex_constants::icase);
	for (std::string part : parts) {
		std::cout << std::regex_replace(part, reg, replacement) << "\n";
		//filestr << out;
	}


	filestr.close();
}

void addRedirrect(std::string file, std::string state) {
	std::regex reg(("state " + state + 
		" \\{\\s*Conditions((?:(?!Conditions)[\\s\\S])+?)"
			"Actions((?:(?!Actions)[\\s\\S])+?)\\}\\s+?\\}").c_str());
	std::string rep = "state " + state + " {\n\tConditions {\n\t"
		"if IAmA \"gamorreanguard\" == 1 goto gamorreanguard"
		"if IAmA \"imperialguard\" == 1 goto imperialguard"
		"if IAmA \"bodyguard\" == 1 goto imperialguard"
		"\n\t\t}\n\tActions{\n\t}\n}\n\n"
		"state " + state + "vanilla {\n\tConditions {$1}\n\tActions {$2}\n\t}\n}\n\n"
		"state " + state + "gamorreanguard {ReferenceScript {\n\t\tScript=bodyguardg\n\t\tSource=Global\n\t\tReturnState=" + state + "\n\t\tConditions {\n\t\t}\n\t}\n\tConditions {\n\t}\n\tActions {\n\t}\n\t}\n}\n\n"
		"state " + state + "impguard {ReferenceScript {\n\t\tScript=bodyguard\n\t\tSource=Global\n\t\tReturnState=" + state + "\n\t\tConditions {\n\t\t}\n\t}\n\tConditions {\n\t}\n\tActions {\n\t}\n\t}\n}\n\n";
	regexFile(file, reg, rep);
}

