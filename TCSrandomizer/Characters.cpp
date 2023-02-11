#include "Characters.h"
#include "App.h"
#include "Defines.h"
#include <wx/wx.h>
#include <sstream>
#include <unordered_map>

extern std::string out;
extern bool extog;
extern bool greenVeh;
extern bool character;
std::vector <Level*> allLevels;

Playable* pi;

extern LogicType logicType;

extern std::vector<Playable*> pls; //Characters and Vehicles
extern std::vector<Playable*> chs; //Characters
extern std::vector<Playable*> vhs; //Vehicles
extern std::unordered_map<std::string, Playable*> nameList;

//enum charID {
//	quigon,
//	obiwan,
//	tc14,
//	jarjar,
//	amidala,
//	panaka,
//	padmeBattle,
//	r2d2,
//	anakinBoy,
//	obiwanJedi,
//	r4p17,
//	anakinPadawan,
//	padmeGeonosis,
//	c3po,
//	macewindu,
//	padmeClawed,
//	yoda,
//	obiwanEp3,
//	anakinJedi,
//	palpatine,
//	cody,
//	chewbacca,
//	leia,
//	antilles,
//	rebelFriend,
//	lukeTatooine,
//	benKenobi,
//	han,
//	hanStormtrooper,
//	lukeStormtrooper,
//	hanHoth,
//	leiaHoth,
//	lukePilot,
//	lukeDagobah,
//	lukeBespin,
//	lando,
//	leiaBespin,
//	lukeJedi,
//	leiaBoushh,
//	landoPalaceGuard,
//	hanSkiff,
//	leiaSlave,
//	leiaEndor,
//	lukeEndor,
//	hanEndor,
//	wicket,
//	vader,
//	gonk,
//	pkdroid,
//	battledroid,
//	battledroidSecurity,
//	battledroidCommander,
//	droideka,
//	tarpals,
//	bossnass,
//	royalguard,
//	padme,
//	watto,
//	pitdroid,
//	maul,
//	zam,
//	dexter,
//	clone,
//	lamasu,
//	taunwe,
//	geonosian,
//	battledroidGeonosis,
//	superbattledroid,
//	jango,
//	bobafettBoy,
//	luminara,
//	kiadimundi,
//	kitfisto,
//	shaakti,
//	aaylasecura,
//	plokoon,
//	dooku,
//	magnaguard,
//	grievous,
//	wookiee,
//	cloneEp3,
//	clonePilot,
//	cloneSwamp,
//	cloneWalker,
//	macewinduEp3,
//	disguisedclone,
//	rebeltrooper,
//	stormtrooper,
//	imperialshuttlepilot,
//	tuskenraider,
//	jawa,
//	sandtrooper,
//	greedo,
//	imperialspy,
//	beachtrooper,
//	deathstartrooper,
//	tiefighterpilot,
//	imperialofficer,
//	tarkin,
//	hanHood,
//	rebelHoth,
//	rebelPilot,
//	snowtrooper,
//	lukeHoth,
//	lobot,
//	ugnaught,
//	bespinguard,
//	leiaPrisoner,
//	gamorreanguard,
//	bibfortuna,
//	palaceguard,
//	bossk,
//	skiffguard,
//	boba,
//	ewok,
//	imperialguard,
//	emperor,
//	ackbar,
//	ig88,
//	dengar,
//	f4lom,
//	benghost,
//	anakinghost,
//	yodaghost,
//	r2q5,
//	indianajones,
//	trainingremote,
//	buzzdroid,
//	skeleton,
//	mousedroid,
//	womprat,
//	rebelengineer,
//	imperialengineer,
//	atatdriver,
//	scouttrooper,
//	hanCarbonite,
//	droid1,
//	droid2,
//	droid3,
//	droid4,
//
//	anakinsPod,
//	nabooStarfighter,
//	anakinsSpeeder,
//	gunship,
//	starfighterYellow,
//	starfighterRed,
//	xwing,
//	ywing,
//	snowspeeder,
//	milleniumFalcon,
//	sebulbasPod,
//	zamsAirspeeder,
//	droidTrifighter,
//	vultureDroid,
//	arcfighter,
//	tiefighter,
//	tieinterceptor,
//	tiefighterVader,
//	tiebomber,
//	imperialshuttle,
//	slave1,
//	anakinsPodGreen,
//	nabooStarfighterGreen,
//	anakinsSpeederGreen,
//	gunshipGreen,
//};
//
//extern Level* Negotiations;
//extern Level* Invasion;
//extern Level* EscapeNaboo;
//extern Level* Podrace;
//extern Level* Theed;
//extern Level* Maul;
//
//extern Level* BHP;
//extern Level* Kamino;
//extern Level* Factory;
//extern Level* JediBattle;
//extern Level* Gunship;
//extern Level* Dooku;
//
//extern Level* Coruscant;
//extern Level* Chancellor;
//extern Level* Grievous;
//extern Level* Kashyyyk;
//extern Level* Ruin;
//extern Level* Vader;
//
//extern Level* SecretPlans;
//extern Level* Jundland;
//extern Level* Spaceport;
//extern Level* Princess;
//extern Level* DSE;
//extern Level* RebelAttack;
//
//extern Level* Hoth;
//extern Level* EchoBase;
//extern Level* FalconFlight;
//extern Level* Dagobah;
//extern Level* CCT;
//extern Level* Bespin;
//
//extern Level* Jabbas;
//extern Level* Carkoon;
//extern Level* Showdown;
//extern Level* Endor;
//extern Level* Destiny;
//extern Level* ITDS;
//
//extern Level* Anakinsflight;
//extern Level* ANewHope;
//
//extern Level* BHM;
//
//extern Level* defaultLevel;
//extern Level* allEpisodes;

void charMaker() {
	std::ifstream readCharacters("files/CHARACTERDATA.txt", std::ios::in);

	std::unordered_map<std::string, bool(Playable::*)> attributes;
	attributes["hat"] = &Playable::hat;
	attributes["lever"] = &Playable::lever;
	attributes["build"] = &Playable::build;
	attributes["box"] = &Playable::box;
	attributes["jump"] = &Playable::jump;
	attributes["doubleJump"] = &Playable::doubleJump;
	attributes["highJump"] = &Playable::highJump;
	attributes["yodaJump"] = &Playable::yodaJump;
	attributes["extraHighJump"] = &Playable::extraHighJump;
	attributes["realDoubleJump"] = &Playable::realDoubleJump;
	attributes["gunganJump"] = &Playable::gunganJump;
	attributes["dive"] = &Playable::dive;
	attributes["flop"] = &Playable::flop;
	attributes["hovering"] = &Playable::hovering;
	attributes["fly"] = &Playable::fly;
	attributes["flutter"] = &Playable::flutter;
	attributes["fett"] = &Playable::fett;
	attributes["attack"] = &Playable::attack;
	attributes["shoot"] = &Playable::shoot;
	attributes["grapple"] = &Playable::grapple;
	attributes["fakeshoot"] = &Playable::fakeshoot;
	attributes["zapper"] = &Playable::zapper;
	attributes["astrozapper"] = &Playable::astrozapper;
	attributes["jedi"] = &Playable::jedi;
	attributes["sith"] = &Playable::sith;
	attributes["choke"] = &Playable::choke;
	attributes["ghost"] = &Playable::ghost;
	attributes["saber"] = &Playable::saber;
	attributes["deflect"] = &Playable::deflect;
	attributes["imperial"] = &Playable::imperial;
	attributes["astro"] = &Playable::astro;
	attributes["proto"] = &Playable::proto;
	attributes["droid"] = &Playable::droid;
	attributes["passive"] = &Playable::passive;
	attributes["gas"] = &Playable::gas;
	attributes["bounty"] = &Playable::bounty;
	attributes["hatch"] = &Playable::hatch;
	attributes["tall"] = &Playable::tall;
	attributes["extratoggle"] = &Playable::extratoggle;
	attributes["pushable"] = &Playable::pushable;
	attributes["chokeable"] = &Playable::chokeable;
	attributes["trickable"] = &Playable::trickable;
	attributes["zappable"] = &Playable::zappable;
	attributes["storm"] = &Playable::storm;
	attributes["slightlyBetterJump"] = &Playable::slightlyBetterJump;
	attributes["vehicle"] = &Playable::vehicle;
	attributes["tow"] = &Playable::tow;
	attributes["tiedoor"] = &Playable::tiedoor;
	attributes["vgreen"] = &Playable::vgreen;
	attributes["leiaAlt"] = &Playable::leiaAlt;
	attributes["landoAlt"] = &Playable::landoAlt;
	attributes["lukeAlt"] = &Playable::lukeAlt;

	if (readCharacters.is_open()) {
		std::string line;
		Playable* parse;
		while (readCharacters.good()) {
			parse = new Playable;
			getline(readCharacters, parse->name);
			getline(readCharacters, parse->realName);
			readCharacters >> parse->price;
			readCharacters >> std::hex >> parse->pointString;
			readCharacters >> parse->speed;
			getline(readCharacters, line);
			getline(readCharacters, line);

			while (line != "") {
				parse->*(attributes[line]) = true; //Don't you just love C syntax?
				getline(readCharacters, line);
			}
			nameList[parse->name] = parse; //so I can reference them in the level data
			pls.push_back(parse);
		}
	}

}

void levMaker() {
	std::ifstream readLevels("files/LEVELDATA.txt", std::ios::in);
	if (readLevels.is_open()) {
		std::string line;
		std::string charName;
		std::istringstream iss(line);
		Level* parse;
		while (readLevels.good()) {
			parse = new Level;
			getline(readLevels, parse->name);
			getline(readLevels, parse->path);
			getline(readLevels, line);
			if (line == "vehicle") parse->vehicleLevel = true;

			getline(readLevels, line);
			while (iss >> charName) {
				parse->vanillaParty.push_back(nameList[charName]);
			}

			getline(readLevels, line);
			while (iss >> charName) {
				parse->unlocks.push_back(nameList[charName]);
			}
			
			getline(readLevels, line);
			while (iss >> charName) {
				parse->vanillaBonusCharacters.push_back(nameList[charName]); //characters you rescue at ends of levels but don't play as
			}

			allLevels.push_back(parse);
		}
	}

}
/*
#if (0)
void renamer(std::string oldName, std::string newName) {
	int test = rename(oldName.c_str(), newName.c_str());
	if (test == -1) {
		wxString err = "File name override failed: " + oldName + " -> " + newName;
		wxGetApp().CallAfter([err]() {
			wxLogError(err);
		});
	}
}

Level::Level(std::string myFirstName, std::vector<Playable*> myVanillaParty, std::string myEpisode, std::vector<Playable*> myUnlocks, bool myVehicleLevel,
						 std::string myName, int myIsFake)
	: firstName(myFirstName), vanillaParty(myVanillaParty), episode(myEpisode), unlocks(myUnlocks), vehicleLevel(myVehicleLevel), isFake(myIsFake) {

	if (myName == "") name = firstName;
	else name = myName;
	party = vanillaParty;
	allLevels.push_back(this);
}

void Level::mix() {
#ifdef _DEBUG
	wxString loggg = name;
	wxGetApp().CallAfter([&loggg] {
		wxLogStatus(loggg);
	});
#endif

	testing = {};
	if (character) {
	label:
		party = {};
		for (int i = 0; i < vanillaParty.size(); i++) {
			Playable* temp;
			if (vehicleLevel)temp = vhs[rand() % vhs.size()];
			else temp = chs[rand() % chs.size()];
			party.push_back(temp);
		}
		//prevents duplicates
		for (int i = 0; i < vanillaParty.size() - 1; i++) {
			for (int j = i + 1; j < vanillaParty.size(); j++) {
				if (party[i] == party[j]) goto label;
			}
		}
	}
}

void Level::mixCollectables() {
	std::vector<char> collectableList = {
		'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm',
		'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c',
		'r'
	};
	collectables = {};

	while (collectableList.size() > 0) {
		int temp = rand() % collectableList.size();
		collectables.push_back(collectableList[temp]);
		collectableList.erase(collectableList.begin() + temp);
	}
}


void Level::add(int n) {
	testing.push_back(party[n]);
}

std::string Level::directory(char scene, std::string fileExtention) {
	std::string directory;
	if (scene == '\0') directory = episode + firstName + '/' + firstName + ".TXT";
	else if (fileExtention == "") {
		directory = episode + firstName + '/' + name + '_' + scene + '/' + name + '_' + scene + ".TXT";
	} else {
		directory = episode + firstName + '/' + name + '_' + scene + "/AI/" + fileExtention;
	}
	return directory;
}

std::string Level::specialDirectory(char scene, std::string fileType) {
	return episode + firstName + '/' + name + '_' + scene + '/' + name + '_' + scene + fileType;
}

void Level::append(std::string appendix, char scene, std::string fileExtention) {
	std::string file = directory(scene, fileExtention);
	appendFile(file, appendix);
}

void Level::replace(std::string newText, int length, std::vector<coord> coordinates, char scene, std::string fileExtention) {
	std::string file = directory(scene, fileExtention);

	txtIns(file, newText, coordinates, length);
}

void Level::replace(int characterNumber, std::vector<coord> coordinates, char scene, std::string fileExtention) {
	replace(party[characterNumber]->name, vanillaParty[characterNumber]->name.length(), coordinates, scene, fileExtention);
}

void Level::specialReplace(std::string newText, int length, std::vector<coord> coordinates, char scene, std::string fileType) {
	std::string file = specialDirectory(scene, fileType);
	txtIns(file, newText, coordinates, length);
}

void Level::specialReplace(int characterNumber, std::vector<coord> coordinates, char scene, std::string fileType) {
	specialReplace(party[characterNumber]->name, vanillaParty[characterNumber]->name.length(), coordinates, scene, fileType);

}

void Level::rename(std::string newText, std::string oldText, char scene) {
	std::string file = episode + firstName + '/' + name + '_' + scene + "/AI/";
	renamer(file + oldText, file + newText);

}

void Level::rename(int characterNumber, char scene) {
	rename(party[characterNumber]->name + ".SCP", vanillaParty[characterNumber]->name + ".SCP", scene); //FIX
}

void Level::binWrite(std::string newText, std::vector<int> address, char scene, std::string fileExtention, int len) {
	std::string file = directory(scene, fileExtention);
	for (int a : address) hexWrite(file, newText, a, len);
}

void Level::binWrite(int characterNumber, std::vector<int> address, char scene, std::string fileExtention) {
	binWrite(party[characterNumber]->name, address, scene, fileExtention, vanillaParty[characterNumber]->name.length());
}

bool AlwaysTrue(std::vector<Playable*>) {
	return true;
}

bool Jedi(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->jedi) return true;
	}
	return false;
}

bool Sith(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->sith) return true;
	}
	return false;
}

bool Saber(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->saber) return true;
	}
	return false;
}

bool LivingJedi(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->jedi && !p->ghost) return true;
	}
	return false;
}

bool Deflect(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->deflect) return true;
	}
	return false;
}

bool Ghost(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->ghost) return true;
	}
	return false;
}

bool Passive(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->passive) return true;
	}
	return false;
}

bool Jump(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->jump) return true;
	}
	return false;
}

bool DoubleTransitionSkip(bool (*ptr)(std::vector<Playable*>), std::vector<Playable*>current) {
	for (Playable* p : current) {
		for (Playable* q : current) {
			if (p->saber && ptr({q}) && !q->ghost) return true;
		}
	}
	return false;
}

bool TransitionSkip(bool (*ptr)(std::vector<Playable*>), std::vector<Playable*>current) {
	for (Playable* p : current) {
		for (Playable* q : current) {
			if (p->attack && ptr({q}) && !q->ghost) return true;
		}
	}
	return false;
}

bool Build(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->build) return true;
	}
	return false;
}

bool Box(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->box) return true;
	}
	return false;
}

bool Lever(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->lever) return true;
	}
	return false;
}

bool DoubleJump(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->doubleJump) return true;
	}
	return false;
}

bool RealDoubleJump(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->realDoubleJump) return true;
	}
	return false;
}

bool HighJump(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->highJump) return true;
	}
	return false;
}

bool Tall(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->tall) return true;
	}
	return false;
}

bool ExtraHighJump(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->extraHighJump) return true;
	}
	return false;
}

bool GunganJump(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->gunganJump) return true;
	}
	return false;
}

bool YodaJump(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->yodaJump) return true;
	}
	return false;
}

bool Grapple(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->grapple) return true;
	}
	return false;
}

bool Shoot(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->shoot) return true;
	}
	return false;
}

bool FakeShoot(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->fakeshoot) return true;
	}
	return false;
}

bool Attack(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->attack) return true;
	}
	return false;
}

bool Hatch(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->hatch) return true;
	}
	return false;
}

bool Fly(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->fly) return true;
	}
	return false;
}

bool Dive(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->dive) return true;
	}
	return false;
}

bool Flop(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->flop) return true;
	}
	return false;
}

bool Flutter(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->flutter) return true;
	}
	return false;
}

bool Hovering(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->hovering) return true;
	}
	return false;
}

bool Fett(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->fett) return true;
	}
	return false;
}

bool Bounty(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->bounty) return true;
	}
	return false;
}

bool Imperial(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->imperial) return true;
	}
	return false;
}

bool Hat(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->hat) return true;
	}
	return false;
}

bool Proto(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->proto) return true;
	}
	return false;
}

bool Astro(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->astro) return true;
	}
	return false;
}

bool Zapper(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->zapper) return true;
	}
	return false;
}

bool Droid(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->droid) return true;
	}
	return false;
}

bool FalconJump(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->doubleJump) return true;
		if (p->dive) return true;
		if (p->flop) return true;
		if (p->slightlyBetterJump) return true;
	}
	return false;
}


bool Tow(std::vector<Playable*> current) {
	for (Playable* p : current) {
		if (p->tow) return true;
	}
	return false;
}

bool PlansThing(std::vector<Playable*> current, Playable* shield, Playable* redGuy) {
	if (logicType != superGlitched) return false;

	for (Playable* x : current) {
		for (Playable* y : current) {
			bool OOB = false;
			bool OOB2 = false;

			if (x != y) {
				if (x->landoAlt && y->leiaAlt) OOB = true;
				if (x->zapper && y->zappable) OOB = true;
				if (x->astrozapper && y->storm) OOB = true;
				if (x->trickable && y->jedi) OOB = true;
				if (x->pushable && y->jedi) OOB = true;
				if (x->chokeable && y->choke) OOB = true;
				if (x == gamorreanguard && y->lukeAlt) OOB = true;

				Playable* otherX = defaultCharacter;
				if (OOB) {
					for (Playable* x2 : current) {
						for (Playable* y2 : current) {
							if (x2 != y2 && x2 != x) {
								if (x2->landoAlt && y2->leiaAlt) OOB2 = true;
								if (x2->zapper && y2->zappable) OOB2 = true;
								if (x2->astrozapper && y2->storm) OOB2 = true;
								if (x2->trickable && y2->jedi) OOB2 = true;
								if (x2->pushable && y2->jedi) OOB2 = true;
								if (x2->chokeable && y2->choke) OOB2 = true;
								if (x2 == gamorreanguard && y2->lukeAlt) OOB2 = true;
								if (OOB2) otherX = x2;
							}
						}
					}
					if (Astro({x, shield})) return true;
					if (Proto({x, otherX}) && Box({x, otherX})) return true;
					if (Proto({redGuy}) &&
							(Any({DoubleJump, Fly}, {x, otherX}) || (Box({x}) && Lever({redGuy})))) return true;
						//								not sure
				}
			}
		}
	}
	return false;
}

bool SuperJump(std::vector<bool (*)(std::vector<Playable*>)> vec, std::vector<Playable*> current) {
	if (logicType != superGlitched) return false;
	for (Playable* x : current) {
		for (Playable* y : current) {
			if (x != y) {
				if (x->landoAlt && y->leiaAlt && All(vec, {y})) return true;
				if (x->zapper && y->zappable && All(vec, {y})) return true;
				if (x->astrozapper && y->storm && All(vec, {y})) return true;
				if (x->trickable && y->jedi && All(vec, {y})) return true;
				if (x->pushable && y->jedi && All(vec, {y})) return true;
				if (x->chokeable && y->choke && All(vec, {y})) return true;
				if (x == gamorreanguard && y->lukeAlt && All(vec, {y})) return true;
			}
		}
	}
	return false;
}


bool InstantSuperJump(std::vector<bool (*)(std::vector<Playable*>)> vec, std::vector<Playable*> current) {
	if (logicType != superGlitched) return false;
	for (Playable* x : current) {
		for (Playable* y : current) {
			if (x != y) {
				if (x->pushable && y->jedi && All(vec, {y})) return true;
				if (x->chokeable && y->choke && All(vec, {y})) return true;
				if (x == gamorreanguard && y->lukeAlt && All(vec, {y})) return true;
			}
		}
	}
	return false;
}

float GetFastest(std::vector<Playable*> current) {
	float fastest = 0.0;
	for (Playable* p : current) {
		if (p->speed > fastest) fastest = p->speed;
	}
	return fastest;
}

float GetSlowest(std::vector<Playable*> current) {
	float slowest = 100.0;
	for (Playable* p : current) {
		if (p->speed < slowest) slowest = p->speed;
	}
	return slowest;
}

int GetType(int pref, bool (*ptr)(std::vector<Playable*>), std::vector<Playable*> current) {
	if (ptr({current[pref]})) return pref;
	for (int i = current.size() - 1; i >= 0; i--) {
		if (ptr({current[i]})) return i;
	}
	return -1;
}

bool Any(std::vector<bool (*)(std::vector<Playable*>)> vec, std::vector<Playable*> current) {
	for (bool(*v)(std::vector<Playable*>) : vec) {
		if (v(current)) return true;
	}
	return false;
}

bool All(std::vector<bool (*)(std::vector<Playable*>)> vec, std::vector<Playable*> current) {
	for (Playable* p : current) {
		for (int i = 0; i < vec.size(); i++) {
			if (!vec[i]({p})) break;
			if (i == vec.size() - 1) return true;
		}
	}
	return false;
}

bool Multi(bool (*ptr)(std::vector<Playable*>), int n, std::vector<Playable*> current) {
	int x = 0;
	for (Playable* p : current) {
		if (ptr({p})) {
			x++;
			if (x == n) {
				return true;
			}
		}
	}
	return false;
}

bool MultiAny(std::vector<bool (*)(std::vector<Playable*>)> vec, int n, std::vector<Playable*> current) {
	int x = 0;
	for (Playable* p : current) {
		for (bool(*v)(std::vector<Playable*>) : vec) {
			if (v({p})) {
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

//0xca35a
int addressPointer = 0x2B0;
int junkCharacters = 0x3f1b6c;

void characterPointer(Playable* play, int address) {
	if (play->pointString != 0x0) {
		numWrite(EXE, readEXE(play->pointString - 0x400000 + 0x4), address);
	} else {
		hexWrite(EXE, play->name, addressPointer);
		numWrite(EXE, addressPointer + 0x400000, junkCharacters - 0x4);
		play->pointString = junkCharacters + 0x400000 - 0x4;

		numWrite(EXE, readEXE(play->pointString - 0x400000 + 0x4), address);

		addressPointer += play->name.length() + 1;
		junkCharacters += 0x8;
		if (junkCharacters == 0x3f1bb4) junkCharacters += 0x8; // "whip" might not be unused
	}
}

void multiPointer(Playable* play, std::vector<int> address) {
	if (play->pointString != 0x0) {
		for (int ad : address)
			numWrite(EXE, readEXE(play->pointString - 0x400000 + 0x4), ad);
	} else {
		hexWrite(EXE, play->name, addressPointer);
		numWrite(EXE, addressPointer + 0x400000, junkCharacters - 0x4);
		play->pointString = junkCharacters + 0x400000 - 0x4;

		for (int ad : address)
			numWrite(EXE, readEXE(play->pointString - 0x400000 + 0x4), ad);

		addressPointer += play->name.length() + 1;
		junkCharacters += 0x8;
		while (junkCharacters == 0x3f1bb4 || junkCharacters == 0x3f1b84 || junkCharacters == 0x3f1bac)
			junkCharacters += 0x8; // "whip" might not be unused and others are weird
	}
}




void logIt(Playable* ch, std::ofstream& log) {
	log << (ch)->name << '\n';
	log << (ch)->realName << '\n';
	log << ch->price << '\n';
	log << std::hex << ch->pointString << '\n';
	log << ch->speed << '\n';

	if (ch->vehicle) log << "vehicle" << '\n';
	if (ch->extratoggle) log << "extratoggle" << '\n';
	if (ch->vgreen) log << "vgreen" << '\n';

	if (ch->hat) log << "hat" << '\n';
	if (ch->lever) log << "lever" << '\n';
	if (ch->build) log << "build" << '\n';
	if (ch->box) log << "box" << '\n';

	if (ch->jump) log << "jump" << '\n';
	if (ch->doubleJump) log << "doubleJump" << '\n';
	if (ch->highJump) log << "highJump" << '\n';
	if (ch->extraHighJump) log << "extraHighJump" << '\n';
	if (ch->yodaJump) log << "yodaJump" << '\n';
	if (ch->realDoubleJump) log << "realDoubleJump" << '\n';
	if (ch->gunganJump) log << "gunganJump" << '\n';
	if (ch->dive) log << "dive" << '\n';
	if (ch->flop) log << "flop" << '\n';
	if (ch->slightlyBetterJump) log << "slightlyBetterJump" << '\n';

	if (ch->hovering) log << "hovering" << '\n';
	if (ch->fly) log << "fly" << '\n';
	if (ch->flutter) log << "flutter" << '\n';
	if (ch->fett) log << "fett" << '\n';

	if (ch->attack) log << "attack" << '\n';
	if (ch->saber) log << "saber" << '\n';
	if (ch->deflect) log << "deflect" << '\n';
	if (ch->shoot) log << "shoot" << '\n';
	if (ch->grapple) log << "grapple" << '\n';
	if (ch->fakeshoot) log << "fakeshoot" << '\n';
	if (ch->zapper) log << "zapper" << '\n';
	if (ch->astrozapper) log << "astrozapper" << '\n';

	if (ch->jedi) log << "jedi" << '\n';
	if (ch->sith) log << "sith" << '\n';
	if (ch->choke) log << "choke" << '\n';
	if (ch->ghost) log << "ghost" << '\n';

	if (ch->imperial) log << "imperial" << '\n';
	if (ch->astro) log << "astro" << '\n';
	if (ch->proto) log << "proto" << '\n';
	if (ch->bounty) log << "bounty" << '\n';

	if (ch->droid) log << "droid" << '\n';
	if (ch->passive) log << "passive" << '\n';
	if (ch->gas) log << "gas" << '\n';
	if (ch->hatch) log << "hatch" << '\n';
	if (ch->tall) log << "tall" << '\n';

	if (ch->pushable) log << "pushable" << '\n';
	if (ch->chokeable) log << "chokeable" << '\n';
	if (ch->trickable) log << "trickable" << '\n';
	if (ch->zappable) log << "zappable" << '\n';
	if (ch->storm) log << "storm" << '\n';

	if (ch->leiaAlt) log << "leiaAlt" << '\n';
	if (ch->landoAlt) log << "landoAlt" << '\n';
	if (ch->lukeAlt) log << "lukeAlt" << '\n';

	if (ch->tow) log << "tow" << '\n';
	if (ch->tiedoor) log << "tiedoor" << '\n';
	log << '\n';
}

void log2() {
	remove("files/log.txt");
	std::ofstream log("files/log.txt");

	for (unsigned int i = 0; i < pls.size(); i++) {
		log << i << '\n';
		logIt(pls[i], log);
	}

	log.close();


	remove("files/log2.txt");
	std::ofstream log2("files/log2.txt");

	log2 << chs.size() << '\n';
	log2 << vhs.size() << '\n';

#define tlog(x)\
for (Playable* y : chs) {if (y->x) log2 << '\t' << y->realName << '\n'; }\
for (Playable* y : vhs) {if (y->x) log2 << '\t' << y->realName << '\n'; }

	log2 << "hat" << '\n'; tlog(hat);
	log2 << "lever" << '\n'; tlog(lever);
	log2 << "build" << '\n'; tlog(build);
	log2 << "box" << '\n'; tlog(box);

	log2 << "jump" << '\n'; tlog(jump);
	log2 << "doubleJump" << '\n'; tlog(doubleJump);
	log2 << "highJump" << '\n'; tlog(highJump);
	log2 << "extraHighJump" << '\n'; tlog(extraHighJump);
	log2 << "yodaJump" << '\n'; tlog(yodaJump);
	log2 << "realDoubleJump" << '\n'; tlog(realDoubleJump);
	log2 << "gunganJump" << '\n'; tlog(gunganJump);
	log2 << "dive" << '\n'; tlog(dive);
	log2 << "flop" << '\n'; tlog(flop);

	log2 << "hovering" << '\n'; tlog(hovering);
	log2 << "fly" << '\n'; tlog(fly);
	log2 << "flutter" << '\n'; tlog(flutter);
	log2 << "fett" << '\n'; tlog(fett);

	log2 << "attack" << '\n'; tlog(attack);
	log2 << "saber" << '\n'; tlog(saber);
	log2 << "deflect" << '\n'; tlog(deflect);
	log2 << "shoot" << '\n'; tlog(shoot);
	log2 << "grapple" << '\n'; tlog(grapple);
	log2 << "fakeshoot" << '\n'; tlog(fakeshoot);
	log2 << "zapper" << '\n'; tlog(zapper);
	log2 << "astrozapper" << '\n'; tlog(astrozapper);

	log2 << "jedi" << '\n'; tlog(jedi);
	log2 << "sith" << '\n'; tlog(sith);
	log2 << "choke" << '\n'; tlog(choke);
	log2 << "ghost" << '\n'; tlog(ghost);

	log2 << "imperial" << '\n'; tlog(imperial);
	log2 << "astro" << '\n'; tlog(astro);
	log2 << "proto" << '\n'; tlog(proto);
	log2 << "bounty" << '\n'; tlog(bounty);

	log2 << "droid" << '\n'; tlog(droid);
	log2 << "passive" << '\n'; tlog(passive);
	log2 << "gas" << '\n'; tlog(gas);
	log2 << "hatch" << '\n'; tlog(hatch);

	log2 << "extratoggle" << '\n'; tlog(extratoggle);
	log2 << "leiaAlt" << '\n'; tlog(leiaAlt);
	log2 << "landoAlt" << '\n'; tlog(landoAlt);
	log2 << "lukeAlt" << '\n'; tlog(lukeAlt);

	log2 << "tow" << '\n'; tlog(tow);
	log2 << "tiedoor" << '\n'; tlog(tiedoor);
	log2 << "vgreen" << '\n'; tlog(vgreen);
	log2.close();
}
#endif
*/