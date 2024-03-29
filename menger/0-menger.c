#include "menger.h"


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
