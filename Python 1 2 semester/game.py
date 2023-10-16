import pygame
import random
from math import cos, sin

FPS = 30
WIN_WIDTH = 900
WIN_HEIGHT = 600

WHITE = (255, 255, 255)
ORANGE = (255, 150, 100)
BLACK = (0, 0, 0)
GRAY = (125, 125, 125)
GRAY1 = (169, 169, 169)
LIGHT_BLUE = (64, 128, 255)
GREEN = (0, 200, 64)
YELLOW = (225, 225, 0)
RED = (255, 42, 0)

pygame.init()

clock = pygame.time.Clock()

sc = pygame.display.set_mode((WIN_WIDTH, WIN_HEIGHT))

rak = [[100, 500], [150, 400], [200, 500], [200, 600], [250, 800],
          [50, 800], [100, 600], [100, 500]]

sop = [[100, 850], [120, 800], [140, 850]]
sop1 = [[160, 850], [180, 800], [200, 850]]

r = 40
x = WIN_WIDTH - r
y = 200

x1 = 150
y1 = 550

x3 = 150
y3 = 550
"""
for i in range(len(rak)):
    for j in range(len(rak[i]) - 1):
        x_old = rak[i][j]
        y_old = rak[i][j + 1]
        rak[i][j] = (x_old - x1) * cos(1) - (y_old - y1) * sin(1) + x1
        rak[i][j + 1] = (x_old - x1) * sin(1) + (y_old - y1) * cos(1) + y1

for i in range(len(sop)):
    for j in range(len(sop[i]) - 1):
        x_old = sop[i][j]
        y_old = sop[i][j + 1]
        sop[i][j] = (x_old - x1) * cos(1) - (y_old - y1) * sin(1) + x1
        sop[i][j + 1] = (x_old - x1) * sin(1) + (y_old - y1) * cos(1) + y1
for i in range(len(sop1)):
    for j in range(len(sop1[i]) - 1):
        x_old = sop1[i][j]
        y_old = sop1[i][j + 1]
        sop1[i][j] = (x_old - x1) * cos(1) - (y_old - y1) * sin(1) + x1
        sop1[i][j + 1] = (x_old - x1) * sin(1) + (y_old - y1) * cos(1) + y1
"""
x2 = []
y2 = []
"""
for i in range(10):
    x2.append(random.randrange(0, 800, 1))
    y2.append(random.randrange(0, 600, 1))
"""
while 1:
    sc.fill(BLACK)
    for i in pygame.event.get():
        if i.type == pygame.QUIT:
            exit()
    """
    for i in range(len(x2)):
        pygame.draw.circle(sc, WHITE, (x2[i], y2[i]), 5)
    """
    pygame.draw.polygon(sc, YELLOW, rak)
    pygame.draw.polygon(sc, RED, sop)
    pygame.draw.polygon(sc, RED, sop1)
    pygame.draw.circle(sc, LIGHT_BLUE, (x3, y3), 35)
    pygame.draw.circle(sc, GRAY, (x, y), r)
    pygame.display.update()

    if y >= WIN_HEIGHT - r:

        r = 40
        x = WIN_WIDTH - r
        y = 200

        x1 = 150
        y1 = 550

        x3 = 150
        y3 = 550
        
        rak = [[100, 500], [150, 400], [200, 500], [200, 600], [250, 800],
               [50, 800], [100, 600], [100, 500]]
        sop = [[100, 850], [120, 800], [140, 850]]
        sop1 = [[160, 850], [180, 800], [200, 850]]

        x2 = []
        y2 = []
        for i in range(10):
            x2.append(random.randrange(0, 800, 1))
            y2.append(random.randrange(0, 600, 1))

        for i in range(len(rak)):
            for j in range(len(rak[i]) - 1):
                x_old = rak[i][j]
                y_old = rak[i][j + 1]
                rak[i][j] = (x_old - x1) * cos(1) - (y_old - y1) * sin(1) + x1
                rak[i][j + 1] = (x_old - x1) * sin(1) + (y_old - y1) * cos(1) + y1

        for i in range(len(sop)):
            for j in range(len(sop[i]) - 1):
                x_old = sop[i][j]
                y_old = sop[i][j + 1]
                sop[i][j] = (x_old - x1) * cos(1) - (y_old - y1) * sin(1) + x1
                sop[i][j + 1] = (x_old - x1) * sin(1) + (y_old - y1) * cos(1) + y1

        for i in range(len(sop1)):
            for j in range(len(sop1[i]) - 1):
                x_old = sop1[i][j]
                y_old = sop1[i][j + 1]
                sop1[i][j] = (x_old - x1) * cos(1) - (y_old - y1) * sin(1) + x1
                sop1[i][j + 1] = (x_old - x1) * sin(1) + (y_old - y1) * cos(1) + y1
    else:
        x -= 5
        y += 5
        x3 += 10
        y3 -= 10
        for i in range(len(rak)):
            rak[i][0] += 10
            rak[i][1] -= 10
        for i in range(len(sop)):
            sop[i][0] += 10
            sop[i][1] -= 10
            sop1[i][0] += 10
            sop1[i][1] -= 10
        if y <= WIN_HEIGHT // 2:
            r += 1
        else:
            r -= 1
            print(r)
    clock.tick(FPS)


"""
import pygame

FPS = 120
WIN_WIDTH = 800
WIN_HEIGHT = 400

WHITE = (255, 255, 255)
ORANGE = (255, 150, 100)
BLACK = (0, 0, 0)
GRAY = (125, 125, 125)
GRAY1 = (169, 169, 169)
LIGHT_BLUE = (64, 128, 255)
GREEN = (0, 200, 64)
YELLOW = (225, 225, 0)
PINK = (230, 50, 230)
RED = (255, 40, 0)

pygame.init()

clock = pygame.time.Clock()

sc = pygame.display.set_mode((WIN_WIDTH, WIN_HEIGHT))

surf = pygame.Surface((400, 350))
surf.fill(WHITE)
sc.blit(surf, (0, 0))

raketa = [[100, 100], [200, 10], [300, 100], [100, 100], [100, 300], [300, 300], [300, 100],
          [100, 200], [0, 300], [100, 300], [300, 200], [400, 300], [300, 300],
          [100, 350], [120, 300], [140, 350], [260, 350], [280, 300], [300, 350]]

r = 30
x = 800 - r
y = 0
x1 = 200
y1 = 175

while 1:
    sc.fill(BLACK)
    surf.fill(BLACK)
    for i in pygame.event.get():
        if i.type == pygame.QUIT:
            exit()


    pygame.draw.polygon(surf, LIGHT_BLUE, [[100, 100], [200, 10], [300, 100]])
    pygame.draw.polygon(surf, PINK, [[100, 100], [100, 300], [300, 300], [300, 100]])
    pygame.draw.polygon(surf, ORANGE, [[100, 200], [0, 300], [100, 300]])
    pygame.draw.polygon(surf, ORANGE, [[300, 200], [400, 300], [300, 300]])
    pygame.draw.polygon(surf, RED, [[100, 350], [120, 300], [140, 350]])
    pygame.draw.polygon(surf, RED, [[260, 350], [280, 300], [300, 350]])
    rot = pygame.transform.rotate(surf, 325)
    rot_rect = rot.get_rect(center=(x1, y1))
    sc.blit(rot, rot_rect)
    pygame.draw.circle(sc, GRAY, (x, y), r)
    pygame.display.update()

    if y >= WIN_HEIGHT - r:
        x = 800 - r
        y = 0
        r = 30
        x1 = 600
        y1 = 0
    else:
        x -= 2
        y += 2
        x1 += 2
        y1 -= 2
        if y <= WIN_HEIGHT // 2:
            r += 1
        else:
            r -= 1
    clock.tick(FPS)


"""