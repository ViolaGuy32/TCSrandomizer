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

extern std::vector<Playable*> pls; //Characters and Vehicles
extern std::vector<Playable*> chs; //Characters
extern std::vector<Playable*> vhs; //Vehicles

Playable::Playable(std::string myName, std::string myRealName, int myPrice, int myAddress, float mySpeed,
	uint64_t myAttributes, std::unordered_map<enemyScp, std::string> myChart/*, scpInfoArr myAtInfo,
	scpInfoArr myBlockInfo, scpInfoArr mySnipeInfo*/)
    : name(myName), realName(myRealName), price(myPrice), address(myAddress), speed(mySpeed), enemyChart(myChart),
      /*nAttackInfo(myAtInfo.conditions, myAtInfo.actions, myAtInfo.appendix),
      nBlockInfo(myBlockInfo.conditions, myBlockInfo.actions, myBlockInfo.appendix),
      nSnipeInfo(mySnipeInfo.conditions, mySnipeInfo.actions, mySnipeInfo.appendix), */att(myAttributes) {

	if (!check(Passive)) att |= Active;

	//if (att & Baddy) enemies.push_back(this);
	if (att & Fake) return;
	pls.push_back(this);
	if (att & Vehicle) {
		if (greenVeh || !(att & Vgreen)) {
			vhs.push_back(this);
		}
	} else {
		if (extog || !(att & Extratoggle)) {
			chs.push_back(this);
		}
	}
}

bool Playable::check(uint64_t a) {
	return att & a;
}
