# Lv. 1 - 완주하지 못한 선수
# https://school.programmers.co.kr/learn/courses/30/lessons/42576

def solution(participant, completion):
    member = {}

    for name in completion:
        member.setdefault(name, 0)
        member[name] += 1

    answer = ''
    for name in participant:
        if member.get(name) == None or member[name] == 0:
            answer = name
            break
        member[name] -= 1

    return answer
