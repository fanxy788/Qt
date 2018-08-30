/**
 * @brief 快速排序
 * 
 * @file qsort.c
 * @author leon@gaoee.com
 * @date 2018-04-06
 */
#include "qsort.h"
#include "debug.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 生成随机数据
 * 
 * @param array 
 * @param size 
 * @param max_value 
 */
void generate_data(int *array, unsigned int size, int max_value)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand() % max_value;
    }
}

/**
 * @brief 打印数据
 * 
 * @param array 
 * @param size 
 */
int print_data(int *array, unsigned int size)
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

/**
 * @brief 交换元素
 * 
 * @param array 
 * @param a 
 * @param b 
 */
void quick_sort_swap(int* array, unsigned int a, unsigned int b){
    int temp = array[a];
    
    if(a == b)
        return ;

    debug_printf("swap %d<->%d\n",a,b);
    array[a] = array[b];
    array[b] = temp;
}

/**
 * @brief 分割并区域排序
 * 
 * @param array 
 * @param left 
 * @param right 
 * @return int 
 */
int quick_sort_partition(int *array, unsigned int left, unsigned int right)
{
    debug_printf("split:%d,%d\n", left, right);

    if (left >= right-1)
        return right;

    int cmp_value = array[left];
    int split_pos = left+1;

    for (unsigned int i = left+1; i < right; i++)
    {
        if (array[i] <= cmp_value)
        {
            if(split_pos != i){
                quick_sort_swap(array, i, split_pos);
            }
            split_pos++;
            debug_printf("pos-> %d\n", split_pos);
        }
    }

    quick_sort_swap(array, left, split_pos-1);
    
    // 左边划走了全部元素，则强制右边划走1个元素
    if(split_pos >= right){
        split_pos --;
    }

    return split_pos;
}

/**
 * @brief 快速排序主函数
 * 
 * @param array 
 * @param left 
 * @param right 
 */
void quick_sort(int *array, unsigned int left, unsigned int right)
{
    unsigned int split_pos = left;

    if (split_pos >= right - 1)
    {
        debug_printf("split:%d,%d,%d\n", left, split_pos, right);
        return;
    }

    split_pos = quick_sort_partition(array, left, right);

    quick_sort(array, left, split_pos);
    quick_sort(array, split_pos, right);

    return;
}
