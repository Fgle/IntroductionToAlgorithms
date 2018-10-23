#include <iostream>
#include <fstream>
#include <iterator>
#include "Chapter4/Chapter4.h"

void Print(int*, int);
int main(int argc, char *argv[]) {
    std::ifstream input("/home/fgle/Programs/Algorithm/DataStructures/IntrodutionToAlgorithms/Chapter4/test");
    if(!input.is_open()){
        std::cout << "文件未打开！" << std::endl;
        return -1;
    }

    std::istream_iterator<int> iter(input);

    int test[MaxSize];
    int result[3];
    for (auto &item : test) {
        item = *iter++;
    }
    Find_maximum_subarray(test, 0, MaxSize-1, result);
    Print(result, 3);
    Chapter4_1_5(test, result);
    Print(result, 3);

}
void Print(int *A, int size){
    for (int i = 0; i < size; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}