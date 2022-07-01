#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#define N 25
#define M 80

void input(int arr[N][M]);
void otrisopvka(int arr[N][M]);
void izmenenie(int arr[N][M], int i, int j, int new_arr[N][M]);
void copy(int new_arr[N][M], int arr[N][M]);

int main() {
    int arr[N][M];
    char key;
    initscr();
    curs_set(0);
    halfdelay(1);
    input(arr);
    key = getch();
    if (freopen("/dev/tty", "r", stdin) != NULL) {
        int new_arr[N][M];
        int speed = 10;
        while (key != 'q') {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    izmenenie(arr, i, j, new_arr);
                }
            }
            if (key == '-' && speed > 6) {
                speed -= 5;
            } else if (key == '+' && speed < 1000000) {
                speed += 5;
            }
            copy(new_arr, arr);
            otrisopvka(arr);
            usleep(speed);
            key = getch();
        }
    } else {
            printf("Ошибка! Не удалось изменить настройки терминала!");
        }
        endwin();
}

void input(int arr[N][M]) {
    char p;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &p);
            if (p == '1') {
                arr[i][j] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }
}

void otrisopvka(int arr[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1) {
                mvprintw(i, j, "#", arr[i][j]);
            } else {
                mvprintw(i, j, " ", arr[i][j]);
            }
            refresh();
        }
    }
}

void izmenenie(int arr[N][M], int i, int j, int new_arr[N][M]) {
    int count = 0;
    if (arr[(i - 1 + N) % N][(j - 1 + M) % M] == 1) {
        count++;
    }
    if (arr[(i - 1 + N) % N][j] == 1) {
        count++;
    }
    if (arr[(i - 1 + N) % N][(j + 1 + M) % M] == 1) {
        count++;
    }
    if (arr[(i + 1 + N) % N][(j - 1 + M) % M] == 1) {
        count++;
    }
    if (arr[(i + 1 + N) % N][j] == 1) {
        count++;
    }
    if (arr[(i + 1 + N) % N][(j + 1 + M) % M] == 1) {
        count++;
    }
    if (arr[i][(j - 1 + M) % M] == 1) {
        count++;
    }
    if (arr[i][(j + 1 + M) % M] == 1) {
        count++;
    }
    if (arr[i][j] == 1 && (count == 2 || count == 3)) {
        new_arr[i][j] = 1;
    } else if (arr[i][j] == 0 && count == 3) {
        new_arr[i][j] = 1;
    } else {
        new_arr[i][j] = 0;
    }
}

void copy(int new_arr[N][M], int arr[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = new_arr[i][j];
        }
    }
}
