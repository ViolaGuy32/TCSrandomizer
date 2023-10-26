//This is just for testing purposes.

#include "Randomize.h"

#include "pch.h"

#include "Defines.h"
bool character = true;
bool extog = true;
bool greenVeh = true;

bool extra = true;
bool collectable = true;
bool panelOp = true;
bool hatOp = true;
bool colorOp = true;
bool enemyOp = true;
//bool advanceMus;
LogicType logicType = casual;
//std::unique_ptr<std::ofstream> loggingIt;

std::string out = "out";
std::string vanillaDirectory = "C:/TCS";

bool enemy = true;

int main() {
#ifdef _DEBUG
	std::cout << "TEST\n";
#endif
	Randomize();
}
