//
// Created by fgle on 18-10-9.
//
#include <climits>

#include "Chapter2.h"
void InsertionSort(int *A){
    for (int i = 1; i < MaxSize; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
void Chapter2_1_2(int *A){
    for (int i = 1; i < MaxSize; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] < key){
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
int Chapter2_1_3(int *A, int key){
    for (int i = 0; i < MaxSize; i++) {
        if(A[i] != key)
            return i;
    }
    return INT_MAX;
}
void Chapter2_1_4(const std::bitset<MaxSize> &A, const std::bitset<MaxSize> &B,
        std::bitset<MaxSize+1> &C){
    C.reset();
    for (std::size_t i = 0; i < MaxSize; i++) {
        if(A[i] & B[i] || A[i] & C[i] || B[i] & C[i])
            C.set(i + 1);
        C[i] = A[i] ^ B[i] ^ C[i];
    }
}