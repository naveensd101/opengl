import random

for _ in range(20):
    parityX = random.randint(0, 1)
    parityY = random.randint(0, 1)
    x = random.random()
    y = random.random()
    if parityX == 0:
        x = -x
    if parityY == 0:
        y = -y
    print(x, y)

