#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"
//#define ldebug printf ("\t%d %s %d %d @%d\n", __LINE__,__FUNCTION__,i,j,pivot)
#define ldebug

int print_data(int *array,  int size)
{
    int sorted = 1;
    int last_val = 0;
    if(size <= 0)
        return sorted;
    last_val = array[0];
    for (size_t i = 0; i < size; i++)
    {
        if(array[i] < last_val)
            sorted = 0;

        printf("%4d ", array[i]);
        if (i % 16 == 15)
        {
            printf("\n");
        }
        last_val = array[i];
    }
    printf("\n");
    return sorted;
}

void quick_sort(int array[], int left, int right)
{
    int i,j;
    i = left;  //第一个数据的位置
    j = right; //数组最后一个数据的位置
    int temp; //互换位置的中间变量
    int pivot = 0;
    int pivot_idx = (left + right)/2;

    if(left >= right)
        return ;

    pivot = array[pivot_idx]; //基准点的位置

//    ldebug("(%d %d) @%d\n",left,right,pivot);

    while (i <= j)
    {
        while ((array[i] <= pivot) && (i <= j))
        {
            i++;
        }

        while ((array[j] > pivot) && (i <= j))
        {
            j--;
        }

        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            ldebug("swap %d(@%d) <->%d(@%d)\n",array[i],i,array[j],j);
        }
    }

    if(i > j)
        i--;

    //getchar();
    //ldebug;

    // 0 - i-j -right
    int split_left_pos = i;
    int split_right_pos = i+1;

    ldebug("sub split:(%d %d) (%d %d)@%d\n",left, split_left_pos, split_right_pos,right,pivot);

    if(split_left_pos >= right){
        temp = array[right];
        array[right] = array[pivot_idx];
        array[pivot_idx] = temp;
        split_left_pos--;
        ldebug("swap2 %d(@%d) <->%d(@%d)\n",array[pivot_idx],pivot_idx,array[right],right);
    }

    //print_data(array, 8);
    if ( split_right_pos < right)
    {
        ldebug("sub split1:%d %d\n",split_right_pos,right);
        quick_sort(array, split_right_pos, right);
    }

    if (left < split_left_pos)
    {
        ldebug("sub split2:%d %d\n",left, split_left_pos);
        quick_sort(array, left, split_left_pos);
    }

    //print_data(array, 7);
    //getchar();
}

int generate_data(int array[], int size, int max_value)
{
    srand (time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand () % (max_value + 1);

    }
    return 0;
}
