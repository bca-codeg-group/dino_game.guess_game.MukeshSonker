#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 10

int dinoX, dinoY;
int obstacleX;
int score;

void initialize() {
    dinoX = 5;
    dinoY = HEIGHT - 1;
    obstacleX = WIDTH - 1;
    score = 0;
}

void draw() {
    system("cls");

    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("\n");

    for (int i = 2; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == dinoY && j == dinoX) {
                printf("D");
            } else if (i == HEIGHT - 1 && j == obstacleX) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("\n");

    printf("Score: %d\n", score);
}

void update() {
    if (obstacleX == 0) {
        score++;
        obstacleX = WIDTH - 1;
    } else {
        obstacleX--;
    }

    if (kbhit()) {
        char key = getch();
        if (key == ' ') {
            if (dinoY == HEIGHT - 1) {
                dinoY -= 2;
            }
        }
    }

    if (dinoY < HEIGHT - 1) {
        dinoY++;
    }
}

int main() {
    initialize();

    while (1) {
        draw();
        update();
    }

    return 0;
}
