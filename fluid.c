#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 20
#define HEIGHT 10

char grid[HEIGHT][WIDTH];

void initializeGrid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = ' ';
        }
    }
}

void drawWalls() {
    for (int y = 0; y < HEIGHT; y++) {
        grid[y][0] = '#';
        grid[y][WIDTH - 1] = '#';
    }
    for (int x = 0; x < WIDTH; x++) {
        grid[0][x] = '#';
        grid[HEIGHT - 1][x] = '#';
    }
}

void drawWater(int x, int y) {
    if (x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1) {
        grid[y][x] = '~';
    }
}

void displayGrid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x]);
        }
        printf("\n");
    }
}

int main() {
    initializeGrid();
    drawWalls();
    drawWater(5, 5);
    drawWater(6, 5);
    drawWater(7, 5);
    displayGrid();
    return 0;
}