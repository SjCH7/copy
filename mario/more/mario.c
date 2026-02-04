#include <cs50.h>
#include <stdio.h>

void addGapBetweenPyramids(void);
void printRow(int pyramidsHeight, int rowNumber);
void addRowIndent(int pyramidsHeight, int rowNumber);
void addBricks(int amountOfBricks);

int main(void)
{
    int pyramidsHeight;
    do
    {
        pyramidsHeight = get_int("Suggest pyramids height (1-8) : ");
    }
    while (pyramidsHeight <= 0 || pyramidsHeight > 8);

    for (int row = 1; row <= pyramidsHeight; row++)
    {
        printRow(pyramidsHeight, row);
    }
}

void addGapBetweenPyramids(void)
{
    for (int i = 0; i < 2; i++)
    {
        printf(" ");
    }
}
void printRow(int pyramidsHeight, int rowNumber)
{
    addRowIndent(pyramidsHeight, rowNumber);
    addBricks(rowNumber);
    addGapBetweenPyramids();
    addBricks(rowNumber);
    printf("\n");
}

void addRowIndent(int pyramidsHeight, int rowNumber)
{
    int indent = pyramidsHeight - rowNumber;
    for (int i = 0; i < indent; i++)
    {
        printf(" ");
    }
}
void addBricks(int amountOfBricks)
{
    for (int i = 0; i < amountOfBricks; i++)
    {
        printf("#");
    }
}
