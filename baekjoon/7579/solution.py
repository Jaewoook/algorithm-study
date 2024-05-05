import sys

input = lambda: sys.stdin.readline().rstrip()
print = lambda arg = '', end = '\n': sys.stdout.write(arg + end)
debug = print

def solution():
    N, M = map(int, input().split())
    bytes = list(map(int, input().split()))
    costs = list(map(int, input().split()))
    max_cost = sum(costs)

    cost_size = max_cost + 1
    dp = [[0] * (cost_size) for _ in range(N + 1)]

    for selection in range(1, N + 1):
        for current_cost in range(cost_size):
            app_memory = bytes[selection - 1]
            cost = costs[selection - 1]

            dp[selection][current_cost] = dp[selection - 1][current_cost]
            if current_cost - cost >= 0:
                dp[selection][current_cost] = max(dp[selection][current_cost], dp[selection - 1][current_cost - cost] + app_memory)

    result = 0
    for cost in range(cost_size):
        if dp[N][cost] >= M:
            result = cost
            break

    print(str(result))

solution()
