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
	const int ln = 1;
	const int col = 1;
	coord();
	coord(const int myLn);
	coord(const int myLn, const int myCol);
};


void getfile(const std::string& file, std::vector<std::string>& contents);

void rgbWrite(const std::string& file, const rgb color, const int address);

void binaryWrite(const std::string& file, char bin, const int address);

void rgbBatch(const std::string& file, const rgb color, const std::vector<int>& IDs);

void rgbFloat(const std::string& file, const rgb color, const int address);

void hexWrite(const std::string& file, const std::string& newWrite, const int address, const int len = 0, bool trailingNull = true);

void binaryWrite(const std::string& file, const std::string& bin, const int address);

int readEXE(const int address);

void numWrite(const std::string& file, const int newWrite, const int address);

void deleteLines(const std::string& file, const std::initializer_list<int>& lines);

void txtIns(const std::string& file, const std::string& newC, const std::initializer_list<coord>& lnCol, const int len = 0);

void txtIns(const std::string& file, const std::string& newC, const coord lnCol, const int len = 0);

void appendFile(const std::string& file, const std::string& appendix);

std::string getGiz(const Level* lev, const char scene);

std::string getGit(const Level* lev, const char scene);

std::string getSCP(const Level* lev, const char scene, const std::string& script);

std::string getScriptTxt(const Level* lev, const char scene);

void renamer(const std::string& oldName, const std::string& newName);