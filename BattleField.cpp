#include "BattleField.h"
#include "Types.h"
#include <iostream>
#include <string>

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
        std::cout << "Choose Between One of this Classes:\n";
        std::cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer\n";

        std::cin >> choice;
        if (std::cin.good())
        {
            if (choice >= 1 && choice <= 4)
            {
                classIndex = choice;
            }
            else
            {
                std::cout << "Invalid input;" << std::endl;
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input;" << std::endl;
        }

    } while (classIndex < 0);


    Types::CharacterClass characterClass = Types::CharacterClass(classIndex);
    std::cout<<"Player Class Choice: {characterClass}\n";
    PlayerCharacter = new Character(characterClass,100,20,0);


    

}

void BattleField::CreateEnemyCharacter()
{
    //randomly choose the enemy class and set up vital variables
    
    int randomInteger = GetRandomInt(1, 4);
    Types::CharacterClass enemyClass = (Types::CharacterClass)randomInteger;
    std::cout << "Enemy Class Choice: {enemyClass}\n";
    EnemyCharacter = new Character(enemyClass,100,20,1);


}

void BattleField::StartGame()
{
    //populates the character variables and targets
    EnemyCharacter->SetTarget(PlayerCharacter);
    PlayerCharacter->SetTarget(EnemyCharacter);

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
            if(PlayerCharacter->StartTurn(grid)) grid->drawBattlefield();
            if(EnemyCharacter->StartTurn(grid)) grid->drawBattlefield();
        }
        else
        {
            if(EnemyCharacter->StartTurn(grid)) grid->drawBattlefield();
            if(PlayerCharacter->StartTurn(grid))grid->drawBattlefield();
        }

        HandleTurn();
    }

}

void BattleField::HandleTurn()
{
    if (PlayerCharacter->GetIsDead())
    {
        std::cout << "Player team wins!!";
        gameOver = true;
    }
    else if (EnemyCharacter->GetIsDead())
    {
        std::cout << "Enemy team wins!!";
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
    PlayerCharacter->SetCurrentBox(RandomLocation);


    //Set enemy character in random position of last column
    random = GetRandomInt(0, grid->getGridBoundaryY() - 1);
    RandomLocation = grid->getBoxAtPosition(random, grid->getGridBoundaryY()-1);
    RandomLocation->isOcupied = true;
    EnemyCharacter->SetCurrentBox(RandomLocation);


    grid->drawBattlefield();



}