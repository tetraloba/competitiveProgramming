#include <stdlib.h>
int funcCmp(const void*, const void*);

qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), funcCmp);

int funcCmp(const void *n1, const void *n2){
    if (*(int*)n1 < *(int*)n2){
        return -1;
    }else if (*(int*)n2 < *(int*)n1){
        return 1;
    }else{
        return 0;
    }
}