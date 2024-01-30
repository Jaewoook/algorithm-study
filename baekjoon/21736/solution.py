import sys

P = "P"
I = "I"
O = "O"
X = "X"
D = (
    (-1, 0),
    (0, -1),
    (1, 0),
    (0, 1)
)

input = lambda: sys.stdin.readline().rstrip()

N, M = map(int, input().split())
campus = [[""] * M for _ in range(N)]
visited = [[False] * M for _ in range(N)]
dfs_q = []
pos = (-1, -1)

for i in range(N):
    campus[i] = list(input())
    try:
        pos = (i, campus[i].index(I))
    except:
        pass

dfs_q.append(pos)
p = 0

while len(dfs_q) > 0:
    moved = False
    i, j = dfs_q[-1]

    for d in D:
        next_i, next_j = d
        next_i += i
        next_j += j
        if not (0 <= next_i < N and 0 <= next_j < M) or campus[next_i][next_j] == X or visited[next_i][next_j]:
            continue
        dfs_q.append((next_i, next_j))
        moved = True
        visited[next_i][next_j] = True
        if campus[next_i][next_j] == P:
            p += 1
        break

    if not moved:
        dfs_q.pop()

sys.stdout.write((str(p) if p > 0 else "TT") + "\n")
