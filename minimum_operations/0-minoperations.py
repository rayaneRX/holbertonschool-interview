#!/usr/bin/python3
"""
Module which contains minoperations function
"""


def minOperations(n):

    if n <= 1:
        return 0

    # Comment
    operations = 0
    factor = 2

    # Comment
    while factor <= n:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    # omment
    return operations
