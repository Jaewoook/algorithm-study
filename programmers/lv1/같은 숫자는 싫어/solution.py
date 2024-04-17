# Lv. 1 - 같은 숫자는 싫어
# https://school.programmers.co.kr/learn/courses/30/lessons/12906

from typing import List

def solution(arr: List[int]):
    answer = []
    prev = None
    for el in arr:
        if prev != el:
            answer.append(el)
            prev = el

    return answer
