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
	int ln = 1;
	int col = 1;
	coord();
	coord(int myLn);
	coord(int myLn, int myCol);
};


void getfile(std::string file, std::vector<std::string>& contents);

void rgbWrite(std::string file, rgb color, int address);

void binaryWrite(std::string file, char bin, int address);

void rgbBatch(std::string file, rgb color, std::vector<int> IDs);

void rgbFloat(std::string file, rgb color, int address);

void hexWrite(std::string file, std::string newWrite, int address, int len = 0, bool trailingNull = true);

void binaryWrite(std::string file, std::string bin, int address);

int readEXE(int address);

void numWrite(std::string file, int newWrite, int address);

void deleteLines(std::string file, std::vector<int> lines);

void txtIns(std::string file, std::string newC, std::vector<coord> lnCol, int len = 0);

void appendFile(std::string file, std::string appendix);

