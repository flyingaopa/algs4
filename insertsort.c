#include <stdio.h>

void logout(int * array, int len)
{
    int i;
    for( i = 0; i < len; i++ )
        printf("%6d ", array[i]);
    printf("\n");
}


void insert_sort(int *array, int len)
{
    int i,j;
    int tmp;

    if( array == NULL || len <= 0 ) return;

    for( i = 0; i < len; i++ )
    {
        for( j = i; j > 0; j-- )
        {
            if( array[j] < array[j - 1] )
            {
                tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
            else
                break;
        }
        logout(array, len);
    }
    return;
}

int main(int argc, char *argv[])
{
    int ar[] = {435,46,5,6345,254,52,7456,2342,3657,4546,34642,352,62,4643,453};
    logout(ar, sizeof(ar)/sizeof(int));
    insert_sort(ar, sizeof(ar)/sizeof(int));
    return 0;
}


