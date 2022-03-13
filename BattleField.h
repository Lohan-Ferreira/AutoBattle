#pragma once
#include "Character.h"


class BattleField
{
public:

	BattleField(int xLength, int yLength);
	~BattleField();


private:

	Grid* grid;
	Character *playerCharacter = nullptr, *enemyCharacter = nullptr;
	std::vector<Character*> battleOrder;
	bool order = false;
	bool gameOver = false;


	void Setup();

	void CreatePlayerCharacter();

	void CreateEnemyCharacter();

	void StartGame();

	void StartTurn();

	bool HandleTurn();

	int GetRandomInt(int min, int max);

	void AlocateCharacters();

};


