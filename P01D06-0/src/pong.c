#include <stdio.h>
#include <stdlib.h>

int main() {
    char arr[28][83];
    int i;
    int j;
    char step;
    int x = 5, xb = 40, yb = 13, y = 14, y1 = 13, y2 = 12, xr = 76, yr = 14, yr1 = 13, yr2 = 12;
    char key;
    char racketL, racketR;
    int alpha = 0;
    int speed = 1;
    int lcount = 0;
    int rcount = 0;

    do {
        for (int i = 0; i < 27; i++) {
            for (int j = 0; j < 82; j++) {
                if (i == 0 || i == 26) {
                    printf("#");
                } else if (j == 0 || j == 81) {
                    printf("#");
                } else if (j == x && (i == y || i == y1 || i == y2)) {
                    printf("@");
                } else if (j == xr && (i == yr || i == yr1 || i == yr2)) {
                    printf("@");
                } else if (j == xb && i == yb) {
                    printf("@");
                } else if (j == 40) {
                    printf("|");
                } else if (i == 1 && j == 39) {
                    printf("%d", lcount);
                } else if (i == 1 && j == 41) {
                    printf("%d", rcount);
                } else {
                    if (rcount > 9 && j == 1 && i == 1) {
                        printf("");
                    }
                    if (lcount > 9 && (j == 2 || j == 71) && i == 1) {
                        printf("");
                    } else {
                    printf(" ");
                    }
                }
                if (j == 81) {
                    printf("\n");
                }
            }
        }
        key = getchar();
        if (key == ' ' || key == 'a' || key == 'z' || key == 'k' || key == 'm') {
                if (xb == x + 1 && (y == yb || y1 == yb || y2 == yb)) {
                    speed = 1;
                } else if (xb == xr - 1 && (yr == yb || yr1 == yb || yr2 == yb)) {
                    speed = -1;
                }
                if (yb == 1) {
                  alpha = 1;
               } else if (yb == 25) {
                   alpha = -1;
                }
            if (xb == x + 1 && y2 == yb) {
                alpha = -1;
            } else if (xb == x + 1 && y1 == yb) {
                alpha = 0;
            } else if (xb == x + 1 && y == yb) {
                alpha = 1;
            } else if (xb == xr - 1 && yr2 == yb) {
                alpha = -1;
            } else if (xb == xr - 1 && yr1 == yb) {
                alpha = 0;
            } else if (xb == xr - 1 && yr == yb) {
                alpha = 1;
            }
                yb = yb + alpha;
                xb = xb + speed;
                }
        if (key == 'a' && (y != 4 || y1 != 3 || y2 != 2)) {
            y--;
            y1--;
            y2--;
        }
        if (key == 'z'&& (y != 25 || y1 != 24 || y2 != 23)) {
            y++;
            y1++;
            y2++;
        }
        if (key == 'k' && (yr != 4 || yr1 != 3 || yr2 != 2)) {
            yr--;
            yr1--;
            yr2--;
        }
        if (key == 'm' && (yr != 25 || yr1 != 24 || yr2 != 23)) {
            yr++;
            yr1++;
            yr2++;
        }
        system("clear");
            if (xb == 1) {
                rcount++;
                x = 5;
                xb = 40;
                yb = 13;
                y = 14;
                y1 = 13;
                y2 = 12;
                xr = 75;
                yr = 14;
                yr1 = 13;
                yr2 = 12;
            } else if (xb == 81) {
                lcount++;
                x = 5;
                xb = 40;
                yb = 12;
                y = 13;
                y1 = 12;
                y2 = 11;
                xr = 75;
                yr = 13;
                yr1 = 12;
                yr2 = 11;
            }
    } while ((lcount != 21) && (rcount != 21));
    if (lcount == 21) {
        printf("Поздравляю игрока слева!");
    } else {
        printf("Поздравляю игрока справа!");
    }
    return 0;
}


