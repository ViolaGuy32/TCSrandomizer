#include "CharacterData.h"
#include "Characters.h"
#include "Defines.h"
#include "externData.h"
#include "pch.h"

void makeCharacters() {
	quigonjinn = new Playable("quigonjinn", "Qui-Gon Jinn", 25000, 0x7f1c30, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable);

	obiwankenobi = new Playable("obiwankenobi", "Obi-Wan Kenobi", 22000, 0x7f1c38, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable);

	tc14 = new Playable(
		"tc14", "TC-14", 4000, 0x7f202c, 0.75f, Proto | Droid | Passive | Gas | Pushable | Zappable);

	jarjarbinks = new Playable("jarjarbinks", "Jar Jar Binks", 14000, 0x7f1f00, 1.32f,
		Build | Box | Jump | DoubleJump | HighJump | RealDoubleJump | HighDoubleJump | GunganJump | Chokeable |
			Lightningable | Trickable);

	amidala = new Playable("amidala", "Queen Amidala", 24000, 0x0, 1.2f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Chokeable | Lightningable | SlightlyHigherJump);

	captainpanaka = new Playable("captainpanaka", "Captain Panaka", 12000, 0x0, 1.2f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Chokeable | Lightningable);

	padmebattle = new Playable("padmebattle", "Padmé (Battle)", 20000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | Attack | Shoot | Grapple | Chokeable | Lightningable);

	r2d2 = new Playable("r2d2", "R2-D2", 5000, 0x7f1fa0, 1.0f,
		Fly | Zapper | AstroZapper | Astro | Droid | Passive | Gas | Pushable | Zappable);

	anakin_boy = new Playable("anakin_boy", "Anakin Skywalker (Boy)", 6000, 0x0, 0.8f,
		Lever | Build | Box | Jump | Hatch | Chokeable | Lightningable);

	obiwankenobi_jedimaster =
		new Playable("obiwankenobi_jedimaster", "Obi-Wan Kenobi (jedi Master)", 30000, 0x7f1f18, 1.2f,
			Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect |
				Jedi | Chokeable | Lightningable);

	r4_p17 = new Playable("r4_p17", "R4-P17", 4000, 0x0, 1.0f,
		Fly | Zapper | AstroZapper | Astro | Droid | Passive | Gas | Pushable | Zappable);

	anakin_padawan = new Playable("anakin_padawan", "Anakin Skywalker (Padawan)", 24000, 0x7f1f10, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable);

	padmegeo = new Playable("padmegeo", "Padmé (Geonosis)", 20000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | Attack | Shoot | Grapple | Chokeable | Lightningable);

	c3po = new Playable(
		"c3po", "C-3PO", 5000, 0x7f2020, 0.75f, Proto | Droid | Passive | Gas | Pushable | Zappable);

	macewindu = new Playable("macewindu", "Mace Windu", 36000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable);

	padmeclawed = new Playable("padmeclawed", "Padmé (Clawed)", 20000, 0x7f1f08, 1.2f,
		Hat | Lever | Build | Box | Jump | Attack | Shoot | Grapple | Chokeable | Lightningable);

	yoda = new Playable("yoda", "Yoda", 80000, 0x7f1d08, 1.44f,
		Lever | Build | Box | Jump | DoubleJump | YodaJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			ResistZap);

	obiwankenobi_ep3 = new Playable("obiwankenobi_ep3", "Obi-Wan Kenobi (Episode III)", 300000, 0x7f1f58, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable);

	anakin_jedi = new Playable("anakin_jedi", "Anakin Skywalker (jedi)", 35000, 0x7f1f60, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable);

	palpatine = new Playable("palpatine", "Chancellor Palpatine", 8000, 0x7f1f90, 1.2f,
		Hat | Lever | Build | Box | Jump | Chokeable | Lightningable);

	clone_ep3_sand = new Playable("clone_ep3_sand", "Commander Cody", 12000, 0x7f1cb0, 1.0f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | Baddy,
		{
			{chatting, "disguisedclone"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "patrol"},
		},
		normalAttack, normalBlock);

	chewbacca = new Playable("chewbacca", "Chewbacca", 18000, 0x7f1d50, 1.2f,
		Hat | Lever | Build | Box | Jump | Attack | Shoot | Grapple | Chokeable | Lightningable);

	princessleia = new Playable("princessleia", "Princess Leia", 20000, 0x7f1c40, 1.2f,
		Hat | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable |
			Lightningable | SlightlyHigherJump | LeiaAlt);

	captainantilles = new Playable("captainantilles", "Captain Antilles", 14000, 0x7f1c58, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump);

	rebelfriend = new Playable("rebelfriend", "Rebel Friend", 15000, 0x0, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump);

	lukeskywalker_tatooine = new Playable("lukeskywalker_tatooine", "Luke Skywalker (Tatooine)", 12000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable |
			SlightlyHigherJump);

	benkenobi = new Playable("benkenobi", "Ben Kenobi", 30000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable);

	hansolo = new Playable("hansolo", "Han Solo", 18000, 0x0, 1.44f,
		Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable);

	hansolo_stormtrooper = new Playable("hansolo_stormtrooper", "Han Solo (Stormtrooper)", 20000, 0x0, 1.44f,
		Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable);

	lukeskywalker_stormtrooper =
		new Playable("lukeskywalker_stormtrooper", "Luke Skywalker (Stormtrooper)", 14000, 0x0, 1.2f,
			Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable |
				SlightlyHigherJump);

	hansolo_hoth = new Playable("hansolo_hoth", "Han Solo (Hoth)", 20000, 0x0, 1.44f,
		Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable);

	princessleia_hoth = new Playable("princessleia_hoth", "Princess Leia (Hoth)", 22000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable |
			Lightningable | SlightlyHigherJump | LeiaAlt);

	lukeskywalker_pilot = new Playable("lukeskywalker_pilot", "Luke Skywalker (Pilot)", 14000, 0x0, 1.2f,
		Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable |
			SlightlyHigherJump);

	lukeskywalker_dagobah = new Playable("lukeskywalker_dagobah", "Luke Skywalker (Dagobah)", 28000, 0x7f1e90, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable | LukeAlt);

	lukeskywalker_bespin = new Playable("lukeskywalker_bespin", "Luke Skywalker (Bespin)", 30000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable | LukeAlt);

	landocalrissian = new Playable("landocalrissian", "Lando Calrissian", 15000, 0x0, 1.28f,
		Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump | LandoAlt);

	princessleia_bespin = new Playable("princessleia_bespin", "Princess Leia (Bespin)", 22000, 0x0, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable | Lightningable |
			SlightlyHigherJump | LeiaAlt);

	lukeskywalker_jedi = new Playable("lukeskywalker_jedi", "Luke Skywalker (jedi)", 40000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable | LukeAlt);

	princessleia_boushh = new Playable("princessleia_boushh", "Princess Leia (Boushh)", 22000, 0x7f1c50, 1.2f,
		Hat | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable |
			Lightningable | SlightlyHigherJump | LeiaAlt);

	lando_palaceguard = new Playable("lando_palaceguard", "Lando (Palace Guard)", 15000, 0x0, 1.28f,
		Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable | Trickable |
			SlightlyHigherJump | LandoAlt);

	hansolo_skiff = new Playable("hansolo_skiff", "Han Solo (Skiff)", 20000, 0x0, 1.44f,
		Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable);

	princessleia_slave = new Playable("princessleia_slave", "Princess Leia (Slave)", 40000, 0x7f1c48, 1.2f,
		Hat | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable |
			Lightningable | SlightlyHigherJump | LeiaAlt);

	princessleia_endor = new Playable("princessleia_endor", "Princess Leia (Endor)", 22000, 0x0, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable | Lightningable |
			SlightlyHigherJump | LeiaAlt);

	lukeskywalker_endor = new Playable("lukeskywalker_endor", "Luke Skywalker (Endor)", 42000, 0x0, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Chokeable |
			Lightningable | LukeAlt);

	hansolo_endor = new Playable("hansolo_endor", "Han Solo (Endor)", 20000, 0x0, 1.44f,
		Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable);

	wicket = new Playable("wicket", "Wicket", 38000, 0x7f1dc8, 0.9f,
		Lever | Build | Box | Jump | Attack | Shoot | Hatch | Chokeable | Lightningable | Trickable);

	darthvader = new Playable("darthvader", "Darth Vader", 150000, 0x7f1eb0, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Sith |
			Choke | Imperial | Chokeable | ResistZap);

	gonkdroid = new Playable("gonkdroid", "Gonk droid", 3000, 0x7f2018, 0.12f,
		Droid | Passive | Gas | Pushable | Zappable | NoLevel);

	pkdroid = new Playable("pkdroid", "PK droid", 1500, 0x7f1ce8, 0.828538f,
		Droid | Passive | Gas | Pushable | Zappable | NoLevel);

	battledroid = new Playable("battledroid", "Battle droid", 6500, 0x7f1c88, 1.2f,
		Attack | Shoot | Droid | Gas | Pushable | Zappable | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "commanderpatrol"},

		},
		normalAttack, normalBlock);

	battledroid_security = new Playable("battledroid_security", "Battle droid (Security)", 8500, 0x7f1ca0, 1.2f,
		Attack | Shoot | Droid | Gas | Pushable | Zappable,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "commanderpatrol"},

		},
		normalAttack, normalBlock);

	//maybe use goalrange 2
	battledroid_commander = new Playable("battledroid_commander", "Battle droid (Commander)", 10000, 0x7f1c90, 1.2f,
		Attack | Shoot | Droid | Gas | Pushable | Zappable | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "commanderpatrol"},

		},
		normalAttack, normalBlock);

	destroyer = new Playable("destroyer", "droideka", 40000, 0x7f1d78, 1.8f,
		Attack | Shoot | Droid | Gas | Zappable | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "storm"},

		},
		normalAttack);

	captaintarpals = new Playable("captaintarpals", "Captain Tarpals", 17500, 0x7f1c60, 1.32f,
		Build | Box | Jump | DoubleJump | HighJump | RealDoubleJump | HighDoubleJump | GunganJump | Attack |
			Chokeable | Lightningable | Trickable);

	bossnass = new Playable("bossnass", "Boss Nass", 15000, 0x0, 1.2f,
		Lever | Build | Box | Jump | Chokeable | Lightningable | Trickable);

	royalguard = new Playable("royalguard", "Royal Guard", 10000, 0x7f1fb8, 1.2f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Chokeable | Lightningable);

	padme = new Playable("padme", "Padmé", 20000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | Attack | Shoot | Grapple | Chokeable | Lightningable);

	watto = new Playable("watto", "Watto", 16000, 0x7f1d38, 1.5f, Flutter | Zapper);

	pitdroid = new Playable(
		"pitdroid", "Pit droid", 4000, 0x7f2068, 0.8f, Droid | Passive | Gas | Pushable | Zappable);

	darthmaul = new Playable("darthmaul", "Darth Maul", 60000, 0x7f1c78, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Sith |
			Chokeable | Lightningable);

	zamwesell = new Playable("zamwesell", "Zam Wesell", 27500, 0x0, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Bounty | Chokeable |
			Lightningable | Trickable);

	dexter = new Playable("dexter", "Dexter Jettster", 10000, 0x0, 1.0f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Chokeable | Lightningable | Trickable |
			SlightlyHigherJump);

	clone_ep2 = new Playable("clone", "Clone", 13000, 0x0, 1.0f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable);

	lamasu = new Playable("lamasu", "Lama Su", 9000, 0x7f2090, 1.2f,
		Lever | Build | Box | Jump | Tall | Chokeable | Lightningable);

	taunwe = new Playable(
		"taunwe", "Taun We", 9000, 0x7f2098, 1.2f, Lever | Build | Box | Jump | Chokeable | Lightningable);

	geonosian = new Playable("geonosian", "Geonosian", 20000, 0x7f1d30, 1.5f,
		Lever | Flutter | Attack | Shoot | Pushable | Chokeable | Lightningable | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "storm"},

		},
		normalAttack, normalBlock);

	battledroid_geonosian = new Playable("battledroid_geonosian", "Battle droid (Geonosis)", 8500, 0x7f1c98, 1.2f,
		Attack | Shoot | Droid | Gas | Pushable | Zappable | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "commanderpatrol"},

		},
		normalAttack, normalBlock);

	superbattledroid = new Playable("superbattledroid", "Super Battle droid", 25000, 0x7f1d80, 1.07f,
		Attack | Shoot | Droid | Gas | Pushable | Zappable | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "commanderpatrol"},

		},
		normalAttack, normalBlock);

	jangofett = new Playable("jangofett", "Jango Fett", 70000, 0x7f1f38, 1.2f,
		Lever | Build | Box | Jump | Fly | Fett | Attack | Shoot | Grapple | Bounty | Chokeable |
			Lightningable | SlightlyHigherJump);

	bobafett_boy = new Playable("bobafett_boy", "Boba Fett (Boy)", 5500, 0x0, 0.8f,
		Lever | Build | Box | Jump | Hatch | Chokeable | Lightningable);

	luminara = new Playable("luminara", "Luminara", 28000, 0x7f1f28, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Chokeable |
			Lightningable);

	kiadimundi = new Playable("kiadimundi", "Ki-Adi Mundi", 30000, 0x0, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Chokeable |
			Lightningable);

	kitfisto = new Playable("kitfisto", "Kit Fisto", 35000, 0x7f1f98, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Chokeable |
			Lightningable);

	shaakti = new Playable("shaakti", "Shaak Ti", 36000, 0x7f1f20, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Chokeable |
			Lightningable);

	aylasecura = new Playable("aylasecura", "Aayla Secura", 37000, 0x0, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Chokeable |
			Lightningable);

	plokoon = new Playable("plokoon", "Plo Koon", 39000, 0x0, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Chokeable |
			Lightningable);

	countdooku = new Playable("countdooku", "Count Dooku", 100000, 0x7f1f88, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Sith | Lightning | Chokeable | Lightningable);

	bodyguard = new Playable("bodyguard", "Grievous' Bodyguard", 24000, 0x7f1c70, 1.4f,
		Jump | DoubleJump | HighJump | ExtraHighJump | Saber | Gas | Tall | Baddy,
		{
			{chatting, "bodyguard"},
			{sniper, "bodyguard"},
			{storm, "bodyguard"},
			{attack, "bodyguard"},
			{block, "bodyguard"},
			{spawnattack, "bodyguard"},
			{patrol, "bodyguard"},

		},
		{"", "AttackOpponent \"range 0.15\"", ""});

	grievous = new Playable("grievous", "General Grievous", 70000, 0x7f1e48, 1.2f,
		Build | Jump | DoubleJump | HighJump | ExtraHighJump | RealDoubleJump | HighDoubleJump | Saber |
			Deflect);

	wookie = new Playable("wookie", "Wookiee", 16000, 0x7f1d58, 1.2f,
		Hat | Lever | Build | Box | Jump | Attack | Shoot | Grapple | Chokeable | Lightningable);

	clone_ep3 = new Playable("clone_ep3", "Clone (Episode III)", 10000, 0x7f1ca8, 1.0f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | Baddy,
		{
			{chatting, "disguisedclone"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "patrol"},

		},

		normalAttack, normalBlock);

	clone_ep3_pilot = new Playable("clone_ep3_pilot", "Clone (Episode III, Pilot)", 11000, 0x0, 1.0f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable);

	clone_ep3_swamp = new Playable("clone_ep3_swamp", "Clone (Episode III, Swamp)", 12000, 0x0, 1.0f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | Baddy,
		{
			{chatting, "disguisedclone"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "patrol"},

		},

		normalAttack, normalBlock);

	clone_ep3_walker = new Playable("clone_ep3_walker", "Clone (Episode III, Walker)", 12000, 0x0, 1.0f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable);

	macewindu_ep3 = new Playable("macewindu_ep3", "Mace Windu (Episode III)", 38000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi |
			Chokeable | Lightningable);

	disguisedclone = new Playable("disguisedclone", "Disguised Clone", 12000, 0x0, 1.0f,
		Lever | Build | Box | Jump | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | Baddy,
		{
			{chatting, "disguisedclone"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "patrol"},

		},

		normalAttack, normalBlock);

	rebelscum = new Playable("rebelscum", "Rebel Trooper", 10000, 0x0, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump);

	stormtrooper = new Playable("stormtrooper", "Stormtrooper", 10000, 0x7f1ff0, 1.2f,
		Lever | Build | Box | Jump | Flop | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump | Storm | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "strolling"},
		},
		normalAttack, normalBlock);

	imperialshuttlepilot = new Playable("imperialshuttlepilot", "imperial Shuttle Pilot", 25000, 0x7f2000, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Imperial | Chokeable |
			Lightningable | Trickable | SlightlyHigherJump | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "strolling"},

		},
		normalAttack, normalBlock);

	tuskenraider = new Playable("tuskenraider", "Tusken Raider", 23000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable |
			Lightningable | Trickable | SlightlyHigherJump | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "patrol"},

		},
		normalAttack, normalBlock);

	jawa = new Playable("jawa", "Jawa", 24000, 0x7f1e88, 0.9f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Zapper | Hatch | Chokeable | Lightningable |
			Trickable | Baddy,
		{
			{chatting, "jawa"},
			{sniper, "jawa"},
			{storm, "jawa"},
			{attack, "jawa"},
			{block, "jawa"},
			{spawnattack, "jawa"},
			{patrol, "jawa"},

		},
		{"", "setState realJawa", funcCustom("realJawa", "jawa", "", "")});

	sandtrooper = new Playable("sandtrooper", "Sandtrooper", 14000, 0x0, 1.2f,
		Lever | Build | Box | Jump | Flop | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump | Storm | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "strolling"},

		},
		normalAttack, normalBlock);

	greedo = new Playable("greedo", "Greedo", 60000, 0x7f2050, 1.3f,
		Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Bounty | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump);

	imperialspy = new Playable("imperialspy", "imperial Spy", 13500, 0x7f2048, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Chokeable | Lightningable | Trickable |
			SlightlyHigherJump);

	beachtrooper = new Playable("beachtrooper", "Beach Trooper", 20000, 0x7f1ff8, 1.2f,
		Lever | Build | Box | Jump | Flop | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump | Storm | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "strolling"},

		},
		normalAttack, normalBlock);

	deathstartrooper = new Playable("deathstartrooper", "Death Star Trooper", 19000, 0x7f1ea8, 1.2f,
		Lever | Build | Box | Jump | Flop | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump | Storm | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "strolling"},

		},
		normalAttack, normalBlock);

	tiefighterpilot = new Playable("tiefighterpilot", "TIE Fighter Pilot", 21000, 0x0, 1.2f,
		Lever | Build | Box | Jump | Flop | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump | Storm | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "strolling"},

		},
		normalAttack, normalBlock);

	imperialofficer = new Playable("imperialofficer", "imperial Officer", 28000, 0x7f2008, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Imperial | Chokeable |
			Lightningable | Trickable | SlightlyHigherJump | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "strolling"},

		},
		normalAttack, normalBlock);

	grandmofftarkin = new Playable("grandmofftarkin", "Grand Moff Tarkin", 38000, 0x7f2010, 1.2f,
		Hat | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Imperial |
			Chokeable | Lightningable | Trickable | SlightlyHigherJump);

	hansolo_hood = new Playable("hansolo_hood", "Han Solo (Hood)", 20000, 0x0, 1.44f,
		Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable);

	rebelhoth = new Playable("rebelhoth", "Rebel Trooper (Hoth)", 16000, 0x0, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump);

	rebelpilot = new Playable("rebelpilot", "Rebel Pilot", 15000, 0x0, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump);

	snowtrooper = new Playable("snowtrooper", "Snowtrooper", 16000, 0x7f1ea0, 1.2f,
		Lever | Build | Box | Jump | Flop | Attack | Shoot | Grapple | Imperial | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump | Storm | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "strolling"},

		},
		normalAttack, normalBlock);

	lukeskywalker_hoth = new Playable("lukeskywalker_hoth", "Luke Skywalker (Hoth)", 14000, 0x0, 1.2f,
		Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable |
			SlightlyHigherJump);

	lobot = new Playable("lobot", "Lobot", 11000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Chokeable | Lightningable | Trickable |
			SlightlyHigherJump);

	ugnaught = new Playable("ugnaught", "Ugnaught", 36000, 0x7f1fd8, 0.9f,
		Lever | Build | Box | Jump | Zapper | Hatch | Chokeable | Lightningable | Trickable | Baddy,
		{
			{chatting, "jawa"},
			{sniper, "jawa"},
			{storm, "jawa"},
			{attack, "jawa"},
			{block, "jawa"},
			{spawnattack, "jawa"},
			{patrol, "jawa"},

		},
		{"", "setState realJawa", funcCustom("realJawa", "jawa", "", "")});

	bespinguard = new Playable("bespinguard", "Bespin Guard", 15000, 0x0, 1.3f,
		Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable | Trickable |
			SlightlyHigherJump);

	princessleia_prisoner = new Playable("princessleia_prisoner", "Princess Leia (Prisoner)", 22000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable |
			Lightningable | SlightlyHigherJump | LeiaAlt);

	gamorreanguard = new Playable("gamorreanguard", "Gamorrean Guard", 40000, 0x7f1c80, 0.75f,
		Lever | Build | Box | Jump | Attack | Chokeable | Lightningable | Trickable | Baddy,
		{
			{chatting, "gamorreanguard"},
			{sniper, "gamorreanguard"},
			{storm, "gamorreanguard"},
			{attack, "gamorreanguard"},
			{block, "gamorreanguard"},
			{spawnattack, "gamorreanguard"},
			{patrol, "gamorreanguard"},

		},
		{"", "AttackOpponent \"range 0.20\"", ""});

	bibfortuna = new Playable("bibfortuna", "Bib Fortuna", 16000, 0x0, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Chokeable | Lightningable | Trickable |
			SlightlyHigherJump);

	palaceguard = new Playable("palaceguard", "Palace Guard", 14000, 0x0, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump);

	bossk = new Playable("bossk", "Bossk", 75000, 0x7f2058, 1.3f,
		Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Bounty | Chokeable | Lightningable |
			Trickable);

	skiffguard = new Playable("skiffguard", "Skiff Guard", 12000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable |
			Lightningable | Trickable | SlightlyHigherJump | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "patrol"},

		},
		normalAttack, normalBlock);

	bobafett = new Playable("bobafett", "Boba Fett", 100000, 0x7f1d88, 1.2f,
		Lever | Build | Box | Jump | Fly | Fett | Attack | Shoot | Grapple | Bounty | Chokeable |
			Lightningable | SlightlyHigherJump);

	ewok = new Playable("ewok", "Ewok", 34000, 0x7f1dc0, 0.9f,
		Lever | Build | Box | Jump | Attack | Shoot | Hatch | Chokeable | Lightningable | Trickable);

	imperialguard = new Playable("imperialguard", "imperial Guard", 45000, 0x7f1c68, 1.2f,
		Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Imperial | Chokeable | Lightningable |
			Trickable | SlightlyHigherJump | Storm | Baddy,
		{
			{chatting, "impguard"},
			{sniper, "impguard"},
			{storm, "impguard"},
			{attack, "impguard"},
			{block, "impguard"},
			{spawnattack, "impguard"},
			{patrol, "impguard"},

		},
		{"", "AttackOpponent \"range 0.15\"", ""});

	theemperor = new Playable("theemperor", "The Emperor", 275000, 0x7f1eb8, 1.2f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Saber | Deflect | Jedi | Sith |
			Lightning | Imperial | Chokeable | Lightningable);

	admiralackbar = new Playable("admiralackbar", "Admiral Ackbar", 33000, 0x0, 1.44f,
		Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Dive | Attack | Shoot | Grapple | Chokeable |
			Lightningable | SlightlyHigherJump);

	ig88 = new Playable("ig88", "IG-88", 100000, 0x0, 1.2f,
		Box | Jump | Attack | Shoot | Grapple | Astro | Proto | Bounty | Droid | Gas | Pushable | Chokeable |
			Lightningable | Zappable | SlightlyHigherJump | AllEpisodes);

	dengar = new Playable("dengar", "Dengar", 70000, 0x0, 1.3f,
		Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Bounty | Chokeable | Lightningable |
			Trickable | AllEpisodes);

	fourlom = new Playable("4lom", "4-LOM", 45000, 0x7f1d90, 1.2f,
		Box | Jump | Attack | Shoot | Grapple | Astro | Proto | Bounty | Droid | Gas | Pushable | Chokeable |
			Lightningable | Zappable | AllEpisodes);

	ghostbenkenobi = new Playable("ghostbenkenobi", "Ben Kenobi (Ghost)", 1100000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Deflect | Jedi | Passive |
			Gas | AllEpisodes);

	anakin_ghost = new Playable("anakin_ghost", "Anakin Skywalker (Ghost)", 1000000, 0x0, 1.2f,
		Hat | Lever | Build | Box | Jump | DoubleJump | RealDoubleJump | Attack | Deflect | Jedi | Passive |
			Gas | AllEpisodes);

	yoda_ghost = new Playable("yoda_ghost", "Yoda (Ghost)", 1200000, 0x7f1d10, 1.44f,
		Lever | Build | Box | Jump | DoubleJump | YodaJump | RealDoubleJump | Attack | Deflect | Jedi |
			Passive | Gas | AllEpisodes);

	r2q5 = new Playable("r2q5", "R2-Q5", 100000, 0x7f1fa8, 1.0f,
		Fly | Zapper | AstroZapper | Astro | Droid | Passive | Gas | Pushable | Zappable | AllEpisodes);

	hansolo_indy = new Playable("hansolo_indy", "Indiana Jones", 50000, 0x7f20c0, 1.44f,
		Hat | Lever | Build | Box | Jump | Dive | Attack | Shoot | Grapple | Chokeable | Lightningable |
			AllEpisodes);

	skeleton = new Playable("skeleton", "Skeleton", 3000, 0x7f20d0, 1.2f, Extratoggle);

	buzzdroid = new Playable("buzzdroid", "Buzz droid", 1500, 0x7f20a0, 1.2f,
		Extratoggle | Attack | Droid | Gas | Pushable | Zappable);

	trainingremote = new Playable("trainingremote", "Training Remote", 2000, 0x7f1d98, 1.05f,
		Extratoggle | Hovering | FakeShoot | Droid | Gas /*| Baddy*/,
		{
			{chatting, "trainingremote"},
			{sniper, "trainingremote"},
			{storm, "trainingremote"},
			{attack, "trainingremote"},
			{block, "trainingremote"},
			{spawnattack, "trainingremote"},
			{patrol, "trainingremote"},
		},

		{"SetSide \"Baddy\"\n\t\tSetCircleDirection \"Random\"\n\t\tSetState \"NotCircle0\"", "",
			funcNoRef("NotCircle", "if Timer > 1 goto CircleAttack0\n\t\t1",
				"ResetTimer\n\t\tEngageOpponent \"goalrange 0.5\" \"firerange 1\"")
				funcNoRef("CircleAttack", "if Timer > 1 goto NotCircle0\n\t\t1",
					"ResetTimer\n\t\tEngageOpponent \"goalrange 0.5\" \"firerange 1\" \"circle\"")},
		normalBlock);

	engineer = new Playable("engineer", "Rebel Engineer", 8000, 0x0, 1.2f,
		Extratoggle | Lever | Build | Box | Jump | SlightlyBetterJump | Attack | Shoot | Grapple | Chokeable |
			Lightningable | Trickable | SlightlyHigherJump);

	naffdroid1 = new Playable("naffdroid1", "droid 1", 1500, 0x7f1cb8, 0.6f,
		Extratoggle | Shoot | Droid | Passive | Gas | Pushable | Zappable);

	naffdroid2 = new Playable("naffdroid2", "droid 2", 1500, 0x7f1cc0, 0.6f,
		Extratoggle | Shoot | Droid | Passive | Gas | Pushable | Zappable);

	naffdroid3 = new Playable("naffdroid3", "droid 3", 1500, 0x7f1cc8, 0.4f,
		Extratoggle | Shoot | Droid | Passive | Gas | Pushable | Zappable);

	naffdroid4 = new Playable("naffdroid4", "droid 4", 1500, 0x7f1cd0, 0.6f,
		Extratoggle | Shoot | Droid | Passive | Gas | Pushable | Zappable);

	womprat = new Playable("womprat", "Womp Rat", 25000, 0x7f1d00, 1.8f, Extratoggle | Passive);

	mousedroid = new Playable("mousedroid", "Mouse droid", 3000, 0x7f1cd8, 2.4f,
		Extratoggle | Droid | Passive | Gas | Pushable | Zappable);

	imperialengineer = new Playable("imperialengineer", "imperial Engineer", 9000, 0x0, 1.2f,
		Extratoggle | Lever | Build | Box | Jump | Flop | Attack | Shoot | Grapple | Imperial | Chokeable |
			Lightningable | Trickable | SlightlyHigherJump | Storm);

	hanincarbonite =
		new Playable("hanincarbonite", "Han Solo (frozen in carbonite)", 5000, 0x0, 0.75f, Extratoggle);

	atat_driver = new Playable("atat_driver", "AT-AT Driver", 25000, 0x0, 1.2f,
		Extratoggle | Lever | Build | Box | Jump | Flop | Attack | Shoot | Grapple | Imperial | Chokeable |
			Lightningable | Trickable | SlightlyHigherJump | Storm);

	scouttrooper = new Playable("scouttrooper", "Scout Trooper", 16000, 0x0, 1.2f,
		Extratoggle | Lever | Build | Box | Jump | Flop | Attack | Shoot | Grapple | Imperial | Chokeable |
			Lightningable | Trickable | SlightlyHigherJump | Storm | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "strolling"},

		},
		normalAttack, normalBlock);

	newanakinspod = new Playable("newanakinspod", "Anakin's Pod", 20000, 0x7f21e0, 1.2f, Vehicle);

	naboostarfighter = new Playable(
		"naboostarfighter", "Naboo Starfighter", 12000, 0x7f20b0, 1.2f, Vehicle | Attack | Shoot | Tow);

	anakinsspeeder =
		new Playable("anakinsspeeder", "Anakin's Speeder", 15000, 0x7f21f0, 1.2f, Vehicle | Attack | Shoot);

	newrepublicgunship = new Playable(
		"newrepublicgunship", "Republic Gunship", 18000, 0x7f1f78, 1.2f, Vehicle | Attack | Shoot | Tow);

	jedistarfighter_yellow_ep3 = new Playable("jedistarfighter_yellow_ep3", "jedi Starfighter (Yellow)", 10000,
		0x7f1f40, 1.2f, Vehicle | Attack | Shoot);

	jedistarfighter_red_ep3 = new Playable(
		"jedistarfighter_red_ep3", "jedi Starfighter (Red)", 10000, 0x7f1f48, 1.2f, Vehicle | Attack | Shoot);

	xwing = new Playable("xwing", "X-wing", 25000, 0x7f1fb0, 1.2f, Vehicle | Attack | Shoot);

	ywing = new Playable("ywing", "Y-wing", 25000, 0x7f1e38, 1.2f, Vehicle | Attack | Shoot);

	snowspeeder = new Playable("snowspeeder", "Snowspeeder", 20000, 0x7f1fc0, 1.2f, Vehicle | Attack | Shoot | Tow);

	millenniumfalcon =
		new Playable("millenniumfalcon", "Millennium Falcon", 40000, 0x7f1ec0, 1.2f, Vehicle | Attack | Shoot);

	sebulbaspod = new Playable("sebulbaspod", "Sebulba's Pod", 20000, 0x7f21c0, 1.2f, Vehicle);

	zamsspeeder = new Playable("zamsspeeder", "Zam's Airspeeder", 24000, 0x7f2200, 1.2f, Vehicle | Attack | Shoot);

	droidtrifighter =
		new Playable("droidtrifighter", "droid Trifighter", 28000, 0x7f2210, 1.2f, Vehicle | Attack | Shoot);

	vulturedroid = new Playable("vulturedroid", "Vulture droid", 30000, 0x7f2208, 1.2f, Vehicle | Attack | Shoot);

	clonearc = new Playable("clonearc", "Clone Arcfighter", 33000, 0x7f20a8, 1.2f, Vehicle | Attack | Shoot);

	tiefighter =
		new Playable("tiefighter", "TIE Fighter", 35000, 0x7f1e58, 1.2f, Vehicle | Attack | Shoot | TieDoor);

	tieinterceptor = new Playable(
		"tieinterceptor", "TIE Interceptor", 40000, 0x7f1fc8, 1.2f, Vehicle | Attack | Shoot | TieDoor);

	tiefighterdarth = new Playable("tiefighterdarth", "TIE Fighter (Darth Vader)", 50000, 0x7f1e50, 1.2f,
		Vehicle | Attack | Shoot | TieDoor);

	tiebomber = new Playable("tiebomber", "TIE Bomber", 60000, 0x7f1e40, 1.2f, Vehicle | Attack | Shoot | TieDoor);

	imperialshuttle =
		new Playable("imperialshuttle", "imperial Shuttle", 25000, 0x7f1fd0, 1.2f, Vehicle | Attack | Shoot);

	slave1 = new Playable("slave1", "Slave 1", 100000, 0x7f1e30, 1.2f, Vehicle | Attack | Shoot | AllEpisodes);

	newanakinspod_green =
		new Playable("newanakinspod_green", "Anakin's Pod (Green)", 20000, 0x7f21b8, 1.2f, Vehicle | Vgreen);

	naboostarfighter_lime = new Playable("naboostarfighter_lime", "Naboo Starfighter (Green)", 12000, 0x7f20b8,
		1.2f, Vehicle | Vgreen | Attack | Shoot | Tow);

	anakinsspeeder_green = new Playable("anakinsspeeder_green", "Anakin's Speeder (Green)", 15000, 0x7f21f8, 1.2f,
		Vehicle | Vgreen | Attack | Shoot);

	newrepublicgunship_green = new Playable("newrepublicgunship_green", "Republic Gunship (Green)", 18000, 0x7f1f80,
		1.2f, Vehicle | Vgreen | Attack | Shoot | Tow);

	defaultCharacter = new Playable("", "", 0, 0, 0.0f, Fake);

	//podrace original uses a different version of the pods
	fakeAnakinsPod = new Playable("anakinspod", "", 0, 0, 0.0f, Fake | Vehicle);

	fakeAnakinsPodGreen = new Playable("anakinspod_green", "", 0, 0, 0.0f, Fake | Vehicle);

	kaminodroid = new Playable("kaminoandroid", "", 0, 0x7f1fe8, 1.05f, Fake | Shoot | Hovering | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "patrol"},

		},
		normalAttack, normalBlock);

	sentrydroid = new Playable("sentrydroid", "", 0, 0x7f1fe0, 1.2f, Fake | Shoot | Hovering | Baddy,
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{spawnattack, "spawnattack"},
			{patrol, "patrol"},

		},
		normalAttack, normalBlock);

	bat = new Playable("bat", "", 0, 0x7f1cf8, 0.75f, Fake | Hovering | Baddy,
		{
			{chatting, "bat"},
			{sniper, "bat"},
			{storm, "bat"},
			{attack, "bat"},
			{block, "bat"},
			{spawnattack, "bat"},
			{patrol, "bat"},
		},
		{"SetGravityHeight \"reset\"", "if CollidingWithOpponent == 1 goto HitOpponent0\n\t\t1",
			funcNoRef("HitOpponent", "1", "TakeDamage \"opponent\"\n\t\tSetState \"Circle\"")
				funcNoRef("Circle", "if Timer > 2 goto Attack1",
					"ResetTimer \"mintime=0\" \"maxtime=1\"\n\t\tSetCircleDirection "
					"\"Reverse\"\n\t\tCircleOpponent "
					"\"0.5\" \"can_go_off_path\"")},
		{"SetGravityHeight \"reset\"", "if CollidingWithOpponent == 1 goto HitOpponent0\n\t\t1",
			funcNoRef("HitOpponent", "1", "TakeDamage \"opponent\"\n\t\tSetState \"Circle\"")
				funcNoRef("Circle", "if Timer > 2 goto Attack1",
					"ResetTimer \"mintime=0\" \"maxtime=1\"\n\t\tSetCircleDirection "
					"\"Reverse\"\n\t\tCircleOpponent "
					"\"0.5\" \"can_go_off_path\"")});

	SpecialScripts = {{bat, "bat"}, {jawa, "jawa"}, {ugnaught, "jawa"}, {bodyguard, "bodyguard"},
		{trainingremote, "trainingremote"}, {gamorreanguard, "gamorreanguard"}, {imperialguard, "impguard"}};
}
