import sys

input = lambda: sys.stdin.readline().rstrip()
print = sys.stdout.write

coinTypes = [500, 100, 50, 10, 5, 1]

def solution():
    price = int(input())
    changes = 1000 - price
    coins = 0
    while changes > 0:
        for coinType in coinTypes:
            if changes // coinType > 0:
                coins += changes // coinType
                changes %= coinType
                break

    print(str(coins) + "\n")

solution()
