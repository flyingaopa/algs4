#include <stdio.h>

void printout(int * array, int lo, int hi)
{
    int i;
    for( i = lo; i <= hi; i++ )
        printf("%6d ", array[i]);
    printf("\n");
}

int partition(int *array, int lo, int hi)
{
    int tmp;
    int i = lo + 1;
    int j = hi;
    while(1)
    {
        while( array[i] < array[lo] && i <= hi ) i++;
        while( array[lo] < array[j] && j >= lo ) j--;
        if( i >= j) break;
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
        i++;
        j--;
    }

    tmp = array[lo];
    array[lo] = array[j];
    array[j] = tmp;
    printf("index = %d\n", j);
    printout(array, lo, hi);
    return j;
}


void quick_sort(int *array, int lo, int hi)
{
    int idx;
    if( hi <= lo ) return;
    idx = partition(array, lo, hi);
    quick_sort(array, lo, idx - 1);
    quick_sort(array, idx + 1, hi);
}

int select(int * array, int lo, int hi, int k)
{
    int j;
    int slo = lo, shi = hi;

while( slo < shi )
{
    j = partition(array, slo, shi);
    if( j < k ) slo = j + 1;
    else if( j > k ) shi = j - 1;
    else
    {
        return array[k];
    }
}
    return array[k];
    
}

int main(int argc, char *argv[])
{
    int ar[] = {435,46,5,6345,435,52,7456,2342,3657,4546,435,352,62,4643,453};
    printf("%d\n\n\n",select(ar, 0, sizeof(ar)/sizeof(int) - 1, 0));
    printf("%d\n\n\n",select(ar, 0, sizeof(ar)/sizeof(int) - 1,  sizeof(ar)/sizeof(int) - 1));
    
    printout(ar, 0, sizeof(ar)/sizeof(int) - 1);
    quick_sort(ar, 0, sizeof(ar)/sizeof(int) - 1);
    printout(ar, 0, sizeof(ar)/sizeof(int) - 1);
    return 0;
}
