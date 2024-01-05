#!/usr/bin/python3

def canUnlockAll(boxes):
     # Get the total number of boxes
    n = len(boxes)
    visited = [False] * n
    stack = [0]
#Lockboxes
    while stack:
        current_box = stack.pop()
        visited[current_box] = True

        for key in boxes[current_box]:
            if not visited[key]:
                stack.append(key)
# Check if all boxes have been visited
    return all(visited)