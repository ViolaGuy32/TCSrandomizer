#pragma once

#include "Characters.h"
#include "Defines.h"
#include "pch.h"
#include <stdint.h>

struct Playable;

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

enum enemyWhere { scp, ai2, both, chain };

struct Enemy {
	enemyWhere enemywhere;
	enemyScp scpFile;
	coord type;
	coord script;
	int address;

	std::string chainStr;
	Playable* newEn;
	Enemy(enemyScp myScp, coord myType, coord myScript);
	Enemy(enemyScp myScp, int myAddress, enemyWhere myWhere = ai2);
	//Enemy( enemyScp myScp, int myAddress, coord myType, coord myScript);
};

struct EnemySet {
	char scene;
	std::vector<Enemy> enemy;
};

struct DoubleNestedEnemy {
	std::string fileName;
	coord type;
	Playable* oldEn;
	coord script = {0, 0};
    enemyScp scpFile = special;
	Playable* newEn = nullptr;
};

struct NestedEnemy {
	enemyScp scpType;
	coord type;
	coord script;
	Playable* oldEn;
	int scpLen;
	int chainAdd = -1;
	Playable* newEn;
};

struct NestedEnemySet {
	char scene;
	std::string fileName;
	std::vector<NestedEnemy> nEns;
};

struct SpecialScpOverwrite {
    std::string oldFunName;
    unsigned int ln;
    std::string extraConditions;
    std::string extraActions;
};

struct SpecialScp {
	char scene;
	enemyScp scpFile;
	attackType atType;
	std::string fileName;
	//std::string fun;
	const char* fun;
	std::vector<Enemy> specialEnemies;
	std::string oldFunName;
	std::vector<Playable*> spEnemyTypes;
	std::vector<DoubleNestedEnemy> dNestEn;
	//bool redirect = false;
	bool inliner = false;
	bool newWay = false;

	std::string scpName;

	std::string attackPattern = "";
	std::string extraConditions = "";
	coord lnCol;
	//std::vector<unsigned int> linesToDelete;

    std::vector<SpecialScpOverwrite> overwriters;
	unsigned int start;
	unsigned int end;

	bool useAltScript;

	SpecialScp(char myScene, enemyScp myScpFile, const char* myFileName, const char* myOldFunName,
		std::vector<int> myAddresses, const char* myFun, coord myLnCol, std::vector<DoubleNestedEnemy> myDNestEn = {},
		bool myUseAltScript = false);

	//SpecialScp(char myScene, attackType myAtType, const char* myFileName, const char* myOldFunName,
	//    std::vector<int> myAddresses, const char* myFun, unsigned int myStart, unsigned int myEnd);

	SpecialScp(char myScene, const char* myFileName, const char* myOldFunFame, std::vector<int> myAddresses,
		unsigned int myLn, const char* myExtraConditions, const char* myExtraActions, std::vector<DoubleNestedEnemy> myDNestEn = {},
		bool myUseAltScript = false);
    
	SpecialScp(char myScene, const char* myFileName, std::vector<int> myAddresses,
		std::vector<SpecialScpOverwrite> myOverwriters, std::vector<DoubleNestedEnemy> myDNestEn = {},
		bool myUseAltScript = false);
};

struct Enemies {
	std::vector<SpecialScp> specialscp;
	std::vector<EnemySet> enemies;
	std::vector<NestedEnemySet> nestedEns;
	std::vector<unsigned int> enemyRes;
	std::vector<Playable*> enemyTypes = {};
};

struct Level {
	std::vector<Playable*> party;
	std::vector<Playable*> vanillaParty;
	std::vector<Playable*> bonusCharacters; //characters you rescue but do not play as
	std::vector<Playable*> vanillaBonusCharacters;

	std::vector<PanelSet> panels;
	std::vector<DispenserSet> dispensers;

	std::string name;
	std::string shortName;
	std::string path;
	bool vehicleLevel = false;
	bool fakeLevel = false;

	std::vector<Collectable> collectables;
	std::vector<SpecialCollectable> specialCollectables;

	Enemies enemies;

	Level(std::string myName, std::string myShortName, std::string myPath, bool isVehicleLevel,
		std::vector<Playable*> myVanillaParty, std::vector<Playable*> myVanillaBonusCharacters,
		std::vector<Playable*> myUnlocks, std::vector<Collectable> myCollectables,
		std::vector<SpecialCollectable> mySpecialCollectables, std::vector<PanelSet> myPanels,
		std::vector<DispenserSet> myDispensers);
};

extern std::vector<DispenserType> availableHats;
extern std::vector<Playable*> testing;
extern Level* currentLev;

void mix(Level*);
void add(int a);
void addHat(int set, int hat, Level* lev = currentLev);

bool atrb(uint64_t req, const std::vector<Playable*>& current = testing);

bool boom(const std::vector<Playable*>& current = testing, std::vector<DispenserType> theHats = availableHats);

bool Multi(uint64_t req, const int n, const std::vector<Playable*>& current = testing);

//bool Any(uint64_t req, const std::vector<Playable*>& current = testing);

bool All(uint64_t req, const std::vector<Playable*>& current = testing);

bool Separate(uint64_t req1, uint64_t req2, const std::vector<Playable*>& current = testing);

//bool MultiAny(const std::vector<bool Playable::*>& atrs, const int n, const std::vector<Playable*>& current =
//testing);

bool SuperJump(uint64_t oobReq = ~0, const std::vector<Playable*>& current = testing);

//bool SuperJump(std::initializer_list<bool Playable::*> atrs, const std::vector<Playable*>& current = testing);

bool InstantSuperJump(uint64_t oobReq = ~0, const std::vector<Playable*>& current = testing);

bool Instant(std::initializer_list<bool Playable::*> atrs, const std::vector<Playable*>& current = testing);

bool LivingJedi(const std::vector<Playable*>& current = testing);

bool DoubleTransitionSkip(uint64_t oobReq = ~0, const std::vector<Playable*> current = testing);
//
//bool DoubleTransitionSkip(
//	std::initializer_list<bool Playable::*> atrs, const std::vector<Playable*>& current = testing);

float GetFastest(const std::vector<Playable*> current = testing);

float GetSlowest(const std::vector<Playable*> current = testing);

//bool Playable::*getPanel(int panSet, int pan);

bool panel(int panSet, int pan, const std::vector<Playable*>& current = testing,
	std::vector<DispenserType> theHats = availableHats);

bool bhPanel(Level* lev, int panSet, int pan, std::vector<DispenserType> theHats = availableHats);

bool panelAnd(int panSet, int pan, uint64_t req, const std::vector<Playable*>& current = testing);

bool panelOr(int panSet, int pan, uint64_t req, const std::vector<Playable*>& current = testing);

//bool panelSeparate(int panSet, int pan, bool Playable::*atr, const std::vector<Playable*>& current = testing);

std::string panelString(int panSet, int pan);
