# Lv. 1 - 큰 수 만들기

def solution(number: str, k):
    size = len(number) - k
    stack = []

    for n in number:
        if len(stack) == 0:
            stack.append(n)
            continue

        while len(stack) > 0 and stack[-1] < n and k > 0:
            stack.pop()
            k -= 1

        if len(stack) < size:
            stack.append(n)

    return "".join(stack)
