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


void renamer(std::string oldName, std::string newName) {
	int test = rename(oldName.c_str(), newName.c_str());
	if (test == -1) {
		wxString err = "File name override failed: " + oldName + " -> " + newName;
		wxGetApp().CallAfter([err]() {
			wxLogError(err);
			});
	}
}

Playable::Playable(std::string myName, std::string myRealName, int myPrice, int myPointString, double mySpeed)
	: name(myName), realName(myRealName), price(myPrice), speed(mySpeed), pointString(myPointString) {
	pi = this;
	lev = defaultLevel;
	if (name != "")
		pls.push_back(this);
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
			if (p->saber && ptr({ q }) && !q->ghost) return true;
		}
	}
	return false;
}

bool TransitionSkip(bool (*ptr)(std::vector<Playable*>), std::vector<Playable*>current) {
	for (Playable* p : current) {
		for (Playable* q : current) {
			if (p->attack && ptr({ q }) && !q->ghost) return true;
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
					if (Astro({ x, shield })) return true;
					if (Proto({ x, otherX }) && Box({ x, otherX })) return true;
					if (Proto({ redGuy }) &&
						(Any({ DoubleJump, Fly }, { x, otherX }) || (Box({ x }) && Lever({ redGuy })))) return true;
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
				if (x->landoAlt && y->leiaAlt && All(vec, { y })) return true;
				if (x->zapper && y->zappable && All(vec, { y })) return true;
				if (x->astrozapper && y->storm && All(vec, { y })) return true;
				if (x->trickable && y->jedi && All(vec, { y })) return true;
				if (x->pushable && y->jedi && All(vec, { y })) return true;
				if (x->chokeable && y->choke && All(vec, { y })) return true;
				if (x == gamorreanguard && y->lukeAlt && All(vec, { y })) return true;
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
				if (x->pushable && y->jedi && All(vec, { y })) return true;
				if (x->chokeable && y->choke && All(vec, { y })) return true;
				if (x == gamorreanguard && y->lukeAlt && All(vec, { y })) return true;
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
	if (ptr({ current[pref] })) return pref;
	for (int i = current.size() - 1; i >= 0; i--) {
		if (ptr({ current[i] })) return i;
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
			if (!vec[i]({ p })) break;
			if (i == vec.size() - 1) return true;
		}
	}
	return false;
}

bool Multi(bool (*ptr)(std::vector<Playable*>), int n, std::vector<Playable*> current) {
	int x = 0;
	for (Playable* p : current) {
		if (ptr({ p })) {
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
			if (v({ p })) {
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

void charMaker() {

#define NORMAL \
  pi->lever = true, pi->build = true, pi->box = true, pi->jump = true, pi->chokeable = true
#define GRAPPLE pi->attack = true, pi->shoot = true, pi->grapple = true, NORMAL
#define DROID pi->droid = true, pi->gas = true, pi->pushable = true, pi->zappable = true
#define ASTRO                                                                  \
  pi->astro = true, pi->fly = true, pi->zapper = true, pi->astrozapper = true, \
  pi->pushable = true, pi->passive = true, DROID

#define JEDI                                                           \
  pi->doubleJump = true, pi->realDoubleJump = true, pi->attack = true, \
  pi->jedi = true, pi->deflect = true, pi->saber = true, NORMAL
	// GHOST does not have deflect
#define GHOST                                                          \
  pi->doubleJump = true, pi->realDoubleJump = true, pi->attack = true, \
  pi->jedi = true, pi->gas = true, pi->passive = true, pi->deflect = true, NORMAL


	quigon = new Playable("quigonjinn", "Qui-Gon Jinn", 25000, 0x7f1c30);
	JEDI, pi->hat = true;
	obiwan = new Playable("obiwankenobi", "Obi-Wan Kenobi", 22000, 0x7f1c38);
	JEDI, pi->hat = true;
	tc14 = new Playable("tc14", "TC-14", 4000, 0x7f202c, 0.75);
	DROID, pi->proto = true, pi->passive = true;
	jarjar = new Playable("jarjarbinks", "Jar Jar Binks", 14000, 0x7f1f00, 1.32);
	pi->highJump = true, pi->jump = true, pi->doubleJump = true,
		pi->realDoubleJump = true, pi->gunganJump = true, pi->build = true,
		pi->box = true, pi->trickable = true, pi->chokeable = true;
	amidala = new Playable("amidala", "Queen Amidala", 24000);
	GRAPPLE;
	panaka = new Playable("captainpanaka", "Captain Panaka", 12000);
	GRAPPLE;
	padmeBattle = new Playable("padmebattle", "Padmé (Battle)", 20000);
	GRAPPLE, pi->hat = true;
	r2d2 = new Playable("r2d2", "R2-D2", 5000, 0x7f1fa0, 1.0);
	ASTRO;
	anakinBoy = new Playable("anakin_boy", "Anakin Skywalker (Boy)", 6000, 0x0, 0.8);
	NORMAL, pi->hatch = true;

	obiwanJedi = new Playable("obiwankenobi_jedimaster", "Obi-Wan Kenobi (Jedi Master)", 30000, 0x7f1f18);
	JEDI, pi->hat = true;
	r4p17 = new Playable("r4_p17", "R4-P17", 4000, 0x0, 1.0);
	ASTRO;
	anakinPadawan = new Playable("anakin_padawan", "Anakin Skywalker (Padawan)", 24000, 0x7f1f10);
	JEDI, pi->hat = true;
	padmeGeonosis = new Playable("padmegeo", "Padmé (Geonosis)", 20000);
	GRAPPLE, pi->hat = true;
	c3po = new Playable("c3po", "C-3PO", 5000, 0x7f2020, 0.75);
	DROID, pi->proto = true, pi->passive = true;
	macewindu = new Playable("macewindu", "Mace Windu", 36000);
	JEDI, pi->hat = true;
	padmeClawed = new Playable("padmeclawed", "Padmé (Clawed)", 20000, 0x7f1f08);
	GRAPPLE, pi->hat = true;
	yoda = new Playable("yoda", "Yoda", 80000, 0x7f1d08, 1.44);
	JEDI, pi->yodaJump = true;

	obiwanEp3 = new Playable("obiwankenobi_ep3", "Obi-Wan Kenobi (Episode III)", 300000, 0x7f1f58);
	JEDI, pi->hat = true;
	anakinJedi = new Playable("anakin_jedi", "Anakin Skywalker (Jedi)", 35000, 0x7f1f60);
	JEDI, pi->hat = true;
	palpatine = new Playable("palpatine", "Chancellor Palpatine", 8000, 0x7f1f90);
	NORMAL, pi->hat = true;
	cody = new Playable("clone_ep3_sand", "Commander Cody", 12000, 0x7f1cb0, 1.0);
	GRAPPLE, pi->trickable = true, pi->imperial = true;
	chewbacca = new Playable("chewbacca", "Chewbacca", 18000, 0x7f1d50);
	GRAPPLE, pi->hat = true;

	leia = new Playable("princessleia", "Princess Leia", 20000, 0x7f1c40);
	GRAPPLE, pi->leiaAlt = true, pi->hat = true, pi->slightlyBetterJump = true;
	antilles = new Playable("captainantilles", "Captain Antilles", 14000, 0x7f1c58);
	GRAPPLE, pi->trickable = true, pi->slightlyBetterJump = true;
	rebelFriend = new Playable("rebelfriend", "Rebel Friend", 15000);
	GRAPPLE, pi->trickable = true, pi->slightlyBetterJump = true;
	lukeTatooine = new Playable("lukeskywalker_tatooine", "Luke Skywalker (Tatooine)", 12000);
	GRAPPLE, pi->dive = true, pi->hat = true;
	benKenobi = new Playable("benkenobi", "Ben Kenobi", 30000);
	JEDI, pi->hat = true;
	han = new Playable("hansolo", "Han Solo", 18000, 0x0, 1.44);
	GRAPPLE, pi->dive = true, pi->hat = true;
	hanStormtrooper = new Playable("hansolo_stormtrooper", "Han Solo (Stormtrooper)", 20000, 0x0, 1.44);
	GRAPPLE, pi->dive = true, pi->hat = true;
	lukeStormtrooper = new Playable("lukeskywalker_stormtrooper", "Luke Skywalker (Stormtrooper)", 14000);
	GRAPPLE, pi->dive = true, pi->hat = true;

	hanHoth = new Playable("hansolo_hoth", "Han Solo (Hoth)", 20000, 0x0, 1.44);
	GRAPPLE, pi->dive = true, pi->hat = true;
	leiaHoth = new Playable("princessleia_hoth", "Princess Leia (Hoth)", 22000);
	GRAPPLE, pi->leiaAlt = true, pi->hat = true, pi->slightlyBetterJump = true;
	lukePilot = new Playable("lukeskywalker_pilot", "Luke Skywalker (Pilot)", 14000);
	GRAPPLE, pi->dive = true; // no hat
	lukeDagobah = new Playable("lukeskywalker_dagobah", "Luke Skywalker (Dagobah)", 28000, 0x7f1e90);
	JEDI, pi->hat = true, pi->lukeAlt = true;
	lukeBespin = new Playable("lukeskywalker_bespin", "Luke Skywalker (Bespin)", 30000);
	JEDI, pi->hat = true, pi->lukeAlt = true;
	lando = new Playable("landocalrissian", "Lando Calrissian", 15000);
	GRAPPLE, pi->trickable = true, pi->dive = true, pi->hat = true, pi->landoAlt = true;
	leiaBespin = new Playable("princessleia_bespin", "Princess Leia (Bespin)", 22000);
	GRAPPLE, pi->leiaAlt = true, pi->slightlyBetterJump = true;  // no hat

	lukeJedi = new Playable("lukeskywalker_jedi", "Luke Skywalker (Jedi)", 40000);
	JEDI, pi->hat = true, pi->lukeAlt = true;
	leiaBoushh = new Playable("princessleia_boushh", "Princess Leia (Boushh)", 22000, 0x7f1c50);
	GRAPPLE, pi->leiaAlt = true, pi->hat = true, pi->slightlyBetterJump = true;
	landoPalaceGuard = new Playable("lando_palaceguard", "Lando (Palace Guard)", 15000);
	GRAPPLE, pi->trickable = true, pi->dive = true, pi->landoAlt = true;  // no hat
	hanSkiff = new Playable("hansolo_skiff", "Han Solo (Skiff)", 1.44, 0x0, 20000);
	GRAPPLE, pi->dive = true, pi->hat = true;
	leiaSlave = new Playable("princessleia_slave", "Princess Leia (Slave)", 40000, 0x7f1c48);
	GRAPPLE, pi->leiaAlt = true, pi->hat = true, pi->slightlyBetterJump = true;
	leiaEndor = new Playable("princessleia_endor", "Princess Leia (Endor)", 22000);
	GRAPPLE, pi->leiaAlt = true, pi->slightlyBetterJump = true;  // no hat
	lukeEndor = new Playable("lukeskywalker_endor", "Luke Skywalker (Endor)", 42000);
	JEDI, pi->lukeAlt = true;  // no hat
	hanEndor = new Playable("hansolo_endor", "Han Solo (Endor)", 20000, 0x0, 1.44);
	GRAPPLE, pi->dive = true, pi->hat = true;
	wicket = new Playable("wicket", "Wicket", 38000, 0x7f1dc8, 0.9);
	NORMAL, pi->trickable = true, pi->hatch = true, pi->shoot = true, pi->attack = true;
	vader = new Playable("darthvader", "Darth Vader", 150000, 0x7f1eb0);
	JEDI, pi->sith = true, pi->choke = true, pi->imperial = true;

	gonk = new Playable("gonkdroid", "Gonk Droid", 3000, 0x7f2018, 0.12);
	DROID, pi->passive = true;
	pkdroid = new Playable("pkdroid", "PK Droid", 1500, 0x7f1ce8, 0.8285375);
	DROID, pi->passive = true;
	battledroid = new Playable("battledroid", "Battle Droid", 6500, 0x7f1c88);
	DROID, pi->shoot = true, pi->attack = true;
	battledroidSecurity = new Playable("battledroid_security", "Battle Droid (Security)", 8500, 0x7f1ca0);
	DROID, pi->shoot = true, pi->attack = true;
	battledroidCommander = new Playable("battledroid_commander", "Battle Droid (Commander)", 10000, 0x7f1c90);
	DROID, pi->shoot = true, pi->attack = true;
	droideka = new Playable("destroyer", "Droideka", 40000, 0x7f1d78, 1.8);
	pi->droid = true, pi->zappable = true, pi->gas = true, pi->shoot = true, pi->attack = true;
	tarpals = new Playable("captaintarpals", "Captain Tarpals", 17500, 0x7f1c60, 1.32);
	pi->highJump = true, pi->jump = true, pi->doubleJump = true,
		pi->realDoubleJump = true, pi->gunganJump = true, pi->build = true,
		pi->box = true, pi->trickable = true, pi->attack = true, pi->chokeable = true;
	bossnass = new Playable("bossnass", "Boss Nass", 15000);
	NORMAL, pi->trickable = true;
	royalguard = new Playable("royalguard", "Royal Guard", 10000, 0x7f1fb8);
	GRAPPLE;
	padme = new Playable("padme", "Padmé", 20000);
	GRAPPLE, pi->hat = true;
	watto = new Playable("watto", "Watto", 16000, 0x7f1d38, 1.5);
	pi->flutter = true, pi->zapper = true;  // build, lever, chokeable, etc?
	pitdroid = new Playable("pitdroid", "Pit Droid", 4000, 0x7f2068, 0.8);
	DROID, pi->passive = true;
	maul = new Playable("darthmaul", "Darth Maul", 60000, 0x7f1c78);
	JEDI, pi->sith = true;

	zam = new Playable("zamwesell", "Zam Wesell", 27500);
	GRAPPLE, pi->trickable = true, pi->bounty = true, pi->slightlyBetterJump = true;
	dexter = new Playable("dexter", "Dexter Jettster", 10000, 0x0, 1.0);
	NORMAL, pi->trickable = true, pi->slightlyBetterJump = true;
	clone = new Playable("clone", "Clone", 13000, 0x0, 1.0);
	GRAPPLE, pi->trickable = true, pi->imperial = true;
	lamasu = new Playable("lamasu", "Lama Su", 9000, 0x7f2090);
	NORMAL, pi->tall = true;  // dooku skip
	taunwe = new Playable("taunwe", "Taun We", 9000, 0x7f2098);
	NORMAL, pi->tall;
	geonosian = new Playable("geonosian", "Geonosian", 20000, 0x7f1d30, 1.5);
	pi->shoot = true, pi->attack = true, pi->lever = true, pi->flutter = true,
		pi->pushable = true, pi->chokeable = true;
	battledroidGeonosis = new Playable("battledroid_geonosian", "Battle Droid (Geonosis)", 8500, 0x7f1c98);
	DROID, pi->shoot = true, pi->attack = true;
	superbattledroid = new Playable("superbattledroid", "Super Battle Droid", 25000, 0x7f1d80, 1.07);
	DROID, pi->shoot = true, pi->attack = true;
	jango = new Playable("jangofett", "Jango Fett", 70000, 0x7f1f38);
	GRAPPLE, pi->bounty = true, pi->fett = true, pi->fly = true;
	bobafettBoy = new Playable("bobafett_boy", "Boba Fett (Boy)", 5500, 0x0, 0.8);
	NORMAL, pi->hatch = true;
	luminara = new Playable("luminara", "Luminara", 28000, 0x7f1f28);
	JEDI;
	kiadimundi = new Playable("kiadimundi", "Ki-Adi Mundi", 30000);
	JEDI;
	kitfisto = new Playable("kitfisto", "Kit Fisto", 35000, 0x7f1f98);
	JEDI;
	shaakti = new Playable("shaakti", "Shaak Ti", 36000, 0x7f1f20);
	JEDI;
	aaylasecura = new Playable("aylasecura", "Aayla Secura", 37000);
	JEDI;
	plokoon = new Playable("plokoon", "Plo Koon", 39000);
	JEDI;

	dooku = new Playable("countdooku", "Count Dooku", 100000, 0x7f1f88);
	JEDI, pi->sith = true, pi->choke = true, pi->hat = true;
	magnaguard = new Playable("bodyguard", "Grievous' Bodyguard", 24000, 0x7f1c70, 1.4);
	pi->extraHighJump = true, pi->highJump = true, pi->jump = true, pi->doubleJump = true,
		pi->gas = true, pi->saber = true, pi->tall = true, pi->droid; //check droid, chokeable
	grievous = new Playable("grievous", "General Grievous", 70000, 0x7f1e48);
	pi->extraHighJump = true, pi->highJump = true, pi->jump = true, pi->doubleJump = true,
		pi->realDoubleJump = true, pi->build = true, pi->deflect = true, pi->saber = true; //chokeable???
	wookiee = new Playable("wookie", "Wookiee", 16000, 0x7f1d58);
	GRAPPLE, pi->hat = true;
	cloneEp3 = new Playable("clone_ep3", "Clone (Episode III)", 10000, 0x7f1ca8, 1.0);
	GRAPPLE, pi->trickable = true, pi->imperial = true;
	clonePilot = new Playable("clone_ep3_pilot", "Clone (Episode III, Pilot)", 11000, 0x0, 1.0);
	GRAPPLE, pi->trickable = true, pi->imperial = true;
	cloneSwamp = new Playable("clone_ep3_swamp", "Clone (Episode III, Swamp)", 12000, 0x0, 1.0);
	GRAPPLE, pi->trickable = true, pi->imperial = true;
	cloneWalker = new Playable("clone_ep3_walker", "Clone (Episode III, Walker)", 12000, 0x0, 1.0);
	GRAPPLE, pi->trickable = true, pi->imperial = true;
	macewinduEp3 = new Playable("macewindu_ep3", "Mace Windu (Episode III)", 38000);
	JEDI, pi->hat = true;
	disguisedclone = new Playable("disguisedclone", "Disguised Clone", 12000, 0x0, 1.0);
	GRAPPLE, pi->trickable = true, pi->imperial = true;

	rebeltrooper = new Playable("rebelscum", "Rebel Trooper", 10000);
	GRAPPLE, pi->trickable = true, pi->slightlyBetterJump = true;
	stormtrooper = new Playable("stormtrooper", "Stormtrooper", 10000, 0x7f1ff0);
	GRAPPLE, pi->storm = true, pi->trickable = true, pi->flop = true, pi->imperial = true;
	imperialshuttlepilot = new Playable("imperialshuttlepilot", "Imperial Shuttle Pilot", 25000, 0x7f2000);
	GRAPPLE, pi->trickable = true, pi->imperial = true, pi->slightlyBetterJump = true;
	tuskenraider = new Playable("tuskenraider", "Tusken Raider", 23000);
	GRAPPLE, pi->trickable = true, pi->hat = true, pi->slightlyBetterJump = true;
	jawa = new Playable("jawa", "Jawa", 24000, 0x7f1e88, 0.9);
	NORMAL, pi->trickable = true, pi->hatch = true, pi->zapper = true, pi->slightlyBetterJump = true;
	sandtrooper = new Playable("sandtrooper", "Sandtrooper", 14000);
	GRAPPLE, pi->storm = true, pi->trickable = true, pi->flop = true, pi->imperial = true;
	greedo = new Playable("greedo", "Greedo", 60000, 0x7f2050);
	GRAPPLE, pi->trickable = true, pi->bounty = true, pi->dive = true;
	imperialspy = new Playable("imperialspy", "Imperial Spy", 13500, 0x7f2048);
	NORMAL, pi->trickable = true, pi->slightlyBetterJump = true;
	beachtrooper = new Playable("beachtrooper", "Beach Trooper", 20000, 0x7f1ff8);
	GRAPPLE, pi->storm = true, pi->trickable = true, pi->flop = true, pi->imperial = true;
	deathstartrooper = new Playable("deathstartrooper", "Death Star Trooper", 19000, 0x7f1ea8);
	GRAPPLE, pi->storm = true, pi->trickable = true, pi->flop = true, pi->imperial = true;
	tiefighterpilot = new Playable("tiefighterpilot", "TIE Fighter Pilot", 21000);
	GRAPPLE, pi->storm = true, pi->trickable = true, pi->flop = true, pi->imperial = true;
	imperialofficer = new Playable("imperialofficer", "Imperial Officer", 28000, 0x7f2008);
	GRAPPLE, pi->trickable = true, pi->imperial = true, pi->slightlyBetterJump = true;
	tarkin = new Playable("grandmofftarkin", "Grand Moff Tarkin", 38000, 0x7f2010);
	GRAPPLE, pi->trickable = true, pi->imperial = true, pi->slightlyBetterJump = true, pi->hat = true;

	hanHood = new Playable("hansolo_hood", "Han Solo (Hood)", 20000, 0x0, 1.44);
	GRAPPLE, pi->dive = true, pi->hat = true;
	rebelHoth = new Playable("rebelhoth", "Rebel Trooper (Hoth)", 16000);
	GRAPPLE, pi->trickable = true, pi->slightlyBetterJump = true;
	rebelPilot = new Playable("rebelpilot", "Rebel Pilot", 15000);
	GRAPPLE, pi->trickable = true, pi->slightlyBetterJump = true;
	snowtrooper = new Playable("snowtrooper", "Snowtrooper", 16000, 0x7f1ea0);
	GRAPPLE, pi->storm = true, pi->trickable = true, pi->flop = true, pi->imperial = true;
	lukeHoth = new Playable("lukeskywalker_hoth", "Luke Skywalker (Hoth)", 14000);
	GRAPPLE, pi->dive = true;  // no hat
	lobot = new Playable("lobot", "Lobot", 11000);
	NORMAL, pi->trickable = true, pi->attack = true, pi->hat = true, pi->slightlyBetterJump = true;
	ugnaught = new Playable("ugnaught", "Ugnaught", 36000, 0x7f1fd8, 0.9);
	NORMAL, pi->trickable = true, pi->hatch = true, pi->zapper = true;
	bespinguard = new Playable("bespinguard", "Bespin Guard", 15000);
	GRAPPLE, pi->trickable = true, pi->dive = true;
	leiaPrisoner = new Playable("princessleia_prisoner", "Princess Leia (Prisoner)", 22000);
	GRAPPLE, pi->leiaAlt = true, pi->hat = true, pi->slightlyBetterJump = true;

	gamorreanguard = new Playable("gamorreanguard", "Gamorrean Guard", 40000, 0x7f1c80, 0.75);
	NORMAL, pi->trickable = true, pi->attack = true;
	bibfortuna = new Playable("bibfortuna", "Bib Fortuna", 16000);
	NORMAL, pi->trickable = true, pi->attack = true, pi->slightlyBetterJump = true;
	palaceguard = new Playable("palaceguard", "Palace Guard", 14000);
	GRAPPLE, pi->trickable = true, pi->slightlyBetterJump = true;  // no hat
	bossk = new Playable("bossk", "Bossk", 75000, 0x7f2058);
	GRAPPLE, pi->trickable = true, pi->bounty = true, pi->dive = true;
	skiffguard = new Playable("skiffguard", "Skiff Guard", 12000);
	GRAPPLE, pi->trickable = true, pi->slightlyBetterJump = true, pi->hat = true;
	boba = new Playable("bobafett", "Boba Fett", 100000, 0x7f1d88);
	GRAPPLE, pi->bounty = true, pi->fett = true, pi->fly = true;
	ewok = new Playable("ewok", "Ewok", 34000, 0x7f1dc0, 0.9);
	NORMAL, pi->trickable = true, pi->hatch = true, pi->shoot = true, pi->attack = true;
	imperialguard = new Playable("imperialguard", "Imperial Guard", 45000, 0x7f1c68);
	NORMAL, pi->storm = true, pi->trickable = true, pi->attack = true, pi->imperial = true, pi->slightlyBetterJump = true;
	emperor = new Playable("theemperor", "The Emperor", 275000, 0x7f1eb8);
	JEDI, pi->sith = true, pi->choke = true, pi->imperial = true;
	ackbar = new Playable("admiralackbar", "Admiral Ackbar", 33000, 0x0, 1.4); //test speed
	GRAPPLE, pi->dive = true, pi->doubleJump = true, pi->realDoubleJump = true;

	ig88 = new Playable("ig88", "IG-88", 100000);
	pi->attack = true, pi->shoot = true, pi->grapple = true, pi->bounty = true,
		pi->box = true, pi->jump = true, pi->astro = true, pi->proto = true, DROID, pi->chokeable = true;
	dengar = new Playable("dengar", "Dengar", 70000);
	GRAPPLE, pi->trickable = true, pi->bounty = true, pi->dive = true;
	f4lom = new Playable("4lom", "4-LOM", 45000, 0x7f1d90);
	pi->attack = true, pi->shoot = true, pi->grapple = true, pi->bounty = true,
		pi->box = true, pi->jump = true, pi->astro = true, pi->proto = true, DROID, pi->chokeable = true;
	benghost = new Playable("ghostbenkenobi", "Ben Kenobi (Ghost)", 1100000);
	GHOST, pi->hat = true;
	anakinghost = new Playable("anakin_ghost", "Anakin Skywalker (Ghost)", 1000000);
	GHOST, pi->hat = true;
	yodaghost = new Playable("yoda_ghost", "Yoda (Ghost)", 1200000, 0x7f1d10, 1.44);
	GHOST, pi->yodaJump = true;
	r2q5 = new Playable("r2q5", "R2-Q5", 100000, 0x7f1fa8, 1.0);
	ASTRO;
	indianajones = new Playable("hansolo_indy", "Indiana Jones", 50000, 0x7f20c0, 1.44);
	GRAPPLE, pi->dive = true, pi->hat = true;

	skeleton = new Playable("skeleton", "Skeleton", 3000, 0x7f20d0);
	pi->extratoggle = true; //chokeable?
	buzzdroid = new Playable("buzzdroid", "Buzz Droid", 1500, 0x7f20a0);
	DROID, pi->attack = true, pi->extratoggle = true;
	trainingremote = new Playable("trainingremote", "Training Remote", 2000, 0x7f1d98, 1.05);
	pi->droid = true, pi->gas = true, pi->fakeshoot = true, pi->hovering = true, pi->extratoggle = true;
	rebelengineer = new Playable("engineer", "Rebel Engineer", 8000);
	GRAPPLE, pi->trickable = true, pi->extratoggle = true, pi->slightlyBetterJump = true;
	droid1 = new Playable("naffdroid1", "Droid 1", 1500, 0x7f1cb8, 0.6);
	DROID, pi->passive = true, pi->shoot = true, pi->extratoggle = true;
	droid2 = new Playable("naffdroid2", "Droid 2", 1500, 0x7f1cc0, 0.6);
	DROID, pi->passive = true, pi->shoot = true, pi->extratoggle = true;
	droid3 = new Playable("naffdroid3", "Droid 3", 1500, 0x7f1cc8, 0.4);
	DROID, pi->passive = true, pi->shoot = true, pi->extratoggle = true;
	droid4 = new Playable("naffdroid4", "Droid 4", 1500, 0x7f1cd0, 0.6);
	DROID, pi->passive = true, pi->shoot = true, pi->extratoggle = true;
	womprat = new Playable("womprat", "Womp Rat", 25000, 0x7f1d00, 1.8);
	pi->passive = true, pi->extratoggle = true; //chokeable?
	mousedroid = new Playable("mousedroid", "Mouse Droid", 3000, 0x7f1cd8, 2.4);
	DROID, pi->passive = true, pi->extratoggle = true;
	imperialengineer = new Playable("imperialengineer", "Imperial Engineer", 9000);
	GRAPPLE, pi->storm = true, pi->trickable = true, pi->flop = true, pi->imperial = true, pi->extratoggle = true;
	hanCarbonite = new Playable("hanincarbonite", "Han Solo (frozen in carbonite)", 5000, 0x0, 0.75);
	pi->extratoggle = true;  // dooku skip, also kaminoans, chokeable?
	atatdriver = new Playable("atat_driver", "AT-AT Driver", 25000);
	GRAPPLE, pi->storm = true, pi->trickable = true, pi->flop = true, pi->imperial = true, pi->extratoggle = true;
	scouttrooper = new Playable("scouttrooper", "Scout Trooper", 16000);
	GRAPPLE, pi->storm = true, pi->trickable = true, pi->flop = true, pi->imperial = true, pi->extratoggle = true;

	anakinsPod = new Playable("newanakinspod", "Anakin's Pod", 20000, 0x7f21e0);
	pi->vehicle = true;
	nabooStarfighter = new Playable("naboostarfighter", "Naboo Starfighter", 12000, 0x7f20b0);
	pi->shoot = true, pi->attack = true, pi->tow = true, pi->vehicle = true;
	anakinsSpeeder = new Playable("anakinsspeeder", "Anakin's Speeder", 15000, 0x7f21f0);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;
	gunship = new Playable("newrepublicgunship", "Republic Gunship", 18000, 0x7f1f78);
	pi->shoot = true, pi->attack = true, pi->tow = true, pi->vehicle = true;
	starfighterYellow = new Playable("jedistarfighter_yellow_ep3", "Jedi Starfighter (Yellow)", 10000, 0x7f1f40);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;
	starfighterRed = new Playable("jedistarfighter_red_ep3", "Jedi Starfighter (Red)", 10000, 0x7f1f48);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;

	xwing = new Playable("xwing", "X-wing", 25000, 0x7f1fb0);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;
	ywing = new Playable("ywing", "Y-wing", 25000, 0x7f1e38);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;
	snowspeeder = new Playable("snowspeeder", "Snowspeeder", 20000, 0x7f1fc0);
	pi->shoot = true, pi->attack = true, pi->tow = true, pi->vehicle = true;
	milleniumFalcon = new Playable("millenniumfalcon", "Millennium Falcon", 40000, 0x7f1ec0);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;

	sebulbasPod = new Playable("sebulbaspod", "Sebulba's Pod", 20000, 0x7f21c0);
	pi->vehicle = true;
	zamsAirspeeder = new Playable("zamsspeeder", "Zam's Airspeeder", 24000, 0x7f2200);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;
	droidTrifighter = new Playable("droidtrifighter", "Droid Trifighter", 28000, 0x7f2210);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;
	vultureDroid = new Playable("vulturedroid", "Vulture Droid", 30000, 0x7f2208);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;
	arcfighter = new Playable("clonearc", "Clone Arcfighter", 33000, 0x7f20a8);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;
	tiefighter = new Playable("tiefighter", "TIE Fighter", 35000, 0x7f1e58);
	pi->shoot = true, pi->attack = true, pi->tiedoor = true, pi->vehicle = true;
	tieinterceptor = new Playable("tieinterceptor", "TIE Interceptor", 40000, 0x7f1fc8);
	pi->shoot = true, pi->attack = true, pi->tiedoor = true, pi->vehicle = true;
	tiefighterVader = new Playable("tiefighterdarth", "TIE Fighter (Darth Vader)", 50000, 0x7f1e50);
	pi->shoot = true, pi->attack = true, pi->tiedoor = true, pi->vehicle = true;
	tiebomber = new Playable("tiebomber", "TIE Bomber", 60000, 0x7f1e40);
	pi->shoot = true, pi->attack = true, pi->tiedoor = true, pi->vehicle = true;
	imperialshuttle = new Playable("imperialshuttle", "Imperial Shuttle", 25000, 0x7f1fd0);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;
	slave1 = new Playable("slave1", "Slave 1", 100000, 0x7f1e30);
	pi->shoot = true, pi->attack = true, pi->vehicle = true;

	anakinsPodGreen = new Playable("newanakinspod_green", "Anakin's Pod (Green)", 20000, 0x7f21b8);
	pi->vgreen = true, pi->vehicle = true;
	nabooStarfighterGreen = new Playable("naboostarfighter_lime", "Naboo Starfighter (Green)", 12000, 0x7f20b8);
	pi->shoot = true, pi->attack = true, pi->tow = true, pi->vgreen = true, pi->vehicle = true;
	anakinsSpeederGreen = new Playable("anakinsspeeder_green", "Anakin's Speeder (Green)", 15000, 0x7f21f8);
	pi->shoot = true, pi->attack = true, pi->vgreen = true, pi->vehicle = true;
	gunshipGreen = new Playable("newrepublicgunship_green", "Republic Gunship (Green)", 18000, 0x7f1f80);
	pi->shoot = true, pi->attack = true, pi->tow = true, pi->vgreen = true, pi->vehicle = true;




	defaultCharacter = new Playable("", "", 0, 0x0);
	pi->defaultCharacter = true;

	for (Playable* p : pls) {
		if (!p->defaultCharacter) {
			if (p->vehicle) {
				if (greenVeh || !p->vgreen) vhs.push_back(p);
			} else {
				if (extog || !p->extratoggle) chs.push_back(p);

			}
		}
	}

}

void levMaker() {

	//name, characters, episode, unlocks, vehicle level, alt second name for Escape and Theed, characters not in party
	Negotiations = new Level("NEGOTIATIONS", { quigon, obiwan, tc14 }, TPM,
		{ quigon, obiwan, tc14, battledroid, battledroidSecurity, battledroidCommander, droideka });
	Invasion = new Level("GUNGAN", { quigon, obiwan, jarjar }, TPM,
		{ jarjar, tarpals, bossnass });
	EscapeNaboo = new Level("PALACERESCUE", { amidala, panaka, quigon, obiwan }, TPM,
		{ amidala, panaka, royalguard, padme }, false, "RESCUE");
	Podrace = new Level("PODSPRINT", { anakinsPod, anakinsPodGreen }, TPM,
		{ watto, pitdroid, anakinsPod, anakinsPodGreen, sebulbasPod }, true);
	Theed = new Level("RETAKEPALACE", { obiwan, quigon, panaka, padmeBattle, r2d2, anakinBoy }, TPM,
		{ padmeBattle, r2d2, anakinBoy }, false, "RETAKE");
	Maul = new Level("MAUL", { obiwan, quigon }, TPM,
		{ maul });

	BHP = new Level("PURSUIT", { anakinsSpeeder, anakinsSpeederGreen }, CLN,
		{ zam, dexter, anakinsSpeeder, anakinsSpeederGreen, zamsAirspeeder }, true);
	Kamino = new Level("KAMINO", { obiwanJedi, r4p17 }, CLN,
		{ obiwanJedi, r4p17, clone, lamasu, taunwe });
	Factory = new Level("FACTORY", { anakinPadawan, padmeGeonosis, r2d2, c3po, obiwanJedi }, CLN,
		{ anakinPadawan, padmeGeonosis, c3po, geonosian, battledroidGeonosis, skeleton }, false, "", 4);
	JediBattle = new Level("JEDI", { macewindu, r2d2, obiwanJedi, anakinPadawan, padmeClawed }, CLN,
		{ macewindu, padmeClawed, superbattledroid, jango, bobafettBoy, luminara, kiadimundi, kitfisto, shaakti, aaylasecura, plokoon });
	Gunship = new Level("GUNSHIP", { gunship, gunshipGreen }, CLN,
		{ gunship, gunshipGreen }, true);
	Dooku = new Level("DOOKU", { obiwanJedi, anakinPadawan, yoda }, CLN,
		{ yoda });

	Coruscant = new Level("DOGFIGHT", { starfighterYellow, starfighterRed }, STH,
		{ starfighterYellow, starfighterRed, droidTrifighter, vultureDroid, arcfighter }, true);
	Chancellor = new Level("CRUISER", { obiwanEp3, anakinJedi, r2d2, palpatine }, STH,
		{ obiwanEp3, anakinJedi, palpatine, dooku, magnaguard, buzzdroid });
	Grievous = new Level("GRIEVOUS", { obiwanEp3, cody }, STH,
		{ cody, grievous });
	Kashyyyk = new Level("KASHYYYK", { yoda, chewbacca }, STH,
		{ chewbacca, wookiee, cloneEp3, clonePilot, cloneSwamp, cloneWalker });
	Ruin = new Level("TEMPLE", { obiwanEp3, yoda }, STH,
		{ macewinduEp3, disguisedclone, trainingremote });
	Vader = new Level("VADER", { obiwanEp3, anakinJedi }, STH);

	SecretPlans = new Level("BLOCKADERUNNER", { leia, antilles, rebelFriend, c3po, r2d2 }, ANH,
		{ leia, antilles, rebelFriend, rebeltrooper, stormtrooper, imperialshuttlepilot, rebelengineer });
	Jundland = new Level("TATOOINE", { lukeTatooine, benKenobi, c3po, r2d2 }, ANH,
		{ lukeTatooine, benKenobi, tuskenraider, jawa, droid1, droid2, droid3, droid4, womprat });
	Spaceport = new Level("MOSEISLEY", { lukeTatooine, benKenobi, r2d2, c3po, han, chewbacca }, ANH,
		{ han, sandtrooper, greedo, imperialspy });
	Princess = new Level("DEATHSTARRESCUE", { hanStormtrooper, lukeStormtrooper, chewbacca, r2d2, c3po, benKenobi, leia }, ANH,
		{ hanStormtrooper, lukeStormtrooper, beachtrooper, deathstartrooper, tiefighterpilot, imperialofficer, tarkin, mousedroid, imperialengineer }, false, "", 7);
	DSE = new Level("DEATHSTARESCAPE", { han, chewbacca, leia, lukeTatooine, r2d2, c3po }, ANH);
	RebelAttack = new Level("DEATHSTARBATTLE", { xwing, ywing }, ANH,
		{ xwing, ywing, tiefighter, tieinterceptor, tiefighterVader }, true);

	Hoth = new Level("HOTHBATTLE", { snowspeeder, snowspeeder }, EMP,
		{ snowspeeder }, true);
	EchoBase = new Level("HOTHESCAPE", { hanHoth, leiaHoth, c3po, chewbacca }, EMP,
		{ hanHoth, leiaHoth , hanHood, rebelHoth, rebelPilot, snowtrooper, lukeHoth });
	FalconFlight = new Level("ASTEROIDCHASE", { milleniumFalcon, xwing }, EMP,
		{ milleniumFalcon, tiebomber, imperialshuttle }, true);
	Dagobah = new Level("DAGOBAH", { lukePilot, r2d2, lukeDagobah, yoda }, EMP,
		{ lukePilot, lukeDagobah });
	CCT = new Level("CLOUDCITYTRAP", { lukeBespin, r2d2 }, EMP,
		{ lukeBespin, hanCarbonite });
	Bespin = new Level("CLOUDCITYESCAPE", { lando, leiaBespin, chewbacca, r2d2, c3po }, EMP,
		{ lando, leiaBespin, lobot, ugnaught, bespinguard, leiaPrisoner });

	Jabbas = new Level("JABBASPALACE", { leiaBoushh, chewbacca, lukeJedi, c3po, r2d2, hanSkiff }, JDI,
		{ lukeJedi, leiaBoushh, hanSkiff, gamorreanguard, bibfortuna, palaceguard, bossk });
	Carkoon = new Level("SARLACCPIT", { landoPalaceGuard, lukeJedi, chewbacca, hanSkiff, c3po, r2d2, leiaSlave }, JDI,
		{ landoPalaceGuard, leiaSlave, skiffguard, boba });
	Showdown = new Level("SPEEDERCHASE", { leiaEndor, lukeEndor }, JDI,
		{ leiaEndor, lukeEndor, atatdriver, scouttrooper });
	Endor = new Level("ENDORBATTLE", { hanEndor, leiaEndor, r2d2, chewbacca, c3po, wicket }, JDI,
		{ hanEndor, wicket, ewok });
	Destiny = new Level("EMPERORFIGHT", { lukeJedi, vader }, JDI,
		{ vader, imperialguard, emperor });
	ITDS = new Level("DEATHSTAR2BATTLE", { milleniumFalcon, xwing }, JDI,
		{ ackbar }, true);

	Anakinsflight = new Level("ANAKINSFLIGHT", { nabooStarfighter, nabooStarfighterGreen }, LEV,
		{ nabooStarfighter, nabooStarfighterGreen }, true);
	ANewHope = new Level("ANEWHOPE", { vader, stormtrooper, c3po }, STH);

	BHM = new Level("", { boba, greedo, ig88, f4lom, bossk, dengar,
		quigon, amidala, jarjar, macewindu, kitfisto, luminara, kiadimundi, rebeltrooper, shaakti, cody,
		r2d2, benKenobi, chewbacca, leia, ackbar, yoda, c3po, lando, lukeTatooine, han }, "", {}, false, "", -1);

	defaultLevel = new Level("", {}, "", { gonk, pkdroid });
	allEpisodes = new Level("", {}, "", { ig88, dengar, f4lom, benghost, anakinghost, yodaghost, r2q5, indianajones, slave1 });

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
