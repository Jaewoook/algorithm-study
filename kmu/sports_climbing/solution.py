import sys

INF = int(1e9)

NEIGHBORS = [
    [-1, 0], [0, 1], [1, 0], [0, -1]
]


def is_empty(map, row, col):
    return map[row][col] == "."


def is_hold(map, row, col):
    return map[row][col] == "H"


def is_valid_range(row, col, n):
    if row < 0 or col < 0 or row > n - 1 or col > n - 1:
        return False
    return True


for _ in range(int(sys.stdin.readline())):
    n = int(sys.stdin.readline())

    map = [sys.stdin.readline().split() for _ in range(n)]
    distance = [[INF for _ in range(n)] for _ in range(n)]
    visited = [[False for _ in range(n)] for _ in range(n)]
    # print("map")
    # print(map)
    # print("distance")
    # print(distance)
    queue = []
    queue.append([n - 1, 0])
    distance[n - 1][0] = 1
    visited[n - 1][0] = True

    while len(queue) > 0:
        # print("current queue: ", end="")
        # print(queue)
        # print("visited: ", end="")
        # print(visited)
        current_row, current_col = queue.pop()
        current_distance = distance[current_row][current_col]

        # rule 1
        for neighbor in NEIGHBORS:
            next_row = current_row + neighbor[0]
            next_col = current_col + neighbor[1]

            if is_valid_range(next_row, next_col, n) and is_hold(map, next_row, next_col) and not visited[next_row][next_col]:
                queue.append([next_row, next_col])
                visited[next_row][next_col] = True
                distance[next_row][next_col] = min(distance[next_row][next_col], current_distance + 1)

        next_row = current_row - 1
        next_col = current_col
        if is_valid_range(next_row, next_col, n) and is_empty(map, next_row, next_col):
            next_row = current_row

            # rule 2 - right two blocks
            next_col = current_col + 2
            if is_valid_range(next_row, next_col, n) and is_hold(map, next_row, next_col) and not visited[next_row][next_col] \
                and is_empty(map, next_row - 1, next_col) and is_empty(map, next_row - 1, next_col - 1) and is_empty(map, next_row, next_col - 1):
                queue.append([next_row, next_col])
                visited[next_row][next_col] = True
                distance[next_row][next_col] = min(distance[next_row][next_col], current_distance + 1)

            # rule 2 - left two oblocks
            next_col = current_col - 2
            if is_valid_range(next_row, next_col, n) and is_hold(map, next_row, next_col) and not visited[next_row][next_col] \
                and is_empty(map, next_row - 1, next_col) and is_empty(map, next_row - 1, next_col + 1) and is_empty(map, next_row, next_col + 1):
                queue.append([next_row, next_col])
                visited[next_row][next_col] = True
                distance[next_row][next_col] = min(distance[next_row][next_col], current_distance + 1)

            # rule 2 - right three oblocks
            next_col = current_col + 3
            if is_valid_range(next_row, next_col, n) and is_hold(map, next_row, next_col) and not visited[next_row][next_col] \
                and is_empty(map, next_row - 1, next_col) and is_empty(map, next_row - 1, next_col - 1) and is_empty(map, next_row - 1, next_col - 2) \
                and is_empty(map, next_row, next_col - 1) and is_empty(map, next_row, next_col - 2):
                queue.append([next_row, next_col])
                visited[next_row][next_col] = True
                distance[next_row][next_col] = min(distance[next_row][next_col], current_distance + 1)

            # rule 2 - left three blocks
            next_col = current_col - 3
            if is_valid_range(next_row, next_col, n) and is_hold(map, next_row, next_col) and not visited[next_row][next_col] \
                and is_empty(map, next_row - 1, next_col) and is_empty(map, next_row - 1, next_col + 1) and is_empty(map, next_row - 1, next_col + 2) \
                and is_empty(map, next_row, next_col + 1) and is_empty(map, next_row, next_col + 2):
                queue.append([next_row, next_col])
                visited[next_row][next_col] = True
                distance[next_row][next_col] = min(distance[next_row][next_col], current_distance + 1)

            # rule 3
            next_row = current_row - 2
            next_col = current_col
            if is_valid_range(next_row, next_col, n) and is_hold(map, next_row, next_col) and not visited[next_row][next_col]:
                queue.append([next_row, next_col])
                visited[next_row][next_col] = True
                distance[next_row][next_col] = min(distance[next_row][next_col], current_distance + 1)

            # rule 4
            next_row = current_row - 1
            next_col = current_col - 1
            if is_valid_range(next_row, next_col, n) and is_hold(map, next_row, next_col) and not visited[next_row][next_col] \
                and is_empty(map, next_row + 1, next_col):
                queue.append([next_row, next_col])
                visited[next_row][next_col] = True
                distance[next_row][next_col] = min(distance[next_row][next_col], current_distance + 1)

            # rule 5
            next_row = current_row - 1
            next_col = current_col + 1
            if is_valid_range(next_row, next_col, n) and is_hold(map, next_row, next_col) and not visited[next_row][next_col] \
                and is_empty(map, next_row + 1, next_col):
                queue.append([next_row, next_col])
                visited[next_row][next_col] = True
                distance[next_row][next_col] = min(distance[next_row][next_col], current_distance + 1)

    # print results
    for i in range(n):
        for j in range(n):
            if map[i][j] == "X" or map[i][j] == ".":
                print(0, end=" ")
            elif distance[i][j] == int(1e9):
                print(-1, end=" ")
            else:
                print(distance[i][j], end=" ")
        print()

# sample input
#
# 2
# 3
# H . H
# . H X
# H . H
# 6
# H . . . . H
# . . H . . .
# . . H . X H
# H . . H . .
# . . . . H H
# H . . H . H

# sample output
#
# 2 0 -1
# 0 2 0
# 1 0 -1
# -1 0 0 0 0 6
# 0 0 5 0 0 0
# 0 0 4 0 0 5
# 2 0 0 3 0 0
# 0 0 0 0 3 4
# 1 0 0 2 0 5
