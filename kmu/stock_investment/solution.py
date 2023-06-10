import sys

for _ in range(int(sys.stdin.readline())):
    d = int(sys.stdin.readline())
    stock_prices = list(map(int, sys.stdin.readline().split()))
    stock_prices.reverse()

    big_price = stock_prices[0]
    amount = 0
    money = 0
    for i in range(1, d):
        if stock_prices[i] >= big_price:
            big_price = stock_prices[i]
            money += amount
            amount = 0
        else:
            amount += big_price - stock_prices[i]
    money += amount

    sys.stdout.write(str(money) + "\n")

# sample input
#
# 3
# 3
# 9 5 4
# 3
# 2 5 10
# 6
# 3 3 7 9 7 4

# sample output
#
# 0
# 13
# 14
