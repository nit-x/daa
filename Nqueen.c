#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *a;
int count = 0;

int place(int pos, int n) {
    for (int i = 1; i < pos; i++) {
        if ((a[i] == a[pos]) || (abs(a[i] - a[pos]) == abs(i - pos))) {
            return 0;
        }
    }
    return 1;
}

void print_sol(int n) {
    count++;
    printf("\n\nSolution #%d:\n", count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == j) {
                printf("Q\t");
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
}

void queen(int n) {
    a = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
    }
    int k = 1;
    a[k] = 0;
    while (k != 0) {
        a[k]++;
        while ((a[k] <= n) && !place(k, n)) {
            a[k]++;
        }
        if (a[k] <= n) {
            if (k == n) {
                print_sol(n);
            } else {
                k++;
                a[k] = 0;
            }
        } else {
            k--;
        }
    }
    free(a);
}

int main() {
    int n = 4; // Change n to the desired board size
    queen(n);
    return 0;
}
