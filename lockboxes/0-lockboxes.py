#!/usr/bin/python3
def canUnlockAll(boxes):
    opened_boxes = set()

    opened_boxes.add(0)

    queue = [0]

    while queue:
        current_box = queue.pop(0)

        for key in boxes[current_box]:
            if key not in opened_boxes:
                opened_boxes.add(key)
                queue.append(key)

    return len(opened_boxes) == len(boxes)
