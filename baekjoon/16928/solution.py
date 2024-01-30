import sys
from collections import deque, defaultdict

input = lambda: sys.stdin.readline().rstrip()

board = [-1] * 101
N, M = map(int, input().split())
shortcuts = defaultdict(int)

for i in range(N + M):
    x, y = map(int, input().split())
    shortcuts[x] = y

# (position, turn)
bfs_q = deque([1])
board[1] = 0

while len(bfs_q) > 0:
    current = bfs_q.popleft()
    turn = board[current]

    if current == 100:
        break

    for dice in range(1, 7):
        next = current + dice
        if shortcuts[next] > 0:
            next = shortcuts[next]

        if next > 100 or board[next] > -1:
            continue

        board[next] = turn + 1
        bfs_q.append(next)

sys.stdout.write(str(board[100]) + "\n")
