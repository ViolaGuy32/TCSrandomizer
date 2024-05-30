#include "pch.h"

//#ifdef WXWIN
//#include "App.h"
//#endif

#include "Characters.h"
#include "Defines.h"
#include "OtherStuff.h"
#include "externData.h"

extern bool extog;
extern bool greenVeh;

extern Playable* defaultCharacter;

extern LogicType logicType;

extern std::vector<Playable*> pls;  //Characters and Vehicles
extern std::vector<Playable*> chs;  //Characters
extern std::vector<Playable*> vhs;  //Vehicles
extern std::vector<Playable*> mnts; //Mounts
extern std::vector<Playable*> trts; //Turrets
extern std::vector<Playable*> grbs; //GrabThings

Playable::Playable(std::string myName, std::string myRealName, int myPrice, int myAddress, float mySpeed,
	uint64_t myAttributes, uint16_t myCategories)
	: name(myName), realName(myRealName), price(myPrice), address(myAddress), speed(mySpeed), att(myAttributes),
	  categories(myCategories) {

	/*std::unordered_map<enemyScp, std::string> myChart/*, scpInfoArr myAtInfo,
		scpInfoArr myBlockInfo, scpInfoArr mySnipeInfo*/

	//enemyChart(myChart),
	/*nAttackInfo(myAtInfo.conditions, myAtInfo.actions, myAtInfo.appendix),
	nBlockInfo(myBlockInfo.conditions, myBlockInfo.actions, myBlockInfo.appendix),
	nSnipeInfo(mySnipeInfo.conditions, mySnipeInfo.actions, mySnipeInfo.appendix), */

	if (!check(Passive)) att |= Active;

	//if (att & Baddy) enemies.push_back(this);
	if (categories & c_Fake) return;
	pls.push_back(this);

	if (categories & c_Mount) {
		mnts.push_back(this);
	} else if (categories & c_Turret) {
		trts.push_back(this);
	} else if (categories & c_GrabThing) {
		grbs.push_back(this);
	} else if (categories & c_Vehicle) {
		if (greenVeh || !(categories & c_Vgreen)) {
			vhs.push_back(this);
		}
	} else {
		if (extog || !(categories & c_Extratoggle)) {
			chs.push_back(this);
		}
	}
}

bool Playable::check(uint64_t a) {
	return att & a;
}

bool Playable::checkCat(uint16_t a) {
	return categories & a;
}
