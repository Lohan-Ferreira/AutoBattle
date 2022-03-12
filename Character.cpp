
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
    //Find position closer to target
    Types::GridBox* nextPos = battlefield->GetBoxAtPosition(currentBox->xIndex + Sign(xDiff), currentBox->yIndex + Sign(yDiff));

    //Move to new box in grid
    SetCurrentBox(nextPos);

}



bool Character::StartTurn(Grid* battlefield) {

    //Calculate coords distance
    int xDiff = target->GetCurrentBox().xIndex - currentBox->xIndex;
    int yDiff = target->GetCurrentBox().yIndex - currentBox->yIndex;

    if (CheckCloseTargets(xDiff,yDiff))  //try to attack
    {
        Attack(target);
        return false;
    }
    else    //if can't, move closer to target
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

/* Sign function to determine in which direction the target is*/
int Character::Sign(int num)
{
    return (num > 0) - (num < 0);
}

