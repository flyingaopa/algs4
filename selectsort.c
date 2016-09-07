/* in iteration i, find index min of smallest remaining entry
 * then swap a[i] and a[min]
 */

void select_sort(int *array, int len)
{
    int i,j;
    int min, tmp;

    if( array == NULL || len <= 0 ) return;

    for( i = 0; i < len; i++ )
    {
        min = i;
        for( j = i + 1, j < len; j++ )
        {
            if( array[j] < array[min] )
                min = j;
        }

        tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
    return;
}
