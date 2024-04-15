# Lv. 1 - 문자열 내 p와 y의 개수

def solution(s):
    p_count = 0
    y_count = 0
    for c in s:
        if c == "P" or c == "p":
            p_count += 1
        if c == "Y" or c == "y":
            y_count += 1

    return True if p_count == y_count else False
