#!/usr/bin/python3
""" Island Perimeter """


def island_perimeter(grid):
    """ Returns the perimeter of the island described in grid """
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            # Check if the cell is an island
            if grid[row][col] == 1:
                perimeter += 4
                # Check the top cell
                if row > 0 and grid[row-1][col] == 1:
                    perimeter -= 1
                # Check the bottom cell
                if row < rows - 1 and grid[row+1][col] == 1:
                    perimeter -= 1
                # Check the left cell
                if col > 0 and grid[row][col-1] == 1:
                    perimeter -= 1
                # Check the right cell
                if col < cols - 1 and grid[row][col+1] == 1:
                    perimeter -= 1

    return perimeter
