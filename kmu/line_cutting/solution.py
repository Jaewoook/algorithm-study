import sys
from copy import deepcopy

def cut(line: int):
    # return memoized value
    if dp[line] > 0:
        return dp[line]

    # print(f"cut line: {line}")

    result = 0

    if line % 2 == 0:
        dp[line // 2] = cut(line // 2)
        result += dp[line // 2] ** 2

    if line > ruler:
        if line - ruler != line / 2:
            dp[line - ruler] = cut(line - ruler)
            dp[ruler] = cut(ruler)
            result += dp[ruler] * dp[line - ruler]

        q = (line + ruler) / 2
        if q == int(q) and int(q) != line - ruler:
            q = int(q)
            dp[q] = cut(q)
            dp[line - q] = cut(line - q)
            result += dp[q] * dp[line - q]

    dp[line] = result if result > 0 else 1
    return dp[line]


for _ in range(int(sys.stdin.readline())):
    global line, ruler, dp
    line, ruler = map(int, sys.stdin.readline().split())
    dp = [0] * (line + 1)
    dp[1] = 1

    # print(f"line: {line}, ruler: {ruler}")

    cut(line)

    # print(dp)
    print(dp[line] % 10007)


# sample input
#
# 3
# 7 3
# 9 3
# 76 5

# sample output
#
# 5
# 1
# 7101
