#include "math_polka.h"
#include "pars.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct Double {
    double c;
    struct Double* Next;
};

double f(char *PN, double x) {
    struct Double *t2 = NULL;
    int i = 0;
    while (i < (int)strlen(PN) && PN[i]) {
        if (PN[i] >= '0' && PN[i] <= '9') {
            double z = 0;
            while (PN[i] != '.' && PN[i] != ' ') {
                z *= 10;
                z += PN[i] - '0';
                i++;
            }
            if (PN[i] == '.') i++;
            double e = 1;
            while (PN[i] != ' ' && PN[i]) {
                z *= 10;
                z += PN[i] - '0';
                e /= 10;
                i++;
            }
            z *= e;
            t2 = InString(t2, z);
        } else {
            if (PN[i] == 'x') {
                t2 = InString(t2, x);
            }
        }
        if (PN[i] == 'S') {
            double a;
            t2 = OutString(t2, &a);
            a = sin(a);
            t2 = InString(t2, a);
        }
        if (PN[i] == 'C') {
            double a;
            t2 = OutString(t2, &a);
            a = cos(a);
            t2 = InString(t2, a);
        }
        if (PN[i] == 'T') {
            double a;
            t2 = OutString(t2, &a);
            a = tan(a);
            t2 = InString(t2, a);
        }
        if (PN[i] == 'G') {
            double a;
            t2 = OutString(t2, &a);
            a = cos(a)/sin(a);
            t2 = InString(t2, a);
        }
        if (PN[i] == 'Q') {
            double a;
            t2 = OutString(t2, &a);
            a = sqrt(a);
            t2 = InString(t2, a);
        }
        if (PN[i] == '~') {
            double a;
            t2 = OutString(t2, &a);
            a = -a;
            t2 = InString(t2, a);
        }
        if (PN[i] == '+') {
            double a;
            t2 = OutString(t2, &a);
            double b;
            t2 = OutString(t2, &b);
            t2 = InString(t2, a + b);
        }
        if (PN[i] == '*') {
            double a;
            t2 = OutString(t2, &a);
            double b;
            t2 = OutString(t2, &b);
            t2 = InString(t2, a * b);
        }
        if (PN[i] == '-') {
            double a;
            t2 = OutString(t2, &a);
            double b;
            t2 = OutString(t2, &b);
            t2 = InString(t2, b - a);
        }
        if (PN[i] == '/') {
            double a;
            t2 = OutString(t2, &a);
            double b;
            t2 = OutString(t2, &b);
            t2 = InString(t2, b / a);
        }
        if (PN[i] == '^') {
            double a;
            t2 = OutString(t2, &a);
            double b;
            t2 = OutString(t2, &b);
            t2 = InString(t2, pow(b, a));
        }
        i++;
    }
    if (t2 != NULL) {
        x = t2 -> c;
        free(t2);
    }
    return x;
}

struct Double* InString(struct Double *t, double s) {
    struct Double *t1 = malloc(sizeof(struct Double));
    t1 -> c = s;
    t1 -> Next = t;
    return t1;
}

struct Double* OutString(struct Double *t, double *s) {
  struct Double *t1 = t;
  *s = t -> c;
  t = t->Next;
  free(t1);
  return t;
}
