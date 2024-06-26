// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a[30], count = 0;

int place(int pos){
    int i;
    for(i=1; i<pos; i++){
        if((a[i]==a[pos]) ||(abs(a[i]-a[pos])==abs(i-pos))){
            return 0;
        }
    }
}

void print_sol(int n){
    int i, j;
    count++;
    printf("\n\nSolution #%d:/n", count);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(a[i] == j){
                printf("Q\t");
            }else{
                printf("*\t");
            }
        }
    }
    
}

void queen(int n){
    int k = 1;
    a[k] = 0;
    while(k!=0){
        a[k] = a[k] + 1;
        while((a[k]<=n) && !place(k)){
            a[k]++;
        }
        if(a[k]<=n){
            if(k==n){
                print_sol(n);
            }else{
                k++;
                a[k] = 0;
            }
        }else{
            k--;
        }
    }
}

int main() {
    queen(2);

    return 0;
}
