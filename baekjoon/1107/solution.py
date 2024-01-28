import sys

N = sys.stdin.readline().strip()
target_channel = int(N)
M = int(sys.stdin.readline())

broken_buttons = []
if M > 0:
    broken_buttons = list(map(int, sys.stdin.readline().split()))

CURRENT_CHANNEL = 100

move_count = abs(target_channel - CURRENT_CHANNEL)

if move_count == 0:
    sys.stdout.write("0\n")
else:
    for ch in range(1_000_001):
        pressed = 0
        can_move = True
        move_ch = ch
        while True:
            if ch % 10 in broken_buttons:
                can_move = False
            pressed += 1
            ch //= 10

            if ch == 0 or not can_move:
                break

        if not can_move:
            continue

        move_count = min(move_count, abs(target_channel - move_ch) + pressed)

    sys.stdout.write(str(move_count) + "\n")
