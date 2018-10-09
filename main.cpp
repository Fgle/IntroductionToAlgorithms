#include <iostream>
#include <fstream>
#include <iterator>
#include "Chapter2/Chapter2.h"
#define MaxSize 6
void Print(int *A, int length);
int main(int argc, char *argv[]) {
    std::ifstream input("/home/fgle/Programs/Algorithm/DataStructures/IntrodutionToAlgorithms/Chapter2/test");
    if(!input.is_open()){
        std::cout << "文件未打开！" << std::endl;
        return -1;
    }

    std::istream_iterator<int> iter(input);

    int test[MaxSize];
    for (auto &item : test) {
        item = *iter++;
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