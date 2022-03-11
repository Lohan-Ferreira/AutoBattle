#pragma once
#include <Vector>
#include "Types.h"

class Grid
{

public:

    Grid(int Lines, int Columns);
    ~Grid();

    void drawBattlefield();
    int getGridBoundaryX();
    int getGridBoundaryY();
    Types::GridBox* getBoxAtPosition(int x, int y);

private:

    int xLenght;
    int yLength;
    std::vector<Types::GridBox*> gridBoxes;

    
};

