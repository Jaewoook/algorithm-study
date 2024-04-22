import sys

def toInt(d: str):
    o = ord(d)
    if ord('0') <= o <= ord('9'):
        return o - ord('0')
    return o - ord('A') + 10

def toAlpha(d: int):
    if d < 10:
        return chr(ord('0') + d)
    return chr(ord('A') + d - 10)

def toAlphaValue(n: int):
    value = ''
    while n > 0:
        digit = n % 36
        n //= 36
        value = toAlpha(digit) + value

    return value if len(value) > 0 else '0'

input = lambda: sys.stdin.readline().rstrip()
print = sys.stdout.write

N = int(input())
diff = [0] * 36

integer = 0

for _ in range(N):
    valuable = False
    value = input()
    integer += int(value, 36)
    valueLength = len(value)
    for i in range(valueLength):
        digit = value[i]
        if not valuable and digit == '0':
            continue
        valuable = True
        place = valueLength - 1 - i
        order = toInt(digit)
        diff[order] += (36 ** place) * (35 - order)

diff.sort(reverse=True)
K = int(input())

for i in range(K):
    integer += diff[i]

print(f"{toAlphaValue(integer)}\n")
