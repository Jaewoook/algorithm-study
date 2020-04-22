T = int(input())

arr = []
for i in range(T):
    arr.append(int(input()))

fibo = [1, 1, 2, 4]
for i in range(4, 69):
    fibo.append(fibo[i - 1] + fibo[i - 2] + fibo[i - 3] + fibo[i - 4])

for i in arr:
    print(fibo[i])
