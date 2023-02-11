#pragma once

#define LEV out + "/LEVELS/"
#define TPM LEV + "EPISODE_I/"
#define CLN LEV + "EPISODE_II/"
#define STH LEV + "EPISODE_III/"
#define ANH LEV + "EPISODE_IV/"
#define EMP LEV + "EPISODE_V/"
#define JDI LEV + "EPISODE_VI/"
#define EXE out + "/LEGOStarWarsSaga.exe"
#define TNG out + "/STUFF/THINGS_PC.GSC"
#define PTL out + "/STUFF/GENERAL.PTL"
#define PT1 out + "/STUFF/GENERAL_LSW1.PTL"
#define PTC out + "/STUFF/CHAR.PTL"
#define PC1 out + "/STUFF/CHAR_LSW1.PTL"

enum LogicType { casual, glitched, superGlitched };

/*

	TODO
	---fix Indiana Jones
	make code to check stringPointer
	make special function for TR

	1-1:
	record 50hz jump
	AI gets stuck on force ledge

	1-2:
	AI won't single jump over bridge

	1-5:
	bad jump 2nd room beginning

	1-6:
	investigate double ghost in casual

	2-3:
	3po AI
	slow 3po

	3-1:
	have spinners correct mode

	3-2:
	?r2 following in tall room

	3-6:
	room 1 AI
	room 3 FP ???---

	4-3:
	more bomb skip stuff

	4-4:
	Ben AI when not Jedi

	6-2:
	check many seeds for SJ

	6-3:
	check jump height

	bounty hunter missions:
	-Kamino with jarjar

	flutters can do OOB!

	thread or wxYeild
	use NOWEAPON for stuff
	minikit spinner colors
	fix file rename when enemy is same as player
	training remote buttons
	Slave 1 unlocked?

	fix double file rename problem
	resist_zap
	match buildable minikits to product
	fix level streaming for faster loads
	use line replace function
	fix special character for padme
	create error messages for missing files
	only open bms if not unpacked
	delete pak files individually
	fix speed variable ROLLS
	double check watto
	test everything with training remote
	check playable attributes in log
	fix name length limit for scp

	bespin guard - slightly faster than 1.2 

	*/