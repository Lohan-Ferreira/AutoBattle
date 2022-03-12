#pragma once
#include "Character.h"


class BattleField
{
public:

	BattleField(int xLength, int yLength);
	~BattleField();


private:

	Grid* grid;
	Character *playerCharacter, *enemyCharacter;
	std::vector<Character*> battleOrder;
	bool order;
	bool gameOver;


	void Setup();

	void CreatePlayerCharacter();

	void CreateEnemyCharacter();

	void StartGame();

	void StartTurn();

	bool HandleTurn();

	int GetRandomInt(int min, int max);

	void AlocateCharacters();

};


