import sys

BLOCKS: tuple[tuple[tuple[int, int]]] = (
    # 1-1
    #
    # 0 0 0 0
    ((0, 0), (0, 1), (0, 2), (0, 3)),
    # 1-2
    #
    # 0
    # 0
    # 0
    # 0
    ((0, 0), (1, 0), (2, 0), (3, 0)),
    # 2
    #
    # 0 0
    # 0 0
    ((0, 0), (1, 0), (0, 1), (1, 1)),
    # 3-1
    #
    # 0
    # 0
    # 0 0
    ((0, 0), (1, 0), (2, 0), (2, 1)),
    # 3-2
    #
    #   0
    #   0
    # 0 0
    ((0, 1), (1, 1), (2, 1), (2, 0)),
    # 3-3
    #
    # 0 0 0
    # 0
    ((0, 0), (0, 1), (0, 2), (1, 0)),
    # 3-4
    #
    # 0 0 0
    #     0
    ((0, 0), (0, 1), (0, 2), (1, 2)),
    # 3-5
    #
    # 0 0
    # 0
    # 0
    ((0, 0), (1, 0), (2, 0), (0, 1)),
    # 3-6
    #
    # 0 0
    #   0
    #   0
    ((0, 1), (1, 1), (2, 1), (0, 0)),
    # 3-7
    #
    # 0
    # 0 0 0
    ((0, 0), (1, 0), (1, 1), (1, 2)),
    # 3-8
    #
    #     0
    # 0 0 0
    ((1, 0), (1, 1), (1, 2), (0, 2)),
    # 4-1
    #
    # 0 0 0
    #   0
    ((0, 0), (0, 1), (0, 2), (1, 1)),
    # 4-2
    #
    #   0
    # 0 0 0
    ((1, 0), (1, 1), (1, 2), (0, 1)),
    # 4-3
    #
    # 0
    # 0 0
    # 0
    ((0, 0), (1, 0), (2, 0), (1, 1)),
    # 4-4
    #
    #   0
    # 0 0
    #   0
    ((0, 1), (1, 1), (2, 1), (1, 0)),
    # 5-1
    #
    # 0
    # 0 0
    #   0
    ((0, 0), (1, 0), (1, 1), (2, 1)),
    # 5-2
    #
    #   0
    # 0 0
    # 0
    ((0, 1), (1, 1), (1, 0), (2, 0)),
    # 5-3
    #
    # 0 0
    #   0 0
    ((0, 0), (0, 1), (1, 1), (1, 2)),
    # 5-4
    #
    #   0 0
    # 0 0
    ((1, 0), (1, 1), (0, 1), (0, 2)),
)

N, M = map(int, sys.stdin.readline().split())
board = [[0] * M for _ in range(N)]

for i in range(N):
    board[i] = list(map(int, sys.stdin.readline().split()))

max_score = 0

for i in range(N):
    for j in range(M):
        for block in BLOCKS:
            score = 0
            possible = True
            for square in block:
                next_i, next_j = square
                next_i += i
                next_j += j

                if not (0 <= next_i < N and 0 <= next_j < M):
                    possible = False
                    break

                score += board[next_i][next_j]

            if possible:
                max_score = max(max_score, score)


sys.stdout.write(str(max_score) + "\n")
