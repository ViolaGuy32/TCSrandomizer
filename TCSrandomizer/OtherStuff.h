#pragma once
#include "pch.h"

#include "Characters.h"

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
	unsigned int ln = 1;
	unsigned int col = 1;
};

struct twoNum {
	unsigned int chNum;
	unsigned int line;
};

struct writeSet {
	std::string newStr;
	unsigned int len;
	std::vector<coord> lnCol;

	writeSet(std::string myStr, unsigned int myLen, std::vector<coord> myLnCol);
	writeSet(unsigned int chNum, std::vector< coord> myLnCol,
		std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);
};

struct writeSingle {
	std::string newStr;
	unsigned int len;
	coord lnCol;

	writeSingle(std::string myStr, unsigned int myLen, coord myLnCol);
	writeSingle(unsigned int chNum, coord myLnCol, std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);
	writeSingle(unsigned int chNum, unsigned int line, std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);
};

//template <typename FUN, typename W>
//void writer(FUN fun,  std::string file,  W stuff);
//
//void oneWrite( writeSingle& wrt, std::vector<std::string>& contents);
//
//void multiWrite( std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);
//
//void manyWrite( std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);


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
void binaryWrite( std::string file, char bin,  int address);
//
//void rgbBatch( std::string file,  rgb color,  std::vector<int>& IDs);
//
//void rgbFloat( std::string file,  rgb color,  int address);
//
void hexWrite( std::string file,  std::string newWrite,  int address,  int len = 0, bool trailingNull = true);
//
void binaryWrite( std::string file,  std::string bin,  int address);
//
//int readEXE( int address);
//


void numWrite( std::string file,  int newWrite,  int address);

void ai2Write(char scene, std::string writ, std::initializer_list<unsigned int> address);

void ai2Write(char scene, unsigned int chNum, std::initializer_list<unsigned int> address,
	std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);

void characterPointer(std::shared_ptr<Playable> play, int address);

void multiPointer(std::shared_ptr<Playable> play, std::vector<int> address);

void txtIns(std::string file, std::string newC, const std::initializer_list<coord>& lnCol, const int len = 0);
void txtIns(std::string file, std::string newC, const std::initializer_list<unsigned int>& lnCol, const int len = 0);

//void txtIns(std::string file, std::string newC, coord lnCol, const int len = 0);

void oneWrite(writeSingle wrt, std::vector<std::string>& contents);

void multiWrite(std::vector<writeSingle> stuff, std::vector<std::string>& contents);

void manyWrite(std::vector<writeSet> stuff, std::vector<std::string>& contents);

void appender(std::string appendix, std::vector<std::string>& contents);

void lineDel(std::vector<unsigned int> lines, std::vector<std::string>& contents);

std::string getBasePath(std::shared_ptr<Level> lev, char scene, std::string fileType);

std::string getSCP(std::shared_ptr<Level> lev, char scene, std::string script);

std::string getAI2(std::shared_ptr<Level> lev, char scene);

void fileDeleter(char scene, int characterNum, std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);

std::string getScriptTxt(std::shared_ptr<Level> lev, char scene);

void renamer(std::string oldName, std::string newName);

std::string getName(unsigned int characterNum, std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);

std::string getVanilla(unsigned int characterNum, std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);

void playerInit(std::vector<writeSingle> writers);

void mainTxtIns(std::string txt, unsigned int len, coord lnCol);

void scpRep(char scene, std::string script, std::string txt, unsigned int len, coord lnCol);

void scpIns(char scene, std::string script, unsigned int chNum, coord lnCol,
	std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);

void scpMulti(char scene, std::string script, writeSet);

void scpMany(char scene, std::string script, std::vector<writeSet> writers);

void batchAnywhere(std::string file, std::vector<writeSet> writers);

void scpName(char scene, unsigned int characterNum, std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);

void scpAppend(char scene, std::string script, std::string appendix);

void scriptTxtAppend(char scene, std::string appendix);

void scriptTxt(char scene, int characterNum, unsigned int line,
	std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);

//void multiScriptTxt(char scene, std::vector<writeSingle> write);
void multiScriptTxt(char scene, std::vector< twoNum> pairs);

void scriptTxtRep(char scene, std::string newStr, std::string oldStr, unsigned int line);

void lineDeleterScp(char scene, std::string script, std::vector<unsigned int> lines);


void lineDeleter(std::string file, std::vector< unsigned int> lines);

void scpDeleter(char scene, std::string script);

void baseFile(char scene, std::string fileType, unsigned int chNum, coord lnCol,
	std::vector<std::shared_ptr<Playable>> Level::* chType = &Level::party);

