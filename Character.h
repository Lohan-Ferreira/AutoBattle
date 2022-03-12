#pragma once
#include "Grid.h"
#include "Character.h"
#include "Types.h"

class Character
{
public:

    Character(Types::CharacterClass charcaterClass, float health, float baseDamage, int index);
    ~Character();

    bool StartTurn(Grid* battlefield);
    int GetIndex();
    bool GetIsDead();
    void TakeDamage(float amount);
    void SetTarget(Character* t);
    void SetCurrentBox(Types::GridBox* gridBox);
    Types::GridBox GetCurrentBox();

private:

    float Health;
    float BaseDamage;
    float DamageMultiplier;
    int PlayerIndex;
    Character* target;
    bool IsDead;
    char Icon;
    Types::GridBox* currentBox;


    

    void Die();

    void WalkTo(Grid* battlefield, int xDiff, int yDiff);

    bool CheckCloseTargets(int xDiff, int yDiff);

    void Attack(Character* target);

    int Sign(int num);


};

