T = int(input())

def get_next_direction(prev_direction, next_direction):
    if prev_direction == "F":
        return next_direction
    if prev_direction == "R":
        if next_direction == "F":
            return "R"
        if next_direction == "R":
            return "B"
        if next_direction == "L":
            return "F"
        if next_direction == "B":
            return "L"
    if prev_direction == "L":
        if next_direction == "F":
            return "L"
        if next_direction == "R":
            return "F"
        if next_direction == "L":
            return "B"
        if next_direction == "B":
            return "R"
    if prev_direction == "B":
        if next_direction == "F":
            return "B"
        if next_direction == "R":
            return "L"
        if next_direction == "L":
            return "R"
        if next_direction == "B":
            return "F"

direction = {
    "F": (1, 0),
    "B": (-1, 0),
    "L": (0, -1),
    "R": (0, 1)
}

for _ in range(T):
    cur_point = (0, 0)
    prev_direction = "B"

    n = int(input())
    map = []
    v = [[[] for _ in range(n)] for _ in range(n)]
    for l in range(n):
        map.append(input().split())

    v[0][0].append("B")
    while True:
        cur_block = map[cur_point[0]][cur_point[1]]
        next_direction = get_next_direction(prev_direction, cur_block[0])
        move_distance = int(cur_block[1])

        next_row, next_col = (i * move_distance for i in direction[next_direction])
        cur_point = (cur_point[0] + next_row, cur_point[1] + next_col)
        prev_direction = next_direction

        if next_direction in v[cur_point[0]][cur_point[1]]:
            break
        else:
            v[cur_point[0]][cur_point[1]].append(next_direction)

    print(f"{cur_point[0]} {cur_point[1]}")

# sample input
#
# 2
# 5
# B1  L1  R2  F1  R2
# F2  R2  L2  R2  F2
# B1  L1  R2  L1  R1
# R3  R3  B1  R2  R1
# R1  R2  B1  L3  R2
# 5
# B3  B1  R2  L2  R2
# B1  F3  B1  R2  B1
# F2  F1  F2  B2  R3
# R4  R1  F3  L2  R3
# R1  F1  B3  R2  B2

# sample output
#
# 1 3
# 2 2
