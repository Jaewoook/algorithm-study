import sys

N, M = map(int, sys.stdin.readline().split())
bucket = [0] * N
for i in range(M):
    i, j, k = map(int, sys.stdin.readline().split())

    for idx in range(i - 1, j):
        bucket[idx] = k

for i in range(N):
    sys.stdout.write(str(bucket[i]) + " ")
sys.stdout.write("\n")
