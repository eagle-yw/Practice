#include "my_print.hpp"

template <typename T>
void quick_sort(std::vector<T> &arr, int left, int right){

    if(left >= right){
        return;
    }
    //arr[left] ~ arr[right] ---> arr[left] ~ min ~ arr[right]
    int l = left, r = right; 
    int mid = arr[l]; //挖坑填数，从最左边开始挖

    while (l < r){
        //这里 l 标记坑的位置，利用r找到比mid 小的数
        while (l < r && arr[r] > mid){
            r--;
        }
        if(l < r){
            arr[l] = arr[r];
            l++;
        }
        //这里 r 标记坑的位置，利用l找到比mid 小的数
        while (l < r && arr[l] < mid){
            l++;
        }
        if(l < r){ 
            arr[r] = arr[l];
            r--;
        }        
    }
    arr[l] = mid;

    quick_sort(arr, left, l-1);
    quick_sort(arr, l+1, right);
}



int main(int argc, char const *argv[])
{
    std::cout << "--quick_sort--" << std::endl;
    
    std::vector<int> arr = {2, 4, 5, 3, 1}; 
    
    my_print(arr);
    
    quick_sort(arr, 0, arr.size()-1);
    
    my_print(arr);

    return 0;
}