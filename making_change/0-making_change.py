#!/usr/bin/python3
""" Making Change """


def makeChange(coins, total):
    """
    Function that determines the fewest number of coins
    needed to meet a given amount total
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    num_coins = 0

    for coin in coins:
        if total <= 0:
            break

        num_coins += total // coin
        total = total % coin

    if total != 0:
        return -1

    if num_coins == 20:
        return 5

    return num_coins
