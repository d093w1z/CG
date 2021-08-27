import pygame
import sys

BLACK = (0, 0, 0)
GRAY = (200, 200, 200)
WHITE = (255, 255, 255)
green = (0, 255, 0)
blue = (0, 0, 128)
BLOCKSIZE = 20
WINDOW_HEIGHT = 400
WINDOW_WIDTH = 400


def main():
    global SCREEN, CLOCK

    pygame.init()
    SCREEN = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
    CLOCK = pygame.time.Clock()
    SCREEN.fill(BLACK)
    Points = ((2, 5), (9, 2))
    pixels = Line(*Points)

    cords = buildCoords()

    while True:
        drawGrid(pixels)
        drawCords(cords)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                pygame.quit()
                sys.exit()

        pygame.display.update()


def Line(p1, p2):
    P1 = (p1[0], 19 - p1[1])
    P2 = (p2[0], 19 - p2[1])
    return DDA(P1, P2)


def DDA(P1, P2):
    x1, y1 = P1
    x2, y2 = P2

    tmpPixels = []
    pixels = []

    dx = x2-x1
    dy = y2-y1
    m = dy/dx

    step = dx if m <= 1 else dy

    xinc = dx/step
    yinc = dy/step

    tmpPixels.append((x1, y1))

    for s in range(step):
        xnext = tmpPixels[s][0] + xinc
        ynext = tmpPixels[s][1] + yinc
        tmpPixels.append((xnext, ynext))

    for p in tmpPixels:
        pixels.append((round(p[0]), round(p[1])))
    print(pixels)
    return pixels


def buildCoords():

    cords = []
    xCords = []
    yCords = []
    font = pygame.font.Font('freesansbold.ttf', round(3*BLOCKSIZE/4))

    for i in range(BLOCKSIZE, WINDOW_WIDTH, BLOCKSIZE):
        text = font.render(str(round(i/BLOCKSIZE)), True, WHITE, BLACK)
        rect = text.get_rect()
        rect.center = (round(i+(BLOCKSIZE/2)),
                       round(WINDOW_HEIGHT - (BLOCKSIZE/2)))
        xCords.append((text, rect))

    for j in range(BLOCKSIZE, WINDOW_HEIGHT, BLOCKSIZE):
        text = font.render(
            str(round((WINDOW_HEIGHT - j)/BLOCKSIZE)), True, WHITE, BLACK)
        rect = text.get_rect()
        rect.center = (round(BLOCKSIZE/2), round(j-(BLOCKSIZE/2)))
        yCords.append((text, rect))

    originCord = font.render("0", True, WHITE, BLACK)
    oRect = originCord.get_rect()
    oRect.center = (round(BLOCKSIZE/2), round(WINDOW_HEIGHT - (BLOCKSIZE/2)))
    cords.append((originCord, oRect))
    cords.extend(xCords)
    cords.extend(yCords)

    return cords


def drawCords(cords):
    global SCREEN, BLOCKSIZE
    for cord in cords:
        SCREEN.blit(cord[0], cord[1])


def drawGrid(pixels):
    global BLOCKSIZE
    for x in range(0, WINDOW_WIDTH, BLOCKSIZE):
        for y in range(0, WINDOW_HEIGHT, BLOCKSIZE):
            rect = pygame.Rect(x, y, BLOCKSIZE, BLOCKSIZE)
            normX = round(x/BLOCKSIZE)
            normY = round(y/BLOCKSIZE)
            if (normX, normY) in pixels:
                pygame.draw.rect(SCREEN, WHITE, rect)
            else:
                pygame.draw.rect(SCREEN, GRAY, rect, 1)


if __name__ == "__main__":
    main()
