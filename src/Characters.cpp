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

extern std::vector<Playable*> enemies;

extern Playable* defaultCharacter;

extern LogicType logicType;

extern std::vector<Playable*> pls; //Characters and Vehicles
extern std::vector<Playable*> chs; //Characters
extern std::vector<Playable*> vhs; //Vehicles

Playable::Playable(std::string myName, std::string myRealName, int myPrice, int myAddress, float mySpeed,
	uint64_t myAttributes, std::unordered_map<enemyScp, std::string> myChart, scpInfoArr myAtInfo,
	scpInfoArr myBlockInfo, scpInfoArr mySnipeInfo)
    : name(myName), realName(myRealName), price(myPrice), address(myAddress), speed(mySpeed), enemyChart(myChart),
      nAttackInfo(myAtInfo.conditions, myAtInfo.actions, myAtInfo.appendix),
      nBlockInfo(myBlockInfo.conditions, myBlockInfo.actions, myBlockInfo.appendix),
      nSnipeInfo(mySnipeInfo.conditions, mySnipeInfo.actions, mySnipeInfo.appendix), attributes(myAttributes) {

	//if (!this->passive) this->active = true;

	if (baddy) enemies.push_back(this);
	if (fake) return;
	pls.push_back(this);
	if (vehicle) {
		if (greenVeh || !vgreen) {
			vhs.push_back(this);
		}
	} else {
		if (extog || !extratoggle) {
			chs.push_back(this);
		}
	}
}
