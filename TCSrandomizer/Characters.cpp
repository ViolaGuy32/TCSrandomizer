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
extern bool panelOp;
extern bool hatOp;

extern  std::mt19937_64* randoPTR;

extern std::vector<Level*> allLevels;

extern Playable* defaultCharacter;
extern Level* BHM;

extern LogicType logicType;

extern std::vector<Playable*> pls; //Characters and Vehicles
extern std::vector<Playable*> chs; //Characters
extern std::vector<Playable*> vhs; //Vehicles


Playable::Playable(std::string myName, std::string myRealName, int myPrice,
	int myAddress, float mySpeed, std::vector<bool Playable::*> Attributes)
	: name(myName), realName(myRealName), price(myPrice), address(myAddress), speed(mySpeed) {
	for (bool Playable::* atr : Attributes) {
		*this.*atr = true;
	}

	if (!this->passive) this->active = true;

	if (fake) return;
	pls.push_back(this);
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

Panel::Panel(PanelType myType, int myAddress)
	: type(myType), address(myAddress), altBody(-1), altColor(-1) {
}


Collectable::Collectable(char c, std::initializer_list<int> addresses) : scene(c) {
	for (int i : addresses) {
		typeAddress.push_back({'\0', i});
	}
}

SpecialCollectable::SpecialCollectable(char c, std::initializer_list<int>addresses) : type('\0') {
	//for minikits with multiple spawn points
	for (int i : addresses) {
		sceneAddress.push_back({c, i});
	}
}

//SpecialCollectable::SpecialCollectable(std::vector<Collectable> spawnPoints) {
//	for (Collectable& spawn : spawnPoints) {
//		for (std::pair<char, int>& p : spawn.typeAddress) {
//			sceneAddress.push_back({spawn.scene, p.second});
//		}
//	}
//}



SpecialCollectable::SpecialCollectable(std::initializer_list<std::pair<char, int>> mySceneAddress)
	: type('\0'), sceneAddress(mySceneAddress) {
	//BHP and Bespin have minikits that span multiple scenes
}

Level::Level(std::string myName, std::string myShortName, std::string myPath, bool isVehicleLevel,
	std::vector<Playable*> myVanillaParty, std::vector<Playable*> myVanillaBonusCharacters,
	std::vector<Playable*> myUnlocks,
	std::vector<Collectable> myCollectables, std::vector<SpecialCollectable> mySpecialCollectables,
	std::vector<PanelSet> myPanels, std::vector<DispenserSet> myDispensers)
	: name(myName), shortName(myShortName), path(myPath), vehicleLevel(isVehicleLevel), vanillaParty(myVanillaParty),
	party(myVanillaParty), vanillaBonusCharacters(myVanillaBonusCharacters), bonusCharacters(myVanillaBonusCharacters),
	collectables(myCollectables), specialCollectables(mySpecialCollectables), panels(myPanels), dispensers(myDispensers) {
	for (Playable* p : myUnlocks) {
		p->lev = this;
	}

	allLevels.push_back(this);
}



void add(int a) {

#ifdef _DEBUG
	logR(currentLev->name + ' ' + currentLev->party[a]->name);
#endif

	testing.push_back(currentLev->party[a]);
}

void addHat(int set, int hat, Level* lev) {
	availableHats.push_back(lev->dispensers[set].dispenser[hat].type);
}

void mix(Level* lev) {

	currentLev = lev;
	testing.clear();
	availableHats.clear();

	if (character) {

		lev->party.clear();
		lev->bonusCharacters.clear();
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

	} //character

	if (panelOp) {
		std::uniform_int_distribution<int> panDist(0, 3);
		for (PanelSet& panSet : lev->panels) {
			for (Panel& pan : panSet.panels) {
				pan.type = (PanelType)panDist(*randoPTR);
				if (pan.type == AstroPanel || pan.type == ProtoPanel) {
					std::uniform_int_distribution<int> bin(0, 1);
					pan.altColor = bin(*randoPTR);
					pan.altBody = bin(*randoPTR);
				}

			}
		}
	}

	if (hatOp) {
		std::uniform_int_distribution<int> hatDist(0, 2);
		for (DispenserSet& dispSet : lev->dispensers) {
			for (Dispenser& disp : dispSet.dispenser) {
				int temp = hatDist(*randoPTR);
				if (temp != 0) temp += 4;
				disp.type = (DispenserType)temp;
			}
		}
	}

	if (lev->party.size() != 0) {
		add(0);
		if (!lev->vehicleLevel || logicType != casual)
			add(1); //Only checks P1 in casual vehicle levels because casual logic does not have 1p2c
	}

}

std::string panelString(int panSet, int pan) {
	PanelType panType = currentLev->panels[panSet].panels[pan].type;

	if (panType == AstroPanel) return "astromech";
	if (panType == ProtoPanel) return "protocol";
	if (panType == BountyPanel) return "bounty_hunter";
	if (panType == ImperialPanel) return "stormtrooper"; //might not work
}

bool Playable::* getPanel(int panSet, int pan, Level* lev = currentLev) {
	PanelType panType = lev->panels[panSet].panels[pan].type;

	if (panType == AstroPanel) return Astro;
	if (panType == ProtoPanel) return Proto;
	if (panType == BountyPanel) return Bounty;
	if (panType == ImperialPanel) return Imperial;
}

bool panel(int panSet, int pan, const std::vector<Playable*>& current, std::vector<DispenserType> theHats) {
	bool Playable::* panType = getPanel(panSet, pan);

	if (atrb(panType, current)) return true;
	if (atrb(Hat, current)) {
		for (DispenserType disp : theHats) {
			if (disp == StormtrooperHat && panType == Imperial) return true;
			if (disp == BountyHat && panType == Bounty) return true;
		}
	}

	return false;
}

bool bhPanel(Level* lev, int panSet, int pan, std::vector<DispenserType> theHats) {
	bool Playable::* panType = getPanel(panSet, pan, lev);

	if (atrb(panType, BHM->party)) return true;
	if (atrb(Hat, BHM->party)) {
		for (DispenserType disp : theHats) {
			if (disp == StormtrooperHat && panType == Imperial) return true;
			if (disp == BountyHat && panType == Bounty) return true;
		}
	}

	return false;
}

bool panelAnd(int panSet, int pan, std::vector<bool Playable::*> atrs, const std::vector<Playable*>& current) {
	bool Playable::* panType = getPanel(panSet, pan);
	std::vector<bool Playable::*> atrs2 = atrs;
	atrs2.push_back(panType);
	if (All(atrs2, current)) return true;

	std::vector<bool Playable::*> atrs3 = atrs;
	atrs3.push_back(Hat);
	if (All(atrs3, current)) {
		for (DispenserType disp : availableHats) {
			if (disp == StormtrooperHat && panType == Imperial) return true;
			if (disp == BountyHat && panType == Bounty) return true;
		}
	}
	return false;
}

bool panelOr(int panSet, int pan, std::vector<bool Playable::*> ats, const std::vector<Playable*>& current) {
	bool Playable::* panType = getPanel(panSet, pan);
	for (bool Playable::* at : ats) {
		if (All({panType, at}, current)) return true;

		for (DispenserType disp : availableHats) {
			if (disp == StormtrooperHat && panType == Imperial) {
				if (All({Hat, at})) return true;
			}

			if (disp == BountyHat && panType == Bounty) {
				if (All({Hat, at})) return true;
			}
		}

	}
	return false;
}

bool panelSeparate(int panSet, int pan, bool Playable::* atr, const std::vector<Playable*>& current) {
	for (Playable* p : current) {
		for (Playable* p2 : current) {
			if (p != p2) {
				if (panel(panSet, pan, {p}) && p2->*atr) return true;
			}
		}
	}
	return false;
}

bool boom(const std::vector<Playable*>& current, std::vector<DispenserType> theHats) {
	if (atrb(Bounty, current)) return true;

	if (atrb(Hat, current)) {
		for (DispenserType disp : theHats) {
			if (disp == BountyHat) return true;
		}
	}

	return false;
}

bool atrb(const bool(Playable::* atr), const   std::vector<Playable*>& current) {
	//checks if anyone in party has given attribute
	for (Playable* p : current) {
		if (p->*atr) return true;
	}
	return false;
}

bool Any(const std::vector<bool Playable::*>& atrs, const std::vector<Playable*>& current) {
	//needs any of the given attributes
	for (Playable* p : current) {
		for (bool Playable::* atr : atrs) {
			if (p->*atr) return true;
		}
	}
	return false;
}

bool All(const std::vector<bool Playable::*>& atrs, const std::vector<Playable*>& current) {
	//needs all of the given attributes

	for (Playable* p : current) {
		int i = 0;
		for (bool Playable::* at : atrs) {
			if (!(p->*at)) break;
			if (i == atrs.size() - 1) return true;
			i++;
		}
	}
	return false;
}

bool Multi(const bool Playable::* atr, const int n, const std::vector<Playable*>& current) {
	//needs multiple with same attribute
	int x = 0;
	for (Playable* p : current) {
		if (p->*atr) {
			x++;
			if (x == n) {
				return true;
			}
		}
	}
	return false;
}

bool Separate(const bool Playable::* atr1, const bool Playable::* atr2, const std::vector<Playable*>& current) {
	for (Playable* p : current) {
		for (Playable* p2 : current) {
			if (p->*atr1 && p2->*atr2 && p != p2) {
				return true;
			}
		}
	}

	return false;
}

bool MultiAny(const std::vector<bool Playable::*>& atrs, const int n, const std::vector<Playable*>& current) {
	//needs multiple who have any of given attributes
	int x = 0;
	for (Playable* p : current) {
		for (bool(Playable::* atr) : atrs) {
			if (p->*atr) {
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
				if (x->lightning && y->lightningable && *y.*atr) return true;
				if (x->lightning && y->resistZap && *y.*atr) return true;
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

bool SuperJump(std::initializer_list<bool Playable::*> atrs, const  std::vector<Playable*>& current) {
	for (bool Playable::* atr : atrs) {
		if (SuperJump(atr, current)) return true;
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
				if (x->lightning && y->lightningable && *y.*atr) return true;
				if (x->lightning && y->resistZap && *y.*atr) return true;
				if (x->lukeAlt && y == gamorreanguard && *y.*atr) return true;
			}
		}
	}
	return false;
}

bool InstantSuperJump(std::initializer_list<bool Playable::*> atrs, const  std::vector<Playable*>& current) {
	for (bool Playable::* atr : atrs) {
		if (InstantSuperJump(atr, current)) return true;
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
			if (p1 != p2) {
				if (p1->saber && p2->*atr && !p2->ghost) return true;
			}
		}
	}
	return false;
}


bool DoubleTransitionSkip(std::initializer_list<bool Playable::*> atrs, const  std::vector<Playable*>& current) {
	for (bool Playable::* atr : atrs) {
		if (DoubleTransitionSkip(atr, current)) return true;
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

