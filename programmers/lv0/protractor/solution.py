# Lv. 0 - 각도기

def solution(angle):
    if 0 <= angle < 90:
        return 1
    elif angle == 90:
        return 2
    elif angle < 180:
        return 3
    else:
        return 4
