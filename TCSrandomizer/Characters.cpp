#include "pch.h"

#include "Characters.h"
#include "App.h"
#include "Defines.h"
#include "OtherStuff.h"

extern std::string out;
extern bool extog;
extern bool greenVeh;
extern bool character;
extern  std::mt19937_64* randoPTR;

extern std::vector<std::shared_ptr<Level>> allLevels;

extern std::shared_ptr<Playable> defaultCharacter;
extern std::shared_ptr<Level> BHM;

extern LogicType logicType;

extern std::vector<std::shared_ptr<Playable>> pls; //Characters and Vehicles
extern std::vector<std::shared_ptr<Playable>> chs; //Characters
extern std::vector<std::shared_ptr<Playable>> vhs; //Vehicles
extern std::map<std::string, std::shared_ptr<Playable>> nameList;

extern std::shared_ptr<Level> currentLev;

Playable::Playable(std::string myName, std::string myRealName, unsigned int myPrice,
	unsigned int myAddress, float mySpeed, std::vector<bool Playable::*> Attributes)
	: name(myName), realName(myRealName), price(myPrice), address(myAddress), speed(mySpeed) {
	for (bool Playable::* atr : Attributes) {
		*this.*atr = true;
	}

	if (vehicle) {
		if (greenVeh || !vgreen) {
			vhs.push_back(std::make_shared<Playable>(this));

		}
	} else {
		if (extog || !extratoggle) {
			chs.push_back(std::make_shared<Playable>(this));

		}
	}
}


void levMaker() {
	std::ifstream readLevels("files/LEVELDATA.txt", std::ios::in);
	std::string line;
	std::string charName;
	std::shared_ptr<Level> parse;
	unsigned int levIt = 0;
	while (readLevels.good()) {
		parse = std::make_shared<Level>();
		getline(readLevels, parse->name);
		getline(readLevels, parse->shortName);
		getline(readLevels, parse->path);
		getline(readLevels, line);
		if (line == "vehicle") parse->vehicleLevel = true;

		getline(readLevels, line);
		std::istringstream iss(line);
		while (iss >> charName) {
			parse->vanillaParty.push_back(nameList[charName]);
		}

		getline(readLevels, line);
		std::istringstream is2(line);

		while (is2 >> charName) {
			parse->unlocks.push_back(nameList[charName]);
		}

		getline(readLevels, line);
		std::istringstream is3(line);
		while (is3 >> charName) {
			parse->vanillaBonusCharacters.push_back(nameList[charName]); //characters you rescue at ends of levels but don't play as
		}

		getline(readLevels, line);

		for (std::shared_ptr<Playable> p : parse->unlocks) {
			p->lev = parse;
		}
		allLevels.push_back(parse);
	}

	//Bounty Hunter Missions
	BHM = std::make_shared<Level>();

	BHM->name = "bounties";
	BHM->vanillaParty = {
		nameList["bobafett"],
		nameList["greedo"],
		nameList["ig88"],
		nameList["4lom"],
		nameList["bossk"],
		nameList["dengar"]
	};

	BHM->vanillaBonusCharacters = {
		nameList["quigonjinn"],
		nameList["amidala"],
		nameList["jarjarbinks"],
		nameList["macewindu"],
		nameList["kitfisto"],
		nameList["luminara"],
		nameList["kiadimundi"],
		nameList["rebelscum"],
		nameList["shaakti"],
		nameList["clone_ep3_sand"],

		nameList["r2d2"],
		nameList["benkenobi"],
		nameList["chewbacca"],
		nameList["princessleia"],
		nameList["admiralackbar"],
		nameList["yoda"],
		nameList["c3po"],
		nameList["landocalrissian"],
		nameList["lukeskywalker_tatooine"],
		nameList["hansolo"],
	};



}

void add(int a) {

#ifdef _DEBUG
	logR(currentLev->name + ' ' + currentLev->party[a]->name);
#endif

	testing.push_back(currentLev->party[a]);
}

void mix(std::shared_ptr<Level> lev) {
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

		//std::array<std::shared_ptr<Playable>>* menu;
		//if (lev->vehicleLevel)
		//	menu = &vhs;
		//else menu = &chs;

		if (lev->vehicleLevel) {
			std::uniform_int_distribution<int> distrib(0, vhs.size() - 1);

			std::map<std::shared_ptr<Playable>, bool> duplicateFinder;

			for (std::shared_ptr<Playable> p : vhs) { duplicateFinder[p] = false; }

			std::shared_ptr<Playable> temp;
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

			std::map<std::shared_ptr<Playable>, bool> duplicateFinder;
			for (std::shared_ptr<Playable> p : chs) { duplicateFinder[p] = false; }


			std::shared_ptr<Playable> temp;
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

bool atrb(const bool(Playable::* atr), const   std::vector<std::shared_ptr<Playable>>& current) {
	//checks if anyone in party has given attribute
	for (std::shared_ptr<Playable> p : current) {
		if (*p.*atr) return true;
	}
	return false;
}

bool Any(const std::initializer_list<bool Playable::*>& atrs, const   std::vector<std::shared_ptr<Playable>>& current) {
	//needs any of the given attributes
	for (std::shared_ptr<Playable> p : current) {
		for (bool Playable::* atr : atrs) {
			if (*p.*atr) return true;
		}
	}
	return false;
}

bool All(const std::initializer_list<bool Playable::*>& atrs, const  std::vector<std::shared_ptr<Playable>>& current) {
	//needs all of the given attributes
	/*for ( std::shared_ptr<Playable> p : current) {
		for (int i = 0; i < atrs.size(); ++i) {
			if (!(p->*atrs[i])) break;
			if (i == atrs.size() - 1) return true;
		}
	}*/
	int i = 0;
	//needs all of the given attributes
	for (std::shared_ptr<Playable> p : current) {
		for (bool Playable::* at : atrs) {
			if (!(*p.*at)) break;
			if (i == atrs.size() - 1) return true;
			i++;
		}
	}
	return false;
}

bool Multi(const bool Playable::* atr, const int n, const   std::vector<std::shared_ptr<Playable>>& current) {
	//needs multiple with same attribute
	int x = 0;
	for (std::shared_ptr<Playable> p : current) {
		if (*p.*atr) {
			x++;
			if (x == n) {
				return true;
			}
		}
	}
	return false;
}

bool MultiAny(const std::initializer_list<bool Playable::*>& atrs, const int n, const  std::vector<std::shared_ptr<Playable>>& current) {
	//needs multiple who have any of given attributes
	int x = 0;
	for (std::shared_ptr<Playable> p : current) {
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


bool SuperJump(const bool Playable::* atr, const  std::vector<std::shared_ptr<Playable>>& current) {
	if (logicType != superGlitched) return false;
	for (std::shared_ptr<Playable> x : current) {
		for (std::shared_ptr<Playable> y : current) {
			if (x != y) {
				if (x->jedi && y->pushable && *y.*atr) return true;
				if (x->choke && y->chokeable && *y.*atr) return true;
				if (x->zapper && y->zappable && *y.*atr) return true;
				if (x->jedi && y->trickable && *y.*atr) return true;
				if (x->astrozapper && y->storm && *y.*atr) return true;
				if (x->landoAlt && y->leiaAlt && *y.*atr) return true;
				if (x->lukeAlt && y == nameList["gamorreanguard"] && *y.*atr) return true;
			}
		}
	}
	return false;
}

bool InstantSuperJump(const bool Playable::* atr, const  std::vector<std::shared_ptr<Playable>>& current) {
	//can act immediatly after SJC
	if (logicType != superGlitched) return false;
	for (std::shared_ptr<Playable> x : current) {
		for (std::shared_ptr<Playable> y : current) {
			if (x != y) {
				if (x->jedi && y->jedi && *y.*atr) return true;
				if (x->chokeable && y->choke && *y.*atr) return true;
				if (x->lukeAlt && y == nameList["gamorreanguard"] && *y.*atr) return true;
			}
		}
	}
	return false;
}

bool LivingJedi(const std::vector<std::shared_ptr<Playable>>& current) {
	//ghosts break some bosses
	for (std::shared_ptr<Playable> p : current) {
		if (p->jedi && !p->ghost) return true;
	}
	return false;
}

bool DoubleTransitionSkip(const bool Playable::* atr, const std::vector<std::shared_ptr<Playable>>current) {
	for (std::shared_ptr<Playable> p1 : current) {
		for (std::shared_ptr<Playable> p2 : current) {
			if (p1->saber && *p2.*atr && !p2->ghost) return true;
		}
	}
	return false;
}

float GetFastest(const std::vector<std::shared_ptr<Playable>> current) {
	float fastest = 0.0f;
	for (std::shared_ptr<Playable> p : current) {
		if (p->speed > fastest) fastest = p->speed;
	}
	return fastest;
}

float GetSlowest(const std::vector<std::shared_ptr<Playable>> current) {
	float slowest = 100.0f;
	for (std::shared_ptr<Playable> p : current) {
		if (p->speed < slowest) slowest = p->speed;
	}
	return slowest;
}

