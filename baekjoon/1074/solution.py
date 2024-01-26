import sys

count = 0
result = -1

def search(start_r: int, start_c: int, search_size: int):
    global arr, count, result
    if result != -1:
        return

    if search_size == 2:
        for row in range(start_r, start_r + search_size):
            if result != -1:
                    break
            for col in range(start_c, start_c + search_size):
                if result != -1:
                    break
                if row == target_row and col == target_col:
                    result = count
                count += 1
    else:
        half = search_size // 2
        offset = half * half
        if start_r <= target_row < start_r + half and start_c <= target_col < start_c + half:
            search(start_r, start_c, half)
        else:
            count += offset

        if start_r <= target_row < start_r + half and start_c + half <= target_col < start_c + half * 2:
            search(start_r, start_c + half, half)
        else:
            count += offset

        if start_r + half <= target_row < start_r + half * 2 and start_c <= target_col < start_c + half:
            search(start_r + half, start_c, half)
        else:
            count += offset

        if start_r + half <= target_row < start_r + half * 2 and start_c + half <= target_col < start_c + half * 2:
            search(start_r + half, start_c + half, half)
        else:
            count += offset

N, target_row, target_col = map(int, sys.stdin.readline().split())
size = 2 ** N
search(0, 0, size)

sys.stdout.write(str(result) + "\n")
