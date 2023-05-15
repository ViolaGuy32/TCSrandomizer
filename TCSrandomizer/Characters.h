#pragma once
#include "pch.h"

//#include "Level.h"

struct Level;

//void charMaker();
//void levMaker();

enum enemyScp { chatting, sniper, storm, attack, block, spawnattack, patrol };

struct Playable {
	std::string name = "";
	std::string realName = "";
	//std::string vanillaName = "";
	int address = 0;

	float speed = 1.2f;
	Level* lev;
	int price = 0;
	bool alwaysTrue = true; //lol

	const char* attackPattern;
	bool hat = false, lever = false, build = false, box = false, jump = false, doubleJump = false,
		 highJump = false, yodaJump = false, extraHighJump = false, realDoubleJump = false,
		 highDoubleJump = false, gunganJump = false, dive = false, flop = false, hovering = false,
		 fly = false, flutter = false, fett = false, attack = false, shoot = false, grapple = false,
		 fakeshoot = false, zapper = false, astrozapper = false, jedi = false, sith = false,
		 choke = false, ghost = false, saber = false, deflect = false, imperial = false,
		 astro = false, proto = false, droid = false, passive = false, gas = false, bounty = false,
		 hatch = false, tall = false, extratoggle = false, pushable = false, chokeable = false,
		 trickable = false, zappable = false, storm = false, slightlyBetterJump = false,
		 slightlyHigherJump = false,

		 lightning = false, lightningable = false, resistZap = false,

		 active = false, vehicle = false, tow = false, tiedoor = false, vgreen = false,

		 leiaAlt = false, landoAlt = false, lukeAlt = false, defaultCharacter = false,
		 storyMode = false, noLevel = false, allEpisodes = false, fake = false;

	std::unordered_map<enemyScp, std::string> enemyChart;
	Playable(std::string myName, std::string myRealName, int myPrice, int myAddress, float mySpeed,
		std::vector<bool Playable::*> Attributes,
		std::unordered_map<enemyScp, std::string> myChart = {}, const char* myAttackPattern = "");
};

//
//struct Spawn {
//	Playable*character;
//	Playable* VanillaCharacter;
//};

struct coord {
	unsigned int ln = 1;
	unsigned int col = 1;
};

enum PanelType { AstroPanel, ProtoPanel, BountyPanel, ImperialPanel };

enum DispenserType {
	RandomHat,
	LeiaHat,
	Fedora,
	TopHat,
	BaseballHat,
	StormtrooperHat,
	BountyHat,
	DroidPanel
};

struct Panel {
	PanelType type;
	int address;

	int altColor;
	int altBody;

	Panel(PanelType myType, int myAddress);
};

struct Dispenser {
	DispenserType type;
	int address;
};

struct PanelSet {
	char scene;
	std::vector<Panel> panels;
};

struct DispenserSet {
	char scene;
	std::vector<Dispenser> dispenser;
};

struct Collectable {
	char scene;
	std::vector<std::pair<char, int>> typeAddress;

	Collectable(char c, std::initializer_list<int> addresses);
};

struct SpecialCollectable {
	char type;
	std::vector<std::pair<char, int>> sceneAddress;
	SpecialCollectable(char c, std::initializer_list<int> addresses);
	//SpecialCollectable(std::vector<Collectable> spawnPoints);
	SpecialCollectable(std::initializer_list<std::pair<char, int>> mySceneAddress);
};

enum enemyWhere { scp, ai2, both };

struct Enemy {
	enemyWhere enemywhere;
	enemyScp scpFile;
	coord type;
	coord script;
	int address;

	Playable* newEn;
	Enemy(enemyScp myScp, coord myType, coord myScript);
	Enemy(enemyScp myScp, int myAddress, enemyWhere myWhere = ai2);
	//Enemy( enemyScp myScp, int myAddress, coord myType, coord myScript);
};

struct EnemySet {
	char scene;
	std::vector<Enemy> enemy;
};

struct SpecialScp {
	char scene;
	enemyScp scpFile;
	std::string fileName;
	//std::string fun;
	const char* fun;
	std::vector<Enemy> specialEnemies;
	std::string oldFunName;
	std::vector<Playable*> spEnemyTypes;
	bool redirect;

	std::string scpName;

	coord lnCol;
	std::vector<unsigned int> linesToDelete;

	SpecialScp(char myScene, enemyScp myScpFile, const char* myFileName, const char* myOldFunName,
		std::vector<int> myAddresses, const char* myFun, unsigned int start, unsigned int end);

	SpecialScp(char myScene, enemyScp myScpFile, const char* myScpName, const char* myFileName,
		const char* myOldFunFame, std::vector<int> myAddresses, unsigned int myLn);
};

struct Level {
	std::vector<Playable*> party;
	std::vector<Playable*> vanillaParty;
	std::vector<Playable*> bonusCharacters; //characters you rescue but do not play as
	std::vector<Playable*> vanillaBonusCharacters;

	std::vector<EnemySet> enemies;
	std::vector<SpecialScp> specialscp;
	std::vector<PanelSet> panels;
	std::vector<DispenserSet> dispensers;

	std::string name;
	std::string shortName;
	std::string path;
	bool vehicleLevel = false;
	bool fakeLevel = false;

	std::vector<Collectable> collectables;
	std::vector<SpecialCollectable> specialCollectables;

	std::vector<unsigned int> enemyRes;
	std::vector<Playable*> enemyTypes;

	Level(std::string myName, std::string myShortName, std::string myPath, bool isVehicleLevel,
		std::vector<Playable*> myVanillaParty, std::vector<Playable*> myVanillaBonusCharacters,
		std::vector<Playable*> myUnlocks, std::vector<Collectable> myCollectables,
		std::vector<SpecialCollectable> mySpecialCollectables, std::vector<PanelSet> myPanels,
		std::vector<DispenserSet> myDispensers, std::vector<SpecialScp> mySpecialScp = {},
		std::vector<EnemySet> myEnemies = {}, std::vector<unsigned int> myEnemyRes = {});
};

extern std::vector<DispenserType> availableHats;
extern std::vector<Playable*> testing;
extern Level* currentLev;

void add(int a);
void addHat(int set, int hat, Level* lev = currentLev);

void mix(Level* lev);

bool atrb(const bool(Playable::*atr), const std::vector<Playable*>& current = testing);

bool boom(const std::vector<Playable*>& current = testing,
	std::vector<DispenserType> theHats = availableHats);

bool Multi(const bool Playable::*atr, const int n, const std::vector<Playable*>& current = testing);

bool Any(
	const std::vector<bool Playable::*>& atrs, const std::vector<Playable*>& current = testing);

bool All(
	const std::vector<bool Playable::*>& atrs, const std::vector<Playable*>& current = testing);

bool Separate(const bool Playable::*atr1, const bool Playable::*atr2,
	const std::vector<Playable*>& current = testing);

bool MultiAny(const std::vector<bool Playable::*>& atrs, const int n,
	const std::vector<Playable*>& current = testing);

bool SuperJump(const bool Playable::*atr = &Playable::alwaysTrue,
	const std::vector<Playable*>& current = testing);

bool SuperJump(
	std::initializer_list<bool Playable::*> atrs, const std::vector<Playable*>& current = testing);

bool InstantSuperJump(const bool Playable::*atr = &Playable::alwaysTrue,
	const std::vector<Playable*>& current = testing);

bool Instant(
	std::initializer_list<bool Playable::*> atrs, const std::vector<Playable*>& current = testing);

bool LivingJedi(const std::vector<Playable*>& current = testing);

bool DoubleTransitionSkip(const bool Playable::*atr = &Playable::alwaysTrue,
	const std::vector<Playable*> current = testing);

bool DoubleTransitionSkip(
	std::initializer_list<bool Playable::*> atrs, const std::vector<Playable*>& current = testing);

float GetFastest(const std::vector<Playable*> current = testing);

float GetSlowest(const std::vector<Playable*> current = testing);

//bool Playable::*getPanel(int panSet, int pan);

bool panel(int panSet, int pan, const std::vector<Playable*>& current = testing,
	std::vector<DispenserType> theHats = availableHats);

bool bhPanel(Level* lev, int panSet, int pan, std::vector<DispenserType> theHats = availableHats);

bool panelAnd(int panSet, int pan, std::vector<bool Playable::*> atrs,
	const std::vector<Playable*>& current = testing);

bool panelOr(int panSet, int pan, std::vector<bool Playable::*> ats,
	const std::vector<Playable*>& current = testing);

bool panelSeparate(
	int panSet, int pan, bool Playable::*atr, const std::vector<Playable*>& current = testing);

std::string panelString(int panSet, int pan);