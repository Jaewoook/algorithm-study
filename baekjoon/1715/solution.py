import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()
debug = print
print = sys.stdout.write

def solution():
    N = int(input())

    cards = []
    for _ in range(N):
        cards.append(int(input()))

    heapq.heapify(cards)
    count = 0
    while len(cards) > 2:
        card1 = heapq.heappop(cards)
        card2 = heapq.heappop(cards)
        count += card1 + card2
        heapq.heappush(cards, card1 + card2)

    if len(cards) == 2:
        count += cards[0] + cards[1]

    print(str(count) + "\n")

solution()
