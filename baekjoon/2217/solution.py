import sys

input = lambda: sys.stdin.readline().rstrip()
print = sys.stdout.write

def solution():
    ropes = {}
    for _ in range(int(input())):
        key = int(input())
        ropes.setdefault(key, 0)
        ropes[key] += 1

    maxWeight = 0
    selected = 0
    ropeWeights = sorted(list(ropes.keys()), reverse=True)
    for ropeWeight in ropeWeights:
        selected += ropes[ropeWeight]
        maxWeight = max(maxWeight, ropeWeight * selected)

    print(str(maxWeight) + "\n")

solution()
