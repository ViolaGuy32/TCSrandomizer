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

	writeSet(const std::string& myStr, unsigned int myLen, const std::vector<coord>& myLnCol);
	writeSet(int chNum, const std::vector<coord>& myLnCol,
		std::vector<Playable*> Level::* chType = &Level::party);
};

struct writeSingle {
	std::string newStr;
	size_t len;
	coord lnCol;

	writeSingle(const std::string& myStr, size_t myLen, coord myLnCol);
	writeSingle(int chNum, coord myLnCol, std::vector<Playable*> Level::* chType = &Level::party);
	writeSingle(int chNum, unsigned int line, std::vector<Playable*> Level::* chType = &Level::party);
};

//template <typename FUN, typename W>
//void writer(FUN fun,  const std::string&file,  W stuff);
//
//void oneWrite( writeSingle& wrt, std::vector<std::string>& contents);
//
//void multiWrite( std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);
//
//void manyWrite( std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);


bool CIcompare(const std::string& first, const std::string& second);

void logR(const std::string& lg);

void oneWriter(const std::string& file, const writeSingle& stuff);

void getfile(const std::string& file, std::vector<std::string>& contents);
//
//void rgbWrite( const std::string&file,  rgb color,  int address);
//
void binaryWrite(const std::string& file, char bin, int address);
//
//void rgbBatch( const std::string&file,  rgb color,  std::vector<int>& IDs);
//
//void rgbFloat( const std::string&file,  rgb color,  int address);
//
void hexWrite(const std::string& file, const std::string& newWrite, size_t address, size_t len = 0, bool trailingNull = true);
//
void binaryWrite(const std::string& file, const std::string& bin, size_t address);
//
//int readEXE( int address);
//


void numWrite(const std::string& file, size_t newWrite, size_t address);

void ai2Write(char scene, const std::string& writ, std::initializer_list<int> address);

void ai2Write(char scene, int chNum, std::initializer_list<int> address,
	std::vector<Playable*> Level::* chType = &Level::party);

void characterPointer(Playable* play, int address);

void multiPointer(Playable* play, const std::vector<int>& address);

void txtIns(const std::string& file, const std::string& newC, const std::initializer_list<coord>& lnCol, const int len = 0);
void txtIns(const std::string& file, const std::string& newC, const std::initializer_list<int>& lnCol, const int len = 0);

//void txtIns(const std::string&file, const std::string&newC, coord lnCol, const int len = 0);

void oneWrite(const writeSingle &wrt, std::vector<std::string>& contents);

void multiWrite(const std::vector<writeSingle>& stuff, std::vector<std::string>& contents);

void weirdWrite(const writeSet &stuff, std::vector<std::string>& contents);

void manyWrite(const std::vector<writeSet>& stuff, std::vector<std::string>& contents);

void appender(const std::string& appendix, std::vector<std::string>& contents);

void lineDel(std::vector<unsigned int> lines, std::vector<std::string>& contents);

std::string getBasePath(Level* lev, char scene, const std::string& fileType);

std::string getMainTxt(Level* lev);

std::string getSCP(Level* lev, char scene, const std::string& script);

std::string getAI2(Level* lev, char scene);

void fileDeleter(char scene, int characterNum, std::vector<Playable*> Level::* chType = &Level::party);

std::string getScriptTxt(Level* lev, char scene);

void renamer(const std::string& oldName, const std::string& newName);

const std::string& getName(unsigned int characterNum, std::vector<Playable*> Level::* chType = &Level::party);

const std::string& getVanilla(unsigned int characterNum, std::vector<Playable*> Level::* chType = &Level::party);

void playerInit(std::vector<writeSingle> writers);

void mainTxtIns(const std::string& txt, int len, coord lnCol);

void scpRep(char scene, const std::string& script, const std::string& txt, int len, coord lnCol);

void scpIns(char scene, const std::string& script, int chNum, coord lnCol,
	std::vector<Playable*> Level::* chType = &Level::party);

void scpMulti(char scene, const std::string& script, writeSet);

void scpMany(char scene, const std::string& script, std::vector<writeSet> writers);

void batchAnywhere(const std::string& file, std::vector<writeSet> writers);

void scpName(char scene, int characterNum, std::vector<Playable*> Level::* chType = &Level::party);

void scpAppend(char scene, const std::string& script, const std::string& appendix);

void scriptTxtAppend(char scene, const std::string& appendix);

void scriptTxt(char scene, int characterNum, unsigned int line,
	std::vector<Playable*> Level::* chType = &Level::party);

//void multiScriptTxt(char scene, std::vector<writeSingle> write);
void multiScriptTxt(char scene, std::vector<twoNum> pairs);

void scriptTxtRep(char scene, const std::string& newStr, const std::string& oldStr, unsigned int line);

void lineDeleterScp(char scene, const std::string& script, std::vector<unsigned int> lines);

void lineDeleter(const std::string& file, std::vector<unsigned int> lines);

void lineDeleter(const std::string& file, unsigned int start, unsigned int end);

void scpDeleter(char scene, const std::string& script);

void baseFile(char scene, const std::string& fileType, int chNum, coord lnCol,
	std::vector<Playable*> Level::* chType = &Level::party);

void appendFile(const std::string& file, const std::string& appendix);

//void fixScript(const std::string&oldFunName,std::vector<Playable*>spEnemyTypes, const std::string&attackPattern, const std::string&extraConditions, coord lnCol, const std::string&tf);

//void redirrector(Level* lev, SpecialScp& sp);


std::array<unsigned int, 55> getLevPtr(unsigned int first);
std::string littleEnd(unsigned int num);
std::string littleEndSigned(int num);
std::string unlockAsm(unsigned int levelptr);

void regexFile(const std::string& file, const std::string& pattern, const std::string& replacement, bool refScript = false);

void regexTest(const std::string& file, const std::string& pattern, const std::string& replacement, bool refScript = false);

