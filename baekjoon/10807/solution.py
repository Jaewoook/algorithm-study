import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

A = int(sys.stdin.readline())

count = 0
for n in arr:
    if n == A:
        count += 1

sys.stdout.write(str(count) + "\n")
