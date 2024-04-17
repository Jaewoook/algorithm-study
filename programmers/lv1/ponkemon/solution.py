# Lv. 1 - 폰켓몬
# https://school.programmers.co.kr/learn/courses/30/lessons/1845

def solution(nums):
    ponkemons = {}
    for n in nums:
        ponkemons.setdefault(n, 0)
        ponkemons[n] += 1

    takable = len(nums) // 2
    counts = ponkemons.values()

    answer = min(takable, len(counts))
    return answer
