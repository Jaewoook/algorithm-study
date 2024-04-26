import sys

input = lambda: sys.stdin.readline().rstrip()
debug = print
print = sys.stdout.write

def solution():
    S = int(input())
    N = 0
    while True:
        N += 1
        if N ** 2 + N == S * 2:
            break
        if N ** 2 + N > S * 2:
            N -= 1
            break

    print(str(N) + "\n")

solution()
