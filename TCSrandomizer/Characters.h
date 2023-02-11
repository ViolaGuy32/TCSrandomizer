#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Functions.h"
//#include "Level.h"

struct Level;

void charMaker();
void levMaker();

struct Playable {
	std::string name = "";
	std::string realName = "";
	int pointString = 0;

	float speed = 1.2;
	Level* lev;
	int price = 0;
	bool hat = 0, lever = 0, build = 0, box = 0, jump = 0, doubleJump = 0,
		highJump = 0, yodaJump = 0, extraHighJump = 0, realDoubleJump = 0,
		gunganJump = 0, dive = 0, flop = 0, hovering = 0, fly = 0, flutter = 0,
		fett = 0, attack = 0, shoot = 0, grapple = 0, fakeshoot = 0,
		zapper = 0, astrozapper = 0, jedi = 0, sith = 0, choke = 0, ghost = 0,
		saber = 0, deflect = 0, imperial = 0, astro = 0, proto = 0, droid = 0,
		passive = 0, gas = 0, bounty = 0, hatch = 0, tall = 0,
		extratoggle = 0, pushable = 0, chokeable = 0,
		trickable = 0, zappable = 0, storm = 0, slightlyBetterJump = 0,

		vehicle = 0, tow = 0, tiedoor = 0, vgreen = 0,

		leiaAlt = 0, landoAlt = 0, lukeAlt = 0, defaultCharacter = 0, storyMode = 0;

};

struct Level {
	std::vector<Playable*> party;
	std::vector<Playable*> vanillaParty;
	std::vector<Playable*> vanillaBonusCharacters;
	std::string name;
	std::string firstName;
	std::string path;
	//std::string episode;
	bool vehicleLevel = false;
	//int isFake;
	std::vector<Playable*> unlocks;
	std::vector<char> collectables;

	/*
	void mix();

	void add(int n);
	void log2();

	std::string directory(char scene = '\0', std::string fileExtention = "");
	std::string specialDirectory(char scene, std::string fileType);

	void replace(std::string newText, int length, std::vector<coord> coordinates, char scene = '\0', std::string fileExtention = "");

	void replace(int characterNumber, std::vector<coord> coordinates, char scene = '\0', std::string fileExtention = "");

	void specialReplace(std::string newText, int length, std::vector<coord> coordinates, char scene, std::string fileType);

	void specialReplace(int characterNumber, std::vector<coord> coordinates, char scene, std::string fileType);

	void rename(std::string newText, std::string oldText, char scene = '\0');

		void append(std::string appendix, char scene = '\0', std::string fileExtention = "");

	void rename(int characterNumber, char scene = '\0');

	void binWrite(std::string newText, std::vector<int> address, char scene = '\0', std::string fileExtention = "", int len = 0);
	void binWrite(int characterNumber, std::vector<int> address, char scene = '\0', std::string fileExtention = "");

	void mixCollectables();
	*/
};
/*
extern std::vector<Playable*> testing; //current logic


void renamer(std::string oldName, std::string newName);
void characterPointer(Playable* play, int address);
void multiPointer(Playable* play, std::vector<int> address);

extern Playable* defaultCharacter;


bool AlwaysTrue(std::vector<Playable*>);

bool Jedi(std::vector<Playable*> current = testing);

bool Sith(std::vector<Playable*> current = testing);

bool Saber(std::vector<Playable*> current = testing);

bool LivingJedi(std::vector<Playable*> current = testing);

bool Deflect(std::vector<Playable*> current = testing);

bool Ghost(std::vector<Playable*> current = testing);

bool Passive(std::vector<Playable*> current = testing);

bool Jump(std::vector<Playable*> current = testing);

bool DoubleTransitionSkip(bool(*ptr)(std::vector<Playable*>) = AlwaysTrue, std::vector<Playable*> current = testing);

bool TransitionSkip(bool(*ptr)(std::vector<Playable*>) = AlwaysTrue, std::vector<Playable*> current = testing);

bool Build(std::vector<Playable*> current = testing);

bool Box(std::vector<Playable*> current = testing);

bool Lever(std::vector<Playable*> current = testing);

bool DoubleJump(std::vector<Playable*> current = testing);

bool RealDoubleJump(std::vector<Playable*> current = testing);

bool HighJump(std::vector<Playable*> current = testing);

bool Tall(std::vector<Playable*> current = testing);

bool ExtraHighJump(std::vector<Playable*> current = testing);

bool GunganJump(std::vector<Playable*> current = testing);

bool YodaJump(std::vector<Playable*> current = testing);

bool Grapple(std::vector<Playable*> current = testing);

bool Shoot(std::vector<Playable*> current = testing);

bool FakeShoot(std::vector<Playable*> current = testing);

bool Attack(std::vector<Playable*> current = testing);

bool Hatch(std::vector<Playable*> current = testing);

bool Fly(std::vector<Playable*> current = testing);

bool Dive(std::vector<Playable*> current = testing);

bool Flop(std::vector<Playable*> current = testing);

bool Flutter(std::vector<Playable*> current = testing);

bool Hovering(std::vector<Playable*> current = testing);

bool Fett(std::vector<Playable*> current = testing);

bool Bounty(std::vector<Playable*> current = testing);

bool Imperial(std::vector<Playable*> current = testing);

bool Hat(std::vector<Playable*> current = testing);

bool Proto(std::vector<Playable*> current = testing);

bool Astro(std::vector<Playable*> current = testing);

bool Zapper(std::vector<Playable*> current = testing);

bool Droid(std::vector<Playable*> current = testing);

bool FalconJump(std::vector<Playable*> current = testing);

bool Tow(std::vector<Playable*> current = testing);

bool PlansThing(std::vector<Playable*> current = testing, Playable* shield = defaultCharacter, Playable* redGuy = defaultCharacter);

bool SuperJump(std::vector<bool(*)(std::vector<Playable*>)> vec = { AlwaysTrue }, std::vector<Playable*> current = testing);

bool InstantSuperJump(std::vector<bool(*)(std::vector<Playable*>)> vec = { AlwaysTrue }, std::vector<Playable*> current = testing);

float GetFastest(std::vector<Playable*> current = testing);

float GetSlowest(std::vector<Playable*> current = testing);

int GetType(int pref, bool (*ptr)(std::vector<Playable*>), std::vector<Playable*> current);

bool Any(std::vector<bool(*)(std::vector<Playable*>)> vec, std::vector<Playable*> current = testing);

bool All(std::vector<bool(*)(std::vector<Playable*>)> vec, std::vector<Playable*> current = testing);

bool Multi(bool(*ptr)(std::vector<Playable*>), int n, std::vector<Playable*> current = testing);

bool MultiAny(std::vector<bool (*)(std::vector<Playable*>)> vec, int n, std::vector<Playable*> current = testing = testing);

void logIt(Playable* ch, std::ofstream& log);

	*/