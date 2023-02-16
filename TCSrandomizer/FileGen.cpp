#include "pch.h"

#include "Defines.h"
#include "FileGen.h"
#include "OtherStuff.h"
#include "App.h"

extern std::string out;
extern std::string vanillaDirectory;

void fileGen() {
	//coppies the game files and removes cutscenes

	logR("\n\t\t\t\t\tGenerating files. . .");
	wxLogStatus("Generating files. . .");

	std::filesystem::remove_all(out);
	std::filesystem::copy(vanillaDirectory, out,
		std::filesystem::copy_options::recursive
		| std::filesystem::copy_options::overwrite_existing);

	//delete individually
	std::string cmd = ("files\\quickbms.exe -F \"*.DAT\" -o files\\ttgames.bms " +
		out + " " + out);
	system(cmd.c_str());

	cmd = out + "/EPISODE_I.DAT";
	std::remove(cmd.c_str());
	cmd = out + "/EPISODE_II.DAT";
	std::remove(cmd.c_str());
	cmd = out + "/EPISODE_III.DAT";
	std::remove(cmd.c_str());
	cmd = out + "/EPISODE_IV.DAT";
	std::remove(cmd.c_str());
	cmd = out + "/EPISODE_V.DAT";
	std::remove(cmd.c_str());
	cmd = out + "/EPISODE_VI.DAT";
	std::remove(cmd.c_str());
	cmd = "del /S " + out + "\\*PAK";
	system(cmd.c_str());

	//makes sure it has the GOG exe
	std::filesystem::copy("files/LEGOStarWarsSaga.exe", out,
		std::filesystem::copy_options::overwrite_existing);

	logR("\n\t\t\t\t\tPatching. . .");
	wxLogStatus("Patching. . .");

	//int freePlay[] = {
	//	//cutscene=
	//	0x55f21,
	//	0x56041,
	//	0x653d5,
	//	0x654c0,
	//	//0x55f4c,

	//	//status
	//	0x175d2e,
	//	0x17a5cf,

	//	//level
	//	//0x14c85,
	//	0x15c696, //breaks invasion cs

	//	//loadlevel
	//	//0xe5636,

	//	//negotiations in-game intro
	//	0x14c85

	//	//0xe0137
	//};

	//for (int i : freePlay)
	//	binaryWrite(EXE, "0f", i);  


	//removes cutscenes

	//---DOOKU OUTRO
	//---VADER OUTRO
	//SPACEPORT MIDTRO?
	//---ep5 finish story
	//test princess midtro
	txtIns(LEV + "AREAS.TXT", "//", {
		//29, 30, //negotiations
		34, 45, 46, 52, 63, 64, 65, 70, 94, 95, 96, 97, 98, 102, 103, 114,
		115, 116, 123, 134, 182, 188, 201, 202, 208, 209, 220, 221,
		222,  //factory
		239, 241, 278,
		//281, //dooku
		345, 346, 383, 384, 398,
		444,  //anh demo
		456,
		457,  //plans
		462, 463,
		474,  //jundland
		480,
		492,  //spaceport
		498, 499, 500, 512,
		513,  //princess
		//530, //dse
		535, 546, 547, 548, 549, 554, 555, 600, 601, 602, 603, 609,
		//621, //echo base
		626, 627, 638, 643, 644, 658, 664, 675, 679, 690,
		691,  //bespin
		695,
		//737, 738, //jabbas
		743, 744,
		755,  //carkoon
		759,
		783,  //endor
		788, 799, 812, 820, 821, 877, 881, 882
		});

		//removes FP checks
	binaryWrite(EXE, "0f", 0xe1ffe);  //kamino
	binaryWrite(EXE, "0f", 0xdf0f2);  //jedi battle
	binaryWrite(EXE, "0f", 0xe7c30);  //falconflight
	binaryWrite(EXE, "0f", 0xe7e9e);  //cct
	binaryWrite(EXE, "0f", 0xe9ba6);  //hoth
	binaryWrite(EXE, "0f", 0xe33a1);  //grievous
	binaryWrite(EXE, "0f", 0xeaf5f);  //destiny
	binaryWrite(EXE, "0f", 0x39475);  //vader

	//diverts outro pointer to status screen
	binaryWrite(EXE, "bcb087", 0xdab15);  //podrace original
	hexWrite(EXE, "jabbaspalace_status", 0x35A450);

	//speeds up cutscenes to 1 frame
	txtIns(out + "/CUT/EPISODEI/EP1_FAILEDNEG_INTRO1.TXT", "//", {9});
	txtIns(out + "/CUT/EPISODEI/EP1_FAILEDNEG_INTRO1.TXT", "500000", {{1, 7}}, 2);
	txtIns(out + "/CUT/EPISODEI/EP1_FAILEDNEG_INTRO1.TXT", "negotiations_a",
		{{10, 13}}, 20);

	txtIns(out + "/CUT/EPISODEII/EP2_KAMINO_DISCOVERJANGO.TXT", "//", {8});
	txtIns(out + "/CUT/EPISODEII/EP2_KAMINO_DISCOVERJANGO.TXT", "500000",
		{{1, 7}}, 2);

	txtIns(out + "/CUT/EPISODEII/EP2_COUNTDOOKU_DOOKUFIGHT.TXT", "//", {7});
	txtIns(out + "/CUT/EPISODEII/EP2_COUNTDOOKU_DOOKUFIGHT.TXT", "500000",
		{{1, 7}}, 2);
	txtIns(out + "/CUT/EPISODEII/EP2_COUNTDOOKU_OUTRO.TXT", "//", {8});
	txtIns(out + "/CUT/EPISODEII/EP2_COUNTDOOKU_OUTRO.TXT", "fpsec 500000\n",
		{1});

	txtIns(out + "/CUT/EPISODEIV/MOSEISLEY_MIDTRO.TXT", "//", {1});
	txtIns(out + "/CUT/EPISODEIV/MOSEISLEY_MIDTRO.TXT", "fpsec 500000\n", {2});

	//finish story
	txtIns(out + "/CUT/EPISODEI/EP1_EPISODECOMPLETE_CELEBRATIONS.TXT", "//",
		{13});
	txtIns(out + "/CUT/EPISODEI/EP1_EPISODECOMPLETE_CELEBRATIONS.TXT", "500000",
		{{1, 7}}, 2);

	txtIns(out + "/CUT/EPISODEII/EP2_ENDING1.TXT", "//", {13});
	txtIns(out + "/CUT/EPISODEII/EP2_ENDING1.TXT", "500000", {{1, 7}}, 2);
	txtIns(out + "/CUT/EPISODEII/EP2_ENDING2.TXT", "500000", {{1, 7}}, 2);

	txtIns(out + "/CUT/EPISODEIII/EP3_EPISODE_OUTRO1.TXT", "//", {14});
	txtIns(out + "/CUT/EPISODEIII/EP3_EPISODE_OUTRO1.TXT", "500000", {{1, 7}}, 2);
	txtIns(out + "/CUT/EPISODEIII/EP3_EPISODE_OUTRO2.TXT", "500000", {{1, 7}}, 2);
	txtIns(out + "/CUT/EPISODEIII/EP3_EPISODE_OUTRO3.TXT", "500000", {{1, 7}}, 2);

	txtIns(out + "/CUT/EPISODEIV/DEATHSTARESCAPE_INTRO.TXT", "//", {7});
	txtIns(out + "/CUT/EPISODEIV/DEATHSTARESCAPE_INTRO.TXT", "fpsec 500000\n",
		{1});

	txtIns(out + "/CUT/EPISODEIV/EPISODE4ENDING.TXT", "//", {1});
	txtIns(out + "/CUT/EPISODEIV/EPISODE4ENDING.TXT", "fpsec 500000\n", {4});

	txtIns(out + "/CUT/EPISODEV/HOTHESCAPE_INTRO.TXT", "//", {1});
	txtIns(out + "/CUT/EPISODEV/HOTHESCAPE_INTRO.TXT", "fpsec 500000\n", {2});

	txtIns(out + "/CUT/EPISODEV/EPISODE5ENDING.TXT", "//", {4});
	txtIns(out + "/CUT/EPISODEV/EPISODE5ENDING.TXT", "fpsec 500000\n", {1});

	txtIns(out + "/CUT/EPISODEVI/JABBASPALACE_INTRO1.TXT", "//", {3});
	txtIns(out + "/CUT/EPISODEVI/JABBASPALACE_INTRO1.TXT", "jabbaspalace_a",
		{{1, 13}}, 19);
	txtIns(out + "/CUT/EPISODEVI/JABBASPALACE_INTRO1.TXT", "fpsec 500000\n", {1});

	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING.TXT", "//", {4});
	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING.TXT", "fpsec 500000\n", {1});
	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING_PART1.TXT", "//", {2});
	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING_PART1.TXT", "fpsec 500000\n",
		{1});
	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING_PART2.TXT", "fpsec 500000\n",
		{1});

	/*

	//slow 3po
	negotiations
	dse ???
	echo base
	jabbas???

	//fix
	podorg mushroom

	*/

	//fix streaming
	txtIns(LEV + "ANAKINSFLIGHT/ANAKINSFLIGHT_C/ANAKINSFLIGHT_C.GIT", "status",
		{{1602, 41}}, 6);

	txtIns(LEV + "BONUS_GUNSHIP/BONUS_GUNSHIP_A/BONUS_GUNSHIP_A.TXT", "//", {5, 6});
	txtIns(LEV + "BONUS_GUNSHIP/BONUS_GUNSHIP_B/BONUS_GUNSHIP_B.TXT", "//", {7, 8, 9});
	txtIns(LEV + "BONUS_GUNSHIP/BONUS_GUNSHIP_B/BONUS_GUNSHIP_B.GIT",
		"newlevel=bonus_gunship_status", {{743, 18}}, 34);

	txtIns(TPM + "GUNGAN/GUNGAN_A/GUNGAN_A.TXT", "//", {42, 43, 503});
	txtIns(TPM + "GUNGAN/GUNGAN_A/AI/JARJARBINKS.SCP",
		"EitherPlayerInTriggerArea \"PlayCutScene\" == 1", {{5, 6}}, 58);
	txtIns(TPM + "GUNGAN/GUNGAN_A/AI/LEVEL.SCP", "//", {23});
	txtIns(TPM + "GUNGAN/GUNGAN_E/GUNGAN_E.TXT", "//", {34, 58});

	txtIns(TPM + "MAUL/MAUL_F/MAUL_F.TXT", "//", {1});
	txtIns(TPM + "MAUL/MAUL_F/AI/DARTHMAUL.SCP", "newlevel=maul_status", {{427, 18}}, 28);

	txtIns(TPM + "NEGOTIATIONS/NEGOTIATIONS_A/NEGOTIATIONS_A.TXT", "//", {7});
	txtIns(TPM + "NEGOTIATIONS/NEGOTIATIONS_C/NEGOTIATIONS_C.TXT",
		"negotiations_status", {{567, 9}}, 15);

	txtIns(TPM + "PALACERESCUE/RESCUE_E/RESCUE_E.TXT", "status", {{102, 16}}, 5);

	//mushroom
	txtIns(TPM + "PODRACE/PODRACE_A/PODRACE_A.TXT", "//", {10, 11, 12});

	txtIns(TPM + "PODRACE/PODRACE_B/PODRACE_B.TXT", "//", {11, 12, 13});
	txtIns(TPM + "PODRACE/PODRACE_C/PODRACE_C.TXT", "//", {11, 12, 13});
	binaryWrite(EXE, "DEAE4D",
		0xDB074);  //allows mushroom to collapse without cutscene

	txtIns(TPM + "PODSPRINT/PODSPRINT_A/PODSPRINT_A.TXT", "//",
		{20, 21, 22, 23, 24, 26, 27, 28, 30, 31, 34, 35});
	//check code
	txtIns(TPM + "PODSPRINT/PODSPRINT_A/AI/LEVEL.SCP", "alwaystrue == 1",
		{{73, 6}}, 45);
	txtIns(TPM + "PODSPRINT/PODSPRINT_A/AI/LEVEL.SCP", "//", {65, 74, 78});

	txtIns(TPM + "RETAKEPALACE/RETAKE_G/AI/LEVEL.SCP", "status", {{136, 34}}, 5);

	txtIns(CLN + "DOOKU/DOOKU_C/DOOKU_C.TXT", "//", {4});
	txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", "//", {215});
	//txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", { 5, 8 });
	txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", "alwaystrue == 1", {{222, 6}}, 56);
	//txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", "alwaystrue == 1", { {7, 6} },
	//48); txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", "\t\tsetstate
	//\"normalintrocomplete\"\n", { 18 });

	//txtIns(CLN + "FACTORY/FACTORY_G/FACTORY_G.TXT", { 1 });
	txtIns(CLN + "FACTORY/FACTORY_G/FACTORY_G.GIT", "Action", {{286, 2}}, 9);
	txtIns(CLN + "FACTORY/FACTORY_G/FACTORY_G.GIT",
		"completelevel \"newlevel=factory_status\"", {{287, 3}}, 8);

	txtIns(CLN + "GUNSHIP/GUNSHIP_A/GUNSHIP_A.TXT", "//", {5, 6});
	txtIns(CLN + "GUNSHIP/GUNSHIP_B/GUNSHIP_B.TXT", "//", {7, 8});
	txtIns(CLN + "GUNSHIP/GUNSHIP_B/GUNSHIP_B.GIT", "newlevel=gunship_status",
		{{882, 18}}, 33);

	txtIns(CLN + "JEDI/JEDI_B/JEDI_B.TXT", "//", {1});
	txtIns(CLN + "JEDI/JEDI_B/AI/LEVEL.SCP", "//", {101});

	txtIns(CLN + "KAMINO/KAMINO_A/KAMINO_A.TXT", "//", {1, 408});
	txtIns(CLN + "KAMINO/KAMINO_A/AI/KAMINO.SCP", "//", {69});
	txtIns(CLN + "KAMINO/KAMINO_A/AI/TAUNWE.SCP", "//", {23});
	txtIns(CLN + "KAMINO/KAMINO_A/AI/TAUNWE2.SCP", "//", {23});
	//txtIns(CLN + "KAMINO/KAMINO_C/KAMINO_C.TXT", { 1, 1181 }); //discover
	//jango txtIns(CLN + "KAMINO/KAMINO_C/AI/LEVEL.SCP",
	//"EitherPlayerInTriggerArea \"Jango\" == 1", { {13, 6 } }, 48);
	txtIns(CLN + "KAMINO/KAMINO_D/KAMINO_D.TXT", "//", {1});
	txtIns(CLN + "KAMINO/KAMINO_D/KAMINO_D.GIT", "//", {2353});
	txtIns(CLN + "KAMINO/KAMINO_D/AI/LEVEL.SCP", "//", {39});
	txtIns(CLN + "KAMINO/KAMINO_D/AI/LEVEL.SCP", "alwaystrue == 1", {{35, 6}},
		44);
	txtIns(CLN + "KAMINO/KAMINO_E/KAMINO_E.TXT", "//", {1, 611, 618});
	txtIns(CLN + "KAMINO/KAMINO_F/KAMINO_F.TXT", "//", {1});
	//fixes invisible mine
	txtIns(CLN + "KAMINO/KAMINO_F/KAMINO_F.GIT", "6", {{12, 8}}, 2);
	txtIns(CLN + "KAMINO/KAMINO_F/KAMINO_F.GIT", "-1", {{306, 9}}, 2);
	txtIns(CLN + "KAMINO/KAMINO_F/KAMINO_F.GIT", "//",
		{896, 897, 1067, 1068, 1069, 1288, 1289, 1290});

	txtIns(CLN + "PURSUIT/PURSUIT_B/PURSUIT_B.TXT", "//", {1});
	txtIns(CLN + "PURSUIT/PURSUIT_B/AI/LEVEL.SCP", "alwaystrue == 1", {{5, 6}},
		41);
	txtIns(CLN + "PURSUIT/PURSUIT_B/AI/LEVEL.SCP", "//", {6});
	txtIns(CLN + "PURSUIT/PURSUIT_D/PURSUIT_D.TXT", "//", {21});
	txtIns(CLN + "PURSUIT/PURSUIT_D/PURSUIT_D.GIT", "status", {{1538, 35}}, 5);
	txtIns(CLN + "PURSUIT/PURSUIT_D/AI/LEVEL.SCP", "alwaystrue == 1", {{5, 6}},
		41);
	txtIns(CLN + "PURSUIT/PURSUIT_D/AI/LEVEL.SCP", "//", {6});
	txtIns(CLN + "PURSUIT/PURSUIT_E/AI/AI_ZAM.SCP", "status", {{67, 35}}, 5);

	txtIns(STH + "ANEWHOPE/ANEWHOPE_A/ANEWHOPE_A.TXT", "//", {15});
	txtIns(STH + "ANEWHOPE/ANEWHOPE_A/AI/LEVEL.SCP", "newlevel=anewhope_status",
		{{27, 19}}, 27);

	txtIns(STH + "CRUISER/CRUISER_A/CRUISER_A.TXT", "//", {5});
	txtIns(STH + "CRUISER/CRUISER_C/CRUISER_C.TXT", "//", {37, 38});
	txtIns(STH + "CRUISER/CRUISER_C/AI/LEVEL.SCP", "//", {19});
	txtIns(STH + "CRUISER/CRUISER_F/CRUISER_F.TXT", "//", {5});
	txtIns(STH + "CRUISER/CRUISER_F/CRUISER_F.GIT", "status", {{57, 35}}, 6);

	txtIns(STH + "DOGFIGHT/DOGFIGHT_A/DOGFIGHT_A.TXT", "//", {2, 3, 4, 230});
	txtIns(STH + "DOGFIGHT/DOGFIGHT_A/DOGFIGHT_B.TXT", "//", {197});

	//?????
	txtIns(STH + "E3CHARACTERBONUS/E3CHARACTERBONUS_A/E3CHARACTERBONUS_A.TXT", "//", {4, 5});

	txtIns(STH + "GRIEVOUS/GRIEVOUS_A/GRIEVOUS_A.TXT", "//", {1, 2});

	txtIns(STH + "KASHYYYK/KASHYYYK_A/KASHYYYK_A.TXT", "//", {1, 2, 3});
	txtIns(STH + "KASHYYYK/KASHYYYK_A/AI/LEVEL.SCP", "//", {32, 36});
	txtIns(STH + "KASHYYYK/KASHYYYK_A/AI/LEVEL.SCP", "alwaystrue == 1", {{31, 6}},
		43);
	txtIns(STH + "KASHYYYK/KASHYYYK_D/KASHYYYK_D.TXT", "//", {1});
	txtIns(STH + "KASHYYYK/KASHYYYK_D/KASHYYYK_D.GIT", "newlevel=kashyyyk_status",
		{{479, 18}}, 27);

	txtIns(STH + "TEMPLE/TEMPLE_C/TEMPLE_C.TXT", "//", {27});
	txtIns(STH + "TEMPLE/TEMPLE_C/TEMPLE_C.GIT", "newlevel=temple_status",
		{{905, 18}}, 32);

	txtIns(STH + "VADER/VADER_B/VADER_B.TXT", "//", {4, 5});
	txtIns(STH + "VADER/VADER_B/AI/LEVEL1.SCP", "//", {19, 22});
	txtIns(STH + "VADER/VADER_B/AI/LEVEL1.SCP", "alwaystrue == 1", {{18, 6}}, 44);
	txtIns(STH + "VADER/VADER_C/VADER_C.TXT", "//", {4, 5});

	txtIns(ANH + "BLOCKADERUNNER/BLOCKADERUNNER_C/BLOCKADERUNNER_C.TXT", "//",
		{21});
	txtIns(ANH + "BLOCKADERUNNER/BLOCKADERUNNER_C/AI/LEVEL.SCP", "//", {59});
	txtIns(ANH + "BLOCKADERUNNER/BLOCKADERUNNER_D/BLOCKADERUNNER_D.GIT", "status",
		{{1367, 42}}, 6);

	txtIns(ANH + "DEATHSTARBATTLE/DEATHSTARBATTLE_C/DEATHSTARBATTLE_C.TXT", "d",
		{{475, 25}}, 6);
	txtIns(ANH + "DEATHSTARBATTLE/DEATHSTARBATTLE_D/DEATHSTARBATTLE_D.TXT", "//",
		{44});
	txtIns(ANH + "DEATHSTARBATTLE/DEATHSTARBATTLE_D/DEATHSTARBATTLE_D.TXT",
		"status", {{593, 25}}, 5);
	txtIns(ANH + "DEATHSTARBATTLE/DEATHSTARBATTLE_D/DEATHSTARBATTLE_D.GIT",
		"status", {{971, 39}}, 5);

	//duplicate
	txtIns(ANH + "DEATHSTARESCAPE/DEATHSTARESCAPE_C/DEATHSTARESCAPE_C.TXT",
		"status", {{154, 25}}, 5);
	txtIns(ANH + "DEATHSTARESCAPE/DEATHSTARESCAPE_C/DEATHSTARESCAPE_C.TXT",
		"status", {{197, 25}}, 5);

	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_A/DEATHSTARRESCUE_A.TXT", "//",
		{80, 81, 82});
	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_A/AI/LEVEL.SCP", "//", {28});
	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_C/DEATHSTARRESCUE_C.TXT", "//",
		{2, 3, 4});
	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_C/DEATHSTARRESCUE_C.TXT",
		"status", {{316, 25}}, 5);
	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_C/DEATHSTARRESCUE_C.GIT",
		"newlevel=deathstarrescue_status", {{2525, 18}}, 30);

	//txtIns(ANH + "MOSEISLEY/MOSEISLEY_C/MOSEISLEY_C.TXT", { 31, 32, 33,
	//114 }); txtIns(ANH + "MOSEISLEY/MOSEISLEY_C/AI/LEVEL.SCP", "alwaystrue ==
	//1", { {48, 6} }, 40);
	txtIns(ANH + "MOSEISLEY/MOSEISLEY_D/MOSEISLEY_D.TXT", "status", {{233, 19}},
		6);

	txtIns(ANH + "TATOOINE/TATOOINE_C/TATOOINE_C.TXT", "status", {{163, 18}}, 5);
	txtIns(ANH + "TATOOINE/TATOOINE_E/TATOOINE_E.GIT", "status", {{1163, 36}}, 5);
	txtIns(ANH + "TATOOINE/TATOOINE_E/TATOOINE_E.TXT", "status", {{121, 18}}, 5);

	txtIns(EMP + "ASTEROIDCHASE/ASTEROIDCHASE_C/ASTEROIDCHASE_C.TXT", "status",
		{{111, 23}}, 5);

	txtIns(EMP + "CLOUDCITYESCAPE/CLOUDCITYESCAPE_B/CLOUDCITYESCAPE_B.TXT", "//",
		{36, 37, 38});
	txtIns(EMP + "CLOUDCITYESCAPE/CLOUDCITYESCAPE_C/CLOUDCITYESCAPE_C.TXT",
		"status", {{132, 25}}, 5);

	txtIns(EMP + "DAGOBAH/DAGOBAH_B/DAGOBAH_B.TXT", "//", {40, 41, 42});
	txtIns(EMP + "DAGOBAH/DAGOBAH_B/AI/LEVEL.SCP", "//", {37});
	txtIns(EMP + "DAGOBAH/DAGOBAH_B/AI/LEVEL.SCP", "gotonewlevel \"level=dagobah_e\"", {{129, 3}}, 35);
	txtIns(EMP + "DAGOBAH/DAGOBAH_C/DAGOBAH_C.TXT", "//", {38, 39, 40});
	txtIns(EMP + "DAGOBAH/DAGOBAH_C/DAGOBAH_C.GIT", "status", {{747, 35}}, 5);
	txtIns(EMP + "DAGOBAH/DAGOBAH_D/DAGOBAH_D.TXT", "//", {32});

	//txtIns(EMP + "ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.TXT", { 2 });

	txtIns(EMP + "HOTHESCAPE/HOTHESCAPE_C/HOTHESCAPE_C.TXT", "status",
		{{162, 20}}, 6);

	txtIns(JDI + "DEATHSTAR2BATTLE/DEATHSTAR2BATTLE_A/DEATHSTAR2BATTLE_A.GIT",
		"b", {{426, 40}}, 6);
	txtIns(JDI + "DEATHSTAR2BATTLE/DEATHSTAR2BATTLE_G/DEATHSTAR2BATTLE_G.TXT",
		"status", {{72, 26}}, 5);

	//txtIns(JDI + "EMPERORFIGHT/EMPERORFIGHT_A/EMPERORFIGHT_A.TXT", { 28,
	//29, 30 });

	txtIns(JDI + "ENDORBATTLE/ENDORBATTLE_D/ENDORBATTLE_D.GIT", "status",
		{{3218, 35}}, 5);

	txtIns(JDI + "JABBASPALACE/JABBASPALACE_A/JABBASPALACE_A.TXT", "//",
		{43, 44, 45});
	txtIns(JDI + "JABBASPALACE/JABBASPALACE_D/JABBASPALACE_D.GIT", "e",
		{{1413, 36}}, 7);

	txtIns(JDI + "SARLACCPIT/SARLACCPIT_A/SARLACCPIT_A.TXT", "//", {4, 5, 6});
	txtIns(JDI + "SARLACCPIT/SARLACCPIT_A/AI/AI_BOBA.SCP", "//", {113, 147});
	txtIns(JDI + "SARLACCPIT/SARLACCPIT_B/SARLACCPIT_B.TXT", "//", {5, 6, 7, 82});
	txtIns(JDI + "SARLACCPIT/SARLACCPIT_C/SARLACCPIT_C.GIT", "status",
		{{998, 38}}, 5);

	txtIns(JDI + "SPEEDERCHASE/SPEEDERCHASE_A/SPEEDERCHASE_A.TXT", "//",
		{12, 13});
	txtIns(JDI + "SPEEDERCHASE/SPEEDERCHASE_A/SPEEDERCHASE_A.GIT", "status",
		{{4403, 40}}, 5);
}