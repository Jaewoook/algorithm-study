import sys

N = int(sys.stdin.readline())

# version 1 - find count of divisor of 5
five = 0
for i in range(5, N + 1):
    while i > 0:
        if i % 5 == 0:
            five += 1
            i //= 5
        else:
            break

sys.stdout.write(str(five) + "\n")

# version 2 - calculate factorial and count 0
# factorial = 1
# for i in range(2, N + 1):
#     factorial *= i

# zero_count = 0
# while factorial % 10 == 0:
#     zero_count += 1
#     factorial //= 10

# sys.stdout.write(str(zero_count) + "\n")
