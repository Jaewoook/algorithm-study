import sys

N, M = map(int, sys.stdin.readline().split())

n_dict = {}
nm_arr = []

for _ in range(N):
    name = sys.stdin.readline()
    n_dict[name] = True

for _ in range(M):
    name = sys.stdin.readline()
    if name in n_dict:
        nm_arr.append(name)

nm_arr.sort()
sys.stdout.write(str(len(nm_arr)) + "\n")
for nm in nm_arr:
    sys.stdout.write(nm)
