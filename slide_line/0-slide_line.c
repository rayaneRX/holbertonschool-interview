#include "slide_line.h"

/**
 * merge_and_slide_left - Slides and merges an array to the left.
 * @line: Points to an array of integers containing size elements.
 * @size: Number of elements in @line.
 */
void merge_and_slide_left(int *line, size_t size)
{
    size_t i, j = 0;

    for (i = 0; i < size; i++)
	{
        if (line[i] != 0)
		{
            if (j > 0 && line[j - 1] == line[i])
			{
                line[j - 1] *= 2;
                line[i] = 0;
            }
			else
			{
                if (j != i)
				{
                    line[j] = line[i];
                    line[i] = 0;
                }
                j++;
            }
        }
    }
}


/**
 * merge_and_slide_right - Slides and merges an array to the right.
 * @line: Points to an array of integers containing size elements.
 * @size: Number of elements in @line.
 */
void merge_and_slide_right(int *line, size_t size)
{
    size_t i, j;

    if (size == 0)
		return;

	j = size - 1;

    for (i = size - 1; i < size; i--)
	{
        if (line[i] != 0)
		{
            if (j < size - 1 && line[j + 1] == line[i])
			{
                line[j + 1] *= 2;
                line[i] = 0;
            }
			else
			{
                if (j != i)
				{
                    line[j] = line[i];
                    line[i] = 0;
                }
                j--;
            }
        }
    }
}


/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers containing size elements.
 * @size: Number of elements in @line.
 * @direction: Left or right.
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction == SLIDE_LEFT)
	{
        merge_and_slide_left(line, size);
    }
	else if (direction == SLIDE_RIGHT)
	{
        merge_and_slide_right(line, size);
    }
	else
	{
        return 0;
    }

    return 1;
}