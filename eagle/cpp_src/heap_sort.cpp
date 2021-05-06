#include "my_print.hpp"

template <typename T>
void max_heap(std::vector<T> &arr, int start, int end){
    int dad = start;
    int son = dad * 2 + 1;

    while(son <= end){
        if(son + 1 <= end && arr[son] < arr[son+1]){
            son++;
        }
        if(arr[dad] > arr[son]){
            return;
        }else{
            std::swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }

}

template <typename T>
void heap_sort(std::vector<T> &arr){
    for(int i = arr.size() / 2 - 1; i >= 0; i--){
        max_heap(arr, i, arr.size() - 1);
    }
    
    for(int i = arr.size() - 1; i > 0; i--){
        std::swap(arr[0], arr[i]);
        max_heap(arr, 0, i - 1);
    }
}


int main(int argc, char* argv[]){

    std::cout << "--heap_sort--" << std::endl;
    
    std::vector<int> arr = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 }; 
    
    my_print(arr);
    
    heap_sort(arr);
    
    my_print(arr);

    return 0;
}