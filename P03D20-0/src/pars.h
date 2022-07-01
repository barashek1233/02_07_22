#ifndef SRC_PARS_H_
#define SRC_PARS_H_

int Prior(char);
struct Stack* push(struct Stack*,  char s);
struct Stack* pop(struct Stack*, char *s);
struct Stack* Math_check(struct Stack *Op, const char *in_f, char **Out, int k, int *l);
void polska_parcer(char in_f[100], char **Out);

#endif  // SRC_PARS_H_
