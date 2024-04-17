# Lv. 2 - 기능개발
# https://school.programmers.co.kr/learn/courses/30/lessons/42586

from typing import List
import math

def solution(progresses: List[int], speeds: List[int]):
    answer = []
    pending = 0
    for i in range(len(progresses)):
        left = math.ceil((100 - progresses[i]) / speeds[i])
        if pending == 0:
            pending = 1
            big_left = left
            continue

        if left <= big_left:
            pending += 1
            continue

        answer.append(pending)
        pending = 1
        big_left = left


    if pending > 0:
        answer.append(pending)

    return answer
