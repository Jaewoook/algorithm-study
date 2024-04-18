# Lv. 2 - 프로세스
# https://school.programmers.co.kr/learn/courses/30/lessons/42587

from typing import List

def solution(priorities: List[int], location: int):
    order = 0
    while priorities:
        highestPriority = max(priorities)
        currentProcess = priorities[0]

        if highestPriority == currentProcess and location == 0:
            return order + 1

        priorities = priorities[1:]
        if currentProcess < highestPriority:
            priorities += [currentProcess]
        # increase execution order only when the process is executed
        else:
            order += 1

        # move location
        if location > 0:
            location -= 1
        else:
            location = len(priorities) - 1

