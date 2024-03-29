#include "menger.h"


/**
 * isEmpty - check if a cell is empty
 * @row: the row position of the cell
 * @col: the column position of the cell
 *
 * Return: 1 if the cell is empty, 0 otherwise
*/

int isEmpty(int row, int col)
{
	while (row > 0 && col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 *
 * Return: void
*/
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (isEmpty(row, col))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}

