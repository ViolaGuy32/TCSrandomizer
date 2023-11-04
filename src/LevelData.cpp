#include "LevelData.h"
#include "Defines.h"
#include "Levels.h"
#include "externData.h"
#include "pch.h"

void makeLevels() {
	//LEVELS

	Negotiations = new Level("NEGOTIATIONS", "NEGOTIATIONS", "/LEVELS/EPISODE_I/NEGOTIATIONS/", false,
		{quigonjinn, obiwankenobi, tc14}, {},
		{quigonjinn, obiwankenobi, tc14, battledroid, battledroid_security, battledroid_commander, destroyer},
		{{'A', {0xa6a0, 0xa689, 0xa672, 0xa65b, 0xa644, 0xa34d, 0xa90d, 0xa8f6, 0xa8df, 0xa8c8}},
			{'B', {0xfc1, 0xfaa, 0xf4e, 0xf37}}, {'C', {0x37c5, 0x37ae, 0x3797, 0x3780, 0x36df, 0x36c8, 0x36b1}}},
		{},

		{{'A',
			 {
				 {ProtoPanel, 0xAA03}, //sheild room
				 {ProtoPanel, 0xAA32}, //box room
				 {ProtoPanel, 0xAA61}, //second story
				 {ProtoPanel, 0xAA90}, //first story
				 {AstroPanel, 0xAABF}, //to room B
			 }},
			{'B', {{AstroPanel, 0x10E7}}}, //useless
			{
				'C',
				{
					{AstroPanel, 0x38C9}, //rb
					{ProtoPanel, 0x38F8}, //end
				},
			}},
		{}, {5, 6, 8});
	Negotiations->enemies = {
		{'A',
			{
				{battledroid_en, 0x414C},
				{battledroid_en, 0x41F1},
				{battledroid_en, 0x4296},
				{battledroid_en, 0x434B},
				{battledroid_security_en, 0x456A},
				{battledroid_security_en, 0x460F},
				{battledroid_security_en, 0x46B4},
				{battledroid_security_en, 0x4759},
				{battledroid_en, 0x47FE},
				{battledroid_en, 0x48B3},
				{battledroid_en, 0x4968},
				{battledroid_en, 0x4A1D},
				{battledroid_en, 0x4AD2},
				{battledroid_en, 0x4B87},
				{battledroid_security_en, 0x4C3C},
				{battledroid_security_en, 0x4CE1},
				{battledroid_security_en, 0x4D86},
				{battledroid_security_en, 0x4E2B},
				{battledroid_security_en, 0x4ED0},
				{battledroid_en, 0x4F85},

				{battledroid_en, "LEVEL2", {30, 77}},
				{battledroid_en, "LEVEL2", {31, 77}},
				{battledroid_en, "LEVEL2", {32, 77}},
				{battledroid_en, "LEVEL2", {33, 77}},
				{battledroid_en, "LEVEL2", {34, 77}},
				{battledroid_en, "LEVEL2", {35, 77}},
				{battledroid_en, "LEVEL2", {87, 73}},
				{battledroid_en, "LEVEL2", {101, 73}},
				{battledroid_en, "LEVEL2", {115, 73}},
				{battledroid_en, "LEVEL2", {129, 77}},
			}},
		{'B',
			{
				{battledroid_security_en, 0xBA8},
				{battledroid_security_en, 0xC48},
				{battledroid_security_en, 0xCE8},
				{battledroid_security_en, 0xD88},
			}},
		{'C',
			{
				{battledroid_en, 0x30FF},
				{battledroid_en, 0x31B4},
				{battledroid_en, 0x3269},
				{battledroid_en, 0x330E},
				{battledroid_en, 0x33B3},
				{battledroid_en, 0x3458},
				{battledroid_en, 0x34FD},
				{battledroid_en, 0x35A2},
				{destroyer_en, 0x3647},
				{destroyer_en, 0x36FC},
				{battledroid_en, 0x38FB},
				{battledroid_en, 0x39A0},
				{battledroid_en, 0x3A45},
				{battledroid_en, 0x3AEA},
				{battledroid_en, 0x3B8F},
				{battledroid_en, 0x3C34},
				{battledroid_en, 0x3CD9},
				{battledroid_en, 0x3D7E},
				{battledroid_en, 0x3E23},
				{battledroid_en, 0x3EC8},
			}},
	};
	//Negotiations->enemies = Enemies(
	//	{
	//		{'A', chatting, "DOORATTACK", "NormalUpdate", {0x456a, 0x460f, 0x46b4, 0x4759},
	//			func("NormalUpdate", "", "GoToOrigin \"waittime=10\""), {30, 19}},
	//
	//		{'A', chatting, "DEACTIVATED", "NormalUpdate", {0x4c3c, 0x4ce1, 0x4d86, 0x4e2b},
	//			func("NormalUpdate", "", "GoToOrigin \"waittime=10\""), {38, 19}},
	//
	//		{'A', chatting, "VENTDROID", "NormalUpdate", {0x4ed0},
	//			func("NormalUpdate", "", "GoToOrigin \"waittime=10\""), {30, 19}},
	//
	//		{'B', attack, "LAZYDROID", "Attack", {0xBA8, 0xC48, 0xCE8, 0xD88}, func("Attack", "", ""), {31, 13}},
	//		{'C', chatting, "MTT_DROID", "Update",
	//			{0x39A0, 0x3A45, 0x3AEA, 0x3B8F, 0x3C34, 0x3CD9, 0x3D7E, 0x3E23, 0x3EC8},
	//			func("Update", "", "GoToOrigin \"waittime=10\""), {31, 13}},
	//		{'C', "DROIDEKA", "Engage", {0x3647, 0x37fc}, 90, retreat("Guard") "\n\t\t" outOfRange("3", "Guard"), ""},
	//	},
	//
	//	{
	//		{'A',
	//			{
	//				{chatting, 0x414c},
	//				{chatting, 0x41f1},
	//				{chatting, 0x4296},
	//				{chatting, 0x434b},
	//				{chatting, 0x434B},
	//				{chatting, 0x48B3},
	//				{chatting, 0x4968},
	//				{chatting, 0x4A1D},
	//				{chatting, 0x4AD2},
	//				{chatting, 0x4B87},
	//				{chatting, 0x4F85},
	//			}},
	//		{'C',
	//			{
	//				{chatting, 0x3269},
	//				{chatting, 0x330E},
	//				{chatting, 0x33B3},
	//				{chatting, 0x3458},
	//				{chatting, 0x34FD},
	//				{chatting, 0x35A2},
	//				{sniper, 0x38FB},
	//				{patrol, 0x30FF},
	//				{patrol, 0x31B4},
	//			}},
	//	},
	//	{}, {5, 6, 7, 8});

	Invasion = new Level("GUNGAN", "GUNGAN", "/LEVELS/EPISODE_I/GUNGAN/", false,
		{quigonjinn, obiwankenobi, jarjarbinks}, {}, {jarjarbinks, captaintarpals, bossnass},
		{{'A', {0x3665, 0x364e, 0x3637, 0x325a, 0x3243, 0x322c, 0x3215, 0x31fe}},
			{'B', {0x1acc, 0x1ab5, 0x1a9e, 0x1a14, 0x1790}}, {'C', {0x214d, 0x2136, 0x211f, 0x1965, 0x194e, 0x1937}},
			{'E', {0xab7, 0x9e8}}},
		{},

		{
			{'B', {{BountyPanel, 0x1C01}}}, //rb
		},
		{}, {7});
	Invasion->enemies = {
		{'A',
			{
				{battledroid_en, 0x1722},
				{battledroid_en, 0x17F7},
			}},
		{'B',
			{
				{battledroid_en, 0x2303},
				{battledroid_en, 0x23A8},
				{battledroid_en, 0x245D},
				{battledroid_en, 0x2512},
				{battledroid_en, 0x25B7},
			}},
		{'C',
			{
				{battledroid_en, 0x4580},
				{battledroid_en, 0x4625},
				{battledroid_en, 0x46CA},
				{battledroid_en, 0x476F},
				{battledroid_en, 0x4814},
				{battledroid_en, 0x48B9},
				{battledroid_en, 0x495E},
				{battledroid_en, 0x4A03},
				{battledroid_en, 0x4AA8},
				{battledroid_en, 0x4B4D},

				{battledroid_en, "LEVEL1", {27, 77}},
				{battledroid_en, "LEVEL1", {28, 77}},
			}},
		{'E',
			{
				{battledroid_en, 0x864},
				{battledroid_en, 0x919},
				{battledroid_en, 0x9CE},
				{battledroid_en, 0xA83},
				{battledroid_en, 0xBED},
			}},
	};

	//Invasion->enemies = Enemies(
	//	{
	//		//{'A', storm, "storm", "STORM", "Approach", {0x1722, 0x17F7}, 37, retreat("Approach"),
	//		//normalAttack},
	//		{'A', "STORM", "Approach", {0x1722, 0x17F7}, 27, "", ""},
	//
	////PUT THIS BACK IN
	//		//{'E', "BATTLEDROID", "Attack", {0x864, 0x1919, 0x9CE, 0xA83}, 88,
	//		//	scpFun("Attack", retreat("update") "\n\t\t" outOfRange("Update", "2"), ""), ""}, //??????
	//		{'E', "STORM", "Approach", {0xBED}, 28, underCover("Base"), ""},
	//	},
	//	{{'B',
	//		 {
	//			 {sniper, 0x2303},
	//			 {storm, 0x23A8},
	//			 {storm, 0x245D},
	//			 {chatting, 0x2512},
	//			 {chatting, 0x25B7},
	//		 }},
	//		{'C',
	//			{
	//				{chatting, 0x44DB},
	//				{chatting, 0x4580},
	//				{chatting, 0x4625},
	//				{chatting, 0x46CA},
	//				{chatting, 0x476F},
	//				{chatting, 0x4814},
	//				{chatting, 0x48B9},
	//				{chatting, 0x495E},
	//				{chatting, 0x4A03},
	//				{chatting, 0x4AA8},
	//				{chatting, 0x4B4D},
	//			}}},
	//	{}, {7});

	EscapeNaboo = new Level("PALACERESCUE", "RESCUE", "/LEVELS/EPISODE_I/PALACERESCUE/", false,
		{amidala, captainpanaka, quigonjinn, obiwankenobi}, {}, {amidala, captainpanaka, royalguard, padme},
		{{'A', {0x8153, 0x813c, 0x8125, 0x810e, 0x7cd5, 0x7cbe}}, {'B', {0x559c, 0x5585, 0x5232, 0x521b, 0x5204}},
			{'C', {0x681d, 0x6806, 0x67ef, 0x67d8, 0x67c1, 0x67aa}}, {'E', {0x343b, 0x3424, 0x33f6, 0x33df}}},
		{}, {}, {}, {7, 8, 9});
	EscapeNaboo->enemies = {
		{'A',
			{
				{battledroid_en, 0x2FC3},
				{battledroid_en, 0x3068},
				{battledroid_en, 0x310D},
				{battledroid_en, 0x331C},
				{battledroid_en, 0x33C1},
				{battledroid_en, 0x3466},
				{battledroid_en, 0x350B},
				{battledroid_en, 0x35B0},
				{battledroid_en, 0x3655},
				{battledroid_en, 0x36FA},
				{battledroid_en, 0x379F},
				{battledroid_en, 0x3844},
				{battledroid_en, 0x38F9},
				{battledroid_en, 0x39AE},
				{battledroid_en, 0x3A63},
				{battledroid_en, 0x3B18},
				{battledroid_en, 0x3BBD},
				{battledroid_en, 0x3C72},
				{battledroid_en, 0x3D27},
			}},
		{'B',
			{
				{battledroid_en, 0x43A7},
				{battledroid_en, 0x445C},
				{battledroid_en, 0x4511},
				{battledroid_en, 0x45C6},
				{battledroid_en, 0x467B},
				{battledroid_en, 0x4720},
				{battledroid_en, 0x47C5},
				{battledroid_en, 0x486A},
				{battledroid_en, 0x490F},
				{destroyer_en, 0x49B4},
				{destroyer_en, 0x4A59},
				{battledroid_en, 0x4AFE},
				{battledroid_en, 0x4BA3},
				{battledroid_en, 0x4C48},
				{battledroid_en, 0x4CED},
				{battledroid_en, 0x4D92},
			}},
		{'C',
			{
				{battledroid_en, 0x9E28},
				{battledroid_en, 0x9ECD},
				{battledroid_en, 0x9F72},
				{battledroid_en, 0xA017},
				{battledroid_en, 0xA0BC},
				{battledroid_en, 0xA161},
				{battledroid_en, 0xA206},
				{battledroid_commander_en, 0xA2AB},
				{battledroid_commander_en, 0xA350},
				{battledroid_en, 0xA3F5},
				{battledroid_en, 0xA4AA},
				{battledroid_en, 0xA54F},
				{battledroid_en, 0xA5F4},
				{battledroid_en, 0xA699},

				{battledroid_en, "LEVEL1", {32, 77}},
				{battledroid_en, "LEVEL1", {33, 77}},
				{battledroid_en, "LEVEL1", {71, 77}},
			}},
		{'E',
			{
				{battledroid_en, 0x403E},
				{battledroid_en, 0x40E3},
				{battledroid_en, 0x4188},
				{battledroid_en, 0x422D},
				{battledroid_en, 0x42D2},
				{battledroid_en, 0x4377},
				{battledroid_en, 0x441C},
				{battledroid_en, 0x44C1},
				{battledroid_en, 0x4566},
			}},
	};
	//EscapeNaboo->enemies = Enemies({},
	//	{
	//		{'A',
	//			{
	//				{chatting, 0x3068},
	//				{chatting, 0x310D},
	//				{chatting, 0x331C},
	//				{sniper, 0x33C1},
	//				{sniper, 0x3466},
	//				{sniper, 0x350B},
	//				{block, 0x35B0},
	//				{block, 0x3655},
	//				{patrol, 0x36FA},
	//				{patrol, 0x379F},
	//				{storm, 0x3844},
	//				{storm, 0x38F9},
	//				{storm, 0x39AE},
	//				{storm, 0x3A63},
	//				{patrol, 0x3B18},
	//				{storm, 0x3BC9},
	//				{storm, 0x3C72},
	//				{storm, 0x3D27},
	//			}},
	//		{'B',
	//			{
	//				{storm, 0x43A7},
	//				{storm, 0x445C},
	//				{storm, 0x4511},
	//				{storm, 0x45C6},
	//				{chatting, 0x467B},
	//				{chatting, 0x4720},
	//				{chatting, 0x47C5},
	//				{sniper, 0x486A},
	//				{sniper, 0x490F},
	//				{chatting, 0x49B4},
	//				{chatting, 0x4A59},
	//				{chatting, 0x4AFE},
	//				{chatting, 0x4BA3},
	//				{chatting, 0x4C48},
	//				{chatting, 0x4CED},
	//				{chatting, 0x4D92},
	//			}},
	//		{'C',
	//			{
	//				{chatting, 0x9E28},
	//				{chatting, 0x9ECD},
	//				{chatting, 0x9F72},
	//				{chatting, 0xA017},
	//				{chatting, 0xA0BC},
	//				{chatting, 0xA161},
	//				{chatting, 0xA206},
	//				{block, 0xA2AB},
	//				{block, 0xA350},
	//				{storm, 0xA3F5},
	//				{chatting, 0xA4AA},
	//				{chatting, 0xA54F},
	//				{block, 0xA5F4},
	//				{chatting, 0xA699},
	//			}},
	//		{'E',
	//			{
	//				{chatting, 0x403E},
	//				{chatting, 0x40E3},
	//				{chatting, 0x4188},
	//				{chatting, 0x422D},
	//				{chatting, 0x42D2},
	//				{chatting, 0x4377},
	//				{patrol, 0x441C},
	//				{patrol, 0x44C1},
	//				{patrol, 0x4566},
	//
	//			}},
	//	},
	//	{}, {7, 8, 9});

	Podrace = new Level("PODSPRINT", "PODSPRINT", "/LEVELS/EPISODE_I/PODSPRINT/", true,
		{newanakinspod, newanakinspod_green}, {}, {watto, pitdroid, newanakinspod, newanakinspod_green, sebulbaspod},
		{{'A', {0x52d4, 0x52bd, 0x52a6, 0x528f, 0x5278, 0x5261, 0x524a, 0x5233, 0x521c, 0x5205, 0x51ee, 0x51c0, 0x51a9,
				   0x5192, 0x517b, 0x5164, 0x514d, 0x5136, 0x511f, 0x5108, 0x50f1}}},
		{}, {}, {});

	Theed = new Level("RETAKEPALACE", "RETAKE", "/LEVELS/EPISODE_I/RETAKEPALACE/", false,
		{obiwankenobi, quigonjinn, captainpanaka, padmebattle, r2d2, anakin_boy}, {}, {padmebattle, r2d2, anakin_boy},
		{{'A', {0x36fc, 0x36e5, 0x3689, 0x3672}}, {'B', {0x61be, 0x61a7, 0x6190, 0x6179}},
			{'D', {0x5abb, 0x5aa4, 0x5a8d, 0x559c, 0x48ac}}, {'E', {0x3799, 0x327a}}, {'F', {0x5f5c, 0x5f45, 0x5f2e}},
			{'G', {0x3473, 0x345c, 0x2938}}},
		{},

		{{'A', {{AstroPanel, 0x38BC}}}, {'B', {{AstroPanel, 0x62FE}}}, {'G', {{AstroPanel, 0x35F6}}}}, {},
		{9, 10, 11, 12});
	Theed->enemies = {
		{'A',
			{
				{destroyer_en, 0x2FF9},
				{destroyer_en, 0x30AE},
				{battledroid_en, 0x3163},
				{battledroid_en, 0x3208},
				{battledroid_en, 0x32AD},
				{battledroid_en, 0x3352},
				{battledroid_en, 0x33F7},
				{battledroid_en, 0x349C},
				{battledroid_en, 0x3551},
				{battledroid_en, 0x3606},
				{battledroid_en, 0x36AB},
				{battledroid_en, 0x3750},
			}},
		{'B',
			{
				{battledroid_en, 0x2995},
				{destroyer_en, 0x2A4A},
				{battledroid_en, 0x2AFF},
				{battledroid_en, 0x2BB4},
				{battledroid_en, 0x2C59},
				{battledroid_en, 0x2CFE},
				{battledroid_en, 0x2DA3},
				{battledroid_en, 0x2E48},
				{battledroid_en, 0x2EED},
				{battledroid_en, 0x2FA2},
				{battledroid_en, 0x3047},
				{battledroid_en, 0x30FC},
				{battledroid_en, 0x31B1},
				{battledroid_commander_en, 0x3266},
				{battledroid_commander_en, 0x331B},
				{battledroid_en, 0x33D0},
			}},
		{'D',
			{
				{battledroid_commander_en, 0x16615},
				{battledroid_en, 0x166CA},
				{battledroid_en, 0x1677F},
				{battledroid_en, 0x16834},
				{battledroid_en, 0x168E9},
				{battledroid_en, 0x1698E},
				{battledroid_en, 0x16A33},
				{battledroid_en, 0x16AD8},
				{battledroid_en, 0x16B8D},
				{battledroid_commander_en, 0x16C42},
				{battledroid_en, 0x16CF7},
				{battledroid_en, 0x16DAC},
				{battledroid_commander_en, 0x16E61},
				{battledroid_en, 0x16F16},
			}},
		{'E',
			{
				{battledroid_en, 0x6231},
				{battledroid_en, 0x62D6},
				{battledroid_en, 0x637B},
				{battledroid_en, 0x6420},
				{battledroid_en, 0x64C5},
			}},
		{'F',
			{
				{destroyer_en, 0x16C6},
				{battledroid_en, 0x177B},
				{battledroid_en, 0x1820},
				{battledroid_en, 0x18C5},
				{battledroid_en, 0x196A},
				{battledroid_en, 0x1A0F},
				{battledroid_en, 0x1AB4},
				{destroyer_en, 0x1B69},
				{destroyer_en, 0x1C1E},
				{battledroid_commander_en, 0x1CD3},
			}},
		{'G',
			{
				{destroyer_en, 0x8E36},
				{battledroid_en, 0x8EEB},
				{battledroid_commander_en, 0x8FA0},
				{battledroid_en, 0x9055},
				{destroyer_en, 0x910A},
				{battledroid_en, 0x91BF},
				{battledroid_commander_en, 0x9274},
				{battledroid_en, 0x9329},
				{destroyer_en, 0x93DE},
				{battledroid_en, 0x9493},
				{battledroid_commander_en, 0x9538},
				{battledroid_security_en, 0x95DD},
				{battledroid_security_en, 0x9682},
				{battledroid_security_en, 0x9727},
				{battledroid_security_en, 0x97CC},
				{battledroid_security_en, 0x9871},
			}},
	};

	//Theed->enemies = Enemies(
	//	{
	//		SpecialScp{'F', "HIDDENDROIDS", "Fight", {0x177B, 0x1820}, 20, "", ""},
	//		SpecialScp{'F', "HIDDENDECKA", "Approach", {0x16C6, 0x1C1E}, 33, "", ""},
	//		SpecialScp{'G', "DROIDS1", "Approach", {0x8E36, 0x8EEB, 0x8FA0, 0x9055, 0x910A}, 31, "", ""},
	//		SpecialScp{'G', "DROIDS2", "Approach", {0x91BF, 0x9274, 0x9329, 0x93DE}, 30, "", ""},
	//		SpecialScp{'G', "BLOCK", "Engage", {0x95DD, 0x9682, 0x9727, 0x97CC, 0x9871}, 17,
	//			"if GotOpponent == 0 goto Base\n\t\tif OpponentRange > shootrange goto Base", ""},
	//	},
	//	{
	//		{'A',
	//			{
	//				{attack, 0x2FF9},
	//				{attack, 0x30AE},
	//				{patrol, 0x3163},
	//				{sniper, 0x3208},
	//				{sniper, 0x32AD},
	//				{sniper, 0x3352},
	//				{sniper, 0x33F7},
	//				{storm, 0x349C},
	//				{storm, 0x3551},
	//				{sniper, 0x3606},
	//				{sniper, 0x36AB},
	//				{sniper, 0x3750},
	//
	//			}},
	//		{'B',
	//			{
	//				{storm, 0x2995},
	//				{storm, 0x2A4A},
	//				{storm, 0x2AFF},
	//				{attack, 0x2BB4},
	//				{attack, 0x2C59},
	//				{attack, 0x2CFE},
	//				{attack, 0x2DA3},
	//				{attack, 0x2E48},
	//				{storm, 0x2EED},
	//				{sniper, 0x2FA2},
	//				{storm, 0x3047},
	//				{storm, 0x30FC},
	//				{storm, 0x31B1},
	//				{storm, 0x3266},
	//				{storm, 0x331B},
	//				{sniper, 0x33D0},
	//
	//			}},
	//		{'D',
	//			{
	//				{storm, 0x16615},
	//				{storm, 0x166CA},
	//				{storm, 0x1677F},
	//				{storm, 0x16834},
	//				{sniper, 0x168E9},
	//				{sniper, 0x1698E},
	//				{sniper, 0x16A33},
	//				{storm, 0x16AD8},
	//				{storm, 0x16B8D},
	//				{storm, 0x16C42},
	//				{storm, 0x16CF7},
	//				{storm, 0x16DAC},
	//				{storm, 0x16E61},
	//				{patrol, 0x16F16},
	//
	//			}},
	//		{'E',
	//			{
	//				{attack, 0x62D6},
	//				{attack, 0x637B},
	//				{attack, 0x6420},
	//				{attack, 0x64C5},
	//
	//			}},
	//		{'F',
	//			{
	//				{attack, 0x18C5},
	//				{attack, 0x196A},
	//				{patrol, 0x1A0F},
	//				{storm, 0x1AB4},
	//				{block, 0x1B69},
	//				{storm, 0x1CD3},
	//
	//			}},
	//		{'G',
	//			{
	//				{attack, 0x9493},
	//				{attack, 0x9538},
	//
	//			}},
	//	},
	//	{}, {9, 10, 11, 12});

	Maul = new Level("MAUL", "MAUL", "/LEVELS/EPISODE_I/MAUL/", false, {obiwankenobi, quigonjinn}, {}, {darthmaul},
		{{'A', {0x2e7c, 0x2e65, 0x2be1, 0x2bca}}, {'B', {0x2a4e, 0x2a37, 0x2a20, 0x2757, 0x2740, 0x2449, 0x1531}},
			{'D', {0x1a95, 0x1a67, 0x1a50, 0x1a39, 0x193c}}, {'E', {0x18bc}}, {'F', {0xe76, 0xe1a, 0xe03, 0xdec}}},
		{}, {{'A', {{ImperialPanel, 0x2F44}}}, {'D', {{ProtoPanel, 0x1C1F}, {ImperialPanel, 0x1C4E}}}}, {}, {5, 6, 7});
	Maul->enemies = {
		{'A',
			{
				{battledroid_en, 0x2763},
				{battledroid_en, 0x2808},
				{battledroid_en, 0x28AD},
				{battledroid_en, 0x2952},

				{battledroid_en, "DARTHMAUL", {63, 42}},
				{battledroid_en, "DARTHMAUL", {64, 42}},
				{battledroid_en, "DARTHMAUL", {65, 42}},
				{battledroid_en, "DARTHMAUL", {66, 42}},
			}},
		{'B',
			{
				{battledroid_en, 0x63B3},
				{battledroid_en, 0x6478},
				{battledroid_en, 0x653D},
				{battledroid_en, 0x65F2},
				{destroyer_en, 0x66A7},
				{destroyer_en, 0x675C},
				{battledroid_en, 0x6811},
				{battledroid_en, 0x68C6},
			}},
		{'D',
			{
				{battledroid_en, "COMMANDER_LEFT", {10, 85}},
				{battledroid_en, "COMMANDER_LEFT", {12, 85}},
				{battledroid_en, "COMMANDER_LEFT", {14, 85}},
				{battledroid_en, "COMMANDER_LEFT", {16, 85}},
				{battledroid_commander_en, "COMMANDER_LEFT", {18, 51}},
				{battledroid_en, "COMMANDER_LEFT", {67, 169}},

				{battledroid_en, "COMMANDER_RIGHT", {10, 85}},
				{battledroid_en, "COMMANDER_RIGHT", {12, 85}},
				{battledroid_en, "COMMANDER_RIGHT", {14, 85}},
				{battledroid_en, "COMMANDER_RIGHT", {16, 85}},
				{battledroid_en, "COMMANDER_RIGHT", {66, 174}},

				{battledroid_commander_en, "LEVEL", {52, 50}},
				{destroyer_en, "LEVEL", {83, 49}},
				{destroyer_en, "LEVEL", {84, 50}},
			}},
	};

	//Maul->enemies = Enemies({{'A', "LEFTDRAWER", "Attack", {0x2763, 0x2808}, 17, "", ""},
	//							{'A', "RIGHTDRAWER", "Attack", {0x28AD, 0x2952}, 17, "", ""},
	//							{'B', "BONUSLEFT", "Chase", {0x653D, 0x65F2, 0x66A7}, 30, "", ""},
	//							{'B', "BONUSRIGHT", "Chase", {0x675C, 0x6811, 0x68C6}, 30, "", ""},
	//							{'D', "ATTACK", "Approach", {}, 18, "", ""},
	//
	//							SpecialScp{'D', "COMMANDER_LEFT", "Defend", {}, 41,
	//								retreat("Update") "\n\t\t" outOfRange(
	//									"Update", "3") "\n\t\t"
	//												   "if EtherPlayaerInTriggerArea \"Left\" == 1 and\n\t\tif "
	//												   "NumBaddies < 11 goto CallTroops"
	//												   "\n\t\t"
	//												   "if EtherPlayaerInTriggerArea \"Right\" == 0 and\n\t\tif "
	//												   "NumBaddies < 11 goto CallTroops",
	//								"", {DoubleNestedEnemy{"LEVEL", {52, 50}, battledroid_commander}}},
	//
	//							SpecialScp{'D', "COMMANDER_RIGHT", "Defend", {}, 40,
	//								retreat("Update") "\n\t\t" outOfRange(
	//									"Update", "3") "\n\t\t"
	//												   "if EtherPlayaerInTriggerArea \"Right\" == 1 and\n\t\tif "
	//												   "NumBaddies < 11 goto CallTroops"
	//												   "\n\t\t"
	//												   "if EtherPlayaerInTriggerArea \"Left\" == 0 and\n\t\tif "
	//												   "NumBaddies < 11 goto CallTroops",
	//								"", {DoubleNestedEnemy{"COMMANDER_LEFT", {18, 51}, battledroid_commander}}},
	//
	//							{'D', "DROIDEKA", "Guard", {}, 14, "", "",
	//								{{"LEVEL", {83, 49}, destroyer}, {"LEVEL", {84, 50}, destroyer}}},
	//							{'A', "MAULDROID", "Approach", {}, 65, "", "",
	//								{
	//									{"DARTHMAUL", {63, 42}, battledroid},
	//									{"DARTHMAUL", {64, 42}, battledroid},
	//									{"DARTHMAUL", {65, 42}, battledroid},
	//									{"DARTHMAUL", {66, 42}, battledroid},
	//								}}},
	//	{
	//		{'B',
	//			{
	//				{storm, 0x63B3},
	//				{storm, 0x6478},
	//			}},
	//	},
	//	{
	//		{
	//			'D',
	//			"COMMANDER_LEFT",
	//			{
	//				NestedEnemy{NONE, {10, 85}, {10, 106}, battledroid, 6, 4},
	//				NestedEnemy{NONE, {12, 85}, {12, 106}, battledroid, 6, 4},
	//				NestedEnemy{NONE, {14, 85}, {14, 106}, battledroid, 6, 4},
	//				NestedEnemy{NONE, {16, 85}, {16, 106}, battledroid, 6, 4},
	//				//NestedEnemy{NONE, {18, 51}, {18, 82}, battledroid_commander, 15, 6},
	//				NestedEnemy{NONE, {67, 169}, {67, 191}, battledroid, 6, 4},
	//			},
	//		},
	//		{
	//			'D',
	//			"COMMANDER_RIGHT",
	//			{
	//				NestedEnemy{NONE, {10, 86}, {10, 107}, battledroid, 6, 4},
	//				NestedEnemy{NONE, {12, 86}, {12, 107}, battledroid, 6, 4},
	//				NestedEnemy{NONE, {14, 86}, {14, 107}, battledroid, 6, 4},
	//				NestedEnemy{NONE, {16, 86}, {16, 107}, battledroid, 6, 4},
	//				NestedEnemy{NONE, {66, 174}, {66, 195}, battledroid, 6, 4},
	//			},
	//		},
	//	},
	//	{5, 6, 7});

	BHP = new Level("PURSUIT", "PURSUIT", "/LEVELS/EPISODE_II/PURSUIT/", true, {anakinsspeeder, anakinsspeeder_green},
		{}, {zamwesell, dexter, anakinsspeeder, anakinsspeeder_green, zamsspeeder},
		{{'A', {0x58b2, 0x589b, 0x5884, 0x586d, 0x5856, 0x5759}}, {'B', {0x1251, 0x123a}},
			{'C', {0x4379, 0x4362, 0x434b, 0x4334, 0x431d, 0x4293, 0x4220}}, {'D', {0x26aa, 0x2693}}},

		{{'A', {0x583f, 0x5828, 0x5811, 0x57fa, 0x57e3}},                                              //Stupid Minikit
			{'A', {0x57cc, 0x57b5, 0x579e, 0x5787, 0x5770}},                                           //Turrets 1
			{'C', {0x4306, 0x42ef, 0x42d8, 0x42c1, 0x42aa}},                                           //Turrets 2
			{{'A', 0x5742}, {'A', 0x572b}, {'A', 0x5714}, {'A', 0x56fd}, {'A', 0x56e6}, {'A', 0x56cf}, //Baners pt. 1
				{'C', 0x427c}, {'C', 0x4265}, {'C', 0x424e}, {'C', 0x4237}}},
		{}, {}); //Banners pt. 2

	Kamino = new Level("KAMINO", "KAMINO", "/LEVELS/EPISODE_II/KAMINO/", false, {obiwankenobi_jedimaster, r4_p17}, {},
		{obiwankenobi_jedimaster, r4_p17, clone_ep2, lamasu, taunwe},
		{{'A', {0x1f52, 0x1f3b, 0x1781, 0x1542}}, {'C', {0x3ce1, 0x3cca, 0x3bfb, 0x3be4, 0x3bcd}},
			{'D', {0x51dc, 0x51c5, 0x51ae, 0x5055, 0x503e, 0x5027}}, {'E', {0x315a, 0x2e63}},
			{'F', {0x2235, 0x221e, 0x2024, 0x200d}}},
		{},

		{{'A', {{AstroPanel, 0x206E}}},                                                   //closet
			{'C', {{AstroPanel, 0x3F4B}, {AstroPanel, 0x3F7C}, {ImperialPanel, 0x3FAD}}}, //bonus
			{'D', {{BountyPanel, 0x5337},                                                 //bonus room
					  {AstroPanel, 0x5365}}},                                             //room 3 end hallway
			{'E',
				{{AstroPanel, 0x3565}, {AstroPanel, 0x3594}, //stop droids
					{AstroPanel, 0x35C3},                    //last story
					{AstroPanel, 0x35F2}, {AstroPanel, 0x3621}, {AstroPanel, 0x3650}, {AstroPanel, 0x367F}}}, //turrets
			{'F', {{AstroPanel, 0x233A}, //outside to elevator
					  {ProtoPanel, 0x2368}}}},
		{}, {9});
	Kamino->enemies = {
		{'C',
			{
				{kaminodroid_en, 0x1C54},
				{kaminodroid_en, 0x1CF9},
				{kaminodroid_en, 0x1D9E},
				{kaminodroid_en, 0x1F8D},
				{kaminodroid_en, 0x2032},
				{kaminodroid_en, 0x20D7},
				{kaminodroid_en, 0x217C},
				{kaminodroid_en, 0x2221},
				{kaminodroid_en, 0x22C6},
			}},
		{'E',
			{
				{kaminodroid_en, 0x170B},
				{kaminodroid_en, 0x17B0},
				{kaminodroid_en, 0x1855},
				{kaminodroid_en, 0x18FA},
				{kaminodroid_en, 0x199F},
				{kaminodroid_en, 0x1A44},

				{kaminodroid_en, "LEVEL", {71, 59}},
				{kaminodroid_en, "LEVEL", {81, 60}},
			}},
		{'F',
			{
				{kaminodroid_en, "LEVEL1", {32, 77}},
				{kaminodroid_en, "LEVEL1", {33, 77}},
				{kaminodroid_en, "LEVEL1", {71, 77}},
			}},
	};
	//Kamino->enemies = Enemies(
	//	{
	//		{'C', "KAMINODROID", "Approach", {0x1C54, 0x1CF9, 0x1D9E, 0x1F8D, 0x2032}, 32, "", ""},
	//		{'C', "KAMINODROID_FP", "Approach", {0x20D7, 0x217C, 0x2221, 0x22C6}, 35, "", ""},
	//		{'E', "ATTACK", "Wander", {}, 19, "if Message \"JangoFight\" > 0 goto Kill", "",
	//			{
	//				DoubleNestedEnemy{"LEVEL", {71, 59}, kaminodroid},
	//				DoubleNestedEnemy{"LEVEL", {81, 60}, kaminodroid},
	//			}},
	//		{'E', "BONUSDROID", "Approach", {0x170B, 0x17B0, 0x1855, 0x18FA, 0x199F, 0x1A44}, 30, "", ""},
	//	},
	//	{}, {}, {9});

	Factory =
		new Level("FACTORY", "FACTORY", "/LEVELS/EPISODE_II/FACTORY/", false, {anakin_padawan, padmegeo, r2d2, c3po},
			{obiwankenobi_jedimaster}, {anakin_padawan, padmegeo, c3po, geonosian, battledroid_geonosian, skeleton},
			{{'A', {0xB33, 0xb1c, 0x825}}, {'B', {0x2f68, 0x2f51, 0x2f3a, 0x280a, 0x27f3}},
				{'D', {0x184e, 0x1837, 0x12bc, 0x12a5}}, {'E', {0xf93, 0xc9c}},
				{'F', {0x1c47, 0x1c30, 0x1c19, 0x1265, 0x124e, 0x1a4d}}, {'G', {0x1531}}},
			{},

			{{'B', {{AstroPanel, 0x311B}, {ImperialPanel, 0x31D7}, {AstroPanel, 0x314A}, {AstroPanel, 0x317A},
					   {AstroPanel, 0x31A9}}},                       //color
																	 //matching
				{'D', {{AstroPanel, 0x1A8C}, {AstroPanel, 0x1ABB}}}, //story
				{'E', {{ProtoPanel, 0x1191}}},                       //story
				{'F', {{AstroPanel, 0x1E49},                         //bridge
						  {ProtoPanel, 0x1E78},                      //end
						  {AstroPanel, 0x1EA7}, {AstroPanel, 0x1ED6}, {AstroPanel, 0x1F05}, {AstroPanel, 0x1F34}}}, //rb
				{'G', {{AstroPanel, 0x1B18},       //left, bonus
						  {AstroPanel, 0x1B47}}}}, //right, story

			{}, {6, 7, 8, 9});
	Factory->enemies = {
		{'A',
			{
				{geonosian_en, 0x1248},
				{geonosian_en, 0x12F8},
				{geonosian_en, 0x13A8},
				{geonosian_en, 0x1458},
				{geonosian_en, 0x1508},
				{geonosian_en, 0x15B8},
				{geonosian_en, 0x1668},
				{geonosian_en, 0x1718},
				{geonosian_en, 0x17C8},
			}},
		{'B',
			{
				{battledroid_geonosian_en, 0x2F8E},
				{battledroid_geonosian_en, 0x3033},
				{destroyer_en, 0x30D8},
				{battledroid_geonosian_en, 0x317D},
			}},
		{'D',
			{
				{battledroid_geonosian_en, 0x5781},
				{battledroid_geonosian_en, 0x5821},
				{battledroid_geonosian_en, 0x58C1},
				{battledroid_geonosian_en, 0x5961},
				{destroyer_en, 0x5A01},
			}},
		{'E',
			{
				{geonosian_en, 0x4D58},
				{geonosian_en, 0x4E0D},
				{geonosian_en, 0x4ED2},
				{geonosian_en, 0x4F97},
				{geonosian_en, 0x505C},
				{geonosian_en, 0x5121},
				{geonosian_en, 0x51E6},
				{geonosian_en, 0x52AB},
				{geonosian_en, 0x5360},
				{geonosian_en, 0x5425},
				{geonosian_en, 0x54EA},
				{geonosian_en, 0x55AF},
				{geonosian_en, 0x5674},
				{geonosian_en, 0x5739},
				{geonosian_en, 0x57EE},
				{destroyer_en, 0x58B3},
				{destroyer_en, 0x5958},
			}},
		{'F',
			{
				{geonosian_en, "LEVEL1", {32, 77}},
				{geonosian_en, "LEVEL1", {33, 77}},
				{geonosian_en, "LEVEL1", {71, 77}},
			}},
		{'G',
			{
				{destroyer_en, 0xA12},
				{geonosian_en, 0xAB2},
				{geonosian_en, 0xB52},
				{geonosian_en, 0xC02},
				{geonosian_en, 0xCC2},
				{battledroid_commander_en, 0xD82},
			}},
	};
	//Factory->enemies = Enemies(
	//	{
	//		{'A', "GEONOSIAN", "Approach", {0x1248, 0x12F8, 0x13A8, 0x1458, 0x1508, 0x15B8, 0x1668, 0x1718, 0x17C8}, 26,
	//			"", ""},
	//		{'F', "GEONOSIAN", "Approach",
	//			{0x4D58, 0x4E0D, 0x4ED2, 0x4F97, 0x505C, 0x5121, 0x51E6, 0x52AB, 0x5360, 0x5425, 0x54EA, 0x55AF, 0x5674,
	//				0x5739, 0x57EE},
	//			24, "", ""},
	//	},
	//	{{'B',
	//		 {
	//			 {block, 0x3033},
	//			 {block, 0x30D8},
	//			 {storm, 0x317D},
	//		 }},
	//		{'D',
	//			{
	//				{sniper, 0x5781},
	//				{sniper, 0x5821},
	//				{sniper, 0x58C1},
	//				{sniper, 0x5961},
	//				{block, 0x5A01},
	//
	//			}},
	//		{'F',
	//			{
	//				{block, 0x58B3},
	//				{block, 0x5958},
	//			}},
	//		{'G',
	//			{
	//				{block, 0xA12},
	//				{block, 0xAB2},
	//				{storm, 0xB52},
	//				{storm, 0xC02},
	//				{storm, 0xCC2},
	//				{storm, 0xD82},
	//			}}},
	//	{}, {6, 7, 8, 9});

	//Do this later
	JediBattle = new Level("JEDI", "JEDI", "/LEVELS/EPISODE_II/JEDI/", false,
		{macewindu, r2d2, obiwankenobi_jedimaster, anakin_padawan, padmeclawed}, {},
		{macewindu, padmeclawed, superbattledroid, jangofett, bobafett_boy, luminara, kiadimundi, kitfisto, shaakti,
			aylasecura, plokoon},
		{{'B', {0x5099, 0x5082, 0x506b, 0x5054, 0x503d, 0x5026, 0x500f, 0x4ff8, 0x4fe1, 0x4fca, 0x4fb3, 0x4de7, 0x4c8e,
				   0x4c60, 0x4c04, 0x4bed, 0x4bd6, 0x4bbf, 0x4ba8, 0x4b91, 0x4b7a}}},
		{}, {{'B', {{ImperialPanel, 0x5305}, {BountyPanel, 0x5334}}}}, {}, {12, 13, 14, 15});
	JediBattle->enemies = {
		{'B',
			{
				{battledroid_security_en, "LEVEL", {26, 87}},
				{battledroid_security_en, "LEVEL", {27, 87}},
				{battledroid_security_en, "LEVEL", {51, 87}},
				{superbattledroid_en, "LEVEL", {52, 87}},
				{superbattledroid_en, "LEVEL", {77, 87}},
				{destroyer_en, "LEVEL", {78, 87}},

				{geonosian_en, "LEVEL1", {28, 158}},
				{superbattledroid_en, "LEVEL1", {28, 134}},
				{battledroid_geonosian_en, "LEVEL1", {28, 105}},
				{battledroid_security_en, "LEVEL1", {28, 77}},
				{geonosian_en, "LEVEL1", {29, 158}},
				{superbattledroid_en, "LEVEL1", {29, 134}},
				{battledroid_geonosian_en, "LEVEL1", {29, 105}},
				{battledroid_security_en, "LEVEL1", {29, 77}},
				{geonosian_en, "LEVEL1", {55, 158}},
				{superbattledroid_en, "LEVEL1", {55, 134}},
				{battledroid_geonosian_en, "LEVEL1", {55, 105}},
				{battledroid_security_en, "LEVEL1", {55, 77}},
			}},
	};
	//JediBattle->enemies = Enemies(
	//	{
	//		{'B', "GEN_BDROIDS", "Update", {}, 16, "", ""},
	//		{'B', "PHASE_DROIDS", "Base", {}, 3, "", ""},
	//	},
	//	{}, {}, {12, 13, 14, 15, 17});

	Gunship = new Level("GUNSHIP", "GUNSHIP", "/LEVELS/EPISODE_II/GUNSHIP/", true,
		{newrepublicgunship, newrepublicgunship_green}, {}, {newrepublicgunship, newrepublicgunship_green},
		{{'A',
			 {0x2332, 0x231b, 0x2304, 0x22ed, 0x22d6, 0x22bf, 0x22a8, 0x2291, 0x227a, 0x2263, 0x224c, 0x2235, 0x221e}},
			{'B', {0x21ea, 0x21d3, 0x21bc, 0x21a5, 0x218e, 0x2177, 0x2160, 0x2149}}},
		{}, {}, {}, {4, 6});
	Gunship->enemies = {
		{'A',
			{
				{hailfiredroid_en, 0x5437, walker},
				{hailfiredroid_en, 0x54DC, walker},
				{hailfiredroid_en, 0x5581, walker},
				{hailfiredroid_en, 0x5626, walker},
				{hailfiredroid_en, 0x56CB, walker},
				{hailfiredroid_en, 0x5770, walker},
				{hailfiredroid_en, 0x5815, walker},
				{hailfiredroid_en, 0x58BA, walker},
				{hailfiredroid_en, 0x595F, walker},
				{hailfiredroid_en, 0x5A04, walker},
				{hailfiredroid_en, 0x5AA9, walker},
				{hailfiredroid_en, 0x5B4E, walker},
				{hailfiredroid_en, 0x5BF3, walker},
				{hailfiredroid_en, 0x5C98, walker},
				{hailfiredroid_en, 0x5D3D, walker},
				{hailfiredroid_en, 0x5DE2, walker},
				{hailfiredroid_en, 0x5E87, walker},
				{hailfiredroid_en, 0x5F2C, walker},
				{hailfiredroid_en, 0x5FD1, walker},
				{hailfiredroid_en, 0x6076, walker},
				{hailfiredroid_en, 0x611B, walker},
				{hailfiredroid_en, 0x61C0, walker},
				{hailfiredroid_en, 0x6265, walker},
				{hailfiredroid_en, 0x630A, walker},
				{hailfiredroid_en, 0x63AF, walker},
				{hailfiredroid_en, 0x6454, walker},
				{hailfiredroid_en, 0x64F9, walker},
				{hailfiredroid_en, 0x659E, walker},
				{hailfiredroid_en, 0x6643, walker},
				{jumbohomingdroid_en, 0x66E8, walker},
				{jumbohomingdroid_en, 0x678D, walker},
				{jumbohomingdroid_en, 0x6832, walker},
				{jumbohomingdroid_en, 0x68D7, walker},
				{jumbohomingdroid_en, 0x697C, walker},
				{jumbohomingdroid_en, 0x6A21, walker},
				{jumbohomingdroid_en, 0x6AC6, walker},
				{jumbohomingdroid_en, 0x6B6B, walker},
				{jumbohomingdroid_en, 0x6C10, walker},
				{jumbohomingdroid_en, 0x6CB5, walker},
				{jumbohomingdroid_en, 0x6D5A, walker},
				{jumbohomingdroid_en, 0x6DFF, walker},
				{jumbohomingdroid_en, 0x6EA4, walker},
				{jumbohomingdroid_en, 0x6F49, walker},
				{hailfiredroid_en, 0x6FEE, walker},
				{hailfiredroid_en, 0x7093, walker},
			}},
		{'B',
			{
				{jumbohomingdroid_en, 0x2132, walker},
				{jumbohomingdroid_en, 0x21D7, walker},
				{jumbohomingdroid_en, 0x227C, walker},
				{jumbohomingdroid_en, 0x2321, walker},
				{jumbohomingdroid_en, 0x23C6, walker},
				{jumbohomingdroid_en, 0x246B, walker},
				{jumbohomingdroid_en, 0x2510, walker},
				{jumbohomingdroid_en, 0x25B5, walker},
				{hailfiredroid_en, 0x265A, walker},
				{hailfiredroid_en, 0x26FF, walker},
				{hailfiredroid_en, 0x27A4, walker},
				{hailfiredroid_en, 0x2849, walker},
				{hailfiredroid_en, 0x28EE, walker},
				{hailfiredroid_en, 0x2993, walker},
				{hailfiredroid_en, 0x2A38, walker},
				{hailfiredroid_en, 0x2ADD, walker},
				{hailfiredroid_en, 0x2B82, walker},

				{hailfiredroid_en, "LEVEL", {33, 25}},
			}},
	};

	Dooku = new Level("DOOKU", "DOOKU", "/LEVELS/EPISODE_II/DOOKU/", false,
		{obiwankenobi_jedimaster, anakin_padawan, yoda}, {}, {yoda},
		{{'B', {0x2245, 0x222e, 0x2217, 0x2200, 0x21e9, 0x1f20, 0x1f09, 0x1ef2, 0x1edb, 0x1ec4, 0x1ead}},
			{'C', {0x2063, 0x204c, 0x2035, 0x201e, 0x2007, 0x1ff0, 0x1d27, 0x1d10, 0x1cf9, 0x1ce2}}},
		{}, {}, {}, {6, 7});
	Dooku->enemies = {
		{'B',
			{
				{battledroid_geonosian_en, 0x11CA},
				{battledroid_geonosian_en, 0x127A},

				{geonosian_en, "DOOKU", {89, 85}},
				{geonosian_en, "DOOKU", {91, 85}},
				{geonosian_en, "DOOKU", {93, 85}},
				{geonosian_en, "DOOKU", {95, 85}},
				{geonosian_en, "DOOKU", {97, 85}},
			}},
	};
	//Dooku->enemies = Enemies({{'B', "STORM", "Approach", {}, 28, "", "",
	//							 {
	//
	//								 DoubleNestedEnemy{"DOOKU", {89, 85}, geonosian},
	//								 DoubleNestedEnemy{"DOOKU", {91, 85}, geonosian},
	//								 DoubleNestedEnemy{"DOOKU", {93, 85}, geonosian},
	//								 DoubleNestedEnemy{"DOOKU", {95, 85}, geonosian},
	//								 DoubleNestedEnemy{"DOOKU", {97, 85}, geonosian},
	//
	//							 }}},
	//	{
	//		{'B',
	//			{
	//				{storm, 0x11CA},
	//				{storm, 0x127A},
	//			}},
	//	},
	//	{}, {6});
	//
	Coruscant = new Level("DOGFIGHT", "DOGFIGHT", "/LEVELS/EPISODE_III/DOGFIGHT/", true,
		{jedistarfighter_yellow_ep3, jedistarfighter_red_ep3}, {},
		{jedistarfighter_yellow_ep3, jedistarfighter_red_ep3, droidtrifighter, vulturedroid, clonearc},
		{{'A', {0x2cbc, 0x2ca5, 0x2c8e, 0x2c77, 0x2c60, 0x2c49, 0x2c32, 0x2c1b, 0x2c04, 0x2bed, 0x2bd6, 0x2bbf, 0x2ba8,
				   0x2b91, 0x2b7a, 0x2b63, 0x2b4c, 0x2b35, 0x2b1e, 0x2b07, 0x2af0}}},
		{}, {}, {});

	Chancellor = new Level("CRUISER", "CRUISER", "/LEVELS/EPISODE_III/CRUISER/", false,
		{obiwankenobi_ep3, anakin_jedi, r2d2, palpatine}, {},
		{obiwankenobi_ep3, anakin_jedi, palpatine, countdooku, bodyguard, buzzdroid},
		{{'A', {0x1bfb, 0x1be4, 0x1bcd}}, {'B', {0x15c0, 0x15a9, 0x1592, 0x11e3, 0x11cc, 0x11b5, 0x119e}},
			{'C', {0x1050, 0x1039, 0xd14}}, {'D', {0x335d}}, {'E', {0xeba, 0xda6}}, {'F', {0x7dd, 0x3a4, 0x38d}},
			{'G', {0x10f9, 0xe75}}},
		{},

		{{'B', {{AstroPanel, 0x1741}, {ProtoPanel, 0x1770}, //minikits
				   {AstroPanel, 0x179F},                    //story bomb
				   {AstroPanel, 0x17CE}}},                  //story, top of room

			{'C', {{ProtoPanel, 0x112F}, {ProtoPanel, 0x115E}, {AstroPanel, 0x118D}}},
			{'D', {{AstroPanel, 0x37BF}}},   //resets moving wall
			{'E', {{AstroPanel, 0xF82},      //turns off gas
					  {AstroPanel, 0xFB1}}}, //end of room
			{'G', {{AstroPanel, 0x11FF}}}},  //elevator (room 2)
		{}, {6, 7, 8, 9, 12, 13});
	Chancellor->enemies = {
		{'A',
			{
				{battledroid_security_en, "GRIEVOUS", {34, 86}},
				{battledroid_security_en, "GRIEVOUS", {35, 86}},
				{battledroid_security_en, "GRIEVOUS", {37, 86}},
				{battledroid_security_en, "GRIEVOUS", {38, 86}},
				{battledroid_security_en, "GRIEVOUS", {40, 86}},
				{battledroid_security_en, "GRIEVOUS", {41, 86}},
			}},
		{'B',
			{
				{destroyer_en, 0x318C},
				{destroyer_en, 0x3251},
				{battledroid_en, 0x3316},
				{battledroid_en, 0x33DB},
				{battledroid_commander_en, 0x34A0},
				{battledroid_en, 0x3565},
				{battledroid_en, 0x362A},
				{battledroid_en, 0x36CF},
				{battledroid_commander_en, 0x3774},
				{battledroid_en, 0x3819},
				{battledroid_en, 0x38BE},
				{destroyer_en, 0x3963},
				{battledroid_en, 0x3A08},
				{battledroid_commander_en, 0x3AAD},

				{destroyer_en, "LEVEL1", {28, 51}},
				{superbattledroid_en, "LEVEL1", {29, 153}},
				{battledroid_security_en, "LEVEL1", {29, 125}},
				{battledroid_commander_en, "LEVEL1", {29, 96}},
				{battledroid_en, "LEVEL1", {29, 77}},
				{superbattledroid_en, "LEVEL1", {30, 153}},
				{battledroid_security_en, "LEVEL1", {30, 125}},
				{battledroid_commander_en, "LEVEL1", {30, 96}},
				{battledroid_en, "LEVEL1", {30, 77}},
				{superbattledroid_en, "LEVEL1", {56, 153}},
				{battledroid_security_en, "LEVEL1", {56, 125}},
				{battledroid_commander_en, "LEVEL1", {56, 96}},
				{battledroid_en, "LEVEL1", {56, 77}},
			}},
		{'C',
			{
				{superbattledroid_en, 0xE06},
				{superbattledroid_en, 0xEAB},
				{battledroid_en, 0xF50},
				{battledroid_commander_en, 0xFF5},
				{battledroid_en, 0x109A},
				{battledroid_commander_en, 0x113F},
				{superbattledroid_en, 0x11E4},
				{superbattledroid_en, 0x1299},
			}},
		{'F',
			{
				{bodyguard_en, 0x112E},
				{bodyguard_en, 0x11E3},
				{battledroid_security_en, 0x1298},
				{battledroid_security_en, 0x135D},
				{battledroid_security_en, 0x1422},
				{battledroid_security_en, 0x14E7},
			}},
		{'G',
			{
				{battledroid_en, 0x2C44},
				{battledroid_en, 0x2CE9},
				{battledroid_en, 0x2D8E},
				{battledroid_commander_en, 0x2E33},
				{battledroid_en, 0x2ED8},
				{battledroid_en, 0x2F7D},
				{superbattledroid_en, 0x3022},
				{superbattledroid_en, 0x30C7},
				{battledroid_en, 0x316C},
				{battledroid_en, 0x3211},
				{battledroid_en, 0x32B6},
				{battledroid_en, 0x335B},
				{battledroid_en, 0x3400},
				{battledroid_en, 0x34A5},
				{battledroid_commander_en, 0x354A},
				{destroyer_en, 0x35EF},
			}},
	};
	//Chancellor->enemies = Enemies(
	//	{
	//		{'A', spawnattack, "DROID", "Base", {}, func("Update", "", "FollowPlayer"), {28, 13},
	//			{{
	//				DoubleNestedEnemy{"GRIEVOUS", {34, 86}, battledroid_security},
	//				DoubleNestedEnemy{"GRIEVOUS", {35, 86}, battledroid_security},
	//				DoubleNestedEnemy{"GRIEVOUS", {37, 86}, battledroid_security},
	//				DoubleNestedEnemy{"GRIEVOUS", {38, 86}, battledroid_security},
	//				DoubleNestedEnemy{"GRIEVOUS", {40, 86}, battledroid_security},
	//				DoubleNestedEnemy{"GRIEVOUS", {41, 86}, battledroid_security},
	//			}}},
	//
	//		{'B', "DESTROYER", "Base", {}, 3, "", ""},
	//		{'B', "STATICATTACK", "Base", {0x318C, 0x3251, 0x3316, 0x33DB, 0x34A0}, 14, "", ""},
	//	},
	//	{
	//		{'B',
	//			{
	//				{storm, 0x3565},
	//				{chatting, 0x362A},
	//				{chatting, 0x36CF},
	//				{chatting, 0x3774},
	//				{chatting, 0x3819},
	//				{sniper, 0x38BE},
	//				{block, 0x3963},
	//				{sniper, 0x3A08},
	//				{storm, 0x3AAD},
	//			}},
	//		{'C',
	//			{
	//				{chatting, 0xE06},
	//				{chatting, 0xEAB},
	//				{storm, 0xF50},
	//				{storm, 0xFF5},
	//				{storm, 0x109A},
	//				{storm, 0x113F},
	//				{storm, 0x11E4},
	//				{storm, 0x1299},
	//			}},
	//		{'F',
	//			{
	//				{attack, 0x112E}, //bodyguard
	//				{attack, 0x11E3}, //bodyguard
	//				{storm, 0x1298},
	//				{storm, 0x135D},
	//				{storm, 0x1422},
	//				{storm, 0x14E7},
	//			}},
	//		{'G',
	//			{
	//				{chatting, 0x2C44},
	//				{chatting, 0x2CE9},
	//				{chatting, 0x2D8E},
	//				{chatting, 0x2E33},
	//				{chatting, 0x2ED8},
	//				{chatting, 0x2F7D},
	//				{chatting, 0x3022},
	//				{chatting, 0x30C7},
	//				{chatting, 0x316C},
	//				{chatting, 0x3211},
	//				{chatting, 0x32B6},
	//				{chatting, 0x335B},
	//				{chatting, 0x3400},
	//				{chatting, 0x34A5},
	//				{chatting, 0x354A},
	//				{block, 0x35EF},
	//			}},
	//	},
	//	{}, {6, 7, 8, 9, 12, 13});

	Grievous = new Level("GRIEVOUS", "GRIEVOUS", "/LEVELS/EPISODE_III/GRIEVOUS/", false,
		{obiwankenobi_ep3, clone_ep3_sand}, {}, {clone_ep3_sand, grievous},
		{{'A', {0x3a2a, 0x3a13, 0x39fc, 0x39e5, 0x39ce, 0x39b7, 0x39a0, 0x3989, 0x3972, 0x395b, 0x3944, 0x392d, 0x37bd,
				   0x3636, 0x361f, 0x3608, 0x35f1, 0x35da, 0x35c3, 0x35ac, 0x3595}}}, //dispenser
		{}, {}, {});

	Kashyyyk = new Level("KASHYYYK", "KASHYYYK", "/LEVELS/EPISODE_III/KASHYYYK/", false, {yoda, chewbacca}, {},
		{chewbacca, wookie, clone_ep3, clone_ep3_pilot, clone_ep3_swamp, clone_ep3_walker},
		{{'A', {0x6157, 0x6140, 0x6129, 0x6112, 0x5fb9, 0x5dd6, 0x5dbf}}, {'B', {0x3374, 0x335d, 0x3346, 0x3204}},
			{'C', {0x2d28, 0x2d11, 0x2cfa}}, {'D', {0x41e1, 0x41ca, 0x41b3, 0x419c, 0x4185, 0x416e}}},
		{{'B', {0x33a2, 0x338b, 0x31ed}}}, {}, //carrots
		{{'A', {{RandomHat, 0x642E}}}}, {5, 6, 7, 9, 10});
	Kashyyyk->enemies = {
		{'A',
			{
				{clone_ep3_en, 0x3BF9},
				{clone_ep3_en, 0x3C9E},
				{clone_ep3_en, 0x3D43},
				{clone_ep3_en, 0x3DE8},
				{clone_ep3_en, 0x407C},
				{clone_ep3_sand_en, 0x4121},
				{clone_ep3_sand_en, 0x41C6},
				{clone_ep3_en, 0x426B},
				{clone_ep3_sand_en, 0x4310},
				{clone_ep3_en, 0x43B5},
				{clone_ep3_en, 0x445A},
				{clone_ep3_sand_en, 0x44FF},
				{clone_ep3_en, 0x45A4},
				{clone_ep3_en, 0x4659},
				{clone_ep3_en, 0x470E},
				{clone_ep3_en, 0x47B3},
				{clone_ep3_sand_en, 0x4858},
				{clone_ep3_sand_en, 0x48FD},
				{clone_ep3_en, 0x49A2},
				{clone_ep3_sand_en, 0x4A47},
				{clone_ep3_en, 0x4AFC},
				//FIX A/LEVEL

				{clone_ep3_swamp_en, "LEVEL2", {27, 118}},
				{clone_ep3_sand_en, "LEVEL2", {27, 96}},
				{battledroid_en, "LEVEL2", {27, 77}},
				{clone_ep3_swamp_en, "LEVEL2", {28, 118}},
				{clone_ep3_sand_en, "LEVEL2", {28, 96}},
				{battledroid_en, "LEVEL2", {28, 77}},
				{clone_ep3_swamp_en, "LEVEL2", {55, 116}},
				{clone_ep3_sand_en, "LEVEL2", {55, 94}},
				{clone_ep3_en, "LEVEL2", {55, 77}},
			}},
		{'B',
			{
				{clone_ep3_en, 0xF44},
				{clone_ep3_en, 0xFF9},
				{battledroid_en, 0x10AE},
				{battledroid_en, 0x1163},
				{clone_ep3_en, 0x1218},
				{clone_ep3_en, 0x12CD},
				{battledroid_en, 0x1382},
				{battledroid_en, 0x1437},
				{battledroid_en, 0x14EC},

				{clone_ep3_en, "CLONEWALKER", {13, 21}},

				{battledroid_en, "LEVEL1", {17, 211}},
				{clone_ep3_en, "LEVEL1", {17, 195}},
			}},
		{'C',
			{
				{battledroid_commander_en, 0xBB2},
				{battledroid_commander_en, 0xC52},

				{battledroid_en, "COMMANDER_LEFT", {44, 169}},
				{battledroid_en, "COMMANDER_RIGHT", {45, 174}},
				{battledroid_commander_en, "LEVEL", {48, 50}},
			}},
		{'D',
			{
				{clone_ep3_swamp_en, 0x398F},
				{battledroid_en, 0x3A44},
				{clone_ep3_swamp_en, 0x3AF9},
				{clone_ep3_en, 0x3BAE},
				{clone_ep3_swamp_en, 0x3D08},
				{battledroid_en, 0x3DBD},
				{clone_ep3_sand_en, 0x3F17},
				{clone_ep3_sand_en, 0x3FCC},
				{battledroid_commander_en, 0x4081},
				{clone_ep3_sand_en, 0x4136},
				{battledroid_commander_en, 0x41EB},
				{clone_ep3_swamp_en, 0x42A0},
				{clone_ep3_sand_en, 0x4365},

				{clone_ep3_en, "CLONEWALKER", {13, 21}},
			}},
	};
	//Kashyyyk->enemies = Enemies({}, {}, {}, {5, 6, 7, 9, 10});

	Ruin = new Level("TEMPLE", "TEMPLE", "/LEVELS/EPISODE_III/TEMPLE/", false, {obiwankenobi_ep3, yoda}, {},
		{macewindu_ep3, disguisedclone, trainingremote},
		{{'A', {0x5330, 0x5319, 0x5302, 0x517b, 0x5164, 0x514d}},
			{'B', {0x420b, 0x41f4, 0x41dd, 0x413c, 0x4125, 0x410e}},
			{'C', {0x5221, 0x520a, 0x51f3, 0x51dc, 0x5197, 0x5180, 0x382a, 0x3813, 0x37fc}}},
		{}, {{'B', {{ImperialPanel, 0x42D3}}}, {'C', {{ProtoPanel, 0x55FF}}}}, {}, {5, 6, 7});
	Ruin->enemies = {
		{'A',
			{
				{disguisedclone_en, 0x12F1},
				{disguisedclone_en, 0x1396},
				{disguisedclone_en, 0x143B},
				{disguisedclone_en, 0x14E0},
				{disguisedclone_en, 0x1585},
				{disguisedclone_en, 0x162A},
				{disguisedclone_en, 0x16CF},
				{disguisedclone_en, 0x1774},
				{disguisedclone_en, 0x1819},
				{disguisedclone_en, 0x18BE},

				{clone_ep3_sand_en, "LEVEL", {25, 116}},
				{clone_ep3_en, "LEVEL", {25, 99}},
				{disguisedclone_en, "LEVEL", {25, 77}},
				{clone_ep3_sand_en, "LEVEL", {53, 116}},
				{clone_ep3_en, "LEVEL", {53, 99}},
				{disguisedclone_en, "LEVEL", {53, 77}},
			}},
		{'B',
			{
				{clone_ep3_sand_en, 0x2BE0},
				{clone_ep3_en, 0x2C85},
				{clone_ep3_en, 0x2D2A},
				{clone_ep3_en, 0x2DCF},
				{clone_ep3_en, 0x2E74},
				{clone_ep3_en, 0x2F29},
				{clone_ep3_sand_en, 0x2FCE},
				{clone_ep3_en, 0x3073},
				{clone_ep3_sand_en, 0x3118},
				{clone_ep3_en, 0x31CD},
				{clone_ep3_en, 0x3272},
				{clone_ep3_en, 0x3317},
				{clone_ep3_en, 0x33BC},
				{clone_ep3_en, 0x3461},
				{disguisedclone_en, 0x3506},
				{disguisedclone_en, 0x35AB},
				{clone_ep3_sand_en, 0x3650},
				{clone_ep3_sand_en, 0x36F5},
			}},
		{'C',
			{
				{clone_ep3_sand_en, 0x1390},
				{clone_ep3_en, 0x1445},
				{clone_ep3_en, 0x14FA},
				{clone_ep3_sand_en, 0x15AF},
				{clone_ep3_en, 0x1664},
				{clone_ep3_en, 0x1719},
				{clone_ep3_sand_en, 0x17CE},
				{clone_ep3_en, 0x1883},
				{clone_ep3_sand_en, 0x1938},
				{clone_ep3_sand_en, 0x19ED},
				{clone_ep3_en, 0x1AA2},
			}},
	};
	//Ruin->enemies = Enemies(
	//	{
	//		{'B', "PIZZAEATERS", "Attack", {0x31CD, 0x3272, 0x3317, 0x33BC, 0x3461, 0x3506, 0x35AB, 0x3650, 0x36F5}, 14,
	//			retreat("base"), ""},
	//	},
	//	{
	//		{'A',
	//			{
	//				{chatting, 0x12F1}, //disguisedclone
	//				{chatting, 0x1396},
	//				{chatting, 0x143B},
	//				{chatting, 0x14E0},
	//				{chatting, 0x1585},
	//				{chatting, 0x162A},
	//				{chatting, 0x16CF},
	//				{chatting, 0x1774},
	//				{chatting, 0x1819},
	//				{chatting, 0x18BE},
	//			}},
	//		{'B',
	//			{
	//				{chatting, 0x2BE0},
	//				{chatting, 0x2C85},
	//				{chatting, 0x2D2A},
	//				{chatting, 0x2DCF},
	//				{storm, 0x2E74},
	//				{attack, 0x2F29},
	//				{attack, 0x2FCE},
	//				{attack, 0x3073},
	//				{storm, 0x3118},
	//			}},
	//		{'C',
	//			{
	//				{storm, 0x1390},
	//				{storm, 0x1445},
	//				{storm, 0x14FA},
	//				{storm, 0x15AF},
	//				{storm, 0x1664},
	//				{storm, 0x1719},
	//				{storm, 0x17CE},
	//				{storm, 0x1883},
	//				{storm, 0x1938},
	//				{storm, 0x19ED},
	//				{storm, 0x1AA2},
	//			}},
	//	},
	//	{}, {5, 6, 7});

	Vader = new Level("VADER", "VADER", "/LEVELS/EPISODE_III/VADER/", false, {obiwankenobi_ep3, anakin_jedi}, {}, {},
		{{'A', {0x47b3, 0x479c, 0x4785, 0x476e, 0x452f, 0x41f3, 0x41dc, 0x41c5, 0x41ae, 0x4197}},
			{'B', {0x187a, 0x1863, 0x1624, 0x160d}}, {'C', {0x28b2, 0x2884, 0x286d, 0x2856, 0x1ffb, 0x1fe4, 0x1fcd}}},
		{}, {{'A', {{AstroPanel, 0x487B}}}}, {});

	SecretPlans = new Level("BLOCKADERUNNER", "BLOCKADERUNNER", "/LEVELS/EPISODE_IV/BLOCKADERUNNER/", false,
		{princessleia, captainantilles, rebelfriend, c3po, r2d2}, {},
		{princessleia, captainantilles, rebelfriend, rebelscum, stormtrooper, imperialshuttlepilot, engineer},
		{{'A', {0x6d3f, 0x6d28, 0x6d11, 0x6cfa}},
			{'B', {0x11033, 0x1101c, 0x11005, 0x10fee, 0x10eac, 0x10e95, 0x10e7e, 0x10e67}},
			{'C', {0x3fc0, 0x3fa9, 0x3f92, 0x3f7b, 0x3ae6}}, {'D', {0x4b1e, 0x4af0}}},

		{{'B', {0x11078, 0x11061, 0x1104a}},  //grapes
			{'D', {0x4b4c, 0x4b35, 0x4b07}}}, //flowers

		{{'A', {{ProtoPanel, 0x6EA9}}},

			{'B', {{AstroPanel, 0x113D9},                               //elevator
					  {BountyPanel, 0x11408}, {ImperialPanel, 0x11437}, //jango car area
					  {ProtoPanel, 0x11466}}},                          //to rb

			{'C', {{ProtoPanel, 0x4141},      //starts midtro
					  {ProtoPanel, 0x4170},   //supercrane
					  {AstroPanel, 0x419F}}}, //end of hallway

			{'D',
				{{ImperialPanel, 0x4CFE}, {ProtoPanel, 0x4DBA}, {ProtoPanel, 0x4DE9}, //There goes another one.
					{AstroPanel, 0x4D2D}, {AstroPanel, 0x4E18}, {ProtoPanel, 0x4D8B}, {AstroPanel, 0x4D5C}}}}, //last 4

		{{'A', {{RandomHat, 0x6EF7}}}}, {10, 11, 14, 17});

	SecretPlans->enemies = {
		EnemySet{'A',
			{
				{stormtrooper_en, "LEVEL", {69, 43}},
				{stormtrooper_en, "LEVEL", {70, 43}},
				{stormtrooper_en, "LEVEL", {71, 43}},
				{stormtrooper_en, "LEVEL", {72, 43}},

				{stormtrooper_en, "LEVEL", {83, 43}},
				{stormtrooper_en, "LEVEL", {84, 43}},
				{stormtrooper_en, "LEVEL", {85, 43}},
				{stormtrooper_en, "LEVEL", {86, 43}},

				{stormtrooper_en, "LEVEL", {98, 43}},
				{stormtrooper_en, "LEVEL", {99, 43}},
				{stormtrooper_en, "LEVEL", {100, 43}},
				{stormtrooper_en, "LEVEL", {101, 43}},
			}},
		EnemySet{'B',
			{
				{stormtrooper_en, 0x6F98},
				{stormtrooper_en, 0x6F98},
				{imperialofficer_en, 0x72F1},
				{stormtrooper_en, 0x7396},
				{stormtrooper_en, 0x744B},
				{stormtrooper_en, 0x7500},
				{stormtrooper_en, 0x75B5},
				{stormtrooper_en, 0x766A},
				{stormtrooper_en, 0x771F},
				{stormtrooper_en, 0x77D4},

				{stormtrooper_en, "AI_VADER2", {64, 43}},
				{stormtrooper_en, "AI_VADER2", {66, 43}},
			}},
		EnemySet{'C',
			{
				{stormtrooper_en, 0x196C},
				{stormtrooper_en, 0x1A11},
				{stormtrooper_en, 0x1AB6},
				{stormtrooper_en, 0x1B5B},
				{stormtrooper_en, 0x1C00},
			}},
		EnemySet{'D',
			{
				{beachtrooper_en, 0x220B},
				{beachtrooper_en, 0x22C0},
				{stormtrooper_en, 0x2375},
				{imperialshuttlepilot_en, 0x242A},
				{stormtrooper_en, 0x24DF},
				{stormtrooper_en, 0x2584},
				{stormtrooper_en, 0x2629},
				{stormtrooper_en, 0x26CE},
				{stormtrooper_en, 0x2773},
				{stormtrooper_en, 0x2818},
				{stormtrooper_en, 0x2A27},
				{stormtrooper_en, 0x2ADC},
				{stormtrooper_en, 0x2B91},
				{stormtrooper_en, 0x2B91},

				{stormtrooper_en, "LEVEL", {84, 44}},
				{stormtrooper_en, "LEVEL", {85, 44}},
				{stormtrooper_en, "LEVEL", {86, 44}},
				{stormtrooper_en, "LEVEL", {87, 44}},

				{imperialofficer_en, "LEVEL", {98, 44}},
				{stormtrooper_en, "LEVEL", {99, 44}},
				{stormtrooper_en, "LEVEL", {100, 44}},
				{stormtrooper_en, "LEVEL", {101, 44}},

				{stormtrooper_en, "LEVEL", {112, 44}},
				{stormtrooper_en, "LEVEL", {113, 44}},
				{imperialofficer_en, "LEVEL", {114, 44}},
				{beachtrooper_en, "LEVEL", {115, 44}},
			}},
	};

	//SecretPlans->enemies = Enemies(
	//	//{{'A', chatting, "WAVE_TROOPER", "Update", {/*nums*/},
	//	//	func("Update", "", "DontPush \"FALSE\"\n\t\tGoToOrigin \"waittime=10\""), {60, 13}}},
	//	std::vector<SpecialScp>{
	//		{'A', chatting, "WAVE_TROOPER", "Update", {},
	//			func("Update", "", "DontPush \"FALSE\"\n\t\tGoToOrigin \"GoToOrigin \"waittime=10\""), {60, 13},
	//			{
	//				DoubleNestedEnemy{"LEVEL", {69, 43}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {70, 43}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {71, 43}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {72, 43}, stormtrooper},
	//
	//				DoubleNestedEnemy{"LEVEL", {83, 43}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {84, 43}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {85, 43}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {86, 43}, stormtrooper},
	//
	//				DoubleNestedEnemy{"LEVEL", {98, 43}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {99, 43}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {100, 43}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {101, 43}, stormtrooper},
	//			}},
	//		{'B', chatting, "WAVE1_TROOPER", "Update", {0x704D, 0x7396, 0x744B, 0x7500},
	//			func("Update", "", "GoToLocator"), {27, 13}},
	//		{'B', chatting, "WAVE2_TROOPER", "Update", {0x75B5, 0x75B5, 0x771F, 0x77D4},
	//			func("Update", "", "GoToLocator"), {27, 13}},
	//		{'B', chatting, "VADER_TROOPER", "Update", {}, func("Update", "", "UseTimeBasedUpdate\n\t\tFollowPlayer"),
	//			{17, 13},
	//			{
	//				DoubleNestedEnemy{"AI_VADER2", {64, 43}, stormtrooper},
	//				DoubleNestedEnemy{"AI_VADER2", {66, 43}, stormtrooper},
	//			},
	//			true},
	//		{'C', "LIFT_TROOPER", "Update", {0x196C, 0x1A11}, 70, "GoToLocator", ""},
	//		{'D', attack, "BEACHTROOPER", "Attack", {0x220B, 0x22C0},
	//			func("Attack", "if GotOpponent == 0 goto WaitBeforeJacuzziing", ""), {28, 13}},
	//		{'D', "BLOCKCHATTING", "Fight", {0x2375, 0x242A, 0x24DF, 0x2584, 0x2629, 0x26CE, 0x2773, 0x2818}, 83,
	//			retreat("Base"), ""},
	//		{'D', chatting, "ESCORT", "UpdatePhase1", {0x2A27, 0x2ADC, 0x2B91, 0x2C46},
	//			func("UpdatePhase1", "", "FacePlayer"), {32, 19}},
	//		{'D', chatting, "SPAWNED_TROOPER", "Update", {}, func("Update", "", "FollowPlayer"), {53, 13},
	//			{
	//
	//				DoubleNestedEnemy{"LEVEL", {84, 44}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {85, 44}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {86, 44}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {87, 44}, stormtrooper},
	//
	//				DoubleNestedEnemy{"LEVEL", {98, 44}, imperialofficer},
	//				DoubleNestedEnemy{"LEVEL", {99, 44}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {100, 44}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {101, 44}, stormtrooper},
	//
	//				DoubleNestedEnemy{"LEVEL", {112, 44}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {113, 44}, stormtrooper},
	//				DoubleNestedEnemy{"LEVEL", {114, 44}, imperialofficer},
	//				DoubleNestedEnemy{"LEVEL", {115, 44}, beachtrooper},
	//			}}},
	//
	//	std::vector<EnemySet>{
	//		{'B', {{NONE, 0x724C}, {NONE, 0x72F1}}},
	//		{'C', {{chatting, 0x1AB6}, {chatting, 0x1B5B}, {chatting, 0x1C00}}},
	//	},
	//	{}, {10, 11, 14, 15, 17});

	Jundland = new Level("TATOOINE", "TATOOINE", "/LEVELS/EPISODE_IV/TATOOINE/", false,
		{lukeskywalker_tatooine, benkenobi, c3po, r2d2}, {},
		{lukeskywalker_tatooine, benkenobi, tuskenraider, jawa, naffdroid1, naffdroid2, naffdroid3, naffdroid4,
			womprat},
		{{'A', {0x7220, 0x7209, 0x71f2, 0x71db, 0x71c4, 0x71ad, 0x7196}}, {'B', {0x7ced, 0x7cd6, 0x7cbf, 0x7ca8}},
			{'C', {0x6907, 0x68f0, 0x68d9, 0x68c2, 0x68ab}}, {'D', {0x3a14, 0x39fd, 0x39e6}}, {'E', {0x4ad2, 0x4abb}}},
		{},

		{{'B', {{ProtoPanel, 0x7FB2}, {AstroPanel, 0x7FE1}, //tv room
				   {AstroPanel, 0x8010},                    //elevator
				   {AstroPanel, 0x803F},                    //vacuum
				   {ProtoPanel, 0x806E},                    //end
				   {ProtoPanel, 0x809D}}},                  //useless

			{'C', {{ProtoPanel, 0x6A0D}, {ProtoPanel, 0x6A3C}, {ProtoPanel, 0x6A6B}}}, //quicksand
			{'E', {{AstroPanel, 0x4CD9}}}},                                            //useless
		{}, {9, 11});
	Jundland->enemies = {
		{'A',
			{
				{tuskenraider_en, 0x562E},
				{tuskenraider_en, 0x5E0A},
				{tuskenraider_en, 0x5EAF},

				{tuskenraider_en, "LEVEL", {111, 47}},
				{tuskenraider_en, "LEVEL", {112, 49}},
				{tuskenraider_en, "LEVEL", {124, 50}},

				{tuskenraider_en, "LEVEL1", {18, 25}},
				{tuskenraider_en, "LEVEL1", {21, 25}},
				{tuskenraider_en, "LEVEL1", {24, 25}},

			}},
		{'B',
			{
				{sandtrooper_en, "LEVEL2", {32, 77}},
				{sandtrooper_en, "LEVEL2", {33, 77}},
				{sandtrooper_en, "LEVEL2", {34, 77}},
				{sandtrooper_en, "LEVEL2", {71, 77}},
			}},
		{'C',
			{
				{tuskenraider_en, 0x636D},
				{tuskenraider_en, 0x6412},
				{tuskenraider_en, 0x64B7},
				{tuskenraider_en, 0x655C},
				{tuskenraider_en, 0x6895},
				{tuskenraider_en, 0x694A},
				{tuskenraider_en, 0x69EF},
				{tuskenraider_en, 0x6AA4},
				{tuskenraider_en, 0x6B59},
				{tuskenraider_en, 0x6BFE},
				{tuskenraider_en, 0x6CB3},
				{tuskenraider_en, 0x6D68},

				{tuskenraider_en, "TUSKENCOMMANDER", {28, 43}},
				{tuskenraider_en, "TUSKENCOMMANDER", {31, 43}},
			}},
		{'D',
			{
				{tuskenraider_en, 0x39B1},
				{tuskenraider_en, 0x3A66},
			}},
		{'E',
			{
				{sandtrooper_en, 0xFEB},
				{sandtrooper_en, 0x1090},
				{sandtrooper_en, 0x1135},
				{sandtrooper_en, 0x11DA},
				{sandtrooper_en, 0x127F},
			}},
	};

	//Jundland->enemies = Enemies(
	//	{
	//		{'A', "TUSKEN_SNIPER", "Engage", {0x5E0A, 0x5EAF}, 24, retreat("Lookout"), ""},
	//		{'C', "TUSKENRAIDER", "Fight", {0x6895, 0x69EF, 0x6BFE, 0x6CB3, 0x6D68}, 54, retreat("Base"), ""},
	//		{'D', "TUSKEN_SNIPER", "Snipe", {0x39B1, 0x3A66}, 25,
	//			retreat("LookOut") "\n\n\t\t" trigger(
	//				"Snipers", "Engage") "\n\n\t\tif GotLocator == 1 and\n\t\tif LocatorRange > 0.25 goto Snipe",
	//			""},
	//		{'A', "PENGUARD", "Fight", {}, 34, retreat("Aproach"), "",
	//			{
	//				{"LEVEL", {111, 47}, tuskenraider},
	//				{"LEVEL", {112, 49}, tuskenraider},
	//			}},
	//		{'A', "TUSKEN_LEDGE", "Engage", {}, 43, retreat("LookOut"), "",
	//			{
	//				{"LEVEL", {124, 50}, tuskenraider},
	//			}},
	//		{'A', "TUSKEN_SET1", "Fight", {}, 21, retreat("Approach"), "",
	//			{
	//				{"LEVEL1", {18, 25}, tuskenraider},
	//				{"LEVEL1", {21, 25}, tuskenraider},
	//				{"LEVEL1", {24, 25}, tuskenraider},
	//			}},
	//	},
	//	{
	//		{'A',
	//			{
	//				{chatting, 0x562E},
	//				{chatting, 0x56E3},
	//			}},
	//		//{'B',
	//		//{
	//		//{chatting, 0x30F3},
	//		//{chatting, 0x3198},
	//		//{chatting, 0x323D},
	//		//{chatting, 0x32E2},
	//		//{chatting, 0x3387},
	//		//{chatting, 0x342C},
	//		//{chatting, 0x34D1},
	//		//{chatting, 0x3576},
	//		//}},
	//		{'C',
	//			{
	//				{sniper, 0x636D},
	//				{chatting, 0x6412},
	//				{chatting, 0x64B7},
	//				{chatting, 0x655C},
	//				//{chatting, 0x674B},
	//				//{chatting, 0x67F0},
	//				{sniper, 0x694A},
	//				{chatting, 0x6AA4},
	//				{chatting, 0x6B59},
	//			}},
	//		//{'D',
	//		//{
	//		//{chatting, 0x3B1B},
	//		//{chatting, 0x3BC0},
	//		//}},
	//		{'E',
	//			{
	//				{chatting, 0xFEB},
	//				{chatting, 0x1090},
	//				{chatting, 0x1135},
	//				{chatting, 0x11DA},
	//				{chatting, 0x127F},
	//			}},
	//	},
	//	{}, {9, 11});

	Spaceport = new Level("MOSEISLEY", "MOSEISLEY", "/LEVELS/EPISODE_IV/MOSEISLEY/", false,
		{lukeskywalker_tatooine, benkenobi, r2d2, c3po, hansolo, chewbacca}, {},
		{hansolo, sandtrooper, greedo, imperialspy},
		{{'A', {0x80d9, 0x80c2, 0x80ab, 0x6eb3, 0x6e57}}, {'B', {0x672b, 0x6714, 0x66fd, 0x66e6, 0x5f43}},
			{'C', {0x2ccc, 0x2cb5}}, {'D', {0x9f93, 0x9f7c, 0x9f65, 0x9f4e, 0x9f37}}, {'E', {0x3564, 0x354d}}},

		{{'A', {0x6e9c, 0x6e85, 0x6e6e}},     //carrots
			{'D', {0x8c2b, 0x8c14, 0x8bfd}}}, //turnips

		{{'A', {{BountyPanel, 0x82AA},                              //fan
				   {ImperialPanel, 0x82DB},                         //spa
				   {AstroPanel, 0x830C},                            //rb
				   {ProtoPanel, 0x833D}, {ImperialPanel, 0x836E}}}, //end

			{'B', {{ProtoPanel, 0x6924}, {AstroPanel, 0x6953}, //atst
					  {ImperialPanel, 0x6982}}},               //go back to A

			{'D', {{BountyPanel, 0xA1DF}, {ProtoPanel, 0xA20E},    //enter bonus
					  {BountyPanel, 0xA23D}, {ProtoPanel, 0xA26C}, //exit bonus
					  {AstroPanel, 0xA29B}}}},                     //theatre

		{{'D', {{StormtrooperHat, 0xA2E9}}}}, {9, 19});
	Spaceport->enemies = {
		{'A',
			{
				{sandtrooper_en, "LEVEL", {43, 50}},
				{sandtrooper_en, "LEVEL", {44, 50}},
				{sandtrooper_en, "LEVEL", {128, 46}},
				{sandtrooper_en, "LEVEL", {140, 51}},
				{sandtrooper_en, "LEVEL", {154, 46}},
			}},
		{'B',
			{
				{sandtrooper_en, 0x2E10},
				{sandtrooper_en, 0x2EB5},
				{sandtrooper_en, 0x2F5A},
				{sandtrooper_en, 0x2FFF},
				{sandtrooper_en, 0x30A4},
				{sandtrooper_en, 0x3338},
				{sandtrooper_en, 0x33DD},
				{sandtrooper_en, 0x3482},
				{sandtrooper_en, 0x3527},
				{sandtrooper_en, 0x35CC},
				{sandtrooper_en, 0x3671},
				{sandtrooper_en, 0x3726},
				{sandtrooper_en, 0x37DB},
				{sandtrooper_en, 0x3890},
				{sandtrooper_en, 0x3945},
				{sandtrooper_en, 0x3A8F},
				{sandtrooper_en, 0x3B44},
				{sentrydroid_en, 0x3BF9},
				{sentrydroid_en, 0x3CAE},
				{sentrydroid_en, 0x3D63},

				{sandtrooper_en, "LEVEL", {133, 41}},
				{sandtrooper_en, "LEVEL", {149, 41}},
				{sandtrooper_en, "LEVEL", {162, 41}},

				{sandtrooper_en, "LEVEL2", {71, 41}},

				{sandtrooper_en, "LEVEL4", {68, 69}},
			}},
		{'D',
			{
				{sandtrooper_en, 0xC10D},
				{sandtrooper_en, 0xC1B2},
				{sandtrooper_en, 0xC257},
				{sandtrooper_en, 0xC2FC},
				{sandtrooper_en, 0xC3A1},
				{sandtrooper_en, 0xC446},
				{sandtrooper_en, 0xC4EB},
				{sandtrooper_en, 0xC77F},
				{sandtrooper_en, 0xC824},
				{sandtrooper_en, 0xC8C9},
				{sandtrooper_en, 0xC96E},
				{sandtrooper_en, 0xCA13},
				{sandtrooper_en, 0xCAB8},
				{sandtrooper_en, 0xCB5D},
				{sandtrooper_en, 0xCC02},
				{sandtrooper_en, 0xCCA7},
				{sandtrooper_en, 0xCE96},

				{sandtrooper_en, "LEVEL1", {26, 48}},
				{sandtrooper_en, "LEVEL1", {28, 48}},
				{sandtrooper_en, "LEVEL1", {30, 48}},
				{sandtrooper_en, "LEVEL1", {32, 51}},
				{sandtrooper_en, "LEVEL1", {34, 51}},

				{sandtrooper_en, "LEVEL1", {45, 51}},
				{sandtrooper_en, "LEVEL1", {47, 51}},
				{sandtrooper_en, "LEVEL1", {49, 51}},
				{sandtrooper_en, "LEVEL1", {51, 49}},
				{sandtrooper_en, "LEVEL1", {53, 49}},

				{sandtrooper_en, "LEVEL1", {64, 51}},
				{sandtrooper_en, "LEVEL1", {66, 51}},
				{sandtrooper_en, "LEVEL1", {68, 51}},
				{sandtrooper_en, "LEVEL1", {70, 48}},
				{sandtrooper_en, "LEVEL1", {72, 48}},

				{sandtrooper_en, "LEVEL1", {101, 46}},

				{sandtrooper_en, "LEVEL3", {75, 75}},
			}},
	};

	//Spaceport->enemies = Enemies(
	//	{{'B', "TAKEOVER", "CheckFight",
	//		 {0x2FFF, 0x30A4, 0x33DD, 0x3482, 0x3527, 0x3671, 0x3726, 0x37DB, 0x3890, 0x3945, 0x3A8F, 0x3B44}, 74,
	//		 "if Timer > 15 goto CheckEmpty\n\t\tif OriginRange > 5 goto GoToOrigin", "",
	//		 {
	//			 {"LEVEL", {149, 41}, sandtrooper},
	//		 }},
	//		{'D', "TAKEOVER", "CheckFight", {0xC4EB, 0xC77F, 0xC824, 0xC8C9, 0xC96E, 0xCA13, 0xCCA7, 0xCE96}, 74,
	//			"if Timer > 15 goto CheckEmpty\n\t\tif OpponentInTriggerArea \"Dewback\" == 0 and \n\t\tif OriginRange "
	//			"> 15 goto GoToOrigin\n\n\t\tif TakenOver == 1 goto TakenOverFight",
	//			""},
	//		{'B', "STORM", "Engage", {0x3338}, 63, "if GotOpponent == 0 goto GoToLocator", ""},
	//		{'D', "STORM", "Engage", {0xC10D, 0xC1B2, 0xC257, 0xC2FC, 0xC3A1, 0xC446}, 61,
	//			"if GotOpponent == 0 and\n\t\tif Timer > 20 gotoLocator", ""},
	//		{'A', "STORMREINFORCE", "Fight", {}, 29, "", "", {{"LEVEL", {140, 51}, sandtrooper}}},
	//		{'A', "STORMGATE", "Engage", {}, 59, "if GotOpponent == 0 goto LookOut", "",
	//			{{"LEVEL", {154, 46}, sandtrooper}}},
	//		{'D', "HANGARATTACK", "Standard_Fight", {}, 115, "if GotOpponent == 0 goto Standard_Approach", "",
	//			{
	//				{"LEVEL1", {26, 48}, sandtrooper},
	//				{"LEVEL1", {28, 48}, sandtrooper},
	//				{"LEVEL1", {30, 48}, sandtrooper},
	//				{"LEVEL1", {32, 51}, sandtrooper},
	//				{"LEVEL1", {34, 51}, sandtrooper},
	//				{"LEVEL1", {45, 51}, sandtrooper},
	//				{"LEVEL1", {47, 51}, sandtrooper},
	//				{"LEVEL1", {49, 51}, sandtrooper},
	//				{"LEVEL1", {51, 49}, sandtrooper},
	//				{"LEVEL1", {53, 49}, sandtrooper},
	//				{"LEVEL1", {64, 51}, sandtrooper},
	//				{"LEVEL1", {66, 51}, sandtrooper},
	//				{"LEVEL1", {68, 51}, sandtrooper},
	//				{"LEVEL1", {70, 48}, sandtrooper},
	//				{"LEVEL1", {72, 48}, sandtrooper},
	//				{"LEVEL1", {101, 46}, sandtrooper},
	//			}}},
	//	{{'B',
	//		 {
	//			 {patrol, 0x2E10},
	//			 {patrol, 0x2F5A},
	//			 {chatting, 0x3BF9}, //sentrydroid
	//			 {chatting, 0x3CAE}, //sentrydroid
	//			 {chatting, 0x3D63},
	//		 }},
	//		{'D',
	//			{
	//				{sniper, 0xCAB8},
	//				{sniper, 0xCB5D},
	//				{sniper, 0xCC02},
	//
	//			}}},
	//	{
	//		{'A', "LEVEL",
	//			{
	//				{storm, {43, 50}, {43, 71}, sandtrooper, 5},
	//				{storm, {44, 50}, {44, 71}, sandtrooper, 5},
	//				{storm, {128, 46}, {128, 67}, sandtrooper, 5},
	//			}},
	//		{'B', "LEVEL",
	//			{
	//				{spawnattack, {133, 41}, {133, 62}, sandtrooper, 11},
	//				{spawnattack, {162, 41}, {162, 62}, sandtrooper, 11},
	//			}},
	//		{'B', "LEVEL2",
	//			{
	//				{NONE, {71, 41}, {71, 62}, sandtrooper, 11},
	//			}},
	//	},
	//	{9});

	Princess = new Level("DEATHSTARRESCUE", "DEATHSTARRESCUE", "/LEVELS/EPISODE_IV/DEATHSTARRESCUE/", false,
		{hansolo_stormtrooper, lukeskywalker_stormtrooper, chewbacca, r2d2, c3po, benkenobi}, {princessleia},
		{hansolo_stormtrooper, lukeskywalker_stormtrooper, beachtrooper, deathstartrooper, tiefighterpilot,
			imperialofficer, grandmofftarkin, mousedroid, imperialengineer},
		{{'A', {0x2ecf, 0x2eb8, 0x2ea1, 0x2e8a}},
			{'B', {0x4f48, 0x4f31, 0x4f1a, 0x4f03, 0x4e79, 0x4e62, 0x4e4b, 0x4e34, 0x3f4a}},
			{'C', {0x50bf, 0x50a8, 0x5091, 0x507a, 0x5063, 0x504c, 0x5035}}, {'D', {0x4e4}}},
		{},
		{{'A', {{ImperialPanel, 0x2FD6},   //first
				   {ProtoPanel, 0x3005},   //minikit
				   {AstroPanel, 0x3034}}}, //cutscene

			{'B', {{AstroPanel, 0x53C0},                          //rb
					  {AstroPanel, 0x53EF}, {AstroPanel, 0x541E}, //elevators
					  {ImperialPanel, 0x544D}}},                  //story /////////APPEARANCE

			{'C', {{ImperialPanel, 0x581D},                          //call room
					  {ImperialPanel, 0x584C},                       //spa
					  {AstroPanel, 0x587B}, {ProtoPanel, 0x58AA}}}}, //extra cells

		{{'A', {{StormtrooperHat, 0x3082}}}, //first room

			{'B', {{StormtrooperHat, 0x549B},      //before bridge
					  {StormtrooperHat, 0x54CB}}}, //after bridge

			{'C', {{StormtrooperHat, 0x58F8}}}, //turnstyle room

			{'D', {{RandomHat, 0x5CB}, {RandomHat, 0x5FB}, {RandomHat, 0x62B}, {RandomHat, 0x65B}}}},
		{26, 28, 29, 30, 31, 32, 41});
	Princess->enemies = {
		EnemySet{'A',
			{
				{stormtrooper_en, 0x1274},
				{stormtrooper_en, 0x1319},
				{imperialofficer_en, 0x13BE},
				{stormtrooper_en, 0x1463},
				{stormtrooper_en, 0x1508},
				{stormtrooper_en, 0x15AD},
				{stormtrooper_en, 0x1652},
				{stormtrooper_en, 0x16F7},
				{stormtrooper_en, 0x179C},
				{stormtrooper_en, 0x1841},
				{stormtrooper_en, 0x18E6},
				{stormtrooper_en, 0x199B},
				{stormtrooper_en, 0x1AF5},
				{stormtrooper_en, 0x1B9A},
				{stormtrooper_en, 0x1C3F},

				{tiefighterpilot_en, "LEVEL2", {29, 93}},
				{stormtrooper_en, "LEVEL2", {29, 73}},
				{tiefighterpilot_en, "LEVEL2", {51, 93}},
				{stormtrooper_en, "LEVEL2", {51, 73}},
			}},
		EnemySet{'B',
			{
				{stormtrooper_en, 0x68CA},
				{stormtrooper_en, 0x6A24},
				{stormtrooper_en, 0x68CA},
				{stormtrooper_en, 0x6AD9},
				{stormtrooper_en, 0x6B8E},
				{stormtrooper_en, 0x6C33},
				{stormtrooper_en, 0x6CE8},
				{imperialofficer_en, 0x6D9D},
				{stormtrooper_en, 0x6E52},
				{stormtrooper_en, 0x6EF7},
				{stormtrooper_en, 0x6F9C},
				{stormtrooper_en, 0x70E6},
				{stormtrooper_en, 0x719B},
				{stormtrooper_en, 0x7250},
				{stormtrooper_en, 0x7305},
				{stormtrooper_en, 0x73BA},
				{stormtrooper_en, 0x746F},
				{stormtrooper_en, 0x7514},
				{stormtrooper_en, 0x75C9},
				{stormtrooper_en, 0x767E},
				{stormtrooper_en, 0x7733},
				{stormtrooper_en, 0x77F8},
				{stormtrooper_en, 0x78BD},
				{stormtrooper_en, 0x7982},
				{imperialofficer_en, 0x7A47},
				{stormtrooper_en, 0x7B0C},
				{stormtrooper_en, 0x7BD1},
				{stormtrooper_en, 0x7C86},
				{stormtrooper_en, 0x7D2B},
				{stormtrooper_en, 0x7DD0},
				{imperialofficer_en, 0x7E75},
				{stormtrooper_en, 0x7F2A},
				{stormtrooper_en, 0x7FCF},

				{stormtrooper_en, "LEVEL1", {33, 42}},

				{stormtrooper_en, "LEVEL2", {32, 42}},

				{tiefighterpilot_en, "LEVEL4", {28, 40}},
				{tiefighterpilot_en, "LEVEL4", {31, 40}},

				{tiefighterpilot_en, "LEVEL5", {25, 40}},
				{tiefighterpilot_en, "LEVEL5", {28, 40}},
			}},
		EnemySet{'C',
			{
				{deathstartrooper_en, 0x36C1},
				{imperialshuttlepilot_en, 0x3766},
				{deathstartrooper_en, 0x380B},
				{imperialofficer_en, 0x38B0},
				{stormtrooper_en, 0x3955},
				{stormtrooper_en, 0x39FA},
				{beachtrooper_en, 0x3B44},
				{beachtrooper_en, 0x3BE9},
				{beachtrooper_en, 0x3C8E},
				{beachtrooper_en, 0x3D33},
				{beachtrooper_en, 0x3DD8},
				{beachtrooper_en, 0x3E7D},
				{beachtrooper_en, 0x3F22},
				{beachtrooper_en, 0x3FC7},
				{deathstartrooper_en, 0x406C},
				{deathstartrooper_en, 0x4111},
				{deathstartrooper_en, 0x41B6},
				{deathstartrooper_en, 0x425B},
				{stormtrooper_en, 0x4300},
				{stormtrooper_en, 0x43A5},
				{stormtrooper_en, 0x444A},
				{stormtrooper_en, 0x44EF},
				{stormtrooper_en, 0x4594},
				{stormtrooper_en, 0x4639},
				{stormtrooper_en, 0x46DE},
				{stormtrooper_en, 0x4783},
				{stormtrooper_en, 0x4828},
				{stormtrooper_en, 0x48CD},

				{stormtrooper_en, "LEVEL1", {34, 42}},

				{stormtrooper_en, "LEVEL2", {36, 42}},

				{deathstartrooper_en, "LEVEL3", {35, 42}},

				{stormtrooper_en, "LEVEL4", {38, 78}},
				{stormtrooper_en, "LEVEL4", {39, 78}},
				{stormtrooper_en, "LEVEL4", {40, 78}},

				{imperialofficer_en, "LEVEL4", {109, 208}},
				{stormtrooper_en, "LEVEL4", {109, 188}},
				{stormtrooper_en, "LEVEL4", {109, 168}},
				{stormtrooper_en, "LEVEL4", {109, 148}},
				{stormtrooper_en, "LEVEL4", {109, 128}},

				{imperialofficer_en, "LEVEL4", {123, 164}},
				{stormtrooper_en, "LEVEL4", {123, 144}},
				{stormtrooper_en, "LEVEL4", {123, 124}},
				{stormtrooper_en, "LEVEL4", {123, 104}},
				{stormtrooper_en, "LEVEL4", {123, 84}},

				{imperialofficer_en, "LEVEL4", {137, 208}},
				{stormtrooper_en, "LEVEL4", {137, 188}},
				{stormtrooper_en, "LEVEL4", {137, 168}},
				{stormtrooper_en, "LEVEL4", {137, 148}},
				{stormtrooper_en, "LEVEL4", {137, 128}},

				{imperialofficer_en, "LEVEL4", {151, 208}},
				{stormtrooper_en, "LEVEL4", {151, 188}},
				{stormtrooper_en, "LEVEL4", {151, 168}},
				{stormtrooper_en, "LEVEL4", {151, 148}},
				{stormtrooper_en, "LEVEL4", {151, 128}},

				{imperialofficer_en, "LEVEL4", {165, 208}},
				{stormtrooper_en, "LEVEL4", {165, 188}},
				{stormtrooper_en, "LEVEL4", {165, 168}},
				{stormtrooper_en, "LEVEL4", {165, 148}},
				{stormtrooper_en, "LEVEL4", {165, 128}},

				{stormtrooper_en, "LEVEL4", {179, 76}},

				{stormtrooper_en, "LEVEL4", {179, 76}},

				{imperialofficer_en, "LEVEL4", {192, 76}},
			}},
		EnemySet{'E',
			{
				{tiefighter_en, "LEVEL", {25, 25}, flyer},
				{tiefighter_en, "LEVEL", {34, 31}, flyer},
			}},
	};

	//bonus hat room
	//Princess->enemies = Enemies( //scene E has flying enemies
	//	{
	//		{'B', "BRIDGE_TROOPS", {0x7733, 0x77F8, 0x78BD, 0x7982, 0x7A47, 0x7B0C},
	//			{
	//				//THESE MUST BE IN ORDER
	//				{"LookForLocator_Engage", 30,
	//					/*	retreat("LookForLocator") "\n\n\t\tif GotLocator == 1 goto "
	//												  "ShootAtObiWan\n\t\tif Timer > 1 goto LookForLocator",
	//						"ReleaseLocator\n\t\tResetTimer\n\t\tGetLocatorFromSet \"name=bridge\""*/
	//					"if AlwaysTrue == 1 goto ShootAtObiWan", "ReleaseLocator"},
	//				{"ShootAtObiWan", 46, "", "SetOpponent \"opponent=ai_obiwankenobi\""},
	//				{"FreePlay_Fight", 95, "if GotOpponent == 0 goto FreePlay_Wait", ""},
	//			}},
	//		{'C', attack, "CALLCENTRE", "Attack", {0x444A, 0x44EF, 0x4594, 0x4639, 0x46DE, 0x4783, 0x4828, 0x48CD},
	//			func("Attack", "", ""), {28, 13}},
	//	},
	//	{
	//		{'A',
	//			{
	//				{chatting, 0x1274},
	//				{chatting, 0x1319},
	//				{chatting, 0x13BE},
	//				{chatting, 0x1463},
	//				{NONE, 0x1508},
	//				{NONE, 0x15AD},
	//				{NONE, 0x1652},
	//				{NONE, 0x16F7},
	//				{NONE, 0x179C},
	//				{NONE, 0x1841},
	//				{chatting, 0x18E6},
	//				{chatting, 0x199B},
	//				{NONE, 0x1AF5},
	//				{NONE, 0x1B9A},
	//				{NONE, 0x1C3F},
	//			}},
	//		{'B',
	//			{
	//				{chatting, 0x68CA},
	//				{chatting, 0x6A24},
	//				{chatting, 0x6AD9},
	//				{patrol, 0x6B8E}, //strolling
	//				{chatting, 0x6C33},
	//				{chatting, 0x6CE8},
	//				{chatting, 0x6D9D},
	//				{patrol, 0x6E52},
	//				{attack, 0x6EF7},
	//				{attack, 0x6F9C},
	//				{chatting, 0x70E6},
	//				{chatting, 0x719B},
	//				{chatting, 0x7250},
	//				{chatting, 0x7305},
	//				{chatting, 0x73BA},
	//				{sniper, 0x746F},
	//				{chatting, 0x7514},
	//				{chatting, 0x75C9},
	//				{chatting, 0x767E},
	//				{chatting, 0x7BD1},
	//				{chatting, 0x7C86},
	//				{chatting, 0x7D2B},
	//				{chatting, 0x7DD0},
	//				{chatting, 0x7E75},
	//				{chatting, 0x7F2A},
	//				{chatting, 0x7FCF},
	//
	//			}},
	//		{'C',
	//			{
	//				{attack, 0x36C1},
	//				{attack, 0x3766},
	//				{attack, 0x380B},
	//				{chatting, 0x38B0},
	//				{chatting, 0x3955},
	//				{chatting, 0x39FA},
	//				{NONE, 0x3B44}, //beach
	//				{NONE, 0x3BE9},
	//				{NONE, 0x3C8E},
	//				{NONE, 0x3D33},
	//				{NONE, 0x3DD8},
	//				{chatting, 0x3E7D},
	//				{chatting, 0x3F22},
	//				{chatting, 0x3FC7},
	//				{block, 0x406C},
	//				{block, 0x4111},
	//				{block, 0x41B6},
	//				{block, 0x425B},
	//				{chatting, 0x4300},
	//				{chatting, 0x43A5},
	//
	//			}},
	//	},
	//	{
	//		{'A', "LEVEL2",
	//			{
	//				{NONE, {29, 93}, {1, 1}, tiefighterpilot, 0},
	//				{NONE, {29, 73}, {1, 1}, stormtrooper, 0},
	//				{NONE, {51, 93}, {1, 1}, tiefighterpilot, 0},
	//				{NONE, {51, 73}, {1, 1}, stormtrooper, 0},
	//			}},
	//		{'B', "LEVEL1",
	//			{
	//				{spawnattack, {33, 42}, {33, 64}, stormtrooper, 11},
	//			}},
	//		{'B', "LEVEL2",
	//			{
	//				{spawnattack, {32, 42}, {32, 64}, stormtrooper, 11},
	//			}},
	//		{'C', "LEVEL1",
	//			{
	//				{spawnattack, {34, 42}, {34, 64}, stormtrooper, 11},
	//			}},
	//		{'C', "LEVEL3",
	//			{
	//				{spawnattack, {35, 42}, {35, 68}, deathstartrooper, 11},
	//			}},
	//		{'B', "LEVEL4",
	//			{
	//				{spawnattack, {28, 40}, {28, 65}, tiefighterpilot, 11},
	//				{spawnattack, {31, 40}, {31, 65}, tiefighterpilot, 11},
	//			}},
	//	},
	//	{26, 28, 29, 30, 31, 32});

	DSE = new Level("DEATHSTARESCAPE", "DEATHSTARESCAPE", "/LEVELS/EPISODE_IV/DEATHSTARESCAPE/", false,
		{hansolo, chewbacca, princessleia, lukeskywalker_tatooine, r2d2, c3po}, {}, {},
		{{'A', {0x2834, 0x281d, 0x2806, 0x27ef}}, {'B', {0x2fe7, 0x2fd0, 0x2fb9, 0x2fa2, 0x2f8b, 0x2ffe}},
			{'C', {0x474a, 0x4733, 0x471c, 0x4705, 0x46ee, 0x4567, 0x4550, 0x4539, 0x4522}}, {'D', {0x746, 0x72f}}},
		{},

		{{'A', {{ProtoPanel, 0x2B50},         //rb
				   {ImperialPanel, 0x2B7F}}}, //story

			{'B', {{ImperialPanel, 0x32F2}}}, //ripmore

			{'C', {{ImperialPanel, 0x4B64},       //swing room
					  {ProtoPanel, 0x4B93},       //falcon - fan
					  {ImperialPanel, 0x4BC2},    //trophy bonus
					  {AstroPanel, 0x4BF1},       //falcon - right
					  {AstroPanel, 0x4C20},       //floor waxer
					  {BountyPanel, 0x4C4F},      //vader
					  {ImperialPanel, 0x4C7E}}}}, //bonus clock

		{{'A', {{StormtrooperHat, 0x2BCD}}},     //first hat
			{'B', {{StormtrooperHat, 0x3340}}},  //ripmore
			{'C', {{StormtrooperHat, 0x4CCC}}}}, //swing room
		{11, 12, 13, 14});
	DSE->enemies = {
		{'A',
			{
				{stormtrooper_en, 0x1695},
				{stormtrooper_en, 0x173A},
				{stormtrooper_en, 0x17DF},
				{stormtrooper_en, 0x1884},
				{tiefighterpilot_en, 0x1929},
				{imperialofficer_en, 0x19CE},
				{stormtrooper_en, 0x1A73},
				{stormtrooper_en, 0x1B18},
				{stormtrooper_en, 0x1BBD},
				{stormtrooper_en, 0x1C62},
				{stormtrooper_en, 0x1D07},
				{stormtrooper_en, 0x1E51},
				{stormtrooper_en, 0x1EF6},
				{stormtrooper_en, 0x1F9B},
				{stormtrooper_en, 0x2040},
				{stormtrooper_en, 0x20E5},
				{stormtrooper_en, 0x218A},
				{stormtrooper_en, 0x222F},
			}},
		{'B',
			{
				{stormtrooper_en, 0x2E91},
				{stormtrooper_en, 0x2F36},
				{stormtrooper_en, 0x2FDB},
				{imperialofficer_en, 0x3080},
				{stormtrooper_en, 0x3125},
				{stormtrooper_en, 0x31CA},
				{deathstartrooper_en, 0x326F},
				{deathstartrooper_en, 0x3314},
				{imperialofficer_en, 0x33B9},
				{stormtrooper_en, 0x345E},
				{stormtrooper_en, 0x3513},
				{imperialofficer_en, 0x35C8},
				{tiefighterpilot_en, 0x367D},
				{tiefighterpilot_en, 0x3722},
				{stormtrooper_en, 0x37C7},
				{stormtrooper_en, 0x386C},
				{stormtrooper_en, 0x3911},
				{stormtrooper_en, 0x39B6},
				{stormtrooper_en, 0x3B00},
				{stormtrooper_en, 0x3BA5},
				{stormtrooper_en, 0x3C4A},
				{stormtrooper_en, 0x3CEF},
				{stormtrooper_en, 0x3D94},
				{stormtrooper_en, 0x3E39},
				{stormtrooper_en, 0x3EDE},

				{stormtrooper_en, "LEVEL", {107, 45}},
				{stormtrooper_en, "LEVEL", {122, 45}},
				{stormtrooper_en, "LEVEL", {137, 46}},
			}},
		{'C',
			{
				{stormtrooper_en, 0x471D},
				{stormtrooper_en, 0x47C2},
				{stormtrooper_en, 0x4867},
				{stormtrooper_en, 0x490C},
				{stormtrooper_en, 0x49B1},
				{stormtrooper_en, 0x4A56},
				{stormtrooper_en, 0x4AFB},
				{stormtrooper_en, 0x4BA0},

				{tiefighterpilot_en, "LEVEL", {103, 62}},
				{stormtrooper_en, "LEVEL", {103, 42}},
				{stormtrooper_en, "LEVEL", {115, 46}},
				{stormtrooper_en, "LEVEL", {116, 46}},

				{tiefighterpilot_en, "LEVEL1", {41, 69}},
				{stormtrooper_en, "LEVEL1", {41, 49}},

				{stormtrooper_en, "LEVEL2", {23, 57}},
				{stormtrooper_en, "LEVEL2", {102, 95}},
				{stormtrooper_en, "LEVEL2", {115, 94}},

				{stormtrooper_en, "LEVEL3", {103, 50}},
				{stormtrooper_en, "LEVEL3", {104, 50}},
				{stormtrooper_en, "LEVEL3", {105, 50}},
			}},
	};

	RebelAttack = new Level("DEATHSTARBATTLE", "DEATHSTARBATTLE", "/LEVELS/EPISODE_IV/DEATHSTARBATTLE/", true,
		{xwing, ywing}, {}, {xwing, ywing, tiefighter, tieinterceptor, tiefighterdarth},
		{{'A', {0x46b0, 0x4699, 0x4682, 0x466b, 0x4654, 0x463d, 0x4626}},
			{'B', {0x6fb0, 0x6f99, 0x6f82, 0x6f6b, 0x6f54, 0x6f3d, 0x6f26}}, {'C', {0x477b, 0x4764, 0x474d}},
			{'D', {0x21e1, 0x21ca, 0x21b3, 0x219c}}},
		{}, {}, {}, {4});
	RebelAttack->enemies = {
		{'A',
			{
				{tiefighter_en, "LEVEL", {18, 31}, flyer},
				{tiefighter_en, "LEVEL", {22, 31}, flyer},
				{tiefighter_en, "LEVEL", {26, 31}, flyer},
				{tiefighter_en, "LEVEL", {27, 31}, flyer},
				{tiefighter_en, "LEVEL", {30, 31}, flyer},
				{tiefighter_en, "LEVEL", {34, 31}, flyer},
				{tiefighter_en, "LEVEL", {69, 31}, flyer},
				{tiefighter_en, "LEVEL", {81, 31}, flyer},
				{tiefighter_en, "LEVEL", {82, 31}, flyer},
				{tiefighter_en, "LEVEL", {94, 31}, flyer},
				{tiefighter_en, "LEVEL", {95, 31}, flyer},
				{tiefighter_en, "LEVEL", {96, 31}, flyer},
				{tiefighter_en, "LEVEL", {107, 31}, flyer},

				{tiefighter_en, "LEVEL1", {42, 25}, walker},
				{tiefighter_en, "LEVEL1", {44, 25}, walker},
				{tiefighter_en, "LEVEL1", {67, 25}, walker},
			}},

		{'B',
			{
				{tiefighter_en, "LEVEL", {16, 31}, flyer},
				{tiefighter_en, "LEVEL", {20, 31}, flyer},
				{tiefighter_en, "LEVEL", {24, 31}, flyer},
				{tiefighter_en, "LEVEL", {25, 31}, flyer},
				{tiefighter_en, "LEVEL", {28, 31}, flyer},
				{tiefighter_en, "LEVEL", {32, 31}, flyer},
				{tiefighter_en, "LEVEL", {67, 31}, flyer},
				{tiefighter_en, "LEVEL", {79, 31}, flyer},
				{tiefighter_en, "LEVEL", {80, 31}, flyer},
				{tiefighter_en, "LEVEL", {92, 31}, flyer},
				{tiefighter_en, "LEVEL", {93, 31}, flyer},
				{tiefighter_en, "LEVEL", {94, 31}, flyer},
				{tiefighter_en, "LEVEL", {105, 31}, flyer},

				{tiefighter_en, "LEVEL1", {69, 25}, walker},
				{tiefighter_en, "LEVEL1", {71, 25}, walker},
				{tiefighter_en, "LEVEL1", {97, 25}, walker},
				{tiefighter_en, "LEVEL1", {99, 25}, walker},
				{tiefighter_en, "LEVEL1", {125, 25}, walker},
				{tiefighter_en, "LEVEL1", {127, 25}, walker},
				{tiefighter_en, "LEVEL1", {151, 25}, walker},
			}},
		{'C',
			{
				{tiefighter_en, "LEVEL", {16, 31}, flyer},
				{tiefighter_en, "LEVEL", {20, 31}, flyer},
				{tiefighter_en, "LEVEL", {24, 31}, flyer},
				{tiefighter_en, "LEVEL", {25, 31}, flyer},
				{tiefighter_en, "LEVEL", {28, 31}, flyer},
				{tiefighter_en, "LEVEL", {32, 31}, flyer},
				{tiefighter_en, "LEVEL", {67, 31}, flyer},
				{tiefighter_en, "LEVEL", {79, 31}, flyer},
				{tiefighter_en, "LEVEL", {80, 31}, flyer},
				{tiefighter_en, "LEVEL", {92, 31}, flyer},
				{tiefighter_en, "LEVEL", {93, 31}, flyer},
				{tiefighter_en, "LEVEL", {94, 31}, flyer},
				{tiefighter_en, "LEVEL", {105, 31}, flyer},

				{tiefighter_en, "LEVEL1", {42, 25}, walker},
				{tiefighter_en, "LEVEL1", {44, 25}, walker},
				{tiefighter_en, "LEVEL1", {69, 25}, walker},
			}},
		{'D',
			{
				{tiefighter_en, "LEVEL", {15, 64}, walker},
			}},
	};

	Hoth = new Level("HOTHBATTLE", "HOTHBATTLE", "/LEVELS/EPISODE_V/HOTHBATTLE/", true, {snowspeeder, snowspeeder}, {},
		{snowspeeder},
		{{'A', {0x2ff9, 0x2fe2, 0x2fcb, 0x2fb4, 0x2f9d}}, {'B', {0x1148, 0x1131}},
			{'C', {0x53e5, 0x53ce, 0x53b7, 0x53a0}}, {'D', {0x3120, 0x3109, 0x30f2, 0x30db, 0x30c4, 0x30ad}},
			{'E', {0x1786, 0x176f, 0x1758, 0x1741}}},
		{}, {}, {}, {3, 4, 7});
	Hoth->enemies = {
		{'A',
			{
				{probedroid_en, 0x1206, walker},
				{probedroid_en, 0x12BB, walker},
				{probedroid_en, 0x1370, walker},
				{atst_lowres_en, 0x1425, walker},
				{atst_lowres_en, 0x14CA, walker},
				{atst_lowres_en, 0x156F, walker},
				{atst_lowres_en, 0x1614, walker},
				{atst_lowres_en, 0x16B9, walker},
				{speederbike_snow_en, 0x175E, walker},
				{speederbike_snow_en, 0x1803, walker},
				{atst_lowres_en, 0x1A97, walker},

				{probedroid_en, "LEVEL", {55, 45}, walker},
				{atst_lowres_en, "LEVEL", {68, 47}, walker},
				{speederbike_snow_en, "LEVEL", {81, 47}, walker},

				{probedroid_en, "LEVEL1", {40, 79}, walker},
			}},
		{'B',
			{
				{atst_lowres_en, 0x772, walker},
				{atst_lowres_en, 0x817, walker},
				{atst_lowres_en, 0x8BC, walker},
				{speederbike_snow_en, 0x961, walker},
				{speederbike_snow_en, 0xA06, walker},
				{speederbike_snow_en, 0xAAB, walker},
			}},
		{'C',
			{
				{atst_lowres_en, 0x121E, walker},
				{atst_lowres_en, 0x12C3, walker},
				{atst_lowres_en, 0x1368, walker},
				{atst_lowres_en, 0x140D, walker},
				{atst_lowres_en, 0x14B2, walker},
				{atst_lowres_en, 0x15FC, walker},
				{atst_lowres_en, 0x16A1, walker},

				{probedroid_en, "LEVEL", {71, 46}, walker},
				{atst_lowres_en, "LEVEL", {72, 46}, walker},
				{atst_lowres_en, "LEVEL", {73, 46}, walker},
				{atst_lowres_en, "LEVEL", {87, 43}, walker},
				{speederbike_snow_en, "LEVEL", {111, 64}, walker},
				{probedroid_en, "LEVEL", {111, 46}, walker},
				{speederbike_snow_en, "LEVEL", {135, 64}, walker},
				{probedroid_en, "LEVEL", {135, 46}, walker},
			}},
		{'D',
			{
				{atst_lowres_en, 0x9F4, walker},
				{atst_lowres_en, 0xA99, walker},
				{atst_lowres_en, 0xB3E, walker},
				{atst_lowres_en, 0xC88, walker},
				{atst_lowres_en, 0xD2D, walker},
				{atst_lowres_en, 0xDD2, walker},
				{atst_lowres_en, 0xE77, walker},
				{atst_lowres_en, 0xF1C, walker},
				{atst_lowres_en, 0xFC1, walker},

				{atst_lowres_en, "LEVEL", {40, 45}, walker},
				{probedroid_en, "LEVEL1", {39, 79}, walker},
			}},
		{'E',
			{
				{probedroid_en, "LEVEL", {43, 61}, walker},
				{atst_lowres_en, "LEVEL", {60, 115}, walker},
				{atst_lowres_en, "LEVEL", {94, 102}, walker},
				{probedroid_en, "LEVEL", {95, 61}, walker},
			}},
	};

	EchoBase = new Level("HOTHESCAPE", "HOTHESCAPE", "/LEVELS/EPISODE_V/HOTHESCAPE/", false,
		{hansolo_hoth, princessleia_hoth, c3po, chewbacca}, {},
		{hansolo_hoth, princessleia_hoth, hansolo_hood, rebelhoth, rebelpilot, snowtrooper, lukeskywalker_hoth},
		{{'A', {0x4d85, 0x4d6e, 0x4d57, 0x4d40, 0x4d29, 0x4d12}},
			{'B', {0x44f7, 0x44e0, 0x44c9, 0x44b2, 0x449b, 0x3d54, 0x3d3d}},
			{'C', {0x48ca, 0x48b3, 0x489c, 0x4885, 0x486e, 0x4857, 0x3d78}}, {'D', {0x2c7}}},
		{},

		{{'A', {{AstroPanel, 0x4F5E},      //challenge kit
				   {ProtoPanel, 0x4F8D}}}, //story

			{'B', {{AstroPanel, 0x46C3},      //ice fishing
					  {ProtoPanel, 0x46F2}}}, //story

			{'C', {{ProtoPanel, 0x4B8A},       //tube room
					  {AstroPanel, 0x4BB9}}}}, //slot machines
		{}, {6});
	EchoBase->enemies = {
		{'A',
			{
				{snowtrooper_en, 0x2CA4},
				{snowtrooper_en, 0x2D49},
				{snowtrooper_en, 0x2DEE},
				{snowtrooper_en, 0x2E93},
				{snowtrooper_en, 0x2F38},
				{snowtrooper_en, 0x2FDD},
				{snowtrooper_en, 0x3092},
				{snowtrooper_en, 0x3147},
				{snowtrooper_en, 0x31FC},
				{snowtrooper_en, 0x32B1},

				{snowtrooper_en, "LEVEL1", {30, 51}},

				{snowtrooper_en, "LEVEL2", {45, 77}},
			}},
		{'B',
			{
				{snowtrooper_en, 0x1ABE},
				{snowtrooper_en, 0x1B63},
				{snowtrooper_en, 0x1C08},
				{snowtrooper_en, 0x1CAD},
				{snowtrooper_en, 0x1D52},
				{snowtrooper_en, 0x1DF7},
				{snowtrooper_en, 0x1E9C},
				{snowtrooper_en, 0x1F41},
				{snowtrooper_en, 0x1FE6},
				{snowtrooper_en, 0x208B},
				{snowtrooper_en, 0x2130},
				{snowtrooper_en, 0x21D5},
				{snowtrooper_en, 0x227A},
				{snowtrooper_en, "LEVEL", {145, 49}},
				{snowtrooper_en, "LEVEL", {158, 49}},
			}},
		{'C',
			{
				{snowtrooper_en, 0x19C7},
				{snowtrooper_en, 0x1A6C},
				{snowtrooper_en, 0x1B11},
				{snowtrooper_en, 0x1BB6},
				{snowtrooper_en, 0x1C5B},
				{snowtrooper_en, 0x1D00},
				{snowtrooper_en, 0x1DA5},
				{snowtrooper_en, 0x1E4A},
				{snowtrooper_en, 0x1EEF},
				{snowtrooper_en, "LEVEL", {132, 45}},
				{snowtrooper_en, "LEVEL1", {51, 76}},
			}},
		{'D',
			{
				{snowtrooper_en, 0xB29},
				{snowtrooper_en, 0xBCE},
				{snowtrooper_en, 0xC73},
				{snowtrooper_en, 0xD18},
				{snowtrooper_en, 0xDBD},
			}},
	};

	FalconFlight = new Level("ASTEROIDCHASE", "ASTEROIDCHASE", "/LEVELS/EPISODE_V/ASTEROIDCHASE/", true,
		{millenniumfalcon, xwing}, {}, {millenniumfalcon, tiebomber, imperialshuttle},
		{{'A', {0x260f, 0x25f8, 0x25e1, 0x25ca, 0x25b3, 0x259c, 0x2585}},
			{'B', {0x4a01, 0x49ea, 0x49d3, 0x49bc, 0x49a5, 0x498e, 0x4977, 0x4960}}, {'C', {0x1617, 0x1600, 0x15e9}},
			{'D', {0x573, 0x55c, 0x545}}},
		{}, {}, {}, {7, 8, 9});
	FalconFlight->enemies = {
		{'A',
			{
				{tiefighter_en, "LEVEL", {56, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {56, 25}, flyer},
				{tiefighter_en, "LEVEL", {68, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {68, 25}, flyer},
				{tiefighter_en, "LEVEL", {80, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {80, 25}, flyer},
				{tiefighter_en, "LEVEL", {92, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {92, 25}, flyer},
			}},
		{'B',
			{
				{tiefighter_en, "LEVEL", {57, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {57, 25}, flyer},
				{tiefighter_en, "LEVEL", {69, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {69, 25}, flyer},
				{tiefighter_en, "LEVEL", {81, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {81, 25}, flyer},
				{tiefighter_en, "LEVEL", {93, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {93, 25}, flyer},
				{tiefighter_en, "LEVEL", {105, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {105, 25}, flyer},
			}},
		{'C',
			{
				{tiefighter_en, "LEVEL", {50, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {50, 25}, flyer},
				{tiefighter_en, "LEVEL", {62, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {62, 25}, flyer},
				{tiefighter_en, "LEVEL", {74, 47}, flyer},
				{tieinterceptor_en, "LEVEL", {74, 25}, flyer},
			}},
		{'D',
			{
				{tieinterceptor_en, "LEVEL", {52, 43}, flyer},
				{tiefighter_en, "LEVEL", {52, 25}, flyer},
				{tiebomber_en, "LEVEL", {64, 25}, flyer},
			}},
	};

	Dagobah = new Level("DAGOBAH", "DAGOBAH", "/LEVELS/EPISODE_V/DAGOBAH/", false,
		{lukeskywalker_pilot, r2d2, lukeskywalker_dagobah, yoda}, {}, {lukeskywalker_pilot, lukeskywalker_dagobah},
		{{'A', {0x4648, 0x4631, 0x461a, 0x4603, 0x45ec}}, {'B', {0x3015, 0x2ffe, 0x2fd0, 0x2fb9}},
			{'C', {0x4ff9, 0x4fe2, 0x4fcb}}, {'D', {0x436b, 0x4354, 0x433d, 0x4326, 0x430f, 0x42f8}},
			{'E', {0x6865, 0x684e}}},

		{{'E', {0x6893, 0x687c, 0x6837}}}, //circle things

		{{'A', {{AstroPanel, 0x478D}}},     //raise bridge
			{'B', {{AstroPanel, 0x3343}}},  //after hut skip - raise platform
			{'C', {{AstroPanel, 0x57C7}}},  //end level - x-wing
			{'D', {{AstroPanel, 0x44C6}}},  //minikit
			{'E', {{AstroPanel, 0x699A}}}}, //end of Training room
		{}, {10});
	Dagobah->enemies = {
		{'A',
			{
				{bat_en, 0x3417},
				{bat_en, 0x3561},
				{bat_en, 0x3606},
				{bat_en, 0x36AB},
				{bat_en, 0x3750},
				{bat_en, 0x37F5},
				{bat_en, 0x389A},
				{bat_en, 0x393F},
				{bat_en, 0x39E4},
			}},
		{'C',
			{
				{bat_en, 0xBC7},
				{bat_en, 0xC6C},
				{bat_en, 0xD11},
				{bat_en, 0xDB6},
				{bat_en, 0xE5B},
				{bat_en, 0xF00},

				{bat_en, "LEVEL", {70, 48}},
				{bat_en, "LEVEL", {72, 48}},
				{bat_en, "LEVEL", {74, 48}},
				{bat_en, "LEVEL", {76, 48}},
				{bat_en, "LEVEL", {86, 48}},
				{bat_en, "LEVEL", {88, 48}},
				{bat_en, "LEVEL", {90, 48}},
				{bat_en, "LEVEL", {92, 48}},
				{bat_en, "LEVEL", {102, 48}},
				{bat_en, "LEVEL", {104, 48}},
				{bat_en, "LEVEL", {106, 48}},
				{bat_en, "LEVEL", {108, 48}},
			}},
		{'D',
			{
				{bat_en, "LEVEL1", {16, 60}},
				{bat_en, "LEVEL1", {33, 95}},
			}},
		{'E',
			{
				{bat_en, "LEVEL", {87, 48}},
				{bat_en, "LEVEL", {89, 48}},
				{bat_en, "LEVEL", {91, 48}},
				{bat_en, "LEVEL", {93, 48}},
				{bat_en, "LEVEL", {103, 48}},
				{bat_en, "LEVEL", {105, 48}},
				{bat_en, "LEVEL", {107, 48}},
				{bat_en, "LEVEL", {109, 48}},
				{bat_en, "LEVEL", {119, 48}},
				{bat_en, "LEVEL", {121, 48}},
				{bat_en, "LEVEL", {123, 48}},
				{bat_en, "LEVEL", {125, 48}},

				{bat_en, "LEVEL2", {25, 95}},
				{bat_en, "LEVEL2", {34, 93}},
			}},
	};

	CCT = new Level("CLOUDCITYTRAP", "CLOUDCITYTRAP", "/LEVELS/EPISODE_V/CLOUDCITYTRAP/", false,
		{lukeskywalker_bespin, r2d2}, {}, {lukeskywalker_bespin, hanincarbonite},
		{{'A', {0x1f65, 0x1f4e, 0x1f37, 0x1f20, 0x1f09, 0x1ef2, 0x1edb}},
			{'B', {0x13db, 0x13c4, 0x13ad, 0x1396, 0x137f, 0x133a, 0x130c, 0x12f5}},
			{'C', {0x163d, 0x1626, 0x15f8, 0x15e1, 0x15ca, 0x160f}}},
		{},

		{{'A', {{AstroPanel, 0x2083},       //raise first bridge
				   {AstroPanel, 0x20B2},    //enter room 2
				   {AstroPanel, 0x20E1},    //get box for turret
				   {BountyPanel, 0x2110},   //minikit
				   {AstroPanel, 0x213F},    //room 2 - end of hallway
				   {AstroPanel, 0x216E},    //dv1 gas
				   {ImperialPanel, 0x219D}, //dv1 - exit room
				   {AstroPanel, 0x21CC}}},  //dv1 raise bridge

			{'B', {{AstroPanel, 0x14A3},                          //DV4 elevator
					  {AstroPanel, 0x14D2}, {AstroPanel, 0x1501}, //DV3
					  {ImperialPanel, 0x1530}}},                  //minikit

			{'C', {{AstroPanel, 0x1827},       //DVT moving platform
					  {AstroPanel, 0x1856},    //DVT elevator (DV2 skip)
					  {AstroPanel, 0x1885},    //DV3 - right
					  {AstroPanel, 0x18B4}}}}, //DV3 - left

		{{'A', {{StormtrooperHat, 0x221A}}}}, //dv1 hat
		{6});
	CCT->enemies = {
		{'A',
			{
				{stormtrooper_en, 0x21C7},
				{stormtrooper_en, 0x226C},
				{stormtrooper_en, 0x2311},
				{stormtrooper_en, 0x23B6},
				{stormtrooper_en, 0x245B},

				{stormtrooper_en, "LEVEL1", {28, 43}},
				{stormtrooper_en, "LEVEL1", {30, 43}},

				{stormtrooper_en, "LEVEL2", {49, 48}},
			}},
		{'B',
			{
				{stormtrooper_en, "LEVEL1", {51, 45}},
				{stormtrooper_en, "LEVEL2", {50, 46}},
			}},
		{'C',
			{
				{stormtrooper_en, "LEVEL1", {61, 48}},
			}},
	};

	Bespin = new Level("CLOUDCITYESCAPE", "CLOUDCITYESCAPE", "/LEVELS/EPISODE_V/CLOUDCITYESCAPE/", false,
		{landocalrissian, princessleia_bespin, chewbacca, r2d2, c3po}, {},
		{landocalrissian, princessleia_bespin, lobot, ugnaught, bespinguard, princessleia_prisoner},
		{{'A', {0x4e34, 0x4e06, 0x4def, 0x4dd8, 0x4dc1, 0x4daa, 0x4d7c, 0x4d65, 0x4d4e}}, {'B', {0x14f, 0xdc}},
			{'C', {0x434c, 0x4335, 0x431e, 0x4307, 0x42f0, 0x424f, 0x4238, 0x4221, 0x420a}}},

		{{{'A', 0x4d37}, {'A', 0x4d93}, {'C', 0x41f3}}}, //towers

		{{'A', {{ProtoPanel, 0x4FD4},         //first minikit
				   {BountyPanel, 0x5003},     //boba opens this
				   {ProtoPanel, 0x5032},      //split path - straight to hat machine
				   {AstroPanel, 0x5061},      //build c3po
				   {AstroPanel, 0x5090},      //turn off gas
				   {AstroPanel, 0x50BF},      //old OOB room
				   {BountyPanel, 0x50EE},     //bonus elevator
				   {ImperialPanel, 0x511D}}}, //story elevator

			{'C', {{AstroPanel, 0x466B},       //extend bridge
					  {ProtoPanel, 0x469A},    //box clip skips this
					  {AstroPanel, 0x46C9},    //go to falcon
					  {AstroPanel, 0x46F8}}}}, //turn off gas

		{{'A', {{RandomHat, 0x516B},             //by first minikit
				   {StormtrooperHat, 0x519B}}}}, //story hat
		{7, 12, 15});
	Bespin->enemies = {
		{'A',
			{
				{stormtrooper_en, 0x4F81},
				{stormtrooper_en, 0x5026},
				{stormtrooper_en, 0x50CB},
				{stormtrooper_en, 0x5170},
				{stormtrooper_en, 0x5215},
				{stormtrooper_en, 0x52CA},
				{stormtrooper_en, 0x537F},
				{stormtrooper_en, 0x5434},
				{stormtrooper_en, 0x54D9},
				{stormtrooper_en, 0x557E},
				{stormtrooper_en, 0x5812},
				{stormtrooper_en, 0x58B7},
				{stormtrooper_en, 0x595C},
				{stormtrooper_en, 0x5A01},
				{imperialofficer_en, 0x5AA6},
				{imperialofficer_en, 0x5B4B},
				{stormtrooper_en, 0x5BF0},
				{stormtrooper_en, 0x5D3A},
				{stormtrooper_en, 0x5DDF},
				{stormtrooper_en, 0x5E84},
				{stormtrooper_en, 0x5F29},
				{stormtrooper_en, 0x5FCE},
				{stormtrooper_en, 0x6073},

				{stormtrooper_en, "AI_BOBAFETT", {416, 43}},
				{stormtrooper_en, "AI_BOBAFETT", {417, 43}},
				{stormtrooper_en, "AI_BOBAFETT", {418, 43}},
				{stormtrooper_en, "AI_BOBAFETT", {419, 43}},
				{stormtrooper_en, "AI_BOBAFETT", {420, 43}},

				{stormtrooper_en, "LEVEL", {101, 47}},
				{stormtrooper_en, "LEVEL", {114, 47}},
				{stormtrooper_en, "LEVEL", {127, 51}},

				{stormtrooper_en, "LEVEL1", {18, 43}},
				{stormtrooper_en, "LEVEL1", {21, 43}},
				{stormtrooper_en, "LEVEL1", {26, 43}},
				{stormtrooper_en, "LEVEL1", {29, 43}},
				{stormtrooper_en, "LEVEL1", {58, 43}},
				{stormtrooper_en, "LEVEL1", {62, 43}},
				{stormtrooper_en, "LEVEL1", {75, 43}},
				{stormtrooper_en, "LEVEL1", {79, 43}},

				{stormtrooper_en, "LEVEL2", {60, 76}},
			}},
		{'C',
			{
				{stormtrooper_en, 0x41CD},
				{stormtrooper_en, 0x4282},
				{stormtrooper_en, 0x4337},
				{stormtrooper_en, 0x43EC},
				{stormtrooper_en, 0x4491},
				{stormtrooper_en, 0x4536},
				{stormtrooper_en, 0x45DB},
				{stormtrooper_en, 0x4680},
				{stormtrooper_en, 0x4735},
				{stormtrooper_en, 0x47EA},
				{stormtrooper_en, 0x489F},
				{stormtrooper_en, 0x49F9},
				{stormtrooper_en, 0x4A9E},
				{stormtrooper_en, 0x4B43},
				{stormtrooper_en, 0x4BE8},
				{imperialofficer_en, 0x4C8D},
				{stormtrooper_en, 0x4D32},
				{stormtrooper_en, 0x4DD7},
				{stormtrooper_en, 0x4E7C},
				{stormtrooper_en, 0x4F21},
				{stormtrooper_en, 0x4FC6},
				{stormtrooper_en, 0x506B},
				{stormtrooper_en, 0x5110},
				{stormtrooper_en, 0x51B5},

				{stormtrooper_en, "LEVEL", {136, 52}},
				{beachtrooper_en, "LEVEL", {149, 52}},
				{stormtrooper_en, "LEVEL", {190, 48}},
				{stormtrooper_en, "LEVEL", {202, 49}},
				{stormtrooper_en, "LEVEL", {252, 46}},
				{beachtrooper_en, "LEVEL", {265, 46}},

				{stormtrooper_en, "LEVEL1", {72, 76}},
				{stormtrooper_en, "LEVEL1", {85, 76}},
			}},
	};

	Jabbas = new Level("JABBASPALACE", "JABBASPALACE", "/LEVELS/EPISODE_VI/JABBASPALACE/", false,
		{princessleia_boushh, chewbacca, lukeskywalker_jedi, c3po, r2d2, hansolo_skiff}, {},
		{lukeskywalker_jedi, princessleia_boushh, hansolo_skiff, gamorreanguard, bibfortuna, palaceguard, bossk},
		{{'A', {0x4314, 0x42fd, 0x42e6, 0x42cf, 0x42b8, 0x42a1, 0x428a, 0x4273, 0x425c}},
			{'B', {0x7a38, 0x7a21, 0x7a0a, 0x79f3, 0x79dc, 0x79c5}}, {'D', {0x303a, 0x3023, 0x300c, 0x2ff5}},
			{'E', {0x9bd, 0x9a6}}},
		{},

		{{'A', {{AstroPanel, 0x4919},      //mk
				   {BountyPanel, 0x4948},  //end scene
				   {BountyPanel, 0x4977},  //open gate
				   {ProtoPanel, 0x49A6}}}, //mk

			{'B', {{ProtoPanel, 0x7C83},                          //bonus
					  {ProtoPanel, 0x7CB2}, {AstroPanel, 0x7CE1}, //droid room
					  {AstroPanel, 0x7D10}}},                     //end scene

			{'D', {{ProtoPanel, 0x3246},       //long room - end
					  {AstroPanel, 0x3275},    //long room - bridge
					  {ImperialPanel, 0x32A4}, //minikit
					  {BountyPanel, 0x32D3}}}, //go to rancor

			{'E', {{AstroPanel, 0xB46},       //left gamorrean
					  {ProtoPanel, 0xB75}}}}, //right gamorrean

		{{'A', {{BountyHat, 0x49F4}}},    //first hat
			{'B', {{BountyHat, 0x7D5E}}}, //second hat

			{'D', {{BountyHat, 0x3321},             //third hat
					  {StormtrooperHat, 0x3351}}}}, //bonus hat
		{9});
	Jabbas->enemies = {
		{'A',
			{
				{gamorreanguard_en, 0x3F57},
				{gamorreanguard_en, 0x3FFC},
				{gamorreanguard_en, 0x40A1},

				{gamorreanguard_en, "LEVEL1", {55, 43}},
				{gamorreanguard_en, "LEVEL1", {65, 43}},
				{gamorreanguard_en, "LEVEL1", {85, 43}},

				{gamorreanguard_en, "LEVEL2", {49, 43}},
				{gamorreanguard_en, "LEVEL2", {59, 43}},
			}},
		{'B',
			{
				{gamorreanguard_en, 0x4ACE},
				{gamorreanguard_en, 0x4B73},
				{gamorreanguard_en, 0x4C18},
				{gamorreanguard_en, 0x4CBD},
				{gamorreanguard_en, 0x4D62},
				{gamorreanguard_en, 0x4E07},
				{gamorreanguard_en, 0x4F51},

				{gamorreanguard_en, "LEVEL1", {42, 48}},
				{gamorreanguard_en, "LEVEL1", {68, 48}},
			}},
		{'D',
			{
				{gamorreanguard_en, 0x490C},
				{gamorreanguard_en, 0x49B1},
				{gamorreanguard_en, 0x4A56},
				{gamorreanguard_en, 0x4AFB},
				{gamorreanguard_en, 0x4BA0},
				{gamorreanguard_en, 0x4C45},
				{gamorreanguard_en, 0x4CEA},

				{gamorreanguard_en, "LEVEL1", {50, 47}},
				{gamorreanguard_en, "LEVEL1", {60, 47}},

				{gamorreanguard_en, "LEVEL2", {51, 47}},
				{gamorreanguard_en, "LEVEL2", {61, 47}},

				{gamorreanguard_en, "LEVEL3", {54, 47}},
				{gamorreanguard_en, "LEVEL3", {64, 47}},
			}},
		{'E',
			{
				{gamorreanguard_en, "LEVEL1", {23, 43}},
				{gamorreanguard_en, "LEVEL2", {23, 43}},
			}},
	};

	Carkoon = new Level("SARLACCPIT", "SARLACCPIT", "/LEVELS/EPISODE_VI/SARLACCPIT/", false,
		{lando_palaceguard, lukeskywalker_jedi, chewbacca, hansolo_skiff, c3po, r2d2, princessleia_slave}, {},
		{lando_palaceguard, princessleia_slave, skiffguard, bobafett},
		{{'A', {0xadb2, 0xad9b, 0xad84, 0xad6d, 0xad56, 0xad3f, 0xad28, 0xad11, 0xacfa}},
			{'B', {0x5a7a, 0x5a63, 0x5a4c, 0x5a35, 0x5a1e}},
			{'C', {0x6e0b, 0x6df4, 0x6ddd, 0x6dc6, 0x6daf, 0x6d98, 0x6d81}}},
		{},

		{{'A', {{ProtoPanel, 0xB67F}, {ProtoPanel, 0xB6AE}, {AstroPanel, 0xB6DD}}}, //bonus
			{'B', {{ProtoPanel, 0x5C2B}}},                                          //elevator

			{'C', {{ProtoPanel, 0x6FC3},       //target
					  {AstroPanel, 0x6FF2}}}}, //cannon ammo
		{}, {14, 15});
	Carkoon->enemies = {
		{'A',
			{
				{gamorreanguard_en, 0x64E6},
				{skiffguard_en, 0x659B},
				{skiffguard_en, 0x6650},
				{skiffguard_en, 0x6705},
				{skiffguard_en, 0x67BA},
				{skiffguard_en, 0x686F},
				{skiffguard_en, 0x6924},
				{skiffguard_en, 0x69D9},
				{skiffguard_en, 0x6A8E},
				{skiffguard_en, 0x6B43},
				{skiffguard_en, 0x6BF8},
				{skiffguard_en, 0x6CAD},
				{skiffguard_en, 0x6D62},
				{skiffguard_en, 0x6EBC},
				{skiffguard_en, 0x6F61},
				{skiffguard_en, 0x7006},

				{skiffguard_en, "LEVEL", {161, 25}},
				{skiffguard_en, "LEVEL", {173, 59}},
				{skiffguard_en, "LEVEL", {186, 25}},
				{skiffguard_en, "LEVEL", {187, 25}},
				{skiffguard_en, "LEVEL", {188, 25}},
			}},
		{'B',
			{
				{gamorreanguard_en, 0x2EA6},
				{gamorreanguard_en, 0x2F4B},
				{gamorreanguard_en, 0x2FF0},
				{skiffguard_en, 0x3095},
				{gamorreanguard_en, 0x313A},
				{skiffguard_en, 0x31DF},
				{skiffguard_en, 0x3284},
				{skiffguard_en, 0x3329},
				{skiffguard_en, 0x33CE},
				{skiffguard_en, 0x3473},
				{skiffguard_en, 0x3518},
				{skiffguard_en, 0x35BD},
				{skiffguard_en, 0x3662},
				{skiffguard_en, 0x3707},
				{skiffguard_en, 0x37AC},
				{skiffguard_en, 0x3851},
				{gamorreanguard_en, 0x38F6},
				{gamorreanguard_en, 0x399B},

				{gamorreanguard_en, "LEVEL1", {27, 43}},
				{gamorreanguard_en, "LEVEL1", {29, 43}},
			}},
		{'C',
			{
				{skiffguard_en, 0x3CB0},
				{skiffguard_en, 0x3D55},
				{gamorreanguard_en, 0x3DFA},

				{gamorreanguard_en, "LEVEL", {96, 45}},
				{gamorreanguard_en, "LEVEL", {100, 45}},
				{skiffguard_en, "LEVEL", {113, 45}},
				{skiffguard_en, "LEVEL", {117, 45}},
				{gamorreanguard_en, "LEVEL", {149, 45}},
				{gamorreanguard_en, "LEVEL", {153, 45}},
				{skiffguard_en, "LEVEL", {166, 45}},
				{skiffguard_en, "LEVEL", {170, 45}},
				{gamorreanguard_en, "LEVEL", {201, 45}},
				{gamorreanguard_en, "LEVEL", {205, 45}},
				{skiffguard_en, "LEVEL", {218, 45}},
				{skiffguard_en, "LEVEL", {222, 45}},
				{gamorreanguard_en, "LEVEL", {254, 45}},
				{gamorreanguard_en, "LEVEL", {258, 45}},
				{skiffguard_en, "LEVEL", {271, 45}},
				{skiffguard_en, "LEVEL", {275, 45}},
			}},
	};

	Showdown = new Level("SPEEDERCHASE", "SPEEDERCHASE", "/LEVELS/EPISODE_VI/SPEEDERCHASE/", false,
		{princessleia_endor, lukeskywalker_endor}, {},
		{princessleia_endor, lukeskywalker_endor, atat_driver, scouttrooper},
		{{'A', {0x10864, 0x1084d, 0x10836, 0x1081f, 0x10808, 0x107f1, 0x107da, 0x107c3, 0x107ac, 0x10795, 0x1077e,
				   0x10767, 0x10750, 0x10739, 0x10722, 0x1070b, 0x106f4, 0x106dd, 0x106c6, 0x106af, 0x10698}}},
		{},

		{{'A', {{ImperialPanel, 0x11F2C}}}}, //rb
		{}, {8, 12});
	Showdown->enemies = {
		{'A',
			{
				{stormtrooper_en, "LEVEL3", {53, 52}},
				{stormtrooper_en, "LEVEL3", {98, 52}},
				{stormtrooper_en, "LEVEL3", {143, 52}},
				{stormtrooper_en, "LEVEL3", {190, 52}},

				{stormtrooper_en, "LEVEL4", {26, 102}},
				{stormtrooper_en, "LEVEL4", {29, 102}},

				{stormtrooper_en, "MELEE_WALKER", {10, 21}},

				{scouttrooper_en, "AI_SPEEDERBIKE", {19, 21}},

				{scouttrooper_en, "PLAYERSPEEDER", {20, 21}},
			}},
	};

	Endor = new Level("ENDORBATTLE", "ENDORBATTLE", "/LEVELS/EPISODE_VI/ENDORBATTLE/", false,
		{hansolo_endor, princessleia_endor, r2d2, chewbacca, c3po, wicket}, {}, {hansolo_endor, wicket, ewok},
		{{'A', {0x79f4, 0x79dd, 0x79c6, 0x79af, 0x796a, 0x7953, 0x793c}},
			{'B', {0xa703, 0xa6ec, 0xa6d5, 0xa6be, 0xa6a7}}, {'C', {0x6ae3, 0x6acc, 0x6ab5, 0x6a9e, 0x6a87}},
			{'D', {0xa9b7, 0xa9a0, 0xa972, 0xa95b}}},
		{},

		{{'A', {{ProtoPanel, 0x7EAA}}},    //drops grapple point (story)
			{'B', {{ProtoPanel, 0xA9DE}}}, //start 12 button
			{'C', {{AstroPanel, 0x6D30}}}, //enter bunker

			{'D', {{AstroPanel, 0xAC41},                                //right side - elevator
					  {ProtoPanel, 0xAC70},                             //right side - unlock lever
					  {AstroPanel, 0xAC9F},                             //right side - drop hatch pieces
					  {ProtoPanel, 0xACCE},                             //left side - unlock lever
					  {ImperialPanel, 0xACFD}, {ProtoPanel, 0xAD2C}}}}, //left side - bonus

		{{'D', {{StormtrooperHat, 0xAD7A}}}}, {11, 12, 13, 24});
	Endor->enemies = {
		{'A',
			{
				{scouttrooper_en, "LEVEL", {104, 146}},
				{stormtrooper_en, "LEVEL", {104, 126}},
			}},
		{'B',
			{
				{scouttrooper_en, 0x2542},
				{scouttrooper_en, 0x25E7},
				{scouttrooper_en, 0x268C},
				{scouttrooper_en, 0x2731},
				{scouttrooper_en, 0x27D6},
				{scouttrooper_en, 0x288B},
				{scouttrooper_en, 0x2940},
				{scouttrooper_en, 0x29F5},
				{scouttrooper_en, 0x2AAA},
				{scouttrooper_en, 0x2B5F},
				{scouttrooper_en, 0x2C14},
				{stormtrooper_en, 0x2CC9},
				{scouttrooper_en, 0x2D6E},
				{scouttrooper_en, 0x2E13},
				{scouttrooper_en, 0x2EB8},
				{scouttrooper_en, 0x2F5D},
			}},
		{'C',
			{
				{stormtrooper_en, 0x2A62},
				{stormtrooper_en, 0x2B07},
				{stormtrooper_en, 0x2C51},
				{stormtrooper_en, 0x2CF6},
				{stormtrooper_en, 0x2DAB},
				{stormtrooper_en, 0x2F05},
				{stormtrooper_en, 0x2FAA},
				{stormtrooper_en, 0x304F},
				{stormtrooper_en, 0x30F4},
				{stormtrooper_en, 0x342D},
				{stormtrooper_en, 0x34E2},
				{stormtrooper_en, 0x3597},
				{stormtrooper_en, 0x364C},
				{stormtrooper_en, 0x3701},
				{stormtrooper_en, 0x37B6},
				{stormtrooper_en, 0x385B},

				{stormtrooper_en, "LEVEL", {80, 99}},
				{scouttrooper_en, "LEVEL", {80, 79}},
				{stormtrooper_en, "LEVEL", {93, 99}},
				{scouttrooper_en, "LEVEL", {93, 79}},
				{stormtrooper_en, "LEVEL", {107, 104}},
				{scouttrooper_en, "LEVEL", {107, 84}},

				{gamorreanguard_en, "LEVEL", {146, 108}},
			}},
		{'D',
			{
				{stormtrooper_en, 0x2756},
				{stormtrooper_en, 0x27FB},
				{stormtrooper_en, 0x28A0},
				{stormtrooper_en, 0x2945},
				{stormtrooper_en, 0x29EA},
				{stormtrooper_en, 0x2A8F},
				{stormtrooper_en, 0x2B34},
				{stormtrooper_en, 0x2BD9},
				{stormtrooper_en, 0x2C7E},
				{imperialofficer_en, 0x2D23},
				{scouttrooper_en, 0x2DC8},
				{stormtrooper_en, 0x2E6D},
				{stormtrooper_en, 0x2F12},
				{stormtrooper_en, 0x2FB7},
				{stormtrooper_en, 0x305C},
				{imperialofficer_en, 0x3101},
				{stormtrooper_en, 0x31A6},
				{stormtrooper_en, 0x324B},
				{imperialofficer_en, 0x32F0},
				{imperialofficer_en, 0x3395},
				{stormtrooper_en, 0x343A},
				{stormtrooper_en, 0x34DF},
				{stormtrooper_en, 0x3584},
				{stormtrooper_en, 0x3629},
				{stormtrooper_en, 0x36CE},
				{stormtrooper_en, 0x3773},
				{stormtrooper_en, 0x3818},
				{stormtrooper_en, 0x38BD},

				{scouttrooper_en, "LEVEL", {64, 55}},
				{scouttrooper_en, "LEVEL", {90, 45}},
			}},
	};

	Destiny = new Level("EMPERORFIGHT", "EMPERORFIGHT", "/LEVELS/EPISODE_VI/EMPERORFIGHT/", false,
		{lukeskywalker_jedi, darthvader}, {}, {darthvader, imperialguard, theemperor},
		{{'A', {0xc7d7, 0xc7c0, 0xc7a9, 0xc792, 0xc77b, 0xc764, 0xc74d, 0xc736, 0xc71f, 0xc708, 0xc6f1, 0xc6da, 0xc6c3,
				   0xb669, 0xb652}},
			{'B', {0x3c13, 0x3bfc, 0x3be5, 0x3bce, 0x3b44, 0x3b2d}}},
		{},

		{{'A', {{ImperialPanel, 0xCA4A}, {BountyPanel, 0xCA79}, {ProtoPanel, 0xCAA8},       //bonus
				   {BountyPanel, 0xCAD7}, {ImperialPanel, 0xCB06}, {BountyPanel, 0xCB35}}}, //bonus

			{'B', {{ProtoPanel, 0x3F78}, {AstroPanel, 0x3FA7}}}}, //bonus
		{}, {5});
	Destiny->enemies = {
		{'A',
			{
				{imperialguard_en, "LEVEL3", {15, 47}},
				{imperialguard_en, "LEVEL3", {16, 47}},

				{imperialguard_en, "LEVEL4", {16, 47}},
				{imperialguard_en, "LEVEL4", {17, 47}},
			}},
		{'B',
			{
				{imperialguard_en, 0xAA8},
				{imperialguard_en, 0xB4D},
			}},
	};

	ITDS = new Level("DEATHSTAR2BATTLE", "DEATHSTAR2BATTLE", "/LEVELS/EPISODE_VI/DEATHSTAR2BATTLE/", true,
		{millenniumfalcon, xwing}, {}, {admiralackbar},
		{{'A', {0xd9c, 0xd85, 0xd6e, 0xd57}}, {'B', {0x34b2, 0x349b, 0x3484, 0x346d}},
			{'C', {0x103a, 0x1023, 0x100c, 0xff5}}, {'D', {0x1f1b, 0x1f04, 0x1eed}}, {'E', {0x1dae, 0x1d97}},
			{'F', {0x1f3f, 0x1f28}}, {'G', {0x30bc, 0x30a5}}},
		{}, {}, {}, {5, 6, 7});
	ITDS->enemies = {
		{'A',
			{
				{tieinterceptor_en, "LEVEL", {17, 25}, flyer},
				{tiefighter_en, "LEVEL", {18, 25}, flyer},
				{tiebomber_en, "LEVEL", {19, 25}, flyer},
				{tieinterceptor_en, "LEVEL", {21, 25}, flyer},
				{tiefighter_en, "LEVEL", {22, 25}, flyer},
				{tiebomber_en, "LEVEL", {23, 25}, flyer},
				{tieinterceptor_en, "LEVEL", {28, 25}, flyer},
				{tiefighter_en, "LEVEL", {29, 25}, flyer},
				{tiebomber_en, "LEVEL", {30, 25}, flyer},
				{tieinterceptor_en, "LEVEL", {33, 25}, flyer},
				{tiefighter_en, "LEVEL", {34, 25}, flyer},
				{tiebomber_en, "LEVEL", {35, 25}, flyer},

				{tieinterceptor_en, "LEVEL", {70, 43}, flyer},
				{tiefighter_en, "LEVEL", {70, 25}, flyer},
				{tiebomber_en, "LEVEL", {82, 25}, flyer},
			}},
		{'B',
			{
				{tieinterceptor_en, "LEVEL", {62, 49}, flyer},
				{tiefighter_en, "LEVEL", {62, 31}, flyer},
				{tieinterceptor_en, "LEVEL", {75, 49}, flyer},
				{tiefighter_en, "LEVEL", {75, 31}, flyer},
				{tieinterceptor_en, "LEVEL", {76, 49}, flyer},
				{tiefighter_en, "LEVEL", {76, 31}, flyer},
				{tieinterceptor_en, "LEVEL", {89, 49}, flyer},
				{tiefighter_en, "LEVEL", {89, 31}, flyer},
				{tieinterceptor_en, "LEVEL", {102, 49}, flyer},
				{tiefighter_en, "LEVEL", {102, 31}, flyer},
				{tieinterceptor_en, "LEVEL", {103, 49}, flyer},
				{tiefighter_en, "LEVEL", {103, 31}, flyer},
			}},
		{'C',
			{
				{tieinterceptor_en, "LEVEL", {47, 49}, flyer},
				{tiefighter_en, "LEVEL", {47, 31}, flyer},
				{tieinterceptor_en, "LEVEL", {59, 49}, flyer},
				{tiefighter_en, "LEVEL", {59, 31}, flyer},
			}},
		{'D',
			{
				{tiefighter_en, "LEVEL", {33, 25}, flyer},
				{tieinterceptor_en, "LEVEL", {46, 25}, flyer},
			}},
		{'E',
			{
				{tieinterceptor_en, "LEVEL", {27, 49}, flyer},
				{tiefighter_en, "LEVEL", {27, 31}, flyer},
				{tiefighter_en, "LEVEL", {37, 31}, flyer},
				{tiefighter_en, "LEVEL", {38, 31}, flyer},
				{tiefighter_en, "LEVEL", {48, 31}, flyer},
				{tiefighter_en, "LEVEL", {49, 31}, flyer},
				{tieinterceptor_en, "LEVEL", {50, 49}, flyer},
				{tiefighter_en, "LEVEL", {50, 31}, flyer},
			}},
		{'F',
			{
				{tieinterceptor_en, "LEVEL", {27, 49}, flyer},
				{tiefighter_en, "LEVEL", {27, 31}, flyer},
				{tiefighter_en, "LEVEL", {37, 31}, flyer},
				{tiefighter_en, "LEVEL", {38, 31}, flyer},
				{tiefighter_en, "LEVEL", {48, 31}, flyer},
				{tiefighter_en, "LEVEL", {49, 31}, flyer},
				{tieinterceptor_en, "LEVEL", {50, 49}, flyer},
				{tiefighter_en, "LEVEL", {50, 31}, flyer},
			}},
		{'G',
			{
				{tieinterceptor_en, "LEVEL", {27, 49}, flyer},
				{tiefighter_en, "LEVEL", {27, 31}, flyer},
				{tiefighter_en, "LEVEL", {37, 31}, flyer},
				{tiefighter_en, "LEVEL", {38, 31}, flyer},
				{tiefighter_en, "LEVEL", {48, 31}, flyer},
				{tiefighter_en, "LEVEL", {49, 31}, flyer},
				{tieinterceptor_en, "LEVEL", {50, 49}, flyer},
				{tiefighter_en, "LEVEL", {50, 31}, flyer},
			}},
	};

	//PodraceOriginal = new Level("PODRACE", "PODRACE", "/LEVELS/EPISODE_I/PODRACE/", true,
	//	{fakeAnakinsPod, fakeAnakinsPodGreen}, {},
	//	{},
	//	{}, {}, {}, {});

	Anakinsflight = new Level("ANAKINSFLIGHT", "ANAKINSFLIGHT", "/LEVELS/ANAKINSFLIGHT/", false,
		{naboostarfighter, naboostarfighter_lime}, {}, {naboostarfighter, naboostarfighter_lime}, {}, {}, {}, {});

	ANewHope =
		new Level("ANEWHOPE", "ANEWHOPE", "/LEVELS/EPISODE_III/ANEWHOPE/", false, {darthvader, stormtrooper, c3po}, {},
			{}, {}, {}, {{'A', {{ProtoPanel, 0x6771}, {ProtoPanel, 0x67A0}, {ProtoPanel, 0x67CF}}}}, {}); //story

	BHM = new Level("", "", "TEST", false, {bobafett, greedo, ig88, fourlom, bossk, dengar},
		{quigonjinn, amidala, jarjarbinks, macewindu, kitfisto, luminara, kiadimundi, rebelscum, shaakti,
			clone_ep3_sand, r2d2, benkenobi, chewbacca, princessleia, admiralackbar, yoda, c3po, landocalrissian,
			lukeskywalker_tatooine, hansolo},
		{}, {}, {}, {}, {});

	Cantina = new Level("MAP", "MAP", "/LEVELS/MAP/", false, {}, {}, {}, {}, {}, {}, {{'\0', {{RandomHat, 0x12402}}}});

	BHM->fakeLevel = true;
	Cantina->fakeLevel = true;
}
