# Lv. 1 - 하샤드 수
# https://school.programmers.co.kr/learn/courses/30/lessons/12947

def solution(x):
    sumOfDigits = 0
    n = x
    while x > 0:
        sumOfDigits += x % 10
        x //= 10

    return n % sumOfDigits == 0
