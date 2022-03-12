#pragma once
#include "Character.h"
#include "Types.h"
#include <list>
#include <iostream>
#include "Grid.h"
using namespace std;
class BattleField
{
public:

	BattleField(int xLength, int yLength);



private:

	Grid* grid;
	Character *PlayerCharacter, *EnemyCharacter;
	bool order;
	bool gameOver;


	void Setup();

	void CreatePlayerCharacter();

	void CreateEnemyCharacter();

	void StartGame();

	void StartTurn();

	void HandleTurn();

	int GetRandomInt(int min, int max);

	void AlocateCharacters();

};


