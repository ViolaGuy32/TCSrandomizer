#pragma once
#include "pch.h"

//#include "Level.h"

struct Level;

//void charMaker();
//void levMaker();

struct Playable {
	std::string name = "";
	std::string realName = "";
	unsigned int address = 0;

	float speed = 1.2;
	Level* lev;
	unsigned int price = 0;
	bool alwaysTrue = true; //lol

	bool hat = false, lever = false, build = false, box = false, jump = false, doubleJump = false,
		highJump = false, yodaJump = false, extraHighJump = false, realDoubleJump = false, highDoubleJump = false,
		gunganJump = false, dive = false, flop = false, hovering = false, fly = false, flutter = false,
		fett = false, attack = false, shoot = false, grapple = false, fakeshoot = false,
		zapper = false, astrozapper = false, jedi = false, sith = false, choke = false, ghost = false,
		saber = false, deflect = false, imperial = false, astro = false, proto = false, droid = false,
		passive = false, gas = false, bounty = false, hatch = false, tall = false,
		extratoggle = false, pushable = false, chokeable = false,
		trickable = false, zappable = false, storm = false, slightlyBetterJump = false,

		vehicle = false, tow = false, tiedoor = false, vgreen = false,

		leiaAlt = false, landoAlt = false, lukeAlt = false,
		defaultCharacter = false, storyMode = false, noLevel = false, allEpisodes = false,
		fake = false;


	Playable(std::string myName, std::string myRealName, unsigned int myPrice,
		unsigned int myAddress, float mySpeed, std::vector<bool Playable::*> Attributes);
};

//
//struct Spawn {
//	Playable*character;
//	Playable* VanillaCharacter;
//};


enum PanelType {
	AstroPanel, ProtoPanel, BountyPanel, ImperialPanel
};

enum DispenserType {
	RandomHat, LeiaHat, Fedora, TopHat, BaseballHat, StormtrooperHat, BountyHat
};

struct Panel {
	PanelType type;
	PanelType vanillaType;
	char scene;
	unsigned int address;
};

struct Dispenser {
	DispenserType type;
	DispenserType vanillaType;
	char scene;
	unsigned int address;
};


struct Collectable {
	char type;
	char scene;
	unsigned int address;
};

struct SpecialCollectable {
	char type;
	std::vector<std::pair<char, int>> sceneAddress;
};

//struct SpecialColelctable {
//	std::vector<Collectable>;
//};

struct Level {
	std::vector<Playable*> party;
	std::vector<Playable*> vanillaParty;
	std::vector<Playable*> bonusCharacters; //characters you rescue but do not play as
	std::vector<Playable*> vanillaBonusCharacters;

	std::vector<Panel> panels;
	std::vector<Dispenser> dispensers;

	std::string name;
	std::string shortName;
	std::string path;
	//std::string episode;
	bool vehicleLevel = false;
	//int isFake;
	std::vector<Playable*> unlocks;
	unsigned int collectIt = 0;

	std::vector<Collectable> collectables;
	std::vector<SpecialCollectable> specialCollectables;

	//std::array<char, 21> collectables =
	//{'m', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm',
	//'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'r'};

	Level(std::string myName, std::string myShortName, std::string myPath, bool isVehicleLevel,
		std::vector<Playable*> myVanillaParty, std::vector<Playable*> myVanillaBonusCharacters,
		std::vector<Playable*> myUnlocks,
		std::vector<Collectable> myCollectables, std::vector<SpecialCollectable> mySpecialCollectables);

};

extern std::vector<Playable*> testing;

void add(int a);

void mix(Level* lev);

bool atrb(const bool(Playable::* atr), const std::vector<Playable*>& current = testing);

bool Multi(const bool Playable::* atr, const  int n, const std::vector<Playable*>& current = testing);

bool Any(const std::initializer_list<bool Playable::*>& atrs, const std::vector<Playable*>& current = testing);

bool All(const std::initializer_list<bool Playable::*>& atrs, const std::vector<Playable*>& current = testing);

bool MultiAny(const std::initializer_list<bool Playable::*>& atrs, const int n, const std::vector<Playable*>& current = testing);

bool SuperJump(const bool Playable::* atr = &Playable::alwaysTrue, const std::vector<Playable*>& current = testing);

bool InstantSuperJump(const bool Playable::* atr = &Playable::alwaysTrue, const std::vector<Playable*>& current = testing);

bool LivingJedi(const std::vector<Playable*>& current = testing);

bool DoubleTransitionSkip(const bool Playable::* atr = &Playable::alwaysTrue, const  std::vector<Playable*> current = testing);

float GetFastest(const std::vector<Playable*> current = testing);

float GetSlowest(const std::vector<Playable*> current = testing);
