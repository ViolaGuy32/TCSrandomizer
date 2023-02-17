//#include "CharacterData.h"
#include "Characters.h"
#include "Defines.h"
#include "pch.h"

Playable* quigonjinn = new Playable("quigonjinn", "Qui-Gon Jinn", 25000, 0x7f1c30, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* obiwankenobi = new Playable("obiwankenobi", "Obi-Wan Kenobi", 22000, 0x7f1c38, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* tc14 = new Playable("tc14", "TC-14", 4000, 0x7f202c, 0.75f,
	{Proto, Droid, Passive, Gas, Pushable, Zappable});

Playable* jarjarbinks = new Playable("jarjarbinks", "Jar Jar Binks", 14000, 0x7f1f00, 1.32f,
	{Build, Box, Jump, DoubleJump, HighJump, RealDoubleJump, HighDoubleJump, GunganJump, Chokeable, Trickable});

Playable* amidala = new Playable("amidala", "Queen Amidala", 24000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable* captainpanaka = new Playable("captainpanaka", "Captain Panaka", 12000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable* padmebattle = new Playable("padmebattle", "Padmé (Battle)", 20000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable* r2d2 = new Playable("r2d2", "R2-D2", 5000, 0x7f1fa0, 1.0f,
	{Fly, Zapper, AstroZapper, Astro, Droid, Passive, Gas, Pushable, Zappable});

Playable* anakin_boy = new Playable("anakin_boy", "Anakin Skywalker (Boy)", 6000, 0x0, 0.8f,
	{Lever, Build, Box, Jump, Hatch, Chokeable});

Playable* obiwankenobi_jedimaster = new Playable("obiwankenobi_jedimaster", "Obi-Wan Kenobi (jedi Master)", 30000, 0x7f1f18, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* r4_p17 = new Playable("r4_p17", "R4-P17", 4000, 0x0, 1.0f,
	{Fly, Zapper, AstroZapper, Astro, Droid, Passive, Gas, Pushable, Zappable});

Playable* anakin_padawan = new Playable("anakin_padawan", "Anakin Skywalker (Padawan)", 24000, 0x7f1f10, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* padmegeo = new Playable("padmegeo", "Padmé (Geonosis)", 20000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable* c3po = new Playable("c3po", "C-3PO", 5000, 0x7f2020, 0.75f,
	{Proto, Droid, Passive, Gas, Pushable, Zappable});

Playable* macewindu = new Playable("macewindu", "Mace Windu", 36000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* padmeclawed = new Playable("padmeclawed", "Padmé (Clawed)", 20000, 0x7f1f08, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable* yoda = new Playable("yoda", "Yoda", 80000, 0x7f1d08, 1.44f,
	{Lever, Build, Box, Jump, DoubleJump, YodaJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* obiwankenobi_ep3 = new Playable("obiwankenobi_ep3", "Obi-Wan Kenobi (Episode III)", 300000, 0x7f1f58, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* anakin_jedi = new Playable("anakin_jedi", "Anakin Skywalker (jedi)", 35000, 0x7f1f60, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* palpatine = new Playable("palpatine", "Chancellor Palpatine", 8000, 0x7f1f90, 1.2f,
	{Hat, Lever, Build, Box, Jump, Chokeable});

Playable* clone_ep3_sand = new Playable("clone_ep3_sand", "Commander Cody", 12000, 0x7f1cb0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* chewbacca = new Playable("chewbacca", "Chewbacca", 18000, 0x7f1d50, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable* princessleia = new Playable("princessleia", "Princess Leia", 20000, 0x7f1c40, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable* captainantilles = new Playable("captainantilles", "Captain Antilles", 14000, 0x7f1c58, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* rebelfriend = new Playable("rebelfriend", "Rebel Friend", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* lukeskywalker_tatooine = new Playable("lukeskywalker_tatooine", "Luke Skywalker (Tatooine)", 12000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* benkenobi = new Playable("benkenobi", "Ben Kenobi", 30000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* hansolo = new Playable("hansolo", "Han Solo", 18000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* hansolo_stormtrooper = new Playable("hansolo_stormtrooper", "Han Solo (Stormtrooper)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* lukeskywalker_stormtrooper = new Playable("lukeskywalker_stormtrooper", "Luke Skywalker (Stormtrooper)", 14000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* hansolo_hoth = new Playable("hansolo_hoth", "Han Solo (Hoth)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* princessleia_hoth = new Playable("princessleia_hoth", "Princess Leia (Hoth)", 22000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable* lukeskywalker_pilot = new Playable("lukeskywalker_pilot", "Luke Skywalker (Pilot)", 14000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* lukeskywalker_dagobah = new Playable("lukeskywalker_dagobah", "Luke Skywalker (Dagobah)", 28000, 0x7f1e90, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable, LukeAlt});

Playable* lukeskywalker_bespin = new Playable("lukeskywalker_bespin", "Luke Skywalker (Bespin)", 30000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable, LukeAlt});

Playable* landocalrissian = new Playable("landocalrissian", "Lando Calrissian", 15000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Trickable, LandoAlt});

Playable* princessleia_bespin = new Playable("princessleia_bespin", "Princess Leia (Bespin)", 22000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable* lukeskywalker_jedi = new Playable("lukeskywalker_jedi", "Luke Skywalker (jedi)", 40000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable, LukeAlt});

Playable* princessleia_boushh = new Playable("princessleia_boushh", "Princess Leia (Boushh)", 22000, 0x7f1c50, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable* lando_palaceguard = new Playable("lando_palaceguard", "Lando (Palace Guard)", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Trickable, LandoAlt});

Playable* hansolo_skiff = new Playable("hansolo_skiff", "Han Solo (Skiff)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* princessleia_slave = new Playable("princessleia_slave", "Princess Leia (Slave)", 40000, 0x7f1c48, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable* princessleia_endor = new Playable("princessleia_endor", "Princess Leia (Endor)", 22000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable* lukeskywalker_endor = new Playable("lukeskywalker_endor", "Luke Skywalker (Endor)", 42000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable, LukeAlt});

Playable* hansolo_endor = new Playable("hansolo_endor", "Han Solo (Endor)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* wicket = new Playable("wicket", "Wicket", 38000, 0x7f1dc8, 0.9f,
	{Lever, Build, Box, Jump, Attack, Shoot, Hatch, Chokeable, Trickable});

Playable* darthvader = new Playable("darthvader", "Darth Vader", 150000, 0x7f1eb0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith, Choke, Imperial, Chokeable});

Playable* gonkdroid = new Playable("gonkdroid", "Gonk droid", 3000, 0x7f2018, 0.12f,
	{Droid, Passive, Gas, Pushable, Zappable, NoLevel});

Playable* pkdroid = new Playable("pkdroid", "PK droid", 1500, 0x7f1ce8, 0.828538f,
	{Droid, Passive, Gas, Pushable, Zappable, NoLevel});

Playable* battledroid = new Playable("battledroid", "Battle droid", 6500, 0x7f1c88, 1.2f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable* battledroid_security = new Playable("battledroid_security", "Battle droid (Security)", 8500, 0x7f1ca0, 1.2f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable* battledroid_commander = new Playable("battledroid_commander", "Battle droid (Commander)", 10000, 0x7f1c90, 1.2f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable* destroyer = new Playable("destroyer", "droideka", 40000, 0x7f1d78, 1.8f,
	{Attack, Shoot, Droid, Gas, Zappable});

Playable* captaintarpals = new Playable("captaintarpals", "Captain Tarpals", 17500, 0x7f1c60, 1.32f,
	{Build, Box, Jump, DoubleJump, HighJump, RealDoubleJump, HighDoubleJump, GunganJump, Attack, Chokeable, Trickable});

Playable* bossnass = new Playable("bossnass", "Boss Nass", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Chokeable, Trickable});

Playable* royalguard = new Playable("royalguard", "Royal Guard", 10000, 0x7f1fb8, 1.2f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable* padme = new Playable("padme", "Padmé", 20000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable* watto = new Playable("watto", "Watto", 16000, 0x7f1d38, 1.5f,
	{Flutter, Zapper});

Playable* pitdroid = new Playable("pitdroid", "Pit droid", 4000, 0x7f2068, 0.8f,
	{Droid, Passive, Gas, Pushable, Zappable});

Playable* darthmaul = new Playable("darthmaul", "Darth Maul", 60000, 0x7f1c78, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith, Chokeable});

Playable* zamwesell = new Playable("zamwesell", "Zam Wesell", 27500, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Bounty, Chokeable, Trickable});

Playable* dexter = new Playable("dexter", "Dexter Jettster", 10000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Chokeable, Trickable});

Playable* clone = new Playable("clone", "Clone", 13000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* lamasu = new Playable("lamasu", "Lama Su", 9000, 0x7f2090, 1.2f,
	{Lever, Build, Box, Jump, Tall, Chokeable});

Playable* taunwe = new Playable("taunwe", "Taun We", 9000, 0x7f2098, 1.2f,
	{Lever, Build, Box, Jump, Chokeable});

Playable* geonosian = new Playable("geonosian", "Geonosian", 20000, 0x7f1d30, 1.5f,
	{Lever, Flutter, Attack, Shoot, Pushable, Chokeable});

Playable* battledroid_geonosian = new Playable("battledroid_geonosian", "Battle droid (Geonosis)", 8500, 0x7f1c98, 1.2f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable* superbattledroid = new Playable("superbattledroid", "Super Battle droid", 25000, 0x7f1d80, 1.07f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable* jangofett = new Playable("jangofett", "Jango Fett", 70000, 0x7f1f38, 1.2f,
	{Lever, Build, Box, Jump, Fly, Fett, Attack, Shoot, Grapple, Bounty, Chokeable});

Playable* bobafett_boy = new Playable("bobafett_boy", "Boba Fett (Boy)", 5500, 0x0, 0.8f,
	{Lever, Build, Box, Jump, Hatch, Chokeable});

Playable* luminara = new Playable("luminara", "Luminara", 28000, 0x7f1f28, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* kiadimundi = new Playable("kiadimundi", "Ki-Adi Mundi", 30000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* kitfisto = new Playable("kitfisto", "Kit Fisto", 35000, 0x7f1f98, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* shaakti = new Playable("shaakti", "Shaak Ti", 36000, 0x7f1f20, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* aylasecura = new Playable("aylasecura", "Aayla Secura", 37000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* plokoon = new Playable("plokoon", "Plo Koon", 39000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* countdooku = new Playable("countdooku", "Count Dooku", 100000, 0x7f1f88, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith, Choke, Chokeable});

Playable* bodyguard = new Playable("bodyguard", "Grievous' Bodyguard", 24000, 0x7f1c70, 1.4f,
	{Jump, DoubleJump, HighJump, ExtraHighJump, Saber, Gas, Tall});

Playable* grievous = new Playable("grievous", "General Grievous", 70000, 0x7f1e48, 1.2f,
	{Build, Jump, DoubleJump, HighJump, ExtraHighJump, RealDoubleJump, HighDoubleJump, Saber, Deflect});

Playable* wookie = new Playable("wookie", "Wookiee", 16000, 0x7f1d58, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable* clone_ep3 = new Playable("clone_ep3", "Clone (Episode III)", 10000, 0x7f1ca8, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* clone_ep3_pilot = new Playable("clone_ep3_pilot", "Clone (Episode III, Pilot)", 11000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* clone_ep3_swamp = new Playable("clone_ep3_swamp", "Clone (Episode III, Swamp)", 12000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* clone_ep3_walker = new Playable("clone_ep3_walker", "Clone (Episode III, Walker)", 12000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* macewindu_ep3 = new Playable("macewindu_ep3", "Mace Windu (Episode III)", 38000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable* disguisedclone = new Playable("disguisedclone", "Disguised Clone", 12000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* rebelscum = new Playable("rebelscum", "Rebel Trooper", 10000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* stormtrooper = new Playable("stormtrooper", "Stormtrooper", 10000, 0x7f1ff0, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable* imperialshuttlepilot = new Playable("imperialshuttlepilot", "imperial Shuttle Pilot", 25000, 0x7f2000, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* tuskenraider = new Playable("tuskenraider", "Tusken Raider", 23000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* jawa = new Playable("jawa", "Jawa", 24000, 0x7f1e88, 0.9f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Zapper, Hatch, Chokeable, Trickable});

Playable* sandtrooper = new Playable("sandtrooper", "Sandtrooper", 14000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable* greedo = new Playable("greedo", "Greedo", 60000, 0x7f2050, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Bounty, Chokeable, Trickable});

Playable* imperialspy = new Playable("imperialspy", "imperial Spy", 13500, 0x7f2048, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Chokeable, Trickable});

Playable* beachtrooper = new Playable("beachtrooper", "Beach Trooper", 20000, 0x7f1ff8, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable* deathstartrooper = new Playable("deathstartrooper", "Death Star Trooper", 19000, 0x7f1ea8, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable* tiefighterpilot = new Playable("tiefighterpilot", "TIE Fighter Pilot", 21000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable* imperialofficer = new Playable("imperialofficer", "imperial Officer", 28000, 0x7f2008, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* grandmofftarkin = new Playable("grandmofftarkin", "Grand Moff Tarkin", 38000, 0x7f2010, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable* hansolo_hood = new Playable("hansolo_hood", "Han Solo (Hood)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* rebelhoth = new Playable("rebelhoth", "Rebel Trooper (Hoth)", 16000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* rebelpilot = new Playable("rebelpilot", "Rebel Pilot", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* snowtrooper = new Playable("snowtrooper", "Snowtrooper", 16000, 0x7f1ea0, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable* lukeskywalker_hoth = new Playable("lukeskywalker_hoth", "Luke Skywalker (Hoth)", 14000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* lobot = new Playable("lobot", "Lobot", 11000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Chokeable, Trickable});

Playable* ugnaught = new Playable("ugnaught", "Ugnaught", 36000, 0x7f1fd8, 0.9f,
	{Lever, Build, Box, Jump, Zapper, Hatch, Chokeable, Trickable});

Playable* bespinguard = new Playable("bespinguard", "Bespin Guard", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* princessleia_prisoner = new Playable("princessleia_prisoner", "Princess Leia (Prisoner)", 22000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable* gamorreanguard = new Playable("gamorreanguard", "Gamorrean Guard", 40000, 0x7f1c80, 0.75f,
	{Lever, Build, Box, Jump, Attack, Chokeable, Trickable});

Playable* bibfortuna = new Playable("bibfortuna", "Bib Fortuna", 16000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Chokeable, Trickable});

Playable* palaceguard = new Playable("palaceguard", "Palace Guard", 14000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* bossk = new Playable("bossk", "Bossk", 75000, 0x7f2058, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Bounty, Chokeable, Trickable});

Playable* skiffguard = new Playable("skiffguard", "Skiff Guard", 12000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* bobafett = new Playable("bobafett", "Boba Fett", 100000, 0x7f1d88, 1.2f,
	{Lever, Build, Box, Jump, Fly, Fett, Attack, Shoot, Grapple, Bounty, Chokeable});

Playable* ewok = new Playable("ewok", "Ewok", 34000, 0x7f1dc0, 0.9f,
	{Lever, Build, Box, Jump, Attack, Shoot, Hatch, Chokeable, Trickable});

Playable* imperialguard = new Playable("imperialguard", "imperial Guard", 45000, 0x7f1c68, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Imperial, Chokeable, Trickable, Storm});

Playable* theemperor = new Playable("theemperor", "The Emperor", 275000, 0x7f1eb8, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith, Choke, Imperial, Chokeable});

Playable* admiralackbar = new Playable("admiralackbar", "Admiral Ackbar", 33000, 0x0, 1.4f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable* ig88 = new Playable("ig88", "IG-88", 100000, 0x0, 1.2f,
	{Box, Jump, Attack, Shoot, Grapple, Astro, Proto, Bounty, Droid, Gas, Pushable, Chokeable, Zappable, AllEpisodes});

Playable* dengar = new Playable("dengar", "Dengar", 70000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Bounty, Chokeable, Trickable, AllEpisodes});

Playable* fourlom = new Playable("4lom", "4-LOM", 45000, 0x7f1d90, 1.2f,
	{Box, Jump, Attack, Shoot, Grapple, Astro, Proto, Bounty, Droid, Gas, Pushable, Chokeable, Zappable, AllEpisodes});

Playable* ghostbenkenobi = new Playable("ghostbenkenobi", "Ben Kenobi (Ghost)", 1100000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Deflect, Jedi, Passive, Gas, Chokeable, AllEpisodes});

Playable* anakin_ghost = new Playable("anakin_ghost", "Anakin Skywalker (Ghost)", 1000000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Deflect, Jedi, Passive, Gas, Chokeable, AllEpisodes});

Playable* yoda_ghost = new Playable("yoda_ghost", "Yoda (Ghost)", 1200000, 0x7f1d10, 1.44f,
	{Lever, Build, Box, Jump, DoubleJump, YodaJump, RealDoubleJump, Attack, Deflect, Jedi, Passive, Gas, Chokeable, AllEpisodes});

Playable* r2q5 = new Playable("r2q5", "R2-Q5", 100000, 0x7f1fa8, 1.0f,
	{Fly, Zapper, AstroZapper, Astro, Droid, Passive, Gas, Pushable, Zappable, AllEpisodes});

Playable* hansolo_indy = new Playable("hansolo_indy", "Indiana Jones", 50000, 0x7f20c0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, AllEpisodes});

Playable* skeleton = new Playable("skeleton", "Skeleton", 3000, 0x7f20d0, 1.2f,
	{Extratoggle});

Playable* buzzdroid = new Playable("buzzdroid", "Buzz droid", 1500, 0x7f20a0, 1.2f,
	{Extratoggle, Attack, Droid, Gas, Pushable, Zappable});

Playable* trainingremote = new Playable("trainingremote", "Training Remote", 2000, 0x7f1d98, 1.05f,
	{Extratoggle, Hovering, FakeShoot, Droid, Gas});

Playable* engineer = new Playable("engineer", "Rebel Engineer", 8000, 0x0, 1.2f,
	{Extratoggle, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable* naffdroid1 = new Playable("naffdroid1", "droid 1", 1500, 0x7f1cb8, 0.6f,
	{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

Playable* naffdroid2 = new Playable("naffdroid2", "droid 2", 1500, 0x7f1cc0, 0.6f,
	{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

Playable* naffdroid3 = new Playable("naffdroid3", "droid 3", 1500, 0x7f1cc8, 0.4f,
	{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

Playable* naffdroid4 = new Playable("naffdroid4", "droid 4", 1500, 0x7f1cd0, 0.6f,
	{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

Playable* womprat = new Playable("womprat", "Womp Rat", 25000, 0x7f1d00, 1.8f,
	{Extratoggle, Passive});

Playable* mousedroid = new Playable("mousedroid", "Mouse droid", 3000, 0x7f1cd8, 2.4f,
	{Extratoggle, Droid, Passive, Gas, Pushable, Zappable});

Playable* imperialengineer = new Playable("imperialengineer", "imperial Engineer", 9000, 0x0, 1.2f,
	{Extratoggle, Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable* hanincarbonite = new Playable("hanincarbonite", "Han Solo (frozen in carbonite)", 5000, 0x0, 0.75f,
	{Extratoggle});

Playable* atat_driver = new Playable("atat_driver", "AT-AT Driver", 25000, 0x0, 1.2f,
	{Extratoggle, Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable* scouttrooper = new Playable("scouttrooper", "Scout Trooper", 16000, 0x0, 1.2f,
	{Extratoggle, Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable* newanakinspod = new Playable("newanakinspod", "Anakin's Pod", 20000, 0x7f21e0, 1.2f,
	{Vehicle});

Playable* naboostarfighter = new Playable("naboostarfighter", "Naboo Starfighter", 12000, 0x7f20b0, 1.2f,
	{Vehicle, Attack, Shoot, Tow});

Playable* anakinsspeeder = new Playable("anakinsspeeder", "Anakin's Speeder", 15000, 0x7f21f0, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* newrepublicgunship = new Playable("newrepublicgunship", "Republic Gunship", 18000, 0x7f1f78, 1.2f,
	{Vehicle, Attack, Shoot, Tow});

Playable* jedistarfighter_yellow_ep3 = new Playable("jedistarfighter_yellow_ep3", "jedi Starfighter (Yellow)", 10000, 0x7f1f40, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* jedistarfighter_red_ep3 = new Playable("jedistarfighter_red_ep3", "jedi Starfighter (Red)", 10000, 0x7f1f48, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* xwing = new Playable("xwing", "X-wing", 25000, 0x7f1fb0, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* ywing = new Playable("ywing", "Y-wing", 25000, 0x7f1e38, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* snowspeeder = new Playable("snowspeeder", "Snowspeeder", 20000, 0x7f1fc0, 1.2f,
	{Vehicle, Attack, Shoot, Tow});

Playable* millenniumfalcon = new Playable("millenniumfalcon", "Millennium Falcon", 40000, 0x7f1ec0, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* sebulbaspod = new Playable("sebulbaspod", "Sebulba's Pod", 20000, 0x7f21c0, 1.2f,
	{Vehicle});

Playable* zamsspeeder = new Playable("zamsspeeder", "Zam's Airspeeder", 24000, 0x7f2200, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* droidtrifighter = new Playable("droidtrifighter", "droid Trifighter", 28000, 0x7f2210, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* vulturedroid = new Playable("vulturedroid", "Vulture droid", 30000, 0x7f2208, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* clonearc = new Playable("clonearc", "Clone Arcfighter", 33000, 0x7f20a8, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* tiefighter = new Playable("tiefighter", "TIE Fighter", 35000, 0x7f1e58, 1.2f,
	{Vehicle, Attack, Shoot, TieDoor});

Playable* tieinterceptor = new Playable("tieinterceptor", "TIE Interceptor", 40000, 0x7f1fc8, 1.2f,
	{Vehicle, Attack, Shoot, TieDoor});

Playable* tiefighterdarth = new Playable("tiefighterdarth", "TIE Fighter (Darth Vader)", 50000, 0x7f1e50, 1.2f,
	{Vehicle, Attack, Shoot, TieDoor});

Playable* tiebomber = new Playable("tiebomber", "TIE Bomber", 60000, 0x7f1e40, 1.2f,
	{Vehicle, Attack, Shoot, TieDoor});

Playable* imperialshuttle = new Playable("imperialshuttle", "imperial Shuttle", 25000, 0x7f1fd0, 1.2f,
	{Vehicle, Attack, Shoot});

Playable* slave1 = new Playable("slave1", "Slave 1", 100000, 0x7f1e30, 1.2f,
	{Vehicle, Attack, Shoot, AllEpisodes});

Playable* newanakinspod_green = new Playable("newanakinspod_green", "Anakin's Pod (Green)", 20000, 0x7f21b8, 1.2f,
	{Vehicle, Vgreen});

Playable* naboostarfighter_lime = new Playable("naboostarfighter_lime", "Naboo Starfighter (Green)", 12000, 0x7f20b8, 1.2f,
	{Vehicle, Vgreen, Attack, Shoot, Tow});

Playable* anakinsspeeder_green = new Playable("anakinsspeeder_green", "Anakin's Speeder (Green)", 15000, 0x7f21f8, 1.2f,
	{Vehicle, Vgreen, Attack, Shoot});

Playable* newrepublicgunship_green = new Playable("newrepublicgunship_green", "Republic Gunship (Green)", 18000, 0x7f1f80, 1.2f,
	{Vehicle, Vgreen, Attack, Shoot, Tow});

Playable* defaultCharacter = new Playable("", "", 0, 0, 0.0f, {Fake});

//podrace original uses a different version of the pods i
Playable* fakeAnakinsPod = new Playable("anakinspod", "", 0, 0, 0.0f, {Fake, Vehicle});

Playable* fakeAnakinsPodGreen = new Playable("anakinspod_green", "", 0, 0, 0.0f, {Fake, Vehicle});

Level* Negotiations = new Level("NEGOTIATIONS", "NEGOTIATIONS", "/LEVELS/EPISODE_I/NEGOTIATIONS/", false,
	{quigonjinn, obiwankenobi, tc14}, {},
	{quigonjinn, obiwankenobi, tc14, battledroid, battledroid_security, battledroid_commander, destroyer},
	{}, {});

Level* Invasion = new Level("GUNGAN", "GUNGAN", "/LEVELS/EPISODE_I/GUNGAN/", false,
	{quigonjinn, obiwankenobi, jarjarbinks}, {},
	{jarjarbinks, captaintarpals, bossnass},
	{}, {});

Level* EscapeNaboo = new Level("PALACERESCUE", "RESCUE", "/LEVELS/EPISODE_I/PALACERESCUE/", false,
	{amidala, captainpanaka, quigonjinn, obiwankenobi}, {},
	{amidala, captainpanaka, royalguard, padme},
	{}, {});

Level* Podrace = new Level("PODSPRINT", "PODSPRINT", "/LEVELS/EPISODE_I/PODSPRINT/", true,
	{newanakinspod, newanakinspod_green}, {},
	{watto, pitdroid, newanakinspod, newanakinspod_green, sebulbaspod},
	{}, {});

Level* Theed = new Level("RETAKEPALACE", "RETAKE", "/LEVELS/EPISODE_I/RETAKEPALACE/", false,
	{obiwankenobi, quigonjinn, captainpanaka, padmebattle, r2d2, anakin_boy}, {},
	{padmebattle, r2d2, anakin_boy},
	{}, {});

Level* Maul = new Level("MAUL", "MAUL", "/LEVELS/EPISODE_I/MAUL/", false,
	{obiwankenobi, quigonjinn}, {},
	{darthmaul},
	{}, {});

Level* BHP = new Level("PURSUIT", "PURSUIT", "/LEVELS/EPISODE_II/PURSUIT/", true,
	{anakinsspeeder, anakinsspeeder_green}, {},
	{zamwesell, dexter, anakinsspeeder, anakinsspeeder_green, zamsspeeder},
	{}, {});

Level* Kamino = new Level("KAMINO", "KAMINO", "/LEVELS/EPISODE_II/KAMINO/", false,
	{obiwankenobi_jedimaster, r4_p17}, {},
	{obiwankenobi_jedimaster, r4_p17, clone, lamasu, taunwe},
	{}, {});

Level* Factory = new Level("FACTORY", "FACTORY", "/LEVELS/EPISODE_II/FACTORY/", false,
	{anakin_padawan, padmegeo, r2d2, c3po}, {obiwankenobi_jedimaster},
	{anakin_padawan, padmegeo, c3po, geonosian, battledroid_geonosian, skeleton},
	{}, {});

Level* JediBattle = new Level("JEDI", "JEDI", "/LEVELS/EPISODE_II/JEDI/", false,
	{macewindu, r2d2, obiwankenobi_jedimaster, anakin_padawan, padmeclawed}, {},
	{macewindu, padmeclawed, superbattledroid, jangofett, bobafett_boy, luminara, kiadimundi, kitfisto, shaakti, aylasecura, plokoon},
	{}, {});

Level* Gunship = new Level("GUNSHIP", "GUNSHIP", "/LEVELS/EPISODE_II/GUNSHIP/", true,
	{newrepublicgunship, newrepublicgunship_green}, {},
	{newrepublicgunship, newrepublicgunship_green},
	{}, {});

Level* Dooku = new Level("DOOKU", "DOOKU", "/LEVELS/EPISODE_II/DOOKU/", false,
	{obiwankenobi_jedimaster, anakin_padawan, yoda}, {},
	{yoda},
	{}, {});

Level* Coruscant = new Level("DOGFIGHT", "DOGFIGHT", "/LEVELS/EPISODE_III/DOGFIGHT/", true,
	{jedistarfighter_yellow_ep3, jedistarfighter_red_ep3}, {},
	{jedistarfighter_yellow_ep3, jedistarfighter_red_ep3, droidtrifighter, vulturedroid, clonearc},
	{}, {});

Level* Chancellor = new Level("CRUISER", "CRUISER", "/LEVELS/EPISODE_III/CRUISER/", false,
	{obiwankenobi_ep3, anakin_jedi, r2d2, palpatine}, {},
	{obiwankenobi_ep3, anakin_jedi, palpatine, countdooku, bodyguard, buzzdroid},
	{}, {});

Level* Grievous = new Level("GRIEVOUS", "GRIEVOUS", "/LEVELS/EPISODE_III/GRIEVOUS/", false,
	{obiwankenobi_ep3, clone_ep3_sand}, {},
	{clone_ep3_sand, grievous},
	{}, {});

Level* Kashyyyk = new Level("KASHYYYK", "KASHYYYK", "/LEVELS/EPISODE_III/KASHYYYK/", false,
	{yoda, chewbacca}, {},
	{chewbacca, wookie, clone_ep3, clone_ep3_pilot, clone_ep3_swamp, clone_ep3_walker},
	{}, {});

Level* Ruin = new Level("TEMPLE", "TEMPLE", "/LEVELS/EPISODE_III/TEMPLE/", false,
	{obiwankenobi_ep3, yoda}, {},
	{macewindu_ep3, disguisedclone, trainingremote},
	{}, {});

Level* Vader = new Level("VADER", "VADER", "/LEVELS/EPISODE_III/VADER/", false,
	{obiwankenobi_ep3, anakin_jedi}, {},
	{},
	{}, {});

Level* SecretPlans = new Level("BLOCKADERUNNER", "BLOCKADERUNNER", "/LEVELS/EPISODE_IV/BLOCKADERUNNER/", false,
	{princessleia, captainantilles, rebelfriend, c3po, r2d2}, {},
	{princessleia, captainantilles, rebelfriend, rebelscum, stormtrooper, imperialshuttlepilot, engineer},
	{}, {});

Level* Jundland = new Level("TATOOINE", "TATOOINE", "/LEVELS/EPISODE_IV/TATOOINE/", false,
	{lukeskywalker_tatooine, benkenobi, c3po, r2d2}, {},
	{lukeskywalker_tatooine, benkenobi, tuskenraider, jawa, naffdroid1, naffdroid2, naffdroid3, naffdroid4, womprat},
	{}, {});

Level* Spaceport = new Level("MOSEISLEY", "MOSEISLEY", "/LEVELS/EPISODE_IV/MOSEISLEY/", false,
	{lukeskywalker_tatooine, benkenobi, r2d2, c3po, hansolo, chewbacca}, {},
	{hansolo, sandtrooper, greedo, imperialspy},
	{}, {});

Level* Princess = new Level("DEATHSTARRESCUE", "DEATHSTARRESCUE", "/LEVELS/EPISODE_IV/DEATHSTARRESCUE/", false,
	{hansolo_stormtrooper, lukeskywalker_stormtrooper, chewbacca, r2d2, c3po, benkenobi}, {princessleia},
	{hansolo_stormtrooper, lukeskywalker_stormtrooper, beachtrooper, deathstartrooper, tiefighterpilot, imperialofficer, grandmofftarkin, mousedroid, imperialengineer},
	{}, {});

Level* DSE = new Level("DEATHSTARESCAPE", "DEATHSTARESCAPE", "/LEVELS/EPISODE_IV/DEATHSTARESCAPE/", false,
	{hansolo, chewbacca, princessleia, lukeskywalker_tatooine, r2d2, c3po}, {},
	{},
	{}, {});

Level* RebelAttack = new Level("DEATHSTARBATTLE", "DEATHSTARBATTLE", "/LEVELS/EPISODE_IV/DEATHSTARBATTLE/", true,
	{xwing, ywing}, {},
	{xwing, ywing, tiefighter, tieinterceptor, tiefighterdarth},
	{}, {});

Level* Hoth = new Level("HOTHBATTLE", "HOTHBATTLE", "/LEVELS/EPISODE_V/HOTHBATTLE/", true,
	{snowspeeder, snowspeeder}, {},
	{snowspeeder},
	{}, {});

Level* EchoBase = new Level("HOTHESCAPE", "HOTHESCAPE", "/LEVELS/EPISODE_V/HOTHESCAPE/", false,
	{hansolo_hoth, princessleia_hoth, c3po, chewbacca}, {},
	{hansolo_hoth, princessleia_hoth, hansolo_hood, rebelhoth, rebelpilot, snowtrooper, lukeskywalker_hoth},
	{}, {});

Level* FalconFlight = new Level("ASTEROIDCHASE", "ASTEROIDCHASE", "/LEVELS/EPISODE_V/ASTEROIDCHASE/", true,
	{millenniumfalcon, xwing}, {},
	{millenniumfalcon, tiebomber, imperialshuttle},
	{}, {});

Level* Dagobah = new Level("DAGOBAH", "DAGOBAH", "/LEVELS/EPISODE_V/DAGOBAH/", false,
	{lukeskywalker_pilot, r2d2, lukeskywalker_dagobah, yoda}, {},
	{lukeskywalker_pilot, lukeskywalker_dagobah},
	{}, {});

Level* CCT = new Level("CLOUDCITYTRAP", "CLOUDCITYTRAP", "/LEVELS/EPISODE_V/CLOUDCITYTRAP/", false,
	{lukeskywalker_bespin, r2d2}, {},
	{lukeskywalker_bespin, hanincarbonite},
	{}, {});

Level* Bespin = new Level("CLOUDCITYESCAPE", "CLOUDCITYESCAPE", "/LEVELS/EPISODE_V/CLOUDCITYESCAPE/", false,
	{landocalrissian, princessleia_bespin, chewbacca, r2d2, c3po}, {},
	{landocalrissian, princessleia_bespin, lobot, ugnaught, bespinguard, princessleia_prisoner},
	{}, {});

Level* Jabbas = new Level("JABBASPALACE", "JABBASPALACE", "/LEVELS/EPISODE_VI/JABBASPALACE/", false,
	{princessleia_boushh, chewbacca, lukeskywalker_jedi, c3po, r2d2, hansolo_skiff}, {},
	{lukeskywalker_jedi, princessleia_boushh, hansolo_skiff, gamorreanguard, bibfortuna, palaceguard, bossk},
	{}, {});

Level* Carkoon = new Level("SARLACCPIT", "SARLACCPIT", "/LEVELS/EPISODE_VI/SARLACCPIT/", false,
	{lando_palaceguard, lukeskywalker_jedi, chewbacca, hansolo_skiff, c3po, r2d2, princessleia_slave}, {},
	{lando_palaceguard, princessleia_slave, skiffguard, bobafett},
	{}, {});

Level* Showdown = new Level("SPEEDERCHASE", "SPEEDERCHASE", "/LEVELS/EPISODE_VI/SPEEDERCHASE/", false,
	{princessleia_endor, lukeskywalker_endor}, {},
	{princessleia_endor, lukeskywalker_endor, atat_driver, scouttrooper},
	{}, {});

Level* Endor = new Level("ENDORBATTLE", "ENDORBATTLE", "/LEVELS/EPISODE_VI/ENDORBATTLE/", false,
	{hansolo_endor, princessleia_endor, r2d2, chewbacca, c3po, wicket}, {},
	{hansolo_endor, wicket, ewok},
	{}, {});

Level* Destiny = new Level("EMPERORFIGHT", "EMPERORFIGHT", "/LEVELS/EPISODE_VI/EMPERORFIGHT/", false,
	{lukeskywalker_jedi, darthvader}, {},
	{darthvader, imperialguard, theemperor},
	{}, {});

Level* ITDS = new Level("DEATHSTAR2BATTLE", "DEATHSTAR2BATTLE", "/LEVELS/EPISODE_VI/DEATHSTAR2BATTLE/", true,
	{millenniumfalcon, xwing}, {},
	{admiralackbar},
	{}, {});

Level* PodraceOriginal = new Level("PODRACE", "PODRACE", "/LEVELS/EPISODE_I/PODRACE/", true,
	{fakeAnakinsPod, fakeAnakinsPodGreen}, {},
	{},
	{}, {});

Level* Anakinsflight = new Level("ANAKINSFLIGHT", "ANAKINSFLIGHT", "/LEVELS/ANAKINSFLIGHT/", false,
	{naboostarfighter, naboostarfighter_lime}, {},
	{},
	{}, {});

Level* ANewHope = new Level("ANEWHOPE", "ANEWHOPE", "/LEVELS/EPISODE_III/ANEWHOPE/", false,
	{}, {},
	{},
	{}, {});

Level* BHM = new Level("", "", "", false,
	{bobafett, greedo, ig88, fourlom, bossk, dengar},
	{quigonjinn, amidala, jarjarbinks, macewindu, kitfisto, luminara, kiadimundi, rebelscum, shaakti, clone_ep3_sand,
	r2d2, benkenobi, chewbacca, princessleia, admiralackbar, yoda, c3po, landocalrissian, lukeskywalker_tatooine, hansolo},
	{}, {}, {});