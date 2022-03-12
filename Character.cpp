#include "Grid.h"
#include "Character.h"
#include "Types.h"
#include "Character.h"
#include <vector>
#include <algorithm>

using namespace std;
Character::Character(Types::CharacterClass charcaterClass, float health, float baseDamage, int index)
{
    DamageMultiplier = 1.0;
    Health = health;
    BaseDamage = baseDamage;
    PlayerIndex = index;
}

Character::~Character() 
{

}




void Character::TakeDamage(float amount) 
{
	if ((Health -= BaseDamage) <= 0) 
	{
		Die();
	}

}

void Character::SetTarget(Character* t)
{
    target = t;
}

void Character::SetCurrentBox(Types::GridBox* gridBox)
{
    currentBox = gridBox;
}

Types::GridBox Character::GetCurrentBox()
{
    return *currentBox;
}

void Character::Die() 
{
    IsDead = true;
}

void Character::WalkTo(Grid* battlefield, int xDiff, int yDiff) 
{
    Types::GridBox* nextPos = battlefield->getBoxAtPosition(currentBox->xIndex + Sign(xDiff), currentBox->yIndex + Sign(yDiff));
    currentBox->isOcupied = false;
    nextPos->isOcupied = true;
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
    return PlayerIndex;
}

bool Character::GetIsDead()
{
    return IsDead;
}

bool Character::CheckCloseTargets(int xDiff, int yDiff)
{
    return xDiff <= 1 && yDiff <= 1;
}

void Character::Attack(Character* target) 
{
    target->TakeDamage(BaseDamage);
}

int Character::Sign(int num)
{
    return (num > 0) - (num < 0);
}

