# Uses python3
import math

money = int(input())
coins = [1, 3, 4]
minCoins = [0] + [math.inf]*money

for i in range(1, money+1):
    for j in coins:
        if i >= j:
            coin = minCoins[i-j]+1
            if coin < minCoins[i]:
                minCoins[i] = coin


print(minCoins[money])
