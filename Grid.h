#pragma once
#include <Vector>
#include "Types.h"


class Grid
{

public:

    Grid(int Lines, int Columns);
    ~Grid();

    void DrawBattlefield();
    int GetGridBoundaryX();
    int GetGridBoundaryY();
    Types::GridBox* GetBoxAtPosition(int x, int y);

private:

    int xLenght;
    int yLength;
    std::vector<Types::GridBox*> gridBoxes;

    
};

