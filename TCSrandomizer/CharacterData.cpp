#include "CharacterData.h"
#include "Characters.h"
#include "Defines.h"
#include "externData.h"
#include "pch.h"

void makeCharactersAndLevels() {
	quigonjinn = new Playable("quigonjinn", "Qui-Gon Jinn", 25000, 0x7f1c30, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	obiwankenobi = new Playable("obiwankenobi", "Obi-Wan Kenobi", 22000, 0x7f1c38, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	tc14 = new Playable(
		"tc14", "TC-14", 4000, 0x7f202c, 0.75f, {Proto, Droid, Passive, Gas, Pushable, Zappable});

	jarjarbinks = new Playable("jarjarbinks", "Jar Jar Binks", 14000, 0x7f1f00, 1.32f,
		{Build, Box, Jump, DoubleJump, HighJump, RealDoubleJump, HighDoubleJump, GunganJump,
			Chokeable, Lightningable, Trickable});

	amidala = new Playable("amidala", "Queen Amidala", 24000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable, Lightningable,
			SlightlyHigherJump});

	captainpanaka = new Playable("captainpanaka", "Captain Panaka", 12000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable, Lightningable});

	padmebattle = new Playable("padmebattle", "Padmé (Battle)", 20000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable, Lightningable});

	r2d2 = new Playable("r2d2", "R2-D2", 5000, 0x7f1fa0, 1.0f,
		{Fly, Zapper, AstroZapper, Astro, Droid, Passive, Gas, Pushable, Zappable});

	anakin_boy = new Playable("anakin_boy", "Anakin Skywalker (Boy)", 6000, 0x0, 0.8f,
		{Lever, Build, Box, Jump, Hatch, Chokeable, Lightningable});

	obiwankenobi_jedimaster = new Playable("obiwankenobi_jedimaster",
		"Obi-Wan Kenobi (jedi Master)", 30000, 0x7f1f18, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	r4_p17 = new Playable("r4_p17", "R4-P17", 4000, 0x0, 1.0f,
		{Fly, Zapper, AstroZapper, Astro, Droid, Passive, Gas, Pushable, Zappable});

	anakin_padawan =
		new Playable("anakin_padawan", "Anakin Skywalker (Padawan)", 24000, 0x7f1f10, 1.2f,
			{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
				Chokeable, Lightningable});

	padmegeo = new Playable("padmegeo", "Padmé (Geonosis)", 20000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable, Lightningable});

	c3po = new Playable(
		"c3po", "C-3PO", 5000, 0x7f2020, 0.75f, {Proto, Droid, Passive, Gas, Pushable, Zappable});

	macewindu = new Playable("macewindu", "Mace Windu", 36000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	padmeclawed = new Playable("padmeclawed", "Padmé (Clawed)", 20000, 0x7f1f08, 1.2f,
		{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable, Lightningable});

	yoda = new Playable("yoda", "Yoda", 80000, 0x7f1d08, 1.44f,
		{Lever, Build, Box, Jump, DoubleJump, YodaJump, RealDoubleJump, Attack, Saber, Deflect,
			Jedi, ResistZap});

	obiwankenobi_ep3 =
		new Playable("obiwankenobi_ep3", "Obi-Wan Kenobi (Episode III)", 300000, 0x7f1f58, 1.2f,
			{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
				Chokeable, Lightningable});

	anakin_jedi = new Playable("anakin_jedi", "Anakin Skywalker (jedi)", 35000, 0x7f1f60, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	palpatine = new Playable("palpatine", "Chancellor Palpatine", 8000, 0x7f1f90, 1.2f,
		{Hat, Lever, Build, Box, Jump, Chokeable, Lightningable});

	clone_ep3_sand = new Playable("clone_ep3_sand", "Commander Cody", 12000, 0x7f1cb0, 1.0f,
		{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable},
		{
			{chatting, "disguisedclone"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "patrol"},
		});

	chewbacca = new Playable("chewbacca", "Chewbacca", 18000, 0x7f1d50, 1.2f,
		{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable, Lightningable});

	princessleia = new Playable("princessleia", "Princess Leia", 20000, 0x7f1c40, 1.2f,
		{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, SlightlyHigherJump, LeiaAlt});

	captainantilles = new Playable("captainantilles", "Captain Antilles", 14000, 0x7f1c58, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump});

	rebelfriend = new Playable("rebelfriend", "Rebel Friend", 15000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump});

	lukeskywalker_tatooine =
		new Playable("lukeskywalker_tatooine", "Luke Skywalker (Tatooine)", 12000, 0x0, 1.2f,
			{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable,
				SlightlyHigherJump});

	benkenobi = new Playable("benkenobi", "Ben Kenobi", 30000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	hansolo = new Playable("hansolo", "Han Solo", 18000, 0x0, 1.44f,
		{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable});

	hansolo_stormtrooper =
		new Playable("hansolo_stormtrooper", "Han Solo (Stormtrooper)", 20000, 0x0, 1.44f,
			{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable});

	lukeskywalker_stormtrooper = new Playable("lukeskywalker_stormtrooper",
		"Luke Skywalker (Stormtrooper)", 14000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable,
			SlightlyHigherJump});

	hansolo_hoth = new Playable("hansolo_hoth", "Han Solo (Hoth)", 20000, 0x0, 1.44f,
		{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable});

	princessleia_hoth = new Playable("princessleia_hoth", "Princess Leia (Hoth)", 22000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, SlightlyHigherJump, LeiaAlt});

	lukeskywalker_pilot =
		new Playable("lukeskywalker_pilot", "Luke Skywalker (Pilot)", 14000, 0x0, 1.2f,
			{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable,
				SlightlyHigherJump});

	lukeskywalker_dagobah =
		new Playable("lukeskywalker_dagobah", "Luke Skywalker (Dagobah)", 28000, 0x7f1e90, 1.2f,
			{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
				Chokeable, Lightningable, LukeAlt});

	lukeskywalker_bespin =
		new Playable("lukeskywalker_bespin", "Luke Skywalker (Bespin)", 30000, 0x0, 1.2f,
			{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
				Chokeable, Lightningable, LukeAlt});

	landocalrissian = new Playable("landocalrissian", "Lando Calrissian", 15000, 0x0, 1.28f,
		{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump, LandoAlt});

	princessleia_bespin =
		new Playable("princessleia_bespin", "Princess Leia (Bespin)", 22000, 0x0, 1.2f,
			{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
				Lightningable, SlightlyHigherJump, LeiaAlt});

	lukeskywalker_jedi =
		new Playable("lukeskywalker_jedi", "Luke Skywalker (jedi)", 40000, 0x0, 1.2f,
			{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
				Chokeable, Lightningable, LukeAlt});

	princessleia_boushh =
		new Playable("princessleia_boushh", "Princess Leia (Boushh)", 22000, 0x7f1c50, 1.2f,
			{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
				Lightningable, SlightlyHigherJump, LeiaAlt});

	lando_palaceguard = new Playable("lando_palaceguard", "Lando (Palace Guard)", 15000, 0x0, 1.28f,
		{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable, Trickable,
			SlightlyHigherJump, LandoAlt});

	hansolo_skiff = new Playable("hansolo_skiff", "Han Solo (Skiff)", 20000, 0x0, 1.44f,
		{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable});

	princessleia_slave =
		new Playable("princessleia_slave", "Princess Leia (Slave)", 40000, 0x7f1c48, 1.2f,
			{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
				Lightningable, SlightlyHigherJump, LeiaAlt});

	princessleia_endor =
		new Playable("princessleia_endor", "Princess Leia (Endor)", 22000, 0x0, 1.2f,
			{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
				Lightningable, SlightlyHigherJump, LeiaAlt});

	lukeskywalker_endor =
		new Playable("lukeskywalker_endor", "Luke Skywalker (Endor)", 42000, 0x0, 1.2f,
			{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
				Chokeable, Lightningable, LukeAlt});

	hansolo_endor = new Playable("hansolo_endor", "Han Solo (Endor)", 20000, 0x0, 1.44f,
		{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable});

	wicket = new Playable("wicket", "Wicket", 38000, 0x7f1dc8, 0.9f,
		{Lever, Build, Box, Jump, Attack, Shoot, Hatch, Chokeable, Lightningable, Trickable});

	darthvader = new Playable("darthvader", "Darth Vader", 150000, 0x7f1eb0, 1.2f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith,
			Choke, Imperial, Chokeable, ResistZap});

	gonkdroid = new Playable("gonkdroid", "Gonk droid", 3000, 0x7f2018, 0.12f,
		{Droid, Passive, Gas, Pushable, Zappable, NoLevel});

	pkdroid = new Playable("pkdroid", "PK droid", 1500, 0x7f1ce8, 0.828538f,
		{Droid, Passive, Gas, Pushable, Zappable, NoLevel});

	battledroid = new Playable("battledroid", "Battle droid", 6500, 0x7f1c88, 1.2f,
		{Attack, Shoot, Droid, Gas, Pushable, Zappable},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "commanderpatrol"},
		});
	battledroid_security = new Playable("battledroid_security", "Battle droid (Security)", 8500,
		0x7f1ca0, 1.2f, {Attack, Shoot, Droid, Gas, Pushable, Zappable},
		{

			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "commanderpatrol"},
		});

	battledroid_commander = new Playable("battledroid_commander", "Battle droid (Commander)", 10000,
		0x7f1c90, 1.2f, {Attack, Shoot, Droid, Gas, Pushable, Zappable},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "commanderpatrol"},

		}

	);

	destroyer = new Playable("destroyer", "droideka", 40000, 0x7f1d78, 1.8f,
		{Attack, Shoot, Droid, Gas, Zappable},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "storm"},
		});

	captaintarpals = new Playable("captaintarpals", "Captain Tarpals", 17500, 0x7f1c60, 1.32f,
		{Build, Box, Jump, DoubleJump, HighJump, RealDoubleJump, HighDoubleJump, GunganJump, Attack,
			Chokeable, Lightningable, Trickable});

	bossnass = new Playable("bossnass", "Boss Nass", 15000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, Chokeable, Lightningable, Trickable});

	royalguard = new Playable("royalguard", "Royal Guard", 10000, 0x7f1fb8, 1.2f,
		{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable, Lightningable});

	padme = new Playable("padme", "Padmé", 20000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable, Lightningable});

	watto = new Playable("watto", "Watto", 16000, 0x7f1d38, 1.5f, {Flutter, Zapper});

	pitdroid = new Playable(
		"pitdroid", "Pit droid", 4000, 0x7f2068, 0.8f, {Droid, Passive, Gas, Pushable, Zappable});

	darthmaul = new Playable("darthmaul", "Darth Maul", 60000, 0x7f1c78, 1.2f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith,
			Chokeable, Lightningable});

	zamwesell = new Playable("zamwesell", "Zam Wesell", 27500, 0x0, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Bounty, Chokeable,
			Lightningable, Trickable});

	dexter = new Playable("dexter", "Dexter Jettster", 10000, 0x0, 1.0f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Chokeable, Lightningable, Trickable,
			SlightlyHigherJump});

	clone = new Playable("clone", "Clone", 13000, 0x0, 1.0f,
		{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable});

	lamasu = new Playable("lamasu", "Lama Su", 9000, 0x7f2090, 1.2f,
		{Lever, Build, Box, Jump, Tall, Chokeable, Lightningable});

	taunwe = new Playable("taunwe", "Taun We", 9000, 0x7f2098, 1.2f,
		{Lever, Build, Box, Jump, Chokeable, Lightningable});

	geonosian = new Playable("geonosian", "Geonosian", 20000, 0x7f1d30, 1.5f,
		{Lever, Flutter, Attack, Shoot, Pushable, Chokeable, Lightningable},
		{
			{chatting, "storm"}, //maybe chatting?
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "storm"}, //storm
			{block, "storm"},
			{patrol, "storm"},
		});

	battledroid_geonosian = new Playable("battledroid_geonosian", "Battle droid (Geonosis)", 8500,
		0x7f1c98, 1.2f, {Attack, Shoot, Droid, Gas, Pushable, Zappable},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "commanderpatrol"},
		});

	superbattledroid = new Playable("superbattledroid", "Super Battle droid", 25000, 0x7f1d80,
		1.07f, {Attack, Shoot, Droid, Gas, Pushable, Zappable},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "commanderpatrol"},

		});

	jangofett = new Playable("jangofett", "Jango Fett", 70000, 0x7f1f38, 1.2f,
		{Lever, Build, Box, Jump, Fly, Fett, Attack, Shoot, Grapple, Bounty, Chokeable,
			Lightningable, SlightlyHigherJump});

	bobafett_boy = new Playable("bobafett_boy", "Boba Fett (Boy)", 5500, 0x0, 0.8f,
		{Lever, Build, Box, Jump, Hatch, Chokeable, Lightningable});

	luminara = new Playable("luminara", "Luminara", 28000, 0x7f1f28, 1.2f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	kiadimundi = new Playable("kiadimundi", "Ki-Adi Mundi", 30000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	kitfisto = new Playable("kitfisto", "Kit Fisto", 35000, 0x7f1f98, 1.2f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	shaakti = new Playable("shaakti", "Shaak Ti", 36000, 0x7f1f20, 1.2f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	aylasecura = new Playable("aylasecura", "Aayla Secura", 37000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	plokoon = new Playable("plokoon", "Plo Koon", 39000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	countdooku = new Playable("countdooku", "Count Dooku", 100000, 0x7f1f88, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Sith, Lightning, Chokeable, Lightningable});

	bodyguard = new Playable("bodyguard", "Grievous' Bodyguard", 24000, 0x7f1c70, 1.4f,
		{Jump, DoubleJump, HighJump, ExtraHighJump, Saber, Gas, Tall},
		{
			{chatting, "bodyguard"},
			{sniper, "bodyguard"},
			{storm, "bodyguard"},
			{attack, "bodyguard"},
			{block, "bodyguard"},
			{patrol, "bodyguard"},
		});

	grievous = new Playable("grievous", "General Grievous", 70000, 0x7f1e48, 1.2f,
		{Build, Jump, DoubleJump, HighJump, ExtraHighJump, RealDoubleJump, HighDoubleJump, Saber,
			Deflect});

	wookie = new Playable("wookie", "Wookiee", 16000, 0x7f1d58, 1.2f,
		{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable, Lightningable});

	clone_ep3 = new Playable("clone_ep3", "Clone (Episode III)", 10000, 0x7f1ca8, 1.0f,
		{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable},
		{
			{chatting, "disguisedclone"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "patrol"},
		});

	clone_ep3_pilot =
		new Playable("clone_ep3_pilot", "Clone (Episode III, Pilot)", 11000, 0x0, 1.0f,
			{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
				Trickable});

	clone_ep3_swamp =
		new Playable("clone_ep3_swamp", "Clone (Episode III, Swamp)", 12000, 0x0, 1.0f,
			{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
				Trickable},
			{
				{chatting, "disguisedclone"},
				{sniper, "sniper"},
				{storm, "storm"},
				{attack, "attack"},
				{block, "block"},
				{patrol, "patrol"},
			});

	clone_ep3_walker =
		new Playable("clone_ep3_walker", "Clone (Episode III, Walker)", 12000, 0x0, 1.0f,
			{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
				Trickable});

	macewindu_ep3 = new Playable("macewindu_ep3", "Mace Windu (Episode III)", 38000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi,
			Chokeable, Lightningable});

	disguisedclone = new Playable("disguisedclone", "Disguised Clone", 12000, 0x0, 1.0f,
		{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable},
		{
			{chatting, "disguisedclone"},
			{sniper, "sniper"},
			{storm, "storm"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "patrol"},
		});

	rebelscum = new Playable("rebelscum", "Rebel Trooper", 10000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump});

	stormtrooper = new Playable("stormtrooper", "Stormtrooper", 10000, 0x7f1ff0, 1.2f,
		{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump, Storm},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "strolling"},
		});

	imperialshuttlepilot =
		new Playable("imperialshuttlepilot", "imperial Shuttle Pilot", 25000, 0x7f2000, 1.2f,
			{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Imperial,
				Chokeable, Lightningable, Trickable, SlightlyHigherJump},
			{
				{chatting, "chatting"},
				{sniper, "sniper"},
				{storm, "chatting"},
				{attack, "attack"},
				{block, "chatting"},
				{patrol, "chatting"},
			});

	tuskenraider = new Playable("tuskenraider", "Tusken Raider", 23000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "chatting"},
			{block, "chatting"},
			{patrol, "chatting"},
		});

	jawa = new Playable("jawa", "Jawa", 24000, 0x7f1e88, 0.9f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Zapper, Hatch, Chokeable, Lightningable,
			Trickable},
		{
			{chatting, "jawa"},
			{sniper, "jawa"},
			{storm, "jawa"},
			{attack, "jawa"},
			{block, "jawa"},
			{patrol, "jawa"},
		});

	sandtrooper = new Playable("sandtrooper", "Sandtrooper", 14000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump, Storm},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "strolling"},
		});

	greedo = new Playable("greedo", "Greedo", 60000, 0x7f2050, 1.3f,
		{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Bounty, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump});

	imperialspy = new Playable("imperialspy", "imperial Spy", 13500, 0x7f2048, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Chokeable, Lightningable, Trickable,
			SlightlyHigherJump});

	beachtrooper = new Playable("beachtrooper", "Beach Trooper", 20000, 0x7f1ff8, 1.2f,
		{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump, Storm},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "strolling"},
		});

	deathstartrooper = new Playable("deathstartrooper", "Death Star Trooper", 19000, 0x7f1ea8, 1.2f,
		{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump, Storm},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "strolling"},
		});

	tiefighterpilot = new Playable("tiefighterpilot", "TIE Fighter Pilot", 21000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump, Storm},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "strolling"},
		});

	imperialofficer = new Playable("imperialofficer", "imperial Officer", 28000, 0x7f2008, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Imperial, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "attack"},
			{block, "chatting"},
			{patrol, "chatting"},
		});

	grandmofftarkin = new Playable("grandmofftarkin", "Grand Moff Tarkin", 38000, 0x7f2010, 1.2f,
		{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Imperial,
			Chokeable, Lightningable, Trickable, SlightlyHigherJump});

	hansolo_hood = new Playable("hansolo_hood", "Han Solo (Hood)", 20000, 0x0, 1.44f,
		{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable});

	rebelhoth = new Playable("rebelhoth", "Rebel Trooper (Hoth)", 16000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump});

	rebelpilot = new Playable("rebelpilot", "Rebel Pilot", 15000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump});

	snowtrooper = new Playable("snowtrooper", "Snowtrooper", 16000, 0x7f1ea0, 1.2f,
		{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump, Storm},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "strolling"},
		});

	lukeskywalker_hoth =
		new Playable("lukeskywalker_hoth", "Luke Skywalker (Hoth)", 14000, 0x0, 1.2f,
			{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable,
				SlightlyHigherJump});

	lobot = new Playable("lobot", "Lobot", 11000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump});

	ugnaught = new Playable("ugnaught", "Ugnaught", 36000, 0x7f1fd8, 0.9f,
		{Lever, Build, Box, Jump, Zapper, Hatch, Chokeable, Lightningable, Trickable},
		{
			{chatting, "jawa"},
			{sniper, "jawa"},
			{storm, "jawa"},
			{attack, "jawa"},
			{block, "jawa"},
			{patrol, "jawa"},
		});

	bespinguard = new Playable("bespinguard", "Bespin Guard", 15000, 0x0, 1.3f,
		{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable, Trickable,
			SlightlyHigherJump});

	princessleia_prisoner =
		new Playable("princessleia_prisoner", "Princess Leia (Prisoner)", 22000, 0x0, 1.2f,
			{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
				Lightningable, SlightlyHigherJump, LeiaAlt});

	gamorreanguard = new Playable("gamorreanguard", "Gamorrean Guard", 40000, 0x7f1c80, 0.75f,
		{Lever, Build, Box, Jump, Attack, Chokeable, Lightningable, Trickable},
		{
			{chatting, "gamorreanguard"},
			{sniper, "gamorreanguard"},
			{storm, "gamorreanguard"},
			{attack, "gamorreanguard"},
			{block, "gamorreanguard"},
			{patrol, "gamorreanguard"},
		});

	bibfortuna = new Playable("bibfortuna", "Bib Fortuna", 16000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Chokeable, Lightningable, Trickable,
			SlightlyHigherJump});

	palaceguard = new Playable("palaceguard", "Palace Guard", 14000, 0x0, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump});

	bossk = new Playable("bossk", "Bossk", 75000, 0x7f2058, 1.3f,
		{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Bounty, Chokeable, Lightningable,
			Trickable});

	skiffguard = new Playable("skiffguard", "Skiff Guard", 12000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "strolling"},
		});

	bobafett = new Playable("bobafett", "Boba Fett", 100000, 0x7f1d88, 1.2f,
		{Lever, Build, Box, Jump, Fly, Fett, Attack, Shoot, Grapple, Bounty, Chokeable,
			Lightningable, SlightlyHigherJump});

	ewok = new Playable("ewok", "Ewok", 34000, 0x7f1dc0, 0.9f,
		{Lever, Build, Box, Jump, Attack, Shoot, Hatch, Chokeable, Lightningable, Trickable});

	imperialguard = new Playable("imperialguard", "imperial Guard", 45000, 0x7f1c68, 1.2f,
		{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Imperial, Chokeable, Lightningable,
			Trickable, SlightlyHigherJump, Storm},
		{
			{chatting, "impguard"},
			{sniper, "impguard"},
			{storm, " impguard"},
			{attack, "impguard"},
			{block, "impguard"},
			{patrol, "impguard"},
		});

	theemperor = new Playable("theemperor", "The Emperor", 275000, 0x7f1eb8, 1.2f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith,
			Lightning, Imperial, Chokeable, Lightningable});

	admiralackbar = new Playable("admiralackbar", "Admiral Ackbar", 33000, 0x0, 1.44f,
		{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Dive, Attack, Shoot, Grapple,
			Chokeable, Lightningable, SlightlyHigherJump});

	ig88 = new Playable("ig88", "IG-88", 100000, 0x0, 1.2f,
		{Box, Jump, Attack, Shoot, Grapple, Astro, Proto, Bounty, Droid, Gas, Pushable, Chokeable,
			Lightningable, Zappable, SlightlyHigherJump, AllEpisodes});

	dengar = new Playable("dengar", "Dengar", 70000, 0x0, 1.3f,
		{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Bounty, Chokeable, Lightningable,
			Trickable, AllEpisodes});

	fourlom = new Playable("4lom", "4-LOM", 45000, 0x7f1d90, 1.2f,
		{Box, Jump, Attack, Shoot, Grapple, Astro, Proto, Bounty, Droid, Gas, Pushable, Chokeable,
			Lightningable, Zappable, AllEpisodes});

	ghostbenkenobi = new Playable("ghostbenkenobi", "Ben Kenobi (Ghost)", 1100000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Deflect, Jedi, Passive,
			Gas, AllEpisodes});

	anakin_ghost = new Playable("anakin_ghost", "Anakin Skywalker (Ghost)", 1000000, 0x0, 1.2f,
		{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Deflect, Jedi, Passive,
			Gas, AllEpisodes});

	yoda_ghost = new Playable("yoda_ghost", "Yoda (Ghost)", 1200000, 0x7f1d10, 1.44f,
		{Lever, Build, Box, Jump, DoubleJump, YodaJump, RealDoubleJump, Attack, Deflect, Jedi,
			Passive, Gas, AllEpisodes});

	r2q5 = new Playable("r2q5", "R2-Q5", 100000, 0x7f1fa8, 1.0f,
		{Fly, Zapper, AstroZapper, Astro, Droid, Passive, Gas, Pushable, Zappable, AllEpisodes});

	hansolo_indy = new Playable("hansolo_indy", "Indiana Jones", 50000, 0x7f20c0, 1.44f,
		{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Lightningable,
			AllEpisodes});

	skeleton = new Playable("skeleton", "Skeleton", 3000, 0x7f20d0, 1.2f, {Extratoggle});

	buzzdroid = new Playable("buzzdroid", "Buzz droid", 1500, 0x7f20a0, 1.2f,
		{Extratoggle, Attack, Droid, Gas, Pushable, Zappable});

	trainingremote = new Playable("trainingremote", "Training Remote", 2000, 0x7f1d98, 1.05f,
		{Extratoggle, Hovering, FakeShoot, Droid, Gas},
		{
			{chatting, "trainingremote"},
			{sniper, "trainingremote"},
			{storm, "trainingremote"},
			{attack, "trainingremote"},
			{block, "trainingremote"},
			{patrol, "trainingremote"},
		});

	engineer = new Playable("engineer", "Rebel Engineer", 8000, 0x0, 1.2f,
		{Extratoggle, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple,
			Chokeable, Lightningable, Trickable, SlightlyHigherJump});

	naffdroid1 = new Playable("naffdroid1", "droid 1", 1500, 0x7f1cb8, 0.6f,
		{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

	naffdroid2 = new Playable("naffdroid2", "droid 2", 1500, 0x7f1cc0, 0.6f,
		{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

	naffdroid3 = new Playable("naffdroid3", "droid 3", 1500, 0x7f1cc8, 0.4f,
		{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

	naffdroid4 = new Playable("naffdroid4", "droid 4", 1500, 0x7f1cd0, 0.6f,
		{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

	womprat = new Playable("womprat", "Womp Rat", 25000, 0x7f1d00, 1.8f, {Extratoggle, Passive});

	mousedroid = new Playable("mousedroid", "Mouse droid", 3000, 0x7f1cd8, 2.4f,
		{Extratoggle, Droid, Passive, Gas, Pushable, Zappable});

	imperialengineer = new Playable("imperialengineer", "imperial Engineer", 9000, 0x0, 1.2f,
		{Extratoggle, Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump, Storm});

	hanincarbonite = new Playable(
		"hanincarbonite", "Han Solo (frozen in carbonite)", 5000, 0x0, 0.75f, {Extratoggle});

	atat_driver = new Playable("atat_driver", "AT-AT Driver", 25000, 0x0, 1.2f,
		{Extratoggle, Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump, Storm});

	scouttrooper = new Playable("scouttrooper", "Scout Trooper", 16000, 0x0, 1.2f,
		{Extratoggle, Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable,
			Lightningable, Trickable, SlightlyHigherJump, Storm},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "attack"},
			{block, "block"},
			{patrol, "strolling"},
		});

	newanakinspod = new Playable("newanakinspod", "Anakin's Pod", 20000, 0x7f21e0, 1.2f, {Vehicle});

	naboostarfighter = new Playable("naboostarfighter", "Naboo Starfighter", 12000, 0x7f20b0, 1.2f,
		{Vehicle, Attack, Shoot, Tow});

	anakinsspeeder = new Playable(
		"anakinsspeeder", "Anakin's Speeder", 15000, 0x7f21f0, 1.2f, {Vehicle, Attack, Shoot});

	newrepublicgunship = new Playable("newrepublicgunship", "Republic Gunship", 18000, 0x7f1f78,
		1.2f, {Vehicle, Attack, Shoot, Tow});

	jedistarfighter_yellow_ep3 = new Playable("jedistarfighter_yellow_ep3",
		"jedi Starfighter (Yellow)", 10000, 0x7f1f40, 1.2f, {Vehicle, Attack, Shoot});

	jedistarfighter_red_ep3 = new Playable("jedistarfighter_red_ep3", "jedi Starfighter (Red)",
		10000, 0x7f1f48, 1.2f, {Vehicle, Attack, Shoot});

	xwing = new Playable("xwing", "X-wing", 25000, 0x7f1fb0, 1.2f, {Vehicle, Attack, Shoot});

	ywing = new Playable("ywing", "Y-wing", 25000, 0x7f1e38, 1.2f, {Vehicle, Attack, Shoot});

	snowspeeder = new Playable(
		"snowspeeder", "Snowspeeder", 20000, 0x7f1fc0, 1.2f, {Vehicle, Attack, Shoot, Tow});

	millenniumfalcon = new Playable(
		"millenniumfalcon", "Millennium Falcon", 40000, 0x7f1ec0, 1.2f, {Vehicle, Attack, Shoot});

	sebulbaspod = new Playable("sebulbaspod", "Sebulba's Pod", 20000, 0x7f21c0, 1.2f, {Vehicle});

	zamsspeeder = new Playable(
		"zamsspeeder", "Zam's Airspeeder", 24000, 0x7f2200, 1.2f, {Vehicle, Attack, Shoot});

	droidtrifighter = new Playable(
		"droidtrifighter", "droid Trifighter", 28000, 0x7f2210, 1.2f, {Vehicle, Attack, Shoot});

	vulturedroid = new Playable(
		"vulturedroid", "Vulture droid", 30000, 0x7f2208, 1.2f, {Vehicle, Attack, Shoot});

	clonearc = new Playable(
		"clonearc", "Clone Arcfighter", 33000, 0x7f20a8, 1.2f, {Vehicle, Attack, Shoot});

	tiefighter = new Playable(
		"tiefighter", "TIE Fighter", 35000, 0x7f1e58, 1.2f, {Vehicle, Attack, Shoot, TieDoor});

	tieinterceptor = new Playable("tieinterceptor", "TIE Interceptor", 40000, 0x7f1fc8, 1.2f,
		{Vehicle, Attack, Shoot, TieDoor});

	tiefighterdarth = new Playable("tiefighterdarth", "TIE Fighter (Darth Vader)", 50000, 0x7f1e50,
		1.2f, {Vehicle, Attack, Shoot, TieDoor});

	tiebomber = new Playable(
		"tiebomber", "TIE Bomber", 60000, 0x7f1e40, 1.2f, {Vehicle, Attack, Shoot, TieDoor});

	imperialshuttle = new Playable(
		"imperialshuttle", "imperial Shuttle", 25000, 0x7f1fd0, 1.2f, {Vehicle, Attack, Shoot});

	slave1 = new Playable(
		"slave1", "Slave 1", 100000, 0x7f1e30, 1.2f, {Vehicle, Attack, Shoot, AllEpisodes});

	newanakinspod_green = new Playable(
		"newanakinspod_green", "Anakin's Pod (Green)", 20000, 0x7f21b8, 1.2f, {Vehicle, Vgreen});

	naboostarfighter_lime = new Playable("naboostarfighter_lime", "Naboo Starfighter (Green)",
		12000, 0x7f20b8, 1.2f, {Vehicle, Vgreen, Attack, Shoot, Tow});

	anakinsspeeder_green = new Playable("anakinsspeeder_green", "Anakin's Speeder (Green)", 15000,
		0x7f21f8, 1.2f, {Vehicle, Vgreen, Attack, Shoot});

	newrepublicgunship_green = new Playable("newrepublicgunship_green", "Republic Gunship (Green)",
		18000, 0x7f1f80, 1.2f, {Vehicle, Vgreen, Attack, Shoot, Tow});

	defaultCharacter = new Playable("", "", 0, 0, 0.0f, {Fake});

	//podrace original uses a different version of the pods
	fakeAnakinsPod = new Playable("anakinspod", "", 0, 0, 0.0f, {Fake, Vehicle});

	fakeAnakinsPodGreen = new Playable("anakinspod_green", "", 0, 0, 0.0f, {Fake, Vehicle});

	kaminodroid = new Playable("kaminoandroid", "", 0, 0x7f1fe8, 1.05f, {Fake, Shoot, Hovering},
		{
			{chatting, "kaminodroid"},
			{sniper, "sniper"},
			{storm, "kaminodroid"},
			{attack, "kaminodroid"},
			{block, "kaminodroid"},
			{patrol, "kaminodroid"},
		});

	sentrydroid = new Playable("sentrydroid", "", 0, 0x7f1fe0, 1.2f, {Fake, Shoot, Hovering},
		{
			{chatting, "chatting"},
			{sniper, "sniper"},
			{storm, "chatting"},
			{attack, "chatting"},
			{block, "chatting"},
			{patrol, "chatting"},
		});

	bat = new Playable("bat", "", 0, 0x7f1cf8, 0.75f, {Fake, Hovering},
		{
			{chatting, "bat"},
			{sniper, "bat"},
			{storm, "bat"},
			{attack, "bat"},
			{block, "bat"},
			{patrol, "bat"},
		});

	//LEVELS
	Negotiations = new Level("NEGOTIATIONS", "NEGOTIATIONS", "/LEVELS/EPISODE_I/NEGOTIATIONS/",
		false, {quigonjinn, obiwankenobi, tc14}, {},
		{quigonjinn, obiwankenobi, tc14, battledroid, battledroid_security, battledroid_commander,
			destroyer},
		{{'A', {0xa6a0, 0xa689, 0xa672, 0xa65b, 0xa644, 0xa34d, 0xa90d, 0xa8f6, 0xa8df, 0xa8c8}},
			{'B', {0xfc1, 0xfaa, 0xf4e, 0xf37}},
			{'C', {0x37c5, 0x37ae, 0x3797, 0x3780, 0x36df, 0x36c8, 0x36b1}}},
		{},

		{{'A',
			 {
				 {ProtoPanel, 0xAA03}, //sheild room
				 {ProtoPanel, 0xAA32}, //box room
				 {ProtoPanel, 0xAA61}, //second story
				 {ProtoPanel, 0xAA90}, //first story
				 {AstroPanel, 0xAABF}, //to room B
			 }},
			{'B', {{AstroPanel, 0x10E7}}}, //useless
			{
				'C',
				{
					{AstroPanel, 0x38C9}, //rb
					{ProtoPanel, 0x38F8}, //end
				},
			}},
		{},
		{
			{'A', chatting, "DOORATTACK", "NormalUpdate", {0x456a, 0x460f, 0x46b4, 0x4759},

				func("NormalUpdate", "", "GoToOrigin \"waittime=10\""), 30, 43},

			{'A', chatting, "DEACTIVATED", "NormalUpdate", {0x4c3c, 0x4ce1, 0x4d86, 0x4e2b},

				func("NormalUpdate", "", "GoToOrigin \"waittime=10\""), 38, 51},

			{'A', chatting, "VENTDROID", "NormalUpdate", {0x4ed0},
				func("NormalUpdate", "", "GoToOrigin \"waittime=10\""), 30, 34},

			{'B', attack, "LAZYDROID", "Attack", {0xBA8, 0xC48, 0xCE8, 0xD88},
				func("Attack", "", ""), 31, 43},
			{'C', chatting, "MTT_DROID", "Update",
				{0x39A0, 0x3A45, 0x3AEA, 0x3B8F, 0x3C34, 0x3CD9, 0x3D7E, 0x3E23, 0x3EC8},
				func("Update", "", "GoToOrigin \"waittime=10\""), 31, 44},

			{'C', block, "block", "DROIDEKA", "Guard", {0x3647, 0x36FC}, 82},
		},

		{
			{'A',
				{
					{chatting, 0x414c},
					{chatting, 0x41f1},
					{chatting, 0x4296},
					{chatting, 0x434b},
					{chatting, 0x434B},
					{chatting, 0x48B3},
					{chatting, 0x4968},
					{chatting, 0x4A1D},
					{chatting, 0x4AD2},
					{chatting, 0x4B87},
					{chatting, 0x4F85},
				}},
			{'C',
				{
					{chatting, 0x3269},
					{chatting, 0x330E},
					{chatting, 0x33B3},
					{chatting, 0x3458},
					{chatting, 0x34FD},
					{chatting, 0x35A2},
					{sniper, 0x38FB},
					{patrol, 0x30FF},
					{patrol, 0x31B4},
				}},
		},
		{5, 6, 7, 8});

	Invasion = new Level("GUNGAN", "GUNGAN", "/LEVELS/EPISODE_I/GUNGAN/", false,
		{quigonjinn, obiwankenobi, jarjarbinks}, {}, {jarjarbinks, captaintarpals, bossnass},
		{{'A', {0x3665, 0x364e, 0x3637, 0x325a, 0x3243, 0x322c, 0x3215, 0x31fe}},
			{'B', {0x1acc, 0x1ab5, 0x1a9e, 0x1a14, 0x1790}},
			{'C', {0x214d, 0x2136, 0x211f, 0x1965, 0x194e, 0x1937}}, {'E', {0xab7, 0x9e8}}},
		{},

		{
			{'B', {{BountyPanel, 0x1C01}}}, //rb
		},
		{},
		{
			{'A', storm, "storm", "STORM", "Approach", {0x1722, 0x17F7}, 19},
			{'E', attack, "attack", "BATTLEDROID", "Attack", {0x864, 0x919, 0x9CE, 0xA83}, 90},
			{'E', storm, "storm", "STORM", "Approach", {0xBED}, 19}, //make this no enter
		},
		{{'B',
			 {
				 {sniper, 0x2303},
				 {storm, 0x23A8},
				 {storm, 0x245D},
				 {chatting, 0x2512},
				 {chatting, 0x25B7},
			 }},
			{'C',
				{
					{chatting, 0x44DB},
					{chatting, 0x4580},
					{chatting, 0x4625},
					{chatting, 0x46CA},
					{chatting, 0x476F},
					{chatting, 0x4814},
					{chatting, 0x48B9},
					{chatting, 0x495E},
					{chatting, 0x4A03},
					{chatting, 0x4AA8},
					{chatting, 0x4B4D},
				}}},
		{7});

	EscapeNaboo = new Level("PALACERESCUE", "RESCUE", "/LEVELS/EPISODE_I/PALACERESCUE/", false,
		{amidala, captainpanaka, quigonjinn, obiwankenobi}, {},
		{amidala, captainpanaka, royalguard, padme},
		{{'A', {0x8153, 0x813c, 0x8125, 0x810e, 0x7cd5, 0x7cbe}},
			{'B', {0x559c, 0x5585, 0x5232, 0x521b, 0x5204}},
			{'C', {0x681d, 0x6806, 0x67ef, 0x67d8, 0x67c1, 0x67aa}},
			{'E', {0x343b, 0x3424, 0x33f6, 0x33df}}},
		{}, {}, {});

	Podrace = new Level("PODSPRINT", "PODSPRINT", "/LEVELS/EPISODE_I/PODSPRINT/", true,
		{newanakinspod, newanakinspod_green}, {},
		{watto, pitdroid, newanakinspod, newanakinspod_green, sebulbaspod},
		{{'A',
			{0x52d4, 0x52bd, 0x52a6, 0x528f, 0x5278, 0x5261, 0x524a, 0x5233, 0x521c, 0x5205, 0x51ee,
				0x51c0, 0x51a9, 0x5192, 0x517b, 0x5164, 0x514d, 0x5136, 0x511f, 0x5108, 0x50f1}}},
		{}, {}, {});

	Theed = new Level("RETAKEPALACE", "RETAKE", "/LEVELS/EPISODE_I/RETAKEPALACE/", false,
		{obiwankenobi, quigonjinn, captainpanaka, padmebattle, r2d2, anakin_boy}, {},
		{padmebattle, r2d2, anakin_boy},
		{{'A', {0x36fc, 0x36e5, 0x3689, 0x3672}}, {'B', {0x61be, 0x61a7, 0x6190, 0x6179}},
			{'D', {0x5abb, 0x5aa4, 0x5a8d, 0x559c, 0x48ac}}, {'E', {0x3799, 0x327a}},
			{'F', {0x5f5c, 0x5f45, 0x5f2e}}, {'G', {0x3473, 0x345c, 0x2938}}},
		{},

		{{'A', {{AstroPanel, 0x38BC}}}, {'B', {{AstroPanel, 0x62FE}}},
			{'G', {{AstroPanel, 0x35F6}}}},
		{});

	Maul = new Level("MAUL", "MAUL", "/LEVELS/EPISODE_I/MAUL/", false, {obiwankenobi, quigonjinn},
		{}, {darthmaul},
		{{'A', {0x2e7c, 0x2e65, 0x2be1, 0x2bca}},
			{'B', {0x2a4e, 0x2a37, 0x2a20, 0x2757, 0x2740, 0x2449, 0x1531}},
			{'D', {0x1a95, 0x1a67, 0x1a50, 0x1a39, 0x193c}}, {'E', {0x18bc}},
			{'F', {0xe76, 0xe1a, 0xe03, 0xdec}}},
		{},
		{{'A', {{ImperialPanel, 0x2F44}}}, {'D', {{ProtoPanel, 0x1C1F}, {ImperialPanel, 0x1C4E}}}},
		{});

	BHP = new Level("PURSUIT", "PURSUIT", "/LEVELS/EPISODE_II/PURSUIT/", true,
		{anakinsspeeder, anakinsspeeder_green}, {},
		{zamwesell, dexter, anakinsspeeder, anakinsspeeder_green, zamsspeeder},
		{{'A', {0x58b2, 0x589b, 0x5884, 0x586d, 0x5856, 0x5759}}, {'B', {0x1251, 0x123a}},
			{'C', {0x4379, 0x4362, 0x434b, 0x4334, 0x431d, 0x4293, 0x4220}},
			{'D', {0x26aa, 0x2693}}},

		{{'A', {0x583f, 0x5828, 0x5811, 0x57fa, 0x57e3}},    //Stupid Minikit
			{'A', {0x57cc, 0x57b5, 0x579e, 0x5787, 0x5770}}, //Turrets 1
			{'C', {0x4306, 0x42ef, 0x42d8, 0x42c1, 0x42aa}}, //Turrets 2
			{{'A', 0x5742}, {'A', 0x572b}, {'A', 0x5714}, {'A', 0x56fd}, {'A', 0x56e6},
				{'A', 0x56cf}, //Baners pt. 1
				{'C', 0x427c}, {'C', 0x4265}, {'C', 0x424e}, {'C', 0x4237}}},
		{}, {}); //Banners pt. 2

	Kamino = new Level("KAMINO", "KAMINO", "/LEVELS/EPISODE_II/KAMINO/", false,
		{obiwankenobi_jedimaster, r4_p17}, {},
		{obiwankenobi_jedimaster, r4_p17, clone, lamasu, taunwe},
		{{'A', {0x1f52, 0x1f3b, 0x1781, 0x1542}}, {'C', {0x3ce1, 0x3cca, 0x3bfb, 0x3be4, 0x3bcd}},
			{'D', {0x51dc, 0x51c5, 0x51ae, 0x5055, 0x503e, 0x5027}}, {'E', {0x315a, 0x2e63}},
			{'F', {0x2235, 0x221e, 0x2024, 0x200d}}},
		{},

		{{'A', {{AstroPanel, 0x206E}}},                                                   //closet
			{'C', {{AstroPanel, 0x3F4B}, {AstroPanel, 0x3F7C}, {ImperialPanel, 0x3FAD}}}, //bonus
			{'D', {{BountyPanel, 0x5337},                      //bonus room
					  {AstroPanel, 0x5365}}},                  //room 3 end hallway
			{'E', {{AstroPanel, 0x3565}, {AstroPanel, 0x3594}, //stop droids
					  {AstroPanel, 0x35C3},                    //last story
					  {AstroPanel, 0x35F2}, {AstroPanel, 0x3621}, {AstroPanel, 0x3650},
					  {AstroPanel, 0x367F}}}, //turrets
			{'F', {{AstroPanel, 0x233A},      //outside to elevator
					  {ProtoPanel, 0x2368}}}},
		{});

	Factory = new Level("FACTORY", "FACTORY", "/LEVELS/EPISODE_II/FACTORY/", false,
		{anakin_padawan, padmegeo, r2d2, c3po}, {obiwankenobi_jedimaster},
		{anakin_padawan, padmegeo, c3po, geonosian, battledroid_geonosian, skeleton},
		{{'A', {0xB33, 0xb1c, 0x825}}, {'B', {0x2f68, 0x2f51, 0x2f3a, 0x280a, 0x27f3}},
			{'D', {0x184e, 0x1837, 0x12bc, 0x12a5}}, {'E', {0xf93, 0xc9c}},
			{'F', {0x1c47, 0x1c30, 0x1c19, 0x1265, 0x124e, 0x1a4d}}, {'G', {0x1531}}},
		{},

		{{'B', {{AstroPanel, 0x311B}, {ImperialPanel, 0x31D7}, {AstroPanel, 0x314A},
				   {AstroPanel, 0x317A}, {AstroPanel, 0x31A9}}}, //color
																 //matching
			{'D', {{AstroPanel, 0x1A8C}, {AstroPanel, 0x1ABB}}}, //story
			{'E', {{ProtoPanel, 0x1191}}},                       //story
			{'F', {{AstroPanel, 0x1E49},                         //bridge
					  {ProtoPanel, 0x1E78},                      //end
					  {AstroPanel, 0x1EA7}, {AstroPanel, 0x1ED6}, {AstroPanel, 0x1F05},
					  {AstroPanel, 0x1F34}}}, //rb
			{'G', {{AstroPanel, 0x1B18},      //left, bonus
					  {AstroPanel, 0x1B47}}}},
		{}); //right, story

	JediBattle = new Level("JEDI", "JEDI", "/LEVELS/EPISODE_II/JEDI/", false,
		{macewindu, r2d2, obiwankenobi_jedimaster, anakin_padawan, padmeclawed}, {},
		{macewindu, padmeclawed, superbattledroid, jangofett, bobafett_boy, luminara, kiadimundi,
			kitfisto, shaakti, aylasecura, plokoon},
		{{'B',
			{0x5099, 0x5082, 0x506b, 0x5054, 0x503d, 0x5026, 0x500f, 0x4ff8, 0x4fe1, 0x4fca, 0x4fb3,
				0x4de7, 0x4c8e, 0x4c60, 0x4c04, 0x4bed, 0x4bd6, 0x4bbf, 0x4ba8, 0x4b91, 0x4b7a}}},
		{}, {{'B', {{ImperialPanel, 0x5305}, {BountyPanel, 0x5334}}}}, {}); //Bounty Hunter Mission

	Gunship = new Level("GUNSHIP", "GUNSHIP", "/LEVELS/EPISODE_II/GUNSHIP/", true,
		{newrepublicgunship, newrepublicgunship_green}, {},
		{newrepublicgunship, newrepublicgunship_green},
		{{'A', {0x2332, 0x231b, 0x2304, 0x22ed, 0x22d6, 0x22bf, 0x22a8, 0x2291, 0x227a, 0x2263,
				   0x224c, 0x2235, 0x221e}},
			{'B', {0x21ea, 0x21d3, 0x21bc, 0x21a5, 0x218e, 0x2177, 0x2160, 0x2149}}},
		{}, {}, {});

	Dooku = new Level("DOOKU", "DOOKU", "/LEVELS/EPISODE_II/DOOKU/", false,
		{obiwankenobi_jedimaster, anakin_padawan, yoda}, {}, {yoda},
		{{'B', {0x2245, 0x222e, 0x2217, 0x2200, 0x21e9, 0x1f20, 0x1f09, 0x1ef2, 0x1edb, 0x1ec4,
				   0x1ead}},
			{'C',
				{0x2063, 0x204c, 0x2035, 0x201e, 0x2007, 0x1ff0, 0x1d27, 0x1d10, 0x1cf9, 0x1ce2}}},
		{}, {}, {});

	Coruscant = new Level("DOGFIGHT", "DOGFIGHT", "/LEVELS/EPISODE_III/DOGFIGHT/", true,
		{jedistarfighter_yellow_ep3, jedistarfighter_red_ep3}, {},
		{jedistarfighter_yellow_ep3, jedistarfighter_red_ep3, droidtrifighter, vulturedroid,
			clonearc},
		{{'A',
			{0x2cbc, 0x2ca5, 0x2c8e, 0x2c77, 0x2c60, 0x2c49, 0x2c32, 0x2c1b, 0x2c04, 0x2bed, 0x2bd6,
				0x2bbf, 0x2ba8, 0x2b91, 0x2b7a, 0x2b63, 0x2b4c, 0x2b35, 0x2b1e, 0x2b07, 0x2af0}}},
		{}, {}, {});

	Chancellor = new Level("CRUISER", "CRUISER", "/LEVELS/EPISODE_III/CRUISER/", false,
		{obiwankenobi_ep3, anakin_jedi, r2d2, palpatine}, {},
		{obiwankenobi_ep3, anakin_jedi, palpatine, countdooku, bodyguard, buzzdroid},
		{{'A', {0x1bfb, 0x1be4, 0x1bcd}},
			{'B', {0x15c0, 0x15a9, 0x1592, 0x11e3, 0x11cc, 0x11b5, 0x119e}},
			{'C', {0x1050, 0x1039, 0xd14}}, {'D', {0x335d}}, {'E', {0xeba, 0xda6}},
			{'F', {0x7dd, 0x3a4, 0x38d}}, {'G', {0x10f9, 0xe75}}},
		{},

		{{'B', {{AstroPanel, 0x1741}, {ProtoPanel, 0x1770}, //minikits
				   {AstroPanel, 0x179F},                    //story bomb
				   {AstroPanel, 0x17CE}}},                  //story, top of room

			{'C', {{ProtoPanel, 0x112F}, {ProtoPanel, 0x115E}, {AstroPanel, 0x118D}}},
			{'D', {{AstroPanel, 0x37BF}}},   //resets moving wall
			{'E', {{AstroPanel, 0xF82},      //turns off gas
					  {AstroPanel, 0xFB1}}}, //end of room
			{'G', {{AstroPanel, 0x11FF}}}},
		{}); //elevator (room 2)

	Grievous = new Level("GRIEVOUS", "GRIEVOUS", "/LEVELS/EPISODE_III/GRIEVOUS/", false,
		{obiwankenobi_ep3, clone_ep3_sand}, {}, {clone_ep3_sand, grievous},
		{{'A',
			{0x3a2a, 0x3a13, 0x39fc, 0x39e5, 0x39ce, 0x39b7, 0x39a0, 0x3989, 0x3972, 0x395b, 0x3944,
				0x392d, 0x37bd, 0x3636, 0x361f, 0x3608, 0x35f1, 0x35da, 0x35c3, 0x35ac, 0x3595}}},
		{}, {}, {}); //dispenser

	Kashyyyk =
		new Level("KASHYYYK", "KASHYYYK", "/LEVELS/EPISODE_III/KASHYYYK/", false, {yoda, chewbacca},
			{}, {chewbacca, wookie, clone_ep3, clone_ep3_pilot, clone_ep3_swamp, clone_ep3_walker},
			{{'A', {0x6157, 0x6140, 0x6129, 0x6112, 0x5fb9, 0x5dd6, 0x5dbf}},
				{'B', {0x3374, 0x335d, 0x3346, 0x3204}}, {'C', {0x2d28, 0x2d11, 0x2cfa}},
				{'D', {0x41e1, 0x41ca, 0x41b3, 0x419c, 0x4185, 0x416e}}},

			{{'B', {0x33a2, 0x338b, 0x31ed}}}, {}, //carrots

			{{'A', {{RandomHat, 0x642E}}}}); //hat dispenser

	Ruin = new Level("TEMPLE", "TEMPLE", "/LEVELS/EPISODE_III/TEMPLE/", false,
		{obiwankenobi_ep3, yoda}, {}, {macewindu_ep3, disguisedclone, trainingremote},
		{{'A', {0x5330, 0x5319, 0x5302, 0x517b, 0x5164, 0x514d}},
			{'B', {0x420b, 0x41f4, 0x41dd, 0x413c, 0x4125, 0x410e}},
			{'C', {0x5221, 0x520a, 0x51f3, 0x51dc, 0x5197, 0x5180, 0x382a, 0x3813, 0x37fc}}},
		{}, {{'B', {{ImperialPanel, 0x42D3}}}, {'C', {{ProtoPanel, 0x55FF}}}}, {});

	Vader = new Level("VADER", "VADER", "/LEVELS/EPISODE_III/VADER/", false,
		{obiwankenobi_ep3, anakin_jedi}, {}, {},
		{{'A', {0x47b3, 0x479c, 0x4785, 0x476e, 0x452f, 0x41f3, 0x41dc, 0x41c5, 0x41ae, 0x4197}},
			{'B', {0x187a, 0x1863, 0x1624, 0x160d}},
			{'C', {0x28b2, 0x2884, 0x286d, 0x2856, 0x1ffb, 0x1fe4, 0x1fcd}}},
		{}, {{'A', {{AstroPanel, 0x487B}}}}, {});

	SecretPlans =
		new Level("BLOCKADERUNNER", "BLOCKADERUNNER", "/LEVELS/EPISODE_IV/BLOCKADERUNNER/", false,
			{princessleia, captainantilles, rebelfriend, c3po, r2d2}, {},
			{princessleia, captainantilles, rebelfriend, rebelscum, stormtrooper,
				imperialshuttlepilot, engineer},
			{{'A', {0x6d3f, 0x6d28, 0x6d11, 0x6cfa}},
				{'B', {0x11033, 0x1101c, 0x11005, 0x10fee, 0x10eac, 0x10e95, 0x10e7e, 0x10e67}},
				{'C', {0x3fc0, 0x3fa9, 0x3f92, 0x3f7b, 0x3ae6}}, {'D', {0x4b1e, 0x4af0}}},

			{{'B', {0x11078, 0x11061, 0x1104a}},  //grapes
				{'D', {0x4b4c, 0x4b35, 0x4b07}}}, //flowers

			{{'A', {{ProtoPanel, 0x6EA9}}},

				{'B', {{AstroPanel, 0x113D9},                               //elevator
						  {BountyPanel, 0x11408}, {ImperialPanel, 0x11437}, //jango car area
						  {ProtoPanel, 0x11466}}},                          //to rb

				{'C', {{ProtoPanel, 0x4141},      //starts midtro
						  {ProtoPanel, 0x4170},   //supercrane
						  {AstroPanel, 0x419F}}}, //end of hallway

				{'D', {{ImperialPanel, 0x4CFE}, {ProtoPanel, 0x4DBA},
						  {ProtoPanel, 0x4DE9}, //There goes another one.
						  {AstroPanel, 0x4D2D}, {AstroPanel, 0x4E18}, {ProtoPanel, 0x4D8B},
						  {AstroPanel, 0x4D5C}}}}, //last 4

			{{'A', {{RandomHat, 0x6EF7}}}});

	Jundland = new Level("TATOOINE", "TATOOINE", "/LEVELS/EPISODE_IV/TATOOINE/", false,
		{lukeskywalker_tatooine, benkenobi, c3po, r2d2}, {},
		{lukeskywalker_tatooine, benkenobi, tuskenraider, jawa, naffdroid1, naffdroid2, naffdroid3,
			naffdroid4, womprat},
		{{'A', {0x7220, 0x7209, 0x71f2, 0x71db, 0x71c4, 0x71ad, 0x7196}},
			{'B', {0x7ced, 0x7cd6, 0x7cbf, 0x7ca8}},
			{'C', {0x6907, 0x68f0, 0x68d9, 0x68c2, 0x68ab}}, {'D', {0x3a14, 0x39fd, 0x39e6}},
			{'E', {0x4ad2, 0x4abb}}},
		{},

		{{'B', {{ProtoPanel, 0x7FB2}, {AstroPanel, 0x7FE1}, //tv room
				   {AstroPanel, 0x8010},                    //elevator
				   {AstroPanel, 0x803F},                    //vacuum
				   {ProtoPanel, 0x806E},                    //end
				   {ProtoPanel, 0x809D}}},                  //useless

			{'C', {{ProtoPanel, 0x6A0D}, {ProtoPanel, 0x6A3C}, {ProtoPanel, 0x6A6B}}}, //quicksand
			{'E', {{AstroPanel, 0x4CD9}}}},
		{}); //useless

	Spaceport = new Level("MOSEISLEY", "MOSEISLEY", "/LEVELS/EPISODE_IV/MOSEISLEY/", false,
		{lukeskywalker_tatooine, benkenobi, r2d2, c3po, hansolo, chewbacca}, {},
		{hansolo, sandtrooper, greedo, imperialspy},
		{{'A', {0x80d9, 0x80c2, 0x80ab, 0x6eb3, 0x6e57}},
			{'B', {0x672b, 0x6714, 0x66fd, 0x66e6, 0x5f43}}, {'C', {0x2ccc, 0x2cb5}},
			{'D', {0x9f93, 0x9f7c, 0x9f65, 0x9f4e, 0x9f37}}, {'E', {0x3564, 0x354d}}},

		{{'A', {0x6e9c, 0x6e85, 0x6e6e}},     //carrots
			{'D', {0x8c2b, 0x8c14, 0x8bfd}}}, //turnips

		{{'A', {{BountyPanel, 0x82AA},                              //fan
				   {ImperialPanel, 0x82DB},                         //spa
				   {AstroPanel, 0x830C},                            //rb
				   {ProtoPanel, 0x833D}, {ImperialPanel, 0x836E}}}, //end

			{'B', {{ProtoPanel, 0x6924}, {AstroPanel, 0x6953}, //atst
					  {ImperialPanel, 0x6982}}},               //go back to A

			{'D', {{BountyPanel, 0xA1DF}, {ProtoPanel, 0xA20E},    //enter bonus
					  {BountyPanel, 0xA23D}, {ProtoPanel, 0xA26C}, //exit bonus
					  {AstroPanel, 0xA29B}}}},                     //theatre

		{{'D', {{StormtrooperHat, 0xA2E9}}}});

	Princess = new Level("DEATHSTARRESCUE", "DEATHSTARRESCUE",
		"/LEVELS/EPISODE_IV/DEATHSTARRESCUE/", false,
		{hansolo_stormtrooper, lukeskywalker_stormtrooper, chewbacca, r2d2, c3po, benkenobi},
		{princessleia},
		{hansolo_stormtrooper, lukeskywalker_stormtrooper, beachtrooper, deathstartrooper,
			tiefighterpilot, imperialofficer, grandmofftarkin, mousedroid, imperialengineer},
		{{'A', {0x2ecf, 0x2eb8, 0x2ea1, 0x2e8a}},
			{'B', {0x4f48, 0x4f31, 0x4f1a, 0x4f03, 0x4e79, 0x4e62, 0x4e4b, 0x4e34, 0x3f4a}},
			{'C', {0x50bf, 0x50a8, 0x5091, 0x507a, 0x5063, 0x504c, 0x5035}}, {'D', {0x4e4}}},
		{},
		{{'A', {{ImperialPanel, 0x2FD6},   //first
				   {ProtoPanel, 0x3005},   //minikit
				   {AstroPanel, 0x3034}}}, //cutscene

			{'B', {{AstroPanel, 0x53C0},                          //rb
					  {AstroPanel, 0x53EF}, {AstroPanel, 0x541E}, //elevators
					  {ImperialPanel, 0x544D}}},                  //story /////////APPEARANCE

			{'C', {{ImperialPanel, 0x581D},                          //call room
					  {ImperialPanel, 0x584C},                       //spa
					  {AstroPanel, 0x587B}, {ProtoPanel, 0x58AA}}}}, //extra cells

		{{'A', {{StormtrooperHat, 0x3082}}}, //first room

			{'B', {{StormtrooperHat, 0x549B},      //before bridge
					  {StormtrooperHat, 0x54CB}}}, //after bridge

			{'C', {{StormtrooperHat, 0x58F8}}}, //turnstyle room

			{'D', {{RandomHat, 0x5CB}, {RandomHat, 0x5FB}, {RandomHat, 0x62B},
					  {RandomHat, 0x65B}}}}); //bonus hat room

	DSE = new Level("DEATHSTARESCAPE", "DEATHSTARESCAPE", "/LEVELS/EPISODE_IV/DEATHSTARESCAPE/",
		false, {hansolo, chewbacca, princessleia, lukeskywalker_tatooine, r2d2, c3po}, {}, {},
		{{'A', {0x2834, 0x281d, 0x2806, 0x27ef}},
			{'B', {0x2fe7, 0x2fd0, 0x2fb9, 0x2fa2, 0x2f8b, 0x2ffe}},
			{'C', {0x474a, 0x4733, 0x471c, 0x4705, 0x46ee, 0x4567, 0x4550, 0x4539, 0x4522}},
			{'D', {0x746, 0x72f}}},
		{},

		{{'A', {{ProtoPanel, 0x2B50},         //rb
				   {ImperialPanel, 0x2B7F}}}, //story

			{'B', {{ImperialPanel, 0x32F2}}}, //ripmore

			{'C', {{ImperialPanel, 0x4B64},       //swing room
					  {ProtoPanel, 0x4B93},       //falcon - fan
					  {ImperialPanel, 0x4BC2},    //trophy bonus
					  {AstroPanel, 0x4BF1},       //falcon - right
					  {AstroPanel, 0x4C20},       //floor waxer
					  {BountyPanel, 0x4C4F},      //vader
					  {ImperialPanel, 0x4C7E}}}}, //bonus clock

		{{'A', {{StormtrooperHat, 0x2BCD}}},      //first hat
			{'B', {{StormtrooperHat, 0x3340}}},   //ripmore
			{'C', {{StormtrooperHat, 0x4CCC}}}}); //swing room

	RebelAttack =
		new Level("DEATHSTARBATTLE", "DEATHSTARBATTLE", "/LEVELS/EPISODE_IV/DEATHSTARBATTLE/", true,
			{xwing, ywing}, {}, {xwing, ywing, tiefighter, tieinterceptor, tiefighterdarth},
			{{'A', {0x46b0, 0x4699, 0x4682, 0x466b, 0x4654, 0x463d, 0x4626}},
				{'B', {0x6fb0, 0x6f99, 0x6f82, 0x6f6b, 0x6f54, 0x6f3d, 0x6f26}},
				{'C', {0x477b, 0x4764, 0x474d}}, {'D', {0x21e1, 0x21ca, 0x21b3, 0x219c}}},
			{}, {}, {});

	Hoth = new Level("HOTHBATTLE", "HOTHBATTLE", "/LEVELS/EPISODE_V/HOTHBATTLE/", true,
		{snowspeeder, snowspeeder}, {}, {snowspeeder},
		{{'A', {0x2ff9, 0x2fe2, 0x2fcb, 0x2fb4, 0x2f9d}}, {'B', {0x1148, 0x1131}},
			{'C', {0x53e5, 0x53ce, 0x53b7, 0x53a0}},
			{'D', {0x3120, 0x3109, 0x30f2, 0x30db, 0x30c4, 0x30ad}},
			{'E', {0x1786, 0x176f, 0x1758, 0x1741}}},
		{}, {}, {});

	EchoBase = new Level("HOTHESCAPE", "HOTHESCAPE", "/LEVELS/EPISODE_V/HOTHESCAPE/", false,
		{hansolo_hoth, princessleia_hoth, c3po, chewbacca}, {},
		{hansolo_hoth, princessleia_hoth, hansolo_hood, rebelhoth, rebelpilot, snowtrooper,
			lukeskywalker_hoth},
		{{'A', {0x4d85, 0x4d6e, 0x4d57, 0x4d40, 0x4d29, 0x4d12}},
			{'B', {0x44f7, 0x44e0, 0x44c9, 0x44b2, 0x449b, 0x3d54, 0x3d3d}},
			{'C', {0x48ca, 0x48b3, 0x489c, 0x4885, 0x486e, 0x4857, 0x3d78}}, {'D', {0x2c7}}},
		{},

		{{'A', {{AstroPanel, 0x4F5E},      //challenge kit
				   {ProtoPanel, 0x4F8D}}}, //story

			{'B', {{AstroPanel, 0x46C3},      //ice fishing
					  {ProtoPanel, 0x46F2}}}, //story

			{'C', {{ProtoPanel, 0x4B8A}, //tube room
					  {AstroPanel, 0x4BB9}}}},
		{}); //slot machines

	FalconFlight = new Level("ASTEROIDCHASE", "ASTEROIDCHASE", "/LEVELS/EPISODE_V/ASTEROIDCHASE/",
		true, {millenniumfalcon, xwing}, {}, {millenniumfalcon, tiebomber, imperialshuttle},
		{{'A', {0x260f, 0x25f8, 0x25e1, 0x25ca, 0x25b3, 0x259c, 0x2585}},
			{'B', {0x4a01, 0x49ea, 0x49d3, 0x49bc, 0x49a5, 0x498e, 0x4977, 0x4960}},
			{'C', {0x1617, 0x1600, 0x15e9}}, {'D', {0x573, 0x55c, 0x545}}},
		{}, {}, {});

	Dagobah = new Level("DAGOBAH", "DAGOBAH", "/LEVELS/EPISODE_V/DAGOBAH/", false,
		{lukeskywalker_pilot, r2d2, lukeskywalker_dagobah, yoda}, {},
		{lukeskywalker_pilot, lukeskywalker_dagobah},
		{{'A', {0x4648, 0x4631, 0x461a, 0x4603, 0x45ec}}, {'B', {0x3015, 0x2ffe, 0x2fd0, 0x2fb9}},
			{'C', {0x4ff9, 0x4fe2, 0x4fcb}},
			{'D', {0x436b, 0x4354, 0x433d, 0x4326, 0x430f, 0x42f8}}, {'E', {0x6865, 0x684e}}},

		{{'E', {0x6893, 0x687c, 0x6837}}}, //circle things

		{{'A', {{AstroPanel, 0x478D}}},    //raise bridge
			{'B', {{AstroPanel, 0x3343}}}, //after hut skip - raise platform
			{'C', {{AstroPanel, 0x57C7}}}, //end level - x-wing
			{'D', {{AstroPanel, 0x44C6}}}, //minikit
			{'E', {{AstroPanel, 0x699A}}}},
		{}); //end of Training room

	CCT = new Level("CLOUDCITYTRAP", "CLOUDCITYTRAP", "/LEVELS/EPISODE_V/CLOUDCITYTRAP/", false,
		{lukeskywalker_bespin, r2d2}, {}, {lukeskywalker_bespin, hanincarbonite},
		{{'A', {0x1f65, 0x1f4e, 0x1f37, 0x1f20, 0x1f09, 0x1ef2, 0x1edb}},
			{'B', {0x13db, 0x13c4, 0x13ad, 0x1396, 0x137f, 0x133a, 0x130c, 0x12f5}},
			{'C', {0x163d, 0x1626, 0x15f8, 0x15e1, 0x15ca, 0x160f}}},
		{},

		{{'A', {{AstroPanel, 0x2083},       //raise first bridge
				   {AstroPanel, 0x20B2},    //enter room 2
				   {AstroPanel, 0x20E1},    //get box for turret
				   {BountyPanel, 0x2110},   //minikit
				   {AstroPanel, 0x213F},    //room 2 - end of hallway
				   {AstroPanel, 0x216E},    //dv1 gas
				   {ImperialPanel, 0x219D}, //dv1 - exit room
				   {AstroPanel, 0x21CC}}},  //dv1 raise bridge

			{'B', {{AstroPanel, 0x14A3},                          //DV4 elevator
					  {AstroPanel, 0x14D2}, {AstroPanel, 0x1501}, //DV3
					  {ImperialPanel, 0x1530}}},                  //minikit

			{'C', {{AstroPanel, 0x1827},       //DVT moving platform
					  {AstroPanel, 0x1856},    //DVT elevator (DV2 skip)
					  {AstroPanel, 0x1885},    //DV3 - right
					  {AstroPanel, 0x18B4}}}}, //DV3 - left

		{{'A', {{StormtrooperHat, 0x221A}}}}); //dv1 hat

	Bespin = new Level("CLOUDCITYESCAPE", "CLOUDCITYESCAPE", "/LEVELS/EPISODE_V/CLOUDCITYESCAPE/",
		false, {landocalrissian, princessleia_bespin, chewbacca, r2d2, c3po}, {},
		{landocalrissian, princessleia_bespin, lobot, ugnaught, bespinguard, princessleia_prisoner},
		{{'A', {0x4e34, 0x4e06, 0x4def, 0x4dd8, 0x4dc1, 0x4daa, 0x4d7c, 0x4d65, 0x4d4e}},
			{'B', {0x14f, 0xdc}},
			{'C', {0x434c, 0x4335, 0x431e, 0x4307, 0x42f0, 0x424f, 0x4238, 0x4221, 0x420a}}},

		{{{'A', 0x4d37}, {'A', 0x4d93}, {'C', 0x41f3}}}, //towers

		{{'A', {{ProtoPanel, 0x4FD4},         //first minikit
				   {BountyPanel, 0x5003},     //boba opens this
				   {ProtoPanel, 0x5032},      //split path - straight to hat machine
				   {AstroPanel, 0x5061},      //build c3po
				   {AstroPanel, 0x5090},      //turn off gas
				   {AstroPanel, 0x50BF},      //old OOB room
				   {BountyPanel, 0x50EE},     //bonus elevator
				   {ImperialPanel, 0x511D}}}, //story elevator

			{'C', {{AstroPanel, 0x466B},       //extend bridge
					  {ProtoPanel, 0x469A},    //box clip skips this
					  {AstroPanel, 0x46C9},    //go to falcon
					  {AstroPanel, 0x46F8}}}}, //turn off gas

		{{'A', {{RandomHat, 0x516B},              //by first minikit
				   {StormtrooperHat, 0x519B}}}}); //story hat

	Jabbas = new Level("JABBASPALACE", "JABBASPALACE", "/LEVELS/EPISODE_VI/JABBASPALACE/", false,
		{princessleia_boushh, chewbacca, lukeskywalker_jedi, c3po, r2d2, hansolo_skiff}, {},
		{lukeskywalker_jedi, princessleia_boushh, hansolo_skiff, gamorreanguard, bibfortuna,
			palaceguard, bossk},
		{{'A', {0x4314, 0x42fd, 0x42e6, 0x42cf, 0x42b8, 0x42a1, 0x428a, 0x4273, 0x425c}},
			{'B', {0x7a38, 0x7a21, 0x7a0a, 0x79f3, 0x79dc, 0x79c5}},
			{'D', {0x303a, 0x3023, 0x300c, 0x2ff5}}, {'E', {0x9bd, 0x9a6}}},
		{},

		{{'A', {{AstroPanel, 0x4919},      //mk
				   {BountyPanel, 0x4948},  //end scene
				   {BountyPanel, 0x4977},  //open gate
				   {ProtoPanel, 0x49A6}}}, //mk

			{'B', {{ProtoPanel, 0x7C83},                          //bonus
					  {ProtoPanel, 0x7CB2}, {AstroPanel, 0x7CE1}, //droid room
					  {AstroPanel, 0x7D10}}},                     //end scene

			{'D', {{ProtoPanel, 0x3246},       //long room - end
					  {AstroPanel, 0x3275},    //long room - bridge
					  {ImperialPanel, 0x32A4}, //minikit
					  {BountyPanel, 0x32D3}}}, //go to rancor

			{'E', {{AstroPanel, 0xB46},       //left gamorrean
					  {ProtoPanel, 0xB75}}}}, //right gamorrean

		{{'A', {{BountyHat, 0x49F4}}},    //first hat
			{'B', {{BountyHat, 0x7D5E}}}, //second hat

			{'D', {{BountyHat, 0x3321},              //third hat
					  {StormtrooperHat, 0x3351}}}}); //bonus hat

	Carkoon = new Level("SARLACCPIT", "SARLACCPIT", "/LEVELS/EPISODE_VI/SARLACCPIT/", false,
		{lando_palaceguard, lukeskywalker_jedi, chewbacca, hansolo_skiff, c3po, r2d2,
			princessleia_slave},
		{}, {lando_palaceguard, princessleia_slave, skiffguard, bobafett},
		{{'A', {0xadb2, 0xad9b, 0xad84, 0xad6d, 0xad56, 0xad3f, 0xad28, 0xad11, 0xacfa}},
			{'B', {0x5a7a, 0x5a63, 0x5a4c, 0x5a35, 0x5a1e}},
			{'C', {0x6e0b, 0x6df4, 0x6ddd, 0x6dc6, 0x6daf, 0x6d98, 0x6d81}}},
		{},

		{{'A', {{ProtoPanel, 0xB67F}, {ProtoPanel, 0xB6AE}, {AstroPanel, 0xB6DD}}}, //bonus
			{'B', {{ProtoPanel, 0x5C2B}}},                                          //elevator

			{'C', {{ProtoPanel, 0x6FC3}, //target
					  {AstroPanel, 0x6FF2}}}},
		{}); //cannon ammo

	Showdown = new Level("SPEEDERCHASE", "SPEEDERCHASE", "/LEVELS/EPISODE_VI/SPEEDERCHASE/", false,
		{princessleia_endor, lukeskywalker_endor}, {},
		{princessleia_endor, lukeskywalker_endor, atat_driver, scouttrooper},
		{{'A', {0x10864, 0x1084d, 0x10836, 0x1081f, 0x10808, 0x107f1, 0x107da, 0x107c3, 0x107ac,
				   0x10795, 0x1077e, 0x10767, 0x10750, 0x10739, 0x10722, 0x1070b, 0x106f4, 0x106dd,
				   0x106c6, 0x106af, 0x10698}}},
		{},

		{{'A', {{ImperialPanel, 0x11F2C}}}}, {}); //rb

	Endor = new Level("ENDORBATTLE", "ENDORBATTLE", "/LEVELS/EPISODE_VI/ENDORBATTLE/", false,
		{hansolo_endor, princessleia_endor, r2d2, chewbacca, c3po, wicket}, {},
		{hansolo_endor, wicket, ewok},
		{{'A', {0x79f4, 0x79dd, 0x79c6, 0x79af, 0x796a, 0x7953, 0x793c}},
			{'B', {0xa703, 0xa6ec, 0xa6d5, 0xa6be, 0xa6a7}},
			{'C', {0x6ae3, 0x6acc, 0x6ab5, 0x6a9e, 0x6a87}},
			{'D', {0xa9b7, 0xa9a0, 0xa972, 0xa95b}}},
		{},

		{{'A', {{ProtoPanel, 0x7EAA}}},    //drops grapple point (story)
			{'B', {{ProtoPanel, 0xA9DE}}}, //start 12 button
			{'C', {{AstroPanel, 0x6D30}}}, //enter bunker

			{'D', {{AstroPanel, 0xAC41},    //right side - elevator
					  {ProtoPanel, 0xAC70}, //right side - unlock lever
					  {AstroPanel, 0xAC9F}, //right side - drop hatch pieces
					  {ProtoPanel, 0xACCE}, //left side - unlock lever
					  {ImperialPanel, 0xACFD}, {ProtoPanel, 0xAD2C}}}}, //left side - bonus

		{{'D', {{StormtrooperHat, 0xAD7A}}}});

	Destiny = new Level("EMPERORFIGHT", "EMPERORFIGHT", "/LEVELS/EPISODE_VI/EMPERORFIGHT/", false,
		{lukeskywalker_jedi, darthvader}, {}, {darthvader, imperialguard, theemperor},
		{{'A', {0xc7d7, 0xc7c0, 0xc7a9, 0xc792, 0xc77b, 0xc764, 0xc74d, 0xc736, 0xc71f, 0xc708,
				   0xc6f1, 0xc6da, 0xc6c3, 0xb669, 0xb652}},
			{'B', {0x3c13, 0x3bfc, 0x3be5, 0x3bce, 0x3b44, 0x3b2d}}},
		{},

		{{'A', {{ImperialPanel, 0xCA4A}, {BountyPanel, 0xCA79}, {ProtoPanel, 0xCAA8},       //bonus
				   {BountyPanel, 0xCAD7}, {ImperialPanel, 0xCB06}, {BountyPanel, 0xCB35}}}, //bonus

			{'B', {{ProtoPanel, 0x3F78}, {AstroPanel, 0x3FA7}}}},
		{}); //bonus

	ITDS = new Level("DEATHSTAR2BATTLE", "DEATHSTAR2BATTLE", "/LEVELS/EPISODE_VI/DEATHSTAR2BATTLE/",
		true, {millenniumfalcon, xwing}, {}, {admiralackbar},
		{{'A', {0xd9c, 0xd85, 0xd6e, 0xd57}}, {'B', {0x34b2, 0x349b, 0x3484, 0x346d}},
			{'C', {0x103a, 0x1023, 0x100c, 0xff5}}, {'D', {0x1f1b, 0x1f04, 0x1eed}},
			{'E', {0x1dae, 0x1d97}}, {'F', {0x1f3f, 0x1f28}}, {'G', {0x30bc, 0x30a5}}},
		{}, {}, {});

	//PodraceOriginal = new Level("PODRACE", "PODRACE", "/LEVELS/EPISODE_I/PODRACE/", true,
	//	{fakeAnakinsPod, fakeAnakinsPodGreen}, {},
	//	{},
	//	{}, {}, {}, {});

	Anakinsflight = new Level("ANAKINSFLIGHT", "ANAKINSFLIGHT", "/LEVELS/ANAKINSFLIGHT/", false,
		{naboostarfighter, naboostarfighter_lime}, {}, {naboostarfighter, naboostarfighter_lime},
		{}, {}, {}, {});

	ANewHope = new Level("ANEWHOPE", "ANEWHOPE", "/LEVELS/EPISODE_III/ANEWHOPE/", false,
		{darthvader, stormtrooper, c3po}, {}, {}, {}, {},
		{{'A', {{ProtoPanel, 0x6771}, {ProtoPanel, 0x67A0}, {ProtoPanel, 0x67CF}}}}, {}); //story

	BHM = new Level("", "", "TEST", false, {bobafett, greedo, ig88, fourlom, bossk, dengar},
		{quigonjinn, amidala, jarjarbinks, macewindu, kitfisto, luminara, kiadimundi, rebelscum,
			shaakti, clone_ep3_sand, r2d2, benkenobi, chewbacca, princessleia, admiralackbar, yoda,
			c3po, landocalrissian, lukeskywalker_tatooine, hansolo},
		{}, {}, {}, {}, {});

	Cantina = new Level("MAP", "MAP", "/LEVELS/MAP/", false, {}, {}, {}, {}, {}, {},
		{{'\0', {{RandomHat, 0x12402}}}});
	BHM->fakeLevel = true;
	Cantina->fakeLevel = true;
}