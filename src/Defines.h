#pragma once

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

//{0} number
//{1} attackpattern
//[2] extraCondition
//{3} appendix
#define scpFun(name, condition, action)                                                                                \
	"state " name "{0} {{\n"                                                                                       \
	"\tConditions {{\n"                                                                                            \
	"\t\t" condition "\n"                                                                                          \
	"\t\t{1}\n"                                                                                                    \
	"\t}}\n"                                                                                                       \
	"\tActions {{\n"                                                                                               \
	"\t\t" action "\n"                                                                                             \
	"\t\t{2}\n"                                                                                                    \
	"\t}}\n"                                                                                                       \
	"}}\n"                                                                                                         \
	"{3}\n"

#define funcNoRef(name, condition, action)                                                                             \
	"state " name "{0} {{\n"                                                                                       \
	"\tConditions {{\n"                                                                                            \
	"\t\t" condition "\n"                                                                                          \
	"\t}}\n"                                                                                                       \
	"\tActions {{\n"                                                                                               \
	"\t\t" action "\n"                                                                                             \
	"\t}}\n"                                                                                                       \
	"}}\n"

//{0} number
//{1} condition
//{2} action
#define func(name, condition, action)                                                                                  \
	"state " name "{0} {{\n"                                                                                       \
	"\tReferenceScript {{\n"                                                                                       \
	"\t\tScript={1}\n"                                                                                             \
	"\t\tSource=Global\n"                                                                                          \
	"\t\tReturnState=" name "{0}\n"                                                                                \
	"\t\tConditions {{\n"                                                                                          \
	"\t\t}}\n"                                                                                                     \
	"\t}}\n"                                                                                                       \
	"\tConditions {{\n"                                                                                            \
	"\t\t" condition "\n"                                                                                          \
	"\t}}\n"                                                                                                       \
	"\tActions {{\n"                                                                                               \
	"\t\t" action "\n"                                                                                             \
	"\t}}\n"                                                                                                       \
	"}}\n"

#define funcCustom(name, referenceScript, condition, action)                                                           \
	"state " name " {{\n"                                                                                          \
	"\tReferenceScript {{\n"                                                                                       \
	"\t\tScript=" referenceScript "\n"                                                                             \
	"\t\tSource=Global\n"                                                                                          \
	"\t\tReturnState=" name "\n"                                                                                   \
	"\t\tConditions {{\n"                                                                                          \
	"\t\t}}\n"                                                                                                     \
	"\t}}\n"                                                                                                       \
	"\tConditions {{\n"                                                                                            \
	"\t\t" condition "\n"                                                                                          \
	"\t}}\n"                                                                                                       \
	"\tActions {{\n"                                                                                               \
	"\t\t" action "\n"                                                                                             \
	"\t}}\n"                                                                                                       \
	"}}\n"

//candefend????
enum LogicType { casual, glitched, superGlitched };

enum PanelType { AstroPanel, ProtoPanel, BountyPanel, ImperialPanel };

enum DispenserType { RandomHat, LeiaHat, Fedora, TopHat, BaseballHat, StormtrooperHat, BountyHat, DroidPanel };

enum enemyScp { chatting, sniper, storm, attack, block, spawnattack, patrol, NONE };

enum attackType { nAttack, nBlock, nSnipe };

struct coord {
	unsigned int ln = 1;
	unsigned int col = 1;
};

/*


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
    jawa escort t-poses
    remove KeepWeaponOut
	last room - super jump
    backflip 50hz for no grapple

4-2:
disguised clone doesn't work on ledges
nonjumpers get stuck on top of hill in A
sj directly into elevator

	4-4:
	Ben AI when not Jedi

	5-5:
	dv1 and dv3 ai

	5-6:
	sometimes puts you by shop?


	bhm enemies


	oil glitch
	test everything with training remote

	fix special character for padme
	fix name length limit for scp

	check playable attributes in log

	allow custom seeds

	make unlocks dependent on residents

	fix spawnattack
	*/
