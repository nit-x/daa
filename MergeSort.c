// INnsertion sort
#include <stdio.h>
#define max 7

int a[max] ={4, 25, 45, 47, 12, 34, 2};
int n = max;
int i, j, k;

void merge(int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    
    for(i=0; i<n1; i++){
        L[i] = a[l+i];
    }
    for(j=0; j<n2; j++){
        R[j] = a[m+1+j];
    }
    
    i = 0;
    j = 0;
    k = l;
    
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
    
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

int main() {
    mergeSort(0, n-1);
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
