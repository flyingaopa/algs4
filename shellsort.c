#include <stdio.h>

void logout(int * array, int len)
{
    int i;
    for( i = 0; i < len; i++ )
        printf("%6d ", array[i]);
    printf("\n");
}

void shell_sort(int * array, int len)
{
    int i,j,step;
    int tmp;

    step = 1;
    while( step < len/3 ) step = 3*step + 1;

    while( step >= 1 )
    {
        printf("step = %u\n", step);
        for( i = step; i < len; i ++ )
        {
		    for( j = i; j >= step; j -= step )
		    {
		        if( array[j] < array[j - step] )
		        {
		            tmp = array[j - step];
		            array[j - step] = array[j];
		            array[j] = tmp;
		        }
		        else
		            break;
		    }
            logout(array, len);
        }
        step = step/3;
    }
    return;
}

int main(int argc, char *argv[])
{
    int ar[] = {435,46,5,6345,254,52,7456,2342,3657,4546,34642,352,62,43,453};
    logout(ar, sizeof(ar)/sizeof(int));
    shell_sort(ar, sizeof(ar)/sizeof(int));
//    logout(ar, sizeof(ar)/sizeof(int));
    return 0;
}

