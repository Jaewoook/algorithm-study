import sys

input = lambda: sys.stdin.readline().rstrip()
debug = print
print = lambda arg = '', end = '\n': sys.stdout.write(arg + end)
INF = float("1e9")

def solution():
    C, N = map(int, input().split())

    promotes: list[tuple[int, int]] = []
    dp = [INF] * (C + 101)
    dp[0] = 0
    for _ in range(N):
        promotes.append(map(int, input().split()))

    for cost, potential in promotes:
        for i in range(potential, C + 101):
            dp[i] = min(dp[i], dp[i - potential] + cost)

    print(str(min(dp[C:])))


solution()
