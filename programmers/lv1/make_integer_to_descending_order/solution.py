# Lv. 1 - 정수 내림차순으로 배치하기
# https://school.programmers.co.kr/learn/courses/30/lessons/12933

def solution(n):
    countArr = [0] * 10
    while n > 0:
        countArr[n % 10] += 1
        n //= 10

    answer = 0
    for index in range(9, -1, -1):
        if countArr[index] == 0:
            continue

        while countArr[index] > 0:
            answer *= 10
            answer += index
            countArr[index] -= 1

    return answer
