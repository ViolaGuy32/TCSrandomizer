#pragma once
#include "pch.h"

#include "Characters.h"
#include "Levels.h"

struct rgb {
	char r;
	char g;
	char b;
	float rF;
	float gF;
	float bF;


	rgb();
};


struct twoNum {
	int chNum;
	unsigned int line;
};

struct writeSet {
	std::string newStr;
	unsigned int len;
	std::vector<coord> lnCol;

	writeSet(std::string myStr, unsigned int myLen, std::vector<coord> myLnCol);
	writeSet(int chNum, std::vector<coord> myLnCol,
		std::vector<Playable*> Level::* chType = &Level::party);
};

struct writeSingle {
	std::string newStr;
	size_t len;
	coord lnCol;

	writeSingle(std::string myStr, size_t myLen, coord myLnCol);
	writeSingle(int chNum, coord myLnCol, std::vector<Playable*> Level::* chType = &Level::party);
	writeSingle(int chNum, unsigned int line, std::vector<Playable*> Level::* chType = &Level::party);
};

//template <typename FUN, typename W>
//void writer(FUN fun,  std::string file,  W stuff);
//
//void oneWrite( writeSingle& wrt, std::vector<std::string>& contents);
//
//void multiWrite( std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);
//
//void manyWrite( std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);


bool CIcompare(std::string first, std::string second);

void logR(std::string lg);

void writer(void(*fun)(writeSingle, std::vector<std::string>&), std::string file, writeSingle stuff);

void writer(void(*fun)(std::string, std::vector<std::string>&), std::string file, std::string stuff);

void writer(void(*fun)(writeSet, std::vector<std::string>&), std::string file, writeSet stuff);

void writer(void(*fun)(coord, std::vector<std::string>&), std::string file, coord stuff);

void writer(void(*fun)(unsigned int, std::vector<std::string>&), std::string file, unsigned int stuff);

void writer(void(*fun)(std::vector<writeSingle>, std::vector<std::string>&), std::string file, std::vector<writeSingle> stuff);

void getfile(std::string file, std::vector<std::string>& contents);
//
//void rgbWrite( std::string file,  rgb color,  int address);
//
void binaryWrite(std::string file, char bin, int address);
//
//void rgbBatch( std::string file,  rgb color,  std::vector<int>& IDs);
//
//void rgbFloat( std::string file,  rgb color,  int address);
//
void hexWrite(std::string file, std::string newWrite, int address, int len = 0, bool trailingNull = true);
//
void binaryWrite(std::string file, std::string bin, int address);
//
//int readEXE( int address);
//


void numWrite(std::string file, int newWrite, int address);

void ai2Write(char scene, std::string writ, std::initializer_list<int> address);

void ai2Write(char scene, int chNum, std::initializer_list<int> address,
	std::vector<Playable*> Level::* chType = &Level::party);

void characterPointer(Playable* play, int address);

void multiPointer(Playable* play, std::vector<int> address);

void txtIns(std::string file, std::string newC, const std::initializer_list<coord>& lnCol, const int len = 0);
void txtIns(std::string file, std::string newC, const std::initializer_list<int>& lnCol, const int len = 0);

//void txtIns(std::string file, std::string newC, coord lnCol, const int len = 0);

void oneWrite(writeSingle wrt, std::vector<std::string>& contents);

void multiWrite(std::vector<writeSingle> stuff, std::vector<std::string>& contents);

void weirdWrite(writeSet stuff, std::vector<std::string>& contents);

void manyWrite(std::vector<writeSet> stuff, std::vector<std::string>& contents);

void appender(std::string appendix, std::vector<std::string>& contents);

void lineDel(std::vector<unsigned int> lines, std::vector<std::string>& contents);

 std::string getBasePath(Level* lev, char scene, std::string fileType);

 std::string getMainTxt(Level* lev);

 std::string getSCP(Level* lev, char scene, std::string script);

 std::string getAI2(Level* lev, char scene);

void fileDeleter(char scene, int characterNum, std::vector<Playable*> Level::* chType = &Level::party);

 std::string getScriptTxt(Level* lev, char scene);

void renamer(std::string oldName, std::string newName);

 std::string getName(int characterNum, std::vector<Playable*> Level::* chType = &Level::party);

 std::string getVanilla(int characterNum, std::vector<Playable*> Level::* chType = &Level::party);

void playerInit(std::vector<writeSingle> writers);

void mainTxtIns(std::string txt, int len, coord lnCol);

void scpRep(char scene, std::string script, std::string txt, int len, coord lnCol);

void scpIns(char scene, std::string script, int chNum, coord lnCol,
	std::vector<Playable*> Level::* chType = &Level::party);

void scpMulti(char scene, std::string script, writeSet);

void scpMany(char scene, std::string script, std::vector<writeSet> writers);

void batchAnywhere(std::string file, std::vector<writeSet> writers);

void scpName(char scene, int characterNum, std::vector<Playable*> Level::* chType = &Level::party);

void scpAppend(char scene, std::string script, std::string appendix);

void scriptTxtAppend(char scene, std::string appendix);

void scriptTxt(char scene, int characterNum, unsigned int line,
	std::vector<Playable*> Level::* chType = &Level::party);

//void multiScriptTxt(char scene, std::vector<writeSingle> write);
void multiScriptTxt(char scene, std::vector<twoNum> pairs);

void scriptTxtRep(char scene, std::string newStr, std::string oldStr, unsigned int line);

void lineDeleterScp(char scene, std::string script, std::vector<unsigned int> lines);

void lineDeleter(std::string file, std::vector<unsigned int> lines);

void lineDeleter(std::string file, unsigned int start, unsigned int end);

void scpDeleter(char scene, std::string script);

void baseFile(char scene, std::string fileType, int chNum, coord lnCol,
	std::vector<Playable*> Level::* chType = &Level::party);

void appendFile( std::string file,  std::string appendix);

//void fixScript(std::string oldFunName,std::vector<Playable*>spEnemyTypes, std::string attackPattern, std::string extraConditions, coord lnCol, std::string tf);

//void redirrector(Level* lev, SpecialScp& sp);


//std::array<unsigned int, 55> getLevPtr(unsigned int first); 
//std::string littleEnd(unsigned int num);
//std::string littleEndSigned(int num);
//std::string unlockAsm(unsigned int levelptr);

void regexFile(std::string file, std::string pattern, std::string replacement, bool refScript = false);

void regexTest(std::string file, std::string pattern, std::string replacement, bool refScript = false);

