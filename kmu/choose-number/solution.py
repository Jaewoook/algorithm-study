import sys

for _ in range(int(sys.stdin.readline())):
    N, M = map(int, sys.stdin.readline().split())

    numbers = sorted(list(map(int, sys.stdin.readline().split())))
    left = 0
    right = 1
    diff = numbers[-1]

    while right < N and diff > M:
        _diff = numbers[right] - numbers[left]
        if _diff < M:
            right += 1
            continue

        diff = min(diff, _diff)
        left += 1

    sys.stdout.write(str(diff) + "\n")

# sample input

# 2
# 6 5
# 8 6 1 4 2 3
# 7 4
# 89 36 33 53 63 83 52

# sample output

# 5
# 6
