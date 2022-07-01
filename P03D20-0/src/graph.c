#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "pars.h"
#include "math_polka.h"

#define height 25
#define wight 80
#define X_S 0.159
#define Y_S 12.000

double test(double a, char *Out);
void Intro(void);

int main() {
    Intro();

    int x = height, y = wight;
    char pole[x][y];
    char formula[100];
    char *Out;
    fgets(formula, 100, stdin);
    polska_parcer(formula, &Out);
    for (int i = 0; i < y; i++) {
        double dot;
        dot = test(i * X_S, Out) * Y_S  + Y_S;
        for (int j = 0; j < x; j++) {
            if (dot >= (j - 0.5) && dot < (j + 0.5)) {
                pole[j][i] = '*';
            } else {
                pole[j][i] = '.';
            }
        }
    }
    printf("\n");
    for (int j = 0; j < x; j++) {
        for (int i = 0; i < y; i++) {
            printf("%c", pole[j][i]);
        }
        printf("\n");
    }
    free(Out);
    return 0;
}

double test(double a, char *Out) {
    double j = f(Out, a);
    return j;
}

void Intro(void) {
    printf("\e[1;1H\e[2J\e[3J");
    for (int i = 0; i < 70; i++)
        printf("-");
    printf("\n|                                                                    |\n");
    printf("|                          Описание:                                 |\n");
    printf("|    1.  Программа на языке С для создания графиков функций.         |\n");
    printf("|    2.  Условный размер поля для отображения графиков 25 на 80.     |\n");
    printf("|        Область определения [0; 4 Пи]. Область значений [-1; 1]     |\n");
    printf("|    3.  Ось ординат направлена вниз, ось абсцисс - направо.         |\n");
    printf("|    4.  Возможные операции & функции:                               |\n");
    printf("|        \"+\", \"-\", \"*\", \"/\", \"()\", \"sin()\",                          |\n");
    printf("|        \"cos()\", \"tan()\",\"ctg()\", sqrt(), ln().                     |\n");
    printf("|    5.  Отрицательное число в функции задается в скобках: (-5).     |\n");
    printf("|    6.  В функции переменная обозначается в виде \"х\".               |\n");
    printf("|    7.  В функции нельзя писать математические выражения,           |\n");
    printf("|        которые приводят к делению на ноль.                         |\n");
    printf("|    8.  При записи функции нужно внамательно отнестись к            |\n");
    printf("|        равному количеству открывающих и закрывающих скобочек.      |\n");
    printf("|                                                                    |\n");
    for (int i = 0; i < 70; i++)
        printf("-");
    printf("\n");
}
