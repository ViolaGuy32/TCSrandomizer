#include "pch.h"

#include "OtherStuff.h"
#include "App.h"
#include "Defines.h"
#include "Characters.h"

extern std::shared_ptr<Level> currentLev;
extern std::string out;
//extern std::unique_ptr<std::ofstream> loggingIt;


void logR(std::string lg) {
#ifdef _DEBUG
	//(*loggingIt) << lg << '\n';

	std::ofstream log2("files/log2.txt", std::ios_base::out | std::ios_base::app);
	log2 << lg << std::endl;
	//wxLogStatus(lg.c_str());
#endif 
}

void writer(void(*fun)(writeSingle, std::vector<std::string>&), std::string file, writeSingle stuff) {

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

void writer(void(*fun)(std::string, std::vector<std::string>&), std::string file, std::string stuff) {
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

void writer(void(*fun)(writeSet, std::vector<std::string>&), std::string file, writeSet stuff) {
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

void writer(void(*fun)(coord, std::vector<std::string>&), std::string file, coord stuff) {
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

void writer(void(*fun)(unsigned int, std::vector<std::string>&), std::string file, unsigned int stuff) {
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

void writer(void(*fun)(std::vector<unsigned int>, std::vector<std::string>&), std::string file, std::vector<unsigned int> stuff) {
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

void writer(void(*fun)(std::vector<writeSet>, std::vector<std::string>&), std::string file, std::vector<writeSet> stuff) {
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

void writer(void(*fun)(std::vector<coord>, std::vector<std::string>&), std::string file, std::vector<coord> stuff) {
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

void writer(void(*fun)(std::vector<writeSingle>, std::vector<std::string>&), std::string file, std::vector<writeSingle> stuff) {
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
	return;
}

std::string cdstr(coord cd) {
	return ("(" + std::to_string(cd.ln) + ", " + std::to_string(cd.col) + ")");
}
//
//std::ostream operator<<(coord lncol, std::ostream& os) {
//	os << "(" + std::to_string(lncol.ln) + ", " + std::to_string(lncol.col) + ")";
//}

writeSingle::writeSingle(std::string myStr, unsigned int myLen, coord myLnCol)
	: newStr(myStr), len(myLen), lnCol(myLnCol) {
}
writeSingle::writeSingle(unsigned int chNum, coord myLnCol, std::vector<std::shared_ptr<Playable>> Level::* chType)
	: newStr(getName(chNum, chType)), len(getVanilla(chNum, chType).length()), lnCol(myLnCol) {
}
writeSingle::writeSingle(unsigned int chNum, unsigned int line, std::vector<std::shared_ptr<Playable>> Level::* chType)
	: newStr(getName(chNum, chType)), len(getVanilla(chNum, chType).length()), lnCol({line, 1}) {
}

writeSet::writeSet(std::string myStr, unsigned int myLen, std::vector< coord> myLnCol)
	: newStr(myStr), len(myLen), lnCol(myLnCol) {
}

writeSet::writeSet(unsigned int chNum, std::vector< coord> myLnCol, std::vector<std::shared_ptr<Playable>> Level::* chType)
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
	if (trailingNull)
		logR(file + " " + newWrite + " " + std::to_string(address));
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
	return val;
}

void numWrite(std::string file, int newWrite, int address) {
	std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);

	fs.seekp(address);
	fs.write((char*)&newWrite, sizeof(newWrite));
	fs.close();
}

void ai2Write(char scene, std::string writ, std::initializer_list<unsigned int> address) {
	for (unsigned int a : address)
		hexWrite(getAI2(currentLev, scene), writ, a);
}

void ai2Write(char scene, unsigned int chNum, std::initializer_list<unsigned int> address,
	std::vector<std::shared_ptr<Playable>> Level::* chType) {
	for (unsigned int a : address)
		hexWrite(getAI2(currentLev, scene), getName(chNum, chType), a);
}

//0xca35a
int addressPointer = 0x2B0;
int junkCharacters = 0x3f1b6c;

void characterPointer(std::shared_ptr<Playable> play, int address) {
	if (play->pointString != 0x0) {
		numWrite(EXE, readEXE(play->pointString - 0x400000 + 0x4), address);
	} else {
		hexWrite(EXE, play->name, addressPointer);
		numWrite(EXE, addressPointer + 0x400000, junkCharacters - 0x4);
		play->pointString = junkCharacters + 0x400000 - 0x4;

		numWrite(EXE, readEXE(play->pointString - 0x400000 + 0x4), address);

		addressPointer += play->name.length() + 1;
		junkCharacters += 0x8;
		if (junkCharacters == 0x3f1bb4) junkCharacters += 0x8; //"whip" might not be unused
	}
}

void multiPointer(std::shared_ptr<Playable> play, std::vector<int> address) {
	if (play->pointString != 0x0) {
		for (int ad : address)
			numWrite(EXE, readEXE(play->pointString - 0x400000 + 0x4), ad);
	} else {
		hexWrite(EXE, play->name, addressPointer);
		numWrite(EXE, addressPointer + 0x400000, junkCharacters - 0x4);
		play->pointString = junkCharacters + 0x400000 - 0x4;

		for (int ad : address)
			numWrite(EXE, readEXE(play->pointString - 0x400000 + 0x4), ad);

		addressPointer += play->name.length() + 1;
		junkCharacters += 0x8;
		while (junkCharacters == 0x3f1bb4 || junkCharacters == 0x3f1b84 || junkCharacters == 0x3f1bac)
			junkCharacters += 0x8; //"whip" might not be unused and others are weird
	}
}



//void deleteLines( std::string file,  std::initializer_list< unsigned int>& lines) {
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

void txtIns(std::string file, std::string newC, const std::initializer_list<unsigned int>& lnCol, const int len) {
#ifdef _DEBUG

	logR(file + " " + newC + " " + std::to_string(len).c_str());

#endif

	std::vector<std::string> contents;
	getfile(file, contents);
	for (unsigned int x : lnCol)
		contents[x - 1].replace(1, len, newC);


	std::ofstream fileout(file);
	for (std::string y : contents)
		fileout << y + "\n";

	fileout.close();

}

/*
void txtIns( std::string file,  std::string newC, coord lnCol, const int len) {
	txtIns(file, newC, {lnCol}, len);
}*/

//void batchTxt( std::string file,  std::initializer_list<writeSet> stuff) {
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
//	for ( std::string y : contents)
//		fileout << y + "\n";
//
//	fileout.close();
//}
//
//void batchPlayerTxt( std::string file,  std::initializer_list<writePlayerSet> stuff) {
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
//	for ( std::string y : contents)
//		fileout << y + "\n";
//
//	fileout.close();
//}
//
//void batchSinglePlayerTxt( std::string file,  std::initializer_list<writePlayerSingle> stuff) {
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
//	for ( std::string y : contents)
//		fileout << y + "\n";
//
//	fileout.close();
//}

//template <typename C, typename W>
//void writer(void(*fun)(std::initializer_list<C>&, std::vector<std::string>&),
//	 std::string file,  std::initializer_list<W> stuff) {
//
//	std::vector<std::string> contents;
//	getfile(file, contents);
//
//	fun(stuff, contents);
//
//	std::ofstream fileout(file);
//	for ( std::string y : contents)
//		fileout << y + "\n";
//
//	fileout.close();
//}


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

void lineDel(std::vector< unsigned int>lines, std::vector<std::string>& contents) {
	//sets line to empty string; actually deleting them would offset coordinates
	for (unsigned int ln : lines) {
	#ifdef _DEBUG
		logR(std::to_string(ln) + ' ' + contents[ln - 1] + ' ' + " deleted.");
	#endif

		contents[ln - 1] = "";
	}
}

void fileDeleter(char scene, int characterNum, std::vector<std::shared_ptr<Playable>> Level::* chType) {
	//deletes file

	std::remove(getSCP(currentLev, scene, getVanilla(characterNum, chType)).c_str());
};
//
//void appendFile( std::string file,  std::string appendix) {
//#ifdef _DEBUG
//	wxGetApp().CallAfter([file]() {
//		wxString log = "appending" + file;
//	logR(log);
//	});
//#endif
//
//	std::vector<std::string> contents;
//	getfile(file, contents);
//	contents.push_back(appendix);
//
//	std::ofstream fileout(file);
//	for (std::string y : contents) {
//		fileout << y + "\n";
//	}
//	fileout.close();
//
//}

//gets path for various types of files

std::string getBasePath(std::shared_ptr<Level> lev, char scene, std::string fileType) {
	return out + lev->path + lev->shortName + '_' + scene + '/' + lev->shortName + '_' + scene + "." + fileType;
}

std::string getMainTxt(std::shared_ptr<Level> lev) {
	return out + lev->path + lev->name + ".TXT";
}

//std::string getGiz( std::shared_ptr<Level> lev,  char scene) {
//	return out + lev->path + lev->shortName + '_' + scene + '/' + lev->shortName + '_' + scene + ".GIZ";
//}
//
//std::string getGit( std::shared_ptr<Level> lev,   char scene) {
//	return out + lev->path + lev->shortName + '_' + scene + '/' + lev->shortName + '_' + scene + ".GIT";
//}
//
//std::string getSceneTxt( std::shared_ptr<Level> lev,   char scene) {
//	return out + lev->path + lev->shortName + '_' + scene + '/' + lev->shortName + '_' + scene + ".TXT";
//}

std::string getSCP(std::shared_ptr<Level> lev, char scene, std::string script) {
	return out + lev->path + lev->shortName + '_' + scene + "/AI/" + script + ".SCP";
}

std::string getAI2(std::shared_ptr<Level> lev, char scene) {
	return out + lev->path + lev->shortName + '_' + scene + "/AI/" + lev->shortName + '_' + scene + ".AI2";
}

std::string getScriptTxt(std::shared_ptr<Level> lev, char scene) {
	return out + lev->path + lev->shortName + '_' + scene + "/AI/SCRIPT.TXT";
}

void renamer(std::string oldName, std::string newName) {
	//renames file
	int test = rename(oldName.c_str(), newName.c_str());
	if (test == -1) {
		wxString err = "File name override failed: " + oldName + " -> " + newName;
		wxLogError(err);
	}
}

std::string getName(unsigned int characterNum, std::vector<std::shared_ptr<Playable>> Level::* chType) {
	//gets name of character
	return (*currentLev.*chType)[characterNum]->name;
}

std::string getVanilla(unsigned int characterNum, std::vector<std::shared_ptr<Playable>> Level::* chType) {
	//gets name of character to be replaced
	if (chType == &Level::bonusCharacters) {
		return currentLev->vanillaBonusCharacters[characterNum]->name;
	} else {
		return currentLev->vanillaParty[characterNum]->name;
	}
}


void playerInit(std::vector<writeSingle> writ) {
	//replaces characters in the main level txt
	//std::vector<writeSingle> writ;
	/*for (basicCh w : writers) {
		writ.push_back(writeSingle{getName(w.chNum, w.chType), getVanilla(w.chNum, w.chType).length(), {w.line, 12}});
	}*/
	writ[0].lnCol.col = 5;

	for (writeSingle& x : writ) x.lnCol.col = 12;

	writer(multiWrite, getMainTxt(currentLev), writ);
};


void mainTxtIns(std::string txt, unsigned int len, coord lnCol) {
	writer(oneWrite, getMainTxt(currentLev), writeSingle(txt, len, lnCol));
}

void scpIns(char scene, std::string script, unsigned int chNum, coord lnCol,
	std::vector<std::shared_ptr<Playable>> Level::* chType) {
 //replaces string in scp file
	writer(oneWrite, getSCP(currentLev, scene, script), writeSingle(chNum, lnCol, chType));
};

void scpRep(char scene, std::string script, std::string txt, unsigned int len, coord lnCol) {
	//replaces text in scp file
	writer(oneWrite, getSCP(currentLev, scene, script), writeSingle(txt, len, lnCol));
};

//void scpRepMulti( char scene,  std::string script,  std::string txt,  unsigned int len,
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
	//	writ.push_back(writeSet{getName(w.chNum, w.chType), getVanilla(w.chNum, w.chType).length(), w.lnCol});
	//}
	writer(manyWrite, getSCP(currentLev, scene, script), writers);
};

void batchAnywhere(std::string file, std::vector<writeSet> writers) {

	writer(manyWrite, file, writers);
};

void scpName(char scene, unsigned int characterNum, std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party) {
	//renames scp file
	renamer(getSCP(currentLev, scene, getVanilla(characterNum, chType)),
		getSCP(currentLev, scene, getName(characterNum, chType)));
};

void scpAppend(char scene, std::string script, std::string appendix) {
	//appends scp file
	writer(appender, getSCP(currentLev, scene, script), appendix);
}

void scriptTxtAppend(char scene, std::string appendix) {
	//appends script.txt
	writer(appender, getScriptTxt(currentLev, scene), appendix);
}

void scriptTxt(char scene, int characterNum, unsigned int line,
	std::vector<std::shared_ptr<Playable>> Level::* chType) {
	//updates script.txt
	writer(oneWrite, getScriptTxt(currentLev, scene), writeSingle(characterNum, {line, 1}, chType));

	scpName(scene, characterNum);
};

void multiScriptTxt(char scene, std::vector< writeSingle> write) {
	//updates script.txt
	//std::vector<writeSet> writ;
	//for (basicCh w : write) {
	//	writ.push_back(writeSet{getName(w.chNum, w.chType), getVanilla(w.chNum, w.chType).length(), {w.line, 1}});
	//	scpName(scene, w.chNum);
	//}
	writer(multiWrite, getScriptTxt(currentLev, scene), write);

};

void scriptTxtRep(char scene, std::string newStr, std::string oldStr, unsigned int line) {
	//replaces text in script.txt
	writer(oneWrite, getScriptTxt(currentLev, scene), writeSingle(newStr, oldStr.length(), {line, 1}));
	renamer(getSCP(currentLev, scene, oldStr),
		getSCP(currentLev, scene, newStr));
};

void lineDeleterScp(char scene, std::string script, std::vector< unsigned int> lines) {
	writer(lineDel, getSCP(currentLev, scene, script), lines);
}

void lineDeleter(std::string file, std::vector<unsigned int> lines) {
	writer(lineDel, file, lines);
}

void scpDeleter(char scene, std::string script) {
	std::remove(getSCP(currentLev, scene, script).c_str());
}

void baseFile(char scene, std::string fileType, unsigned int chNum, coord lnCol,
	std::vector<std::shared_ptr<Playable>> Level::* chType) {
	writer(oneWrite, getBasePath(currentLev, scene, fileType), {chNum, lnCol, chType});
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

//void OLDtxtIns( std::string file, std::string newC, std::vector<coord> lnCol, int len = 0) {
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
//			//logR(temp);
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
//	logR("txtIns");
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
//		logR(temp);
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
//coord::coord( unsigned int myLn) : ln(myLn) {}
//
//coord::coord( unsigned int myLn,  unsigned int myCol) : ln(myLn), col(myCol) {}
