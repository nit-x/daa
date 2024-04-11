// Insertion sort
#include <stdio.h>
#define max 7

int a[max] ={4, 25, 45, 47, 12, 34, 2};
int n = max;
int i, j, key;

int main() {
    for(j = 1; j < n; j++){
        key = a[j];
        i = j-1;
        while(a[i]>key){
            a[i+1] = a[i];
            i = i - 1;
        }
        a[i+1] = key;
    }
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
