import sys

X = int(sys.stdin.readline())
cost = 0
for i in range(int(sys.stdin.readline())):
    price, count = map(int, sys.stdin.readline().split())
    cost += price * count

sys.stdout.write("Yes" if cost == X else "No" + "\n")
