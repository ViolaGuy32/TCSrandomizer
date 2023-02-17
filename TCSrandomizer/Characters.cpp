#include "pch.h"

#include "externData.h"
#include "Characters.h"
#include "App.h"
#include "Defines.h"
#include "OtherStuff.h"

extern std::string out;
extern bool extog;
extern bool greenVeh;
extern bool character;
extern  std::mt19937_64* randoPTR;

extern std::vector<Level*> allLevels;

extern Playable* defaultCharacter;
extern Level* BHM;

extern LogicType logicType;

extern std::vector<Playable*> pls; //Characters and Vehicles
extern std::vector<Playable*> chs; //Characters
extern std::vector<Playable*> vhs; //Vehicles

extern Level* currentLev;

Playable::Playable(std::string myName, std::string myRealName, unsigned int myPrice,
	unsigned int myAddress, float mySpeed, std::vector<bool Playable::*> Attributes)
	: name(myName), realName(myRealName), price(myPrice), address(myAddress), speed(mySpeed) {
	for (bool Playable::* atr : Attributes) {
		*this.*atr = true;
	}
	if (fake) return;

	if (vehicle) {
		if (greenVeh || !vgreen) {
			vhs.push_back(this);

		}
	} else {
		if (extog || !extratoggle) {
			chs.push_back(this);

		}
	}
}

Level::Level(std::string myName, std::string myShortName, std::string myPath, bool isVehicleLevel,
	std::vector<Playable*> myVanillaParty, std::vector<Playable*> myVanillaBonusCharacters,
	std::vector<Playable*> myUnlocks,
	std::vector<Collectable> myCollectables, std::vector<SpecialCollectable> mySpecialCollectables)
	: name(myName), shortName(myShortName), path(myPath), vehicleLevel(isVehicleLevel), vanillaParty(myVanillaParty),
	party(myVanillaParty), vanillaBonusCharacters(myVanillaBonusCharacters), bonusCharacters(myVanillaBonusCharacters),
	unlocks(myUnlocks), collectables(myCollectables), specialCollectables(mySpecialCollectables) {
	allLevels.push_back(this);
}



void add(int a) {

#ifdef _DEBUG
	logR(currentLev->name + ' ' + currentLev->party[a]->name);
#endif

	testing.push_back(currentLev->party[a]);
}

void mix(Level* lev) {
	//generates random characters for given level
//
//#ifdef _DEBUG
//	if (lev->name != currentLev->name)
//		logR(lev->name);
//#endif

	testing.clear();
	lev->party.clear();
	lev->bonusCharacters.clear();
	currentLev = lev;

	if (character) {

		//std::array<Playable*>* menu;
		//if (lev->vehicleLevel)
		//	menu = &vhs;
		//else menu = &chs;

		if (lev->vehicleLevel) {
			std::uniform_int_distribution<int> distrib(0, vhs.size() - 1);

			std::map<Playable*, bool> duplicateFinder;

			for (Playable* p : vhs) { duplicateFinder[p] = false; }

			Playable* temp;
			for (int i = 0; i < lev->vanillaParty.size(); i++) {
				do { temp = (vhs)[distrib(*randoPTR)]; } while (duplicateFinder[temp] == true);
				duplicateFinder[temp] = true;
				lev->party.push_back(temp);
			}

			for (int i = 0; i < lev->vanillaBonusCharacters.size(); i++) {
				do { temp = (vhs)[distrib(*randoPTR)]; } while (duplicateFinder[temp] == true);
				duplicateFinder[temp] = true;
				lev->bonusCharacters.push_back(temp);
			}

		} else {
			std::uniform_int_distribution<int> distrib(0, chs.size() - 1);

			std::map<Playable*, bool> duplicateFinder;
			for (Playable* p : chs) { duplicateFinder[p] = false; }


			Playable* temp;
			for (int i = 0; i < lev->vanillaParty.size(); i++) {
				do { temp = (chs)[distrib(*randoPTR)]; } while (duplicateFinder[temp] == true);
				duplicateFinder[temp] = true;
				lev->party.push_back(temp);
			}

			for (int i = 0; i < lev->vanillaBonusCharacters.size(); i++) {
				do { temp = (chs)[distrib(*randoPTR)]; } while (duplicateFinder[temp] == true);
				duplicateFinder[temp] = true;
				lev->bonusCharacters.push_back(temp);
			}
		}

		add(0);
		if (!lev->vehicleLevel || logicType != casual)
			add(1); //Only checks P1 in casual vehicle levels because casual logic does not have 1p2c

		//prevents duplicates
		/*for (int i = 0; i < lev->vanillaParty.size() - 1; i++) {
			for (int j = i + 1; j < lev->vanillaParty.size(); j++) {
				if (lev->party[i] == lev->party[j]) goto label;
			}
		}*/
	}
}

bool atrb(const bool(Playable::* atr), const   std::vector<Playable*>& current) {
	//checks if anyone in party has given attribute
	for (Playable* p : current) {
		if (*p.*atr) return true;
	}
	return false;
}

bool Any(const std::initializer_list<bool Playable::*>& atrs, const   std::vector<Playable*>& current) {
	//needs any of the given attributes
	for (Playable* p : current) {
		for (bool Playable::* atr : atrs) {
			if (*p.*atr) return true;
		}
	}
	return false;
}

bool All(const std::initializer_list<bool Playable::*>& atrs, const  std::vector<Playable*>& current) {
	//needs all of the given attributes

	int i = 0;
	for (Playable* p : current) {
		for (bool Playable::* at : atrs) {
			if (!(*p.*at)) break;
			if (i == atrs.size() - 1) return true;
			i++;
		}
	}
	return false;
}

bool Multi(const bool Playable::* atr, const int n, const   std::vector<Playable*>& current) {
	//needs multiple with same attribute
	int x = 0;
	for (Playable* p : current) {
		if (*p.*atr) {
			x++;
			if (x == n) {
				return true;
			}
		}
	}
	return false;
}

bool MultiAny(const std::initializer_list<bool Playable::*>& atrs, const int n, const  std::vector<Playable*>& current) {
	//needs multiple who have any of given attributes
	int x = 0;
	for (Playable* p : current) {
		for (bool(Playable::* atr) : atrs) {
			if (*p.*atr) {
				x++;
				if (x == n) {
					return true;
				}
				break;
			}
		}
	}
	return false;
}


bool SuperJump(const bool Playable::* atr, const  std::vector<Playable*>& current) {
	if (logicType != superGlitched) return false;
	for (Playable* x : current) {
		for (Playable* y : current) {
			if (x != y) {
				if (x->jedi && y->pushable && *y.*atr) return true;
				if (x->choke && y->chokeable && *y.*atr) return true;
				if (x->zapper && y->zappable && *y.*atr) return true;
				if (x->jedi && y->trickable && *y.*atr) return true;
				if (x->astrozapper && y->storm && *y.*atr) return true;
				if (x->landoAlt && y->leiaAlt && *y.*atr) return true;
				if (x->lukeAlt && y == gamorreanguard && *y.*atr) return true;
			}
		}
	}
	return false;
}

bool InstantSuperJump(const bool Playable::* atr, const  std::vector<Playable*>& current) {
	//can act immediatly after SJC
	if (logicType != superGlitched) return false;
	for (Playable* x : current) {
		for (Playable* y : current) {
			if (x != y) {
				if (x->jedi && y->jedi && *y.*atr) return true;
				if (x->chokeable && y->choke && *y.*atr) return true;
				if (x->lukeAlt && y == gamorreanguard && *y.*atr) return true;
			}
		}
	}
	return false;
}

bool LivingJedi(const std::vector<Playable*>& current) {
	//ghosts break some bosses
	for (Playable* p : current) {
		if (p->jedi && !p->ghost) return true;
	}
	return false;
}

bool DoubleTransitionSkip(const bool Playable::* atr, const std::vector<Playable*>current) {
	for (Playable* p1 : current) {
		for (Playable* p2 : current) {
			if (p1->saber && *p2.*atr && !p2->ghost) return true;
		}
	}
	return false;
}

float GetFastest(const std::vector<Playable*> current) {
	float fastest = 0.0f;
	for (Playable* p : current) {
		if (p->speed > fastest) fastest = p->speed;
	}
	return fastest;
}

float GetSlowest(const std::vector<Playable*> current) {
	float slowest = 100.0f;
	for (Playable* p : current) {
		if (p->speed < slowest) slowest = p->speed;
	}
	return slowest;
}

