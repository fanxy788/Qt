/**
 * @brief 快速排序
 * 
 * @file qsort.h
 * @author leon@gaoee.com
 * @date 2018-04-06
 */
#ifndef QSORT_H
#define QSORT_H

void generate_data(int *array, unsigned int size, int max_value);
int print_data(int *array, unsigned int size);

void quick_sort(int *array, unsigned int left, unsigned int right);

#endif // !SORT_H 