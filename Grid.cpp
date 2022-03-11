#include "Grid.h"
#include "Types.h"


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
            Types::GridBox* currentgrid = gridBoxes[yLength * i + j];
            if (currentgrid->ocupied)
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