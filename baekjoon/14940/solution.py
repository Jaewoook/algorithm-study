import sys

WALL = 0
NORMAL = 1
TARGET = 2
INF = float("inf")
DIRECTIONS = ((-1, 0), (0, -1), (1, 0), (0, 1))

n, m = map(int, sys.stdin.readline().split())
board = [[0] * m for _ in range(n)]
dist = [[INF] * m for _ in range(n)]
target_row = -1
target_col = -1

for i in range(n):
    board[i] = list(map(int, sys.stdin.readline().split()))
    try:
        target_col = board[i].index(TARGET)
        target_row = i
    except:
        pass

dist[target_row][target_col] = 0
bfs_queue = [(target_row, target_col)]
next_bfs_queue = []
phase = 1

while len(bfs_queue) > 0:
    i, j = bfs_queue.pop()

    for k in range(4):
        next_i = i + DIRECTIONS[k][0]
        next_j = j + DIRECTIONS[k][1]

        if not (0 <= next_i < n and 0 <= next_j < m) or board[next_i][next_j] == WALL or dist[next_i][next_j] != INF:
            continue

        dist[next_i][next_j] = phase
        next_bfs_queue.append((next_i, next_j))

    if len(bfs_queue) == 0:
        bfs_queue = next_bfs_queue
        next_bfs_queue = []
        phase += 1

for i in range(n):
    for j in range(m):
        d = dist[i][j]
        if d == INF and board[i][j] == WALL:
            d = 0
        elif d == INF and board[i][j] == NORMAL:
            d = -1
        sys.stdout.write(str(d) + " ")
    sys.stdout.write("\n")

