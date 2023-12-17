#include "pch.h"

//#ifdef WXWIN
//#include "App.h"
//#endif

#include "CharacterData.h"
#include "Characters.h"
#include "Defines.h"
#include "Enemies.h"
#include "EnemyData.h"
#include "EnemyPatch.h"
#include "FileGen.h"
#include "LevelData.h"
#include "Levels.h"
#include "OtherStuff.h"
#include "Randomize.h"
#include <fstream>

Playable* quigonjinn;
Playable* obiwankenobi;
Playable* tc14;
Playable* jarjarbinks;
Playable* amidala;
Playable* captainpanaka;
Playable* padmebattle;
Playable* r2d2;
Playable* anakin_boy;
Playable* obiwankenobi_jedimaster;
Playable* r4_p17;
Playable* anakin_padawan;
Playable* padmegeo;
Playable* c3po;
Playable* macewindu;
Playable* padmeclawed;
Playable* yoda;
Playable* obiwankenobi_ep3;
Playable* anakin_jedi;
Playable* palpatine;
Playable* clone_ep3_sand;
Playable* chewbacca;
Playable* princessleia;
Playable* captainantilles;
Playable* rebelfriend;
Playable* lukeskywalker_tatooine;
Playable* benkenobi;
Playable* hansolo;
Playable* hansolo_stormtrooper;
Playable* lukeskywalker_stormtrooper;
Playable* hansolo_hoth;
Playable* princessleia_hoth;
Playable* lukeskywalker_pilot;
Playable* lukeskywalker_dagobah;
Playable* lukeskywalker_bespin;
Playable* landocalrissian;
Playable* princessleia_bespin;
Playable* lukeskywalker_jedi;
Playable* princessleia_boushh;
Playable* lando_palaceguard;
Playable* hansolo_skiff;
Playable* princessleia_slave;
Playable* princessleia_endor;
Playable* lukeskywalker_endor;
Playable* hansolo_endor;
Playable* wicket;
Playable* darthvader;
Playable* gonkdroid;
Playable* pkdroid;
Playable* battledroid;
Playable* battledroid_security;
Playable* battledroid_commander;
Playable* destroyer;
Playable* captaintarpals;
Playable* bossnass;
Playable* royalguard;
Playable* padme;
Playable* watto;
Playable* pitdroid;
Playable* darthmaul;
Playable* zamwesell;
Playable* dexter;
Playable* clone_ep2;
Playable* lamasu;
Playable* taunwe;
Playable* geonosian;
Playable* battledroid_geonosian;
Playable* superbattledroid;
Playable* jangofett;
Playable* bobafett_boy;
Playable* luminara;
Playable* kiadimundi;
Playable* kitfisto;
Playable* shaakti;
Playable* aylasecura;
Playable* plokoon;
Playable* countdooku;
Playable* bodyguard;
Playable* grievous;
Playable* wookie;
Playable* clone_ep3;
Playable* clone_ep3_pilot;
Playable* clone_ep3_swamp;
Playable* clone_ep3_walker;
Playable* macewindu_ep3;
Playable* disguisedclone;
Playable* rebelscum;
Playable* stormtrooper;
Playable* imperialshuttlepilot;
Playable* tuskenraider;
Playable* jawa;
Playable* sandtrooper;
Playable* greedo;
Playable* imperialspy;
Playable* beachtrooper;
Playable* deathstartrooper;
Playable* tiefighterpilot;
Playable* imperialofficer;
Playable* grandmofftarkin;
Playable* hansolo_hood;
Playable* rebelhoth;
Playable* rebelpilot;
Playable* snowtrooper;
Playable* lukeskywalker_hoth;
Playable* lobot;
Playable* ugnaught;
Playable* bespinguard;
Playable* princessleia_prisoner;
Playable* gamorreanguard;
Playable* bibfortuna;
Playable* palaceguard;
Playable* bossk;
Playable* skiffguard;
Playable* bobafett;
Playable* ewok;
Playable* imperialguard;
Playable* theemperor;
Playable* admiralackbar;
Playable* ig88;
Playable* dengar;
Playable* fourlom;
Playable* ghostbenkenobi;
Playable* anakin_ghost;
Playable* yoda_ghost;
Playable* r2q5;
Playable* hansolo_indy;
Playable* skeleton;
Playable* buzzdroid;
Playable* trainingremote;
Playable* engineer;
Playable* naffdroid1;
Playable* naffdroid2;
Playable* naffdroid3;
Playable* naffdroid4;
Playable* womprat;
Playable* mousedroid;
Playable* imperialengineer;
Playable* hanincarbonite;
Playable* atat_driver;
Playable* scouttrooper;
Playable* newanakinspod;
Playable* naboostarfighter;
Playable* anakinsspeeder;
Playable* newrepublicgunship;
Playable* jedistarfighter_yellow_ep3;
Playable* jedistarfighter_red_ep3;
Playable* xwing;
Playable* ywing;
Playable* snowspeeder;
Playable* millenniumfalcon;
Playable* sebulbaspod;
Playable* zamsspeeder;
Playable* droidtrifighter;
Playable* vulturedroid;
Playable* clonearc;
Playable* tiefighter;
Playable* tieinterceptor;
Playable* tiefighterdarth;
Playable* tiebomber;
Playable* imperialshuttle;
Playable* slave1;
Playable* newanakinspod_green;
Playable* naboostarfighter_lime;
Playable* anakinsspeeder_green;
Playable* newrepublicgunship_green;
Playable* defaultCharacter;
Playable* fakeAnakinsPod;
Playable* fakeAnakinsPodGreen;
Playable* kaminodroid;
Playable* sentrydroid;
Playable* bat;

Playable* att;
Playable* mtt;
Playable* atst_lowres;
Playable* hailfiredroid;
Playable* jumbohomingdroid;

Playable* probedroid;
Playable* speederbike_snow;
Playable* droidstarfighter;

Level* Negotiations;
Level* Invasion;
Level* EscapeNaboo;
Level* Podrace;
Level* Theed;
Level* Maul;
Level* BHP;
Level* Kamino;
Level* Factory;
Level* JediBattle;
Level* Gunship;
Level* Dooku;
Level* Coruscant;
Level* Chancellor;
Level* Grievous;
Level* Kashyyyk;
Level* Ruin;
Level* Vader;
Level* SecretPlans;
Level* Jundland;
Level* Spaceport;
Level* Princess;
Level* DSE;
Level* RebelAttack;
Level* Hoth;
Level* EchoBase;
Level* FalconFlight;
Level* Dagobah;
Level* CCT;
Level* Bespin;
Level* Jabbas;
Level* Carkoon;
Level* Showdown;
Level* Endor;
Level* Destiny;
Level* ITDS;
//Level* PodraceOriginal;
Level* Anakinsflight;
Level* ANewHope;
Level* BHM;
Level* Cantina;

EnemyType* clone_ep3_sand_en;
EnemyType* battledroid_en;
EnemyType* battledroid_security_en;
EnemyType* battledroid_commander_en;
EnemyType* destroyer_en;
EnemyType* geonosian_en;
EnemyType* battledroid_geonosian_en;
EnemyType* superbattledroid_en;
EnemyType* bodyguard_en;
EnemyType* clone_ep3_en;
EnemyType* clone_ep3_swamp_en;
EnemyType* disguisedclone_en;
EnemyType* stormtrooper_en;
EnemyType* imperialshuttlepilot_en;
EnemyType* tuskenraider_en;
EnemyType* sandtrooper_en;
EnemyType* beachtrooper_en;
EnemyType* deathstartrooper_en;
EnemyType* tiefighterpilot_en;
EnemyType* imperialofficer_en;
EnemyType* snowtrooper_en;
EnemyType* gamorreanguard_en;
EnemyType* skiffguard_en;
EnemyType* imperialguard_en;
EnemyType* scouttrooper_en;
EnemyType* kaminodroid_en;
EnemyType* sentrydroid_en;
EnemyType* bat_en;

EnemyType* att_en;
EnemyType* mtt_en;
EnemyType* atst_lowres_en;
EnemyType* hailfiredroid_en;
EnemyType* jumbohomingdroid_en;

EnemyType* droidstarfighter_en;
EnemyType* tiefighter_en;
EnemyType* tieinterceptor_en;
EnemyType* tiebomber_en;
EnemyType* probedroid_en;
EnemyType* speederbike_snow_en;

std::unordered_map<Playable*, const char*> SpecialScripts;

extern bool character;
extern bool extog;
extern bool greenVeh;

extern bool extra;
extern bool collectable;
extern bool enemy;
extern bool panelOp;
extern bool hatOp;
extern bool colorOp;
extern bool enemyOp;
//extern bool advanceMus;
extern LogicType logicType;
//extern std::unique_ptr<std::ofstream> loggingIt;

uint64_t seed = 0;
std::mt19937_64* randoPTR;

extern std::string out;
extern std::string vanillaDirectory;

std::vector<Level*> allLevels;

std::vector<Playable*> pls;                    //Characters and Vehicles
std::vector<Playable*> chs;                    //Characters
std::vector<Playable*> vhs;                    //Vehicles
std::vector<Playable*> testing = {};           //Current logic;
std::vector<DispenserType> availableHats = {}; //Current logic;
std::vector<EnemyType*> enemyTypes;            //AvailableEnemies
std::vector<EnemyType*> flyerTypes;
std::vector<EnemyType*> walkerTypes;
Level* currentLev;

size_t addressPointer;
size_t junkCharacters;

void Randomize() {

	std::cout << "Randomizing\n";
	addressPointer = 0x2B0;
	junkCharacters = 0x3f1b6c;

	std::random_device rd;

	std::mt19937_64 rando(rd());
	randoPTR = &rando;

	makeCharacters();
	makeEnemyTypes();
	makeLevels();
	//makeEnemies();

	currentLev = BHM;

#if (0)
	int blueColor = 0x00bfff;
	int greenColor = 0x1ebf0f;
	int redColor = 0xff1f00;
	int purpleColor = 0xc800ff;

	if (colorOp) {
		blueColor = rand() % 0xFFFFFF;
		greenColor = rand() % 0xFFFFFF;
		redColor = rand() % 0xFFFFFF;
		purpleColor = rand() % 0xFFFFFF;
	}
	rgb red;
	rgb blue;
	rgb green;
	rgb purple;
#endif

	//std::array<std::string, 36> extras = {
	std::array<std::string, 36> extras = {"supergonk", "poomoney", "walkietalkiedisable", "powerbrickdetector",
		"superslap", "forcezipup", "coinmagnet", "disarmtroopers", "characterstuds", "perfectdeflect",
		"explodingblasterbolts", "forcepull", "vehiclesmartbomb", "superastromech", "superjedislam",
		"superthermaldetonator", "deflectbolts", "darkside", "superblasters", "fastforce", "supersabres", "tractorbeam",
		"invincibility", "scorex2", "selfdestruct", "fastbuild", "scorex4", "regenerate", "scorex6", "minikitdetector",
		"superzapper", "rockets", "scorex8", "superewokcatapult", "scorex10", "infinitetorpedos"};

	std::array<std::string, 36> vanillaExtras = extras;

	if (extra) {
		std::shuffle(extras.begin(), extras.end(), rando);
	}

	if (collectable) {
		for (int i = 0; i < 36; i++) {
			int q = 0;
			std::array<char, 21> collect = {'m', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'c', 'c', 'c', 'c', 'c',
				'c', 'c', 'c', 'c', 'c', 'r'};
			std::shuffle(collect.begin(), collect.end(), rando);
			for (Collectable& col : allLevels[i]->collectables) {
				for (std::pair<char, int>& pairr : col.typeAddress) {
					pairr.first = collect[q];
					++q;
				}
			}

			for (SpecialCollectable& col : allLevels[i]->specialCollectables) {
				col.type = collect[q];
				++q;
			}
		}
	}
	Playable* cantina1 = quigonjinn;
	Playable* cantina2 = obiwankenobi;
	Playable* indy = hansolo_indy;
	Playable* allMinikitsCharacter = slave1;

	auto tooLong = [](int ch) {
		//SCP files do not work if name is too long
		if (currentLev->party[ch]->name.length() > 16) return true;
		else return false;
	};

negotiations:
	mix(Negotiations);

	if (tooLong(2)) goto negotiations;

	if (!atrb(Jedi)) goto negotiations;

	add(2);
	if (logicType == casual) {
		if (!panel(2, 1) || !panel(0, 2) || !panel(0, 3) || !Multi((DoubleJump), 2)) goto negotiations;
	} else {

		if (!Multi(Jump | Flutter, 2)) goto negotiations;

		if (SuperJump()) goto invasion;
		if (panel(2, 1) && panel(0, 2) && panel(0, 3)) goto invasion;

		goto negotiations;
	}

invasion:
	mix(Invasion);
	if (tooLong(2)) goto invasion;

	if (logicType == casual) {
		if (atrb(Jedi)) goto invasion2;

	} else {
		if (atrb(Jedi) || atrb(HighJump)) goto invasion2;
	}
	goto invasion;

invasion2:
	add(2);
	if (logicType == casual) {
		if (!atrb(HighJump)) goto invasion;
	} else {
		if (atrb(Jedi)) goto escape;
		if (atrb(Fett) && atrb(HighDoubleJump)) goto escape;
		goto invasion;
	}

escape:
	mix(EscapeNaboo);
	if (atrb(Grapple)) goto podrace;

	if (logicType != casual) {
		if (SuperJump(Jump | Flutter) && atrb(Shoot)) goto podrace;
	}
	goto escape;

podrace:
	mix(Podrace);

theed:
	mix(Theed);
	add(2);
	add(3);
	add(4);
	add(5); //0 and 1 are in->mix function.

	if (logicType == casual) {
		if (panel(0, 0) && panelAny(1, 0, Jedi | Grapple | Hatch | Fly) && panel(2, 0) && Multi(Jedi, 2) &&
			atrb(Hatch) && Multi(DoubleJump | Grapple | Hatch | Fly, 6))
			goto maul;
	} else {
		if (logicType != superGlitched) {
			//button room
			std::vector<Playable*> overGap;
			for (Playable* p : testing) {
				if (p->check(Fly)) overGap.push_back(p);
				else if (p->check(Grapple)) overGap.push_back(p);
				else if (p->check(HighJump)) overGap.push_back(p);
				else if (atrb(Jedi)) {
					if (p->check(Jump) && p->speed >= 0.79f) overGap.push_back(p);
					else if (p->check(Flutter)) overGap.push_back(p);
				} else if (atrb(Choke) && p->check(Chokeable)) overGap.push_back(p);
				else if (atrb(Lightning) && p->check(Lightningable)) overGap.push_back(p);
			}
			if (overGap.size() < 6) goto theed;
		}

		if (panelAny(1, 0, Fly | Grapple | HighJump)) goto theed2;
		if (atrb(Jedi) && panelAny(1, 0, Jump | Fly | Flutter)) goto theed2;
		goto theed;

	theed2:

		if (!panel(2, 0)) goto theed; //hangar

		if (!panel(0, 0) && !atrb(Jedi)) goto theed; //first room

		if (!All(DoubleJump | Attack) && !atrb(Shoot)) goto theed;
		if (!atrb(HighJump) && !atrb(Jedi) && !SuperJump(Jump | Flutter)) goto theed;
		goto maul;
	}
	goto theed;

maul:
	mix(Maul);

	if (logicType == casual) {
		if (Multi(Jedi, 2) && LivingJedi()) goto bhp;
	} else {
		if (Multi(Jedi, 2)) goto bhp;
	}
	goto maul;

bhp:
	mix(BHP);

	if (atrb(Shoot)) goto kamino;

	goto bhp;

kamino:
	mix(Kamino);

	//Jango fight
	if (Multi(Passive, 2) && !(Shoot)) goto kamino;

	if (!atrb(Jedi)) goto kamino;
	if (logicType == casual) {
		if (!panel(2, 1)) goto kamino; //clone room
		if (!panel(3, 2)) goto kamino; //to jango fight
		if (!panel(4, 0)) goto kamino; //to elevator
		if (!atrb(Fly)) goto kamino;

	} else { //worst superjump ever
		if (atrb(Jedi) && atrb(Fly) && SuperJump(Jump)) goto factory;

		if (!panel(2, 1)) goto kamino;                //clone room
		if (!panel(3, 2) && !atrb(Jedi)) goto kamino; //to jango fight
		if (!atrb(Fly)) goto kamino;                  //to elevator
	}

factory:
	mix(Factory);
	if (tooLong(2)) goto factory;
	if (tooLong(3)) goto factory;

	if (!atrb(Attack)) goto factory;

	add(2); //r2
	if (!panelAny(1, 1, Fly | Jump)) goto factory;
	//if (!panelAnd(1, 1, Fly) && !panelAnd(1, 1, Jump)) goto factory;

	if (logicType == casual) {
		if (!atrb(Jedi) && !atrb(ExtraHighJump)) goto factory;
	} else {
		if (!atrb(Jedi) && !atrb(HighJump)) goto factory;

		if (atrb(Jedi) && panelAny(1, 1, Fly)) goto factory2;

		if (panelAny(1, 1, Jedi)) goto factory2;
	}

	if (atrb(Grapple)) goto factory2;

	goto factory;

factory2:
	add(3); //3po
	//if (All({Astro, Proto})) goto factory;
	if (!atrb(Jedi)) goto factory;

	if (!panel(2, 0)) goto factory; //turn thing room
	if (!panel(4, 1)) goto factory; //end room

	if (logicType == casual) {
		if (panelAny(3, 1, DoubleJump)) goto jedibattle;
		if (panelAny(3, 1, Fly)) goto jedibattle;
		if (panelAny(3, 0, DoubleJump) && panel(3, 1)) goto jedibattle;
		if (panelAny(3, 0, Fly) && panel(3, 1)) goto jedibattle;

		goto factory;
	} else {
		//extending bridge
		if (panelOr(3, 0, DoubleJump | Pushable | Fly)) goto factory3;
		if (panelAny(3, 0, Chokeable) && atrb(Choke)) goto factory3;
		if (panelAny(3, 0, Lightningable) && atrb(Lightning)) goto factory3;

		//if you can't extend the bridge
		testing.clear();
		for (Playable* p : Factory->party) {
			if (p->check(DoubleJump)) testing.push_back(p);
			if (p->check(Fly)) testing.push_back(p);
			if (p->check(Pushable)) testing.push_back(p);
			if (p->check(Chokeable) && atrb(Choke, Factory->party)) testing.push_back(p);
			if (p->check(Lightningable) && atrb(Lightning, Factory->party)) testing.push_back(p);
		}

	factory3:
		if (panel(3, 1)) goto jedibattle;

		goto factory;
	}

jedibattle:

	mix(JediBattle);

	if (!atrb(Jedi)) goto jedibattle;

gunship:
	mix(Gunship);

	if (!atrb(Tow)) goto gunship;

dooku:
	mix(Dooku);
	if (Multi(Passive, 2) && !atrb(Shoot)) //fixes the softlock that Zojalyx got
		goto dooku;
	if (logicType == casual) {
		if (!Multi(Jedi, 2)) goto dooku;
	} else {
		if (!atrb(Jedi | Shoot)) goto dooku;
	}
	//Yoda cutscene
	testing.clear();
	add(0);
	add(2);
	if (!atrb(Attack)) goto dooku;
	if (Multi(Passive, 2) && !atrb(Shoot)) goto dooku;

coruscant:
	mix(Coruscant);

	if (!atrb(Shoot)) goto coruscant;

chancellor:
	mix(Chancellor);
	if (tooLong(2)) goto chancellor;
	if (tooLong(3)) goto chancellor;

	if (!atrb(Jedi)) goto chancellor;

	add(2);                            //r2
	if (!panel(0, 2)) goto chancellor; //bomb, might be possible to skip
	if (!panel(0, 3) && logicType == casual) goto chancellor; //top of room

	add(3); //palpatine
	if (!Multi(Jedi, 2)) goto chancellor;

	if (logicType == casual && GetSlowest() < 1.0) goto chancellor;

	bool gasOff = false;
	if (panelAny(3, 0, Gas | Fly)) gasOff = true;
	if (logicType != casual && panelAny(3, 0, DoubleJump | Dive | Flop)) gasOff = true;
	if (gasOff && panel(3, 1)) goto grievous;
	if (panelAny(3, 1, Gas | Fly)) goto grievous;
	if (logicType != casual && panelAny(3, 1, DoubleJump | Dive | Flop)) goto grievous;
	goto chancellor;

grievous:
	mix(Grievous);
	if (logicType == casual) {
		if (!atrb(Jedi)) goto grievous;
		if (!atrb(Grapple)) goto grievous;
	} else {
		if (atrb(Jedi)) goto kashyyyk;
		if (All(Jump | Shoot)) goto kashyyyk;

		goto grievous;
	}

kashyyyk:
	mix(Kashyyyk);
	if (!atrb(Jedi)) goto kashyyyk;
	if (logicType == casual) {
		if (!atrb(Grapple)) goto kashyyyk;
	} else {
		if (!Multi(Jump | Flutter, 2)) goto kashyyyk;
		if (logicType != superGlitched) {
			//no enemies on buttons except in super glitched
			if (!atrb(Grapple) && !atrb(YodaJump)) goto kashyyyk;
		}
	}

ruin:
	mix(Ruin);
	if (!atrb(Jedi)) goto ruin;

vader:
	mix(Vader);
	if (Multi(Ghost, 2)) goto vader;
	if (logicType == casual) {
		if (Multi(Jedi, 2)) goto secretplans;
	} else {
		if (!atrb(Jedi)) goto vader;
		if (GetSlowest() <= 1.01) goto vader;
		if (Multi(DoubleJump, 2)) goto secretplans;
		if (atrb(YodaJump)) //force clip into wall thing
			goto secretplans;
		if (InstantSuperJump()) goto secretplans;
	}

	goto vader;

secretplans:
	bool supercraneDoor = false;
	auto plansthing = [&supercraneDoor](std::vector<Playable*> current, Playable* shield, Playable* redGuy) {
		//This is for scene 3 super jump
		if (logicType != superGlitched) return false;

		for (Playable* x : current) {
			for (Playable* y : current) {
				bool OOB = false;
				bool OOB2 = false;

				if (x != y) {
					if (x->att & Pushable && y->att & Jedi) OOB = true;
					else if (x->att & Chokeable && y->att & Choke) OOB = true;
					else if (x->att & Lightningable && y->att & Lightning) OOB = true;
					else if (x->att & Trickable && y->att & Jedi) OOB = true;
					else if (x->att & Zappable && y->att & Zapper) OOB = true;
					else if (x->att & Storm && y->att & AstroZapper) OOB = true;
					else if (x->att & LeiaAlt && y->att & LandoAlt) OOB = true;
					else if (x == gamorreanguard && y->att & LukeAlt) OOB = true;

					Playable* otherX = defaultCharacter;
					if (OOB) {
						for (Playable* x2 : current) {
							for (Playable* y2 : current) {
								if (x2 != y2 && x2 != x) {
									if (x2->att & Pushable && y2->att & Jedi) OOB2 = true;
									else if (x2->att & Chokeable && y2->att & Choke) OOB2 = true;
									else if (x2->att & Lightningable && y2->att & Lightning) OOB2 = true;
									else if (x2->att & Trickable && y2->att & Jedi) OOB2 = true;
									else if (x2->att & Zappable && y2->att & Zapper) OOB2 = true;
									else if (x2->att & Storm && y2->att & AstroZapper) OOB2 = true;
									else if (x2->att & LeiaAlt && y2->att & LandoAlt) OOB2 = true;
									else if (x2 == gamorreanguard && y2->att & LukeAlt) OOB2 = true;

									if (OOB2) otherX = x2;
								}
							}
						}
						//HATS HATS HATS HATS HATS HATS HATS HATS HATS HATS HATS
#define plnp SecretPlans->party
						if (panel(2, 2, {x, shield}) && panel(2, 1, {plnp[1], plnp[2], plnp[3], plnp[4]})) {
							supercraneDoor = true;
							return true;
						}
						if (panel(2, 1, {x, otherX}) && atrb(Box | Bounty, {x, otherX})) {
							supercraneDoor = true;
							return true;
						}
						if (panel(2, 1, {redGuy}) && (atrb(DoubleJump | Fly, {x, otherX}) ||
														 (atrb(Box | Bounty, {x}) && atrb(Lever, {redGuy})))) {
							supercraneDoor = true;
							return true;
						}
						//not sure
					}
				}
			}
		}
		return false;
	};

	mix(SecretPlans);

	if (logicType == casual) {
		if (!All(Grapple | Build) && !All(YodaJump | Build) && !All(ExtraHighJump | Build)) goto secretplans;
		if (!atrb(Lever)) goto secretplans;
		if (!atrb(Shoot) && !atrb(FakeShoot)) goto secretplans;

	} else {
		addHat(0, 0);

		if (!atrb(Attack)) goto secretplans;
		if (!atrb(Build)) goto secretplans;
		if (!atrb(Lever)) goto secretplans;
		if (((All(Grapple | Build) || atrb(YodaJump) || //Both Yodas can build
				 All(ExtraHighJump | Build)) &&
				(atrb(Shoot) || atrb(FakeShoot))) ||
			SuperJump(Jump | Flutter) || DoubleTransitionSkip(Jump | Flutter))
			goto secretplans2;
		goto secretplans;
	}
secretplans2:

	add(3); //3po
	if (logicType == casual) {
		if (!panel(2, 0)) //midtro panel
			goto secretplans;
	} else {
		//Bounties can get the car
		if (atrb(Jedi | Bounty) && panel(2, 2, {SecretPlans->party[4]})) goto secretplans3;

		if (atrb(Hat) && availableHats[0] == BountyHat && panel(2, 2, {SecretPlans->party[4]})) goto secretplans3;

		if (panel(2, 0) && panel(2, 2, {SecretPlans->party[1], SecretPlans->party[3], SecretPlans->party[4]}))
			goto secretplans3;

		//droids and rebel friend area with super jumps
		if (plansthing({SecretPlans->party[0], SecretPlans->party[1], SecretPlans->party[3]}, SecretPlans->party[4],
				SecretPlans->party[2]))
			goto secretplans3;

		if (panel(2, 0) && plansthing({SecretPlans->party[1], SecretPlans->party[3], SecretPlans->party[4]},
							   defaultCharacter, SecretPlans->party[2]))
			goto secretplans3;

		goto secretplans;
	}

secretplans3:

	testing.clear();
	add(1); //midtro
	add(3);
	add(4);
	if (logicType == casual) {
		if (!panel(2, 2)) goto secretplans;
		if (!atrb(Jedi | Fett) && !(SecretPlans->party[2]->check(Lever) && atrb(Box | Bounty))) goto secretplans;
	}

	add(2); //rebel friend
	if (panel(2, 1)) supercraneDoor = true;
	if (!supercraneDoor) goto secretplans;

	if (!atrb(Lever)) goto secretplans;
	if (atrb(Build)) goto secretplans4;

	{
		std::vector<Playable*> temp = testing;
		testing.clear();
		for (Playable* p : temp) {
			if (p->check(Jump) || p->check(Fly)) testing.push_back(p);
		}
	}

secretplans4:
	//escape pods
	if (!panel(3, 3)) goto secretplans;
	if (!panel(3, 4)) goto secretplans;
	if (!panel(3, 5)) goto secretplans;
	if (!panel(3, 6)) goto secretplans;

jundland:
	mix(Jundland);
	if (logicType == casual) {
		if (!atrb(Jedi)) goto jundland;
		if (!All(Grapple | Lever)) goto jundland;
	} else {
		if (atrb(Jedi)) goto jundland4;
		//if (HighJump() && DoubleTransitionSkip(Jump)) goto jundland4; //can get inside but cannot
		//get past first area
		goto jundland;
	}

jundland4:
	add(3); //r2
	if (logicType == casual) {
		if (!panel(0, 2)) goto jundland;
		if (!Multi(Lever, 2)) goto jundland;
	} else {
		if (panel(0, 2)) goto jundland2;
		if (InstantSuperJump()) //&& atrb(Proto)
			goto jundland2;
		goto jundland;
	}
jundland2:
	if (Multi(Lever, 2)) goto jundland3;
	//only grapple characters can do weirdshots
	if (atrb(Grapple) && logicType == superGlitched) goto jundland3;

	if (atrb(Grapple)) {
		std::vector<Playable*> temp = {};
		for (Playable* p : testing) {
			if (p->check(Fly) || p->check(DoubleJump)) temp.push_back(p);
		}
		if (panel(0, 3, temp)) temp.push_back(Jundland->party[2]);
		if (panel(0, 4, temp)) goto spaceport;

		goto jundland;
	}

jundland3:
	if (panel(0, 3)) add(2); //3po
	if (!panel(0, 4)) goto jundland;

	testing  = Jundland->party;
	if (logicType == casual) {
		if (!panel(1, 0)) {
			std::vector<Playable*> temp = testing;
			testing.clear();
			for (Playable* p : temp) {
				if (p->check(Jump | Fly | Flutter | Hovering)) testing.push_back(p);
			}
		}
		if (!panel(1, 1)) goto jundland;
		if (!panel(1, 2)) goto jundland;
	}

spaceport:
	mix(Spaceport);
	add(2);
	add(3);
	//cantina buttons
	if (logicType == casual && !atrb(Shoot) && !atrb(FakeShoot)) {
		for (Playable* p : testing)
			if (p->check(Droid) && !p->check(Jump)) goto spaceport3;
		goto spaceport;
	}

spaceport3:
	if (logicType == casual) {
		if (!panel(0, 3) && !panel(0, 4)) goto spaceport;
		//jump off speeder to skip forcing ramp
		if (!atrb(Jedi) && !panelAny(0, 3, Jump) && !panelAny(0, 4, Jump)) goto spaceport;

		if (atrb(Bounty)) goto spaceport2;
		if (panel(1, 0) && panel(1, 1)) goto spaceport2;

		goto spaceport;
	} else {
		if (!atrb(Box)) goto spaceport;
	}

spaceport2:
	testing.clear();
	add(4); //han and chewbacca
	add(5);
	if (logicType == casual) {
		if (!atrb(Box)) goto spaceport;
	} else {
		if (!atrb(Box) && !atrb(DoubleJump)) goto spaceport;
		if (GetFastest() > 1.2001) //test exact number
			goto princess;
	}
	if (!atrb(Attack) && !atrb(FakeShoot)) goto spaceport;
	if (atrb(Bounty)) goto princess;
	if (All(Grapple | Lever | Box)) goto princess;
	if (All(DoubleJump | Lever | Box)) goto princess;
	goto spaceport;

princess:
	mix(Princess);
	if (tooLong(5)) goto princess;

	add(2);
	add(3);
	add(4);
	add(5);
	if (!atrb(Jedi)) goto princess;
	addHat(0, 0);

	if (logicType == casual) {
		if (!panel(0, 0)) goto princess;
		if (!panel(0, 2)) goto princess;
	}

	testing.clear();
	add(0); //midtro
	add(1);
	add(2);
	if (logicType == casual) availableHats.clear();
	addHat(1, 0);
	addHat(1, 1);

	{
		bool gotHats = false;
		if ((panel(1, 0) || panel(1, 2)) && logicType != casual) {
			//bonus room with lots of hat machines
			addHat(3, 0);
			addHat(3, 1);
			addHat(3, 2);
			addHat(3, 3);
			gotHats = true;
		}

		if (!Princess->party[5]->check(Jedi) && !atrb(DoubleJump | Fly)) goto princess;
		if (!atrb(Grapple)) goto princess;
		if (!panel(1, 3)) goto princess; //try oil glitch

		if (logicType == casual) availableHats.clear();

		if (panel(2, 0)) goto dse;

		{
			std::vector<Playable*> hasThisHat;
			for (Playable* p : testing)
				if (p->check(Grapple)) hasThisHat.push_back(p);

			addHat(2, 0);
			if (panel(2, 0, hasThisHat)) goto dse;

			if ((panel(1, 1, hasThisHat) || panel(1, 2, hasThisHat)) && !gotHats && logicType != casual) {
				//bonus room with lots of hat machines
				availableHats.pop_back();
				addHat(3, 0);
				addHat(3, 1);
				addHat(3, 2);
				addHat(3, 3);
				if (panel(2, 0)) goto dse;
			}

			goto princess;
		}
	} //gotHats

dse:
	mix(DSE);
	add(2);
	add(3);
	addHat(0, 0);

	if (!atrb(Build)) goto dse;
	if (!Multi(Lever, 2)) goto dse;

	//first area
	if (panelAny(0, 1, Grapple)) goto dse3;
	if (panelAny(0, 1, DoubleJump)) goto dse3;
	goto dse;

dse3:
	if (logicType == casual) availableHats.clear();
	addHat(1, 0);
	if (!panelAny(1, 0, Grapple)) goto dse;

	if (logicType == casual) availableHats.clear();
	addHat(2, 0);
	if (!panelAny(2, 0, Grapple)) goto dse;

	if (logicType == casual) {
		add(4); //droids
		add(5);
		if (!panel(2, 1)) goto dse;
		if (!panel(2, 3)) goto dse;
		//Droideka and mouse droid do not need floor waxer.
		//Uses slightly lower value to avoid rounding errors.
		if (!panel(2, 4) && GetFastest() < 1.799) goto dse;
	}

rebelattack:
	mix(RebelAttack);

	if (!atrb(Shoot)) goto rebelattack;

hoth:
	mix(Hoth);

	if (!atrb(Tow)) goto hoth;

echobase:
	mix(EchoBase);
	if (logicType == casual) {
		if (!atrb(Build)) goto echobase;
		if (!atrb(Box)) goto echobase;
		if (!atrb(Attack | FakeShoot)) goto echobase;
	} else {
		if (atrb(Build) && atrb(Box) && atrb(Attack | FakeShoot)) goto echobase2;
		if (panel(0, 0) && SuperJump()) goto echobase2;
		goto echobase;
	}

echobase2:
	add(2); //3po

	if (panel(0, 1)) goto echobase3;
	if (SuperJump()) goto echobase3;
	goto echobase;
echobase3:
	//snomobile
	if (logicType == casual) {
		if (!panel(1, 1)) goto echobase;
	}

	if (!atrb(Build)) goto echobase;
	if (!atrb(Box)) goto echobase;

	//ending
	add(3); //chewbacca
	if (Multi(Lever, 2)) goto falconflight;
	if (All(DoubleJump | Build)) goto falconflight;
	if (logicType != casual) {
		if (SuperJump(Build)) //everyone who can build can jump or flutter
			goto falconflight;
		for (Playable* p : testing) {
			if (p->check(DoubleJump) && p->check(Build)) goto falconflight;
			if (p->check(Dive) && p->check(Build)) goto falconflight;
			if (p->check(Flop) && p->check(Build)) goto falconflight;
			if (p->check(SlightlyBetterJump) && p->check(Build)) goto falconflight;
		}
	}
	goto echobase;

falconflight:
	mix(FalconFlight);
	if (!atrb(Shoot)) goto falconflight;

dagobah:
	mix(Dagobah);
	if (!atrb(DoubleJump | Fly | Flutter | Tall | Hovering)) goto dagobah;
	if (logicType == casual) {
		if (!atrb(Build | Flutter | Tall | Hovering)) goto dagobah;
		testing.clear(); //training room
		add(1);
		add(2);
		if (!atrb(Jedi)) goto dagobah;
		if (!panelAny(4, 0, Fly) && !panelAny(4, 0, DoubleJump)) goto dagobah;

	} else {
		if (Multi(Jump | Fly | Flutter | Tall | Hovering, 2) && atrb(AstroZapper)) goto dagobah2;
		//test
		testing.clear();
		//training
		add(1);
		add(2);
		if (atrb(AstroZapper)) goto dagobah2;
		if (atrb(Jedi)) {
			if (atrb(YodaJump)) goto dagobah2;
			if (panel(4, 0)) goto dagobah2;
		}
		goto dagobah;
	}

dagobah2:
	testing.clear(); //cave
	add(1);
	add(2);
	add(3);
	if (logicType == casual) {
		if (!Multi(Jedi, 2)) goto dagobah;

		//you can easily double jump accross
		//if (!panelAnd(1, 0, {Fly}) && !All({Flutter, Attack}) && !All({Hovering, FakeShoot})) goto
		//dagobah;

		if (!panel(2, 0)) goto dagobah;

	} else {
		if (!atrb(Jedi)) goto dagobah;
		if (!panel(2, 0)) goto dagobah;
	}

cct:

	currentLev = CCT;

	if (logicType == casual) {

		//probability of getting valid seed is so low that using mix() takes too long.

	cctCasual:
		mix(CCT);
		testing.clear();
		availableHats.clear();

		if (character) {
			CCT->party.clear();

			std::uniform_int_distribution<int> distrib(0, chs.size() - 1);
			Playable* c1 = (chs)[distrib(*randoPTR)];
			Playable* c2 = (chs)[distrib(*randoPTR)];
			if (c1 == c2) goto cctCasual;

			CCT->party.push_back(c1);
			CCT->party.push_back(c2);
		}

		add(0);
		add(1);
		if (!atrb(Jedi)) goto cctCasual;
		if (!atrb(Active)) goto cctCasual;

		std::uniform_int_distribution<int> panDist(0, 3);
		auto rPanMake = [&panDist](int panSet, int pan) {
			if (panelOp) {
				CCT->panels[panSet].panels[pan].type = (PanelType)panDist(*randoPTR);
			}
		};

		auto rPan = [&rPanMake](int panSet, int pan) {
			//Greatly speeds up seed generation; not sure about seed distribution
			for (int i = 0; i < 25; ++i) {
				rPanMake(panSet, pan);
				if (panel(panSet, pan)) break;
			}
			return panel(panSet, pan);
		};

		rPanMake(1, 1);

		rPanMake(1, 2);

		if (All(Fly | Active)) goto cct8;
		if (panelAny(1, 1, Fly) && panelAny(1, 2, Fly)) goto cct8;
		goto cctCasual;
	cct8:

		if (!rPan(0, 2)) goto cctCasual;

		if (!rPan(0, 4)) goto cctCasual;

		if (!rPan(2, 0)) goto cctCasual;

		if (!rPan(2, 1) && !atrb(Fett)) goto cctCasual;
		if (!rPan(2, 2) && !atrb(Fett)) goto cctCasual;
		if (!rPan(2, 3) && !atrb(Fett)) goto cctCasual;

		if (!rPan(1, 0)) goto cctCasual;

		//first room
		int bridgeUp = false;
		rPanMake(0, 0);

		if (panelAny(0, 0, Fly)) bridgeUp = true;

		std::vector<Playable*> overBridge;

		for (Playable* p : testing) {
			if (p->check(Fly)) overBridge.push_back(p);
			if (bridgeUp && p->check(Jump)) overBridge.push_back(p);
		}

		rPanMake(0, 1);
		if (!atrb(Build, overBridge)) goto cctCasual;
		if (!panel(0, 1, overBridge)) goto cctCasual;

		if (hatOp) {
			std::uniform_int_distribution<int> hatDist(0, 2);
			int temp = hatDist(*randoPTR);
			if (temp != 0) temp += 4;
			CCT->dispensers[0].dispenser[0].type = (DispenserType)temp;
		}

		std::vector<Playable*> balcony;
		addHat(0, 0);
		rPanMake(0, 7);
		for (Playable* p : testing) {
			if (p->check(Fett)) balcony.push_back(p);
		}

		if (rPan(0, 5)) {
			for (Playable* p : testing) {
				for (Playable* q : testing) {
					if (p != q) {
						if (panel(0, 7, {p}) && atrb(Box, {q})) balcony = testing;
					}
				}
			}
		}

		rPanMake(0, 6);
		if (!panel(0, 6, balcony)) goto cctCasual;

		rPanMake(0, 3);
		rPanMake(1, 3);

		if (panelOp) {
			for (PanelSet& panSet : CCT->panels) {
				for (Panel& pan : panSet.panels) {

					if (pan.type == AstroPanel || pan.type == ProtoPanel) {
						std::uniform_int_distribution<int> bin(0, 1);
						pan.altColor = bin(*randoPTR);
						pan.altBody = bin(*randoPTR);
					}
				}
			}
		}

	} else {

	cctGlitch:

		mix(CCT);

		if (!atrb(Jedi)) goto cctGlitch;
		if (!atrb(Active)) goto cctGlitch;

		//first room
		int bridgeUp = false;
		if (panelAny(0, 0, Fly)) bridgeUp = true;

		std::vector<Playable*> overBridge;

		for (Playable* p : testing) {
			//check fluttering
			if (p->check(Fly)) overBridge.push_back(p);
			if (bridgeUp && p->check(Jump)) overBridge.push_back(p);
		}

		if (logicType != superGlitched) {
			if (!atrb(Build, overBridge)) goto cctGlitch;
			if (!panel(0, 1, overBridge)) goto cctGlitch;
		} else {
			if (overBridge.size() == 0) goto cctGlitch;
		}

		//second room
		if (!atrb(Bounty) && !panel(0, 2)) goto cctGlitch;
		//you can skip panel at end of hallway with door clip pixel jump
		//try hitting room 3 transition from OOB

		//dv1
		addHat(0, 0);
		std::vector<Playable*> dv1;
		for (Playable* p : testing) {
			if (p->check(Fly) || p->check(RealDoubleJump)) dv1.push_back(p);
		}

		//if you actually do the fight
		if (panel(0, 5)) {
			//go through door during camera pan
			if (dv1.size() > 1 || Multi(Attack, 2)) {
				if (logicType != superGlitched) {
					availableHats.clear(); //cannot backtrack
				}
				goto cct2;
			}

			dv1 = testing; //use crane
		}
		if (panel(0, 6, dv1)) goto cct2;
		if (panel(0, 7, dv1)) {
			//raise platform
			//does not matter - need dj anyway
			//for (Playable* p : testing) {
			//	//see if this needs dj
			//	if (p->jump) dv1.push_back(p);
			//}
		}

		goto cctGlitch;
	cct2:
		//dvt
		//bounty and imperial panels have different hitbox, so you probably cannot do DV2 skip
		if (CCT->panels[2].panels[1].type == AstroPanel && panel(2, 1) && logicType == superGlitched) goto cct3;
		if (atrb(Fett)) goto cct3; //can jump to vader to skip panels
		if (panel(2, 2) && panel(2, 3)) goto cct3;
		goto cctGlitch;

	cct3:
		//dv3
		for (Playable* p : testing) {
			if ((p->check(RealDoubleJump | Fly) && !p->check(Passive))) goto bespin;
		}

		goto cctGlitch;
	}

bespin:
	mix(Bespin);
	add(2);

	if (!(atrb(Lever) && atrb(Attack | FakeShoot)) && !atrb(DoubleJump) && !atrb(Flutter) && !atrb(Hovering))
		goto bespin;

	{
		std::vector<Playable*> pastFight;
		std::vector<Playable*> pastDoor;
		bool got3po = false;
		bool gotr2 = false;
		bool openneddoor = false;
		bool room2 = false;
		bool r2Door = false;
		bool bonusHat = false;

		if (panel(0, 5)) r2Door = true;

		//old OOB
		if (logicType != casual && r2Door) {
			for (Playable* p : testing) {
				if (p->check(DoubleJump) || (p->check(Jump) && p->speed >= 1.199)) pastFight.push_back(p);
			}
		}

		while (!room2) {
			size_t tempSize = testing.size();
			size_t hatSize = availableHats.size();
			if (!bonusHat) {
				if (panel(0, 0)) {
					addHat(0, 0);
					bonusHat = true;
				}
			}
			if (panel(0, 1)) pastFight = testing;
			if (panel(0, 1, {bobafett}) && atrb(Attack)) pastFight = testing;

			//slave 1
			if (!gotr2 && pastFight.size() != 0) {
				std::vector<Playable*> temp = pastFight;
				temp.push_back(Bespin->party[3]);
				if (panel(0, 4, temp)) {
					add(3);
					pastFight.push_back(Bespin->party[3]);
					gotr2 = true;

				} else {
					for (Playable* p : temp) {
						if ((p->check(Gas) || (logicType != casual && p->check(Jump))) //BTS
							&& (panel(0, 5, {p}) || (r2Door && logicType != casual))) {
							add(3);
							pastFight.push_back(Bespin->party[3]);
							gotr2 = true;
							r2Door = true;
						}
					}
				}
			}

			//built 3po
			if (!got3po) {
				if (panel(0, 3, pastFight)) {
					if (atrb(Build, pastFight) && atrb(Lever, pastFight) && atrb(Box, pastFight)) {
						add(4);
						pastFight.push_back(Bespin->party[4]);
						got3po = true;
					}
				}
				//door clip to get 3po
				if (logicType != casual && All(Build | Jump, pastFight) && All(Lever | Jump, pastFight) &&
					All(Box | Jump, pastFight)) {
					if (r2Door || gotr2 || panel(0, 6, pastDoor)) {
						add(4);
						pastFight.push_back(Bespin->party[4]);
						got3po = true;
					}
				}
			}

			//door clip
			if (logicType != casual) {
				for (Playable* p : pastFight) {
					if (p->check(Jump)) pastDoor.push_back(p);
				}
			}

			//open door normally
			if (!openneddoor) {
				if (panel(0, 2, pastFight)) {
					pastDoor = pastFight;
					addHat(0, 1);
					openneddoor = true;
				}
			}

			std::vector<DispenserType> tempHats = availableHats;
			tempHats.push_back(Bespin->dispensers[0].dispenser[1].type);
			if (panel(0, 6, pastDoor, tempHats)) pastDoor = testing;
			if (panel(0, 7, pastDoor, tempHats)) room2 = true;

			//if no advancements are made, seed must be bad
			if (tempSize == testing.size() && availableHats.size() == hatSize) goto bespin;
		}
	}

bespin2:
	testing.clear();
	availableHats.clear();

	if (logicType != casual) {
		addHat(0, 1);
		if (panel(0, 0)) addHat(0, 0);
	}

	add(0);
	add(1);
	add(2);
	add(3);
	add(4);
	if (!All(Lever | Grapple)) goto bespin;

	if (logicType == casual) {
		if (!panelAny(1, 0, Fly)) goto bespin;

		if (!All(Box | DoubleJump) && !All(Box | Grapple)) goto bespin;

		if (!panel(1, 1)) goto bespin;
		if (!panel(1, 2)) goto bespin;
		if (!panel(1, 3)) goto bespin;

	} else {
		std::vector<Playable*> overGap;
		if (panelAny(1, 0, Fly)) overGap = testing;
		else
			for (Playable* p : testing) {
				if (p->check(Fly)) overGap.push_back(p);
			}

		//box clip
		if (Multi(Fett, 2, overGap)) goto jabbas;
		//if (panel(1, 1, overGap) && (atrb(Gas, overGap) || panel(1, 2, overGap))) goto jabbas;
		////fix this
		if (panel(1, 1, overGap)) {
			if (atrb(Gas, overGap)) {
				if (panelAny(1, 2, Gas)) goto jabbas;
				if (panelAny(1, 3, Gas)) {
					if (panel(1, 2)) goto jabbas;
				}
			}
		}

		if (Separate(Box, Fly, overGap)) goto jabbas;
		if (Separate(Box, Gas, overGap)) {
			if (panelAny(1, 2, Gas)) goto jabbas;
			if (panelAny(1, 3, Gas)) {
				if (panel(1, 2)) goto jabbas;
			}
		}
		goto bespin;
	}

jabbas:
	mix(Jabbas);
	//door
	if (!atrb(Shoot) && !atrb(FakeShoot) && !atrb(Deflect)) goto jabbas;
	if (!atrb(Build) && !atrb(DoubleJump)) goto jabbas;

	//inside
	addHat(0, 0);
	std::vector<Playable*> pastGate;

	if (panel(0, 2)) {
		pastGate = testing;
	} else if (logicType != casual) {
		for (Playable* p : testing) {
			if (p->check(YodaJump)) pastGate.push_back(p);

			if (logicType == superGlitched) {
				for (Playable* x : testing) {
					if (p != x) {
						if (x->check(Jedi) && p->check(Pushable)) pastGate.push_back(p);
						if (x->check(Choke) && p->check(Chokeable)) pastGate.push_back(p);
						if (x->check(Lightning) && p->check(Lightningable)) pastGate.push_back(p);
						if (x->check(Zapper) && p->check(Zappable)) pastGate.push_back(p);
						if (x->check(Jedi) && p->check(Trickable)) pastGate.push_back(p);
						if (x->check(AstroZapper) && p->check(Storm)) pastGate.push_back(p);
						if (x->check(LandoAlt) && p->check(LeiaAlt)) pastGate.push_back(p);
						if (x->check(LukeAlt) && p == gamorreanguard) pastGate.push_back(p);
					}
				}
			}
		}
	}

	if (pastGate.size() != 0) pastGate.push_back(Jabbas->party[2]);

	if (!panel(0, 1, pastGate)) goto jabbas;
	if (!atrb(Build, pastGate)) goto jabbas;

jabbas2: //scene B
	add(2);
	if (logicType == casual) availableHats.clear();
	addHat(1, 0);
	if (logicType == casual) {
		if (!atrb(Jedi)) goto jabbas;
		if (!boom()) goto jabbas;

		std::vector<Playable*> droidRoom;
		for (Playable* t : testing)
			if (atrb(Jump | Fly | Flutter, {t})) //can get into droid room
				droidRoom.push_back(t);

		if (atrb(Jedi, droidRoom)) {
			droidRoom.push_back(Jabbas->party[3]);
			droidRoom.push_back(Jabbas->party[4]);
		}
		if (panel(1, 1, droidRoom) && panel(1, 2, droidRoom) && panel(1, 3, droidRoom)) goto jabbas3;

	} else {
		if (atrb(Jedi)) goto jabbas3;

		std::vector<Playable*> droidRoom;
		if (boom()) droidRoom = testing;
		else {
			for (Playable* t : testing) {
				if (t->check(Box)) { //can get into droid room
					droidRoom.push_back(t);
				}
			}
		}

		if (atrb(DoubleJump, droidRoom)) {
			droidRoom.push_back(Jabbas->party[3]);
			droidRoom.push_back(Jabbas->party[4]);
		}
		if (atrb(Jedi, droidRoom)) goto jabbas3;

		if (panel(1, 1, droidRoom) && panel(1, 2, droidRoom) && panel(1, 3, droidRoom)) goto jabbas3;
	}
	goto jabbas;

jabbas3: //long room

	testing.clear();
	if (logicType == casual) availableHats.clear();
	add(0);
	add(1);
	add(2);
	add(3);
	add(4);
	if (logicType == casual) {
		if (!panel(2, 0)) goto jabbas;
		if (!panelAny(2, 1, Fly) && !panelAny(2, 0, Fly)) goto jabbas;
		addHat(2, 0);
		addHat(2, 1);
		if (!panel(2, 3)) goto jabbas;

	} else {
		if (atrb(Jedi)) goto jabbas4;

		if (panelAny(2, 0, Fly | Box | DoubleJump)) goto jabbas4;

		if (SuperJump(Jump | Flutter)) goto jabbas4;
		goto jabbas;
	}

jabbas4: //rancor

	if (logicType != superGlitched) availableHats.clear();
	else {
		addHat(2, 0);
		addHat(2, 1);
	}
	testing.clear();
	add(1);
	add(2);
	add(3);
	add(4);
	if (!panel(3, 0) && !panel(3, 1) && !panel(3, 0, {Jabbas->party[5]}, {}) && !panel(3, 1, {Jabbas->party[5]}, {})) {

		goto jabbas;
	}

	add(5);
	if (!atrb(Attack) && !atrb(FakeShoot)) goto jabbas;
	if (!atrb(Lever)) goto jabbas;

carkoon:

	mix(Carkoon);
	add(0);
	add(1);
	if (atrb(Lever) && atrb(Build)) goto carkoon2;
	if (atrb(Fly)) goto carkoon2;
	if (logicType != casual) {
		if (atrb(RealDoubleJump)) goto carkoon2;
	}
	goto carkoon;

carkoon2: //second skiff
	add(2);
	add(3);
	if (logicType == casual) {
		if (!atrb(Grapple)) goto carkoon;
		if (!atrb(Jedi)) goto carkoon;
	} else {
		if (atrb(Jedi)) goto carkoon3;
		if (!atrb(Build)) goto carkoon;
		if (!atrb(Box)) goto carkoon;

		//superjump to skip Jedi in entire opening
		if (logicType == superGlitched) {
			//You might be able to get over there with flop.
			if (Multi(DoubleJump | Fly | Dive, 2)) goto carkoon4;
			if (atrb(Grapple) && Multi(DoubleJump | Dive, 2)) goto carkoon4;
			goto carkoon;
		carkoon4:
			//boba fight
			if (atrb(Shoot)) goto carkoon5;
			if (All(DoubleJump | Attack)) goto carkoon5;
			if (All(Fly | Attack)) goto carkoon5;
			if (All(Dive | Attack)) goto carkoon5;

			goto carkoon;
		carkoon5:
			if (All(DoubleJump | Lever)) goto carkoon3;
			if (All(Fly | Lever)) goto carkoon3;
			if (All(Dive | Lever)) goto carkoon3;

			goto carkoon;
		}
		goto carkoon;
	}

carkoon3: //inside
	add(4);
	add(5);
	if (logicType == casual) {
		if (!panel(1, 0)) goto carkoon;
	} else {
		if (!atrb(Saber)) //double jump slam into room 3
			goto carkoon;
	}

	add(6); //leia
	if (!panel(2, 1) && !atrb(Bounty)) goto carkoon;
	if (!panel(2, 0)) goto carkoon;

showdown:
	mix(Showdown);

	if (!Multi(Lever, 2)) goto showdown;
	if (Multi(Jedi, 2)) goto endor;
	if (atrb(Jedi) && All(Grapple | SlightlyHigherJump)) goto endor;

	if (logicType != casual) {
		if (Multi(Box, 2) && atrb(DoubleJump)) { //need both to ride speeders
			if (atrb(Jedi) || atrb(Fett)) goto endor;
		}
	}
	goto showdown;

endor:
	mix(Endor);
	add(2);
	add(3);
	add(4);
	add(5);
	if (!atrb(Lever)) goto endor;
	if (!atrb(Box)) goto endor;
	if (!atrb(Build)) goto endor;
	if (logicType == casual) {
		if (!panel(0, 0)) goto endor;
		if (!panel(1, 0)) goto endor;
		if (!panel(2, 0)) goto endor;

		addHat(0, 0);
		if (!panel(3, 0)) goto endor;
		if (!panel(3, 1)) goto endor;
		if (!panelAny(3, 2, Fly)) goto endor;
		if (!panel(3, 3)) goto endor;

		if (!atrb(Hatch)) goto endor;
		if (!atrb(Grapple)) goto endor;
		if (!Multi(Grapple | DoubleJump | Hatch, 4)) //left side
			goto endor;
	} else {
		if (logicType != superGlitched) {
			if (!panel(2, 0)) goto endor;
		}

		addHat(0, 0);
		if (!panel(3, 0)) goto endor;
		if (!panel(3, 1)) goto endor;
		if (!panel(3, 3)) goto endor;

		if (atrb(DoubleJump)) //12 button skip
			goto destiny;
		if (panel(1, 0) && atrb(Hatch) && Multi(Grapple | Hatch, 4)) //left side
			goto destiny;
		goto endor;
	}

destiny:
	mix(Destiny);
	if (logicType == casual) {
		if (!atrb(Sith)) goto destiny;
		if (!Multi(Jedi, 2)) goto destiny;
	} else {
		if (!atrb(Saber)) goto destiny;
	}

itds:
	mix(ITDS);
	if (!atrb(Shoot)) goto itds;
	//
	//podraceoriginal:
	//	mix(PodraceOriginal);

anakinsflight:
	mix(Anakinsflight);
	if (!atrb(Shoot)) goto anakinsflight;

anewhope:
	mix(ANewHope);
	if (logicType == casual) {
		if (!atrb(Attack) && !atrb(FakeShoot)) goto anewhope;
		add(2); //3po
		if (!panel(0, 0)) goto anewhope;
		if (!panel(0, 1)) goto anewhope;
		if (!panel(0, 2)) goto anewhope;
	} else {
		if (DoubleTransitionSkip()) goto bhm;
		if (atrb(Attack) || atrb(FakeShoot)) {
			add(2); //3po
			if (panel(0, 0) && panel(0, 1) && panel(0, 2)) goto bhm;
		}
		goto anewhope;
	}

bhm:
	mix(BHM);
	if (!character) goto cantinaX; //DELETE THIS

	//logR("BOUNTIES MIXED");
	//for (Playable* p : BHM->party) {
	//	logR(p->name + " player");
	//}
	//
	//for (Playable* p : BHM->bonusCharacters) {
	//	logR(p->name + " target");
	//}

	add(2);
	add(3);
	add(4);
	add(5);

	//check all bonus numbers
	if (BHM->bonusCharacters[0] == battledroid) goto bhm;
	if (BHM->bonusCharacters[0] == pkdroid) goto bhm;
	if (BHM->bonusCharacters[1] == battledroid) goto bhm;
	if (BHM->bonusCharacters[2] == battledroid) goto bhm;
	//if (BHM->bonusCharacters[8] == gungan) goto bhm;
	if (BHM->bonusCharacters[3] == geonosian) goto bhm;
	//if (BHM->bonusCharacters[10] == kaminodroid) goto bhm;
	if (BHM->bonusCharacters[5] == battledroid_security) goto bhm;
	if (BHM->bonusCharacters[6] == battledroid) goto bhm;
	if (BHM->bonusCharacters[6] == destroyer) goto bhm;
	if (BHM->bonusCharacters[7] == battledroid) goto bhm;
	if (BHM->bonusCharacters[7] == clone_ep3) goto bhm;
	if (BHM->bonusCharacters[7] == clone_ep3_sand) goto bhm;
	if (BHM->bonusCharacters[7] == clone_ep3_swamp) goto bhm;
	if (BHM->bonusCharacters[8] == clone_ep3) goto bhm;
	if (BHM->bonusCharacters[8] == clone_ep3_sand) goto bhm;
	if (BHM->bonusCharacters[8] == disguisedclone) goto bhm;
	if (BHM->bonusCharacters[9] == battledroid) goto bhm;
	if (BHM->bonusCharacters[10] == engineer) goto bhm;
	if (BHM->bonusCharacters[10] == rebelscum) goto bhm;
	if (BHM->bonusCharacters[11] == jawa) goto bhm;
	if (BHM->bonusCharacters[11] == sandtrooper) goto bhm;
	//if (BHM->bonusCharacters[12] == scoundrel) goto bhm;
	if (BHM->bonusCharacters[12] == sandtrooper) goto bhm;
	if (BHM->bonusCharacters[13] == mousedroid) goto bhm;
	if (BHM->bonusCharacters[13] == stormtrooper) goto bhm;
	if (BHM->bonusCharacters[13] == imperialofficer) goto bhm;
	if (BHM->bonusCharacters[14] == snowtrooper) goto bhm;
	if (BHM->bonusCharacters[15] == ewok) goto bhm;
	//if (BHM->bonusCharacters[16] == civillian) goto bhm;
	if (BHM->bonusCharacters[16] == stormtrooper) goto bhm;
	//if (BHM->bonusCharacters[17] == civillian) goto bhm;
	if (BHM->bonusCharacters[17] == stormtrooper) goto bhm;
	if (BHM->bonusCharacters[18] == sandtrooper) goto bhm;
	if (BHM->bonusCharacters[19] == snowtrooper) goto bhm;

	//why was this here?
	//if (!atrb(HighDoubleJump))
	//	goto bhm;
	if (!bhPanel(Negotiations, 0, 1)) goto bhm;
	if (!bhPanel(Factory, 3, 2)) goto bhm;
	if (!bhPanel(JediBattle, 0, 1)) goto bhm;
	if (!bhPanel(SecretPlans, 1, 1) && !bhPanel(SecretPlans, 1, 2)) goto bhm;
	if (!bhPanel(Jundland, 0, 2)) goto bhm;
	if (!bhPanel(Jundland, 0, 4)) goto bhm;
	if (!bhPanel(EchoBase, 2, 0)) goto bhm;

	//bounty or yodajump

	if (logicType == casual) {
		if (!atrb(Gas)) goto bhm;
		if (!atrb(Fly)) goto bhm;
		if (!bhPanel(Bespin, 1, 1)) goto bhm;

		if (bhPanel(Bespin, 0, 0)) addHat(0, 0, Bespin);
		if (!bhPanel(Bespin, 0, 1)) goto bhm;
		if (!bhPanel(Bespin, 0, 2)) goto bhm;
		addHat(0, 1, Bespin);
		if (!bhPanel(Bespin, 0, 6)) goto bhm;

		availableHats.clear();

	} else {

		if (bhPanel(Bespin, 0, 0)) addHat(0, 0, Bespin);
		if (bhPanel(Bespin, 0, 1)) goto bhm7;
		if (bhPanel(Bespin, 0, 5)) {
			if (atrb(DoubleJump)) goto bhm7;
			for (Playable* p : testing) {
				if (p->check(Jump) && p->speed >= 1.199) goto bhm7;
			}
		}
		addHat(0, 1, Bespin);
		if (bhPanel(Bespin, 0, 6)) goto bhm7;

		goto bhm;

	bhm7:
		availableHats.clear();

		if (!atrb(Gas | Fly)) goto bhm;
		if (!atrb(Fly) && !All(HighJump | RealDoubleJump)) goto bhm;
	}
	if (!atrb(Bounty)) goto bhm;

	if (!atrb(Build)) goto bhm;
	if (!atrb(Lever)) goto bhm;
	if (!atrb(Fett) && !All(Grapple | DoubleJump)) goto bhm;

	//ghost cannot be captured
	if (atrb(Ghost, BHM->bonusCharacters)) goto bhm;

cantinaX:
	mix(Cantina);

	for (Level* lev : allLevels) {
		if (!lev->fakeLevel)
			for (Playable* p : lev->party) {
				//p->storyMode = true;
				p->StoryMode = true;
			}
	}
	if (character) {
#ifdef _DEBUG
		logR("Cantina");
#endif

		std::uniform_int_distribution<int> randPlayable(0, pls.size() - 1);
		std::uniform_int_distribution<int> randCharacters(0, chs.size() - 1);

	cantina:
		cantina1 = chs[randCharacters(rando)];
		cantina2 = chs[randCharacters(rando)];
		if (cantina1 == cantina2) goto cantina;

	indy:
		indy = pls[randPlayable(rando)];
		if (indy->StoryMode) goto indy;

	allMinikits:
		allMinikitsCharacter = pls[randPlayable(rando)];
		if (allMinikitsCharacter->StoryMode) goto allMinikits;
	}

	//if (enemyOp && 1) {
	//	for (Level* lev : allLevels) {
	//		for (NestedEnemySet& nestSet : lev->enemies.nestedEns) {
	//			for (NestedEnemy& nest : nestSet.nEns) {
	//				if (std::find(lev->enemies.enemyTypes.begin(), lev->enemies.enemyTypes.end(), nest.newEn) ==
	//					lev->enemies.enemyTypes.end()) {
	//					lev->enemies.enemyTypes.push_back(nest.newEn);
	//				}
	//			}
	//		}
	//		for (EnemySet& enSet : lev->enemies.enemies) {
	//			for (Enemy& en : enSet.enemy) {
	//				if (std::find(lev->enemies.enemyTypes.begin(), lev->enemies.enemyTypes.end(), en.newEn) ==
	//					lev->enemies.enemyTypes.end()) {
	//					lev->enemies.enemyTypes.push_back(en.newEn);
	//				}
	//			}
	//		}
	//		for (SpecialScp& sp : lev->enemies.specialscp) {
	//			for (Enemy& spEn : sp.specialEnemies) {
	//				if (std::find(lev->enemies.enemyTypes.begin(), lev->enemies.enemyTypes.end(), spEn.newEn) ==
	//					lev->enemies.enemyTypes.end()) {
	//					lev->enemies.enemyTypes.push_back(spEn.newEn);
	//				}
	//				if (std::find(sp.spEnemyTypes.begin(), sp.spEnemyTypes.end(), spEn.newEn) ==
	//					sp.spEnemyTypes.end()) {
	//					sp.spEnemyTypes.push_back(spEn.newEn);
	//				}
	//				if (std::find(sp.spEnemyTypes.begin(), sp.spEnemyTypes.end(), spEn.newEn) ==
	//					sp.spEnemyTypes.end()) {
	//					sp.spEnemyTypes.push_back(spEn.newEn);
	//				}
	//			}
	//			for (DoubleNestedEnemy& dne : sp.dNestEn) {
	//				if (std::find(lev->enemies.enemyTypes.begin(), lev->enemies.enemyTypes.end(), dne.newEn) ==
	//					lev->enemies.enemyTypes.end()) {
	//					lev->enemies.enemyTypes.push_back(dne.newEn);
	//				}
	//			}
	//		}
	//	}
	//}
	cantina1->StoryMode = true;
	cantina2->StoryMode = true;
	indy->StoryMode = true;

	//regexTest(getSCP(Princess, 'B', "BRIDGE_TROOPS"), "state shootatobiwan((?:(?!state)[\\s\\S])+?)FollowPlayer
	//\"run\"", "state shootatobiwan$1FollowCharacter \"character=" + Princess->party[5]->name + "\" \"run\""); return;

	//FILE GEN IS HERE
	fileGen();
	//FILE GEN IS HERE
	//system("cls");

	std::cout << "Cutscenes removed\n";
	//TESTING THIS

	{
		//Diverts references for nonexistent characters to dummy character so I can
		//use override said characters.
		int addresses[] = {0x4f13, 0x4f33, 0x4fc6, 0x1a7af, 0x29322, 0x895e9, 0xca382, 0x1de5f, 0x31774, 0x8727a,
			0x317a2, 0x317b2, 0x1f29f, 0x2d314, 0x400a6, 0x400c2, 0x400c9, 0x400e5, 0x4005c, 0x40078, 0x400ec, 0x40108,
			0x4007f, 0x317c2, 0xb57e5, 0x87288, 0xa91ca, 0x1e3e2, 0x1e3eb, 0xa91d7, 0x40039, 0x40055};

		for (int address : addresses)
			binaryWrite(EXE, "b8177f", address);
	}

	std::cout << "Dummy characters done\n";

	if (enemyOp) {
		for (Level* lev : allLevels) {
			std::string appendix;
			for (EnemySet& enset : lev->enemies) {
				for (Enemy& en : enset.enemy) {
					if (en.address != 0) {
						hexWrite(getAI2(lev, enset.scene), en.newType->type->name, en.address);

						std::string scrip;
						std::fstream fs(getAI2(lev, enset.scene), std::ios::binary | std::ios::in | std::ios::out);
						fs.seekg(en.address - 0x10);
						char c = fs.get();
						while (c != '\0') {
							scrip += c;
							c = fs.get();
						}
						fs.close();
						std::string temp;
						if (CIcompare(scrip, "chatting") /* || CIcompare(scrip, "storm")*/) {
							if (en.newType == gamorreanguard_en) temp = "gamorreanguard";
							else if (en.newType == imperialguard_en) temp = "impguard";
							else if (en.newType == bodyguard_en) temp = "impguard";
						}
						if (temp != "") hexWrite(getAI2(lev, enset.scene), temp, en.address - 0x10);
					}
					if (en.file != "") {
						txtIns(getSCP(lev, enset.scene, en.file), en.newType->type->name, {en.lncol},
							en.vanillaType->type->name.length());
					}
					if (appendix.find('\"' + en.newType->type->name + '\"') == std::string::npos) {
						appendix += "character \"" + en.newType->type->name + "\" resident\n";
					}
				}

				//PUT THIS BACK IN
				//lineDeleter(getMainTxt(lev), lev->enemyLines);
				appendFile(getMainTxt(lev), appendix);
			}
		}
	}

	//	if (enemyOp && 1) {
	//
	//		////I want these scripts accessable from the entire game.
	//		std::filesystem::rename(getSCP(Chancellor, 'F', "BODYGUARD"), SCR + "BODYGUARD.SCP");
	//		std::filesystem::rename(getSCP(Destiny, 'A', "IMPGUARD"), SCR + "IMPGUARD.SCP");
	//		//std::filesystem::copy("files/trainingremote.scp", SCR + "trainingremote.scp");
	//		appendFile(SCR + "SCRIPT.TXT", "\nimpguard\nbodyguard\ntrainingremote");
	//
	//		//fixScript(
	//		//    "Fight", enemies, normalAttack, "if GotOpponent == 0 goto Approach", {45, 1}, SCR + "STORM.SCP");
	//
	//		for (Level* lev : allLevels) {
	//            std::cout << lev->name << std::endl;
	//			std::string tf = getMainTxt(lev);
	//			lineDeleter(tf, lev->enemies.enemyRes);
	//
	//			for (Playable* p : lev->enemies.enemyTypes) {
	//				appendFile(tf, "character \"" + p->name + "\" resident");
	//			}
	//			for (EnemySet& enSet : lev->enemies.enemies) {
	//				for (Enemy& en : enSet.enemy) {
	//
	//					if (en.enemywhere == ai2) {
	//						hexWrite(getAI2(lev, enSet.scene), en.newEn->name, en.address);
	//						if (en.scpFile != NONE) {
	//							hexWrite(
	//								getAI2(lev, enSet.scene), en.newEn->enemyChart[en.scpFile], en.address - 0x10,
	//0x10);
	//						}
	//						//if (SpecialScripts.find(en.newEn) != std::string::npos) {
	//						//	hexWrite(getAI2(lev, enSet.scene), SpecialScripts[en.newEn],
	//						//	    en.address - 0x10);
	//						//}
	//					}
	//				}
	//			}
	//			for (NestedEnemySet nestSet : lev->enemies.nestedEns) {
	//				for (NestedEnemy nest : nestSet.nEns) {
	//					std::cout << lev->name.c_str() << ' ' << nestSet.scene << ' ' << nestSet.fileName << ' '
	//							  << nest.type << std::endl;
	//					if (nest.scpType != NONE) {
	//						txtIns(getSCP(lev, nestSet.scene, nestSet.fileName),
	//nest.newEn->enemyChart[nest.scpType], 							{nest.script}, nest.scpLen);
	//					}
	//					txtIns(getSCP(lev, nestSet.scene, nestSet.fileName), nest.newEn->name, {nest.type},
	//						nest.oldEn->name.length());
	//					if (nest.chainAdd > -1) {
	//						std::vector<Playable*>& spTemp = lev->enemies.specialscp[nest.chainAdd].spEnemyTypes;
	//						if (std::find(spTemp.begin(), spTemp.end(), nest.newEn) == spTemp.end()) {
	//							spTemp.push_back(nest.newEn);
	//						}
	//					}
	//				}
	//			}
	//			for (SpecialScp& sp : lev->enemies.specialscp) {
	//                std::cout << '\t' << sp.fileName << std::endl;
	//				for (Enemy& spEn : sp.specialEnemies) {
	//
	//					hexWrite(getAI2(lev, sp.scene), spEn.newEn->name, spEn.address);
	//				}
	//				//if (sp.redirect) {
	//				//fixScript(sp.oldFunName, sp.spEnemyTypes, sp.attackPattern, sp.extraConditions,
	//				//sp.lnCol, getSCP(lev, sp.scene, sp.fileName));
	//				/*} else */
	//				for (DoubleNestedEnemy& dne : sp.dNestEn) {
	//					if (sp.useAltScript && SpecialScripts.find(dne.newEn) != std::string::npos) {
	//						//std::cout << dne.type.ln << ',' << dne.type.col << ' ' << dne.newEn->name << ' ' <<
	//						//dne.fileName
	//						//		  << ' ' << dne.script.ln << ',' << dne.script.col << ' ' << dne.oldEn <<
	//std::endl; 						txtIns(getSCP(lev, sp.scene, dne.fileName), SpecialScripts[dne.newEn],
	//{dne.script}, 							dne.fileName.length());
	//					}
	//					txtIns(getSCP(lev, sp.scene, dne.fileName), dne.newEn->name, {dne.type},
	//dne.oldEn->name.length()); 					if (std::find(sp.spEnemyTypes.begin(), sp.spEnemyTypes.end(),
	//dne.newEn)
	//== sp.spEnemyTypes.end()) { 						sp.spEnemyTypes.push_back(dne.newEn);
	//					}
	//				}
	//
	//				if (sp.newWay) {
	//					//for (NestedEnemy nest : sp.nestedSource.nEns) {
	//					//	//scpRep(sp.nestedSource.scene, sp.nestedSource.fileName,
	//					//	//	nest.newEn->name, nest.oldEn->name.length(), nest.type);
	//					//	if (nest.scpType != NONE) {
	//					//		txtIns(getSCP(lev, sp.nestedSource.scene,
	//					//			       sp.nestedSource.fileName),
	//					//			nest.newEn->enemyChart[nest.scpType], {nest.script},
	//					//			nest.scpLen);
	//					//		//scpRep(sp.nestedSource.scene, sp.nestedSource.fileName,
	//					//		//	nest.newEn->enemyChart[nest.scpType], nest.scpLen,
	//					//		//	nest.script);
	//					//	}
	//					//	txtIns(getSCP(lev, sp.nestedSource.scene, sp.nestedSource.fileName),
	//					//		nest.newEn->name, {nest.type}, nest.oldEn->name.length());
	//					//
	//					//	if (nest.chainAdd > -1) {
	//					//		lev->specialscp[nest.chainAdd].spEnemyTypes.push_back(
	//					//			nest.newEn);
	//					//	}
	//					//}
	//
	//					std::string tf = getSCP(lev, sp.scene, sp.fileName);
	//
	//					for (int j = sp.overwriters.size() - 1; j >= 0; j--) {
	//#define overwrite sp.overwriters[j]
	//						std::string redirect;
	//						std::string ending;
	//						for (int i = 0; i < sp.spEnemyTypes.size(); i++) {
	//							if (!(sp.useAltScript && !SpecialScripts.find(sp.spEnemyTypes[i]) != std::string::npos))
	//{ 								if (SpecialScripts.find(sp.spEnemyTypes[i]) != std::string::npos) { 									redirect += "\t\tif iAm \"" +
	//sp.spEnemyTypes[i]->name + "\" == 1 goto " + 												overwrite.oldFunName + std::to_string(i) + "\n";
	//
	//									ending += "state " + overwrite.oldFunName + std::to_string(i) + " {\n";
	//									ending += "\tReferenceScript {\n"
	//											  "\t\tScript=";
	//
	//									ending += SpecialScripts[sp.spEnemyTypes[i]];
	//
	//									ending += "\n\t\tSource=Global\n"
	//											  "\t\tReturnState=" +
	//											  overwrite.oldFunName + std::to_string(i) +
	//											  "\n"
	//											  "\t\tConditions {\n"
	//											  "\t\t}\n"
	//											  "\t}\n";
	//									ending += "\tConditions {\n"
	//											  "\t\t" +
	//											  //spEnemyTypes[i]->conditions + "\n\t\t" +
	//											  overwrite.extraConditions +
	//											  "\n\t}\n"
	//											  "\tActions {\n"
	//											  "\t\t" +
	//											  overwrite.extraActions +
	//											  //sp.spEnemyTypes[i]->nAttackInfo.actions +
	//											  "\n\t}\n"
	//											  "}\n";
	//								}
	//							}
	//						}
	//						txtIns(tf, redirect, {{overwrite.ln, 1}}, 0);
	//						appendFile(tf, ending);
	//					}
	//
	//				} else {
	//					redirrector(lev, sp);
	//				}
	//			}
	//		}
	//	}

	if (panelOp) {
		for (Level* lev : allLevels) {
			for (PanelSet& panSet : lev->panels) {
				for (Panel& pan : panSet.panels) {
					binaryWrite(getBasePath(lev, panSet.scene, "GIZ"), pan.type, pan.address);
					if (pan.type == AstroPanel || pan.type == ProtoPanel) {
						binaryWrite(getBasePath(lev, panSet.scene, "GIZ"), pan.altColor, pan.address + 19);
						binaryWrite(getBasePath(lev, panSet.scene, "GIZ"), pan.altBody, pan.address + 20);
					}
				}
			}
		}

		//Makes the actual panel visible once you build
		//it since I could not figure out how to replace
		//the icon on the fake one.
		txtIns(getBasePath(Princess, 'A', "GIT"), "\t\tStartInvisible\n", {439});
		binaryWrite(getBasePath(Princess, 'A', "GIZ"), "00", 0x3035);
	}

	if (hatOp) {
		for (Level* lev : allLevels) {
			for (DispenserSet& dispSet : lev->dispensers) {
				for (Dispenser& disp : dispSet.dispenser) {
					binaryWrite(getBasePath(lev, dispSet.scene, "GIZ"), disp.type, disp.address);
				}
			}
		}
	}

	if (collectable) {
#ifdef _DEBUG
		logR("Starting collectables");
#endif

		for (int i = 0; i < 36; ++i) {
			int challengeNum = 1;

			for (Collectable& collect : allLevels[i]->collectables) {

#ifdef _DEBUG
				logR((allLevels[i]->name + " collectables").c_str());
#endif
				std::string file = getBasePath(allLevels[i], collect.scene, "GIZ");
				std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);

				for (std::pair<char, int> mk : collect.typeAddress) {

					fs.seekg(mk.second);
					char type = fs.get();
#ifdef _DEBUG
					if (type != 'c' && type != 'm' && type != 'r') {
						std::stringstream st;
						st << std::hex << mk.first;
						logR(st.str() + " " + file +
							 " is not a "
							 "collectabl"
							 "e.\n");
					}
#endif
					if (type == 'c') {
						//some challenge
						//kits have the
						//same name,
						//which breaks
						//when changed
						//to minikits
						hexWrite(file, "c_pup" + std::to_string(challengeNum), mk.second - 0x14);
						++challengeNum;
					}

					binaryWrite(file, mk.first, mk.second);
				}
			}

			for (SpecialCollectable& collect : allLevels[i]->specialCollectables) {

#ifdef _DEBUG
				logR((allLevels[i]->name + " special collectables").c_str());
#endif
				for (std::pair<char, int> special : collect.sceneAddress) {

					std::string file = getBasePath(allLevels[i], special.first, "GIZ");
					std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);

					fs.seekg(special.second);
					char type = fs.get();
#ifdef _DEBUG
					if (type != 'c' && type != 'm' && type != 'r') {
						std::stringstream st;
						st << std::hex << collect.type;
						logR(st.str() + " " + file +
							 " is not a "
							 "collectabl"
							 "e.\n");
					}
#endif
					if (type == 'c') {
						//some challenge
						//kits have the
						//same name,
						//which breaks
						//when changed
						//to minikits
						hexWrite(file, "c_pup" + std::to_string(challengeNum), special.second - 0x14);
						++challengeNum;
					}

					binaryWrite(file, collect.type, special.second);
				}
			}
		}

		//fixes camera pan in challenge
		lineDeleter(getBasePath(SecretPlans, 'B', "GIT"), {1830});
		//allows spinners to work in challenge mode
		lineDeleter(getBasePath(Coruscant, 'A', "GIT"), {274, 302, 330, 358, 386, 414, 442, 470, 498, 526});
		//allows carrot camerapan to work in challenge
		//mode
		lineDeleter(getBasePath(Kashyyyk, 'B', "GIT"), {170});
	}

	std::cout << "Collectables patched\n";
	if (extra) {
#ifdef _DEBUG
		logR("Starting extras");

#endif
		unsigned int lines[] = {39, 57, 75, 88, 128, 144, 195, 214, 233, 246, 259, 286, 332, 351, 363, 377, 392, 406,
			468, 485, 505, 523, 540, 562, 615, 632, 652, 669, 684, 700, 749, 764, 777, 793, 806, 829};

		std::vector<writeSet> ex;
		for (unsigned int i = 0; i < extras.size(); i++) {
			ex.push_back({extras[i], static_cast<unsigned int>(vanillaExtras[i].length()), {{lines[i], 18}}});
		}

		batchAnywhere(LEV + "AREAS.TXT", ex);
	}

	//Patches levels with new characters
	if (character) {
#ifdef _DEBUG
		logR("Patching Levels");

#endif

		//pointerWrite(EXE, cantina1->name, 0x3f1c30);
		//pointerWrite(EXE, cantina2->name, 0x3f1c38);

#define bonusCharacter &Level::bonusCharacters

		characterPointer(cantina1, 0xca35a);
		characterPointer(cantina2, 0xca360);

		//std::remove("cantina.txt");
		//std::ofstream can("cantina.txt", std::ios_base::out);
		//can << cantina1->name << std::endl;
		//can << cantina2->name << std::endl;
		//can.close();

		//Removes name length limit for creature spawns
		//(this took forever to fix) binaryWrite(EXE,
		//"dc", 0x113402); binaryWrite(EXE, "d8",
		//0x113410); binaryWrite(EXE, "e4", 0x113418);
		//binaryWrite(EXE, "20", 0x113420);
		//binaryWrite(EXE, "28", 0x11342d);
		//binaryWrite(EXE, "20", 0x11345a);
		//binaryWrite(EXE, "e0", 0x113510);

		currentLev = Negotiations;
		playerInit({{0, 1}, {1, 2}, {2, 3}});
		//playerInit(0, 1);
		//playerInit(1, 2);
		//playerInit(2, 3); //tc

		scpIns('A', "LEVEL", 2, {18, 22});
		scpMulti('A', "LEVEL1", {2, {{17, 22}, {21, 22}, {40, 22}}});

		//stops tc from going to panel
		scpRep('A', "TC14", "alwaystrue", 26, {35, 6});
		lineDeleterScp('A', "TC14", {39});

		scriptTxtRep('A', "ai_pk", "PKDROID", 4);
		ai2Write('A', "ai_pk", {0x4400, 0x44B5});
		scriptTxtRep('C', "ai_pk", "PKDROID", 6);
		ai2Write('C', "ai_pk", {0x3846});

		scriptTxt('A', 2, 5);

		currentLev = Invasion;
		playerInit({{0, 1}, {1, 2}, {2, 3}});

		scriptTxtRep('A', "ai_bdroid", "BATTLEDROID", 4);
		ai2Write('A', "ai_bdroid", {});
		scriptTxtRep('E', "ai_bdroid", "BATTLEDROID", 1);
		ai2Write('E', "ai_bdroid", {0x854, 0x909, 0x9BE, 0xA73, 0xB28});

		scriptTxt('A', 2, 2);
		fileDeleter('B', 2);

		currentLev = EscapeNaboo;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}});

		//TCS->checks if character is Jedi instead of who
		//character is
		scpRep('A', "PARTY",
			"if IAm \"" + EscapeNaboo->party[0]->name +
				"\" == 1 goto Activate\n"
				"\t\tif IAm \"" +
				EscapeNaboo->party[1]->name + "\" == 1 goto Activate",
			39, {5, 3});

		scpRep('B', "PARTY",
			"if IAm \"" + EscapeNaboo->party[0]->name +
				"\" == 1 goto Activate\n"
				"\t\tif IAm \"" +
				EscapeNaboo->party[1]->name + "\" == 1 goto Activate",
			39, {5, 3});

		scpIns('B', "LEVEL", 2, {17, 26});
		scpIns('B', "LEVEL", 3, {16, 26});
		scpIns('C', "LEVEL", 2, {26, 28});
		scpIns('C', "LEVEL", 3, {25, 28});

		currentLev = Podrace;
		playerInit({{0, 1}, {1, 2}});
		//fixes scaling problem
		binaryWrite(EXE, "0f", 0xB5129);
		binaryWrite(EXE, "0f", 0x35946);

		currentLev = Theed;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}});
		//scpMulti('A', "LEVEL", {2, {{20, 25}, {21,
		//28}}});

		scpMany('A', "LEVEL",
			{{2, {{20, 25}, {21, 28}}}, {3, {{18, 25}, {19, 28}}}, {4, {{24, 25}, {25, 28}}},
				{5, {{22, 25}, {23, 28}}}});

		currentLev = Maul;
		playerInit({{0, 1}, {1, 2}});
		scpIns('F', "DARTHMAUL", 0, {381, 21});

		//fixes ditto problem
		scriptTxtRep('A', "dmaul", "DARTHMAUL", 1);
		scriptTxtRep('D', "dmaul", "DARTHMAUL", 1);
		scriptTxtRep('E', "dmaul", "DARTHMAUL", 2);
		scriptTxtRep('F', "dmaul", "DARTHMAUL", 2);

		ai2Write('A', "dmaul", {0x26ae});
		ai2Write('D', "dmaul", {0x307B});
		ai2Write('E', "dmaul", {0x6F9});
		ai2Write('F', "dmaul", {0x96B});

		currentLev = BHP;
		playerInit({{0, 1}, {1, 2}});

		currentLev = Kamino;
		playerInit({{0, 1}, {1, 2}});
		scpMany('C', "LEVEL",
			{
				{0, {{47, 28}, {83, 28}}},
				{1, {{48, 28}, {84, 28}}},
			});

		//ditto
		scriptTxtRep('A', "ai_taunwe", "TAUNWE", 3);
		ai2Write('A', "ai_taunwe", {0x1439});
		scriptTxtRep('C', "ai_taunwe", "TAUNWE", 2);
		ai2Write('C', "ai_taunwe", {0x1B9F});
		scriptTxtRep('D', "ai_taunwe", "TAUNWE", 1);
		ai2Write('D', "ai_taunwe", {0x2BAE});

		scriptTxtRep('C', "ai_jango", "JANGOFETT", 1);
		ai2Write('C', "ai_jango", {0x1afa});

		currentLev = Factory;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 10, bonusCharacter}});

		scpRep('D', "PARTY", "if CategoryIs \"Astromech\" == 1", 18, {12, 3});
		scpRep('E', "PARTY", "if CategoryIs \"Astromech\" == 1", 18, {12, 3});

		//Do not delete this yet.
		//if (!Proto({ Factory->party[3] }))
		//Factory->replace("1", 3, { {34, 17} }, 'E',
		//"C3PO.SCP"); Factory->replace("\t\tif
		//CategoryIs \"Protocol\" == 1 goto
		//ProtoUpdate\n", 0, { {12, 1} }, 'E',
		//"PARTY.SCP"); Factory->append( "state
		//ProtoUpdate <openbrace>\n"
		//				"\tConditions
		//{\n"
		//				"\t}\n"
		//				"\tActions {\n"
		//				"\t\tFollowPlayer
		//\"0.5\"\n"
		//				"\t}\n"
		//				"}",

		//				'E',
		//"PARTY.SCP");

		scpRep('F', "PARTY", "if CategoryIs \"noweapon\" == 1", 18, {13, 3});

		lineDeleterScp('F', "PARTY", {14});

		ai2Write('G', 0, {0x972}, bonusCharacter);
		characterPointer(Factory->party[0], 0xE010F);

		multiScriptTxt('A', {{2, 2}, {3, 3}});
		multiScriptTxt('B', {{2, 2}, {3, 3}});
		/*scpName('A', 2);
		scpName('A', 3);
		scpName('B', 2);
		scpName('B', 3);*/

		scriptTxt('D', 3, 1);
		scriptTxt('E', 3, 2);
		//Makes sure protocol droid follows you onto the
		//turn things
		/*{
						int turn =
		GetType(3, Proto, Factory->party);
						Factory->rename(turn,
		'E');

		}*/

		////these two don't follow
		//auto uLength = [](int ch, int address) {
		//	std::string name =
		//Factory->party[ch]->name; 	char c =
		//name.length() + 1;
		//	//binaryWrite(Factory->directory('E',
		//"FACTORY_E.AI2"), c, address - 1);
		//	std::fstream fs(getAI2(Factory, 'E'),
		//		std::ios::in | std::ios::out);
		//	fs.seekp(address - 1);
		//	fs << c;

		//	fs.seekp(address);
		//	//fs.write(name.c_str(), name.length());
		//	 int i = 0;
		//	while (i < name.length()) {
		//		fs.seekp(address + i);
		//		fs << char(name[i]);

		//		i++;
		//	}
		//	fs.seekp(address + 1);
		//	fs << '\0';
		//};
		//uLength(1, 0x181a);
		//uLength(2, 0x143d);

		//Factory->binWrite(1, { 0x181A }, 'E',
		//"FACTORY_E.AI2"); Factory->binWrite(2, {
		//0x143D }, 'E', "FACTORY_E.AI2");
		currentLev = JediBattle;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {2, 8}, {3, 9}, {4, 10}}); //so they still spawn in FP

		scpMany('B', "PARTY", {{2, {{15, 11}, {31, 11}}}, {3, {{11, 11}, {26, 11}}}, {4, {{7, 11}, {21, 11}}}});
		scpIns('B', "LEVEL", 4, {7, 45});

		multiPointer(JediBattle->party[2], {0xDFABF, 0x3fffa4});
		multiPointer(JediBattle->party[3], {0xDFAAB, 0x3fffa0});
		multiPointer(JediBattle->party[4], {0xDFA98, 0x3fff9c});
		//fixes green saber
		//binaryWrite(EXE, 0x0f, 0x190E6);

		currentLev = Gunship;
		playerInit({{0, 1}, {1, 2}});

		currentLev = Dooku;
		playerInit({{0, 1}, {1, 2}, {2, 3}});
		scpMany('C', "DOOKU", {{0, {{209, 45}}}, {1, {{207, 26}, {214, 29}}}, {2, {{208, 43}}}}); //Yoda
		scpIns('C', "PARTY", 2, {6, 11});
		scpIns('B', "PARTY", 2, {18, 11});

		currentLev = Coruscant;
		playerInit({{0, 1}, {1, 2}});

		currentLev = Chancellor;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}});

		scpMany('C', "DOOKU", {{0, {{29, 28}}}, {1, {{28, 28}}}});
		scpIns('B', "R2D2", 2, {38, 74});

		//tall room AI is stupid
		/*if (!Chancellor->party[2]->astro) {
			scpRep('B', "R2D2", "ReferenceScript", 16, {1, 1});
		}*/

		//std::ofstream party(Chancellor->directory('B',
		//"PARTY.SCP"));
		std::ofstream party(getSCP(Chancellor, 'B', "PARTY"));
		party << "state Base {\n"
			  << "\tConditions {\n"
			  << "\t\tif FreePlay == 1 goto "
				 "NormalUpdate\n"
			  << "\t\tif CategoryIs \"Astromech\" == 1 "
				 "goto PanelUpdate\n"
			  << "\t\tif AlwaysTrue == 1 goto "
				 "NormalUpdate\n"
			  << "\t}\n"
			  << "\tActions {\n"
			  << "\t}\n"
			  << "}\n"
			  << "state NormalUpdate {\n"
			  << "\tReferenceScript {\n"
			  << "\t\tScript=GeneralParty\n"
			  << "\t\tSource=Global\n"
			  << "\t\tReturnState=NormalUpdate\n"
			  << "\t\tConditions {\n"
			  << "\t\t}\n"
			  << "\t}\n"
			  << "\tConditions{\n"
			  << "\t}\n"
			  << "\tActions {\n"
			  << "\t}\n"
			  << "}\n"
			  << "state PanelUpdate {\n"
			  << "\tConditions{\n"
			  << "\t}\n"
			  << "\tActions {\n"
			  << "\t\tFollowPlayer \"1\"\n"
			  << "\t}\n"
			  << "}\n";

		scriptTxtAppend('B', "party");

		scpMulti('D', "PARTY", {"if Freeplay == 1 and\n", 0, {{22, 3}, {23, 3}}}); //test

		scriptTxtRep('A', "ai_griev", "GRIEVOUS", 3);
		ai2Write('A', "ai_griev", {0x8F7});

		if (!enemyOp) {
			scriptTxtRep('F', "ai_guard", "BODYGUARD", 1);
			ai2Write('F', "ai_guard", {0x111E, 0x11D3});
		}

		multiScriptTxt('A', {
								{2, 1},
								{3, 4},
							});
		multiScriptTxt('B', {
								{2, 1},
								{3, 4},
							});
		multiScriptTxt('C', {
								{2, 2},
								{3, 4},
							});
		multiScriptTxt('G', {
								{2, 2},
								{3, 3},
							});

		currentLev = Grievous;
		playerInit({{0, 1}, {1, 2}});
		//fixes ditto problem
		scriptTxtRep('A', "ai_griev", "GRIEVOUS", 3);
		ai2Write('A', "ai_griev", {0x472d});

		currentLev = Kashyyyk;
		playerInit({{0, 1}, {1, 2}});
		scpMany('A', "LEVEL", {{0, {{44, 28}}}, {1, {{45, 28}}}});

		scriptTxtRep('A', "ai_wookiee", "WOOKIE", 4);
		ai2Write('A', "ai_wookiee", {});

		currentLev = Ruin;
		playerInit({{0, 1}, {1, 2}});

		currentLev = Vader;
		playerInit({{0, 1}, {1, 2}});
		lineDeleterScp('B', "PARTY", {37});

		currentLev = SecretPlans;
		playerInit({{0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}});

		scpMany('A', "PARTY",
			{{0, {{23, 11}}}, {1, {{26, 11}}}, {2, {{29, 11}, {14, 11}}}, {3, {{17, 11}}}, {4, {{20, 11}}}});
		scpMany('B', "PARTY",
			{{0, {{23, 11}}}, {1, {{26, 11}}}, {2, {{29, 11}, {14, 11}}}, {3, {{17, 11}}}, {4, {{20, 11}}}});
		scpMany('C', "PARTY", {{0, {{7, 11}, {10, 11}}}, {2, {{34, 11}}}, {3, {{28, 11}, {53, 11}}}, {4, {{31, 11}}}});
		scpMany('D', "PARTY", {{0, {{38, 26}}}, {1, {{8, 11}}}, {2, {{9, 11}}}, {3, {{6, 11}}}, {4, {{7, 11}}}});

		scpMany('C', "LEVEL",
			{{0, {{53, 26}, {54, 25}}}, {3, {{21, 22}, {36, 27}, {37, 27}, {38, 29}}},
				{4, {{49, 27}, {50, 27}, {51, 29}}}});
		scpIns('C', "LIFT_TROOPER", 2, {34, 25});

		scriptTxtRep('D', "ai_beach", "BEACHTROOPER", 7);
		ai2Write('D', "ai_beach", {0x21FB, 0x22B0});

		currentLev = Jundland;
		playerInit({{0, 3}, {1, 4}, {2, 5}, {3, 6}});

		scpMany('A', "LEVEL", {{0, {{51, 23}}}, {1, {{52, 23}}}, {2, {{54, 26}}}, {3, {{55, 26}}}});

		scpMany('A', "PARTY", {{2, {{16, 11}}}, {3, {{17, 11}}}});
		scpMany('B', "PARTY", {{2, {{6, 11}}}, {3, {{9, 11}}}});
		scpMany('D', "PARTY", {{2, {{6, 11}, {9, 11}, {32, 11}}}, {3, {{7, 11}, {12, 11}, {35, 11}}}});

		scriptTxtRep('C', "ai_tusken", "TUSKENRAIDER", 3);
		ai2Write('C', "ai_tusken", {0x6885, 0x69DF, 0x6BEE, 0x6CA3, 0x6D58});

		currentLev = Spaceport;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}});

		scpMany('A', "PARTY",
			{{0, {{8, 11}}}, {1, {{11, 11}}}, {2, {{14, 11}}}, {3, {{17, 11}}}, {4, {{24, 11}}}, {5, {{21, 11}}}});
		scpMany('B', "PARTY",
			{{0, {{8, 11}}}, {1, {{11, 11}}}, {2, {{14, 11}}}, {3, {{17, 11}}}, {4, {{24, 11}}}, {5, {{21, 11}}}});
		scpMany('C', "PARTY",
			{{0, {{8, 11}}}, {1, {{11, 11}}}, {2, {{14, 11}}}, {3, {{17, 11}}}, {4, {{24, 11}}}, {5, {{21, 11}}}});

		scpMany('C', "LEVEL",
			{{0, {{100, 26}, {101, 25}}}, {1, {{103, 26}, {104, 25}}}, {2, {{106, 26}, {107, 25}}},
				{3, {{109, 26}, {110, 25}}}, {4, {{97, 23}, {98, 28}}}, {5, {{94, 23}, {95, 28}}}});

		scpMany('D', "LEVEL",
			{{0, {{26, 26}, {27, 27}, {28, 27}, {29, 28}, {30, 29}, {108, 26}, {109, 27}, {110, 27}, {111, 29}}},
				{1, {{32, 26}, {33, 27}, {34, 27}, {35, 28}, {36, 29}, {113, 26}, {114, 27}, {115, 27}, {116, 29}}},
				{2, {{38, 26}, {39, 27}, {40, 27}, {41, 28}, {42, 29}, {118, 26}, {119, 27}, {120, 27}, {121, 29}}},
				{3, {{44, 26}, {45, 27}, {46, 27}, {47, 28}, {48, 29}, {123, 26}, {124, 27}, {125, 27}, {126, 29}}}});

		scpMany('E', "LEVEL",
			{{0, {{16, 26}, {17, 27}, {18, 27}, {19, 26}}}, {1, {{21, 26}, {22, 27}, {23, 27}, {24, 26}}},
				{2, {{26, 26}, {27, 27}, {28, 27}, {29, 26}}}, {3, {{31, 26}, {32, 27}, {33, 27}, {34, 26}}}});

		currentLev = Princess;
		playerInit({{0, 17}, {1, 18}, {2, 19}, {3, 20}, {4, 21}, {5, 22}, {0, 25, bonusCharacter}});

		scpMany('A', "LEVEL", {{3, {{35, 26}, {36, 25}}}, {4, {{33, 26}, {34, 25}}}, {5, {{37, 26}, {38, 25}}}});
		scpMany('B', "LEVEL", {{3, {{24, 26}}}, {4, {{25, 26}}}, {5, {{26, 26}}}});

		ai2Write('B', 5, {0x6825});
		ai2Write('C', 0, {0x3A9F}, bonusCharacter);

		//TCS stupidly->checks weapon instead of
		//character
		scpRep('B', "LEVEL",
			"\t\tdeactivate \"character=" + Princess->party[3]->name + "\"\n" +
				"\t\tdeactivate \"character=" + Princess->party[4]->name + "\"\n", //+
			//"\t\tdeactivate\"character=" +
			//Princess->party[5]->name + "\"\n",
			0, {27, 1});

		scpRep('C', "LEVEL",
			"\t\tif FreePlay == 0 goto "
			"MakeSurePlayersNotDroids\n",
			0, {4, 1});

		scpAppend('C', "LEVEL",
			"state MakeSurePlayersNotDroids {\n"
			"\tConditions {\n"
			"\t}\n"
			"\tActions {\n"
			"\t\tdeactivate \"character=" +
				Princess->party[3]->name + "\"\n" + "\t\tdeactivate \"character=" + Princess->party[4]->name + "\"\n" +
				//"\t\tdeactivate \"character=" +
				//Princess->party[5]->name + "\"\n" +
				"\t}\n" + "}");

		std::ofstream os(getSCP(Princess, 'D', "LEVEL"));
		os << "state Base {\n"
		   << "\tConditions {\n"
		   << "\t\tif FreePlay == 0 goto "
			  "MakeSurePlayersNotDroids\n"
		   << "\t}\n"
		   << "\tActions {\n"
		   << "\t}\n"
		   << "}\n"
		   << "state MakeSurePlayersNotDroids {\n"
		   << "\tConditions {\n"
		   << "\t}\n"
		   << "\tActions {\n"
		   << "\t\tdeactivate \"character=" + Princess->party[3]->name + "\"\n"
		   << "\t\tdeactivate \"character=" + Princess->party[4]->name + "\"\n"
		   << "\t}\n"
		   << "}\n";
		os.close();

		scpRep('E', "LEVEL",
			"\t\tif FreePlay == 0 goto "
			"MakeSurePlayersNotDroids\n",
			0, {3, 1});

		scpAppend('E', "LEVEL",
			"state MakeSurePlayersNotDroids {\n"
			"\tConditions {\n"
			"\t}\n"
			"\tActions {\n"
			"\t\tdeactivate \"character=" +
				Princess->party[3]->name + "\"\n" + "\t\tdeactivate \"character=" + Princess->party[4]->name + "\"\n" +
				"\t}\n" + "}");

		scpDeleter('A', "NOWEAPON");
		scpDeleter('B', "NOWEAPON");
		scpDeleter('C', "NOWEAPON");
		scpDeleter('D', "NOWEAPON");
		scpDeleter('E', "NOWEAPON");

		scriptTxt('A', 5, 6);
		scriptTxt('B', 5, 9);
		scriptTxt('C', 5, 3);
		scriptTxt('D', 5, 1);
		scriptTxt('E', 5, 4);

		currentLev = DSE;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}});

		scpMany('A', "PARTY", {{4, {{15, 11}}}, {5, {{14, 11}}}});
		scpMany('B', "PARTY", {{4, {{15, 11}}}, {5, {{14, 11}}}});
		scpMany('C', "PARTY", {{4, {{12, 11}, {15, 11}}}, {5, {{6, 11}, {9, 11}}}});

		currentLev = RebelAttack;
		playerInit({{0, 1}, {1, 2}});

		currentLev = Hoth;
		mainTxtIns("character \"" + Hoth->party[0]->name +
					   "\" player\n"
					   "character \"" +
					   Hoth->party[1]->name + "\" player",
			32, {1, 1});

		currentLev = EchoBase;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}});

		scpMany('A', "PARTY", {{2, {{24, 11}}}, {3, {{5, 11}}}});

		scpMany('B', "PARTY",
			{{"if CategoryIs \"protocol\"", 13, {{23, 3}}}, {"category=protocol", 14, {{111, 29}}},
				{"protocol", 4, {{112, 60}}}, {3, {{5, 11}}}});

		scpIns('C', "PARTY", 3, {6, 11});

		scriptTxtRep('A', "ai_skeleton", "SKELETON", 5);
		ai2Write('A', "ai_skeleton", {0x33FB, 0x34B0});

		currentLev = FalconFlight;
		playerInit({{0, 3}, {1, 4}});

		currentLev = Dagobah;
		playerInit({{0, 3}, {1, 4}, {2, 5}, {3, 6}});

		scpMany('A', "LEVEL",
			{{0, {{21, 26}, {22, 27}, {23, 27}, {24, 25}}}, {2, {{34, 26}, {35, 27}, {36, 27}, {37, 25}}},
				{3, {{39, 26}, {40, 27}, {41, 27}, {42, 25}}}});
		scpMany('B', "LEVEL",
			{{0, {{41, 26}, {42, 27}, {43, 27}, {44, 25}}}, {1, {{59, 28}, {65, 29}, {84, 29}}},
				{2, {{57, 28}, {61, 59}, {63, 29}, {82, 29}, {96, 26}, {97, 27}, {98, 27}, {99, 25}}},
				{3, {{58, 28}, {64, 29}, {83, 29}, {101, 26}, {102, 27}, {103, 27}, {104, 25}}}});
		scpMany('C', "LEVEL",
			{{0, {{25, 26}, {26, 27}, {27, 27}, {28, 25}}}, {2, {{38, 26}, {39, 27}, {40, 27}, {41, 25}}},
				{3, {{43, 26}, {44, 27}, {45, 27}, {46, 25}}}});
		scpMany('D', "LEVEL",
			{{0, {{35, 26}, {36, 27}, {37, 27}, {38, 25}}}, {2, {{48, 26}, {49, 27}, {50, 27}, {51, 25}}},
				{3, {{53, 26}, {54, 27}, {55, 27}, {56, 25}}}});
		scpMany('E', "LEVEL",
			{{0, {{33, 26}, {34, 27}, {35, 27}, {36, 25}, {54, 26}, {55, 27}, {56, 27}, {57, 25}}}, {3, {{38, 27}}}});

		//fixes AI
		scpRep('C', "PARTY", "if CategoryIs \"Jedi\" == 0", 18, {5, 3});

		scpMany('E', "PARTY", {{2, {{9, 11}}}, {3, {{7, 11}, {170, 11}}}});

		hexWrite(EXE, "\0",
			0x35E3A0); //unrestricts xwing force

		//training
		if (Dagobah->party[2]->check(Jedi))
			multiPointer(Dagobah->party[2], {0x3464d, 0x35b2d, 0x87114, 0xa219a, 0xa23f7, 0xa38b6});
		else if (Dagobah->party[1]->check(Jedi))
			multiPointer(Dagobah->party[1], {0x3464d, 0x35b2d, 0x87114, 0xa219a, 0xa23f7, 0xa38b6});

		currentLev = CCT;
		playerInit({{0, 3}, {1, 4}});

		scpRep('A', "PARTY", "if CategoryIs \"Droid\" == 1", 18, {5, 3});
		scpRep('B', "PARTY", "if CategoryIs \"Droid\" == 1", 18, {5, 3});
		scpRep('C', "PARTY", "if CategoryIs \"Droid\" == 1", 18, {5, 3});

		currentLev = Bespin;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}});

		scpMany('A', "PARTY", {{3, {{14, 11}, {20, 11}}}, {4, {{15, 11}, {17, 11}}}});
		scpMulti('B', "PARTY", {4, {{14, 11}, {16, 11}}});

		scpMany('C', "PARTY",
			{{"if CategoryIs \"Protocol\"", 13, {{13, 3}, {24, 3}}},
				{"if CategoryIs \"Astromech\"", 13, {{18, 3}, {30, 3}}}});

		//buildable 3po
		baseFile('A', "TXT", 4, {494, 13});
		baseFile('A', "GIT", 4, {1598, 22});

		if (Bespin->panels[0].panels[1].type != BountyPanel) {
			//Prevents camera pan if Boba can't open
			//door
			lineDeleterScp('A', "AI_BOBAFETT", {345, 348});
		}

		currentLev = Jabbas;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}});

		scpMulti('E', "LEVEL", {0, {{17, 26}, {18, 25}}});

		scpMany('A', "PARTY", {{2, {{28, 11}}}, {3, {{7, 11}}}, {4, {{8, 11}, {10, 11}}}, {5, {{6, 11}}}});

		scpMany('B', "PARTY",
			{
				{3, {{27, 11}, {30, 11}}},
				{4, {{35, 11}}},
				{5, {{9, 11}}},
			});

		//fixes AI
		scpMulti('B', "PARTY", {"if CategoryIs \"Jedi\"", 27, {{49, 3}, {38, 3}}});

		int leverGuy = -1;
		if (!Jabbas->party[1]->check(Jedi) && Jabbas->party[1]->check(Lever)) leverGuy = 1;
		else if (!Jabbas->party[0]->check(Jedi) && Jabbas->party[0]->check(Lever)) leverGuy = 0;
		else if (!Jabbas->party[2]->check(Jedi) && Jabbas->party[2]->check(Lever)) leverGuy = 2;

		if (leverGuy != -1) scpMulti('B', "PARTY", {leverGuy, {{39, 11}, {50, 11}}});

		scpIns('D', "PARTY", 5, {6, 11});

		scpMany('E', "PARTY",
			{{"if CategoryIs \"Astromech\"", 13, {{6, 3}}}, {"if CategoryIs \"Protocol\"", 13, {{8, 3}}}});

		currentLev = Carkoon;
		playerInit({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}});

		scpMany('A', "LEVEL", {{2, {{132, 27}, {133, 27}, {134, 29}}}, {3, {{130, 59}, {136, 27}, {137, 27}}}});
		scpMany('B', "LEVEL",
			{{4, {{56, 27}, {57, 27}, {58, 26}, {59, 29}}}, {5, {{61, 27}, {62, 27}, {63, 26}, {64, 29}}}});

		scpMany('A', "PARTY",
			{{2, {{36, 11}}}, {3, {{39, 11}}}, {4, {{8, 11}, {11, 11}}}, {5, {{9, 11}, {14, 11}}},
				{6, {{7, 11}, {17, 11}}}});
		scpMany('B', "PARTY", {{4, {{30, 11}}}, {5, {{27, 11}}}, {6, {{6, 11}, {8, 11}}}});

		currentLev = Showdown;
		playerInit({{0, 3}, {1, 4}});

		currentLev = Endor;
		playerInit({{0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}});

		if (Endor->party[0]->check(Grapple)) leverGuy = 0;
		else if ((Endor->party[1]->check(Grapple))) leverGuy = 1;
		else if ((Endor->party[2]->check(Grapple))) leverGuy = 2;
		else if ((Endor->party[3]->check(Grapple))) leverGuy = 3;
		else if ((Endor->party[4]->check(Grapple))) leverGuy = 4;
		else if ((Endor->party[5]->check(Grapple))) leverGuy = 5;

		scpIns('B', "PARTY", leverGuy, {5, 11});

		currentLev = Destiny;
		playerInit({{0, 1}, {1, 2}});

		currentLev = ITDS;
		playerInit({{0, 1}, {1, 2}});

		//currentLev = PodraceOriginal;
		//playerInit({{0, 1}, {1, 2}});

		currentLev = Anakinsflight;
		playerInit({{0, 1}, {1, 2}});

		currentLev = ANewHope;
		playerInit({{0, 1}, {1, 2}, {2, 3}});

		scriptTxt('A', 2, 1);
		scriptTxt('B', 2, 1);

		//takeover speeder?

		//bounty hunter missions
		{
			currentLev = BHM;

			batchAnywhere(LEV + "MISSIONS.TXT",
				{{"party \"" + BHM->party[0]->name + "\" \"" + BHM->party[1]->name + "\" \"" + BHM->party[2]->name +
						 "\" \"" + BHM->party[3]->name + "\" \"" + BHM->party[4]->name + "\" \"" + BHM->party[5]->name +
						 "\" ",
					 56, {{1, 1}}},

					{0, {{5, 15}}, bonusCharacter}, {1, {{6, 15}}, bonusCharacter}, {2, {{7, 15}}, bonusCharacter},
					{3, {{8, 15}}, bonusCharacter}, {4, {{9, 15}}, bonusCharacter}, {5, {{10, 15}}, bonusCharacter},
					{6, {{11, 15}}, bonusCharacter}, {7, {{12, 15}}, bonusCharacter}, {8, {{13, 15}}, bonusCharacter},
					{9, {{14, 15}}, bonusCharacter},

					{10, {{17, 15}}, bonusCharacter}, {11, {{18, 15}}, bonusCharacter},
					{12, {{19, 15}}, bonusCharacter}, {13, {{20, 15}}, bonusCharacter},
					{14, {{21, 15}}, bonusCharacter}, {15, {{22, 15}}, bonusCharacter},
					{16, {{23, 15}}, bonusCharacter}, {17, {{24, 15}}, bonusCharacter},
					{18, {{25, 15}}, bonusCharacter}, {19, {{26, 15}}, bonusCharacter}});

			auto missionReplace2 = [](int c, unsigned int line, Level* lev, char scene, std::string script) {
				writer(oneWrite, getSCP(lev, scene, script),
					{BHM->bonusCharacters[c]->name,
						static_cast<unsigned int>(BHM->vanillaBonusCharacters[c]->name.length()), {line, 49}});
				//scpIns(scene, script, c,
				//{line, 49}, bonusCharacter);
			};

			missionReplace2(0, 24, Negotiations, 'A', "LEVEL2");
			missionReplace2(1, 24, EscapeNaboo, 'C', "LEVEL1");
			missionReplace2(2, 24, Invasion, 'C', "LEVEL1");
			missionReplace2(3, 24, Factory, 'F', "LEVEL1");
			missionReplace2(4, 24, Kamino, 'F', "LEVEL1");
			missionReplace2(5, 25, JediBattle, 'B', "LEVEL1");
			missionReplace2(6, 25, Chancellor, 'B', "LEVEL1");
			missionReplace2(7, 24, Kashyyyk, 'A', "LEVEL2");
			missionReplace2(8, 24, Ruin, 'A', "LEVEL");
			missionReplace2(9, 25, Grievous, 'A', "LEVEL2");

			missionReplace2(10, 30, SecretPlans, 'B', "LEVEL1");
			missionReplace2(11, 24, Jundland, 'B', "LEVEL2");
			missionReplace2(12, 28, Spaceport, 'D', "LEVEL3");
			missionReplace2(13, 30, Princess, 'C', "LEVEL4");
			missionReplace2(14, 25, EchoBase, 'C', "LEVEL1");
			missionReplace2(15, 20, Endor, 'A', "LEVEL2");
			missionReplace2(16, 23, Bespin, 'A', "LEVEL2");
			missionReplace2(17, 26, Bespin, 'C', "LEVEL1");
			missionReplace2(18, 21, Spaceport, 'B', "LEVEL4");
			missionReplace2(19, 19, EchoBase, 'A', "LEVEL2");

			std::vector<writeSet> bounties;

			auto missionNames = [&bounties](int c, coord lc, unsigned int len) {
				bounties.push_back({BHM->bonusCharacters[c]->realName, len, {lc}});
			};

			missionNames(0, {266, 18}, 12);
			missionNames(1, {267, 18}, 13);
			missionNames(2, {268, 18}, 13);
			missionNames(3, {269, 18}, 10);
			missionNames(4, {270, 18}, 9);
			missionNames(5, {271, 18}, 8);
			missionNames(6, {272, 18}, 12);
			missionNames(7, {273, 18}, 13);
			missionNames(8, {274, 18}, 7);
			missionNames(9, {275, 19}, 14);

			missionNames(10, {9, 17}, 5);
			missionNames(11, {10, 17}, 14);
			missionNames(12, {11, 17}, 9);
			missionNames(13, {12, 17}, 13);
			missionNames(14, {13, 17}, 14);
			missionNames(15, {14, 17}, 4);
			missionNames(16, {15, 17}, 5);
			missionNames(17, {16, 17}, 16);
			missionNames(18, {17, 17}, 14);
			missionNames(19, {18, 17}, 8);

			batchAnywhere(ENGLISH, bounties);
		}
		multiPointer(allMinikitsCharacter, {0x2b0ce, 0x84ef2, 0x5a750, 0x5fd87, 0x5a7db, 0x5fe12});

		//removed 0x86969, 0x86982,
		multiPointer(indy, {0x2e585, 0xc1053, 0x83b26, 0xc5098, 0x86969, 0x86982, 0xc50d0, 0xc65b1});
		numWrite(EXE, indy->price, 0x2e5c7);
		//txtIns(out + "/STUFF/TEXT/ENGLISH.TXT",
		//indy->realName, {{1627, 7}}, 13);
		writer(oneWrite, ENGLISH, writeSingle{indy->realName, 13, {1627, 7}});

	} //character

outro:
	//Character unlocks
#ifdef _DEBUG
	logR("starting collection");
#endif

	std::ofstream collect(out + "/CHARS/COLLECTION.TXT");

	auto collectWrite = [&](std::vector<Playable*>& vec) {
		for (Playable* p : vec) {
			collect << "collect \"" + p->name + "\" ";
			if (p == allMinikitsCharacter) collect << "all_minikits_complete" << '\n';
			else if (p->StoryMode) collect << "story" << '\n';
			else {
				if (p->check(AllEpisodes)) {
					collect << "all_episodes_complete ";
				} else if (!(p->check(NoLevel))) {
					collect << "area_complete "
							   "\"";
					collect << p->lev->name << "\" ";
				}
				collect << "buy_in_shop ";
				collect << std::to_string(p->price) << '\n';
			}
#ifdef _DEBUG
			logR(p->realName + " collected.");
#endif
		}
	};

	collectWrite(chs);

	collect << "collect \"weirdo1\"" << '\n';
	collect << "collect \"weirdo2\"" << '\n';

	collectWrite(vhs);

	std::string minis[] = {"mini_republic_cruiser", "mini_gungan_bongo", "mini_royal_starship", "mini_sebulba_pod",
		"mini_naboo_starfighter", "mini_sith_infiltrator",

		"mini_zam_speeder", "mini_jedi_starfighter", "mini_droideka", "mini_gunship", "mini_atte", "mini_solar_sailor",

		"mini_dropship", "mini_emergency_ship", "mini_e3_jedi_starfighter", "mini_wookie_cat", "mini_e3_x_wing",
		"mini_v_wing",

		"mini_star_destroyer", "mini_sand_crawler", "mini_land_speeder", "mini_millennium_falcon", "mini_y_wing",
		"mini_tie_advanced",

		"mini_atat", "mini_snow_speeder", "mini_tie_fighter", "mini_x_wing", "mini_slave1", "mini_cloud_car",

		"mini_desert_skiff", "mini_sail_barge", "mini_tie_bomber", "mini_atst", "mini_tie_interceptor",
		"mini_imperial_shuttle"};

	for (std::string mini : minis) {
		collect << "collect \"" << mini << "\" minikit" << '\n';
	}
	collect.close();

	//fixes ET characters
	if (extog) {
		writer(oneWrite, ENGLISH, writeSingle{"Nothing", 13, {839, 6}});

		lineDeleter(CHR + "BUZZDROID/BUZZDROID.TXT", {7});
		lineDeleter(CHR + "HANINCARBONITE/HANINCARBONITE.TXT", {20});
		lineDeleter(CHR + "MOUSEDROID/MOUSEDROID.TXT", {17});
		lineDeleter(CHR + "NAFFDROID1/NAFFDROID1.TXT", {19});
		lineDeleter(CHR + "NAFFDROID2/NAFFDROID2.TXT", {19});
		lineDeleter(CHR + "NAFFDROID3/NAFFDROID3.TXT", {13});
		lineDeleter(CHR + "NAFFDROID4/NAFFDROID4.TXT", {19});
		lineDeleter(CHR + "REBELSCUM/ENGINEER.TXT", {5});
		lineDeleter(CHR + "SKELETON/SKELETON.TXT", {6});
		lineDeleter(CHR + "STORMTROOPER/ATAT_DRIVER.TXT", {4});
		lineDeleter(CHR + "STORMTROOPER/IMPERIALENGINEER.TXT", {7});
		lineDeleter(CHR + "STORMTROOPER/SCOUTTROOPER.TXT", {6});
		lineDeleter(CHR + "TRAININGREMOTE/TRAININGREMOTE.TXT", {4});
		lineDeleter(CHR + "WOMPRAT/WOMPRAT.TXT", {18});
	}

	//if (enemyOp) {
	//	PatchEnemies();
	//}

	/*
	blue	3fb112
	green	3fb102
	red		3fb0f2
	purple	3fb122
	*/

	/*
	green:
	model		205
	material	316
	mesh		389ac

	float		3419AC
	modelptr	36361c
	grnglwptr	363B50
	specialptr	35C4F4
	grnmd		36ADFC

	3F483C
	*/

#if (0)
	if (colorOp) {
		//numWrite(EXE, blueColor, 0x3fb112);
		//numWrite(EXE, greenColor, 0x3fb102);
		//numWrite(EXE, redColor, 0x3fb0f2);
		//numWrite(EXE, purpleColor, 0x3fb122);

		//rgbWrite(EXE, blue, 0x3fb112);
		//rgbWrite(EXE, green, 0x3fb102);
		//rgbWrite(EXE, red, 0x3fb0f2);
		//rgbWrite(EXE, purple, 0x3fb122);

		rgbBatch(PTL, blue, {0x4A0, 0x4A8, 0x591A, 0x5922, 0x592A, 0x77D2, 0xF5FD, 0xF689, 0xF691, 0x8357});
		rgbBatch(PTL, green, {0x877, 0x87F, 0x5543, 0x554B, 0x5553, 0xAD94});
		rgbBatch(PTL, red, {0x60C8, 0x60D0, 0x60D8, 0xB542, 0xC0C7, 0xC0CF, 0xFDAB, 0xFE37, 0xFE3F});
		rgbBatch(PTL, purple, {0xC4E, 0xC56, 0x5CF1, 0x5CF9, 0x5D01, 0xB16B, 0x19021});

		rgbBatch(PT1, blue, {0x4A0, 0x4A8, 0x10628, 0x10630, 0x111B0, 0x111B8, 0x111C0});
		rgbBatch(PT1, green, {0x878, 0x880, 0x10DD8, 0x10DE0, 0x10DE0});
		rgbBatch(PT1, red, {0x1028, 0x1030, 0x11968, 0x11960, 0x11970});
		rgbBatch(PT1, purple, {0xC50, 0xC58, 0x11588, 0x11590, 0x11598, 0x11960, 0x11968});

		rgbBatch(PTC, blue, {0x1025, 0x102D});
		rgbBatch(PTC, green, {0x13FC, 0x1404});
		rgbBatch(PTC, red, {0x1BAA, 0x1BB2, 0x1F81, 0x1F89});
		rgbBatch(PTC, purple, {0x17D3, 0x17DB});

		rgbBatch(PC1, blue, {0xC50, 0xC58});
		rgbBatch(PC1, green, {0x1028, 0x1030});
		rgbBatch(PC1, red, {0x17D8, 0x17E0, 0x1BB0, 0x1BB8});
		rgbBatch(PC1, purple, {0x1400, 0x1408});

		//rgbFloat(TNG, blue, 0x341C70);
		//rgbFloat(TNG, green, 0x3419AC);
		//rgbFloat(TNG, red, 0x341160);
		//rgbFloat(TNG, purple, 0x3416E8);

		//rgbFloat(TNG, green, 0x342A44);

		//219	0260ff
		//rgbFloat(TNG, red, 0x341F34); //double

		rgbBatch(PC1, red, {0x1BB0, 0x1BB8});
		rgbBatch(TNG, blue, {214, 316, 217, 272});
		rgbBatch(TNG, green, {316, 213, 317, 274, 273});
		rgbBatch(TNG, red, {316, 210, 215, 273, 274});
		rgbBatch(TNG, purple, {316, 212, 271, 272});

		//for (int i = 0; i < 340; i++) {
		//	rgbFloat(TNG, green, 0x31CC98 + (i *
		//0x2c4));
		//}
	}
#endif

	//free memory
	chs.clear();
	vhs.clear();
	testing.clear();

	for (Playable* p : pls)
		delete p;
	for (Level* lev : allLevels)
		delete lev;
	for (EnemyType* en : enemyTypes)
		delete en;
	for (EnemyType* en : walkerTypes)
		delete en;
	pls.clear();
	allLevels.clear();

	delete defaultCharacter;
	//delete BHM;

	logR("\n\t\t\t\t\tDone.");
	//loggingIt->close();
	std::cout << "Done.\n";
	//wxLogStatus("Done.");
}
