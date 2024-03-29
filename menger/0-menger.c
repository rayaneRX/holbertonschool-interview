#include <stdio.h>
#include <math.h>

void drawSponge(int size, int x, int y) {
    int i, j;
    for (i = x; i < x + size; i++) {
        for (j = y; j < y + size; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void menger(int level) {
    if (level < 0)
        return;
    
    int size = pow(3, level);
    int i, j;
    for (i = 0; i < size; i += size / 3) {
        for (j = 0; j < size; j += size / 3) {
            if (i == size / 3 && j == size / 3)
                continue;
            drawSponge(size / 3, i, j);
        }
    }
}
