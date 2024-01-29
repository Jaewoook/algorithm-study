import sys
import heapq

for _ in range(int(sys.stdin.readline())):
    T = int(sys.stdin.readline())

    left = {}
    min_q: list[int] = []
    max_q: list[int] = []
    q_size = 0
    for _ in range(T):
        OP, V = sys.stdin.readline().split()
        V = int(V)

        if OP == "I":
            q_size += 1
            left.setdefault(V, 0)
            left[V] += 1
            heapq.heappush(min_q, V)
            heapq.heappush(max_q, -V)
        elif OP == "D":
            if q_size == 0:
                continue

            v = 0
            if V == -1:
                while True:
                    v = heapq.heappop(min_q)
                    if left[v] != 0:
                        break

            if V == 1:
                while True:
                    v = -heapq.heappop(max_q)
                    if left[v] != 0:
                        break

            left[v] -= 1
            q_size -= 1

    if q_size == 0:
        sys.stdout.write("EMPTY\n")
    else:
        while True:
            max_val = -heapq.heappop(max_q)
            if left[max_val] != 0:
                break

        if q_size > 1:
            while True:
                min_val = heapq.heappop(min_q)
                if left[min_val] != 0:
                    break

        else:
            min_val = max_val

        sys.stdout.write(f"{str(max_val)} {str(min_val)}\n")
