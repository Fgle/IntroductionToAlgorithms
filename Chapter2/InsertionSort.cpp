//
// Created by fgle on 18-10-9.
//

#include "InsertionSort.h"

void InsertionSort(int *A, int length){
    for (int i = 1; i < length; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[i] > key){
            A[j + 1] = A[i];
            j++;
        }
        A[j] = key;
    }
}
