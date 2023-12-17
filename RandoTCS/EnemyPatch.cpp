#include "EnemyPatch.h"
#include "OtherStuff.h"
#include "externData.h"
#include "Defines.h"

extern std::string out;

struct patchdata {
	Level* lev;
	char scene;
	std::string scp;

	std::string toString() {
		return getSCP(lev, scene, scp);
	}
};

void mainRegex(std::string pd) {
	regexFile(pd, "state (\\w+)\\s*\\{\\s*Conditions((?:(?!Conditions)[\\s\\S])+?)"
		"Actions((?:(?!Actions)[\\s\\S])+?)"
		"EngageOpponent \"goalrange ((?:\\w|\\d|\\.)+)\" \"firerange(?:=| )((?:\\w|\\d|\\.)+)\""
		"([\\s\\S]+?)\\}\\s+?\\}",

		"state $1 {\n\tConditions {"
		"\n\t\tif IAmA \"gamorreanguard\" == 1 goto $1gamorreanguard"
		"\n\t\tif IAmA \"imperialguard\" == 1 goto $1imperialguard"
		"\n\t\tif IAmA \"bodyguard\" == 1 goto $1imperialguard"
		"\n\t\tif AlwaysTrue == 1 goto $1vanilla"
		"\n\t}\n\tActions {\n\t}\n}\n\n"
		"state $1vanilla {\n\tConditions $2Actions $3EngageOpponent \"goalrange $4\" \"firerange=$5\"$6}\n}\n\n"
		"state $1imperialguard {\n\tConditions $2Actions $3AttackOpponent \"goalrange 0.15\"$6}\n}\n\n"
		"state $1gamorreanguard {\n\tConditions $2Actions $3AttackOpponent \"goalrange 0.20\"$6}\n}\n\n"
	);
};

void fixSnipe(std::string pd) {
	regexFile(pd, "state (\\w+)\\s*\\{\\s*Conditions\\s*\\{((?:(?!Conditions)[\\s\\S])+?)\\}\\s*Actions\\s*\\{((?:(?!Actions)[\\s\\S])+?)EngageOpponent \"static\" \"(.*?)\"([\\s\\S]+?)\\}\\s+?\\}",
		"state $1 {\n\tConditions {"
		"\n\t\tif IAmA \"gamorreanguard\" == 1 goto $1togamorreanguard"
		"\n\t\tif IAmA \"imperialguard\" == 1 goto $1toimpguard"
		"\n\t\tif IAmA \"bodyguard\" == 1 goto $1toimpguard"
		"\n\t\tif AlwaysTrue == 1 goto $1vanilla"
		"\n\t}\n\tActions {\n\t}\n}\n\n"
		"state $1vanilla {\n\tConditions {$2}\n\tActions {$3EngageOpponent \"static\" \"$4\"$5\n\t}\n}\n\n"
		"state $1toimpguard {\n\tConditions {\n\t\tif GotOpponent == 1 goto $1impguard\n\t\tif Timer > 5 and$2}\n\tActions {\n\t\tResetTimer\n\t\tFollowPlayer \"run\"$6\n\t}\n}\n\n"
		"state $1impguard {\n\tConditions {\n\t\tif GotOpponent == 0 goto $1toimpguard\n\t}\n\tActions {\n\t\tAttackOpponent \"goalrange 0.15\"\n\t}\n}\n\n"
		"state $1togamorreanguard {\n\tConditions {\n\t\tif GotOpponent == 1 goto $1gamorreanguard\n\t\tif Timer > 5 and$2}\n\tActions {\n\t\tResetTimer\n\t\tFollowPlayer \"run\"$6\n\t}\n}\n\n"
		"state $1gamorreanguard {\n\tConditions {\n\t\tif GotOpponent == 0 goto $1togamorreanguard\n\t}\n\tActions {\n\t\tAttackOpponent \"goalrange 0.20\"\n\t}\n}\n\n"
		//"state $1toimpguard {\n\tConditions {\n\t\tif GotOpponent == 1 goto $1impguard\n\t\tif Timer > 5 and$2}\n\tActions {$3ResetTimer\n\t\tFollowPlayer \"run\"$6\n\t}\n}\n\n"
		//"state $1impguard {\n\tConditions {$2}\n\tActions {\n\t\tAttackOpponent \"goalrange 0.15\"\n\t}\n}\n\n"
		//"state $1togamorreanguard {\n\tConditions {\n\t\tif GotOpponent == 1 goto $1gamorreanguard\n\t\tif Timer > 5 and$2}\n\tActions {$3ResetTimer\n\t\tFollowPlayer \"run\"$6\n\t}\n}\n\n"
		//"state $1gamorreanguard {\n\tConditions {$2}\n\tActions {\n\t\tAttackOpponent \"goalrange 0.20\"\n\t}\n}\n\n"
	);
};

void chase(std::string pd) {
	regexFile(pd, "state (\\w+)\\s*\\{\\s*Conditions((?:(?!Conditions)[\\s\\S])+?)"
		"Actions((?:(?!Actions)[\\s\\S])+?)"
		"EngageOpponent \"goalrange ((?:\\w|\\d|\\.)+)\" \"firerange(?:=| )((?:\\w|\\d|\\.)+)\""
		"([\\s\\S]+?)\\}\\s+?\\}",
		"state $1 {\n\tConditions {"
		"\n\t\tif IAmA \"gamorreanguard\" == 1 goto $1togamorreanguard"
		"\n\t\tif IAmA \"imperialguard\" == 1 goto $1toimpguard"
		"\n\t\tif IAmA \"bodyguard\" == 1 goto $1toimpguard"
		"\n\t\tif AlwaysTrue == 1 goto $1vanilla"
		"\n\t}\n\tActions {\n\t}\n}\n\n"
		"state $1vanilla {\n\tConditions {$2}\n\tActions {$3EngageOpponent \"static\" \"$4\"$5\n\t}\n}\n\n"
		"state $1toimpguard {\n\tConditions {\n\t\tif GotOpponent == 1 goto $1impguard\n\t\tif Timer > 5 and$2}\n\tActions {\n\t\tResetTimer\n\t\tFollowPlayer \"run\"$6\n\t}\n}\n\n"
		"state $1impguard {\n\tConditions {\n\t\tif GotOpponent == 0 goto $1toimpguard\n\t}\n\tActions {\n\t\tAttackOpponent \"goalrange 0.15\"\n\t}\n}\n\n"
		"state $1togamorreanguard {\n\tConditions {\n\t\tif GotOpponent == 1 goto $1gamorreanguard\n\t\tif Timer > 5 and$2}\n\tActions {\n\t\tResetTimer\n\t\tFollowPlayer \"run\"$6\n\t}\n}\n\n"
		"state $1gamorreanguard {\n\tConditions {\n\t\tif GotOpponent == 0 goto $1togamorreanguard\n\t}\n\tActions {\n\t\tAttackOpponent \"goalrange 0.20\"\n\t}\n}\n\n"
		//"state $1toimpguard {\n\tConditions {\n\t\tif GotOpponent == 1 goto $1impguard\n\t\tif Timer > 5 and$2}\n\tActions {$3ResetTimer\n\t\tFollowPlayer \"run\"$6\n\t}\n}\n\n"
		//"state $1impguard {\n\tConditions {$2}\n\tActions {\n\t\tAttackOpponent \"goalrange 0.15\"\n\t}\n}\n\n"
		//"state $1togamorreanguard {\n\tConditions {\n\t\tif GotOpponent == 1 goto $1gamorreanguard\n\t\tif Timer > 5 and$2}\n\tActions {$3ResetTimer\n\t\tFollowPlayer \"run\"$6\n\t}\n}\n\n"
		//"state $1gamorreanguard {\n\tConditions {$2}\n\tActions {\n\t\tAttackOpponent \"goalrange 0.20\"\n\t}\n}\n\n"
	);
};
void reAttack(std::string pd) {
	regexFile(pd, "state (\\w+)\\s*\\{\\s*ReferenceScript\\s*\\{\\s*Script=Attack\\s*Source=(\\w+)\\s*ReturnState=(\\w+)\\s*Conditions\\s*\\{([\\s\\S]*?)\\}\\s*\\}\\s*?Conditions\\s*\\{((?:(?!Conditions)[\\s\\S])+?)\\}\\s*Actions\\s*\\{((?:(?!Actions)[\\s\\S])+?)\\}\\s+?\\}",
		"state $1 {\n\tConditions {"
		"\n\t\tif IAmA \"gamorreanguard\" == 1 goto $1gamorreanguard"
		"\n\t\tif IAmA \"imperialguard\" == 1 goto $1imperialguard"
		"\n\t\tif IAmA \"bodyguard\" == 1 goto $1imperialguard"
		"\n\t\tif AlwaysTrue == 1 goto $1vanilla"
		"\n\t}\n\tActions {\n\t}\n}\n\n"
		"state $1vanilla {\n\tReferenceScript {\n\t\tScript=Attack\n\t\tSource=$2\n\t\tReturnState=$3\n\t\tConditions {$4}\n\t}\n\tConditions {$5}\n\tActions {$6}\n}\n\n"
		"state $1imperialguard {\n\tReferenceScript {\n\t\tScript=bodyguard\n\t\tSource=$2\n\t\tReturnState=$3\n\t\tConditions {$4}\n\t}\n\tConditions {\n\t\tif Timer > 5 and$5}\n\tActions {\n\t\tResetTimer$6}\n}\n\n"
		"state $1gamorreanguard {\n\tReferenceScript {\n\t\tScript=bodyguardG\n\t\tSource=$2\n\t\tReturnState=$3\n\t\tConditions {$4}\n\t}\n\tConditions {\n\t\tif Timer > 5 and$5}\n\tActions {\n\t\tResetTimer$6}\n}\n\n",
		true);
};

void reChatting(std::string pd) {
	regexFile(pd, "state (\\w+)\\s*\\{\\s*ReferenceScript\\s*\\{\\s*Script=Attack\\s*Source=(\\w+)\\s*ReturnState=(\\w+)\\s*Conditions\\s*\\{([\\s\\S]*?)\\}\\s*\\}\\s*?Conditions\\s*\\{((?:(?!Conditions)[\\s\\S])+?)\\}\\s*Actions\\s*\\{((?:(?!Actions)[\\s\\S])+?)\\}\\s+?\\}",
		"state $1 {\n\tConditions {"
		"\n\t\tif IAmA \"gamorreanguard\" == 1 goto $1gamorreanguard"
		"\n\t\tif IAmA \"imperialguard\" == 1 goto $1imperialguard"
		"\n\t\tif IAmA \"bodyguard\" == 1 goto $1imperialguard"
		"\n\t\tif AlwaysTrue == 1 goto $1vanilla"
		"\n\t}\n\tActions {\n\t}\n}\n\n"
		"state $1vanilla {\n\tReferenceScript {\n\t\tScript=Chatting\n\t\tSource=$2\n\t\tReturnState=$3\n\t\tConditions {$4}\n\t}\n\tConditions {$5}\n\tActions {$6}\n}\n\n"
		"state $1imperialguard {\n\tReferenceScript {\n\t\tScript=impguard\n\t\tSource=$2\n\t\tReturnState=$3\n\t\tConditions {$4}\n\t}\n\tConditions {\n\t\tif Timer > 5 and$5}\n\tActions {\n\t\tResetTimer$6}\n}\n\n"
		"state $1gamorreanguard {\n\tReferenceScript {\n\t\tScript=gamorreanguard\n\t\tSource=$2\n\t\tReturnState=$3\n\t\tConditions {$4}\n\t}\n\tConditions {\n\t\tif Timer > 5 and$5}\n\tActions {\n\t\tResetTimer$6}\n}\n\n",
		true);
};

void PatchEnemies() {

	std::filesystem::rename(getSCP(Chancellor, 'F', "BODYGUARD"), SCR + "BODYGUARD.SCP");
	std::filesystem::rename(getSCP(Destiny, 'A', "IMPGUARD"), SCR + "IMPGUARD.SCP");
	std::filesystem::copy(SCR + "BODYGUARD.SCP", SCR + "BODYGUARDG.SCP");
	appendFile(SCR + "SCRIPT.TXT", "\nimpguard\nbodyguard\nbodyguardg");
	txtIns(SCR + "BODYGUARDG.SCP", "0.20", { 31, 25 }, 4);

	const std::string reg();
	const std::string reg2();
	const std::string reg3();

	const std::string regSnipe();
	mainRegex(SCR + "PATROL.SCP");
	mainRegex(SCR + "COMMANDER_PATROL.SCP");
	mainRegex(SCR + "STORM.SCP"); //??????
	fixSnipe(SCR + "SNIPER.SCP");
	reAttack(SCR + "BEACHTROOPER.SCP");


	std::vector<patchdata> minimal = {
		{Negotiations, 'A', "MISSIONBADDIE"},
		{Invasion, 'A', "STORM"},
		{Invasion, 'E', "STORM"},
		{EscapeNaboo, 'C', "MISSIONBADDIE"},

	};
	std::vector<patchdata> snipe = {

		{Negotiations, 'C', "DROIDEKA"},
	};
	std::vector<patchdata> chaser = {
		{Invasion, 'A', "BATTLEDROID"},
		{Invasion, 'C', "MISSIONBADDIE"},
		{Invasion, 'E', "BATTLEDROID"},
	};
	std::vector<patchdata> reAttacker = {
		{Negotiations, 'B', "LAZYDROID"},
	};
	std::vector<patchdata> reChatter = {
		{Negotiations, 'A', "DEACTIVATED"},
		{Negotiations, 'A', "DOORATTACK"},
		{Negotiations, 'A', "VENTDROID"},
		{Negotiations, 'C', "MTT_DROID"},
	};

	for (patchdata pd : minimal) {
		mainRegex(pd.toString());
	}

	for (patchdata pd : snipe) {
		fixSnipe(pd.toString());
	}

	for (patchdata pd : chaser) {
		chase(pd.toString());
	}

	for (patchdata pd : reAttacker) {
		reAttack(pd.toString());
	}

	for (patchdata pd : reChatter) {
		reChatting(pd.toString());
	}

	//((?:(?!Actions)[\\s\\S])+?)
	//regexFile(getSCP(Princess, 'B', "BRIDGE_TROOPS"), "state shootatobiwan((?:(?!state)[\\s\\S])+?)FollowPlayer \"run\"", "state shootatobiwan$1FollowCharacter \"character=" + Princess->party[5]->getSCP(pd.lev, pd.scene, pd.scp) + "\" \"run\"");
	//regexFile(getSCP(Princess, 'B', "BRIDGE_TROOPS"), "state lookforlocator_engageto((?:(?!state)[\\s\\S])+?)FollowPlayer \"run\"", "state lookforlocator_engageto$1                  ");

	std::cout << "Enemies patched";

}