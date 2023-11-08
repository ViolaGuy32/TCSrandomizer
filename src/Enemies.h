#pragma once

enum enemyCategory { normal, walker, flyer };

struct EnemyType {
	const Playable* const type;
	const float range = 3.5;
	const enemyCategory category;
	EnemyType(const Playable* myType, const enemyCategory myCategory = normal, const float myRange = 3.5);
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
