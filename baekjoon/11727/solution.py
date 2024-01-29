import sys

input = lambda: sys.stdin.readline().rstrip()

N = int(input())
DP = [0] * (N + 1)
DP[1] = 1
if N >= 2:
    DP[2] = 3
if N >= 3:
    DP[3] = 6

for n in range(3, N + 1):
    DP[n] = (DP[n - 1] + DP[n - 2] * 2) % 10_007

sys.stdout.write(str(DP[N]) + "\n")
