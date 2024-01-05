#!/usr/bin/python3
"""
a method that determines if all the boxes can be opened.
"""
def canUnlockAll(boxes):
    n = len(boxes)
    opened_boxes = [False] * n
    opened_boxes[0] = True

    stack = [0]
    while stack:
        current_box = stack.pop()
        for key in boxes[current_box]:
            if not opened_boxes[key]:
                opened_boxes[key] = True
                stack.append(key)

    return all(opened_boxes)