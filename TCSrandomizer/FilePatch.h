#pragma once
#include <string>
#include <fstream>
#include <vector>
//#include "Characters.h"

void fileGen();

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
	const int col = 1;
	coord();
	coord(const unsigned int myLn);
	coord(const unsigned int myLn, const unsigned int myCol);

};


struct writeSet {
	const std::string newStr;
	const unsigned int len;
	const std::initializer_list<coord> lnCol;
};

struct writeSingle {
	const std::string newStr;
	const unsigned int len;
	const coord lnCol;

	writeSingle(const std::string myStr, const unsigned int myLen, const coord lnCol);
	writeSingle(const int chNum, const coord myLnCol, const std::vector<Playable*> Level::* chType = &Level::party);
};

template <typename FUN, typename W>
void writer(FUN fun, const std::string& file, const W stuff);

void oneWrite(const writeSingle& wrt, std::vector<std::string>& contents);

void multiWrite(const std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);

void manyWrite(const std::initializer_list<writeSet>& stuff, std::vector<std::string>& contents);

void deleteLines(const std::string& file, const std::initializer_list<int>& lines);

void getfile(const std::string& file, std::vector<std::string>& contents);

void rgbWrite(const std::string& file, const rgb color, const int address);

void binaryWrite(const std::string& file, char bin, const int address);

void rgbBatch(const std::string& file, const rgb color, const std::vector<int>& IDs);

void rgbFloat(const std::string& file, const rgb color, const int address);

void hexWrite(const std::string& file, const std::string& newWrite, const int address, const int len = 0, bool trailingNull = true);

void binaryWrite(const std::string& file, const std::string& bin, const int address);

int readEXE(const int address);

void numWrite(const std::string& file, const int newWrite, const int address);

void appendFile(const std::string& file, const std::string& appendix);

std::string getGiz(const Level* lev, const char scene);

std::string getGit(const Level* lev, const char scene);

std::string getSCP(const Level* lev, const char scene, const std::string& script);

std::string getScriptTxt(const Level* lev, const char scene);

void renamer(const std::string& oldName, const std::string& newName);

std::string getName(const unsigned int characterNum, const std::vector<Playable*> Level::* chType = &Level::party);

std::string getVanilla(const unsigned int characterNum, const std::vector<Playable*> Level::* chType = &Level::party);
