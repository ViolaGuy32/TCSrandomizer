#include "Randomize.h"

#include <wx/log.h>

#include <filesystem>
#include <sstream>
#include <vector>
#include <array>
#include <random>

#include "App.h"
#include "Characters.h"
#include "Defines.h"

const std::mt19937_64* randoPTR;
uint64_t seed = 0;
extern bool character;
extern bool extog;
extern bool greenVeh;

extern bool extra;
extern bool collectable;
extern bool enemy;
extern bool colorOp;
extern bool advanceMus;
extern LogicType logicType;

std::vector<Playable*> pls; //Characters and Vehicles
std::vector<Playable*> chs;           //Characters
std::vector<Playable*> vhs;           //Vehicles
std::vector<Playable*> testing = {};  //Current logic

extern std::string out;
extern std::string vanilla;
extern std::vector<Level*> allLevels;

std::unordered_map<std::string, Playable*> nameList;
Playable* defaultCharacter;
Level* BHM;


void Randomize() {
	std::remove("files/log.txt");
	std::ofstream loggingIt("files/log.txt");

	//std::random_device rando;
	//std::seed_seq rando(time(NULL));
	//srand(time(nullptr));


	if (seed == 0) {
		std::random_device rd;
		seed = rd();
	}
	const std::mt19937_64 rando(seed);
	randoPTR = &rando;

	charMaker();
	levMaker();

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
	std::array<std::string, 36> extras = {
		"supergonk",
		"poomoney",
		"walkietalkiedisable",
		"powerbrickdetector",
		"superslap",
		"forcezipup",
		"coinmagnet",
		"disarmtroopers",
		"characterstuds",
		"perfectdeflect",
		"explodingblasterbolts",
		"forcepull",
		"vehiclesmartbomb",
		"superastromech",
		"superjedislam",
		"superthermaldetonator",
		"deflectbolts",
		"darkside",
		"superblasters",
		"fastforce",
		"supersabres",
		"tractorbeam",
		"invincibility",
		"scorex2",
		"selfdestruct",
		"fastbuild",
		"scorex4",
		"regenerate",
		"scorex6",
		"minikitdetector",
		"superzapper",
		"rockets",
		"scorex8",
		"superewokcatapult",
		"scorex10",
		"infinitetorpedos"
	};

	std::array<std::string, 36> vanillaExtras = extras;

	if (extra) {
		std::shuffle(extras.begin(), extras.end(), rando);
	}

	if (collectable) {
		for (int i = 0; i < 36; i++) {
			std::shuffle(allLevels[i]->collectables.begin(), allLevels[i]->collectables.end(), rando);
		}
	}

	Playable* cantina1 = nameList["quigonjinn"];
	Playable* cantina2 = nameList["obiwankenobi"];
	Playable* indy = nameList["hansolo_indy"];
	Playable* allMinikitsCharacter = nameList["slave1"];

	if (character) {
		//makes code easier to read and debug
	#define Build &Playable::build
	#define Lever &Playable::lever
	#define Box &Playable::box //also for riding stuff

	#define Jedi &Playable::jedi
	#define Sith &Playable::sith
	#define Saber &Playable::saber //includes magnaguard
	#define Deflect &Playable::deflect

	#define Attack &Playable::attack
	#define Grapple &Playable::grapple
	#define Shoot &Playable::shoot
	#define FakeShoot &Playable::fakeshoot //training remote does no damage to enemies but can still destroy objects

	#define Jump &Playable::jump
	#define DoubleJump &Playable::doubleJump
	#define RealDoubleJump &Playable::realDoubleJump
	#define HighJump &Playable::highJump
	#define ExtraHighJump &Playable::extraHighJump
	#define HighDoubleJump &Playable::highDoubleJump
	#define Dive &Playable::dive
	#define YodaJump &Playable::yodaJump

	#define Fly &Playable::fly
	#define Flutter &Playable::flutter
	#define Hovering &Playable::hovering //trainingremote
	#define Fett &Playable::fett
	#define Zapper &Playable::zapper
	#define AstroZapper &Playable::astrozapper

	#define Hat &Playable::hat
	#define Proto &Playable::proto
	#define Astro &Playable::astro
	#define Imperial &Playable::imperial
	#define Bounty &Playable::bounty

	#define Passive &Playable::passive
	#define Ghost &Playable::ghost
	#define Hatch &Playable::hatch
	#define Tall &Playable::tall //can walk in swamp

	#define Tow &Playable::tow

		cantina :
		cantina1 = chs[rand() % chs.size()];
		cantina2 = chs[rand() % chs.size()];
		if (cantina1 == cantina2)
			goto cantina;

	negotiations:
		mix(Negotiations);

		if (!atrb(Jedi)) goto negotiations;

		add(2);
		if (logicType == casual) {
			if (!atrb(Proto) || !MultiAny({DoubleJump, Dive}, 2))
				goto negotiations;
		} else {
			if (!atrb(Proto) && !SuperJump())
				goto negotiations;
			if (!Multi(Jump, 2))
				goto negotiations;
		}

	invasion:
		mix(Invasion);

		if (logicType == casual) {
			if (atrb(Jedi))
				goto invasion2;

		} else {
			if (atrb(Jedi) || atrb(HighJump))
				goto invasion2;
		}
		goto invasion;

	invasion2:
		add(2);
		if (logicType == casual) {
			if (!atrb(HighJump))
				goto invasion;
		} else {
			if (atrb(Jedi))
				goto escape;
			if (atrb(Fett) && atrb(HighDoubleJump))
				goto escape;
			goto invasion;
		}

	escape:
		mix(EscapeNaboo);
		if (atrb(Grapple)) goto podrace;

		if (logicType != casual) {
			if (SuperJump(Jump) && atrb(Shoot))
				goto podrace;
		}
		goto escape;

	podrace:
		mix(Podrace);

	theed:
		mix(Theed);
		add(2);
		add(3);
		add(4);
		add(5); //0 and 1 are in mix function.

		if (logicType == casual) {
			if (atrb(Astro) && Multi(Jedi, 2) && atrb(Hatch) &&
				MultiAny({Jedi, Grapple, Hatch, Fly}, 6))
				goto maul;
		} else {
			if (logicType != superGlitched) {
				//button room
				if (!(atrb(Jedi) && MultiAny({Jump, Fly, Flutter}, 6)
					|| MultiAny({Fly, Grapple, HighJump}, 6)))
					goto theed;
			}
			if (!atrb(Astro))
				goto theed;
			if (!All({DoubleJump, Attack}) && !atrb(Shoot))
				goto theed;
			if (!atrb(HighJump) && !atrb(Jedi) && !SuperJump(Jump))
				goto theed;
			goto maul;
		}
		goto theed;

		//double ghost
	maul:
		mix(Maul);
		if (logicType == casual) {
			if (Multi(Jedi, 2) && LivingJedi())
				goto bhp;
		} else {
			if (Multi(Jedi, 2)) goto
				bhp;
		}
		goto maul;

	bhp:
		mix(BHP);

		if (atrb(Shoot))
			goto kamino;

		goto bhp;

	kamino:
		mix(Kamino);

		//Jango fight
		if (Multi(Passive, 2) && !(Shoot))
			goto kamino;
		//Astrozapper is flying astromechs
		if (atrb(Jedi) && atrb(AstroZapper))
			goto factory;

		if (logicType != casual) { //worst superjump ever
			if (atrb(Jedi) && atrb(Fly) && SuperJump())
				goto factory;
		}
		goto kamino;

	factory:
		mix(Factory);

		if (!atrb(Attack)) goto factory;

		add(2); //r2
		if (!atrb(Astro)) goto factory;
		if (logicType == casual) {
			if (!atrb(Jedi) && !atrb(ExtraHighJump))
				goto factory;
		} else {
			if (!atrb(Jedi) && !atrb(HighJump))
				goto factory;
			if (atrb(Jedi) && atrb(AstroZapper))
				goto factory2;
		}

		if (atrb(Grapple))
			goto factory2;
		goto factory;

	factory2:
		add(3); //3po
		if (All({Astro, Proto})) goto factory;
		if (!atrb(Jedi)) goto factory;
		if (!atrb(Proto)) goto factory;

		if (logicType == casual) {
			if (!atrb(AstroZapper)) goto factory;
		}

	jedibattle:

		mix(JediBattle);

		if (!atrb(Jedi))
			goto jedibattle;

	gunship:
		mix(Gunship);

		if (!atrb(Tow))
			goto gunship;

	dooku:
		mix(Dooku);
		if (Multi(Passive, 2) && !atrb(Shoot)) //fixes the softlock that Zojalyx got
			goto dooku;
		if (logicType == casual) {
			if (!Multi(Jedi, 2))
				goto dooku;
		} else {
			if (!Any({Jedi, Shoot}))
				goto dooku;
		}
		//Yoda cutscene
		testing = {};
		add(0);
		add(2);
		if (!atrb(Attack))
			goto dooku;
		if (Multi(Passive, 2) && !atrb(Shoot))
			goto dooku;

	coruscant:
		mix(Coruscant);

		if (!atrb(Shoot))
			goto coruscant;

	chancellor:
		mix(Chancellor);
		if (!atrb(Jedi)) goto chancellor;

		add(2); //r2
		if (!atrb(Astro)) //might be possible to skip
			goto chancellor;
		add(3); //palpatine
		if (!Multi(Jedi, 2))
			goto chancellor;
		if (logicType == casual) {
			//can outrun elevator
			if (GetSlowest() < 1.0)
				goto chancellor;
		}

	grievous:
		mix(Grievous);
		if (logicType == casual) {
			if (!atrb(Jedi)) goto grievous;
			if (!atrb(Grapple)) goto grievous;
		} else {
			if (atrb(Jedi))
				goto kashyyyk;
			if (All({Jump, Shoot}))
				goto kashyyyk;

			goto grievous;
		}

	kashyyyk:
		mix(Kashyyyk);
		if (!atrb(Jedi)) goto kashyyyk;
		if (logicType == casual) {
			if (!atrb(Grapple))
				goto kashyyyk;
		} else {
			if (!MultiAny({Jump, Flutter}, 2))
				goto kashyyyk;
			if (logicType != superGlitched) {
				//no enemies on buttons except in super glitched
				if (!atrb(Grapple) && !atrb(YodaJump))
					goto kashyyyk;
			}
		}

	ruin:
		mix(Ruin);
		if (!atrb(Jedi))
			goto ruin;

	vader:
		mix(Vader);
		if (Multi(Ghost, 2))
			goto vader;
		if (logicType == casual) {
			if (Multi(Jedi, 2))
				goto secretplans;
		} else {
			if (!atrb(Jedi))
				goto vader;
			if (GetSlowest() <= 1.01)
				goto vader;
			if (Multi(DoubleJump, 2))
				goto secretplans;
			if (atrb(YodaJump)) //force clip into wall thing
				goto secretplans;
			if (InstantSuperJump())
				goto secretplans;
		}

		goto vader;

	secretplans:

		bool(*plansthing)(std::vector<Playable*>, Playable*, Playable*) =
			[](std::vector<Playable*> current, Playable* shield, Playable* redGuy) {
			//This is for scene 3 super jump
			if (logicType != superGlitched) return false;

			for (Playable* x : current) {
				for (Playable* y : current) {
					bool OOB = false;
					bool OOB2 = false;

					if (x != y) {
						if (x->pushable && y->jedi) OOB = true;
						else if (x->chokeable && y->choke) OOB = true;
						else if (x->trickable && y->jedi) OOB = true;
						else if (x->zapper && y->zappable) OOB = true;
						else if (x->astrozapper && y->storm) OOB = true;
						else if (x->landoAlt && y->leiaAlt) OOB = true;
						else if (x == nameList["gamorreanguard"] && y->lukeAlt) OOB = true;

						Playable* otherX = defaultCharacter;
						if (OOB) {
							for (Playable* x2 : current) {
								for (Playable* y2 : current) {
									if (x2 != y2 && x2 != x) {
										if (x2->pushable && y2->jedi) OOB2 = true;
										else if (x2->chokeable && y2->choke) OOB2 = true;
										else if (x2->trickable && y2->jedi) OOB2 = true;
										else if (x2->zapper && y2->zappable) OOB2 = true;
										else if (x2->astrozapper && y2->storm) OOB2 = true;
										else if (x2->landoAlt && y2->leiaAlt) OOB2 = true;
										else if (x2 == nameList["gamorreanguard"] && y2->lukeAlt) OOB2 = true;

										if (OOB2) otherX = x2;
									}
								}
							}
							if (atrb(Astro, {x, shield})) return true;
							if (atrb(Proto, {x, otherX}) && atrb(Box, {x, otherX})) return true;
							if (atrb(Proto, {redGuy}) &&
								(Any({DoubleJump, Fly}, {x, otherX}) || (atrb(Box, {x}) && atrb(Lever, {redGuy})))) return true;
							//								not sure
						}
					}
				}
			}
			return false;
		};

		mix(SecretPlans);
		if (logicType == casual) {
			if (!All({Grapple, Build}) && !All({YodaJump, Build}) &&
				!All({ExtraHighJump, Build}))
				goto secretplans;
			if (!atrb(Lever))
				goto secretplans;
			if (!atrb(Shoot) && !atrb(FakeShoot))
				goto secretplans;

		} else {
			if (!atrb(Attack))
				goto secretplans;
			if (!atrb(Build))
				goto secretplans;
			if (!atrb(Lever))
				goto secretplans;
			if (((All({Grapple, Build}) || atrb(YodaJump) || //Both Yodas can build
				All({ExtraHighJump, Build})) &&
				(atrb(Shoot) || atrb(FakeShoot))) ||
				SuperJump(Jump) || DoubleTransitionSkip(Jump))
				goto secretplans2;
			goto secretplans;
		}
	secretplans2:

		add(3); //3po
		if (logicType == casual) {
			if (!atrb(Proto))
				goto secretplans;
		} else {
			//Bounties can get the car
			if (Any({Jedi, Bounty}) && SecretPlans->party[4]->astro)
				goto secretplans3;
			if (atrb(Proto) && atrb(Astro, {SecretPlans->party[1], SecretPlans->party[3],
														SecretPlans->party[4]}))
				goto secretplans3;

			//droids and rebel friend area with super jumps
			if (plansthing({SecretPlans->party[0], SecretPlans->party[1],
							SecretPlans->party[3]}, SecretPlans->party[4], SecretPlans->party[2]))
				goto secretplans3;

			if (atrb(Proto) && plansthing({SecretPlans->party[1], SecretPlans->party[3],
														SecretPlans->party[4]}, defaultCharacter, SecretPlans->party[2]))
				goto secretplans3;

			goto secretplans;
		}


	secretplans3:

		testing = {};
		add(1); //midtro
		add(3);
		add(4);
		if (logicType == casual) {
			if (!atrb(Astro))
				goto secretplans;
			if (!Any({Jedi, Fett}) && !(SecretPlans->party[2]->lever && atrb(Box)))
				goto secretplans;
		}
		add(2); //rebel friend
		if (!atrb(Build) && !All({Jump, Proto}))
			goto secretplans;
		if (!atrb(Proto))
			goto secretplans;
		if (!atrb(Astro))
			goto secretplans;
		if (!atrb(Lever))
			goto secretplans;

	jundland:
		mix(Jundland);
		if (logicType == casual) {
			if (!atrb(Jedi))
				goto jundland;
			if (!All({Grapple, Lever}))
				goto jundland;
		} else {
			if (atrb(Jedi))
				goto jundland4;
			//if (HighJump() && DoubleTransitionSkip(Jump)) goto jundland4; //can get inside but cannot get past first area
			goto jundland;
		}

	jundland4:
		add(3); //r2
		if (logicType == casual) {
			if (!atrb(Astro))
				goto jundland;
			if (!Multi(Lever, 2))
				goto jundland;
		} else {
			if (atrb(Astro))
				goto jundland2;
			if (InstantSuperJump() && atrb(Proto))
				goto jundland2;
			goto jundland;
		jundland2:
			if (Multi(Lever, 2))
				goto jundland3;
			//only grapple characters can do weirdshots
			if (atrb(Grapple) && logicType == superGlitched)
				goto jundland3;
			if (atrb(Grapple) && atrb(AstroZapper) && Jundland->party[2]->proto)
				goto jundland3;
			goto jundland;
		}

	jundland3:
		add(2); //3po
		if (!atrb(Proto))
			goto jundland;

	spaceport:
		mix(Spaceport);
		add(2);
		add(3);
		//cantina buttons
		if (!atrb(Shoot) && !atrb(FakeShoot)) {
			for (Playable* p : testing)
				if (p->droid && !p->jump)
					goto spaceport3;
			goto spaceport;
		}
	spaceport3:
		if (logicType == casual) {
			if (!All({Proto, Imperial}) && !atrb(Imperial))
				goto spaceport;
			if (atrb(Bounty))
				goto spaceport2;
			if (atrb(Proto) && atrb(Astro))
				goto spaceport2;

			goto spaceport;
		} else {
			if (!atrb(Box))
				goto spaceport;
		}

	spaceport2:
		testing = {};
		add(4); //han and chewbacca
		add(5);
		if (logicType == casual) {
			if (!atrb(Box))
				goto spaceport;
		} else {
			if (!atrb(Box) && !atrb(DoubleJump))
				goto spaceport;
			if (GetFastest() > 1.2001) //test exact number
				goto princess;
		}
		if (!atrb(Attack) && !atrb(FakeShoot))
			goto spaceport;
		if (atrb(Bounty))
			goto princess;
		if (All({Grapple, Lever, Box}))
			goto princess;
		if (All({DoubleJump, Lever, Box}))
			goto princess;
		goto spaceport;

	princess:
		mix(Princess);
		add(2);
		add(3);
		add(4);
		add(5);
		if (!atrb(Jedi))
			goto princess;
		if (logicType == casual) {
			if (!atrb(Astro))
				goto princess;
		}
		testing = {};
		add(0); //midtro
		add(1);
		add(2);
		if (!Princess->party[5]->jedi && !Any({DoubleJump, Fly}))
			goto princess;
		if (!atrb(Grapple))
			goto princess;
		if (!Any({Hat, Imperial}))
			goto princess;

	dse:
		mix(DSE);
		add(2);
		add(3);
		if (!atrb(Build))
			goto dse;
		if (!Multi(Lever, 2))
			goto dse;
		if (All({Grapple, Hat}))
			goto dse2;
		if (All({Grapple, Imperial}))
			goto dse2;
		goto dse;

	dse2:
		if (logicType == casual) {
			add(4); //droids
			add(5);
			if (!atrb(Astro))
				goto dse;
			if (!atrb(Proto))
				goto dse;
		}

	rebelattack:
		mix(RebelAttack);

		if (!atrb(Shoot))
			goto rebelattack;

	hoth:
		mix(Hoth);

		if (!atrb(Tow))
			goto hoth;

	echobase:
		mix(EchoBase);
		if (logicType == casual) {
			if (!atrb(Build))
				goto echobase;
			if (!atrb(Box))
				goto echobase;
			if (!Any({Attack, FakeShoot}))
				goto echobase;
		} else {
			if (atrb(Build) && atrb(Box) && Any({Attack, FakeShoot}))
				goto echobase2;
			if (atrb(Astro) && SuperJump())
				goto echobase2;
			goto echobase;
		}

	echobase2:
		add(2); //3po

		if (atrb(Proto)) goto echobase3;
		if (SuperJump()) goto echobase3;
		goto echobase;
	echobase3:
		//snomobile
		if (!atrb(Build)) goto echobase;
		if (!atrb(Box)) goto echobase;

		//ending
		add(3); //chewbacca
		if (Multi(Lever, 2))
			goto falconflight;
		if (All({DoubleJump, Build}))
			goto falconflight;
		if (logicType != casual) {
			if (SuperJump(Build)) //everyone who can build can jump or flutter
				goto falconflight;
			for (Playable* p : testing) {
				if (p->doubleJump && p->build) goto falconflight;
				if (p->dive && p->build) goto falconflight;
				if (p->flop && p->build) goto falconflight;
				if (p->slightlyBetterJump && p->build) goto falconflight;
			}
		}
		goto echobase;

	falconflight:
		mix(FalconFlight);
		if (!atrb(Shoot))
			goto falconflight;

	dagobah:
		mix(Dagobah);
		if (!Any({DoubleJump, Fly, Flutter, Tall, Hovering}))
			goto dagobah;
		if (logicType == casual) {
			if (!Any({Build, Flutter, Tall, Hovering}))
				goto dagobah;
			testing = {}; //training room
			add(1);
			add(2);
			if (!atrb(Jedi) || !atrb(AstroZapper))
				goto dagobah;
		} else {
			if (MultiAny({Jump, Fly, Flutter, Tall, Hovering}, 2) &&
				atrb(AstroZapper))
				goto dagobah2;  //test
			testing = {}; //training
			add(1);
			add(2);
			if (atrb(AstroZapper))
				goto dagobah2;
			if (atrb(Jedi) && Any({Astro, YodaJump}))
				goto dagobah2;
			goto dagobah;
		}

	dagobah2:
		testing = {}; //cave
		add(1);
		add(2);
		add(3);
		if (logicType == casual) {
			if (!Multi(Jedi, 2))
				goto dagobah;
			if (!atrb(AstroZapper))
				goto dagobah;

		} else {
			if (!atrb(Jedi))
				goto dagobah;
			if (!atrb(Astro))
				goto dagobah;
		}

	cct:
		mix(CCT);
		if (!LivingJedi())
			goto cct;
		if (logicType == casual) {
			if (!atrb(AstroZapper))
				goto cct;
			if (!Any({Imperial, Hat}))
				goto cct;
		} else {
			if (!atrb(Fly))
				goto cct;
			if (atrb(Astro))
				goto bespin;
			if (logicType == superGlitched && Any({Imperial, Hat}))
				goto bespin; //door clip pixel jump
			goto cct;
		}

	bespin:
		mix(Bespin);
		add(2);
		if (!atrb(Attack))
			goto bespin;
		if (!atrb(Lever) && !atrb(DoubleJump) && !atrb(Flutter) && !atrb(Hovering))
			goto bespin;
		if (logicType == casual) {
			if (atrb(Proto) && Any({Imperial, Hat}))
				goto bespin2;
			add(3); //r2
			if (atrb(Proto) && atrb(Astro) && Any({Imperial, Hat}))
				goto bespin2;

			//building 3po
			if (!atrb(Astro))
				goto bespin;
			if (!atrb(Build))
				goto bespin;
			if (!atrb(Lever))
				goto bespin;
			if (!atrb(Box))
				goto bespin;
			add(4); //3po
			if (atrb(Proto) && Any({Imperial, Hat}))
				goto bespin2;
			goto bespin;
		} else {
			if (Any({Imperial, Hat}))
				goto bespin2; //all hats and imperials can do door clip

			add(3); //r2
			if (Any({Imperial, Hat}, {Bespin->party[3]}) && atrb(Astro))
				goto bespin2;
			if (Any({Imperial, Hat}, {Bespin->party[4]}) && atrb(Astro) && atrb(Build) &&
				atrb(Box) && atrb(Lever))
				goto bespin2;
		}

	bespin2:
		testing = {};
		add(0);
		add(1);
		add(2);
		add(3);
		add(4);
		if (!All({Lever, Grapple}))
			goto bespin;
		if (logicType == casual) {
			if (!atrb(AstroZapper))
				goto bespin;
			if (!All({Box, DoubleJump}) && !All({Box, Grapple}))
				goto bespin;
		} else {
			if (!atrb(AstroZapper) && !Multi(Fett, 2))
				goto bespin;
		}

	jabbas:
		mix(Jabbas);
		//door
		if (!atrb(Shoot) && !atrb(FakeShoot) && !atrb(Deflect))
			goto jabbas;
		if (!atrb(Build) && !atrb(DoubleJump))
			goto jabbas;
		if (atrb(Bounty))
			goto jabbas2;
		if (atrb(Hat))
			goto jabbas2;
		if (logicType != casual) {
			if (Any({Bounty, Hat}), Jabbas->party[2]) {
				if (atrb(YodaJump)) //only Yoda can jump over the gate
					goto jabbas2;
				if (SuperJump())
					goto jabbas2;
			}
		}
		goto jabbas;

	jabbas2:  //got luke
		add(2);
		if (logicType == casual) {
			if (!atrb(Jedi))
				goto jabbas;
			std::vector<Playable*> droidRoom;
			for (Playable* t : testing)
				if (Any({Jump, Fly, Flutter}, {t})) //can get into droid room
					droidRoom.push_back(t);
			droidRoom.push_back(Jabbas->party[3]);
			droidRoom.push_back(Jabbas->party[4]);
			if (atrb(Astro, droidRoom) && atrb(Proto, droidRoom))
				goto jabbas3;

		} else {
			if (atrb(Jedi))
				goto jabbas3;
			if (All({Box, Astro, Proto}))
				goto jabbas3;
			if (All({Box, DoubleJump})) {
				add(3); //droids
				add(4);
			}
			if (atrb(Jedi))
				goto jabbas3;
			if (atrb(Astro) && atrb(Proto))
				goto jabbas3;
		}
		goto jabbas;

	jabbas3:  //long room
		testing = {};
		add(0);
		add(1);
		add(2);
		add(3);
		add(4);
		if (logicType == casual) {
			if (!atrb(Proto))
				goto jabbas;
			if (!atrb(AstroZapper))
				goto jabbas;
		} else {
			if (atrb(Jedi))
				goto jabbas4;
			if (atrb(Proto) && atrb(Zapper))
				goto jabbas4;
			if (SuperJump({Jump}))
				goto jabbas4;
			goto jabbas;
		}

	jabbas4:  //rancor
		testing = {};
		add(1);
		add(2);
		add(3);
		add(4);
		add(5);
		if (!atrb(Astro) && !atrb(Proto))
			goto jabbas;
		if (!atrb(Attack) && !atrb(FakeShoot))
			goto jabbas;
		if (!atrb(Lever))
			goto jabbas;

	carkoon:
		mix(Carkoon);
		add(0);
		add(1);
		if (atrb(Lever) && atrb(Build))
			goto carkoon2;
		if (atrb(Fly))
			goto carkoon2;
		if (logicType != casual) {
			if (atrb(RealDoubleJump))
				goto carkoon2;
		}
		goto carkoon;

	carkoon2: //second skiff
		add(2);
		add(3);
		if (logicType == casual) {
			if (!atrb(Grapple))
				goto carkoon;
			if (!atrb(Jedi))
				goto carkoon;
		} else {
			if (atrb(Jedi))
				goto carkoon3;
			if (!atrb(Build))
				goto carkoon;
			if (!atrb(Box))
				goto carkoon;

			//superjump to skip Jedi in entire opening
			if (logicType == superGlitched) {
				//You might be able to get over there with flop.
				if (MultiAny({DoubleJump, Fly, Dive}, 2))
					goto carkoon4;
				if (atrb(Grapple) && MultiAny({DoubleJump, Dive}, 2))
					goto carkoon4;
				goto carkoon;
			carkoon4:
				//boba fight
				if (All({DoubleJump, Attack}))
					goto carkoon5;
				if (All({Fly, Attack}))
					goto carkoon5;
				if (All({Dive, Attack}))
					goto carkoon5;

				goto carkoon;
			carkoon5:
				if (All({DoubleJump, Lever}))
					goto carkoon3;
				if (All({Fly, Lever}))
					goto carkoon3;
				if (All({Dive, Lever}))
					goto carkoon3;

				goto carkoon;
			}
			goto carkoon;
		}

	carkoon3: //inside
		add(4);
		add(5);
		if (logicType == casual) {
			if (!atrb(Proto))
				goto carkoon;
		} else {
			if (!atrb(Saber)) //double jump slam into room 3
				goto carkoon;
		}

		add(6); //leia
		if (!atrb(Astro) && !atrb(Bounty))
			goto carkoon;
		if (!atrb(Proto))
			goto carkoon;

	showdown:
		mix(Showdown);
		add(0);
		add(1);
		if (Multi(Jedi, 2))
			goto endor;
		if (atrb(Jedi) && atrb(Grapple))
			goto endor;
		if (logicType != casual) {
			if (Multi(Box, 2) && atrb(DoubleJump)) { //need both to ride speeders
				if (atrb(Jedi) || atrb(Fett))
					goto endor;
			}
		}
		goto showdown;

	endor:
		mix(Endor);
		add(2);
		add(3);
		add(4);
		add(5);
		if (!atrb(Proto))
			goto endor;
		if (logicType == casual) {
			if (!atrb(AstroZapper))
				goto endor;
			if (!atrb(Hatch))
				goto endor;
			if (!atrb(Grapple))
				goto endor;
			if (!MultiAny({Grapple, DoubleJump, Hatch}, 4)) //left side
				goto endor;
		} else {
			if (!atrb(Astro))
				goto endor;
			if (!atrb(Lever))
				goto endor;
			if (!atrb(Box))
				goto endor;
			if (!atrb(Build))
				goto endor;
			if (atrb(DoubleJump)) //12 button skip
				goto destiny;
			if (atrb(Hatch) && MultiAny({Grapple, Hatch}, 4)) //left side
				goto destiny;
			goto endor;
		}

	destiny:
		mix(Destiny);
		if (logicType == casual) {
			if (!atrb(Sith))
				goto destiny;
			if (!Multi(Jedi, 2))
				goto destiny;
		} else {
			if (!atrb(Saber))
				goto destiny;
		}

	itds:
		mix(ITDS);
		if (!atrb(Shoot))
			goto itds;

	anakinsflight:
		mix(Anakinsflight);
		if (!atrb(Shoot))
			goto anakinsflight;

	anewhope:
		mix(ANewHope);
		if (logicType == casual) {
			if (!atrb(Attack) && !atrb(FakeShoot))
				goto anewhope;
			add(2); //3po
			if (!atrb(Proto))
				goto anewhope;
		} else {
			if (DoubleTransitionSkip())
				goto bhm;
			if (atrb(Attack) || atrb(FakeShoot)) {
				add(2); //3po
				if (atrb(Proto))
					goto bhm;
			}
			goto anewhope;
		}

	bhm:
		mix(BHM);
		add(2);
		add(3);
		add(4);
		add(5);

		//breaks if target is not unique
		const Playable* battledroid = nameList["battledroid"];
		const Playable* pkdroid = nameList["pkdroid"];
		const Playable* geonosian = nameList["geonosian"];
		const Playable* battledroidSecurity = nameList["battledroid_security"];
		const Playable* droideka = nameList["destroyer"];
		const Playable* cloneEp3 = nameList["clone_ep3"];
		const Playable* cody = nameList["clone_ep3_sand"];
		const Playable* cloneSwamp = nameList["clone_ep3_swamp"];
		const Playable* disguisedclone = nameList["disguisedclone"];
		const Playable* rebelengineer = nameList["engineer"];
		const Playable* rebeltrooper = nameList["rebelscum"];
		const Playable* jawa = nameList["jawa"];
		const Playable* sandtrooper = nameList["sandtrooper"];
		const Playable* mousedroid = nameList["mousedroid"];
		const Playable* stormtrooper = nameList["stormtrooper"];
		const Playable* imperialofficer = nameList["imperialofficer"];
		const Playable* snowtrooper = nameList["snowtrooper"];
		const Playable* ewok = nameList["ewok"];

		if (BHM->party[6] == battledroid)
			goto bhm;
		if (BHM->party[6] == pkdroid)
			goto bhm;
		if (BHM->party[7] == battledroid)
			goto bhm;
		if (BHM->party[8] == battledroid)
			goto bhm;
		//if (BHM->party[8] == gungan) goto bhm;
		if (BHM->party[9] == geonosian)
			goto bhm;
		//if (BHM->party[10] == kaminodroid) goto bhm;
		if (BHM->party[11] == battledroidSecurity)
			goto bhm;
		if (BHM->party[12] == battledroid)
			goto bhm;
		if (BHM->party[12] == droideka)
			goto bhm;
		if (BHM->party[13] == battledroid)
			goto bhm;
		if (BHM->party[13] == cloneEp3)
			goto bhm;
		if (BHM->party[13] == cody)
			goto bhm;
		if (BHM->party[13] == cloneSwamp)
			goto bhm;
		if (BHM->party[14] == cloneEp3)
			goto bhm;
		if (BHM->party[14] == cody)
			goto bhm;
		if (BHM->party[14] == disguisedclone)
			goto bhm;
		if (BHM->party[15] == battledroid)
			goto bhm;
		if (BHM->party[16] == rebelengineer)
			goto bhm;
		if (BHM->party[16] == rebeltrooper)
			goto bhm;
		if (BHM->party[17] == jawa)
			goto bhm;
		if (BHM->party[17] == sandtrooper)
			goto bhm;
		//if (BHM->party[18] == scoundrel) goto bhm;
		if (BHM->party[18] == sandtrooper)
			goto bhm;
		if (BHM->party[19] == mousedroid)
			goto bhm;
		if (BHM->party[19] == stormtrooper)
			goto bhm;
		if (BHM->party[19] == imperialofficer)
			goto bhm;
		if (BHM->party[20] == snowtrooper)
			goto bhm;
		if (BHM->party[21] == ewok)
			goto bhm;
		//if (BHM->party[22] == civillian) goto bhm;
		if (BHM->party[22] == stormtrooper)
			goto bhm;
		//if (BHM->party[23] == civillian) goto bhm;
		if (BHM->party[23] == stormtrooper)
			goto bhm;
		if (BHM->party[24] == sandtrooper)
			goto bhm;
		if (BHM->party[25] == snowtrooper)
			goto bhm;


		if (!GunganJump())
			goto bhm;  //temp
		if (!atrb(Astro))
			goto bhm;
		if (!atrb(Proto))
			goto bhm;
		if (!atrb(Build))
			goto bhm;
		if (!atrb(Lever))
			goto bhm;
		if (!atrb(Fett) && !All({Grapple, DoubleJump}))
			goto bhm;
		if (logicType == casual) {
			if (!atrb(Fly))
				goto bhm;
		} else {
			if (!atrb(Fly) && !All({HighJump, RealDoubleJump}))
				goto bhm;
		}

		//ghost cannot be captured
		if (atrb(Ghost, BHM->bonusCharacters)) goto bhm;
	}

	for (Level* lev : allLevels) {
		for (Playable* p : lev->party) {
			p->storyMode = true;
		}
	}

	if (character) {
		std::uniform_int_distribution<int> randPlayable(0, pls.size() - 1);

	indy:
		indy = pls[randPlayable(rando)];
		if (indy->storyMode)
			goto indy;

	allMinikits:
		allMinikitsCharacter = pls[randPlayable(rando)];
		if (allMinikitsCharacter->storyMode)
			goto allMinikits;
	}

	cantina1->storyMode = true;
	cantina2->storyMode = true;
	indy->storyMode = true;

	//FILE GEN IS HERE
	fileGen();
	//FILE GEN IS HERE

	//Diverts references for nonexistent characters to dummy character so I can
	//use override said characters.
	int addresses[] = {
		0x4f13,  0x4f33,  0x4fc6,  0x1a7af, 0x29322, 0x895e9, 0xca382, 0x1de5f,
		0x31774, 0x8727a, 0x317a2, 0x317b2, 0x1f29f, 0x2d314, 0x400a6, 0x400c2,
		0x400c9, 0x400e5, 0x4005c, 0x40078, 0x400ec, 0x40108, 0x4007f, 0x317c2,
		0xb57e5, 0x87288, 0xa91ca, 0x1e3e2, 0x1e3eb, 0xa91d7, 0x40039, 0x40055
	};

	for (int address : addresses)
		numWrite(EXE, 0x7f17b8, address);

	if (collectable) {
	#ifdef _DEBUG
		wxGetApp().CallAfter([]() { wxLogStatus("Starting collectables"); });
	#endif
		int x = 1;
		auto collectableWrite = [&x, &loggingIt](Level* lev, char scene,
			std::vector<int> address) {
			std::string file = getGiz(lev, scene);
			std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
			for (int cAddress : address) {
				fs.seekg(cAddress);
				char type = fs.get();
			#ifdef _DEBUG
				if (type != 'c' && type != 'm' && type != 'r') {
					std::stringstream st;
					st << std::hex << cAddress;
					loggingIt << st.str() + " " + file + " is not a collectable.\n";
				}
			#endif
				if (type == 'c') {  //some challenge kits have the same name, which
					//breaks when changed to minikits
					hexWrite(file, "c_pup" + std::to_string(x), cAddress - 0x14);
					x++;
					if (x > 10)
						x = 1;
				}

				binaryWrite(file, lev->collectables[lev->collectables.size() - 1],
					cAddress);
				lev->collectables.pop_back();
			}
		};

		//minikits with multiple spawn points
		auto specialCollectable
			= [&x, &loggingIt](Level* lev, char scene, std::vector<int> address) {
			std::string file = getGiz(lev, scene);
			std::fstream fs(file, std::ios::in | std::ios::out | std::ios::binary);
			for (int cAddress : address) {
				fs.seekg(cAddress);
				char type = fs.get();
			#ifdef _DEBUG
				if (type != 'c' && type != 'm' && type != 'r') {
					std::stringstream st;
					st << std::hex << cAddress;
					loggingIt << st.str() + " " + file + " is not a collectable.\n";
				}
			#endif
				if (type == 'c') {  //some challenge kits have the same name, which
					//breaks when changed to minikits
					hexWrite(file, "c_pup" + std::to_string(x), cAddress - 0x14);
					x++;
					if (x > 10)
						x = 1;
				}

				binaryWrite(file, lev->collectables[lev->collectables.size() - 1],
					cAddress);
			}
			lev->collectables.pop_back();
		};

		collectableWrite(Negotiations, 'A',
			{0xa6a0, 0xa689, 0xa672, 0xa65b, 0xa644, 0xa34d, 0xa90d,
				 0xa8f6, 0xa8df, 0xa8c8});
		collectableWrite(Negotiations, 'B', {0xfc1, 0xfaa, 0xf4e, 0xf37});
		collectableWrite(Negotiations, 'C',
			{0x37c5, 0x37ae, 0x3797, 0x3780, 0x36df, 0x36c8, 0x36b1});

		collectableWrite(
			Invasion, 'A',
			{0x3665, 0x364e, 0x3637, 0x325a, 0x3243, 0x322c, 0x3215, 0x31fe});
		collectableWrite(Invasion, 'B', {0x1acc, 0x1ab5, 0x1a9e, 0x1a14, 0x1790});
		collectableWrite(Invasion, 'C',
			{0x214d, 0x2136, 0x211f, 0x1965, 0x194e, 0x1937});
		collectableWrite(Invasion, 'E', {0xab7, 0x9e8});

		collectableWrite(EscapeNaboo, 'A',
			{0x8153, 0x813c, 0x8125, 0x810e, 0x7cd5, 0x7cbe});
		collectableWrite(EscapeNaboo, 'B',
			{0x559c, 0x5585, 0x5232, 0x521b, 0x5204});
		collectableWrite(EscapeNaboo, 'C',
			{0x681d, 0x6806, 0x67ef, 0x67d8, 0x67c1, 0x67aa});
		collectableWrite(EscapeNaboo, 'E', {0x343b, 0x3424, 0x33f6, 0x33df});

		collectableWrite(Podrace, 'A',
			{0x52d4, 0x52bd, 0x52a6, 0x528f, 0x5278, 0x5261, 0x524a,
				 0x5233, 0x521c, 0x5205, 0x51ee, 0x51c0, 0x51a9, 0x5192,
				 0x517b, 0x5164, 0x514d, 0x5136, 0x511f, 0x5108, 0x50f1});

		collectableWrite(Theed, 'A', {0x36fc, 0x36e5, 0x3689, 0x3672});
		collectableWrite(Theed, 'B', {0x61be, 0x61a7, 0x6190, 0x6179});
		collectableWrite(Theed, 'D', {0x5abb, 0x5aa4, 0x5a8d, 0x559c, 0x48ac});
		collectableWrite(Theed, 'E', {0x3799, 0x327a});
		collectableWrite(Theed, 'F', {0x5f5c, 0x5f45, 0x5f2e});
		collectableWrite(Theed, 'G', {0x3473, 0x345c, 0x2938});

		collectableWrite(Maul, 'A', {0x2e7c, 0x2e65, 0x2be1, 0x2bca});
		collectableWrite(Maul, 'B',
			{0x2a4e, 0x2a37, 0x2a20, 0x2757, 0x2740, 0x2449, 0x1531});
		collectableWrite(Maul, 'D', {0x1a95, 0x1a67, 0x1a50, 0x1a39, 0x193c});
		collectableWrite(Maul, 'E', {0x18bc});
		collectableWrite(Maul, 'F', {0xe76, 0xe1a, 0xe03, 0xdec});

		collectableWrite(BHP, 'A',
			{0x58b2, 0x589b, 0x5884, 0x586d, 0x5856, 0x5759});
		specialCollectable(BHP,
			'A',  //Stupid Minikit
			{0x583f, 0x5828, 0x5811, 0x57fa, 0x57e3});
		specialCollectable(BHP,
			'A',  //turrets
			{0x57cc, 0x57b5, 0x579e, 0x5787, 0x5770});
		collectableWrite(BHP, 'B', {0x1251, 0x123a});
		collectableWrite(BHP, 'C',
			{0x4379, 0x4362, 0x434b, 0x4334, 0x431d, 0x4293, 0x4220});
		specialCollectable(BHP,
			'C',  //turrets
			{0x4306, 0x42ef, 0x42d8, 0x42c1, 0x42aa});
		collectableWrite(BHP, 'D', {0x26aa, 0x2693});

		//banners
		std::vector<int> roomA = {0x5742, 0x572b, 0x5714, 0x56fd, 0x56e6, 0x56cf};
		std::vector<int> roomB = {0x427c, 0x4265, 0x424e, 0x4237};
		std::string bhpFile = getGiz(BHP, 'A');
		std::fstream fs(bhpFile, std::ios::in | std::ios::out | std::ios::binary);
		for (int cAddress : roomA) {
			fs.seekg(cAddress);
			char type = fs.get();
			binaryWrite(bhpFile, BHP->collectables[BHP->collectables.size() - 1],
				cAddress);
		}
		bhpFile = getGit(BHP, 'C');
		for (int cAddress : roomB) {
			fs.seekg(cAddress);
			char type = fs.get();
			binaryWrite(bhpFile, BHP->collectables[BHP->collectables.size() - 1],
				cAddress);
		}
		fs.close();

		BHP->collectables.pop_back();

		collectableWrite(Kamino, 'A', {0x1f52, 0x1f3b, 0x1781, 0x1542});
		collectableWrite(Kamino, 'C', {0x3ce1, 0x3cca, 0x3bfb, 0x3be4, 0x3bcd});
		collectableWrite(Kamino, 'D',
			{0x51dc, 0x51c5, 0x51ae, 0x5055, 0x503e, 0x5027});
		collectableWrite(Kamino, 'E', {0x315a, 0x2e63});
		collectableWrite(Kamino, 'F', {0x2235, 0x221e, 0x2024, 0x200d});

		collectableWrite(Factory, 'A', {0xB33, 0xb1c, 0x825});
		collectableWrite(Factory, 'B', {0x2f68, 0x2f51, 0x2f3a, 0x280a, 0x27f3});
		collectableWrite(Factory, 'D', {0x184e, 0x1837, 0x12bc, 0x12a5});
		collectableWrite(Factory, 'E', {0xf93, 0xc9c});
		collectableWrite(Factory, 'F',
			{0x1c47, 0x1c30, 0x1c19, 0x1265, 0x124e, 0x1a4d});
		collectableWrite(Factory, 'G', {0x1531});

		collectableWrite(JediBattle, 'B',
			{0x5099, 0x5082, 0x506b, 0x5054, 0x503d, 0x5026, 0x500f,
				 0x4ff8, 0x4fe1, 0x4fca, 0x4fb3, 0x4de7, 0x4c8e, 0x4c60,
				 0x4c04, 0x4bed, 0x4bd6, 0x4bbf, 0x4ba8, 0x4b91, 0x4b7a});

		collectableWrite(Gunship, 'A',
			{0x2332, 0x231b, 0x2304, 0x22ed, 0x22d6, 0x22bf, 0x22a8,
				 0x2291, 0x227a, 0x2263, 0x224c, 0x2235, 0x221e});
		collectableWrite(
			Gunship, 'B',
			{0x21ea, 0x21d3, 0x21bc, 0x21a5, 0x218e, 0x2177, 0x2160, 0x2149});

		collectableWrite(Dooku, 'B',
			{0x2245, 0x222e, 0x2217, 0x2200, 0x21e9, 0x1f20, 0x1f09,
				 0x1ef2, 0x1edb, 0x1ec4, 0x1ead});
		collectableWrite(Dooku, 'C',
			{0x2063, 0x204c, 0x2035, 0x201e, 0x2007, 0x1ff0, 0x1d27,
				 0x1d10, 0x1cf9, 0x1ce2});

		//allows spinners to work in challenge mode
		deleteLines(getGit(Coruscant, 'A'),
			{274, 302, 330, 358, 386, 414, 442, 470, 498, 526});
		collectableWrite(Coruscant, 'A',
			{0x2cbc, 0x2ca5, 0x2c8e, 0x2c77, 0x2c60, 0x2c49, 0x2c32,
				 0x2c1b, 0x2c04, 0x2bed, 0x2bd6, 0x2bbf, 0x2ba8, 0x2b91,
				 0x2b7a, 0x2b63, 0x2b4c, 0x2b35, 0x2b1e, 0x2b07, 0x2af0});

		collectableWrite(Chancellor, 'A', {0x1bfb, 0x1be4, 0x1bcd});
		collectableWrite(Chancellor, 'B',
			{0x15c0, 0x15a9, 0x1592, 0x11e3, 0x11cc, 0x11b5, 0x119e});
		collectableWrite(Chancellor, 'C', {0x1050, 0x1039, 0xd14});
		collectableWrite(Chancellor, 'D', {0x335d});
		collectableWrite(Chancellor, 'E', {0xeba, 0xda6});
		collectableWrite(Chancellor, 'F', {0x7dd, 0x3a4, 0x38d});
		collectableWrite(Chancellor, 'G', {0x10f9, 0xe75});

		collectableWrite(Grievous, 'A',
			{0x3a2a, 0x3a13, 0x39fc, 0x39e5, 0x39ce, 0x39b7, 0x39a0,
				 0x3989, 0x3972, 0x395b, 0x3944, 0x392d, 0x37bd, 0x3636,
				 0x361f, 0x3608, 0x35f1, 0x35da, 0x35c3, 0x35ac, 0x3595});

		//allows carrot camerapan to work in challenge mode
		deleteLines(getGit(Kashyyyk, 'B'), {170});
		collectableWrite(Kashyyyk, 'A',
			{0x6157, 0x6140, 0x6129, 0x6112, 0x5fb9, 0x5dd6, 0x5dbf});
		collectableWrite(Kashyyyk, 'B', {0x3374, 0x335d, 0x3346, 0x3204});
		specialCollectable(Kashyyyk,
			'B',  //carrots
			{0x33a2, 0x338b, 0x31ed});
		collectableWrite(Kashyyyk, 'C', {0x2d28, 0x2d11, 0x2cfa});
		collectableWrite(Kashyyyk, 'D',
			{0x41e1, 0x41ca, 0x41b3, 0x419c, 0x4185, 0x416e});

		collectableWrite(Ruin, 'A',
			{0x5330, 0x5319, 0x5302, 0x517b, 0x5164, 0x514d});
		collectableWrite(Ruin, 'B',
			{0x420b, 0x41f4, 0x41dd, 0x413c, 0x4125, 0x410e});
		collectableWrite(Ruin, 'C',
			{0x5221, 0x520a, 0x51f3, 0x51dc, 0x5197, 0x5180, 0x382a,
				 0x3813, 0x37fc});

		collectableWrite(Vader, 'A',
			{0x47b3, 0x479c, 0x4785, 0x476e, 0x452f, 0x41f3, 0x41dc,
				 0x41c5, 0x41ae, 0x4197});
		collectableWrite(Vader, 'B', {0x187a, 0x1863, 0x1624, 0x160d});
		collectableWrite(Vader, 'C',
			{0x28b2, 0x2884, 0x286d, 0x2856, 0x1ffb, 0x1fe4, 0x1fcd});

		//fixes camera pan in challenge
		deleteLines(getGit(SecretPlans, 'B'), {1830});
		collectableWrite(SecretPlans, 'A', {0x6d3f, 0x6d28, 0x6d11, 0x6cfa});
		collectableWrite(SecretPlans, 'B',
			{0x11033, 0x1101c, 0x11005, 0x10fee, 0x10eac, 0x10e95,
				 0x10e7e, 0x10e67});
		specialCollectable(SecretPlans,
			'B',  //grapes
			{0x11078, 0x11061, 0x1104a});
		collectableWrite(SecretPlans, 'C',
			{0x3fc0, 0x3fa9, 0x3f92, 0x3f7b, 0x3ae6});
		collectableWrite(SecretPlans, 'D', {0x4b1e, 0x4af0});
		specialCollectable(SecretPlans,
			'D',  //flowers
			{0x4b4c, 0x4b35, 0x4b07});

		collectableWrite(Jundland, 'A',
			{0x7220, 0x7209, 0x71f2, 0x71db, 0x71c4, 0x71ad, 0x7196});
		collectableWrite(Jundland, 'B', {0x7ced, 0x7cd6, 0x7cbf, 0x7ca8});
		collectableWrite(Jundland, 'C', {0x6907, 0x68f0, 0x68d9, 0x68c2, 0x68ab});
		collectableWrite(Jundland, 'D', {0x3a14, 0x39fd, 0x39e6});
		collectableWrite(Jundland, 'E', {0x4ad2, 0x4abb});

		deleteLines(getGit(Spaceport, 'A'), {2228});
		deleteLines(getGit(Spaceport, 'D'), {1430});

		collectableWrite(Spaceport, 'A', {0x80d9, 0x80c2, 0x80ab, 0x6eb3, 0x6e57});
		specialCollectable(Spaceport,
			'A',  //carrots
			{0x6e9c, 0x6e85, 0x6e6e});
		collectableWrite(Spaceport, 'B', {0x672b, 0x6714, 0x66fd, 0x66e6, 0x5f43});
		collectableWrite(Spaceport, 'C', {0x2ccc, 0x2cb5});
		collectableWrite(Spaceport, 'D', {0x9f93, 0x9f7c, 0x9f65, 0x9f4e, 0x9f37});
		specialCollectable(Spaceport,
			'D',  //turnips
			{0x8c2b, 0x8c14, 0x8bfd});
		collectableWrite(Spaceport, 'E', {0x3564, 0x354d});

		collectableWrite(Princess, 'A', {0x2ecf, 0x2eb8, 0x2ea1, 0x2e8a});
		collectableWrite(Princess, 'B',
			{0x4f48, 0x4f31, 0x4f1a, 0x4f03, 0x4e79, 0x4e62, 0x4e4b,
				 0x4e34, 0x3f4a});
		collectableWrite(Princess, 'C',
			{0x50bf, 0x50a8, 0x5091, 0x507a, 0x5063, 0x504c, 0x5035});
		collectableWrite(Princess, 'D', {0x4e4});

		collectableWrite(DSE, 'A', {0x2834, 0x281d, 0x2806, 0x27ef});
		collectableWrite(DSE, 'B',
			{0x2fe7, 0x2fd0, 0x2fb9, 0x2fa2, 0x2f8b, 0x2ffe});
		collectableWrite(DSE, 'C',
			{0x474a, 0x4733, 0x471c, 0x4705, 0x46ee, 0x4567, 0x4550,
				 0x4539, 0x4522});
		collectableWrite(DSE, 'D', {0x746, 0x72f});

		collectableWrite(RebelAttack, 'A',
			{0x46b0, 0x4699, 0x4682, 0x466b, 0x4654, 0x463d, 0x4626});
		collectableWrite(RebelAttack, 'B',
			{0x6fb0, 0x6f99, 0x6f82, 0x6f6b, 0x6f54, 0x6f3d, 0x6f26});
		collectableWrite(RebelAttack, 'C', {0x477b, 0x4764, 0x474d});
		collectableWrite(RebelAttack, 'D', {0x21e1, 0x21ca, 0x21b3, 0x219c});

		collectableWrite(Hoth, 'A', {0x2ff9, 0x2fe2, 0x2fcb, 0x2fb4, 0x2f9d});
		collectableWrite(Hoth, 'B', {0x1148, 0x1131});
		collectableWrite(Hoth, 'C', {0x53e5, 0x53ce, 0x53b7, 0x53a0});
		collectableWrite(Hoth, 'D',
			{0x3120, 0x3109, 0x30f2, 0x30db, 0x30c4, 0x30ad});
		collectableWrite(Hoth, 'E', {0x1786, 0x176f, 0x1758, 0x1741});

		collectableWrite(EchoBase, 'A',
			{0x4d85, 0x4d6e, 0x4d57, 0x4d40, 0x4d29, 0x4d12});
		collectableWrite(EchoBase, 'B',
			{0x44f7, 0x44e0, 0x44c9, 0x44b2, 0x449b, 0x3d54, 0x3d3d});
		collectableWrite(EchoBase, 'C',
			{0x48ca, 0x48b3, 0x489c, 0x4885, 0x486e, 0x4857, 0x3d78});
		collectableWrite(EchoBase, 'D', {0x2c7});

		collectableWrite(FalconFlight, 'A',
			{0x260f, 0x25f8, 0x25e1, 0x25ca, 0x25b3, 0x259c, 0x2585});
		collectableWrite(
			FalconFlight, 'B',
			{0x4a01, 0x49ea, 0x49d3, 0x49bc, 0x49a5, 0x498e, 0x4977, 0x4960});
		collectableWrite(FalconFlight, 'C', {0x1617, 0x1600, 0x15e9});
		collectableWrite(FalconFlight, 'D', {0x573, 0x55c, 0x545});

		collectableWrite(Dagobah, 'A', {0x4648, 0x4631, 0x461a, 0x4603, 0x45ec});
		collectableWrite(Dagobah, 'B', {0x3015, 0x2ffe, 0x2fd0, 0x2fb9});
		collectableWrite(Dagobah, 'C', {0x4ff9, 0x4fe2, 0x4fcb});
		collectableWrite(Dagobah, 'D',
			{0x436b, 0x4354, 0x433d, 0x4326, 0x430f, 0x42f8});
		collectableWrite(Dagobah, 'E', {0x6865, 0x684e});
		specialCollectable(Dagobah,
			'E',  //circle things
			{0x6893, 0x687c, 0x6837});

		collectableWrite(CCT, 'A',
			{0x1f65, 0x1f4e, 0x1f37, 0x1f20, 0x1f09, 0x1ef2, 0x1edb});
		collectableWrite(
			CCT, 'B',
			{0x13db, 0x13c4, 0x13ad, 0x1396, 0x137f, 0x133a, 0x130c, 0x12f5});
		collectableWrite(CCT, 'C',
			{0x163d, 0x1626, 0x15f8, 0x15e1, 0x15ca, 0x160f});

		collectableWrite(Bespin, 'A',
			{0x4e34, 0x4e06, 0x4def, 0x4dd8, 0x4dc1, 0x4daa, 0x4d7c,
				 0x4d65, 0x4d4e});
		collectableWrite(Bespin, 'B', {0x14f, 0xdc});
		collectableWrite(Bespin, 'C',
			{0x434c, 0x4335, 0x431e, 0x4307, 0x42f0, 0x424f, 0x4238,
				 0x4221, 0x420a});
		//TOWERS
		roomA = {0x4d37, 0x4d93};
		roomB = {0x41f3};
		bhpFile = getGiz(Bespin, 'A');
		fs.open(bhpFile, std::ios::in | std::ios::out | std::ios::binary);
		for (int cAddress : roomA) {
			fs.seekg(cAddress);
			char type = fs.get();
			binaryWrite(bhpFile,
				Bespin->collectables[Bespin->collectables.size() - 1],
				cAddress);
		}
		bhpFile = getGiz(Bespin, 'C');
		for (int cAddress : roomB) {
			fs.seekg(cAddress);
			char type = fs.get();
			binaryWrite(bhpFile,
				Bespin->collectables[Bespin->collectables.size() - 1],
				cAddress);
		}
		fs.close();
		Bespin->collectables.pop_back();

		collectableWrite(Jabbas, 'A',
			{0x4314, 0x42fd, 0x42e6, 0x42cf, 0x42b8, 0x42a1, 0x428a,
				 0x4273, 0x425c});
		collectableWrite(Jabbas, 'B',
			{0x7a38, 0x7a21, 0x7a0a, 0x79f3, 0x79dc, 0x79c5});
		collectableWrite(Jabbas, 'D', {0x303a, 0x3023, 0x300c, 0x2ff5});
		collectableWrite(Jabbas, 'E', {0x9bd, 0x9a6});

		collectableWrite(Carkoon, 'A',
			{0xadb2, 0xad9b, 0xad84, 0xad6d, 0xad56, 0xad3f, 0xad28,
				 0xad11, 0xacfa});
		collectableWrite(Carkoon, 'B', {0x5a7a, 0x5a63, 0x5a4c, 0x5a35, 0x5a1e});
		collectableWrite(Carkoon, 'C',
			{0x6e0b, 0x6df4, 0x6ddd, 0x6dc6, 0x6daf, 0x6d98, 0x6d81});

		collectableWrite(
			Showdown, 'A',
			{0x10864, 0x1084d, 0x10836, 0x1081f, 0x10808, 0x107f1, 0x107da,
			 0x107c3, 0x107ac, 0x10795, 0x1077e, 0x10767, 0x10750, 0x10739,
			 0x10722, 0x1070b, 0x106f4, 0x106dd, 0x106c6, 0x106af, 0x10698});

		collectableWrite(Endor, 'A',
			{0x79f4, 0x79dd, 0x79c6, 0x79af, 0x796a, 0x7953, 0x793c});
		collectableWrite(Endor, 'B', {0xa703, 0xa6ec, 0xa6d5, 0xa6be, 0xa6a7});
		collectableWrite(Endor, 'C', {0x6ae3, 0x6acc, 0x6ab5, 0x6a9e, 0x6a87});
		collectableWrite(Endor, 'D', {0xa9b7, 0xa9a0, 0xa972, 0xa95b});

		collectableWrite(
			Destiny, 'A',
			{0xc7d7, 0xc7c0, 0xc7a9, 0xc792, 0xc77b, 0xc764, 0xc74d, 0xc736, 0xc71f,
			 0xc708, 0xc6f1, 0xc6da, 0xc6c3, 0xb669, 0xb652});
		collectableWrite(Destiny, 'B',
			{0x3c13, 0x3bfc, 0x3be5, 0x3bce, 0x3b44, 0x3b2d});

		collectableWrite(ITDS, 'A', {0xd9c, 0xd85, 0xd6e, 0xd57});
		collectableWrite(ITDS, 'B', {0x34b2, 0x349b, 0x3484, 0x346d});
		collectableWrite(ITDS, 'C', {0x103a, 0x1023, 0x100c, 0xff5});
		collectableWrite(ITDS, 'D', {0x1f1b, 0x1f04, 0x1eed});
		collectableWrite(ITDS, 'E', {0x1dae, 0x1d97});
		collectableWrite(ITDS, 'F', {0x1f3f, 0x1f28});
		collectableWrite(ITDS, 'G', {0x30bc, 0x30a5});

	#ifdef _DEBUG
		for (int i = 0; i < 36; i++) {
			if (allLevels[i]->collectables.size() > 0) {
				loggingIt << allLevels[i]->name + " has " +
					std::to_string(allLevels[i]->collectables.size()) +
					" collectables left.\n";
			}
		}
	#endif

		loggingIt.close();
	}

	if (extra) {
	#ifdef _DEBUG
		wxGetApp().CallAfter([] { wxLogStatus("Starting extras"); });

	#endif
		int lines[] = {39,  57,  75,  88,  128, 144, 195, 214, 233, 246, 259, 286,
									 332, 351, 363, 377, 392, 406, 468, 485, 505, 523, 540, 562,
									 615, 632, 652, 669, 684, 700, 749, 764, 777, 793, 806, 829};

		for (unsigned int i = 0; i < extras.size(); i++) {
			txtIns(LEV + "AREAS.TXT", extras[i], {{lines[i], 18}}, vanillaExtras[i].length());
		}
	}

	//Patches levels with new characters
	if (character) {
	#ifdef _DEBUG
		wxGetApp().CallAfter([] { wxLogStatus("Patching Levels"); });

	#endif
			//pointerWrite(EXE, cantina1->name, 0x3f1c30);
			//pointerWrite(EXE, cantina2->name, 0x3f1c38);
		characterPointer(cantina1, 0xca35a);
		characterPointer(cantina2, 0xca360);

		Negotiations->replace(0, {{1, 12}});
		Negotiations->replace(1, {{2, 12}});
		Negotiations->replace(2, {{3, 12}});
		Negotiations->replace(2, {{18, 22}}, 'A', "LEVEL.SCP");
		Negotiations->replace(2, {{17, 22}, {21, 22}, {40, 22}}, 'A', "LEVEL1.SCP");
		//stops tc from going to panel
		Negotiations->replace("alwaystrue", 26, {{35, 6}}, 'A', "TC14.SCP");
		deleteLines(Negotiations->directory('A', "TC14.SCP"), {39});

		Negotiations->replace(2, {{5}}, 'A', "SCRIPT.TXT");
		Negotiations->rename(2, 'A');

		Invasion->replace(0, {{1, 12}});
		Invasion->replace(1, {{2, 12}});
		Invasion->replace(2, {{3, 12}});
		Invasion->replace(2, {2}, 'A', "SCRIPT.TXT");
		Invasion->rename(2, 'A');
		std::remove(
			(out + "/LEVELS/EPISODE_I/GUNGAN/GUNGAN_B/AI/JARJARBINKS.SCP").c_str());

		EscapeNaboo->replace(0, {{1, 12}});
		EscapeNaboo->replace(1, {{2, 12}});
		EscapeNaboo->replace(2, {{3, 12}});
		EscapeNaboo->replace(3, {{4, 12}});
		EscapeNaboo->replace("if IAm \"" + EscapeNaboo->party[0]->name +
			"\" == 1 goto Activate\n\t\tif IAm \"" +
			EscapeNaboo->party[1]->name +
			"\" == 1 goto Activate",
			39, {{5, 3}}, 'A', "PARTY.SCP");
		EscapeNaboo->replace("if IAm \"" + EscapeNaboo->party[0]->name +
			"\" == 1 goto Activate\n\t\tif IAm \"" +
			EscapeNaboo->party[1]->name +
			"\" == 1 goto Activate",
			39, {{5, 3}}, 'B', "PARTY.SCP");
		EscapeNaboo->replace(2, {{17, 26}}, 'B', "LEVEL.SCP");
		EscapeNaboo->replace(3, {{16, 26}}, 'B', "LEVEL.SCP");
		EscapeNaboo->replace(2, {{26, 28}}, 'C', "LEVEL.SCP");
		EscapeNaboo->replace(3, {{25, 28}}, 'C', "LEVEL.SCP");

		Podrace->replace(0, {{1, 12}});
		Podrace->replace(1, {{2, 12}});

		//fixes scaling problem
		binaryWrite(EXE, 0x0f, 0xB5129);
		binaryWrite(EXE, 0x0f, 0x35946);

		Theed->replace(0, {{1, 12}});
		Theed->replace(1, {{2, 12}});
		Theed->replace(2, {{3, 12}});
		Theed->replace(3, {{4, 12}});
		Theed->replace(4, {{5, 12}});
		Theed->replace(5, {{6, 12}});
		Theed->replace(2, {{20, 25}, {21, 28}}, 'A', "LEVEL.SCP");
		Theed->replace(3, {{18, 25}, {19, 28}}, 'A', "LEVEL.SCP");
		Theed->replace(4, {{24, 25}, {25, 28}}, 'A', "LEVEL.SCP");
		Theed->replace(5, {{22, 25}, {23, 28}}, 'A', "LEVEL.SCP");

		Maul->replace(0, {{1, 12}});
		Maul->replace(1, {{2, 12}});
		Maul->replace(0, {{381, 21}}, 'F', "DARTHMAUL.SCP");
		//fixes ditto problem
		Maul->replace("dmaul", 9, {1}, 'A', "SCRIPT.TXT");
		Maul->replace("dmaul", 9, {1}, 'D', "SCRIPT.TXT");
		Maul->replace("dmaul", 9, {2}, 'E', "SCRIPT.TXT");
		Maul->replace("dmaul", 9, {2}, 'F', "SCRIPT.TXT");
		Maul->binWrite("dmaul", {0x26AE}, 'A', "MAUL_A.AI2");
		Maul->binWrite("dmaul", {0x307B}, 'D', "MAUL_D.AI2");
		Maul->binWrite("dmaul", {0x6F9}, 'E', "MAUL_E.AI2");
		Maul->binWrite("dmaul", {0x96B}, 'F', "MAUL_F.AI2");
		Maul->rename("dmaul.scp", "DARTHMAUL.SCP", 'A');
		Maul->rename("dmaul.scp", "DARTHMAUL.SCP", 'D');
		Maul->rename("dmaul.scp", "DARTHMAUL.SCP", 'E');
		Maul->rename("dmaul.scp", "DARTHMAUL.SCP", 'F');

		BHP->replace(0, {{1, 12}});
		BHP->replace(1, {{2, 12}});

		Kamino->replace(0, {{1, 12}});
		Kamino->replace(1, {{2, 12}});
		Kamino->replace(0, {{47, 28}, {83, 28}}, 'C', "LEVEL.SCP");
		Kamino->replace(1, {{48, 28}, {84, 28}}, 'C', "LEVEL.SCP");
		//ditto
		Kamino->replace("ai_jango", 8, {1}, 'C', "SCRIPT.TXT");
		Kamino->binWrite("ai_jango", {0x1AFA}, 'C', "KAMINO_C.AI2");
		Kamino->rename("ai_jango.scp", "JANGOFETT.SCP", 'C');

		Factory->replace(0, {{1, 12}});
		Factory->replace(1, {{2, 12}});
		Factory->replace(2, {{3, 12}});
		Factory->replace(3, {{4, 12}});
		Factory->replace(4, {{10, 12}});
		Factory->replace("if CategoryIs \"Astromech\" == 1", 18, {{12, 3}}, 'D',
			"PARTY.SCP");
		Factory->replace("if CategoryIs \"Astromech\" == 1", 18, {{12, 3}}, 'E',
			"PARTY.SCP");

		/*
		if (!Proto({ Factory->party[3] })) Factory->replace("1", 3, { {34, 17} },
		'E', "C3PO.SCP"); Factory->replace("\t\tif CategoryIs \"Protocol\" == 1 goto
		ProtoUpdate\n", 0, { {12, 1} }, 'E', "PARTY.SCP"); Factory->append( "state
		ProtoUpdate {\n"
						"\tConditions {\n"
						"\t}\n"
						"\tActions {\n"
						"\t\tFollowPlayer \"0.5\"\n"
						"\t}\n"
						"}",

						'E', "PARTY.SCP");*/

		Factory->replace("if CategoryIs \"noweapon\" == 1", 18, {{13, 3}}, 'F',
			"PARTY.SCP");
		deleteLines(Factory->directory('F', "PARTY.SCP"), {14});
		Factory->replace(2, {2}, 'A', "SCRIPT.TXT");
		Factory->replace(3, {3}, 'A', "SCRIPT.TXT");

		Factory->replace(2, {2}, 'B', "SCRIPT.TXT");
		Factory->replace(3, {3}, 'B', "SCRIPT.TXT");

		Factory->replace(3, {1}, 'D', "SCRIPT.TXT");
		Factory->replace(3, {2}, 'E', "SCRIPT.TXT");

		Factory->rename(2, 'A');
		Factory->rename(2, 'B');

		Factory->rename(3, 'A');
		Factory->rename(3, 'B');
		Factory->rename(3, 'D');

		Factory->rename(3, 'E');
		//Makes sure protocol droid follows you onto the turn things
		/*{
						int turn = GetType(3, Proto, Factory->party);
						Factory->rename(turn, 'E');

		}*/

		//these two don't follow
		auto uLength = [](int ch, int address) {
			std::string name = Factory->party[ch]->name;
			char c = name.length() + 1;
			//binaryWrite(Factory->directory('E', "FACTORY_E.AI2"), c, address - 1);
			std::fstream fs(Factory->directory('E', "FACTORY_E.AI2"),
				std::ios::in | std::ios::out);
			fs.seekp(address - 1);
			fs << c;

			fs.seekp(address);
			//fs.write(name.c_str(), name.length());
			unsigned int i = 0;
			while (i < name.length()) {
				fs.seekp(address + i);
				fs << char(name[i]);

				i++;
			}
			fs.seekp(address + 1);
			fs << '\0';
		};
		//uLength(1, 0x181a);
		//uLength(2, 0x143d);

		//Factory->binWrite(1, { 0x181A }, 'E', "FACTORY_E.AI2");
		//Factory->binWrite(2, { 0x143D }, 'E', "FACTORY_E.AI2");

		Factory->binWrite(4, {0x972}, 'G', "FACTORY_G.AI2");
		characterPointer(Factory->party[4], 0xE010F);

		JediBattle->replace(0, {{1, 12}});
		JediBattle->replace(1, {{2, 12}});
		JediBattle->replace(2, {{3, 12}, {8, 12}});   //obiwan
		JediBattle->replace(3, {{4, 12}, {9, 12}});   //anakin
		JediBattle->replace(4, {{5, 12}, {10, 12}});  //padme
		JediBattle->replace(2, {{15, 11}, {31, 11}}, 'B', "PARTY.SCP");
		JediBattle->replace(3, {{11, 11}, {26, 11}}, 'B', "PARTY.SCP");
		JediBattle->replace(4, {{7, 11}, {21, 11}}, 'B', "PARTY.SCP");
		JediBattle->replace(4, {{7, 45}}, 'B', "LEVEL.SCP");

		multiPointer(JediBattle->party[2], {0xDFABF, 0x3fffa4});
		multiPointer(JediBattle->party[3], {0xDFAAB, 0x3fffa0});
		multiPointer(JediBattle->party[4], {0xDFA98, 0x3fff9c});
		//fixes green saber
		//binaryWrite(EXE, 0x0f, 0x190E6);

		Gunship->replace(0, {{1, 12}});
		Gunship->replace(1, {{2, 12}});

		Dooku->replace(0, {{1, 12}});  //obiwan
		Dooku->replace(1, {{2, 12}});  //anakin
		Dooku->replace(2, {{3, 12}});  //yoda
		Dooku->replace(0, {{209, 45}}, 'C', "DOOKU.SCP");
		Dooku->replace(1, {{207, 26}, {214, 29}}, 'C', "DOOKU.SCP");
		Dooku->replace(2, {{208, 43}}, 'C', "DOOKU.SCP");
		Dooku->replace(2, {{6, 11}}, 'C', "PARTY.SCP");
		Dooku->replace(2, {{18, 11}}, 'B', "PARTY.SCP");

		Coruscant->replace(0, {{1, 12}});
		Coruscant->replace(1, {{2, 12}});

		Chancellor->replace(0, {{1, 12}});
		Chancellor->replace(1, {{2, 12}});
		Chancellor->replace(2, {{3, 12}});  //r2
		Chancellor->replace(3, {{4, 12}});  //palpatine
		Chancellor->replace(0, {{29, 28}}, 'C', "DOOKU.SCP");
		Chancellor->replace(1, {{28, 28}}, 'C', "DOOKU.SCP");
		Chancellor->replace(2, {{38, 74}}, 'B', "R2D2.SCP");

		Chancellor->replace(2, {1}, 'A', "SCRIPT.TXT");
		Chancellor->replace(2, {1}, 'B', "SCRIPT.TXT");
		Chancellor->replace(2, {2}, 'C', "SCRIPT.TXT");
		Chancellor->replace(2, {2}, 'G', "SCRIPT.TXT");

		Chancellor->replace(3, {4}, 'A', "SCRIPT.TXT");
		Chancellor->replace(3, {4}, 'B', "SCRIPT.TXT");
		Chancellor->replace(3, {4}, 'C', "SCRIPT.TXT");
		Chancellor->replace(3, {3}, 'G', "SCRIPT.TXT");

		if (!Astro({Chancellor->party[2]}))
			Chancellor->replace("ReferenceScript", 16, {{1, 1}}, 'B', "R2D2.SCP");

		std::ofstream party(Chancellor->directory('B', "PARTY.SCP"));
		party << "state Base {\n"
			<< "\tConditions {\n"
			<< "\t\tif FreePlay == 1 goto NormalUpdate\n"
			<< "\t\tif CategoryIs \"Astromech\" == 1 goto PanelUpdate\n"
			<< "\t\tif AlwaysTrue == 1 goto NormalUpdate\n"
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
		Chancellor->append("party", 'B', "SCRIPT.TXT");
		Chancellor->rename(2, 'A');
		Chancellor->rename(2, 'B');
		Chancellor->rename(2, 'C');
		Chancellor->rename(2, 'G');

		Chancellor->rename(3, 'A');
		Chancellor->rename(3, 'B');
		Chancellor->rename(3, 'C');
		Chancellor->rename(3, 'G');

		Chancellor->replace("if Freeplay == 1 and\n", 0, {{22, 3}, {23, 3}}, 'D',
			"PARTY.SCP");  //test

		Grievous->replace(0, {{1, 12}});
		Grievous->replace(1, {{2, 12}});
		//fixes ditto problem
		Grievous->replace("ai_griev", 8, {3}, 'A', "SCRIPT.TXT");
		Grievous->binWrite("ai_griev", {0x472D}, 'A', "GRIEVOUS_A.AI2");
		Grievous->rename("ai_griev.scp", "GRIEVOUS.SCP", 'A');

		Kashyyyk->replace(0, {{1, 12}});
		Kashyyyk->replace(1, {{2, 12}});
		Kashyyyk->replace(0, {{44, 28}}, 'A', "LEVEL.SCP");
		Kashyyyk->replace(1, {{45, 28}}, 'A', "LEVEL.SCP");

		Ruin->replace(0, {{1, 12}});
		Ruin->replace(1, {{2, 12}});

		Vader->replace(0, {{1, 12}});
		Vader->replace(1, {{2, 12}});
		Vader->replace("//", 0, {37}, 'C', "PARTY.SCP");

		SecretPlans->replace(0, {{3, 12}});  //leia
		SecretPlans->replace(1, {{4, 12}});  //antilles
		SecretPlans->replace(2, {{5, 12}});  //friend
		SecretPlans->replace(3, {{6, 12}});  //3po
		SecretPlans->replace(4, {{7, 12}});  //r2

		SecretPlans->replace(0, {{23, 11}}, 'A', "PARTY.SCP");
		SecretPlans->replace(1, {{26, 11}}, 'A', "PARTY.SCP");
		SecretPlans->replace(2, {{29, 11}, {14, 11}}, 'A', "PARTY.SCP");
		SecretPlans->replace(3, {{17, 11}}, 'A', "PARTY.SCP");
		SecretPlans->replace(4, {{20, 11}}, 'A', "PARTY.SCP");

		SecretPlans->replace(0, {{23, 11}}, 'B', "PARTY.SCP");
		SecretPlans->replace(1, {{26, 11}}, 'B', "PARTY.SCP");
		SecretPlans->replace(2, {{29, 11}, {14, 11}}, 'B', "PARTY.SCP");
		SecretPlans->replace(3, {{17, 11}}, 'B', "PARTY.SCP");
		SecretPlans->replace(4, {{20, 11}}, 'B', "PARTY.SCP");

		SecretPlans->replace(0, {{7, 11}, {10, 11}}, 'C', "PARTY.SCP");
		SecretPlans->replace(2, {{34, 11}}, 'C', "PARTY.SCP");
		SecretPlans->replace(3, {{28, 11}, {53, 11}}, 'C',
			"PARTY.SCP");  //use categoryis for {53, 11}
		SecretPlans->replace(4, {{31, 11}}, 'C', "PARTY.SCP");

		SecretPlans->replace(0, {{38, 26}}, 'D', "PARTY.SCP");
		SecretPlans->replace(1, {{8, 11}}, 'D', "PARTY.SCP");
		SecretPlans->replace(2, {{9, 11}}, 'D', "PARTY.SCP");
		SecretPlans->replace(3, {{6, 11}}, 'D', "PARTY.SCP");
		SecretPlans->replace(4, {{7, 11}}, 'D', "PARTY.SCP");

		SecretPlans->replace(0, {{53, 26}, {54, 25}}, 'C', "LEVEL.SCP");
		SecretPlans->replace(3, {{21, 22}, {36, 27}, {37, 27}, {38, 29}}, 'C',
			"LEVEL.SCP");
		SecretPlans->replace(4, {{49, 27}, {50, 27}, {51, 29}}, 'C', "LEVEL.SCP");

		SecretPlans->replace(2, {{34, 25}}, 'C', "LIFT_TROOPER.SCP");

		Jundland->replace(0, {{3, 12}});  //luke
		Jundland->replace(1, {{4, 12}});  //ben
		Jundland->replace(2, {{5, 12}});  //3po
		Jundland->replace(3, {{6, 12}});  //r2

		Jundland->replace(0, {{51, 23}}, 'A', "LEVEL.SCP");
		Jundland->replace(1, {{52, 23}}, 'A', "LEVEL.SCP");
		Jundland->replace(2, {{54, 26}}, 'A', "LEVEL.SCP");
		Jundland->replace(3, {{55, 26}}, 'A', "LEVEL.SCP");

		Jundland->replace(2, {{16, 11}}, 'A', "PARTY.SCP");
		Jundland->replace(3, {{17, 11}}, 'A', "PARTY.SCP");

		Jundland->replace(2, {{6, 11}}, 'B', "PARTY.SCP");
		Jundland->replace(3, {{9, 11}}, 'B', "PARTY.SCP");

		Jundland->replace(2, {{6, 11}, {9, 11}, {32, 11}}, 'D', "PARTY.SCP");
		Jundland->replace(3, {{7, 11}, {12, 11}, {35, 11}}, 'D', "PARTY.SCP");

		Spaceport->replace(0, {{1, 12}});  //luke
		Spaceport->replace(1, {{2, 12}});  //ben
		Spaceport->replace(2, {{3, 12}});  //r2
		Spaceport->replace(3, {{4, 12}});  //3po
		Spaceport->replace(4, {{5, 12}});  //han
		Spaceport->replace(5, {{6, 12}});  //chewie

		Spaceport->replace(0, {{8, 11}}, 'A', "PARTY.SCP");
		Spaceport->replace(1, {{11, 11}}, 'A', "PARTY.SCP");
		Spaceport->replace(2, {{14, 11}}, 'A', "PARTY.SCP");
		Spaceport->replace(3, {{17, 11}}, 'A', "PARTY.SCP");
		Spaceport->replace(4, {{24, 11}}, 'A', "PARTY.SCP");
		Spaceport->replace(5, {{21, 11}}, 'A', "PARTY.SCP");

		Spaceport->replace(0, {{8, 11}}, 'B', "PARTY.SCP");
		Spaceport->replace(1, {{11, 11}}, 'B', "PARTY.SCP");
		Spaceport->replace(2, {{14, 11}}, 'B', "PARTY.SCP");
		Spaceport->replace(3, {{17, 11}}, 'B', "PARTY.SCP");
		Spaceport->replace(4, {{24, 11}}, 'B', "PARTY.SCP");
		Spaceport->replace(5, {{21, 11}}, 'B', "PARTY.SCP");

		Spaceport->replace(0, {{8, 11}}, 'C', "PARTY.SCP");
		Spaceport->replace(1, {{11, 11}}, 'C', "PARTY.SCP");
		Spaceport->replace(2, {{14, 11}}, 'C', "PARTY.SCP");
		Spaceport->replace(3, {{17, 11}}, 'C', "PARTY.SCP");
		Spaceport->replace(4, {{24, 11}}, 'C', "PARTY.SCP");
		Spaceport->replace(5, {{21, 11}}, 'C', "PARTY.SCP");

		Spaceport->replace(0, {{100, 26}, {101, 25}}, 'C', "LEVEL.SCP");
		Spaceport->replace(1, {{103, 26}, {104, 25}}, 'C', "LEVEL.SCP");
		Spaceport->replace(2, {{106, 26}, {107, 25}}, 'C', "LEVEL.SCP");
		Spaceport->replace(3, {{109, 26}, {110, 25}}, 'C', "LEVEL.SCP");
		Spaceport->replace(4, {{97, 23}, {98, 28}}, 'C', "LEVEL.SCP");
		Spaceport->replace(5, {{94, 23}, {95, 28}}, 'C', "LEVEL.SCP");

		Spaceport->replace(0,
			{{26, 26},
				 {27, 27},
				 {28, 27},
				 {29, 28},
				 {30, 29},
				 {108, 26},
				 {109, 27},
				 {110, 27},
				 {111, 29}},
			'D', "LEVEL.SCP");
		Spaceport->replace(1,
			{{32, 26},
				 {33, 27},
				 {34, 27},
				 {35, 28},
				 {36, 29},
				 {113, 26},
				 {114, 27},
				 {115, 27},
				 {116, 29}},
			'D', "LEVEL.SCP");
		Spaceport->replace(2,
			{{38, 26},
				 {39, 27},
				 {40, 27},
				 {41, 28},
				 {42, 29},
				 {118, 26},
				 {119, 27},
				 {120, 27},
				 {121, 29}},
			'D', "LEVEL.SCP");
		Spaceport->replace(3,
			{{44, 26},
				 {45, 27},
				 {46, 27},
				 {47, 28},
				 {48, 29},
				 {123, 26},
				 {124, 27},
				 {125, 27},
				 {126, 29}},
			'D', "LEVEL.SCP");

		Spaceport->replace(0, {{16, 26}, {17, 27}, {18, 27}, {19, 26}}, 'E',
			"LEVEL.SCP");
		Spaceport->replace(1, {{21, 26}, {22, 27}, {23, 27}, {24, 26}}, 'E',
			"LEVEL.SCP");
		Spaceport->replace(2, {{26, 26}, {27, 27}, {28, 27}, {29, 26}}, 'E',
			"LEVEL.SCP");
		Spaceport->replace(3, {{31, 26}, {32, 27}, {33, 27}, {34, 26}}, 'E',
			"LEVEL.SCP");

		Princess->replace(0, {{17, 12}});  //han
		Princess->replace(1, {{18, 12}});  //luke
		Princess->replace(2, {{19, 12}});  //chewie
		Princess->replace(3, {{20, 12}});  //r2
		Princess->replace(4, {{21, 12}});  //3po
		Princess->replace(5, {{22, 12}});  //ben
		Princess->replace(6, {{25, 12}});  //leia

		Princess->replace(3, {{35, 26}, {36, 25}}, 'A', "LEVEL.SCP");
		Princess->replace(4, {{33, 26}, {34, 25}}, 'A', "LEVEL.SCP");
		Princess->replace(5, {{37, 26}, {38, 25}}, 'A', "LEVEL.SCP");

		Princess->replace(3, {{24, 26}}, 'B', "LEVEL.SCP");
		Princess->replace(4, {{25, 26}}, 'B', "LEVEL.SCP");
		Princess->replace(5, {{26, 26}}, 'B', "LEVEL.SCP");

		Princess->replace(5, {6}, 'A', "SCRIPT.TXT");
		Princess->replace(5, {9}, 'B', "SCRIPT.TXT");
		Princess->replace(5, {3}, 'C', "SCRIPT.TXT");
		Princess->replace(5, {1}, 'D', "SCRIPT.TXT");
		Princess->replace(5, {4}, 'E', "SCRIPT.TXT");

		Princess->binWrite(5, {0x6825}, 'B', "DEATHSTARRESCUE_B.AI2");
		//TCS stupidly checks weapon instead of character
		Princess->replace(
			"\t\tdeactivate \"character=" + Princess->party[3]->name + "\"\n" +
			"\t\tdeactivate \"character=" + Princess->party[4]->name +
			"\"\n",  //+
			//"\t\tdeactivate\"character=" + Princess->party[5]->name + "\"\n",
			0, {27}, 'B', "LEVEL.SCP");
		Princess->replace("\t\tif FreePlay == 0 goto MakeSurePlayersNotDroids\n", 0,
			{4}, 'C', "LEVEL.SCP");
		Princess->append(std::string("state MakeSurePlayersNotDroids {\n"
			"\tConditions {\n"
			"\t}\n"
			"\tActions {\n"
			"\t\tdeactivate \"character=" +
			Princess->party[3]->name + "\"\n" +
			"\t\tdeactivate \"character=" +
			Princess->party[4]->name + "\"\n" +
			//"\t\tdeactivate \"character=" +
			//Princess->party[5]->name + "\"\n" +
			"\t}\n" + "}"),
			'C', "LEVEL.SCP");

		std::ofstream os(Princess->directory('D', "LEVEL.SCP"));
		os << "state Base {\n"
			<< "\tConditions {\n"
			<< "\t\tif FreePlay == 0 goto MakeSurePlayersNotDroids\n"
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

		Princess->replace("\t\tif FreePlay == 0 goto MakeSurePlayersNotDroids\n", 0,
			{4}, 'E', "LEVEL.SCP");
		Princess->append(
			std::string("state MakeSurePlayersNotDroids {\n"
				"\tConditions {\n"
				"\t}\n"
				"\tActions {\n"
				"\t\tdeactivate \"character=" +
				Princess->party[3]->name + "\"\n" +
				"\t\tdeactivate \"character=" + Princess->party[4]->name +
				"\"\n" + "\t}\n" + "}"),
			'E', "LEVEL.SCP");

		std::remove(Princess->directory('A', "NOWEAPON.SCP").c_str());
		std::remove(Princess->directory('B', "NOWEAPON.SCP").c_str());
		std::remove(Princess->directory('C', "NOWEAPON.SCP").c_str());
		std::remove(Princess->directory('D', "NOWEAPON.SCP").c_str());
		std::remove(Princess->directory('E', "NOWEAPON.SCP").c_str());

		Princess->rename(5, 'A');
		Princess->rename(5, 'B');
		Princess->rename(5, 'C');
		Princess->rename(5, 'D');
		Princess->rename(5, 'E');
		Princess->binWrite(6, {0x3A9F}, 'C', "DEATHSTARRESCUE_C.AI2");

		DSE->replace(0, {{1, 12}});  //han
		DSE->replace(1, {{2, 12}});  //chewie
		DSE->replace(2, {{3, 12}});  //leia
		DSE->replace(3, {{4, 12}});  //luke
		DSE->replace(4, {{5, 12}});  //r2
		DSE->replace(5, {{6, 12}});  //cpo

		DSE->replace(4, {{15, 11}}, 'A', "PARTY.SCP");
		DSE->replace(5, {{14, 11}}, 'A', "PARTY.SCP");

		DSE->replace(4, {{15, 11}}, 'B', "PARTY.SCP");
		DSE->replace(5, {{14, 11}}, 'B', "PARTY.SCP");

		DSE->replace(4, {{12, 11}, {15, 11}}, 'C', "PARTY.SCP");
		DSE->replace(5, {{6, 11}, {9, 11}}, 'C', "PARTY.SCP");

		RebelAttack->replace(0, {{1, 12}});
		RebelAttack->replace(1, {{2, 12}});

		Hoth->replace("character \"" + Hoth->party[0]->name +
			"\" player\ncharacter \"" + Hoth->party[1]->name +
			"\" player",
			32, {1});

		EchoBase->replace(0, {{1, 12}});
		EchoBase->replace(1, {{2, 12}});
		EchoBase->replace(2, {{3, 12}});  //3po
		EchoBase->replace(3, {{4, 12}});  //chewbacca

		EchoBase->replace(2, {{24, 11}}, 'A', "PARTY.SCP");
		EchoBase->replace(3, {{5, 11}}, 'A', "PARTY.SCP");

		EchoBase->replace("if CategoryIs \"protocol\"", 13, {{23, 3}}, 'B',
			"PARTY.SCP");
		EchoBase->replace("category=protocol", 14, {{111, 29}}, 'B', "PARTY.SCP");
		EchoBase->replace("protocol", 4, {{112, 60}}, 'B', "PARTY.SCP");
		EchoBase->replace(3, {{5, 11}}, 'B', "PARTY.SCP");

		EchoBase->replace(3, {{6, 11}}, 'C', "PARTY.SCP");

		FalconFlight->replace(0, {{3, 12}});
		FalconFlight->replace(1, {{4, 12}});

		Dagobah->replace(0, {{3, 12}});  //luke pilot
		Dagobah->replace(1, {{4, 12}});  //r2
		Dagobah->replace(2, {{5, 12}});  //luke dagobah
		Dagobah->replace(3, {{6, 12}});  //yoda

		Dagobah->replace(0, {{21, 26}, {22, 27}, {23, 27}, {24, 25}}, 'A',
			"LEVEL.SCP");
		Dagobah->replace(2, {{34, 26}, {35, 27}, {36, 27}, {37, 25}}, 'A',
			"LEVEL.SCP");
		Dagobah->replace(3, {{39, 26}, {40, 27}, {41, 27}, {42, 25}}, 'A',
			"LEVEL.SCP");

		Dagobah->replace(0, {{41, 26}, {42, 27}, {43, 27}, {44, 25}}, 'B',
			"LEVEL.SCP");
		Dagobah->replace(1, {{59, 28}, {65, 29}, {84, 29}}, 'B', "LEVEL.SCP");
		Dagobah->replace(2,
			{{57, 28},
				 {61, 59},
				 {63, 29},
				 {82, 29},
				 {96, 26},
				 {97, 27},
				 {98, 27},
				 {99, 25}},
			'B', "LEVEL.SCP");
		Dagobah->replace(3,
			{{58, 28},
				 {64, 29},
				 {83, 29},
				 {101, 26},
				 {102, 27},
				 {103, 27},
				 {104, 25}},
			'B', "LEVEL.SCP");

		Dagobah->replace(0, {{25, 26}, {26, 27}, {27, 27}, {28, 25}}, 'C',
			"LEVEL.SCP");
		Dagobah->replace(2, {{38, 26}, {39, 27}, {40, 27}, {41, 25}}, 'C',
			"LEVEL.SCP");
		Dagobah->replace(3, {{43, 26}, {44, 27}, {45, 27}, {46, 25}}, 'C',
			"LEVEL.SCP");

		Dagobah->replace(0, {{35, 26}, {36, 27}, {37, 27}, {38, 25}}, 'D',
			"LEVEL.SCP");
		Dagobah->replace(2, {{48, 26}, {49, 27}, {50, 27}, {51, 25}}, 'D',
			"LEVEL.SCP");
		Dagobah->replace(3, {{53, 26}, {54, 27}, {55, 27}, {56, 25}}, 'D',
			"LEVEL.SCP");

		Dagobah->replace(0,
			{{33, 26},
				 {34, 27},
				 {35, 27},
				 {36, 25},
				 {54, 26},
				 {55, 27},
				 {56, 27},
				 {57, 25}},
			'E', "LEVEL.SCP");
		Dagobah->replace(3, {{38, 27}}, 'E', "LEVEL.SCP");
		//fixes AI
		Dagobah->replace("if CategoryIs \"Jedi\" == 0", 18, {{5, 3}}, 'C',
			"PARTY.SCP");

		Dagobah->replace(2, {{9, 11}}, 'E', "PARTY.SCP");
		Dagobah->replace(3, {{7, 11}, {170, 11}}, 'E', "PARTY.SCP");
		hexWrite(EXE, "\0", 0x35E3A0);  //unrestricts xwing force
		//training
		if (Jedi({Dagobah->party[0]}))
			multiPointer(Dagobah->party[0],
				{0x3464d, 0x35b2d, 0x87114, 0xa219a, 0xa23f7, 0xa38b6});
		else if (Jedi({Dagobah->party[1]}))
			multiPointer(Dagobah->party[1],
				{0x3464d, 0x35b2d, 0x87114, 0xa219a, 0xa23f7, 0xa38b6});

		CCT->replace(0, {{3, 12}});
		CCT->replace(1, {{4, 12}});
		CCT->replace("if CategoryIs \"Droid\" == 1", 18, {{5, 3}}, 'A',
			"PARTY.SCP");
		CCT->replace("if CategoryIs \"Droid\" == 1", 18, {{5, 3}}, 'B',
			"PARTY.SCP");
		CCT->replace("if CategoryIs \"Droid\" == 1", 18, {{5, 3}}, 'C',
			"PARTY.SCP");

		Bespin->replace(0, {{1, 12}});
		Bespin->replace(1, {{2, 12}});
		Bespin->replace(2, {{3, 12}});
		Bespin->replace(3, {{4, 12}});  //r2
		Bespin->replace(4, {{5, 12}});  //3po

		Bespin->replace(3, {{14, 11}, {20, 11}}, 'A', "PARTY.SCP");
		Bespin->replace(4, {{15, 11}, {17, 11}}, 'A', "PARTY.SCP");

		Bespin->replace(4, {{14, 11}, {16, 11}}, 'B', "PARTY.SCP");
		Bespin->replace("if CategoryIs \"Protocol\"", 13, {{13, 3}, {24, 3}}, 'C',
			"PARTY.SCP");
		Bespin->replace("if CategoryIs \"Astromech\"", 13, {{18, 3}, {30, 3}}, 'C',
			"PARTY.SCP");

		Bespin->replace(4, {{494, 13}}, 'A');
		Bespin->specialReplace(4, {{1598, 22}}, 'A', ".GIT");
		//Bespin->replace(4, { 7 }, 'A', "SCRIPT.TXT");
		//Bespin->rename("_" + Bespin->party[4]->name + ".SCP", "_C3PO.SCP", 'A');
		////double check, might be supurfluous

		Jabbas->replace(0, {{1, 12}});  //leia
		Jabbas->replace(1, {{2, 12}});  //chewie
		Jabbas->replace(2, {{3, 12}});  //luke
		Jabbas->replace(3, {{4, 12}});  //3po
		Jabbas->replace(4, {{5, 12}});  //r2
		Jabbas->replace(5, {{6, 12}});  //han

		Jabbas->replace(0, {{17, 26}, {18, 25}}, 'E', "LEVEL.SCP");

		Jabbas->replace(2, {{28, 11}}, 'A', "PARTY.SCP");
		Jabbas->replace(3, {{7, 11}}, 'A', "PARTY.SCP");
		Jabbas->replace(4, {{8, 11}, {10, 11}}, 'A', "PARTY.SCP");
		Jabbas->replace(5, {{6, 11}}, 'A', "PARTY.SCP");

		Jabbas->replace(3, {{27, 11}, {30, 11}}, 'B', "PARTY.SCP");
		Jabbas->replace(4, {{35, 11}}, 'B', "PARTY.SCP");
		Jabbas->replace(5, {{9, 11}}, 'B', "PARTY.SCP");
		//fixes AI
		Jabbas->replace("if CategoryIs \"Jedi\"", 27, {{49, 3}, {38, 3}}, 'B',
			"PARTY.SCP");
		int leverGuy = -1;
		if (!Jedi({Jabbas->party[1]}) && Lever({Jabbas->party[1]}))
			leverGuy = 1;
		else if (!Jedi({Jabbas->party[0]}) && Lever({Jabbas->party[0]}))
			leverGuy = 0;
		else if (!Jedi({Jabbas->party[2]}) && Lever({Jabbas->party[2]}))
			leverGuy = 2;

		if (leverGuy != -1)
			Jabbas->replace(Jabbas->party[leverGuy]->name, 9, {{39, 11}, {50, 11}},
				'B', "PARTY.SCP");

		Jabbas->replace(5, {{6, 11}}, 'D', "PARTY.SCP");
		Jabbas->replace("if CategoryIs \"Astromech\"", 13, {{6, 3}}, 'E',
			"PARTY.SCP");
		Jabbas->replace("if CategoryIs \"Protocol\"", 13, {{8, 3}}, 'E',
			"PARTY.SCP");

		Carkoon->replace(0, {{1, 12}});
		Carkoon->replace(1, {{2, 12}});
		Carkoon->replace(2, {{3, 12}});  //chewie
		Carkoon->replace(3, {{4, 12}});  //han
		Carkoon->replace(4, {{5, 12}});  //3po
		Carkoon->replace(5, {{6, 12}});  //r2
		Carkoon->replace(6, {{7, 12}});  //leia

		Carkoon->replace(2, {{132, 27}, {133, 27}, {134, 29}}, 'A', "LEVEL.SCP");
		Carkoon->replace(3, {{130, 59}, {136, 27}, {137, 27}, {138, 29}}, 'A',
			"LEVEL.SCP");

		Carkoon->replace(4, {{56, 27}, {57, 27}, {58, 26}, {59, 29}}, 'B',
			"LEVEL.SCP");
		Carkoon->replace(5, {{61, 27}, {62, 27}, {63, 26}, {64, 29}}, 'B',
			"LEVEL.SCP");

		Carkoon->replace(2, {{36, 11}}, 'A', "PARTY.SCP");
		Carkoon->replace(3, {{39, 11}}, 'A', "PARTY.SCP");
		Carkoon->replace(4, {{8, 11}, {11, 11}}, 'A', "PARTY.SCP");
		Carkoon->replace(5, {{9, 11}, {14, 11}}, 'A', "PARTY.SCP");
		Carkoon->replace(6, {{7, 11}, {17, 11}}, 'A', "PARTY.SCP");

		Carkoon->replace(4, {{30, 11}}, 'B', "PARTY.SCP");
		Carkoon->replace(5, {{27, 11}}, 'B', "PARTY.SCP");
		Carkoon->replace(6, {{6, 11}, {8, 11}}, 'B', "PARTY.SCP");

		Showdown->replace(0, {{3, 12}});
		Showdown->replace(1, {{4, 12}});

		Endor->replace(0, {{3, 12}});
		Endor->replace(1, {{4, 12}});
		Endor->replace(2, {{5, 12}});
		Endor->replace(3, {{6, 12}});
		Endor->replace(4, {{7, 12}});
		Endor->replace(5, {{8, 12}});
		if (Grapple({Endor->party[0]}))
			leverGuy = 0;
		else if (Grapple({Endor->party[1]}))
			leverGuy = 1;
		else if (Grapple({Endor->party[2]}))
			leverGuy = 2;
		else if (Grapple({Endor->party[3]}))
			leverGuy = 3;
		else if (Grapple({Endor->party[4]}))
			leverGuy = 4;
		else if (Grapple({Endor->party[5]}))
			leverGuy = 5;
		Endor->replace(leverGuy, {{5, 11}}, 'B', "PARTY.SCP");

		Destiny->replace(0, {{1, 12}});
		Destiny->replace(1, {{2, 12}});

		ITDS->replace(0, {{1, 12}});
		ITDS->replace(1, {{2, 12}});

		Anakinsflight->replace(0, {{1, 12}});
		Anakinsflight->replace(1, {{2, 12}});

		ANewHope->replace(0, {{1, 12}});
		ANewHope->replace(1, {{2, 12}});
		ANewHope->replace(2, {{3, 12}});  //3po
		ANewHope->replace(2, {1}, 'A', "SCRIPT.TXT");
		ANewHope->replace(2, {1}, 'B', "SCRIPT.TXT");
		ANewHope->rename(2, 'A');
		ANewHope->rename(2, 'B');

		//takeover speeder?

		//bounty hunter missions
		{
			deleteLines(LEV + "MISSIONS.TXT", {1});
			txtIns(LEV + "MISSIONS.TXT",
				"party \"" + BHM->party[0]->name +
				"\ "
				"\"" +
				BHM->party[1]->name +
				"\ "
				"\"" +
				BHM->party[2]->name +
				"\ "
				"\"" +
				BHM->party[3]->name +
				"\ "
				"\"" +
				BHM->party[4]->name +
				"\ "
				"\"" +
				BHM->party[5]->name + "\ ",
				{1}, 0);

			auto missionReplace = [](int c, int line) {
				txtIns(LEV + "MISSIONS.TXT", BHM->party[c]->name, {{line, 15}},
					BHM->vanillaParty[c]->name.length());
			};

			missionReplace(6, 5);
			missionReplace(7, 6);
			missionReplace(8, 7);
			missionReplace(9, 8);
			missionReplace(10, 9);
			missionReplace(11, 10);
			missionReplace(12, 11);
			missionReplace(13, 12);
			missionReplace(14, 13);
			missionReplace(15, 14);

			missionReplace(16, 17);
			missionReplace(17, 18);
			missionReplace(18, 19);
			missionReplace(19, 20);
			missionReplace(20, 21);
			missionReplace(21, 22);
			missionReplace(22, 23);
			missionReplace(23, 24);
			missionReplace(24, 25);
			missionReplace(25, 26);

			auto missionReplace2 = [](int c, int line, Level* lev, char scene,
				std::string fileExtention) {
				lev->replace(BHM->party[c]->name, BHM->vanillaParty[c]->name.length(),
					{{line, 49}}, scene, fileExtention);
			};

			missionReplace2(6, 24, Negotiations, 'A', "LEVEL2.SCP");
			missionReplace2(7, 24, EscapeNaboo, 'C', "LEVEL1.SCP");
			missionReplace2(8, 24, Invasion, 'C', "LEVEL1.SCP");
			missionReplace2(9, 24, Factory, 'F', "LEVEL1.SCP");
			missionReplace2(10, 24, Kamino, 'F', "LEVEL1.SCP");
			missionReplace2(11, 25, JediBattle, 'B', "LEVEL1.SCP");
			missionReplace2(12, 25, Chancellor, 'B', "LEVEL1.SCP");
			missionReplace2(13, 24, Kashyyyk, 'A', "LEVEL2.SCP");
			missionReplace2(14, 24, Ruin, 'A', "LEVEL.SCP");
			missionReplace2(15, 25, Grievous, 'A', "LEVEL2.SCP");

			missionReplace2(16, 30, SecretPlans, 'B', "LEVEL1.SCP");
			missionReplace2(17, 24, Jundland, 'B', "LEVEL2.SCP");
			missionReplace2(18, 28, Spaceport, 'D', "LEVEL3.SCP");
			missionReplace2(19, 30, Princess, 'C', "LEVEL4.SCP");
			missionReplace2(20, 25, EchoBase, 'C', "LEVEL1.SCP");
			missionReplace2(21, 20, Endor, 'A', "LEVEL2.SCP");
			missionReplace2(22, 23, Bespin, 'A', "LEVEL2.SCP");
			missionReplace2(23, 26, Bespin, 'C', "LEVEL1.SCP");
			missionReplace2(24, 21, Spaceport, 'B', "LEVEL4.SCP");
			missionReplace2(25, 19, EchoBase, 'A', "LEVEL2.SCP");

			auto missionNames = [](int c, coord lc, int len) {
				txtIns(out + "/STUFF/TEXT/ENGLISH.TXT", BHM->party[c]->realName, {lc},
					len);
			};

			missionNames(6, {266, 18}, 12);
			missionNames(7, {267, 18}, 13);
			missionNames(8, {268, 18}, 13);
			missionNames(9, {269, 18}, 10);
			missionNames(10, {270, 18}, 9);
			missionNames(11, {271, 18}, 8);
			missionNames(12, {272, 18}, 12);
			missionNames(13, {273, 18}, 13);
			missionNames(14, {274, 18}, 7);
			missionNames(15, {275, 19}, 14);

			missionNames(16, {9, 17}, 5);
			missionNames(17, {10, 17}, 14);
			missionNames(18, {11, 17}, 9);
			missionNames(19, {12, 17}, 13);
			missionNames(20, {13, 17}, 14);
			missionNames(21, {14, 17}, 4);
			missionNames(22, {15, 17}, 5);
			missionNames(23, {16, 17}, 16);
			missionNames(24, {17, 17}, 14);
			missionNames(25, {18, 17}, 8);

			//txtIns(LEV + "MISSIONS.TXT", BHM->party[6]->name, { {5, 15} }, 10);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[7]->name, { {6, 15} }, 7);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[8]->name, { {7, 15} }, 11);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[9]->name, { {8, 15} }, 9);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[10]->name, { {9, 15} }, 8);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[11]->name, { {10, 15} }, 8);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[12]->name, { {11, 15} }, 10);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[13]->name, { {12, 15} }, 9);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[14]->name, { {13, 15} }, 7);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[15]->name, { {14, 15} }, 14);

			//txtIns(LEV + "MISSIONS.TXT", BHM->party[16]->name, { {17, 15} }, 4);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[17]->name, { {18, 15} }, 9);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[18]->name, { {19, 15} }, 9);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[19]->name, { {20, 15} }, 12);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[20]->name, { {21, 15} }, 13);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[21]->name, { {22, 15} }, 4);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[22]->name, { {23, 15} }, 4);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[23]->name, { {24, 15} }, 15);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[24]->name, { {25, 15} }, 22);
			//txtIns(LEV + "MISSIONS.TXT", BHM->party[25]->name, { {26, 15} }, 7);
		}

		//Character unlocks
	#ifdef _DEBUG
		wxGetApp().CallAfter([] { wxLogStatus("starting collection"); });
	#endif

		std::ofstream collect(out + "/CHARS/COLLECTION.TXT");

		auto collectWrite = [&](std::vector<Playable*>& vec) {
			for (Playable* p : vec) {
				collect << "collect \"" + p->name + "\" ";
				if (p == allMinikitsCharacter)
					collect << "all_minikits_complete" << '\n';
				else if (p->storyMode)
					collect << "story" << '\n';
				else {
					if (p->lev == allEpisodes)
						collect << "all_episodes_complete";
					else if (p->lev != defaultLevel) {
						collect << "area_complete \"";
						collect << p->lev->firstName << "\"";
					}
					collect << " buy_in_shop ";
					collect << std::to_string(p->price) << '\n';
				}
			#ifdef _DEBUG
				wxGetApp().CallAfter([&p] {
					wxString collected = p->realName + " collected.";
				wxLogStatus(collected);
				});
			#endif
			}
		};

		collectWrite(chs);

		collect << "collect \"weirdo1\"" << '\n';
		collect << "collect \"weirdo2\"" << '\n';

		collectWrite(vhs);
		std::string minis[] = {"mini_republic_cruiser",
													 "mini_gungan_bongo",
													 "mini_royal_starship",
													 "mini_sebulba_pod",
													 "mini_naboo_starfighter",
													 "mini_sith_infiltrator",

													 "mini_zam_speeder",
													 "mini_jedi_starfighter",
													 "mini_droideka",
													 "mini_gunship",
													 "mini_atte",
													 "mini_solar_sailor",

													 "mini_dropship",
													 "mini_emergency_ship",
													 "mini_e3_jedi_starfighter",
													 "mini_wookie_cat",
													 "mini_e3_x_wing",
													 "mini_v_wing",

													 "mini_star_destroyer",
													 "mini_sand_crawler",
													 "mini_land_speeder",
													 "mini_millennium_falcon",
													 "mini_y_wing",
													 "mini_tie_advanced",

													 "mini_atat",
													 "mini_snow_speeder",
													 "mini_tie_fighter",
													 "mini_x_wing",
													 "mini_slave1",
													 "mini_cloud_car",

													 "mini_desert_skiff",
													 "mini_sail_barge",
													 "mini_tie_bomber",
													 "mini_atst",
													 "mini_tie_interceptor",
													 "mini_imperial_shuttle"};

		for (std::string mini : minis) {
			collect << "collect \"" << mini << "\" minikit" << '\n';
		}
		collect.close();

		multiPointer(allMinikitsCharacter, {0x2b0ce, 0x84ef2});

		multiPointer(indy, {0x2e585, 0x86969, 0x86982, 0xc1053, 0x83b24, 0xc5098,
												0xc50d0, 0xc65b1});
		numWrite(EXE, indy->price, 0x2e5c7);
		txtIns(out + "/STUFF/TEXT/ENGLISH.TXT", indy->realName, {{1627, 7}}, 13);

		//fixes ET characters
	#define CHR out + "/CHARS/"
	#define chfile(x) CHR + x->name + "/" + x->name + ".TXT"
		if (extog) {
			txtIns(out + "/STUFF/TEXT/ENGLISH.TXT", "Nothing", {{839, 6}}, 12);

			deleteLines(CHR + "BUZZDROID/BUZZDROID.TXT", {7});
			deleteLines(CHR + "HANINCARBONITE/HANINCARBONITE.TXT", {20});
			deleteLines(CHR + "MOUSEDROID/MOUSEDROID.TXT", {17});
			deleteLines(CHR + "NAFFDROID1/NAFFDROID1.TXT", {19});
			deleteLines(CHR + "NAFFDROID2/NAFFDROID2.TXT", {19});
			deleteLines(CHR + "NAFFDROID3/NAFFDROID3.TXT", {13});
			deleteLines(CHR + "NAFFDROID4/NAFFDROID4.TXT", {19});
			deleteLines(CHR + "REBELSCUM/ENGINEER.TXT", {5});
			deleteLines(CHR + "SKELETON/SKELETON.TXT", {6});
			deleteLines(CHR + "STORMTROOPER/ATAT_DRIVER.TXT", {4});
			deleteLines(CHR + "STORMTROOPER/IMPERIALENGINEER.TXT", {7});
			deleteLines(CHR + "STORMTROOPER/SCOUTTROOPER.TXT", {6});
			deleteLines(CHR + "TRAININGREMOTE/TRAININGREMOTE.TXT", {4});
			deleteLines(CHR + "WOMPRAT/WOMPRAT.TXT", {18});
		}
	}

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

		rgbBatch(PTL, blue,
			{0x4A0, 0x4A8, 0x591A, 0x5922, 0x592A, 0x77D2, 0xF5FD, 0xF689,
				 0xF691, 0x8357});
		rgbBatch(PTL, green, {0x877, 0x87F, 0x5543, 0x554B, 0x5553, 0xAD94});
		rgbBatch(PTL, red,
			{0x60C8, 0x60D0, 0x60D8, 0xB542, 0xC0C7, 0xC0CF, 0xFDAB, 0xFE37,
				 0xFE3F});
		rgbBatch(PTL, purple,
			{0xC4E, 0xC56, 0x5CF1, 0x5CF9, 0x5D01, 0xB16B, 0x19021});

		rgbBatch(PT1, blue,
			{0x4A0, 0x4A8, 0x10628, 0x10630, 0x111B0, 0x111B8, 0x111C0});
		rgbBatch(PT1, green, {0x878, 0x880, 0x10DD8, 0x10DE0, 0x10DE0});
		rgbBatch(PT1, red, {0x1028, 0x1030, 0x11968, 0x11960, 0x11970});
		rgbBatch(PT1, purple,
			{0xC50, 0xC58, 0x11588, 0x11590, 0x11598, 0x11960, 0x11968});

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
		//	rgbFloat(TNG, green, 0x31CC98 + (i * 0x2c4));
		//}
	}
#endif

	wxGetApp().CallAfter([] { wxLogStatus("Done."); });
}
