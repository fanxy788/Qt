#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BubbleSort.h"

void BubbleSort_test ()
{
    int sorted = 0;
    int array[] = {5, 1, 3, 5, 6, 2, 4, 0};
    int size = sizeof(array) / sizeof(array[0]);
    PrintData (array, size);
//    BubbleSort (array, size);
    CocktailSort (array, size);
    printf ("\n#########\n");
    sorted = PrintData (array, size);

    printf ("\n##### %s  [%s]\n", __FUNCTION__, sorted ? "PASS" : "FAIL");
}

void Sort_test2 ()
{
    int sorted = 0;
    int size = 4;
    int MAX = 9;

    int * array = NULL;
    array = (int *)malloc (sizeof (int) * size);
    GenerateDate (array, size, MAX);
    PrintData (array, size);
//    BubbleSort (array, size);
//    CocktailSort (array, size);
//    SelectionSort (array, size);
//    InsertionSort(array, size);
    QuickSort (array, 0, size-1);
    printf ("\n#########\n");
    sorted = PrintData (array, size);

    printf ("\n##### %s  [%s]", __FUNCTION__, sorted ? "PASS" : "FAIL");
    if (!array)
        free(array);
    array = NULL;
}

int main()
{
    Sort_test2();
    return 0;
}
