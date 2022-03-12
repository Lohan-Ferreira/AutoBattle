#include "Grid.h"
#include <iostream>


Grid::Grid(int Lines, int Columns)
{
    xLenght = Lines;
    yLength = Columns;
    for (int i = 0; i < Lines; i++)
    {

        for (int j = 0; j < Columns; j++)
        {
            Types::GridBox* newBox = new Types::GridBox(i, j, false, -1);
            gridBoxes.push_back(newBox);
        }
    }
}

Grid::~Grid() 
{
    for (int i = 0; i < gridBoxes.size(); i++)
    {
        delete gridBoxes[i];
    }
}

void Grid::DrawBattlefield()
{
    for (int i = 0; i < xLenght; i++)
    {
        for (int j = 0; j < yLength; j++)
        {
            Types::GridBox* currentgrid = gridBoxes.at(yLength * i + j);
            if (currentgrid->isOcupied)
            {

                std::cout << "[X]\t";
            }
            else
            {
                std::cout << "[ ]\t";
            }
        }
       std::cout << std::endl;
    }
    std::cout << std::endl;
}

Types::GridBox* Grid::GetBoxAtPosition(int x, int y)
{
    Types::GridBox* gridBox;
    try
    {
        gridBox = gridBoxes.at(yLength * x + y);
        return gridBox;
    }
    catch (const std::exception e)
    {
        return nullptr;
    }
    
}

int Grid::GetGridBoundaryX()
{
    return xLenght;
}

int Grid::GetGridBoundaryY()
{
    return yLength;
}


