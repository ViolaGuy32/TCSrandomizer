#pragma once
#include "pch.h"

#define LEV out + "\\LEVELS\\"

#define TPM LEV + "EPISODE_I\\"
#define CLN LEV + "EPISODE_II\\"
#define STH LEV + "EPISODE_III\\"
#define ANH LEV + "EPISODE_IV\\"
#define EMP LEV + "EPISODE_V\\"
#define JDI LEV + "EPISODE_VI\\"

#define EXE out + "\\LEGOStarWarsSaga.exe"
#define ENGLISH out + "\\STUFF\\TEXT\\ENGLISH.TXT"
#define CHR out + "\\CHARS\\"
#define SCR out + "\\SCRIPTS\\"

#define normalAttack                                                                                                   \
	{ "", "EngageOpponent \"goalrange 1.5\" \"firerange 3\"", "" }

#define normalBlock                                                                                                    \
	{ "", "EngageOpponent \"static\" \"firerange 3\"", "" }

#define retreat(exit) "if GotOpponent == 0 goto " exit
#define target(att) "if GotOpponent == 1 goto " exit
#define outOfRange(exit, range) "if OpponentRange > " range " goto " exit
#define underCover(exit) "if PartyUnderCover == 1 goto " exit
#define trigger(area, exit) "if EitherPlayerInTriggerArea " area "goto" exit
//{0} number
//{1} attackpattern
//[2] extraCondition
//{3} appendix
#define scpFun(name, condition, action)                                                                                \
	"state " name "{0} {{\n"                                                                                           \
	"\tConditions {{\n"                                                                                                \
	"\t\t" condition "\n"                                                                                              \
	"\t\t{1}\n"                                                                                                        \
	"\t}}\n"                                                                                                           \
	"\tActions {{\n"                                                                                                   \
	"\t\t" action "\n"                                                                                                 \
	"\t\t{2}\n"                                                                                                        \
	"\t}}\n"                                                                                                           \
	"}}\n"                                                                                                             \
	"{3}\n"

#define funcNoRef(name, condition, action)                                                                             \
	"state " name "{0} {{\n"                                                                                           \
	"\tConditions {{\n"                                                                                                \
	"\t\t" condition "\n"                                                                                              \
	"\t}}\n"                                                                                                           \
	"\tActions {{\n"                                                                                                   \
	"\t\t" action "\n"                                                                                                 \
	"\t}}\n"                                                                                                           \
	"}}\n"

//{0} number
//{1} condition
//{2} action
#define func(name, condition, action)                                                                                  \
	"state " name "{0} {{\n"                                                                                           \
	"\tReferenceScript {{\n"                                                                                           \
	"\t\tScript={1}\n"                                                                                                 \
	"\t\tSource=Global\n"                                                                                              \
	"\t\tReturnState=" name "{0}\n"                                                                                    \
	"\t\tConditions {{\n"                                                                                              \
	"\t\t}}\n"                                                                                                         \
	"\t}}\n"                                                                                                           \
	"\tConditions {{\n"                                                                                                \
	"\t\t" condition "\n"                                                                                              \
	"\t}}\n"                                                                                                           \
	"\tActions {{\n"                                                                                                   \
	"\t\t" action "\n"                                                                                                 \
	"\t}}\n"                                                                                                           \
	"}}\n"

#define funcCustom(name, referenceScript, condition, action)                                                           \
	"state " name " {{\n"                                                                                              \
	"\tReferenceScript {{\n"                                                                                           \
	"\t\tScript=" referenceScript "\n"                                                                                 \
	"\t\tSource=Global\n"                                                                                              \
	"\t\tReturnState=" name "\n"                                                                                       \
	"\t\tConditions {{\n"                                                                                              \
	"\t\t}}\n"                                                                                                         \
	"\t}}\n"                                                                                                           \
	"\tConditions {{\n"                                                                                                \
	"\t\t" condition "\n"                                                                                              \
	"\t}}\n"                                                                                                           \
	"\tActions {{\n"                                                                                                   \
	"\t\t" action "\n"                                                                                                 \
	"\t}}\n"                                                                                                           \
	"}}\n"

//candefend????
enum LogicType { casual, glitched, superGlitched };

enum PanelType { AstroPanel, ProtoPanel, BountyPanel, ImperialPanel };

enum DispenserType { RandomHat, LeiaHat, Fedora, TopHat, BaseballHat, StormtrooperHat, BountyHat, DroidPanel };

enum enemyScp { chatting, sniper, storm, attack, block, spawnattack, patrol, NONE, special };

enum attackType { nAttack, nBlock, nSnipe };

struct coord {
	unsigned int ln = 1;
	unsigned int col = 1;

	friend std::ostream& operator<<(std::ostream& out, const coord& lncol) {
		return out << '(' << lncol.ln << ", " << lncol.col << ')';
	}
};

/*

fix panel color

New skips:
DVT


bounties don't work if characters are not randomized

shaddowed scipts

use scripts from bonuses and arcade maps

modify conditions in redirrect

BLOCK_CHATTING

story characters interfere with bhm
specialscp additional actions

finish story sometimes puts you buy the shop

fix geonosian rename

have fixScript do normal scripts

returnstate uses update instead of vanillaupdate
remove returning to locator for special scripts??
fix out.TXT

special scripts:
jawa (unnaught)
gamorreanguard
impguard
bat

floating characters don't finish spawning from grapple

defend and block are DIFFERENT

 sarlacc_a/galley ?????
check geonosians in Jedi Battle
 snipers not working.
	1-1:
	LAZYDROID not working

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
    rebel friend enemies keep falling off.
    CHECK GIT TO REVERT PLANSTHING!!!!!
	jawa escort t-poses
	remove KeepWeaponOut
	jump boost crane room

4-2:
dropout intro
hill guys don't infinitely spawn
disguised clone doesn't work on ledges
nonjumpers get stuck on top of hill in A
sj directly into elevator
second to last room ledge trooper won't attack


	4-3:
	intro drops out
	SET MESSAGE
	they don't jump off the ledge
	force push through the sensors
    A ledge fails spawns (super battle droid blocks it?)
	cleaClearTakeOverTarget?
    B deathstartrooper spawnattack t-poses
    B takeover kaminodroid is stuck
    spy spawns don't always work 
hangerattack is broken
    bodyguards follow me into block pushing room
	bridgetroops melee "followcharacter

	4-4:
	Ben AI when not Jedi
	tie fighter minigame has 4 characters

	5-1:
	fix scaling


	5-5:
	dv1 and dv3 ai
	dv1 casual

	5-6:
	sometimes puts you by shop?

	6-4:
	double jump right side

	bhm enemies


	oil glitch
	test everything with training remote

	fix special character for padme
	fix name length limit for scp


	allow custom seeds

	make unlocks dependent on residents

	fix spawnattack


















	active npcs:

	passive npcs:

	*/
