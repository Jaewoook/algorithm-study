import sys

MOD = 1000000007

N, M = map(int, sys.stdin.readline().split())
board = [[0] * M] * N
dp = []

for i in range(N):
    line = list(map(int, sys.stdin.readline().split()))
    board[i] = line
    dp.append([0] * M)

dp[0] = board[0]

for i in range(1, N):
    for j in range(M):
        if board[i][j] != 1:
            continue

        left = max(j - 1, 0)
        right = min(j + 1, M - 1)
        sum = 0
        for k in range(left, right + 1):
            if board[i - 1][k] == 1:
                sum = (sum + dp[i - 1][k]) % MOD
        dp[i][j] = sum

total = 0
for i in range(M):
    total = (total + dp[N - 1][i]) % MOD

sys.stdout.write(str(total) + "\n")

# sample input
#
# 3 2
# 0 1
# 1 0
# 0 1

# sample output
#
# 1
