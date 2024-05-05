import sys

input = lambda: sys.stdin.readline().rstrip()
print = lambda arg = '', end = '\n': sys.stdout.write(arg + end)
debug = print

def solution():
    N, K = map(int, input().split())

    dp = [[0] * (K + 1) for _ in range(N + 1)]

    objects = [list(map(int, input().split())) for _ in range(N)]
    for i in range(1, N + 1):
        for max_weight in range(K + 1):
            weight, value = objects[i - 1]
            dp[i][max_weight] = dp[i - 1][max_weight]

            if max_weight - weight >= 0:
                dp[i][max_weight] = max(dp[i][max_weight], value + dp[i - 1][max_weight - weight])

    print(str(dp[N][K]))

solution()
