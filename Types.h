#pragma once

#include <iostream>

class Types
{
public:

    struct GridBox
    {
        int xIndex;
        int yIndex;
        bool isOcupied;
        int Index;

        GridBox(int x, int y, bool ocupied, int index)
        {
            xIndex = x;
            yIndex = y;
            isOcupied = ocupied;
            Index = index;
        }
    };

    enum class CharacterClass
    {
        Paladin = 1,
        Warrior = 2,
        Cleric = 3,
        Archer = 4
    };

    /*Operator overload to allow printing of enum class*/
    friend std::ostream& operator<< (std::ostream& stm, CharacterClass characterClass)
    {
        switch (characterClass)
        {
        case CharacterClass::Paladin : return stm << "Paladin";
        case CharacterClass::Warrior : return stm << "Warrior";
        case CharacterClass::Cleric : return stm << "Cleric";
        case CharacterClass::Archer : return stm << "Archer";
        default: return stm << "";
        }
    }

};

