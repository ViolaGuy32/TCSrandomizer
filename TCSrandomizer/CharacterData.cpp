#include "CharacterData.h"
#include "Characters.h"

Playable quigonjinn("quigonjinn", "Qui-Gon Jinn", 25000, 0x7f1c30, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable obiwankenobi("obiwankenobi", "Obi-Wan Kenobi", 22000, 0x7f1c38, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable tc14("tc14", "TC-14", 4000, 0x7f202c, 0.75f,
	{Proto, Droid, Passive, Gas, Pushable, Zappable});

Playable jarjarbinks("jarjarbinks", "Jar Jar Binks", 14000, 0x7f1f00, 1.32f,
	{Build, Box, Jump, DoubleJump, HighJump, RealDoubleJump, HighDoubleJump, GunganJump, Chokeable, Trickable});

Playable amidala("amidala", "Queen Amidala", 24000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable captainpanaka("captainpanaka", "Captain Panaka", 12000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable padmebattle("padmebattle", "Padmé (Battle)", 20000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable r2d2("r2d2", "R2-D2", 5000, 0x7f1fa0, 1.0f,
	{Fly, Zapper, AstroZapper, Astro, Droid, Passive, Gas, Pushable, Zappable});

Playable anakin_boy("anakin_boy", "Anakin Skywalker (Boy)", 6000, 0x0, 0.8f,
	{Lever, Build, Box, Jump, Hatch, Chokeable});

Playable obiwankenobi_jedimaster("obiwankenobi_jedimaster", "Obi-Wan Kenobi (jedi Master)", 30000, 0x7f1f18, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable r4_p17("r4_p17", "R4-P17", 4000, 0x0, 1.0f,
	{Fly, Zapper, AstroZapper, Astro, Droid, Passive, Gas, Pushable, Zappable});

Playable anakin_padawan("anakin_padawan", "Anakin Skywalker (Padawan)", 24000, 0x7f1f10, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable padmegeo("padmegeo", "Padmé (Geonosis)", 20000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable c3po("c3po", "C-3PO", 5000, 0x7f2020, 0.75f,
	{Proto, Droid, Passive, Gas, Pushable, Zappable});

Playable macewindu("macewindu", "Mace Windu", 36000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable padmeclawed("padmeclawed", "Padmé (Clawed)", 20000, 0x7f1f08, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable yoda("yoda", "Yoda", 80000, 0x7f1d08, 1.44f,
	{Lever, Build, Box, Jump, DoubleJump, YodaJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable obiwankenobi_ep3("obiwankenobi_ep3", "Obi-Wan Kenobi (Episode III)", 300000, 0x7f1f58, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable anakin_jedi("anakin_jedi", "Anakin Skywalker (jedi)", 35000, 0x7f1f60, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable palpatine("palpatine", "Chancellor Palpatine", 8000, 0x7f1f90, 1.2f,
	{Hat, Lever, Build, Box, Jump, Chokeable});

Playable clone_ep3_sand("clone_ep3_sand", "Commander Cody", 12000, 0x7f1cb0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable chewbacca("chewbacca", "Chewbacca", 18000, 0x7f1d50, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable princessleia("princessleia", "Princess Leia", 20000, 0x7f1c40, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable captainantilles("captainantilles", "Captain Antilles", 14000, 0x7f1c58, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable rebelfriend("rebelfriend", "Rebel Friend", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable lukeskywalker_tatooine("lukeskywalker_tatooine", "Luke Skywalker (Tatooine)", 12000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable benkenobi("benkenobi", "Ben Kenobi", 30000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable hansolo("hansolo", "Han Solo", 18000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable hansolo_stormtrooper("hansolo_stormtrooper", "Han Solo (Stormtrooper)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable lukeskywalker_stormtrooper("lukeskywalker_stormtrooper", "Luke Skywalker (Stormtrooper)", 14000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable hansolo_hoth("hansolo_hoth", "Han Solo (Hoth)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable princessleia_hoth("princessleia_hoth", "Princess Leia (Hoth)", 22000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable lukeskywalker_pilot("lukeskywalker_pilot", "Luke Skywalker (Pilot)", 14000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable lukeskywalker_dagobah("lukeskywalker_dagobah", "Luke Skywalker (Dagobah)", 28000, 0x7f1e90, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable, LukeAlt});

Playable lukeskywalker_bespin("lukeskywalker_bespin", "Luke Skywalker (Bespin)", 30000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable, LukeAlt});

Playable landocalrissian("landocalrissian", "Lando Calrissian", 15000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Trickable, LandoAlt});

Playable princessleia_bespin("princessleia_bespin", "Princess Leia (Bespin)", 22000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable lukeskywalker_jedi("lukeskywalker_jedi", "Luke Skywalker (jedi)", 40000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable, LukeAlt});

Playable princessleia_boushh("princessleia_boushh", "Princess Leia (Boushh)", 22000, 0x7f1c50, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable lando_palaceguard("lando_palaceguard", "Lando (Palace Guard)", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Trickable, LandoAlt});

Playable hansolo_skiff("hansolo_skiff", "Han Solo (Skiff)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable princessleia_slave("princessleia_slave", "Princess Leia (Slave)", 40000, 0x7f1c48, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable princessleia_endor("princessleia_endor", "Princess Leia (Endor)", 22000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable lukeskywalker_endor("lukeskywalker_endor", "Luke Skywalker (Endor)", 42000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable, LukeAlt});

Playable hansolo_endor("hansolo_endor", "Han Solo (Endor)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable wicket("wicket", "Wicket", 38000, 0x7f1dc8, 0.9f,
	{Lever, Build, Box, Jump, Attack, Shoot, Hatch, Chokeable, Trickable});

Playable darthvader("darthvader", "Darth Vader", 150000, 0x7f1eb0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith, Choke, Imperial, Chokeable});

Playable gonkdroid("gonkdroid", "Gonk droid", 3000, 0x7f2018, 0.12f,
	{Droid, Passive, Gas, Pushable, Zappable, NoLevel});

Playable pkdroid("pkdroid", "PK droid", 1500, 0x7f1ce8, 0.828538f,
	{Droid, Passive, Gas, Pushable, Zappable, NoLevel});

Playable battledroid("battledroid", "Battle droid", 6500, 0x7f1c88, 1.2f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable battledroid_security("battledroid_security", "Battle droid (Security)", 8500, 0x7f1ca0, 1.2f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable battledroid_commander("battledroid_commander", "Battle droid (Commander)", 10000, 0x7f1c90, 1.2f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable destroyer("destroyer", "droideka", 40000, 0x7f1d78, 1.8f,
	{Attack, Shoot, Droid, Gas, Zappable});

Playable captaintarpals("captaintarpals", "Captain Tarpals", 17500, 0x7f1c60, 1.32f,
	{Build, Box, Jump, DoubleJump, HighJump, RealDoubleJump, HighDoubleJump, GunganJump, Attack, Chokeable, Trickable});

Playable bossnass("bossnass", "Boss Nass", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Chokeable, Trickable});

Playable royalguard("royalguard", "Royal Guard", 10000, 0x7f1fb8, 1.2f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable padme("padme", "Padmé", 20000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable watto("watto", "Watto", 16000, 0x7f1d38, 1.5f,
	{Flutter, Zapper});

Playable pitdroid("pitdroid", "Pit droid", 4000, 0x7f2068, 0.8f,
	{Droid, Passive, Gas, Pushable, Zappable});

Playable darthmaul("darthmaul", "Darth Maul", 60000, 0x7f1c78, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith, Chokeable});

Playable zamwesell("zamwesell", "Zam Wesell", 27500, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Bounty, Chokeable, Trickable});

Playable dexter("dexter", "Dexter Jettster", 10000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Chokeable, Trickable});

Playable clone("clone", "Clone", 13000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable lamasu("lamasu", "Lama Su", 9000, 0x7f2090, 1.2f,
	{Lever, Build, Box, Jump, Tall, Chokeable});

Playable taunwe("taunwe", "Taun We", 9000, 0x7f2098, 1.2f,
	{Lever, Build, Box, Jump, Chokeable});

Playable geonosian("geonosian", "Geonosian", 20000, 0x7f1d30, 1.5f,
	{Lever, Flutter, Attack, Shoot, Pushable, Chokeable});

Playable battledroid_geonosian("battledroid_geonosian", "Battle droid (Geonosis)", 8500, 0x7f1c98, 1.2f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable superbattledroid("superbattledroid", "Super Battle droid", 25000, 0x7f1d80, 1.07f,
	{Attack, Shoot, Droid, Gas, Pushable, Zappable});

Playable jangofett("jangofett", "Jango Fett", 70000, 0x7f1f38, 1.2f,
	{Lever, Build, Box, Jump, Fly, Fett, Attack, Shoot, Grapple, Bounty, Chokeable});

Playable bobafett_boy("bobafett_boy", "Boba Fett (Boy)", 5500, 0x0, 0.8f,
	{Lever, Build, Box, Jump, Hatch, Chokeable});

Playable luminara("luminara", "Luminara", 28000, 0x7f1f28, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable kiadimundi("kiadimundi", "Ki-Adi Mundi", 30000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable kitfisto("kitfisto", "Kit Fisto", 35000, 0x7f1f98, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable shaakti("shaakti", "Shaak Ti", 36000, 0x7f1f20, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable aylasecura("aylasecura", "Aayla Secura", 37000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable plokoon("plokoon", "Plo Koon", 39000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable countdooku("countdooku", "Count Dooku", 100000, 0x7f1f88, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith, Choke, Chokeable});

Playable bodyguard("bodyguard", "Grievous' Bodyguard", 24000, 0x7f1c70, 1.4f,
	{Jump, DoubleJump, HighJump, ExtraHighJump, Saber, Gas, Tall});

Playable grievous("grievous", "General Grievous", 70000, 0x7f1e48, 1.2f,
	{Build, Jump, DoubleJump, HighJump, ExtraHighJump, RealDoubleJump, HighDoubleJump, Saber, Deflect});

Playable wookie("wookie", "Wookiee", 16000, 0x7f1d58, 1.2f,
	{Hat, Lever, Build, Box, Jump, Attack, Shoot, Grapple, Chokeable});

Playable clone_ep3("clone_ep3", "Clone (Episode III)", 10000, 0x7f1ca8, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable clone_ep3_pilot("clone_ep3_pilot", "Clone (Episode III, Pilot)", 11000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable clone_ep3_swamp("clone_ep3_swamp", "Clone (Episode III, Swamp)", 12000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable clone_ep3_walker("clone_ep3_walker", "Clone (Episode III, Walker)", 12000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable macewindu_ep3("macewindu_ep3", "Mace Windu (Episode III)", 38000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Chokeable});

Playable disguisedclone("disguisedclone", "Disguised Clone", 12000, 0x0, 1.0f,
	{Lever, Build, Box, Jump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable rebelscum("rebelscum", "Rebel Trooper", 10000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable stormtrooper("stormtrooper", "Stormtrooper", 10000, 0x7f1ff0, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable imperialshuttlepilot("imperialshuttlepilot", "imperial Shuttle Pilot", 25000, 0x7f2000, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable tuskenraider("tuskenraider", "Tusken Raider", 23000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable jawa("jawa", "Jawa", 24000, 0x7f1e88, 0.9f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Zapper, Hatch, Chokeable, Trickable});

Playable sandtrooper("sandtrooper", "Sandtrooper", 14000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable greedo("greedo", "Greedo", 60000, 0x7f2050, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Bounty, Chokeable, Trickable});

Playable imperialspy("imperialspy", "imperial Spy", 13500, 0x7f2048, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Chokeable, Trickable});

Playable beachtrooper("beachtrooper", "Beach Trooper", 20000, 0x7f1ff8, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable deathstartrooper("deathstartrooper", "Death Star Trooper", 19000, 0x7f1ea8, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable tiefighterpilot("tiefighterpilot", "TIE Fighter Pilot", 21000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable imperialofficer("imperialofficer", "imperial Officer", 28000, 0x7f2008, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable grandmofftarkin("grandmofftarkin", "Grand Moff Tarkin", 38000, 0x7f2010, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable});

Playable hansolo_hood("hansolo_hood", "Han Solo (Hood)", 20000, 0x0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable rebelhoth("rebelhoth", "Rebel Trooper (Hoth)", 16000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable rebelpilot("rebelpilot", "Rebel Pilot", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable snowtrooper("snowtrooper", "Snowtrooper", 16000, 0x7f1ea0, 1.2f,
	{Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable lukeskywalker_hoth("lukeskywalker_hoth", "Luke Skywalker (Hoth)", 14000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable lobot("lobot", "Lobot", 11000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Chokeable, Trickable});

Playable ugnaught("ugnaught", "Ugnaught", 36000, 0x7f1fd8, 0.9f,
	{Lever, Build, Box, Jump, Zapper, Hatch, Chokeable, Trickable});

Playable bespinguard("bespinguard", "Bespin Guard", 15000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable princessleia_prisoner("princessleia_prisoner", "Princess Leia (Prisoner)", 22000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, LeiaAlt});

Playable gamorreanguard("gamorreanguard", "Gamorrean Guard", 40000, 0x7f1c80, 0.75f,
	{Lever, Build, Box, Jump, Attack, Chokeable, Trickable});

Playable bibfortuna("bibfortuna", "Bib Fortuna", 16000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Chokeable, Trickable});

Playable palaceguard("palaceguard", "Palace Guard", 14000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable bossk("bossk", "Bossk", 75000, 0x7f2058, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Bounty, Chokeable, Trickable});

Playable skiffguard("skiffguard", "Skiff Guard", 12000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable bobafett("bobafett", "Boba Fett", 100000, 0x7f1d88, 1.2f,
	{Lever, Build, Box, Jump, Fly, Fett, Attack, Shoot, Grapple, Bounty, Chokeable});

Playable ewok("ewok", "Ewok", 34000, 0x7f1dc0, 0.9f,
	{Lever, Build, Box, Jump, Attack, Shoot, Hatch, Chokeable, Trickable});

Playable imperialguard("imperialguard", "imperial Guard", 45000, 0x7f1c68, 1.2f,
	{Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Imperial, Chokeable, Trickable, Storm});

Playable theemperor("theemperor", "The Emperor", 275000, 0x7f1eb8, 1.2f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Saber, Deflect, Jedi, Sith, Choke, Imperial, Chokeable});

Playable admiralackbar("admiralackbar", "Admiral Ackbar", 33000, 0x0, 1.4f,
	{Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Dive, Attack, Shoot, Grapple, Chokeable});

Playable ig88("ig88", "IG-88", 100000, 0x0, 1.2f,
	{Box, Jump, Attack, Shoot, Grapple, Astro, Proto, Bounty, Droid, Gas, Pushable, Chokeable, Zappable, AllEpisodes});

Playable dengar("dengar", "Dengar", 70000, 0x0, 1.2f,
	{Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Bounty, Chokeable, Trickable, AllEpisodes});

Playable fourlom("4lom", "4-LOM", 45000, 0x7f1d90, 1.2f,
	{Box, Jump, Attack, Shoot, Grapple, Astro, Proto, Bounty, Droid, Gas, Pushable, Chokeable, Zappable, AllEpisodes});

Playable ghostbenkenobi("ghostbenkenobi", "Ben Kenobi (Ghost)", 1100000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Deflect, Jedi, Passive, Gas, Chokeable, AllEpisodes});

Playable anakin_ghost("anakin_ghost", "Anakin Skywalker (Ghost)", 1000000, 0x0, 1.2f,
	{Hat, Lever, Build, Box, Jump, DoubleJump, RealDoubleJump, Attack, Deflect, Jedi, Passive, Gas, Chokeable, AllEpisodes});

Playable yoda_ghost("yoda_ghost", "Yoda (Ghost)", 1200000, 0x7f1d10, 1.44f,
	{Lever, Build, Box, Jump, DoubleJump, YodaJump, RealDoubleJump, Attack, Deflect, Jedi, Passive, Gas, Chokeable, AllEpisodes});

Playable r2q5("r2q5", "R2-Q5", 100000, 0x7f1fa8, 1.0f,
	{Fly, Zapper, AstroZapper, Astro, Droid, Passive, Gas, Pushable, Zappable, AllEpisodes});

Playable hansolo_indy("hansolo_indy", "Indiana Jones", 50000, 0x7f20c0, 1.44f,
	{Hat, Lever, Build, Box, Jump, Dive, Attack, Shoot, Grapple, Chokeable, AllEpisodes});

Playable skeleton("skeleton", "Skeleton", 3000, 0x7f20d0, 1.2f,
	{Extratoggle});

Playable buzzdroid("buzzdroid", "Buzz droid", 1500, 0x7f20a0, 1.2f,
	{Extratoggle, Attack, Droid, Gas, Pushable, Zappable});

Playable trainingremote("trainingremote", "Training Remote", 2000, 0x7f1d98, 1.05f,
	{Extratoggle, Hovering, FakeShoot, Droid, Gas});

Playable engineer("engineer", "Rebel Engineer", 8000, 0x0, 1.2f,
	{Extratoggle, Lever, Build, Box, Jump, SlightlyBetterJump, Attack, Shoot, Grapple, Chokeable, Trickable});

Playable naffdroid1("naffdroid1", "droid 1", 1500, 0x7f1cb8, 0.6f,
	{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

Playable naffdroid2("naffdroid2", "droid 2", 1500, 0x7f1cc0, 0.6f,
	{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

Playable naffdroid3("naffdroid3", "droid 3", 1500, 0x7f1cc8, 0.4f,
	{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

Playable naffdroid4("naffdroid4", "droid 4", 1500, 0x7f1cd0, 0.6f,
	{Extratoggle, Shoot, Droid, Passive, Gas, Pushable, Zappable});

Playable womprat("womprat", "Womp Rat", 25000, 0x7f1d00, 1.8f,
	{Extratoggle, Passive});

Playable mousedroid("mousedroid", "Mouse droid", 3000, 0x7f1cd8, 2.4f,
	{Extratoggle, Droid, Passive, Gas, Pushable, Zappable});

Playable imperialengineer("imperialengineer", "imperial Engineer", 9000, 0x0, 1.2f,
	{Extratoggle, Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable hanincarbonite("hanincarbonite", "Han Solo (frozen in carbonite)", 5000, 0x0, 0.75f,
	{Extratoggle});

Playable atat_driver("atat_driver", "AT-AT Driver", 25000, 0x0, 1.2f,
	{Extratoggle, Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable scouttrooper("scouttrooper", "Scout Trooper", 16000, 0x0, 1.2f,
	{Extratoggle, Lever, Build, Box, Jump, Flop, Attack, Shoot, Grapple, Imperial, Chokeable, Trickable, Storm});

Playable newanakinspod("newanakinspod", "Anakin's Pod", 20000, 0x7f21e0, 1.2f,
	{Vehicle});

Playable naboostarfighter("naboostarfighter", "Naboo Starfighter", 12000, 0x7f20b0, 1.2f,
	{Vehicle, Attack, Shoot, Tow});

Playable anakinsspeeder("anakinsspeeder", "Anakin's Speeder", 15000, 0x7f21f0, 1.2f,
	{Vehicle, Attack, Shoot});

Playable newrepublicgunship("newrepublicgunship", "Republic Gunship", 18000, 0x7f1f78, 1.2f,
	{Vehicle, Attack, Shoot, Tow});

Playable jedistarfighter_yellow_ep3("jedistarfighter_yellow_ep3", "jedi Starfighter (Yellow)", 10000, 0x7f1f40, 1.2f,
	{Vehicle, Attack, Shoot});

Playable jedistarfighter_red_ep3("jedistarfighter_red_ep3", "jedi Starfighter (Red)", 10000, 0x7f1f48, 1.2f,
	{Vehicle, Attack, Shoot});

Playable xwing("xwing", "X-wing", 25000, 0x7f1fb0, 1.2f,
	{Vehicle, Attack, Shoot});

Playable ywing("ywing", "Y-wing", 25000, 0x7f1e38, 1.2f,
	{Vehicle, Attack, Shoot});

Playable snowspeeder("snowspeeder", "Snowspeeder", 20000, 0x7f1fc0, 1.2f,
	{Vehicle, Attack, Shoot, Tow});

Playable millenniumfalcon("millenniumfalcon", "Millennium Falcon", 40000, 0x7f1ec0, 1.2f,
	{Vehicle, Attack, Shoot});

Playable sebulbaspod("sebulbaspod", "Sebulba's Pod", 20000, 0x7f21c0, 1.2f,
	{Vehicle});

Playable zamsspeeder("zamsspeeder", "Zam's Airspeeder", 24000, 0x7f2200, 1.2f,
	{Vehicle, Attack, Shoot});

Playable droidtrifighter("droidtrifighter", "droid Trifighter", 28000, 0x7f2210, 1.2f,
	{Vehicle, Attack, Shoot});

Playable vulturedroid("vulturedroid", "Vulture droid", 30000, 0x7f2208, 1.2f,
	{Vehicle, Attack, Shoot});

Playable clonearc("clonearc", "Clone Arcfighter", 33000, 0x7f20a8, 1.2f,
	{Vehicle, Attack, Shoot});

Playable tiefighter("tiefighter", "TIE Fighter", 35000, 0x7f1e58, 1.2f,
	{Vehicle, Attack, Shoot, TieDoor});

Playable tieinterceptor("tieinterceptor", "TIE Interceptor", 40000, 0x7f1fc8, 1.2f,
	{Vehicle, Attack, Shoot, TieDoor});

Playable tiefighterdarth("tiefighterdarth", "TIE Fighter (Darth Vader)", 50000, 0x7f1e50, 1.2f,
	{Vehicle, Attack, Shoot, TieDoor});

Playable tiebomber("tiebomber", "TIE Bomber", 60000, 0x7f1e40, 1.2f,
	{Vehicle, Attack, Shoot, TieDoor});

Playable imperialshuttle("imperialshuttle", "imperial Shuttle", 25000, 0x7f1fd0, 1.2f,
	{Vehicle, Attack, Shoot});

Playable slave1("slave1", "Slave 1", 100000, 0x7f1e30, 1.2f,
	{Vehicle, Attack, Shoot, AllEpisodes});

Playable newanakinspod_green("newanakinspod_green", "Anakin's Pod (Green)", 20000, 0x7f21b8, 1.2f,
	{Vehicle, Vgreen});

Playable naboostarfighter_lime("naboostarfighter_lime", "Naboo Starfighter (Green)", 12000, 0x7f20b8, 1.2f,
	{Vehicle, Vgreen, Attack, Shoot, Tow});

Playable anakinsspeeder_green("anakinsspeeder_green", "Anakin's Speeder (Green)", 15000, 0x7f21f8, 1.2f,
	{Vehicle, Vgreen, Attack, Shoot});

Playable newrepublicgunship_green("newrepublicgunship_green", "Republic Gunship (Green)", 18000, 0x7f1f80, 1.2f,
	{Vehicle, Vgreen, Attack, Shoot, Tow});