#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "quicksort.h"

int _passed_count = 0;

void qsort_test1(){
    const int size = 7;
    int array[7] = {4,1,3,6,7,2,9};
    int sorted = 0;
    printf("######## %s\n",__FUNCTION__);
    print_data(array, size);
    quick_sort(array, 0, size-1);
    sorted = print_data(array,size);
    printf("######## %s [%s]\n\n",__FUNCTION__, sorted? "PASS":"FAIL");
}

void qsort_test2(){
    const int size = 8;
    int array[8] = {363,89,128,260,410,147,89, 301};
    int sorted = 0;
    printf("######## %s\n",__FUNCTION__);
    print_data(array, size);
    quick_sort(array, 0, size-1);
    sorted = print_data(array,size);
    printf("######## %s [%s]\n\n",__FUNCTION__, sorted? "PASS":"FAIL");
}

void qsort_test3(){
    const int size = 128;
    const int max_value = 1024;
    int *array= NULL;
    int sorted = 0;

    array = (int*)malloc(sizeof(int)*size);
    if(!array)
        return ;

    //printf("######## %s\n",__FUNCTION__);
    generate_data(array, size, max_value);

    print_data(array, size);

    //printf ("####\n");
    quick_sort(array, 0, size-1);
    //printf ("####\n");

    sorted = print_data(array,size);
    //printf("######## %s [%s]\n\n",__FUNCTION__, sorted? "PASS":"FAIL");
    if(sorted)
        _passed_count++;
    if(array)
        free(array);
    array = NULL;
}

int main(int argc, char** argv){
    qsort_test1();
    qsort_test2();
    qsort_test2();
//    for(int i = 0; i < 1024; i++){
//            printf(".");
        qsort_test3();
//    }

    printf("\ndone, _passed_count=%d.\n",_passed_count);
}
