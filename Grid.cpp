#include "Grid.h"



Grid::Grid(int Lines, int Columns)
{
    xLenght = Lines;
    yLength = Columns;
    //Console.WriteLine("The battle field has been created\n");
    for (int i = 0; i < Lines; i++)
    {

        for (int j = 0; j < Columns; j++)
        {
            Types::GridBox* newBox = new Types::GridBox(i, j, false, (yLength * i + j));
            gridBoxes.push_back(newBox);
        }
    }
	//drawBattlefield(Lines, Columns);
}

Grid::~Grid() 
{

}

void Grid::drawBattlefield()
{
    for (int i = 0; i < xLenght; i++)
    {
        for (int j = 0; j < yLength; j++)
        {
            Types::GridBox* currentgrid = gridBoxes.at(yLength * i + j);
            if (currentgrid->isOcupied)
            {

                printf("[X]\t");
            }
            else
            {
                printf("[ ]\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

Types::GridBox* Grid::getBoxAtPosition(int x, int y)
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

int Grid::getGridBoundaryX()
{
    return xLenght;
}

int Grid::getGridBoundaryY()
{
    return yLength;
}


