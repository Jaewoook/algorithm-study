import sys

for _ in range(int(sys.stdin.readline())):
    N = sorted(list(sys.stdin.readline().strip()))

    for idx in range(len(N)):
        if N[idx] != '0' and idx != 0:
            tmp = N[0]
            N[0] = N[idx]
            N[idx] = tmp
            break

    sys.stdout.write("".join(N) + "\n")


# sample input
#
# 3
# 201
# 911
# 12131191

# sample output
#
# 102
# 119
# 11111239
