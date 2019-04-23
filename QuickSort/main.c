#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) do { int tmp = a; a = b; b = tmp; } while (0)

int partition(int* tab, int left, int right) {
    int x = tab[right];
    int i;
    i=left-1;
    for(int j=left; j<right; j++)
    {
        if(tab[j]<x)
        {
            i++;
            SWAP(tab[i],tab[j]);
        }
    }
    SWAP(tab[right], tab[i+1]);
    return i+1;
}

void quickSort(int tab[], int left, int right) {
    if(left<right)
    {
        int q = partition(tab,left,right);
        quickSort(tab,left,q-1);
        quickSort(tab,q+1,right);
    }
}

int main() {
    int Z;

    scanf("%d", &Z);

    int val;

    while (Z--) {

        int n;
        scanf("%d", &n);
        int *tab = malloc(n*sizeof(n));
        for(int i=0; i<n; i++) {
            scanf("%d", &tab[i]);
        }

        quickSort(tab, 0, n-1);
        for(int i=0; i<n; i++) {
            printf("%d\n", tab[i]);
        }
        free(tab);
    }
}
