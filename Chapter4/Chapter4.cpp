//
// leftreateright by fgle on 18-10-18.
//

#include <climits>
#include "Chapter4.h"

void Find_max_crossing_subarray(int *A, int low, int mid, int high, int *B){
    int left_sum = INT_MIN;
    int max_left = mid;
    int sum = 0;
    int right_sum = INT_MIN;
    int max_right = mid;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    B[0] = max_left;
    B[1] = max_right;
    B[2] = right_sum + left_sum;
}
void Find_maximum_subarray(int *A, int low, int high, int *B){
    int left[3] = {0};
    int right[3] = {0};
    if(low == high){
        B[0] = low;
        B[1] = high;
        B[2] = A[low];
    } else {
        int mid = (low + high) / 2;

        Find_maximum_subarray(A, low, mid, left);
        Find_maximum_subarray(A, mid + 1, high, right);
        Find_max_crossing_subarray(A, low, mid, high, B);
        if (left[2] >= right[2] && left[2] >= B[2])
            for (int i = 0; i < 3; i++)
                B[i] = left[i];
        if (right[2] >= left[2] && right[2] >= B[2])
            for (int j = 0; j < 3; j++)
                B[j] = right[j];
    }
}
/***
 * 如果[begin...end]是[0...i-1]的子数组,则[0...i]的最大子数组为：
 * (1): [begin...end]
 * (2): [begin...i]
 * (3): [index...i]
***/
void Chapter4_1_5(int *A, int *B){
    int index = 0;
    int max_sum = A[0];     //最大子数组和
    int index_sum = A[0];   //[index...i]的和
    int negative_sum = 0;   // 负数序列和
    int begin = 0;  //最大子数组的开始下标
    int end = 0;    //最大子数组的结束下标
    for (int i = 1; i < MaxSize; i++) {
         negative_sum = index_sum - A[index];
        if (A[i] < 0) {
            index_sum += A[i];
            continue;
        }
        if(index == end){
            if (negative_sum + A[i] >= 0){   //[begin...i]
                index = i;
                end = index;
                max_sum += negative_sum + A[i];
                index_sum = 0;
            }else if (A[i - 1] < 0 && negative_sum + max_sum < 0) {
                index = i;
                index_sum = 0;
            }
        } else if (negative_sum + A[index] < 0) {
            index = i;
            index_sum = 0;
        } else if (index_sum + A[i] > max_sum) {   //[index...i]
            begin = index;
            index = i;
            end = index;
            max_sum = index_sum + A[i];
            index_sum = 0;
        }
        if (A[i] > max_sum) {    //[index...i]其中index == i
            begin = end = i;
            max_sum = A[i];
            index = i;
            index_sum = 0;
        }
        index_sum += A[i];
    }
    B[0] = begin;
    B[1] = end;
    B[2] = max_sum;
}