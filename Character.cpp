
#include "Character.h"
#include <iostream>


Character::Character(Types::CharacterClass charcaterClass, float hp, float baseDmg, int index)
{
    damageMultiplier = 1.0;
    health = hp;
    baseDamage = baseDmg;
    playerIndex = index;
    isDead = false;
    currentBox = nullptr;
    target = nullptr;

}

Character::~Character() 
{

}




void Character::TakeDamage(float amount) 
{
	if ((health -= baseDamage) <= 0) 
	{
		Die();
	}

}

void Character::SetTarget(Character* t)
{
    target = t;
}

void Character::SetCurrentBox(Types::GridBox* newBox)
{
    if (currentBox != nullptr)
    {
        currentBox->Index = -1;
        currentBox->isOcupied = false;
        
    }
    newBox->Index = playerIndex;
    newBox->isOcupied = true;
    currentBox = newBox;

}

Types::GridBox Character::GetCurrentBox()
{
    return *currentBox;
}

void Character::Die() 
{
    isDead = true;
}

void Character::WalkTo(Grid* battlefield, int xDiff, int yDiff) 
{
    Types::GridBox* nextPos = battlefield->GetBoxAtPosition(currentBox->xIndex + Sign(xDiff), currentBox->yIndex + Sign(yDiff));
    currentBox->isOcupied = false;
    currentBox->Index = -1;
    nextPos->isOcupied = true;
    nextPos->Index = playerIndex;
    currentBox = nextPos;
}



bool Character::StartTurn(Grid* battlefield) {

    int xDiff = target->GetCurrentBox().xIndex - currentBox->xIndex;
    int yDiff = target->GetCurrentBox().yIndex - currentBox->yIndex;

    if (CheckCloseTargets(xDiff,yDiff))
    {
        Attack(target);
        return false;
    }
    else
    { 
        WalkTo(battlefield, xDiff, yDiff);
        return true;

    }
    
}

int Character::GetIndex()
{
    return playerIndex;
}

bool Character::GetIsDead()
{
    return isDead;
}

bool Character::CheckCloseTargets(int xDiff, int yDiff)
{
    //Use absolute distance between self and target to determine if target is close 
    return abs(xDiff) <= 1 && abs(yDiff) <= 1;
}

void Character::Attack(Character* target) 
{
    float damage = baseDamage * damageMultiplier;
    target->TakeDamage(damage);
    std::cout << "Player " << playerIndex << " dealt "<< damage << " damage to player " << target->playerIndex<<std::endl;
}

int Character::Sign(int num)
{
    return (num > 0) - (num < 0);
}

