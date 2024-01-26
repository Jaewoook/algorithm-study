import sys
import math

def round(n):
    if n - math.floor(n) >= 0.5:
        return math.ceil(n)
    else:
        return math.floor(n)

n = int(sys.stdin.readline())
op = []

for _ in range(n):
    op.append(int(sys.stdin.readline()))

op.sort()
cut = round(n * 0.15)
result = round(sum(op[cut:n - cut]) / (n - cut * 2)) if n > 0 else 0

sys.stdout.write(str(result) + "\n")
