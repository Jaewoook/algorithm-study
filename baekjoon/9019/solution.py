import sys
from collections import deque

MAX_R = 10000

for _ in range(int(sys.stdin.readline())):
    CREATED = [False] * MAX_R
    queue: deque[tuple[int, str]] = deque()
    A, B = map(int, sys.stdin.readline().split())

    queue.append((A, ""))
    CREATED[A] = True
    cmd = ""
    result = ""
    while len(queue) > 0:
        current, cmd = queue.popleft()
        if current == B:
            break

        d_result = current * 2 % MAX_R
        d_cmd = cmd + "D"
        if not CREATED[d_result]:
            CREATED[d_result] = True
            queue.append((d_result, d_cmd))

        s_result = current - 1 if current > 0 else 9999
        s_cmd = cmd + "S"
        if not CREATED[s_result]:
            CREATED[s_result] = True
            queue.append((s_result, s_cmd))

        l_result = (current % 1000) * 10 + current // 1000
        l_cmd = cmd + "L"
        if not CREATED[l_result]:
            CREATED[l_result] = l_cmd
            queue.append((l_result, l_cmd))

        r_result = current // 10 + (current % 10) * 1000
        r_cmd = cmd + "R"
        if not CREATED[r_result]:
            CREATED[r_result] = r_cmd
            queue.append((r_result, r_cmd))

    sys.stdout.write(cmd + "\n")
