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
    C.reset();  //初始化C
    for (std::size_t i = 0; i < MaxSize; i++) {
        if(A[i] & B[i] || A[i] & C[i] || B[i] & C[i]) //进位标志
            C.set(i + 1);
        C[i] = A[i] ^ B[i] ^ C[i];  //按位加
    }
}

void Merge(int *A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[n1 + 1];       //q前面的数
    int right[n2 + 1];      //q后面的数
    int i, j;
    for (i = 0; i < n1; i++)
        left[i] = A[p + i];
    for (i = 0; i < n2; i++)
        right[i] = A[q + i + 1];
    left[n1] = INT_MAX;     //哨兵, 去除越界判断语句
    right[n2] = INT_MAX;
    i = j =0;
    for (int k = p; k <= r; k++) {
        if(left[i] < right[j]){
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
    }
}
void MergeSort(int *A, int p, int r){
    if(p < r){
        int q = (p + r)/2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

void MergeIf(int *A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[n1];       //q前面的数
    int right[n2];      //q后面的数
    int i, j, k;
    for (i = 0; i < n1; i++)
        left[i] = A[p + i];
    for (i = 0; i < n2; i++)
        right[i] = A[q + i + 1];
    i = j =0;
    for (k = p; k <= r; k++) {
        if(i == n1 || j == n2)
            break;
        if(left[i] < right[j]){
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
    }
    while (i < n1)
        A[k++] = left[i++];
    while (j < n2)
        A[k++] = right[j++];
}
void MergeIfSort(int *A, int p, int r){
    if(p < r){
        int q = (p + r)/2;
        MergeIfSort(A, p, q);
        MergeIfSort(A, q + 1, r);
        MergeIf(A, p, q, r);
    }
}