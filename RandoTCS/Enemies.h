#pragma once
#include "pch.h"
#include "Characters.h"

enum enemyCategory { normal, walker, flyer };

struct EnemyType {
	Playable* type;
	float range = 3.5;
	enemyCategory category;
	EnemyType(Playable* myType, enemyCategory myCategory = normal, float myRange = 3.5);
};

struct Enemy {
	EnemyType* vanillaType;
	unsigned int address;

	coord lncol;
	std::string file;
	EnemyType* newType;

	enemyCategory category;
	Enemy(EnemyType* myVanillaType, unsigned int myAddress, enemyCategory myCategory = normal);

	Enemy(EnemyType* myVanillaType, const char* myFile, coord myLncol, enemyCategory myCategory = normal);
};

struct EnemySet {
	char scene;
	std::vector<Enemy> enemy;
};
