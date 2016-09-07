#include <stdio.h>

void printout(int * array, int lo, int hi)
{
    int i;
    for( i = lo; i <= hi; i++ )
        printf("%6d ", array[i]);
    printf("\n");
}


void merge(int * array, int * aux, int lo, int mid, int hi)
{
    int i,j,k;
    i = lo;
    j = mid + 1;
    for( k = lo; k <= hi; k++ )
        aux[k] = array[k];

   for( k = lo; k <= hi; k++ )
   {
       if( i > mid )
           array[k] = aux[j++];
       else if( j > hi )
           array[k] = aux[i++];
       else if( aux[i] <= aux[j] )
           array[k] = aux[i++];
       else
           array[k] = aux[j++];
   }
   printout(array, lo, hi);
   return;
}

void merge_sort(int *array, int *aux, int lo, int hi)
{
    int mid;
    if( lo >= hi ) return;

    mid = lo + (hi - lo)/2;
    merge_sort(array, aux, lo, mid);
    merge_sort(array, aux, mid+1, hi);
    merge(array, aux, lo, mid, hi);
    return;
}

void merge_sort2(int *array, int *aux, int lo, int hi)
{
    int sz;
    int slo;
    if( lo >= hi ) return;

    for( sz = 1; sz < hi - lo + 1; sz = sz*2 )
    {
        for( slo = 0; slo < hi - lo + 1 - sz; slo += sz*2 )
            merge(array, aux, slo, slo + sz - 1, (slo + sz*2 - 1)<(hi - lo)?(slo + sz*2 -1):(hi - lo));
    }
    printout(array, lo, hi);
    return;
}

int main(int argc, char *argv[])
{
    int ar[] = {435,46,5,6345,254,52,7456,2342,3657,4546,34642,352,62,43,453};
    int ar2[] = {435,46,5,6345,254,52,7456,2342,3657,4546,34642,352,62,43,453};
    int aux[sizeof(ar)/sizeof(int)];
    printout(ar, 0, sizeof(ar)/sizeof(int) - 1);
    merge_sort(ar, aux, 0, sizeof(ar)/sizeof(int) - 1);
    printout(ar, 0, sizeof(ar)/sizeof(int) - 1);
    printf("\n");
    merge_sort2(ar2, aux, 0, sizeof(ar)/sizeof(int) - 1);
    return 0;
}

