#pragma once

#define LEV out + "/LEVELS/"

#define TPM LEV + "EPISODE_I/"
#define CLN LEV + "EPISODE_II/"
#define STH LEV + "EPISODE_III/"
#define ANH LEV + "EPISODE_IV/"
#define EMP LEV + "EPISODE_V/"
#define JDI LEV + "EPISODE_VI/"

#define EXE out + "/LEGOStarWarsSaga.exe"
#define ENGLISH out + "/STUFF/TEXT/ENGLISH.TXT"
#define CHR out + "/CHARS/"


#define TNG out + "/STUFF/THINGS_PC.GSC"
#define PTL out + "/STUFF/GENERAL.PTL"
#define PT1 out + "/STUFF/GENERAL_LSW1.PTL"
#define PTC out + "/STUFF/CHAR.PTL"
#define PC1 out + "/STUFF/CHAR_LSW1.PTL"

#define Build &Playable::build
#define Lever &Playable::lever
#define Box &Playable::box //also for riding stuff

#define Jedi &Playable::jedi
#define Sith &Playable::sith
#define Choke &Playable::choke
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
#define YodaJump &Playable::yodaJump
#define GunganJump &Playable::gunganJump
#define Dive &Playable::dive
#define Flop &Playable::flop
#define SlightlyBetterJump &Playable::slightlyBetterJump

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

#define Droid &Playable::droid
#define Gas &Playable::gas
#define Pushable &Playable::pushable
#define Zappable &Playable::zappable
#define Storm &Playable::storm
#define Chokeable &Playable::chokeable
#define Trickable &Playable::trickable

#define Active &Playable::active

#define FakeShoot &Playable::fakeshoot

#define Tow &Playable::tow
#define TieDoor &Playable::tiedoor

#define Extratoggle &Playable::extratoggle
#define Vehicle &Playable::vehicle
#define Vgreen &Playable::vgreen

#define LeiaAlt &Playable::leiaAlt
#define LandoAlt &Playable::landoAlt
#define LukeAlt &Playable::lukeAlt

#define NoLevel &Playable::noLevel
#define AllEpisodes &Playable::allEpisodes
#define Fake &Playable::fake

enum LogicType { casual, glitched, superGlitched };



/*
 

	1-1:
	AI gets stuck on force ledge

	1-2:
	AI won't single jump over bridge

	1-5:
	bad jump 2nd room beginning
	wicket freezes in theed 2

	2-3:
	3po AI

	3-1:
	have spinners only spawn in correct mode

	3-2:
	r2 not following in tall room

	3-6:
	room 1 AI

	4-1:
	skip midtro sheild with force choke
	free rebel friend with bomb

	4-3:
	more bomb skip stuff

	4-4:
	midtro panel icon
	Ben AI when not Jedi
	backtracking to hat room with other hat
	turnstile room hat needs grapple

	5-5:
	dv1 & dvt & dv4 fett casual
	dvt glitched skip fan
	dv1, dv3 - fix ai

	5-6:
	add bool for r2 door
	BTS
	Boba freezes at door
	go OOB for 3po
	outside - use 3po panel with flyer
	puts you by shop?

	6-3:
	check jump height

	6-4:
	try skipping bunker elevator with oob

	BHM panels


	OIL GLITCH	
	resist_zap
	flutters can do OOB
	test everything with training remote

	fix special character for padme
	fix name length limit for scp
	
	create error messages for missing files
	check playable attributes in log

	add seed to gui

	fix speed variable for ROLLS
	bespin guard - slightly faster than 1.2

	*/