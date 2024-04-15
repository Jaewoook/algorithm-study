# Lv. 1 - 약수의 합

def solution(n):
    sum = 0
    divisors = [False] * (n + 1)
    if n > 0:
        divisors[1] = True
    for i in range(2, n + 1):
        if n % i == 0:
            divisors[i] = True

    for i in range(1, n + 1):
        if divisors[i]:
            sum += i

    return sum
