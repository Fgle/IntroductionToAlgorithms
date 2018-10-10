#include <iostream>
#include <fstream>
#include <iterator>
#include "Chapter2/Chapter2.h"

void Print(int*);
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
    Print(test);
    MergeIfSort(test,0,MaxSize-1);
    Print(test);
//    std::bitset<MaxSize> a(10);
//    std::bitset<MaxSize> b(30);
//    std::bitset<MaxSize + 1> c;
//    std::cout << a << std::endl;
//    std::cout << b << std::endl;
//    Chapter2_1_4(a, b, c);
//    std::cout << c << std::endl;
//    return 0;
}
void Print(int *A){
    for (int i = 0; i < MaxSize; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}