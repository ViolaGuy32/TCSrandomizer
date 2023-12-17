#include "pch.h"
#include "Enemies.h"

extern std::vector<EnemyType*> enemyTypes;
extern std::vector<EnemyType*> walkerTypes;
extern std::vector<EnemyType*> flyerTypes;

EnemyType::EnemyType(Playable* myType, enemyCategory myCategory, float myRange)
	: type(myType), category(myCategory), range(myRange) {

	if (category == normal) enemyTypes.push_back(this);
	else if (category == flyer) {
		flyerTypes.push_back(this);
		walkerTypes.push_back(this);
	} else if (category == walker) walkerTypes.push_back(this);
}

Enemy::Enemy(EnemyType* myVanillaType, unsigned int myAddress, enemyCategory myCategory)
	: vanillaType(myVanillaType), address(myAddress), file(""), lncol({0, 0}), newType(nullptr), category(myCategory) {}

Enemy::Enemy(EnemyType* myVanillaType, const char* myFile, coord myLncol, enemyCategory myCategory)
	: vanillaType(myVanillaType), address(0), file(myFile), lncol(myLncol), newType(nullptr), category(myCategory) {}
