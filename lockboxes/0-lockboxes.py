#!/usr/bin/python3
"""
a method that determines if all the boxes can be opened.
"""
def canUnlockAll(boxes):
    opened = set()
    opened.add(0)

    queue = [0]

    while queue:
        box = queue.pop(0)

        for key in boxes[box]:
            if key not in opened and key < len(boxes):
                opened.add(key)
                queue.append(key)

    return len(opened) == len(boxes)