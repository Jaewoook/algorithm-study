import sys

DIRECTION = [
    [-1, 0], [0, 1], [1, 0], [0, -1]
]

def bfs(maze: list[list[int]], visited: list[list[bool]], N: int, M: int):
    move = 1
    current = [0, 0]
    queue = []
    next_queue = []
    queue.append(current)
    while len(queue) > 0:
        current_row, current_col = queue.pop(0)

        for row, col in DIRECTION:
            next_row = current_row + row
            next_col = current_col + col

            if next_row < 0 or next_col < 0 or next_row > N - 1 or next_col > M - 1 or maze[next_row][next_col] == 0 or visited[next_row][next_col]:
                continue

            visited[next_row][next_col] = True
            next_queue.append([next_row, next_col])
            if next_row == N - 1 and next_col == M - 1:
                return move

        if len(queue) == 0:
            move += 1
            queue = next_queue
            next_queue = []



for i in range(int(sys.stdin.readline())):
    N, M = map(int, sys.stdin.readline().split())
    maze = []
    visited = []
    for j in range(N):
        row = list(map(int, list(sys.stdin.readline().strip())))
        maze.append(row)
        visited.append([False] * M)

    move = bfs(maze, visited, N, M) + 1

    sys.stdout.write(str(move) + "\n")

# sample input
#
# 2
# 5 5
# 10000
# 10000
# 10000
# 11110
# 00011
# 3 6
# 101111
# 101010
# 111011
