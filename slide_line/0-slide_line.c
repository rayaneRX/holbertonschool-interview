#include "slide_line.h"

/**
 * slide_left - Slide and merge the numbers to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void slide_left(int *line, size_t size)
{
    size_t i;
    int merged[size];
    size_t merged_index = 0;

    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (merged_index == 0)
            {
                merged[merged_index++] = line[i];
            }
            else
            {
                if (line[i] == merged[merged_index - 1])
                {
                    merged[merged_index - 1] *= 2;
                }
                else
                {
                    merged[merged_index++] = line[i];
                }
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        if (i < merged_index)
            line[i] = merged[i];
        else
            line[i] = 0;
    }
}

/**
 * slide_right - Slide and merge the numbers to the right
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void slide_right(int *line, size_t size)
{
    size_t i;
    int merged[size];
    size_t merged_index = size;

    for (i = size; i > 0; i--)
    {
        if (line[i - 1] != 0)
        {
            if (merged_index == size)
            {
                merged[--merged_index] = line[i - 1];
            }
            else
            {
                if (line[i - 1] == merged[merged_index])
                {
                    merged[merged_index] *= 2;
                }
                else
                {
                    merged[--merged_index] = line[i - 1];
                }
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        if (i >= merged_index)
            line[i] = merged[i];
        else
            line[i] = 0;
    }
}

/**
 * slide_line - Slide and merge the numbers in a line
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    if (direction == SLIDE_LEFT)
    {
        slide_left(line, size);
    }
    else if (direction == SLIDE_RIGHT)
    {
        slide_right(line, size);
    }

    return 1;
}
