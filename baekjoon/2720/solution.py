import sys

input = lambda: sys.stdin.readline().rstrip()
print = sys.stdout.write

COIN_TYPES = [25, 10, 5, 1]

def solution():
    for _ in range(int(input())):
        cent = int(input())

        for i in range(4):
            print(str(cent // COIN_TYPES[i]) + " ")
            cent %= COIN_TYPES[i]

        print("\n")

solution()
