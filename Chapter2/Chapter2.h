//
// Created by fgle on 18-10-9.
//

#ifndef INTRODUTIONTOALGORITHMS_CHAPTER2_H
#define INTRODUTIONTOALGORITHMS_CHAPTER2_H
#include <bitset>
#define MaxSize 6
/***InsertionSort***/
void InsertionSort(int*);
/***2.1-2***/
void Chapter2_1_2(int*);
/***2.1_3****/
int Chapter2_1_3(int*, int);
/***2.1_4***/
void Chapter2_1_4(const std::bitset<MaxSize>&, const std::bitset<MaxSize>&, std::bitset<MaxSize+1>&);
/***MergeSort***/
void Merge(int*, int, int, int);
void MergeSort(int*, int, int);
/***2.3-2***/
void MergeIf(int*, int, int, int);
void MergeIfSort(int*, int, int);
#endif //INTRODUTIONTOALGORITHMS_CHAPTER2_H
