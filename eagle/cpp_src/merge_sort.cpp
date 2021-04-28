#include "my_print.hpp"




template <typename T>
void merge_sort_recursive(std::vector<T> &arr, std::vector<T> &temp_arr, int start, int end){
    if(start >= end){
        return;
    }

    int mid = (start + end) / 2;
    merge_sort_recursive(arr, temp_arr, start, mid);
    merge_sort_recursive(arr, temp_arr, mid+1, end);
    int l_start = start, r_start = mid + 1;
    int l_end = mid, r_end = end;
    int i = start;
    while (l_start <= l_end && r_start <= r_end){
        temp_arr[i++] = arr[l_start] < arr[r_start] ? arr[l_start++] : arr[r_start++];
    }
    while(l_start <= l_end){
        temp_arr[i++] = arr[l_start++]; 
    }
    while(r_start <= r_end){
        temp_arr[i++] = arr[r_start++]; 
    }
    
    for(i = start; i  <= end; i++){
        arr[i] = temp_arr[i];
    }
}

template <typename T>
void merge_sort(std::vector<T> &arr){

    std::vector<T> temp_arr(arr.size());
    
    merge_sort_recursive(arr, temp_arr, 0, arr.size()-1);
}

template <typename T>
void merge_sort_iteration(std::vector<T> &arr){
    std::vector<T> temp_arr(arr.size());

    for(int i = 1; i < arr.size(); i*=2){
        int l_start = 0, l_end = 0;
        int r_start = 0, r_end = 0;
        for(l_start = 0; l_start < arr.size() - i; l_start = r_end){
            int tmp = l_start;
            l_end   = l_start + i;
            r_start = l_end;
            r_end   = r_start + i < arr.size() ? r_start + i : arr.size();
            int k   = 0;
            
            //std::cout << tmp << std::endl;
            while (l_start < l_end && r_start < r_end){
                temp_arr[k++] = arr[l_start] > arr[r_start] ? arr[l_start++] : arr[r_start++];
            }
            while(l_start < l_end){
                temp_arr[k++] = arr[l_start++]; 
            }
            while(r_start < r_end){
                temp_arr[k++] = arr[r_start++]; 
            }

            for(int j =0; j < k; j++){
                arr[tmp++] = temp_arr[j];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "--shell_sort--" << std::endl;
    
    std::vector<int> arr = {2, 4, 5, 3, 1}; 
    
    my_print(arr);
    
    merge_sort(arr);
    
    my_print(arr);

    merge_sort_iteration(arr);

    my_print(arr);

    return 0;
}
