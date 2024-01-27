import sys

WHITE = 0
BLUE = 1

N = int(sys.stdin.readline())
paper = []

def cut(start_i: int, start_j: int, size: int):
    if is_all_same(start_i, start_j, size):
        color = paper[start_i][start_j]
        return (1, 0) if color == WHITE else (0, 1)

    half = size // 2
    w1, b1 = cut(start_i, start_j, half)
    w2, b2 = cut(start_i, start_j + half, half)
    w3, b3 = cut(start_i + half, start_j, half)
    w4, b4 = cut(start_i + half, start_j + half, half)

    return (w1 + w2 + w3 + w4, b1 + b2 + b3 + b4)

def is_all_same(start_i: int, start_j: int, size: int):
    c = paper[start_i][start_j]
    for i in range(start_i, start_i + size):
        for j in range(start_j, start_j + size):
            if c != paper[i][j]:
                return False

    return True

for _ in range(N):
    paper.append(list(map(int, sys.stdin.readline().split())))

n_white, n_blue = cut(0, 0, N)

sys.stdout.write(str(n_white) + "\n" + str(n_blue) + "\n")
