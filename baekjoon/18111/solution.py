import sys
import math

def normalize_world(goal_h: int):
    work_time = 0
    inven = B

    for row in world:
        for block in row:
            diff = goal_h - block
            if diff < 0:
                work_time += diff * -2
                inven -= diff
            elif diff > 0:
                work_time += diff
                inven -= diff

    return (work_time, inven)

N, M, B = map(int, sys.stdin.readline().split())
world = [[] for _ in range(N)]

for i in range(N):
    world[i] = list(map(int, sys.stdin.readline().split()))

min_time = float("inf")
max_world_h = 0

for goal in range(256 + 1):
    expected, left_block = normalize_world(goal)
    # print(f"h: {goal}, expected: {expected}, block: {left_block}")
    if left_block >= 0 and expected <= min_time and max_world_h <= goal:
        max_world_h = goal
        min_time = expected

sys.stdout.write(f"{str(min_time)} {str(max_world_h)}\n")

# 평균으로 안됨
# 4 3 0
# 64 0 0
# 0 0 0
# 0 0 0

# 3 4 1
# 64 64 64 64
# 64 64 64 64
# 64 64 64 63

# 3 4 0
# 64 64 64 64
# 64 64 64 64
# 64 64 64 63

# 3 4 99
# 0 0 0 0
# 0 0 0 0
# 0 0 0 1

# 1 3 68
# 0 0 1

# 3 4 11
# 29 51 54 44
# 22 44 32 62
# 25 38 16 2
