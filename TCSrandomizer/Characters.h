#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <unordered_map>

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
	const bool alwaysTrue = true; //lol

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

		leiaAlt = false, landoAlt = false, lukeAlt = false, defaultCharacter = false, storyMode = false;

};

struct Level {
	std::vector<Playable*> party;
	std::vector<Playable*> bonusCharacters; //characters you rescue but do not play as
	std::vector<Playable*> vanillaParty;
	std::vector<Playable*> vanillaBonusCharacters;
	std::string name;
	std::string shortName;
	std::string path;
	//std::string episode;
	bool vehicleLevel = false;
	//int isFake;
	std::vector<Playable*> unlocks;
	std::vector<char> collectables;

	std::unordered_map<std::vector<Playable*>, std::vector<Playable*>> vanillaMap = {
		{party, vanillaParty},
		{bonusCharacters, vanillaBonusCharacters}
	};
};

extern std::vector<Playable*> testing;

void add(int a);

void mix(Level* lev);

bool atrb(const bool(Playable::* atr), const std::vector<Playable*>& current = testing);

bool Multi(const bool Playable::* atr, const int n, const std::vector<Playable*>& current = testing);

bool Any(const std::initializer_list<bool Playable::*>& atrs, const std::vector<Playable*>& current = testing);

bool All(const std::initializer_list<bool Playable::*>& atrs, const std::vector<Playable*>& current = testing);

bool MultiAny(const std::initializer_list<bool Playable::*>& atrs, const int n, const std::vector<Playable*>& current = testing);

bool SuperJump(const bool Playable::* atr = &Playable::alwaysTrue, const std::vector<Playable*>& current = testing);

bool InstantSuperJump(const bool Playable::* atr = &Playable::alwaysTrue, const std::vector<Playable*>& current = testing);

bool LivingJedi(const std::vector<Playable*>& current = testing);

bool DoubleTransitionSkip(const bool Playable::* atr = &Playable::alwaysTrue, std::vector<Playable*>current = testing);

float GetFastest(std::vector<Playable*> current = testing);

float GetSlowest(std::vector<Playable*> current = testing);
