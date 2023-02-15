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


#define TNG out + "/STUFF/THINGS_PC.GSC"
#define PTL out + "/STUFF/GENERAL.PTL"
#define PT1 out + "/STUFF/GENERAL_LSW1.PTL"
#define PTC out + "/STUFF/CHAR.PTL"
#define PC1 out + "/STUFF/CHAR_LSW1.PTL"

#define Negotiations allLevels[0]
#define Invasion allLevels[1]
#define EscapeNaboo allLevels[2]
#define Podrace allLevels[3]
#define Theed allLevels[4]
#define Maul allLevels[5]

#define BHP allLevels[6]
#define Kamino allLevels[7]
#define Factory allLevels[8]
#define JediBattle allLevels[9]
#define Gunship allLevels[10]
#define Dooku allLevels[11]

#define Coruscant allLevels[12]
#define Chancellor allLevels[13]
#define Grievous allLevels[14]
#define Kashyyyk allLevels[15]
#define Ruin allLevels[16]
#define Vader allLevels[17]

#define SecretPlans allLevels[18]
#define Jundland allLevels[29]
#define Spaceport allLevels[20]
#define Princess allLevels[21]
#define DSE allLevels[22]
#define RebelAttack allLevels[23]

#define Hoth allLevels[24]
#define EchoBase allLevels[25]
#define FalconFlight allLevels[26]
#define Dagobah allLevels[27]
#define CCT allLevels[28]
#define Bespin allLevels[29]

#define Jabbas allLevels[30]
#define Carkoon allLevels[31]
#define Showdown allLevels[32]
#define Endor allLevels[33]
#define Destiny allLevels[34]
#define ITDS allLevels[35]

#define Anakinsflight allLevels[36]
#define ANewHope allLevels[37]

enum LogicType { casual, glitched, superGlitched };



/*


bounties

character
bobafett greedo ig88 4lom bossk dengar
quigonjinn amidala jarjarbinks macewindu kitfisto luminara kiadimundi rebelscum shaakti clone_ep3_sand r2d2 benkenobi chewbacca princessleia admiralackbar yoda c3po landocalrissian lukeskywalker_tatooine hansolo


noLevel

character


gonkdroid pkdroid

allLevel

character


ig88 dengar 4lom ghostbenkenobi anakin_ghost yoda_ghost r2q5 hansolo_indy slave1




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
	shoot boba from other skiff

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