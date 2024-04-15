# Lv. 1 - 체육복
# Array 이용하여 풂

def solution(n, lost, reserve):
    students = [1] * (n + 1)
    students[0] = 0

    for l in lost:
        students[l] = 0
    for r in reserve:
        students[r] += 1

    for s in range(1, n+1):
        if students[s] <= 1:
            continue

        left = s - 1
        right = s + 1
        if left > 0 and students[left] == 0:
            students[left] = 1
            students[s] -= 1
        elif right <= n and students[right] == 0:
            students[right] = 1
            students[s] -= 1

    count = 0
    count = sum([1 for student in students if student > 0])

    return count
