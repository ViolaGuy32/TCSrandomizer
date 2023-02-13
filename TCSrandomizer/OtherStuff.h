#pragma once
#include <string>
#include <fstream>
#include <vector>
//#include "Characters.h"

struct rgb {
	char r;
	char g;
	char b;
	float rF;
	float gF;
	float bF;


	rgb();
};

struct coord {
	const unsigned int ln = 1;
	const unsigned int col = 1;
};
//
//struct basicCh {
//	const unsigned int chNum;
//	const unsigned int line;
//	const std::vector<Playable*> Level::* chType = &Level::party;
//};
//
//struct advancedCh {
//	const unsigned int chNum;
//	std::initializer_list<const coord> lnCol;
//	const std::vector<Playable*> Level::* chType = &Level::party;
//};

struct writeSet {
	const std::string newStr;
	const unsigned int len;
	const std::initializer_list<coord> lnCol;

	writeSet(const std::string myStr, const unsigned int myLen, const std::initializer_list<const coord> myLnCol);
	writeSet(const int chNum, const std::initializer_list<const coord> myLnCol,
		const std::vector<Playable*> Level::* chType = &Level::party);
};

struct writeSingle {
	const std::string newStr;
	const unsigned int len;
	coord lnCol;

	writeSingle(const std::string myStr, const unsigned int myLen, coord myLnCol);
	writeSingle(const int chNum, coord myLnCol, const std::vector<Playable*> Level::* chType = &Level::party);
	writeSingle(const int chNum, unsigned int line, const std::vector<Playable*> Level::* chType = &Level::party);
};

//template <typename FUN, typename W>
//void writer(FUN fun, const std::string& file, const W stuff);
//
//void oneWrite(const writeSingle& wrt, std::vector<std::string>& contents);
//
//void multiWrite(const std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);
//
//void manyWrite(const std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);

void deleteLines(const std::string& file, const std::initializer_list<const unsigned int>& lines);

void getfile(const std::string& file, std::vector<std::string>& contents);
//
//void rgbWrite(const std::string& file, const rgb color, const int address);
//
//void binaryWrite(const std::string& file, char bin, const int address);
//
//void rgbBatch(const std::string& file, const rgb color, const std::vector<int>& IDs);
//
//void rgbFloat(const std::string& file, const rgb color, const int address);
//
//void hexWrite(const std::string& file, const std::string& newWrite, const int address, const int len = 0, bool trailingNull = true);
//
//void binaryWrite(const std::string& file, const std::string& bin, const int address);
//
//int readEXE(const int address);
//
//void numWrite(const std::string& file, const int newWrite, const int address);

void fileDeleter(const char scene, const int characterNum, std::vector<Playable*> Level::* chType = &Level::party);
//
//std::string getGiz(const Level* lev, const char scene);
//
//std::string getGit(const Level* lev, const char scene);
//
//std::string getSCP(const Level* lev, const char scene, const std::string& script);

std::string getScriptTxt(const Level* lev, const char scene);

void renamer(const std::string& oldName, const std::string& newName);

std::string getName(const unsigned int characterNum, const std::vector<Playable*> Level::* chType = &Level::party);

std::string getVanilla(const unsigned int characterNum, const std::vector<Playable*> Level::* chType = &Level::party);

void playerInit(std::initializer_list<writeSingle> writers);

void mainTxtIns(const std::string& txt, const unsigned int len, const coord lnCol);

void scpIns(const char scene, const std::string& script, const unsigned int chNum, const coord lnCol,
	const std::vector<Playable*> Level::* chType = &Level::party);

void scpRep(const char scene, const std::string& script, const std::string txt, const unsigned int len, const coord lnCol);

void scpRepMulti(const char scene, const std::string& script, const std::string txt, const unsigned int len, const std::initializer_list<const coord> lnCol);

void scpRepMany(const char scene, const std::string& script, const std::initializer_list<const writeSet> writ);

void scpMulti(const char scene, const std::string& script, const unsigned int chNum, const std::initializer_list<coord> lnCol, const std::vector<Playable*> Level::* chType = &Level::party);

void scpMany(const char scene, const std::string& script, std::initializer_list<advancedCh> writers);

void scpName(const char scene, const unsigned int characterNum, const std::vector<Playable*> Level::* chType);

void scpAppend(const char scene, const std::string& script, const std::string& appendix);

void scriptTxtAppend(const char scene, const std::string& appendix);

void scriptTxt(const char scene, const int characterNum, const unsigned int line, 
	std::vector<Playable*> Level::* chType = &Level::party);

void multiScriptTxt(const char scene, const std::initializer_list<const basicCh> write);

void scriptTxtRep(const char scene, const std::string newStr, const std::string oldStr, const unsigned int line);

void lineDeleterScp(const char scene, const std::string& script, std::initializer_list<const unsigned int> lines);

void scpDeleter(const char scene, const std::string& script);

void baseFile(const char scene, const std::string& fileType, const unsigned int chNum, const coord lnCol,
	const std::vector<Playable*> Level::* chType = &Level::party);
