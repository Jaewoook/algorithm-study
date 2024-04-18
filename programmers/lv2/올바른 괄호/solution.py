# Lv. 2 - 올바른 괄호
# https://school.programmers.co.kr/learn/courses/30/lessons/12909

def solution(s):
    stack = []

    for paren in s:
        if len(stack) == 0 and paren == ")":
            return False

        if paren == "(":
            stack.append("(")
            continue

        stack.pop()

    return len(stack) == 0
