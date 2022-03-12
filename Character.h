#pragma once
#include "Grid.h"


class Character
{
public:

    Character(Types::CharacterClass charcaterClass, float hp, float baseDmg, int index);
    ~Character();

    bool StartTurn(Grid* battlefield);
    int GetIndex();
    bool GetIsDead();
    void TakeDamage(float amount);
    void SetTarget(Character* t);
    void SetCurrentBox(Types::GridBox* gridBox);
    Types::GridBox GetCurrentBox();

private:

    float health;
    float baseDamage;
    float damageMultiplier;
    int playerIndex;
    Character* target;
    bool isDead;
    Types::GridBox* currentBox;


    

    void Die();

    void WalkTo(Grid* battlefield, int xDiff, int yDiff);

    bool CheckCloseTargets(int xDiff, int yDiff);

    void Attack(Character* target);

    int Sign(int num);


};

