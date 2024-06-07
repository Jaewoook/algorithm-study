import sys

input = lambda: sys.stdin.readline().rstrip()
debug = print
print = lambda arg = '', end = '\n': sys.stdout.write(arg + end)
INF = float("1e9")

def solution():
    for _ in range(int(input())):
        input()
        coins = list(map(int, input().split()))
        M = int(input())

        dp = [0] * (M + 1)
        dp[0] = 1

        for coin in coins:
            for money in range(coin, M + 1):
                dp[money] += dp[money - coin]

        print(str(dp[M]))

solution()
