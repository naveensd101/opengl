import random
print(10)
for _ in range(10):
    x = random.random()
    y = random.random()
    if(random.random() < 0.5):
        x = -x
    if(random.random() < 0.5):
        y = -y
    print(x, y)
