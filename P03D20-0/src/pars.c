#include "pars.h"
#include <stdio.h>
#include <stdlib.h>
#define sin 'S'
#define cos 'C'
#define tan 'T'
#define ctg 'G'
#define sqrt 'Q'
#define ln 'L'
struct Stack {
    char c;
    struct Stack* Next;
};

int Prior(char);
struct Stack* push(struct Stack*,  char s);
struct Stack* pop(struct Stack*, char *s);
struct Stack* Math_check(struct Stack *Op, const char *in_f, char **Out, int k, int *l);


void polska_parcer(char in_f[100], char **Out) {
  *Out = malloc(sizeof(char) * 1000);
  struct Stack *t, *Op = NULL;
  char a;
  int k = 0, l = 0;
  while (in_f[k] != '\0') {
    if (in_f[k] == ')') {
      while ((Op -> c) != '(') {
        Op = pop(Op, &a);
        (*Out)[l++] = a;
        (*Out)[l++] = ' ';
      }
      t = Op;
      Op = Op -> Next;
      free(t);
    }
    Op = Math_check(Op, in_f, Out, k, &l);
    if (in_f[k] == 'x') {
      (*Out)[l++] = in_f[k];
      (*Out)[l++] = ' ';
    }
    if (k != 0 && (in_f[k] == '-' && in_f[k-1] == '(' && (in_f[k+1] >= '0' && in_f[k+1] <= '9'))) {
      in_f[k] = '~';
    }
    if ((in_f[k] >= '0' && in_f[k] <= '9')
      && (in_f[k+1] >= '0' && in_f[k+1] <= '9')) {
      (*Out)[l++] = in_f[k];
    } else if ((in_f[k] >= '0' && in_f[k] <= '9')
      && (in_f[k+1] == '.')) {
        (*Out)[l++] = in_f[k];
        (*Out)[l++] = in_f[k+1];
    } else if (in_f[k] >= '0' && in_f[k] <= '9') {
      (*Out)[l++] = in_f[k];
      (*Out)[l++] = ' ';
    }
    if ( in_f[k] == '(' ) Op = push(Op, in_f[k]);
    if ( in_f[k] == '+' || in_f[k] == '-' || in_f[k] == '*'
      || in_f[k] == '/' || in_f[k] == '~' || in_f[k] == '^') {
      while (Op != NULL && Prior(Op -> c) >= Prior(in_f[k])) {
        Op = pop(Op, &a);
        (*Out)[l++] = a;
        (*Out)[l++] = ' ';
      }
      Op = push(Op, in_f[k]);
    }
    k++;
  }
  while (Op !=NULL) {
    Op = pop(Op, &a);
    (*Out)[l++] = a;
  }
  (*Out)[l] = '\0';
}

struct Stack* Math_check(struct Stack *Op, const char *in_f, char **Out, int k, int *l) {
  if ((in_f[k] == 's' && in_f[k+1] == 'i'
       && in_f[k+2] == 'n' && in_f[k+3] == '(')) {
      Op = push(Op, sin);
      *Out[*l++] = ' ';
    }
    if ((in_f[k] == 'c' && in_f[k+1] == 'o'
       && in_f[k+2] == 's' && in_f[k+3] == '(')) {
      Op = push(Op, cos);
      *Out[*l++] = ' ';
    }
    if ((in_f[k] == 't' && in_f[k+1] == 'a'
       && in_f[k+2] == 'n' && in_f[k+3] == '(')) {
      Op = push(Op, tan);
      *Out[*l++] = ' ';
    }
    if ((in_f[k] == 'c' && in_f[k+1] == 't'
      && in_f[k+2] == 'g' && in_f[k+3] == '(')) {
      Op = push(Op, ctg);
      *Out[*l++] = ' ';
    }
    if ((in_f[k] == 's' && in_f[k+1] == 'q'
      && in_f[k+2] == 'r' && in_f[k+3] == 't' && in_f[k+4] == '(')) {
      Op = push(Op, sqrt);
      *Out[*l++] = ' ';
    }
    if ((in_f[k] == 'l' && in_f[k+1] == 'n' && in_f[k+2] == '(')) {
      Op = push(Op, ln);
      *Out[*l++] = ' ';
    }
  return Op;
}

int Prior(char a) {
  int res = 0;
  switch (a) {
    case 'Q': case '~': case '^': res = 5; break;
    case 'S': case 'C': case 'T': case 'G': case 'L': res = 4; break;
    case '*': case '/': res = 3; break;
    case '-': case '+': res = 2; break;
    case '(': res = 1; break;
  }
  return res;
}

struct Stack* push(struct Stack *t, char s) {
    struct Stack *t1 = malloc(sizeof(struct Stack));
    t1 -> c = s;
    t1 -> Next = t;
    return t1;
}

struct Stack* pop(struct Stack *t, char *s) {
  struct Stack *t1 = t;
  *s = t -> c;
  t = t->Next;
  free(t1);
  return t;
}
