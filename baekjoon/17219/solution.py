import sys

input = lambda: sys.stdin.readline().rstrip()

N, M = map(int, input().split())
kv = {}
for _ in range(N):
    url, pw = input().split()
    kv.setdefault(url, pw)

for _ in range(M):
    url = input()
    sys.stdout.write(kv[url] + "\n")
