import pygame

pygame.init()
sc = pygame.display.set_mode((400, 400))
clock = pygame.time.Clock()
FPS = 60
RED = (255, 0, 0)
GREEN = (0, 200, 64)
BLACK = (0, 0, 0)
x = 300
y = 300
w = 180
h = 70
x_c = 390
y_c = 335 
r = 60
k = 0.6
k1 = 0.4
t = 1
while 1:
    sc.fill(BLACK)
    for i in pygame.event.get():
        if i.type == pygame.QUIT:
            exit()

    pygame.draw.ellipse(sc, GREEN, (x, y, w, h))
    pygame.draw.circle(sc, GREEN, (x_c, y_c), r)
    pygame.display.update()
    if x > 0:
        x -= 5
        y -= 5
        w -= int(5*k)
        h -= int(3*k1)
        x_c = x + int(w / 2)
        y_c = y + int(h / 2)
        r -= int(2*k)
    else:
        x = 300
        y = 300
        w = 180
        h = 70
        x_c = 390
        y_c = 335
        r = 60
        k = 0.6
        k1 = 0.4
        t = 1

    clock.tick(FPS)