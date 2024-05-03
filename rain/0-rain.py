#!/usr/bin/python3
""" Rain """


def rain(walls):
    """ Rain """

    if not walls:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    total_water = 0
    for i in range(n):
        water_above_wall = min(left_max[i], right_max[i]) - walls[i]
        if water_above_wall > 0:
            total_water += water_above_wall

    return total_water
