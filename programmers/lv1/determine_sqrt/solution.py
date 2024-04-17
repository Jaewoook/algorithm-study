# Lv. 1 - 정수 제곱근 판별
# https://school.programmers.co.kr/learn/courses/30/lessons/12934

import math

def solution(n):
    sqrt = math.sqrt(n) // 1

    return (sqrt + 1) ** 2 if sqrt ** 2 == n else -1
