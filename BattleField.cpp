#include "Grid.h"
#include "BattleField.h"
#include "Types.h"
#include "Character.h"
#include <iostream>
#include "BattleField.h"
#include <list>
#include <string>

using namespace std;

BattleField::BattleField(int xLength, int yLength) {
    
    grid = new Grid(xLength, yLength);
    Setup();
}

void BattleField::Setup()
{
    CreatePlayerCharacter();
    CreateEnemyCharacter();
    AlocateCharacters();
    gameOver = false;
    StartGame();
}





void BattleField::CreatePlayerCharacter()
{

    int choice;
    int classIndex = -1;
    do{

        //asks for the player to choose between for possible classes via console.
        cout << "Choose Between One of this Classes:\n";
        cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer\n";

        cin >> choice;
        if (cin.good())
        {
            if (choice >= 1 && choice <= 4)
            {
                classIndex = choice;
            }
            else
            {
                cout << "Invalid input;" << endl;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input;" << endl;
        }

    } while (classIndex < 0);


    Types::CharacterClass characterClass = (Types::CharacterClass)classIndex;
    cout<<"Player Class Choice: {characterClass}";
    PlayerCharacter = new Character(characterClass);
    PlayerCharacter->Health = 100;
    PlayerCharacter->BaseDamage = 20;
    PlayerCharacter->PlayerIndex = 0;

    

}

void BattleField::CreateEnemyCharacter()
{
    //randomly choose the enemy class and set up vital variables
    
    int randomInteger = GetRandomInt(1, 4);
    Types::CharacterClass enemyClass = (Types::CharacterClass)randomInteger;
    cout << "Enemy Class Choice: {enemyClass}";
    EnemyCharacter = new Character(enemyClass);
    EnemyCharacter->Health = 100;
    EnemyCharacter->BaseDamage = 20;
    EnemyCharacter->PlayerIndex = 1;

}

void BattleField::StartGame()
{
    //populates the character variables and targets
    EnemyCharacter->target = PlayerCharacter;
    PlayerCharacter->target = EnemyCharacter;

    //Define randomly who goes first
    order = rand() % 2;

    StartTurn();

}

void BattleField::StartTurn() 
{

    while (!gameOver)
    {

        if (order)
        {
            PlayerCharacter->StartTurn();
            EnemyCharacter->StartTurn();
        }
        else
        {
            EnemyCharacter->StartTurn();
            PlayerCharacter->StartTurn();
        }

        HandleTurn();
    }

}

void BattleField::HandleTurn()
{
    if (PlayerCharacter->IsDead)
    {
        cout << "Player team wins!!";
        gameOver = true;
    }
    else if (EnemyCharacter->IsDead)
    {
        cout << "Enemy team wins!!";
        gameOver = true;
    }
}

int BattleField::GetRandomInt(int min, int max)
{

    if (max < min)
    {
        int aux = min;
        min = max;
        max = aux;
    }

    int range = max - min + 1;
    int index = rand() % range + min ;
    return index;
}

void BattleField::AlocateCharacters()
{

    //Set player character in random position of first column
    int random = GetRandomInt(0,grid->getGridBoundaryY()-1);
    Types::GridBox* RandomLocation = grid->getBoxAtPosition(random,0);
    RandomLocation->isOcupied = true;
    PlayerCharacter->currentBox = RandomLocation;


    //Set enemy character in random position of last column
    random = GetRandomInt(0, grid->getGridBoundaryY() - 1);
    RandomLocation = grid->getBoxAtPosition(random, grid->getGridBoundaryY()-1);


    grid->drawBattlefield();



}