//
// Created by fgle on 18-10-9.
//
#include <iostream>
#include <fstream>
#include <iterator>
#include "InsertionSort.h"
#define MaxSize 6
void Print(int *A, int length);
int main(int argc, char *argv[]) {
    std::ifstream input("test");
    if(!input.is_open()){
        std::cout << "文件未打开！" << std::endl;
        return -1;
    }

    std::istream_iterator<int> iter(input);

    int test[MaxSize];
    for (auto &item : test) {
        item = *iter++;
    }
    for (const auto &item : test) {
        std::cout << item << " ";
    }
    Print(test, MaxSize);
    InsertionSort(test, MaxSize);
    Print(test, MaxSize);
    return 0;
}
void Print(int *A, int length){
    for (int i = 0; i < length; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}