#ifndef EX1_H
#define EX1_H

int fold (int count, int arr[], int (*fn) (int, int), int initial);
int fold_help(int count, int num, int value, int arr[], int (*fn) (int, int));
int fn_add (int a, int b);
int fn_count_odd(int a, int b);

#endif