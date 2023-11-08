#pragma once
#include "Defines.h"
#include "pch.h"

struct Level;

struct scpInfoArr {
	const char* conditions = "";
	const char* actions    = "";
	const char* appendix   = "";
};

struct scpInfo {
	std::string conditions;
	std::string actions;
	std::string appendix;
};

///*constexpr */uint64_t p(int x) {
//	return std::pow(2, x);
//}

const uint64_t Hat                = 0x1;
const uint64_t Lever              = 0x2;
const uint64_t Build              = 0x4;
const uint64_t Box                = 0x8;
const uint64_t Jump               = 0x10;
const uint64_t DoubleJump         = 0x20;
const uint64_t HighJump           = 0x40;
const uint64_t YodaJump           = 0x80;
const uint64_t ExtraHighJump      = 0x100;
const uint64_t RealDoubleJump     = 0x200;
const uint64_t HighDoubleJump     = 0x400;
const uint64_t GunganJump         = 0x800;
const uint64_t SlightlyBetterJump = 0x1000;
const uint64_t SlightlyHigherJump = 0x2000;
const uint64_t Dive               = 0x4000;
const uint64_t Flop               = 0x8000;
const uint64_t Hovering           = 0x10000;
const uint64_t Fly                = 0x20000;
const uint64_t Flutter            = 0x40000;
const uint64_t Fett               = 0x80000;
const uint64_t Attack             = 0x100000;
const uint64_t Shoot              = 0x200000;
const uint64_t Grapple            = 0x400000;
const uint64_t FakeShoot          = 0x800000;
const uint64_t Zapper             = 0x1000000;
const uint64_t AstroZapper        = 0x2000000;
const uint64_t Jedi               = 0x4000000;
const uint64_t Sith               = 0x8000000;
const uint64_t Choke              = 0x10000000;
const uint64_t Lightning          = 0x20000000;
const uint64_t Ghost              = 0x40000000;
const uint64_t Saber              = 0x80000000;
const uint64_t Deflect            = 0x100000000;
const uint64_t Imperial           = 0x200000000;
const uint64_t Astro              = 0x400000000;
const uint64_t Proto              = 0x800000000;
const uint64_t Droid              = 0x1000000000;
const uint64_t Passive            = 0x2000000000;
const uint64_t Gas                = 0x4000000000;
const uint64_t Bounty             = 0x8000000000;
const uint64_t Hatch              = 0x10000000000;
const uint64_t Tall               = 0x20000000000;
const uint64_t Pushable           = 0x40000000000;
const uint64_t Chokeable          = 0x80000000000;
const uint64_t Lightningable      = 0x100000000000;
const uint64_t Trickable          = 0x200000000000;
const uint64_t Zappable           = 0x400000000000;
const uint64_t ResistZap          = 0x800000000000;
const uint64_t Storm              = 0x10000000000000;
const uint64_t Active             = 0x20000000000000;
const uint64_t LeiaAlt            = 0x40000000000000;
const uint64_t LandoAlt           = 0x80000000000000;
const uint64_t LukeAlt            = 0x100000000000000;
const uint64_t Extratoggle        = 0x200000000000000;
//const uint64_t Baddy              = 0x400000000000000;
const uint64_t DefaultCharacter   = 0x800000000000000;
const uint64_t Fake               = 0x1000000000000000;
const uint64_t NoLevel            = 0x2000000000000000;
const uint64_t AllEpisodes        = 0x4000000000000000;

const uint64_t Vehicle = 0x8000000000000000;
//These are exclusive to ships so they can reuse flags.
const uint64_t Tow     = 0x2;
const uint64_t TieDoor = 0x4;
const uint64_t Vgreen  = 0x8;

struct Playable {
	std::string name     = "";
	std::string realName = "";
	//std::string vanillaName = "";
	float speed = 1.2f;
	Level* lev;
	size_t address     = 0;
	int price       = 0;
	bool alwaysTrue = true; //lol
	bool StoryMode = false;

	//std::string attackPattern;

	uint64_t att = 0x0; //Individual bits are flags for different attributes.

	std::unordered_map<enemyScp, std::string> enemyChart;
	scpInfo nAttackInfo;
	scpInfo nBlockInfo;
	scpInfo nSnipeInfo;

	Playable(std::string myName, std::string myRealName, int myPrice, int myAddress, float mySpeed,
		uint64_t myAttributes, std::unordered_map<enemyScp, std::string> myChart = {}/*, scpInfoArr myAtInfo = {},
		scpInfoArr myBlockInfo = {}, scpInfoArr mySnipeInfo = {}*/);

	bool check(uint64_t a);

};
