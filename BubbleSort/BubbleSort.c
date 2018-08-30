#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BubbleSort.h"

/**
 * @brief 交换元素
 *
 * @param array
 * @param i
 * @param j
 */

void Swap (int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * @brief 冒泡排序
 *
 * @param array
 * @param size
 */

void BubbleSort (int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                Swap (array, j, j+1);
            }
        }
    }
}

/**
 * @brief 打印数据
 *
 * @param array
 * @param size
 */
int PrintData (int array[], int size)
{
    int sorted = 1;
    int last_val;
    if (size <= 0)
        return sorted;

    last_val = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < last_val)
            sorted = 0;

        printf ("%4d ", array[i]);
        if (i % 16 == 15)
        {
            printf ("\n");
        }
        last_val = array[i];
    }
    printf ("\n");
    return sorted;
}

void GenerateDate (int * array, int size, int MAX)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % MAX;
    }
}

/**
 * @brief 鸡尾酒排序
 *
 * @param array
 * @param size
 */

void CocktailSort (int array[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (array[i] > array[i+1])
            {
                Swap(array, i, i+1);
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (array[i-1] > array[i])
            {
                Swap(array, i-1, i);
            }
        }
        left++;
    }

}

/**
 * @brief 选择排序
 *
 * @param array
 * @param size
 */

void SelectionSort (int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        if (min != i)
        {
            Swap(array, i, min);
        }
    }
}



//void InsertionSort(int array[], int size)
//{
//    for (int i = 1; i < size; i++)         // 类似抓扑克牌排序
//    {
//        int get = array[i];                 // 右手抓到一张扑克牌
//        int j = i - 1;                  // 拿在左手上的牌总是排序好的
//        while (j >= 0 && array[j] > get)    // 将抓到的牌与手牌从右向左进行比较
//        {
//            array[j + 1] = array[j];            // 如果该手牌比抓到的牌大，就将其右移
//            j--;
//        }
//array[j+1] = get;
//    }
//
//}

void InsertionSort(int array[], int size)//n为数组a的元素个数

{
    //进行N-1轮插入过程
    for(int i=1; i<size; i++)
    {
        //首先找到元素a[i]需要插入的位置
        int j=0;
        while( (array[j]<array[i]) && (j<i))
        {
            j++;
        }
        //将元素插入到正确的位置
        if(i != j)  //如果i==j，说明a[i]刚好在正确的位置
        {
            int temp = array[i];
            for(int k = i; k > j; k--)
            {
                array[k] = array[k-1];
            }
            array[j] = temp;
        }
    }
}

/**
 * @brief 快速排序
 *
 * @param array
 * @param size
 */

//int Partition(int array[], int first, int end)
//{
//
//    int i,j;
//
//    i = first;
//    j = end;
//
//    while (i < j)
//    {
//        //进行右侧扫描
//        while (i < j&&array[i] < array[j])
//            j--;
//        if (i < j)
//        {
//            Swap (array, i, j);
//            i++;
//        }
//        //进行左侧扫描
//        while (i < j&&array[i] <= array[j])
//            i++;
//        if (i < j)
//        {
//            Swap (array, i, j);
//            j--;
//        }
//    }
//
//    return i;
//}
//
////快速排序算法，递归调用
//void QuickSort(int array[], int first, int end)
//{
//    int pivot;
//    if (first < end)
//    {
//        pivot = Partition(array, first, end);
//
//        QuickSort(array, first, pivot - 1);
//        QuickSort(array, pivot + 1, end);
//    }
//}


void QuickSort(int array[], int left, int right)
{
    int mediakry = array[left];
    int i = left;
    int j = right;
    int n = 0;
    if (left >= right)
        return;
    while (i < j)
    {
        while (i < j && array[j] >= mediakry)
        {
            j--;
        }
        array[i] = array[j];
        while (i < j && array[i] <= mediakry)
        {
            i++;
        }
        array[j] = array[i];
    }
    array[i] = mediakry;
    QuickSort(array, left, i-1);
    QuickSort(array, i+1, right);
}
