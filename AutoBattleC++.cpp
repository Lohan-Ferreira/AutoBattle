// AutoBattleC++.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include "BattleField.h"
#include <iostream>

int main()
{
    srand(time(NULL));
    BattleField* battleField = new BattleField(15,3);

    delete(battleField);

    return 0;
}


