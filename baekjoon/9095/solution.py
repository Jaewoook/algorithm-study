import sys

dp = [0, 1, 2, 4]

for i in range(4, 12):
    dp.append(dp[i - 1] + dp[i - 2] + dp[i - 3])

for _ in range(int(sys.stdin.readline())):
    n = int(sys.stdin.readline())

    sys.stdout.write(str(dp[n]) + "\n")

# 4 만드는 조합 - 7
# 4 - 1 = 3 만드는 조합
# 4 - 2 = 2 만드는 조합
# 4 - 3 = 1 만드는 조합

# 5 만드는 조합 - 13
# 5 - 1 = 4 만드는 조합 - 7
# 5 - 2 = 3 만드는 조합 - 4
# 5 - 3 = 2 만드는 조합 - 2
