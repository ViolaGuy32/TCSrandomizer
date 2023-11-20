#include "Levels.h"
#include "Enemies.cpp"
#include "externData.h"

extern std::vector<Playable*> enemies;
extern std::vector<Level*> allLevels;

extern std::string out;
extern bool character;
extern bool panelOp;
extern bool hatOp;
extern bool enemyOp;

extern std::vector<Playable*> pls; //Characters and Vehicles
extern std::vector<Playable*> chs; //Characters
extern std::vector<Playable*> vhs; //Vehicles
extern std::mt19937_64* randoPTR;
extern LogicType logicType;
extern Level* BHM;

//Enemy::Enemy(enemyScp myScp, coord myType, coord myScript)
//	: enemywhere(scp), scpFile(myScp), type(myType), script(myScript), address(0) {}
//
//Enemy::Enemy(enemyScp myScp, int myAddress, enemyWhere myWhere)
//	: enemywhere(myWhere), scpFile(myScp), type({0, 0}), script({0, 0}), address(myAddress) {}
//
//SpecialScp::SpecialScp(char myScene, enemyScp myScpFile, const char* myFileName, const char* myOldFunName,
//	std::vector<int> myAddresses, const char* myFun, coord myLnCol, std::vector<DoubleNestedEnemy> myDNestEn,
//	bool myUseAltScript)
//	: scene(myScene), scpFile(myScpFile), fileName(myFileName), fun(myFun), oldFunName(myOldFunName), lnCol(myLnCol),
//	  dNestEn(myDNestEn), useAltScript(myUseAltScript) {
//	for (int address : myAddresses) {
//		specialEnemies.push_back({scpFile, address, ai2});
//	}
//}
//
//SpecialScp::SpecialScp(char myScene, const char* myFileName, const char* myOldFunName, std::vector<int> myAddresses,
//	unsigned int myLn, const char* myExtraConditions, const char* myExtraActions, std::vector<DoubleNestedEnemy>
//myDNestEn, bool myUseAltScript) 	: scene(myScene), fileName(myFileName), newWay(true), dNestEn(myDNestEn),
//useAltScript(myUseAltScript) { 	overwriters.push_back({myOldFunName, myLn, myExtraConditions, myExtraActions});
//for (int address : myAddresses) { 		specialEnemies.push_back({scpFile, address, ai2});
//	}
//}
//
//SpecialScp::SpecialScp(char myScene, const char* myFileName, std::vector<int> myAddresses,
//	std::vector<SpecialScpOverwrite> myOverwriters, std::vector<DoubleNestedEnemy> myDNestEn, bool myUseAltScript)
//	: scene(myScene), fileName(myFileName), overwriters(myOverwriters), newWay(true), dNestEn(myDNestEn),
//	  useAltScript(myUseAltScript) {
//	for (int address : myAddresses) {
//		specialEnemies.push_back({scpFile, address, ai2});
//	}
//}

//SpecialScp::SpecialScp(char myScene, attackType myAtType, const char* myFileName, const char* myOldFunName,
//    std::vector<int> myAddresses, const char* myFun, unsigned int myStart, unsigned int myEnd)
//    : scene(myScene), atType(myAtType), fileName(myFileName), oldFunName(myOldFunName), redirect(false), fun(myFun),
//      inliner(true), start(myStart), end(myEnd) {
//
//	for (int address : myAddresses) {
//		specialEnemies.push_back({scpFile, address, ai2});
//	}
//}

Panel::Panel(PanelType myType, int myAddress) : type(myType), address(myAddress), altBody(-1), altColor(-1) {}

Collectable::Collectable(char c, std::initializer_list<int> addresses) : scene(c) {
	for (int i : addresses) {
		typeAddress.push_back({'\0', i});
	}
}

SpecialCollectable::SpecialCollectable(char c, std::initializer_list<int> addresses) : type('\0') {
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
	std::vector<Playable*> myUnlocks, std::vector<Collectable> myCollectables,
	std::vector<SpecialCollectable> mySpecialCollectables, std::vector<PanelSet> myPanels,
	std::vector<DispenserSet> myDispensers, std::vector<unsigned int> myEnemyLines)
	: name(myName), shortName(myShortName), path(myPath), vehicleLevel(isVehicleLevel), vanillaParty(myVanillaParty),
	  party(myVanillaParty), vanillaBonusCharacters(myVanillaBonusCharacters),
	  bonusCharacters(myVanillaBonusCharacters), collectables(myCollectables),
	  specialCollectables(mySpecialCollectables), panels(myPanels), dispensers(myDispensers), enemyLines(myEnemyLines) {
	for (Playable* p : myUnlocks) {
		p->lev = this;
	}

	allLevels.push_back(this);
}

void add(int a) {

#ifdef _DEBUG
//logR(currentLev->name + ' ' + currentLev->party[a]->name);
#endif
	testing.push_back(currentLev->party[a]);
}

void addHat(int set, int hat, Level* lev) {
	availableHats.push_back(lev->dispensers[set].dispenser[hat].type);
}

void mix(Level* lev) {
	//wxLogStatus(lev->name.c_str());
	if (lev != currentLev) std::cout << lev->name.c_str() << " Done." << std::endl;
	currentLev = lev;
	testing.clear();
	availableHats.clear();

	if (character) {

		lev->party.clear();
		lev->bonusCharacters.clear();
		if (lev->vehicleLevel) {
			std::uniform_int_distribution<int> distrib(0, vhs.size() - 1);

			std::unordered_map<Playable*, bool> duplicateFinder;

			for (Playable* p : vhs) {
				duplicateFinder[p] = false;
			}

			Playable* temp;
			for (int i = 0; i < lev->vanillaParty.size(); i++) {
				do {
					temp = (vhs)[distrib(*randoPTR)];
				} while (duplicateFinder[temp] == true);
				duplicateFinder[temp] = true;
				lev->party.push_back(temp);
			}

			for (int i = 0; i < lev->vanillaBonusCharacters.size(); i++) {
				do {
					temp = (vhs)[distrib(*randoPTR)];
				} while (duplicateFinder[temp] == true);
				duplicateFinder[temp] = true;
				lev->bonusCharacters.push_back(temp);
			}

		} else {
			std::uniform_int_distribution<int> distrib(0, chs.size() - 1);

			std::unordered_map<Playable*, bool> duplicateFinder;
			for (Playable* p : chs) {
				duplicateFinder[p] = false;
			}

			Playable* temp;
			for (int i = 0; i < lev->vanillaParty.size(); i++) {
				do {
					temp = (chs)[distrib(*randoPTR)];
				} while (duplicateFinder[temp] == true);
				duplicateFinder[temp] = true;
				lev->party.push_back(temp);
			}

			for (int i = 0; i < lev->vanillaBonusCharacters.size(); i++) {
				do {
					temp = (chs)[distrib(*randoPTR)];
				} while (duplicateFinder[temp] == true);
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

	if (enemyOp) {
		std::uniform_int_distribution<int> enemyDist(0, enemyTypes.size() - 1);
		std::uniform_int_distribution<int> flyerDist(0, flyerTypes.size() - 1);
		std::uniform_int_distribution<int> walkerDist(0, walkerTypes.size() - 1);
		for (EnemySet& enSet : lev->enemies) {
			for (Enemy& en : enSet.enemy) {
				//if (en.category == normal) en.newType = enemyTypes[enemyDist(*randoPTR)];
				if (en.category == normal) en.newType = bodyguard_en;
				else if (en.category == flyer) en.newType = flyerTypes[flyerDist(*randoPTR)];
				else if (en.category == walker) en.newType = walkerTypes[walkerDist(*randoPTR)];
			}
		}
	}

	if (lev->party.size() != 0) {
		add(0);
		if (!lev->vehicleLevel || logicType != casual)
			add(1); //Only checks P1 in casual vehicle levels
					//because casual logic does not have 1p2c
	}

	//if (enemyOp) {
	//	std::uniform_int_distribution<int> distrib(0, enemies.size() - 1);
	//	for (NestedEnemySet& nestSet : lev->enemies.nestedEns) {
	//		for (NestedEnemy& nest : nestSet.nEns) {
	//			nest.newEn = enemies[distrib(*randoPTR)];
	//		}
	//	}
	//	for (EnemySet& enSet : lev->enemies.enemies) {
	//		for (Enemy& en : enSet.enemy) {
	//
	//			en.newEn = enemies[distrib(*randoPTR)];
	//		}
	//	}
	//	for (SpecialScp& sp : lev->enemies.specialscp) {
	//		for (Enemy& spEn : sp.specialEnemies) {
	//
	//			spEn.newEn = enemies[distrib(*randoPTR)];
	//		}
	//		for (DoubleNestedEnemy& dne : sp.dNestEn) {
	//
	//			dne.newEn = enemies[distrib(*randoPTR)];
	//		}
	//	}
	//}
}

std::string panelString(int panSet, int pan) {
	PanelType panType = currentLev->panels[panSet].panels[pan].type;

	if (panType == AstroPanel) return "astromech";
	if (panType == ProtoPanel) return "protocol";
	if (panType == BountyPanel) return "bounty_hunter";
	if (panType == ImperialPanel) return "stormtrooper"; //might not work
	return "";
}

uint64_t getPanel(int panSet, int pan, Level* lev = currentLev) {
	PanelType panType = lev->panels[panSet].panels[pan].type;

	if (panType == AstroPanel) return Astro;
	if (panType == ProtoPanel) return Proto;
	if (panType == BountyPanel) return Bounty;
	if (panType == ImperialPanel) return Imperial;
	return Astro;
}

bool panel(int panSet, int pan, const std::vector<Playable*>& current, std::vector<DispenserType> theHats) {
	uint64_t panType = getPanel(panSet, pan);

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
	uint64_t panType = getPanel(panSet, pan, lev);

	if (atrb(panType, BHM->party)) return true;
	if (atrb(Hat, BHM->party)) {
		for (DispenserType disp : theHats) {
			if (disp == StormtrooperHat && panType == Imperial) return true;
			if (disp == BountyHat && panType == Bounty) return true;
		}
	}

	return false;
}

bool panelAnd(int panSet, int pan, uint64_t req, const std::vector<Playable*>& current) {
	uint64_t panType = getPanel(panSet, pan);
	uint64_t req2 = req | panType;
	if (All(req2, current)) return true;

	uint64_t req3 = req | Hat;
	if (All(req3, current)) {
		for (DispenserType disp : availableHats) {
			if (disp == StormtrooperHat && panType == Imperial) return true;
			if (disp == BountyHat && panType == Bounty) return true;
		}
	}
	return false;
}

bool panelOr(int panSet, int pan, uint64_t req, const std::vector<Playable*>& current) {
	//Need either panel or any in req
	uint64_t panType = getPanel(panSet, pan);
	if (atrb(panType | req, current)) return true;

	for (DispenserType disp : availableHats) {
		if (disp == StormtrooperHat && panType == Imperial) {
			if (atrb(Hat, current)) return true;
		}

		if (disp == BountyHat && panType == Bounty) {
			if (atrb(Hat, current)) return true;
		}
	}
	return false;
}

//
//bool panelSeparate(int panSet, int pan, bool Playable::*atr, const std::vector<Playable*>& current) {
//	for (Playable* p : current) {
//		for (Playable* p2 : current) {
//			if (p != p2) {
//				if (panel(panSet, pan, {p}) && p2->*atr) return true;
//			}
//		}
//	}
//	return false;
//}

bool boom(const std::vector<Playable*>& current, std::vector<DispenserType> theHats) {
	if (atrb(Bounty, current)) return true;

	if (atrb(Hat, current)) {
		for (DispenserType disp : theHats) {
			if (disp == BountyHat) return true;
		}
	}

	return false;
}

bool atrb(uint64_t req, const std::vector<Playable*>& current) {
	//checks if anyone in party has any given attribute
	for (Playable* p : current) {
		if (p->check(req)) return true;
	}
	return false;
}

//bool Any(const std::vector<bool Playable::*>& atrs, const std::vector<Playable*>& current) {
//	//needs any of the given attributes
//	for (Playable* p : current) {
//		for (bool Playable::*atr : atrs) {
//			if (p->*atr) return true;
//		}
//	}
//	return false;
//}

bool All(uint64_t req, const std::vector<Playable*>& current) {
	//needs all of the given attributes

	for (Playable* p : current) {
		if (!(req & ~p->att)) return true;
		//int i = 0;
		//for (bool Playable::*at : atrs) {
		//	if (!(p->*at)) break;
		//	if (i == atrs.size() - 1) return true;
		//	i++;
		//}
	}
	return false;
}

bool Multi(uint64_t req, const int n, const std::vector<Playable*>& current) {
	//needs multiple with any of given attributes
	int x = 0;
	for (Playable* p : current) {
		if (p->check(req)) {
			x++;
			if (x == n) {
				return true;
			}
		}
	}
	return false;
}

bool Separate(uint64_t req1, uint64_t req2, const std::vector<Playable*>& current) {
	for (Playable* p : current) {
		for (Playable* p2 : current) {
			if (p->check(req1) && p2->check(req2) && p != p2) {
				return true;
			}
		}
	}

	return false;
}

//bool MultiAny(const std::vector<bool Playable::*>& atrs, const int n, const std::vector<Playable*>& current) {
//	//needs multiple who have any of given attributes
//	int x = 0;
//	for (Playable* p : current) {
//		for (bool(Playable::*atr) : atrs) {
//			if (p->*atr) {
//				x++;
//				if (x == n) {
//					return true;
//				}
//				break;
//			}
//		}
//	}
//	return false;
//}

bool SuperJump(uint64_t oobReq, const std::vector<Playable*>& current) {
	//only needs one from oobReq
	if (logicType != superGlitched) return false;
	for (Playable* x : current) {
		for (Playable* y : current) {
			if (x != y) {
				if (x->check(Jedi) && y->check(Pushable) && y->check(oobReq)) return true;
				if (x->check(Choke) && y->check(Chokeable) && y->check(oobReq)) return true;
				if (x->check(Lightning) && y->check(Lightningable) && y->check(oobReq)) return true;
				if (x->check(Lightning) && y->check(ResistZap) && y->check(oobReq)) return true;
				if (x->check(Zapper) && y->check(Zappable) && y->check(oobReq)) return true;
				if (x->check(Jedi) && y->check(Trickable) && y->check(oobReq)) return true;
				if (x->check(AstroZapper) && y->check(Storm) && y->check(oobReq)) return true;
				if (x->check(LandoAlt) && y->check(LeiaAlt) && y->check(oobReq)) return true;
				if (x->check(LukeAlt) && y == gamorreanguard && y->check(oobReq)) return true;
			}
		}
	}
	return false;
}

//bool SuperJump(std::initializer_list<bool Playable::*> atrs, const std::vector<Playable*>& current) {
//	for (bool Playable::*atr : atrs) {
//		if (SuperJump(atr, current)) return true;
//	}
//	return false;
//}

bool InstantSuperJump(uint64_t oobReq, const std::vector<Playable*>& current) {
	//can act immediatly after SJC
	if (logicType != superGlitched) return false;
	for (Playable* x : current) {
		for (Playable* y : current) {
			if (x != y) {
				if (x->check(Jedi) && y->check(Jedi) && y->check(oobReq)) return true;
				if (x->check(Chokeable) && y->check(Choke) && y->check(oobReq)) return true;
				if (x->check(Lightning) && y->check(Lightningable) && y->check(oobReq)) return true;
				if (x->check(Lightning) && y->check(ResistZap) && y->check(oobReq)) return true;
				if (x->check(LukeAlt) && y == gamorreanguard && y->check(oobReq)) return true;
			}
		}
	}
	return false;
}

//bool InstantSuperJump(std::initializer_list<bool Playable::*> atrs, const std::vector<Playable*>& current) {
//	for (bool Playable::*atr : atrs) {
//		if (InstantSuperJump(atr, current)) return true;
//	}
//	return false;
//}

bool LivingJedi(const std::vector<Playable*>& current) {
	//ghosts break some bosses
	for (Playable* p : current) {
		if (p->check(Jedi) && !p->check(Ghost)) return true;
	}
	return false;
}

bool DoubleTransitionSkip(uint64_t oobReq, const std::vector<Playable*> current) {
	for (Playable* p1 : current) {
		for (Playable* p2 : current) {
			if (p1 != p2) {
				if (p1->check(Saber) && p2->check(oobReq) && !p2->check(Ghost)) return true;
			}
		}
	}
	return false;
}

//bool DoubleTransitionSkip(std::initializer_list<bool Playable::*> atrs, const std::vector<Playable*>& current) {
//	for (bool Playable::*atr : atrs) {
//		if (DoubleTransitionSkip(atr, current)) return true;
//	}
//	return false;
//}

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
