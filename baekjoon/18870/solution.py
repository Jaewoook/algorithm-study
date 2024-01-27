import sys

N = int(sys.stdin.readline())

arr = list(map(int, sys.stdin.readline().split()))
sorted_arr = sorted(list(set(arr)))
compact = {}

for i, e in enumerate(sorted_arr):
    compact[e] = i

for e in arr:
    sys.stdout.write(str(compact[e]) + " ")
sys.stdout.write("\n")
