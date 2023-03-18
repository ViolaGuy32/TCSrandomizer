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

//
//#define TNG out + "/STUFF/THINGS_PC.GSC"
//#define PTL out + "/STUFF/GENERAL.PTL"
//#define PT1 out + "/STUFF/GENERAL_LSW1.PTL"
//#define PTC out + "/STUFF/CHAR.PTL"
//#define PC1 out + "/STUFF/CHAR_LSW1.PTL"

#define Build &Playable::build
#define Lever &Playable::lever
#define Box &Playable::box //also for riding stuff

#define Jedi &Playable::jedi
#define Sith &Playable::sith
#define Choke &Playable::choke
#define Lightning &Playable::lightning
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
#define SlightlyHigherJump &Playable::slightlyHigherJump

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
#define Lightningable &Playable::lightningable
#define ResistZap &Playable::resistZap
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

	2-3:
	3po won't always follow onto turn things

	3-1:
	have spinners only spawn in correct mode

	3-2:
	r2 not following in tall room

	3-6:
	room 1 AI

	4-1:
	last room - super jump

	4-4:
	Ben AI when not Jedi

	5-5:
	dv1 and dv3 ai

	5-6:
	sometimes puts you by shop?


	oil glitch
	test everything with training remote

	fix special character for padme
	fix name length limit for scp
	
	check playable attributes in log

	allow custom seeds

	*/