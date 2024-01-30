import sys

input = lambda: sys.stdin.readline().rstrip()

P1 = input()
P2 = input()

LP1 = len(P1) + 1
LP2 = len(P2) + 1
LCS = [[0] * LP2 for _ in range(LP1)]

for i in range(1, LP1):
    for j in range(1, LP2):
        LCS[i][j] = LCS[i - 1][j - 1] + 1 if P1[i - 1] == P2[j - 1] else max(LCS[i - 1][j], LCS[i][j - 1])

i = LP1 - 1
j = LP2 - 1
result = ""

while i > 0 and j > 0:
    if LCS[i][j - 1] == LCS[i][j]:
        j -= 1
    elif LCS[i - 1][j] == LCS[i][j]:
        i -= 1
    elif LCS[i - 1][j - 1] + 1 == LCS[i][j]:
        result = P1[i - 1] + result
        i -= 1
        j -= 1

sys.stdout.write(result + "\n")
