#include "pch.h"

//#ifdef WXWIN
//#include "App.h"
//#endif

#include "Defines.h"
#include "FileGen.h"
#include "OtherStuff.h"
#include "externData.h"

extern std::string out;
extern std::string vanillaDirectory;
extern Level* currentLev;
extern std::vector<Level*> allLevels;
extern bool unlockAll;

void speedUp(int episode, std::string file, std::initializer_list<unsigned int> ln = {}, std::string goLev = "") {
	std::string eps[] = { "EPISODEI", "EPISODEII", "EPISODEIII", "EPISODEIV", "EPISODEV", "EPISODEVI" };
	std::string realFile = out + "/CUT/" + eps[episode - 1] + "/";
	if (episode < 4) realFile += "EP" + std::to_string(episode) + "_";
	realFile += file + ".TXT";
	appendFile(realFile, "fpsec 500000");
	if (ln.size() != 0) lineDeleter(realFile, ln);
	if (goLev != "") appendFile(realFile, "goto_level \"" + goLev + "\"");
	std::cout << "Sped up " << realFile << std::endl;
}

void fileGen() {
	//copies the game files and removes cutscenes

	logR("\n\t\t\t\t\tGenerating files. . .");
	//wxLogStatus("Generating files. . .");
	std::cout << "Generating files. . ." << std::endl;

	//std::filesystem::remove_all(out);


	std::filesystem::copy(vanillaDirectory, out,
		std::filesystem::copy_options::recursive | std::filesystem::copy_options::skip_existing);

	//std::string cmd = ("files\\quickbms.exe -F \"*.DAT\" -o files\\ttgames.bms " + out + " " + out);
	//system(cmd.c_str());
	std::cout << "Done copying." << std::endl;
	std::remove((out + "EPISODE_I.DAT").c_str());
	std::remove((out + "EPISODE_II.DAT").c_str());
	std::remove((out + "EPISODE_III.DAT").c_str());
	std::remove((out + "EPISODE_IV.DAT").c_str());
	std::remove((out + "EPISODE_V.DAT").c_str());
	std::remove((out + "EPISODE_VI.DAT").c_str());
	std::remove((out + "GAME.DAT").c_str());

	std::remove((out + "\\SCRIPTS\\AI.PAK").c_str());
	std::remove((out + "\\STUFF\\ATS\\ATS.PAK").c_str());
	std::remove((out + "\\ALLTXT.PAK").c_str());
	for (Level* lev : allLevels) {
		for (char scene = 'A'; scene < 'H'; scene++)
			std::remove((out + lev->path + lev->shortName + '_' + scene + "/AI/AI.PAK").c_str());
		std::cout << lev->name << " AI2s deleted." << std::endl;
	}

	std::remove((out + "\\LEVELS\\MAP\\MAP\\AI\\AI.PAK").c_str());
	//system(("del /S " + LEV + "\\*.PAK").c_str());
	//system(("del " + out + "\\SCRIPTS\\AI.PAK").c_str());
	//system(("del " + out + "\\ALLTXT.PAK").c_str());
	//system(("rm " + out + "/*.PAK").c_str());
	//system(("find " + out + " -type f -name '*.PAK' -delete").c_str());
	//system("cls");

	//std::filesystem::remove(LEV + "ANAKINSFLIGHT/ANAKINSFLIGHT_A/AI/AI.PAK");
	//std::filesystem::remove(LEV + "ANAKINSFLIGHT/ANAKINSFLIGHT_B/AI/AI.PAK");
	//std::filesystem::remove(LEV + "ANAKINSFLIGHT/ANAKINSFLIGHT_C/AI/AI.PAK");
	//std::filesystem::remove(LEV + "BONUS/NEW_TOWN/AI/AI.PAK");
	//std::filesystem::remove(LEV + "BONUS_GUNSHIP/BONUS_GUNSHIP_A/AI/AI.PAK");
	//std::filesystem::remove(LEV + "BONUS_GUNSHIP/BONUS_GUNSHIP_B/AI/AI.PAK");
	//std::filesystem::remove(LEV + "BONUS_2/LEGO_CITY/AI/AI.PAK");
	//std::filesystem::remove(TPM + "E1CHARACTERBONUS/E1CHARACTERBONUS_A/AI/AI.PAK");
	//std::filesystem::remove(TPM + "E1VEHICLEBONUS/E1VEHICLEBONUS/AI/AI.PAK");
	//std::filesystem::remove(TPM + "GUNGAN/GUNGAN_A/AI/AI.PAK");
	//std::filesystem::remove(TPM + "GUNGAN/GUNGAN_B/AI/AI.PAK");
	//std::filesystem::remove(TPM + "GUNGAN/GUNGAN_C/AI/AI.PAK");
	//std::filesystem::remove(TPM + "GUNGAN/GUNGAN_D/AI/AI.PAK");
	//std::filesystem::remove(TPM + "GUNGAN/GUNGAN_E/AI/AI.PAK");
	//std::filesystem::remove(TPM + "MAUL/MAUL_A/AI/AI.PAK");
	//std::filesystem::remove(TPM + "MAUL/MAUL_B/AI/AI.PAK");
	//std::filesystem::remove(TPM + "MAUL/MAUL_D/AI/AI.PAK");
	//std::filesystem::remove(TPM + "MAUL/MAUL_E/AI/AI.PAK");
	//std::filesystem::remove(TPM + "MAUL/MAUL_F/AI/AI.PAK");
	//std::filesystem::remove(TPM + "NEGOTIATIONS/NEGOTIATIONS_A/AI/AI.PAK");
	//std::filesystem::remove(TPM + "NEGOTIATIONS/NEGOTIATIONS_B/AI/AI.PAK");
	//std::filesystem::remove(TPM + "NEGOTIATIONS/NEGOTIATIONS_C/AI/AI.PAK");
	//std::filesystem::remove(TPM + "NEGOTIATIONS/NEGOTIATIONS_OUTRO/AI/AI.PAK");
	//std::filesystem::remove(TPM + "PALACERESCUE/RESCUE_A/AI/AI.PAK");
	//std::filesystem::remove(TPM + "PALACERESCUE/RESCUE_B/AI/AI.PAK");
	//std::filesystem::remove(TPM + "PALACERESCUE/RESCUE_C/AI/AI.PAK");
	//std::filesystem::remove(TPM + "PALACERESCUE/RESCUE_E/AI/AI.PAK");
	//std::filesystem::remove(TPM + "PODRACE/PODRACE_A/AI/AI.PAK");
	//std::filesystem::remove(TPM + "PODRACE/PODRACE_B/AI/AI.PAK");
	//std::filesystem::remove(TPM + "PODRACE/PODRACE_C/AI/AI.PAK");
	//std::filesystem::remove(TPM + "PODSPRINT/PODSPRINT_A/AI/AI.PAK");
	//std::filesystem::remove(TPM + "RETAKEPALACE/RETAKE_A/AI/AI.PAK");
	//std::filesystem::remove(TPM + "RETAKEPALACE/RETAKE_B/AI/AI.PAK");
	//std::filesystem::remove(TPM + "RETAKEPALACE/RETAKE_D/AI/AI.PAK");
	//std::filesystem::remove(TPM + "RETAKEPALACE/RETAKE_E/AI/AI.PAK");
	//std::filesystem::remove(TPM + "RETAKEPALACE/RETAKE_F/AI/AI.PAK");
	//std::filesystem::remove(TPM + "RETAKEPALACE/RETAKE_G/AI/AI.PAK");
	//
	//std::filesystem::remove(CLN + "DOOKU/DOOKU_B/AI/AI.PAK");
	//std::filesystem::remove(CLN + "DOOKU/DOOKU_C/AI/AI.PAK");
	//std::filesystem::remove(CLN + "E2CHARACTERBONUS/E2CHARACTERBONUS/AI/AI.PAK");
	//std::filesystem::remove(CLN + "E2VEHICLEBONUS/E2VEHICLEBONUS/AI/AI.PAK");
	//std::filesystem::remove(CLN + "FACTORY/FACTORY_A/AI/AI.PAK");
	//std::filesystem::remove(CLN + "FACTORY/FACTORY_B/AI/AI.PAK");
	//std::filesystem::remove(CLN + "FACTORY/FACTORY_D/AI/AI.PAK");
	//std::filesystem::remove(CLN + "FACTORY/FACTORY_E/AI/AI.PAK");
	//std::filesystem::remove(CLN + "FACTORY/FACTORY_F/AI/AI.PAK");
	//std::filesystem::remove(CLN + "FACTORY/FACTORY_G/AI/AI.PAK");
	//std::filesystem::remove(CLN + "GUNSHIP/GUNSHIP_A/AI/AI.PAK");
	//std::filesystem::remove(CLN + "GUNSHIP/GUNSHIP_B/AI/AI.PAK");

	//cmd = "del /S " + out + "\\*PAK";
	//system(cmd.c_str());

	logR("\n\t\t\t\t\tPatching. . .");
	//wxLogStatus("Patching. . .");
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
	//
	//for (int i : freePlay)
	//	binaryWrite(EXE, "0f", i);

	//removes cutscenes

	//0x15C696 removes midtros, breaks jarjar

	//binaryWrite(EXE, "0f", );

	//0x1f2aa0:
	//89e583ec04a1a895870050e8f00ad8ffa3a01b950089ece9e3c0c8ff

	//0x07eb90
	//c744240c0300000052e9023f370090

	//return;

	//---DOOKU OUTRO
	//---VADER OUTRO
	//SPACEPORT MIDTRO?
	//---ep5 finish story
	//test princess midtro

	//txtIns(LEV + "AREAS.TXT", "//",
	//       {//29, 30, //negotiations
	//	34, 45, 46, 52, 63, 64, 65, 70, 94, 95, 96, 97, 98, 102, 103,
	//	114, 115, 116, 123, 134, 182, 188, 201, 202, 208, 209, 220, 221,
	//	222, //factory
	//	239, 241, 278,
	//	//281, //dooku
	//	345, 346, 383, 384, 398,
	//	444, //anh demo
	//	456,
	//	457, //plans
	//	462, 463,
	//	474, //jundland
	//	480,
	//	492, //spaceport
	//	498, 499, 500, 512,
	//	513, //princess
	//	//530, //dse
	//	535, 546, 547, 548, 549, 554, 555, 600, 601, 602, 603, 609,
	//	//621, //echo base
	//	626, 627, 638, 643, 644, 658, 664, 675, 679, 690,
	//	691, //bespin
	//	695,
	//	//737, 738, //jabbas
	//	743, 744,
	//	755, //carkoon
	//	759,
	//	783, //endor
	//	788, 799, 812, 820, 821, 877, 881, 882});

	lineDeleter(LEV + "AREAS.TXT", { 29, 45, 63, 65, 94, 95, 96, 97, 114, 115, 201, 220, 221, 383, 456, 512, 546, 547,
									   548, 600, 601, 602, 690, 737 });

	//lineDeleter(out + Negotiations->path + "NEGOTIATIONS_INTRO/EP1_FAILEDNEG_INTRO2.TXT", {1,
	//2, 3}); lineDeleter(out + BHP->path + "PURSUIT_INTRO/PURSUIT_INTRO.TXT", {1});
	//lineDeleter(out + Vader->path + "VADER_INTRO/VADER_INTRO.TXT", {1});
	//lineDeleter(out + ITDS->path + "DEATHSTAR2BATTLE_INTRO/DEATHSTAR2BATTLE_INTRO.TXT", {2});

	//TODO bonus gunship

	//finish story
	txtIns(out + "/CUT/EPISODEI/EP1_EPISODECOMPLETE_CELEBRATIONS.TXT", "//", { 13 });
	txtIns(out + "/CUT/EPISODEI/EP1_EPISODECOMPLETE_CELEBRATIONS.TXT", "500000", { {1, 7} }, 2);

	txtIns(out + "/CUT/EPISODEII/EP2_ENDING1.TXT", "//", { 13 });
	txtIns(out + "/CUT/EPISODEII/EP2_ENDING1.TXT", "500000", { {1, 7} }, 2);
	txtIns(out + "/CUT/EPISODEII/EP2_ENDING2.TXT", "500000", { {1, 7} }, 2);

	txtIns(out + "/CUT/EPISODEIII/EP3_EPISODE_OUTRO1.TXT", "//", { 14 });
	txtIns(out + "/CUT/EPISODEIII/EP3_EPISODE_OUTRO1.TXT", "500000", { {1, 7} }, 2);
	txtIns(out + "/CUT/EPISODEIII/EP3_EPISODE_OUTRO2.TXT", "500000", { {1, 7} }, 2);
	txtIns(out + "/CUT/EPISODEIII/EP3_EPISODE_OUTRO3.TXT", "500000", { {1, 7} }, 2);

	txtIns(out + "/CUT/EPISODEIV/EPISODE4ENDING.TXT", "//", { 1 });
	txtIns(out + "/CUT/EPISODEIV/EPISODE4ENDING.TXT", "fpsec 500000\n", { 4 });

	txtIns(out + "/CUT/EPISODEV/EPISODE5ENDING.TXT", "//", { 4 });
	txtIns(out + "/CUT/EPISODEV/EPISODE5ENDING.TXT", "fpsec 500000\n", { 1 });

	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING.TXT", "//", { 4 });
	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING.TXT", "fpsec 500000\n", { 1 });
	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING_PART1.TXT", "//", { 2 });
	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING_PART1.TXT", "fpsec 500000\n", { 1 });
	txtIns(out + "/CUT/EPISODEVI/EPISODE6ENDING_PART2.TXT", "fpsec 500000\n", { 1 });

	//removes FP checks
	binaryWrite(EXE, "0f", 0xe1ffe); //kamino
	binaryWrite(EXE, "0f", 0xdf0f2); //jedi battle
	binaryWrite(EXE, "0f", 0xe7c30); //falconflight
	binaryWrite(EXE, "0f", 0xe7e9e); //cct
	binaryWrite(EXE, "0f", 0xe9ba6); //hoth
	binaryWrite(EXE, "0f", 0xe33a1); //grievous
	binaryWrite(EXE, "0f", 0xeaf5f); //destiny
	binaryWrite(EXE, "0f", 0x39475); //vader

	//diverts outro pointer to status screen
	binaryWrite(EXE, "bcb087", 0xdab15); //podrace original
	hexWrite(EXE, "jabbaspalace_status", 0x35A450);

	//
	speedUp(1, "FAILEDNEG_INTRO2A", { 1, 8 }, "negotiations_a");
	txtIns(TPM + "NEGOTIATIONS/NEGOTIATIONS_A/NEGOTIATIONS_A.TXT", "//", { 7 });
	txtIns(TPM + "NEGOTIATIONS/NEGOTIATIONS_C/NEGOTIATIONS_C.TXT", "negotiations_status", { {567, 9} }, 15);

	speedUp(1, "GUNGANCITY_INTRO2", { 1 });
	txtIns(TPM + "GUNGAN/GUNGAN_A/GUNGAN_A.TXT", "//", { 42, 43, 503 });
	txtIns(TPM + "GUNGAN/GUNGAN_A/AI/JARJARBINKS.SCP", "EitherPlayerInTriggerArea \"PlayCutScene\" == 1", { {5, 6} }, 58);
	lineDeleter(TPM + "GUNGAN/GUNGAN_A/AI/LEVEL.SCP", { 23 });
	lineDeleter(TPM + "GUNGAN/GUNGAN_E/GUNGAN_E.TXT", { 34, 58 });

	speedUp(1, "RESCUE_INTRO2", { 1, 8 }, "rescue_a");
	txtIns(TPM + "PALACERESCUE/RESCUE_E/RESCUE_E.TXT", "status", { {102, 16} }, 5);

	speedUp(1, "PODRACE_INTRO", { 1 });
	lineDeleter(TPM + "PODRACE/PODRACE_A/PODRACE_A.TXT", { 10, 11, 12 });
	lineDeleter(TPM + "PODRACE/PODRACE_B/PODRACE_B.TXT", { 11, 12, 13 });
	lineDeleter(TPM + "PODRACE/PODRACE_C/PODRACE_C.TXT", { 11, 12, 13 });
	binaryWrite(EXE, "DEAE4D",
		0xDB074); //allows mushroom to collapse without cutscene

	speedUp(1, "PODSPRINT", { 1 });
	txtIns(TPM + "PODSPRINT/PODSPRINT_A/PODSPRINT_A.TXT", "//", { 20, 21, 22, 23, 26, 27, 28, 30, 31, 34, 35 });
	//check code
	txtIns(TPM + "PODSPRINT/PODSPRINT_A/AI/LEVEL.SCP", "alwaystrue == 1", { {73, 6} }, 45);
	lineDeleter(TPM + "PODSPRINT/PODSPRINT_A/AI/LEVEL.SCP", { 65, 74, 78 });

	speedUp(1, "RETAKETHEEDPALACE_INTRO3", { 1 });
	txtIns(TPM + "RETAKEPALACE/RETAKE_G/AI/LEVEL.SCP", "status", { {136, 34} }, 5);

	speedUp(1, "DARTHMAUL_INTRO", { 5 });
	txtIns(TPM + "MAUL/MAUL_F/MAUL_F.TXT", "//", { 1 });
	txtIns(TPM + "MAUL/MAUL_F/AI/DARTHMAUL.SCP", "newlevel=maul_status", { {427, 18} }, 28);

	speedUp(1, "ANAKINSFLIGHT_INTRO", { 1 });
	txtIns(LEV + "ANAKINSFLIGHT/ANAKINSFLIGHT_C/ANAKINSFLIGHT_C.GIT", "status", { {1602, 41} }, 6);

	speedUp(2, "PURSUIT_INTRO2", { 1 });
	lineDeleter(CLN + "PURSUIT/PURSUIT_INTRO/PURSUIT_INTRO.TXT", { 1 });
	txtIns(CLN + "PURSUIT/PURSUIT_B/AI/LEVEL.SCP", "alwaystrue == 1", { {5, 6} }, 41);
	txtIns(CLN + "PURSUIT/PURSUIT_B/AI/LEVEL.SCP", "//", { 6 });
	txtIns(CLN + "PURSUIT/PURSUIT_B/PURSUIT_B.TXT", "//", { 1 });
	txtIns(CLN + "PURSUIT/PURSUIT_D/PURSUIT_D.TXT", "//", { 21 });
	txtIns(CLN + "PURSUIT/PURSUIT_D/PURSUIT_D.GIT", "status", { {1538, 35} }, 5);
	txtIns(CLN + "PURSUIT/PURSUIT_D/AI/LEVEL.SCP", "alwaystrue == 1", { {5, 6} }, 41);
	txtIns(CLN + "PURSUIT/PURSUIT_D/AI/LEVEL.SCP", "//", { 6 });
	txtIns(CLN + "PURSUIT/PURSUIT_E/AI/AI_ZAM.SCP", "status", { {67, 35} }, 5);

	speedUp(2, "KAMINO_INTRO2", { 1 });
	speedUp(2, "KAMINO_DISCOVERJANGO", { 8 });
	txtIns(CLN + "KAMINO/KAMINO_A/KAMINO_A.TXT", "//", { 1, 408 });
	txtIns(CLN + "KAMINO/KAMINO_A/AI/KAMINO.SCP", "//", { 69 });
	txtIns(CLN + "KAMINO/KAMINO_A/AI/TAUNWE.SCP", "//", { 23 });
	txtIns(CLN + "KAMINO/KAMINO_A/AI/TAUNWE2.SCP", "//", { 23 });
	//txtIns(CLN + "KAMINO/KAMINO_C/KAMINO_C.TXT", { 1, 1181 }); //discover
	//jango txtIns(CLN + "KAMINO/KAMINO_C/AI/LEVEL.SCP",
	//"EitherPlayerInTriggerArea \"Jango\" == 1", { {13, 6 } }, 48);
	txtIns(CLN + "KAMINO/KAMINO_D/KAMINO_D.TXT", "//", { 1 });
	txtIns(CLN + "KAMINO/KAMINO_D/KAMINO_D.GIT", "//", { 2353 });
	txtIns(CLN + "KAMINO/KAMINO_D/AI/LEVEL.SCP", "//", { 39 });
	txtIns(CLN + "KAMINO/KAMINO_D/AI/LEVEL.SCP", "alwaystrue == 1", { {35, 6} }, 44);
	txtIns(CLN + "KAMINO/KAMINO_E/KAMINO_E.TXT", "//", { 1, 611, 618 });
	txtIns(CLN + "KAMINO/KAMINO_F/KAMINO_F.TXT", "//", { 1 });
	//fixes invisible mine
	txtIns(CLN + "KAMINO/KAMINO_F/KAMINO_F.GIT", "6", { {12, 8} }, 2);
	txtIns(CLN + "KAMINO/KAMINO_F/KAMINO_F.GIT", "-1", { {306, 9} }, 2);
	txtIns(CLN + "KAMINO/KAMINO_F/KAMINO_F.GIT", "//", { 896, 897, 1067, 1068, 1069, 1288, 1289, 1290 });

	speedUp(2, "FACTORY_INTRO3", { 1 });
	//txtIns(CLN + "FACTORY/FACTORY_G/FACTORY_G.TXT", { 1 });
	txtIns(CLN + "FACTORY/FACTORY_G/FACTORY_G.GIT", "Action", { {286, 2} }, 9);
	txtIns(CLN + "FACTORY/FACTORY_G/FACTORY_G.GIT", "completelevel \"newlevel=factory_status\"", { {287, 3} }, 8);

	speedUp(2, "GUNSHIPCAVALRY_INTRO", { 4 });
	txtIns(CLN + "GUNSHIP/GUNSHIP_A/GUNSHIP_A.TXT", "//", { 6 });
	txtIns(CLN + "GUNSHIP/GUNSHIP_B/GUNSHIP_B.TXT", "//", { 7, 8 });
	txtIns(CLN + "GUNSHIP/GUNSHIP_B/GUNSHIP_B.GIT", "newlevel=gunship_status", { {882, 18} }, 33);
	txtIns(LEV + "BONUS_GUNSHIP/BONUS_GUNSHIP_A/BONUS_GUNSHIP_A.TXT", "//", { 6 });
	txtIns(LEV + "BONUS_GUNSHIP/BONUS_GUNSHIP_B/BONUS_GUNSHIP_B.TXT", "//", { 7, 8, 9 });
	txtIns(LEV + "BONUS_GUNSHIP/BONUS_GUNSHIP_B/BONUS_GUNSHIP_B.GIT", "newlevel=bonus_gunship_status", { {743, 18} }, 34);

	speedUp(2, "JEDIBATTLE_INTRO", { 1 });
	txtIns(CLN + "JEDI/JEDI_B/JEDI_B.TXT", "//", { 1 });
	txtIns(CLN + "JEDI/JEDI_B/AI/LEVEL.SCP", "//", { 101 });

	speedUp(2, "COUNTDOOKU_INTRO", { 2, 10 });
	speedUp(2, "COUNTDOOKU_DOOKUFIGHT", { 7 });
	speedUp(2, "COUNTDOOKU_OUTRO", { 8 });
	txtIns(CLN + "DOOKU/DOOKU_C/DOOKU_C.TXT", "//", { 4 });
	txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", "//", { 215 });
	//txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", { 5, 8 });
	txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", "alwaystrue == 1", { {222, 6} }, 56);
	//txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", "alwaystrue == 1", { {7, 6}
	//}, 48); txtIns(CLN + "DOOKU/DOOKU_C/AI/DOOKU.SCP", "\t\tsetstate
	//\"normalintrocomplete\"\n", { 18 });

	speedUp(3, "BATTLEOVERCORUSCANT_INTRO", { 1, 17 });
	txtIns(STH + "DOGFIGHT/DOGFIGHT_A/DOGFIGHT_A.TXT", "//", { 3, 4, 230 });
	txtIns(STH + "DOGFIGHT/DOGFIGHT_A/DOGFIGHT_B.TXT", "//", { 197 });

	speedUp(3, "CRUISER_INTRO", { 1 });
	txtIns(STH + "CRUISER/CRUISER_C/CRUISER_C.TXT", "//", { 37, 38 });
	txtIns(STH + "CRUISER/CRUISER_C/AI/LEVEL.SCP", "//", { 19 });
	txtIns(STH + "CRUISER/CRUISER_F/CRUISER_F.TXT", "//", { 5 });
	txtIns(STH + "CRUISER/CRUISER_F/CRUISER_F.GIT", "status", { {57, 35} }, 6);

	speedUp(3, "GENERALGRIEVOUS_INTRO2", { 1 });
	txtIns(STH + "GRIEVOUS/GRIEVOUS_A/GRIEVOUS_A.TXT", "//", { 1 });

	speedUp(3, "KASHYYYK_INTRO2", { 1 });
	txtIns(STH + "KASHYYYK/KASHYYYK_A/KASHYYYK_A.TXT", "//", { 1, 3 });
	txtIns(STH + "KASHYYYK/KASHYYYK_A/AI/LEVEL.SCP", "//", { 32, 36 });
	txtIns(STH + "KASHYYYK/KASHYYYK_A/AI/LEVEL.SCP", "alwaystrue == 1", { {31, 6} }, 43);
	txtIns(STH + "KASHYYYK/KASHYYYK_D/KASHYYYK_D.TXT", "//", { 1 });
	txtIns(STH + "KASHYYYK/KASHYYYK_D/KASHYYYK_D.GIT", "newlevel=kashyyyk_status", { {479, 18} }, 27);

	speedUp(3, "TEMPLE_INTRO2", { 1 });
	txtIns(STH + "TEMPLE/TEMPLE_C/TEMPLE_C.TXT", "//", { 27 });
	txtIns(STH + "TEMPLE/TEMPLE_C/TEMPLE_C.GIT", "newlevel=temple_status", { {905, 18} }, 32);

	speedUp(3, "DARTHVADER_INTRO1", { 6, 7 }, "vader_a");
	txtIns(STH + "VADER/VADER_B/VADER_B.TXT", "//", { 4, 5 });
	txtIns(STH + "VADER/VADER_INTRO/VADER_INTRO.TXT", "//", { 2 });
	txtIns(STH + "VADER/VADER_B/AI/LEVEL1.SCP", "//", { 19, 22 });
	txtIns(STH + "VADER/VADER_B/AI/LEVEL1.SCP", "alwaystrue == 1", { {18, 6} }, 44);
	txtIns(STH + "VADER/VADER_C/VADER_C.TXT", "//", { 4, 5 });

	speedUp(3, "ANEWHOPE_INTRO", { 1, 45 });
	txtIns(STH + "ANEWHOPE/ANEWHOPE_A/ANEWHOPE_A.TXT", "//", { 15 });
	txtIns(STH + "ANEWHOPE/ANEWHOPE_A/AI/LEVEL.SCP", "newlevel=anewhope_status", { {27, 19} }, 27);

	//?????
	txtIns(STH + "E3CHARACTERBONUS/E3CHARACTERBONUS_A/E3CHARACTERBONUS_A.TXT", "//", { 4, 5 });

	speedUp(4, "BLOCKADERUNNER_INTRO2");
	txtIns(ANH + "BLOCKADERUNNER/BLOCKADERUNNER_C/BLOCKADERUNNER_C.TXT", "//", { 21 });
	txtIns(ANH + "BLOCKADERUNNER/BLOCKADERUNNER_C/AI/LEVEL.SCP", "//", { 59 });
	txtIns(ANH + "BLOCKADERUNNER/BLOCKADERUNNER_D/BLOCKADERUNNER_D.GIT", "status", { {1367, 42} }, 6);

	speedUp(4, "TATOOINE_INTRO", { 3 });
	txtIns(ANH + "TATOOINE/TATOOINE_C/TATOOINE_C.TXT", "status", { {163, 18} }, 5);
	txtIns(ANH + "TATOOINE/TATOOINE_E/TATOOINE_E.GIT", "status", { {1163, 36} }, 5);
	txtIns(ANH + "TATOOINE/TATOOINE_E/TATOOINE_E.TXT", "status", { {121, 18} }, 5);

	speedUp(4, "MOSEISLEY_INTRO", { 1, 4 });
	speedUp(4, "MOSEISLEY_MIDTRO", { 1 });

	//txtIns(ANH + "MOSEISLEY/MOSEISLEY_C/MOSEISLEY_C.TXT", { 31, 32, 33,
	//114 }); txtIns(ANH + "MOSEISLEY/MOSEISLEY_C/AI/LEVEL.SCP", "alwaystrue
	//== 1", { {48, 6} }, 40);
	txtIns(ANH + "MOSEISLEY/MOSEISLEY_D/MOSEISLEY_D.TXT", "status", { {233, 19} }, 6);

	speedUp(4, "DEATHSTARRESCUE_INTRO2");
	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_A/DEATHSTARRESCUE_A.TXT", "//", { 80, 81, 82 });
	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_A/AI/LEVEL.SCP", "//", { 28 });
	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_C/DEATHSTARRESCUE_C.TXT", "//", { 2, 3, 4 });
	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_C/DEATHSTARRESCUE_C.TXT", "status", { {316, 25} }, 5);
	txtIns(ANH + "DEATHSTARRESCUE/DEATHSTARRESCUE_C/DEATHSTARRESCUE_C.GIT", "newlevel=deathstarrescue_status",
		{ {2525, 18} }, 30);

	speedUp(4, "DEATHSTARESCAPE_INTRO", { 8 });
	txtIns(ANH + "DEATHSTARESCAPE/DEATHSTARESCAPE_C/DEATHSTARESCAPE_C.TXT", "status", { {154, 25} }, 5);
	txtIns(ANH + "DEATHSTARESCAPE/DEATHSTARESCAPE_C/DEATHSTARESCAPE_C.TXT", "status", { {197, 25} }, 5);

	txtIns(out + "/CUT/EPISODEIV/DEATHSTARESCAPE_INTRO.TXT", "//", { 7 });
	txtIns(out + "/CUT/EPISODEIV/DEATHSTARESCAPE_INTRO.TXT", "fpsec 500000\n", { 1 });

	speedUp(4, "DEATHSTARBATTLE_INTRO4");
	txtIns(ANH + "DEATHSTARBATTLE/DEATHSTARBATTLE_C/DEATHSTARBATTLE_C.TXT", "d", { {475, 25} }, 6);
	txtIns(ANH + "DEATHSTARBATTLE/DEATHSTARBATTLE_D/DEATHSTARBATTLE_D.TXT", "//", { 44 });
	txtIns(ANH + "DEATHSTARBATTLE/DEATHSTARBATTLE_D/DEATHSTARBATTLE_D.TXT", "status", { {593, 25} }, 5);
	txtIns(ANH + "DEATHSTARBATTLE/DEATHSTARBATTLE_D/DEATHSTARBATTLE_D.GIT", "status", { {971, 39} }, 5);

	speedUp(5, "HOTHBATTLE_INTRO4");

	speedUp(5, "HOTHESCAPE_INTRO", { 1 });
	txtIns(EMP + "HOTHESCAPE/HOTHESCAPE_C/HOTHESCAPE_C.TXT", "status", { {162, 20} }, 6);

	speedUp(5, "ASTEROIDCHASE_INTRO", { 1 });
	txtIns(EMP + "ASTEROIDCHASE/ASTEROIDCHASE_C/ASTEROIDCHASE_C.TXT", "status", { {111, 23} }, 5);

	speedUp(5, "DAGOBAH_INTRO", { 4 });
	txtIns(EMP + "DAGOBAH/DAGOBAH_B/DAGOBAH_B.TXT", "//", { 40, 41, 42 });
	txtIns(EMP + "DAGOBAH/DAGOBAH_B/AI/LEVEL.SCP", "//", { 37 });
	txtIns(EMP + "DAGOBAH/DAGOBAH_B/AI/LEVEL.SCP", "gotonewlevel \"level=dagobah_e\"", { {129, 3} }, 35);
	txtIns(EMP + "DAGOBAH/DAGOBAH_C/DAGOBAH_C.TXT", "//", { 38, 39, 40 });
	txtIns(EMP + "DAGOBAH/DAGOBAH_C/DAGOBAH_C.GIT", "status", { {747, 35} }, 5);
	txtIns(EMP + "DAGOBAH/DAGOBAH_D/DAGOBAH_D.TXT", "//", { 32 });

	speedUp(5, "CLOUDCITYTRAP_INTRO", { 1 });

	speedUp(5, "CLOUDCITYESCAPE_INTRO2", {});
	txtIns(EMP + "CLOUDCITYESCAPE/CLOUDCITYESCAPE_B/CLOUDCITYESCAPE_B.TXT", "//", { 36, 37, 38 });
	txtIns(EMP + "CLOUDCITYESCAPE/CLOUDCITYESCAPE_C/CLOUDCITYESCAPE_C.TXT", "status", { {132, 25} }, 5);

	//txtIns(EMP + "ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.TXT", { 2 });

	speedUp(6, "JABBASPALACE_INTRO2", {});
	txtIns(JDI + "JABBASPALACE/JABBASPALACE_A/JABBASPALACE_A.TXT", "//", { 43, 44, 45 });
	txtIns(JDI + "JABBASPALACE/JABBASPALACE_D/JABBASPALACE_D.GIT", "e", { {1413, 36} }, 7);

	speedUp(6, "SARLACCPIT_INTRO", { 4 });
	txtIns(JDI + "SARLACCPIT/SARLACCPIT_A/SARLACCPIT_A.TXT", "//", { 4, 5, 6 });
	txtIns(JDI + "SARLACCPIT/SARLACCPIT_A/AI/AI_BOBA.SCP", "//", { 113, 147 });
	txtIns(JDI + "SARLACCPIT/SARLACCPIT_B/SARLACCPIT_B.TXT", "//", { 5, 6, 7, 82 });
	txtIns(JDI + "SARLACCPIT/SARLACCPIT_C/SARLACCPIT_C.GIT", "status", { {998, 38} }, 5);

	speedUp(6, "SPEEDERCHASE_INTRO", { 1 });
	txtIns(JDI + "SPEEDERCHASE/SPEEDERCHASE_A/SPEEDERCHASE_A.TXT", "//", { 13 });
	txtIns(JDI + "SPEEDERCHASE/SPEEDERCHASE_A/SPEEDERCHASE_A.GIT", "status", { {4403, 40} }, 5);

	speedUp(2, "KAMINO_INTRO1", { 1, 8, 12 }, "endorbattle_a");
	lineDeleter(JDI + "ENDORBATTLE/ENDORBATTLE_INTRO/ENDORBATTLE_INTRO.TXT", { 2 });
	appendFile(
		JDI + "ENDORBATTLE/ENDORBATTLE_INTRO/ENDORBATTLE_INTRO.TXT", "cutscene \"episodeii\\ep2_kamino_intro1\"");
	txtIns(JDI + "ENDORBATTLE/ENDORBATTLE_D/ENDORBATTLE_D.GIT", "status", { {3218, 35} }, 5);

	speedUp(2, "FACTORY_INTRO2", { 1, 8 }, "emperorfight_a");
	lineDeleter(JDI + "EMPERORFIGHT/EMPERORFIGHT_INTRO/EMPERORFIGHT_INTRO.TXT", { 2 });
	appendFile(
		JDI + "EMPERORFIGHT/EMPERORFIGHT_INTRO/EMPERORFIGHT_INTRO.TXT", "cutscene \"episodeii\\ep2_factory_intro2\"");
	//txtIns(JDI + "EMPERORFIGHT/EMPERORFIGHT_A/EMPERORFIGHT_A.TXT", { 28,
	//29, 30 });

	speedUp(6, "DEATHSTAR2BATTLE_INTRO2");
	lineDeleter(JDI + "DEATHSTAR2BATTLE/DEATHSTAR2BATTLE_INTRO/DEATHSTAR2BATTLE_INTRO.TXT", { 2 });
	txtIns(JDI + "DEATHSTAR2BATTLE/DEATHSTAR2BATTLE_A/DEATHSTAR2BATTLE_A.GIT", "b", { {426, 40} }, 6);
	txtIns(JDI + "DEATHSTAR2BATTLE/DEATHSTAR2BATTLE_G/DEATHSTAR2BATTLE_G.TXT", "status", { {72, 26} }, 5);

	//system("cls");

	if (unlockAll) {
		const unsigned int jumpFrom = 0x42ad25;
		const unsigned int jumpTo = 0x785EA0;
		//binaryWrite(EXE, jmp(jumpTo), jumpFrom - 0x400000);
		std::string temp = "E8" + littleEndSigned(jumpTo - jumpFrom - 5); //call
		std::cout << temp << std::endl;
		binaryWrite(EXE, temp, jumpFrom - 0x400000);
		std::array<unsigned int, 55> levPtrs = getLevPtr(0x87af70);
		std::string func; //make this a function
		func += "55"      //push ebp
			"89e5"    //mov ebp, esp
			"33db";   //xor ebx, ebx
		for (unsigned int i : levPtrs) {
			func += unlockAsm(i);
		}
		func += "a164b08700" //code I hade to erase to make room for call
			"89ec"       //mov esp, ebp
			"5d"         //pop ebp
			"c3";        //ret
		std::cout << func << std::endl;
		binaryWrite(EXE, func, jumpTo - 0x400000);
	}
}
