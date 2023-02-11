#include <wx/wx.h>
#include "Characters.h"
#include "App.h"
#include "Defines.h"

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

extern Playable* quigon;
extern Playable* obiwan;
extern Playable* tc14;
extern Playable* jarjar;
extern Playable* amidala;
extern Playable* panaka;
extern Playable* padmeBattle;
extern Playable* r2d2;
extern Playable* anakinBoy;
extern Playable* obiwanJedi;
extern Playable* r4p17;
extern Playable* anakinPadawan;
extern Playable* padmeGeonosis;
extern Playable* c3po;
extern Playable* macewindu;
extern Playable* padmeClawed;
extern Playable* yoda;
extern Playable* obiwanEp3;
extern Playable* anakinJedi;
extern Playable* palpatine;
extern Playable* cody;
extern Playable* chewbacca;
extern Playable* leia;
extern Playable* antilles;
extern Playable* rebelFriend;
extern Playable* lukeTatooine;
extern Playable* benKenobi;
extern Playable* han;
extern Playable* hanStormtrooper;
extern Playable* lukeStormtrooper;
extern Playable* hanHoth;
extern Playable* leiaHoth;
extern Playable* lukePilot;
extern Playable* lukeDagobah;
extern Playable* lukeBespin;
extern Playable* lando;
extern Playable* leiaBespin;
extern Playable* lukeJedi;
extern Playable* leiaBoushh;
extern Playable* landoPalaceGuard;
extern Playable* hanSkiff;
extern Playable* leiaSlave;
extern Playable* leiaEndor;
extern Playable* lukeEndor;
extern Playable* hanEndor;
extern Playable* wicket;
extern Playable* vader;
extern Playable* gonk;
extern Playable* pkdroid;
extern Playable* battledroid;
extern Playable* battledroidSecurity;
extern Playable* battledroidCommander;
extern Playable* droideka;
extern Playable* tarpals;
extern Playable* bossnass;
extern Playable* royalguard;
extern Playable* padme;
extern Playable* watto;
extern Playable* pitdroid;
extern Playable* maul;
extern Playable* zam;
extern Playable* dexter;
extern Playable* clone;
extern Playable* lamasu;
extern Playable* taunwe;
extern Playable* geonosian;
extern Playable* battledroidGeonosis;
extern Playable* superbattledroid;
extern Playable* jango;
extern Playable* bobafettBoy;
extern Playable* luminara;
extern Playable* kiadimundi;
extern Playable* kitfisto;
extern Playable* shaakti;
extern Playable* aaylasecura;
extern Playable* plokoon;
extern Playable* dooku;
extern Playable* magnaguard;
extern Playable* grievous;
extern Playable* wookiee;
extern Playable* cloneEp3;
extern Playable* clonePilot;
extern Playable* cloneSwamp;
extern Playable* cloneWalker;
extern Playable* macewinduEp3;
extern Playable* disguisedclone;
extern Playable* rebeltrooper;
extern Playable* stormtrooper;
extern Playable* imperialshuttlepilot;
extern Playable* tuskenraider;
extern Playable* jawa;
extern Playable* sandtrooper;
extern Playable* greedo;
extern Playable* imperialspy;
extern Playable* beachtrooper;
extern Playable* deathstartrooper;
extern Playable* tiefighterpilot;
extern Playable* imperialofficer;
extern Playable* tarkin;
extern Playable* hanHood;
extern Playable* rebelHoth;
extern Playable* rebelPilot;
extern Playable* snowtrooper;
extern Playable* lukeHoth;
extern Playable* lobot;
extern Playable* ugnaught;
extern Playable* bespinguard;
extern Playable* leiaPrisoner;
extern Playable* gamorreanguard;
extern Playable* bibfortuna;
extern Playable* palaceguard;
extern Playable* bossk;
extern Playable* skiffguard;
extern Playable* boba;
extern Playable* ewok;
extern Playable* imperialguard;
extern Playable* emperor;
extern Playable* ackbar;
extern Playable* ig88;
extern Playable* dengar;
extern Playable* f4lom;
extern Playable* benghost;
extern Playable* anakinghost;
extern Playable* yodaghost;
extern Playable* r2q5;
extern Playable* indianajones;
extern Playable* trainingremote;
extern Playable* buzzdroid;
extern Playable* skeleton;
extern Playable* mousedroid;
extern Playable* womprat;
extern Playable* rebelengineer;
extern Playable* imperialengineer;
extern Playable* atatdriver;
extern Playable* scouttrooper;
extern Playable* hanCarbonite;
extern Playable* droid1;
extern Playable* droid2;
extern Playable* droid3;
extern Playable* droid4;

extern Playable* anakinsPod;
extern Playable* nabooStarfighter;
extern Playable* anakinsSpeeder;
extern Playable* gunship;
extern Playable* starfighterYellow;
extern Playable* starfighterRed;
extern Playable* xwing;
extern Playable* ywing;
extern Playable* snowspeeder;
extern Playable* milleniumFalcon;
extern Playable* sebulbasPod;
extern Playable* zamsAirspeeder;
extern Playable* droidTrifighter;
extern Playable* vultureDroid;
extern Playable* arcfighter;
extern Playable* tiefighter;
extern Playable* tieinterceptor;
extern Playable* tiefighterVader;
extern Playable* tiebomber;
extern Playable* imperialshuttle;
extern Playable* slave1;
extern Playable* anakinsPodGreen;
extern Playable* nabooStarfighterGreen;
extern Playable* anakinsSpeederGreen;
extern Playable* gunshipGreen;

extern Level* Negotiations;
extern Level* Invasion;
extern Level* EscapeNaboo;
extern Level* Podrace;
extern Level* Theed;
extern Level* Maul;

extern Level* BHP;
extern Level* Kamino;
extern Level* Factory;
extern Level* JediBattle;
extern Level* Gunship;
extern Level* Dooku;

extern Level* Coruscant;
extern Level* Chancellor;
extern Level* Grievous;
extern Level* Kashyyyk;
extern Level* Ruin;
extern Level* Vader;

extern Level* SecretPlans;
extern Level* Jundland;
extern Level* Spaceport;
extern Level* Princess;
extern Level* DSE;
extern Level* RebelAttack;

extern Level* Hoth;
extern Level* EchoBase;
extern Level* FalconFlight;
extern Level* Dagobah;
extern Level* CCT;
extern Level* Bespin;

extern Level* Jabbas;
extern Level* Carkoon;
extern Level* Showdown;
extern Level* Endor;
extern Level* Destiny;
extern Level* ITDS;

extern Level* Anakinsflight;
extern Level* ANewHope;

extern Level* BHM;

extern Level* defaultLevel;
extern Level* allEpisodes;

void charMaker() {
	std::ifstream readCharacters("files/CHARACTERDATA.txt", std::ios::in);
	std::ofstream loggering("files/log.txt");
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
			while ( line != "") {
				if (line == "hat") parse->hat = true;
				else if (line == "lever") parse->lever = true;
				else if (line == "build") parse->build = true;
				else if (line == "box") parse->box = true;
				else if (line == "jump") parse->jump = true;
				else if (line == "doubleJump") parse->doubleJump = true;
				else if (line == "highJump") parse->highJump = true;
				else if (line == "yodaJump") parse->yodaJump = true;
				else if (line == "extraHighJump") parse->extraHighJump = true;
				else if (line == "realDoubleJump") parse->realDoubleJump = true;
				else if (line == "gunganJump") parse->gunganJump = true;
				else if (line == "dive") parse->dive = true;
				else if (line == "flop") parse->flop = true;
				else if (line == "hovering") parse->hovering = true;
				else if (line == "fly") parse->fly = true;
				else if (line == "flutter") parse->flutter = true;
				else if (line == "fett") parse->fett = true;
				else if (line == "attack") parse->attack = true;
				else if (line == "shoot") parse->shoot = true;
				else if (line == "grapple") parse->grapple = true;
				else if (line == "fakeshoot") parse->fakeshoot = true;
				else if (line == "zapper") parse->zapper = true;
				else if (line == "astrozapper") parse->astrozapper = true;
				else if (line == "jedi") parse->jedi = true;
				else if (line == "sith") parse->sith = true;
				else if (line == "choke") parse->choke = true;
				else if (line == "ghost") parse->ghost = true;
				else if (line == "saber") parse->saber = true;
				else if (line == "deflect") parse->deflect = true;
				else if (line == "imperial") parse->imperial = true;
				else if (line == "astro") parse->astro = true;
				else if (line == "proto") parse->proto = true;
				else if (line == "droid") parse->droid = true;
				else if (line == "passive") parse->passive = true;
				else if (line == "gas") parse->gas = true;
				else if (line == "bounty") parse->bounty = true;
				else if (line == "hatch") parse->hatch = true;
				else if (line == "tall") parse->tall = true;
				else if (line == "extratoggle") parse->extratoggle = true;
				else if (line == "pushable") parse->pushable = true;
				else if (line == "chokeable") parse->chokeable = true;
				else if (line == "trickable") parse->trickable = true;
				else if (line == "zappable") parse->zappable = true;
				else if (line == "storm") parse->storm = true;
				else if (line == "slightlyBetterJump") parse->slightlyBetterJump = true;
				else if (line == "vehicle") parse->vehicle = true;
				else if (line == "tow") parse->tow = true;
				else if (line == "tiedoor") parse->tiedoor = true;
				else if (line == "vgreen") parse->vgreen = true;
				else if (line == "leiaAlt") parse->leiaAlt = true;
				else if (line == "landoAlt") parse->landoAlt = true;
				else if (line == "lukeAlt") parse->lukeAlt = true;
			#ifdef _DEBUG
				else wxLogError((line + " is not an attribute.").c_str());
			#endif
				getline(readCharacters, line);

			}
			pls.push_back(parse);

		}
	}

}

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


void levMaker() {

	//name, characters, episode, unlocks, vehicle level, alt second name for Escape and Theed, characters not in party
	Negotiations = new Level("NEGOTIATIONS", {quigon, obiwan, tc14}, TPM,
													 {quigon, obiwan, tc14, battledroid, battledroidSecurity, battledroidCommander, droideka});
	Invasion = new Level("GUNGAN", {quigon, obiwan, jarjar}, TPM,
											 {jarjar, tarpals, bossnass});
	EscapeNaboo = new Level("PALACERESCUE", {amidala, panaka, quigon, obiwan}, TPM,
													{amidala, panaka, royalguard, padme}, false, "RESCUE");
	Podrace = new Level("PODSPRINT", {anakinsPod, anakinsPodGreen}, TPM,
											{watto, pitdroid, anakinsPod, anakinsPodGreen, sebulbasPod}, true);
	Theed = new Level("RETAKEPALACE", {obiwan, quigon, panaka, padmeBattle, r2d2, anakinBoy}, TPM,
										{padmeBattle, r2d2, anakinBoy}, false, "RETAKE");
	Maul = new Level("MAUL", {obiwan, quigon}, TPM,
									 {maul});

	BHP = new Level("PURSUIT", {anakinsSpeeder, anakinsSpeederGreen}, CLN,
									{zam, dexter, anakinsSpeeder, anakinsSpeederGreen, zamsAirspeeder}, true);
	Kamino = new Level("KAMINO", {obiwanJedi, r4p17}, CLN,
										 {obiwanJedi, r4p17, clone, lamasu, taunwe});
	Factory = new Level("FACTORY", {anakinPadawan, padmeGeonosis, r2d2, c3po, obiwanJedi}, CLN,
											{anakinPadawan, padmeGeonosis, c3po, geonosian, battledroidGeonosis, skeleton}, false, "", 4);
	JediBattle = new Level("JEDI", {macewindu, r2d2, obiwanJedi, anakinPadawan, padmeClawed}, CLN,
												 {macewindu, padmeClawed, superbattledroid, jango, bobafettBoy, luminara, kiadimundi, kitfisto, shaakti, aaylasecura, plokoon});
	Gunship = new Level("GUNSHIP", {gunship, gunshipGreen}, CLN,
											{gunship, gunshipGreen}, true);
	Dooku = new Level("DOOKU", {obiwanJedi, anakinPadawan, yoda}, CLN,
										{yoda});

	Coruscant = new Level("DOGFIGHT", {starfighterYellow, starfighterRed}, STH,
												{starfighterYellow, starfighterRed, droidTrifighter, vultureDroid, arcfighter}, true);
	Chancellor = new Level("CRUISER", {obiwanEp3, anakinJedi, r2d2, palpatine}, STH,
												 {obiwanEp3, anakinJedi, palpatine, dooku, magnaguard, buzzdroid});
	Grievous = new Level("GRIEVOUS", {obiwanEp3, cody}, STH,
											 {cody, grievous});
	Kashyyyk = new Level("KASHYYYK", {yoda, chewbacca}, STH,
											 {chewbacca, wookiee, cloneEp3, clonePilot, cloneSwamp, cloneWalker});
	Ruin = new Level("TEMPLE", {obiwanEp3, yoda}, STH,
									 {macewinduEp3, disguisedclone, trainingremote});
	Vader = new Level("VADER", {obiwanEp3, anakinJedi}, STH);

	SecretPlans = new Level("BLOCKADERUNNER", {leia, antilles, rebelFriend, c3po, r2d2}, ANH,
													{leia, antilles, rebelFriend, rebeltrooper, stormtrooper, imperialshuttlepilot, rebelengineer});
	Jundland = new Level("TATOOINE", {lukeTatooine, benKenobi, c3po, r2d2}, ANH,
											 {lukeTatooine, benKenobi, tuskenraider, jawa, droid1, droid2, droid3, droid4, womprat});
	Spaceport = new Level("MOSEISLEY", {lukeTatooine, benKenobi, r2d2, c3po, han, chewbacca}, ANH,
												{han, sandtrooper, greedo, imperialspy});
	Princess = new Level("DEATHSTARRESCUE", {hanStormtrooper, lukeStormtrooper, chewbacca, r2d2, c3po, benKenobi, leia}, ANH,
											 {hanStormtrooper, lukeStormtrooper, beachtrooper, deathstartrooper, tiefighterpilot, imperialofficer, tarkin, mousedroid, imperialengineer}, false, "", 7);
	DSE = new Level("DEATHSTARESCAPE", {han, chewbacca, leia, lukeTatooine, r2d2, c3po}, ANH);
	RebelAttack = new Level("DEATHSTARBATTLE", {xwing, ywing}, ANH,
													{xwing, ywing, tiefighter, tieinterceptor, tiefighterVader}, true);

	Hoth = new Level("HOTHBATTLE", {snowspeeder, snowspeeder}, EMP,
									 {snowspeeder}, true);
	EchoBase = new Level("HOTHESCAPE", {hanHoth, leiaHoth, c3po, chewbacca}, EMP,
											 {hanHoth, leiaHoth , hanHood, rebelHoth, rebelPilot, snowtrooper, lukeHoth});
	FalconFlight = new Level("ASTEROIDCHASE", {milleniumFalcon, xwing}, EMP,
													 {milleniumFalcon, tiebomber, imperialshuttle}, true);
	Dagobah = new Level("DAGOBAH", {lukePilot, r2d2, lukeDagobah, yoda}, EMP,
											{lukePilot, lukeDagobah});
	CCT = new Level("CLOUDCITYTRAP", {lukeBespin, r2d2}, EMP,
									{lukeBespin, hanCarbonite});
	Bespin = new Level("CLOUDCITYESCAPE", {lando, leiaBespin, chewbacca, r2d2, c3po}, EMP,
										 {lando, leiaBespin, lobot, ugnaught, bespinguard, leiaPrisoner});

	Jabbas = new Level("JABBASPALACE", {leiaBoushh, chewbacca, lukeJedi, c3po, r2d2, hanSkiff}, JDI,
										 {lukeJedi, leiaBoushh, hanSkiff, gamorreanguard, bibfortuna, palaceguard, bossk});
	Carkoon = new Level("SARLACCPIT", {landoPalaceGuard, lukeJedi, chewbacca, hanSkiff, c3po, r2d2, leiaSlave}, JDI,
											{landoPalaceGuard, leiaSlave, skiffguard, boba});
	Showdown = new Level("SPEEDERCHASE", {leiaEndor, lukeEndor}, JDI,
											 {leiaEndor, lukeEndor, atatdriver, scouttrooper});
	Endor = new Level("ENDORBATTLE", {hanEndor, leiaEndor, r2d2, chewbacca, c3po, wicket}, JDI,
										{hanEndor, wicket, ewok});
	Destiny = new Level("EMPERORFIGHT", {lukeJedi, vader}, JDI,
											{vader, imperialguard, emperor});
	ITDS = new Level("DEATHSTAR2BATTLE", {milleniumFalcon, xwing}, JDI,
									 {ackbar}, true);

	Anakinsflight = new Level("ANAKINSFLIGHT", {nabooStarfighter, nabooStarfighterGreen}, LEV,
														{nabooStarfighter, nabooStarfighterGreen}, true);
	ANewHope = new Level("ANEWHOPE", {vader, stormtrooper, c3po}, STH);

	BHM = new Level("", {boba, greedo, ig88, f4lom, bossk, dengar,
		quigon, amidala, jarjar, macewindu, kitfisto, luminara, kiadimundi, rebeltrooper, shaakti, cody,
		r2d2, benKenobi, chewbacca, leia, ackbar, yoda, c3po, lando, lukeTatooine, han}, "", {}, false, "", -1);

	defaultLevel = new Level("", {}, "", {gonk, pkdroid});
	allEpisodes = new Level("", {}, "", {ig88, dengar, f4lom, benghost, anakinghost, yodaghost, r2q5, indianajones, slave1});


	std::ofstream levelDat("files/LEVELDATA.txt");
	for (Level* l : allLevels) {
		levelDat << l->name << '\n';
		levelDat << l->episode << l->firstName << '\n';
		if (l->vehicleLevel) levelDat << "vehicle" << '\n';
		else levelDat << "character" << '\n';

		for (Playable* p : l->vanillaParty) levelDat << p->name << ' ';
		levelDat << '\n';
		for (Playable* p : l->unlocks) levelDat << p->name << ' ';

		levelDat << '\n';
	}


	for (Level* l : allLevels) {
		for (Playable* p : l->unlocks) {
			p->lev = l;
		}
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
