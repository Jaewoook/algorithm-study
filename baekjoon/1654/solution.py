import sys

# K - 갖고 있는 랜선의 수
# N - 필요한 랜선의 수
K, N = map(int, sys.stdin.readline().split())
lines = []

for _ in range(K):
    lines.append(int(sys.stdin.readline()))

left = 1
right = max(lines)
mid = left + (right - left) // 2

while left <= right:
    quotient = 0
    for line in lines:
        quotient += line // mid

    if quotient < N:
        right = mid - 1
    else:
        left = mid + 1
    mid = left + (right - left) // 2

sys.stdout.write(str(mid) + "\n")

# sample input

# 4 11
# 802
# 743
# 457
# 539
