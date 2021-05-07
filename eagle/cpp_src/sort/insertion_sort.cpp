#include "my_print.hpp"

template <typename T>
void insertion_sort(std::vector<T> &arr){
    for(int i = 1; i < arr.size(); i++){
        T temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;        
    }
}

template <typename T>
void binary_insert_sort(std::vector<T> &arr){
    for(int i = 1; i < arr.size(); i++ ){
        
        T temp = arr[i];
        int low = 0, high = i - 1, m = 0;

        if(temp >= arr[i - 1]){
            continue;
        }

        while (low <= high){
            m = (low + high) / 2;
            if(arr[m] > temp){
                high = m -1;
            }else{
                low = m + 1;
            }
        }

        int j = i - 1;
        while (j >= high+1){
            arr[j+1] = arr[j]; 
            j--;
        } 
        arr[j+1] = temp;       
    }
    
}


int main(int argc, char const *argv[])
{
    std::cout << "--insertion_sort--" << std::endl;
    
    std::vector<int> arr1 = {2, 4, 5, 3, 1};
    
    my_print(arr1);

    binary_insert_sort(arr1);

    my_print(arr1);
    
    std::cout << "--binary_insert_sort--" << std::endl;
    std::vector<int> arr2 = {2, 4, 5, 3, 1};
    
    my_print(arr2);

    binary_insert_sort(arr2);

    my_print(arr2);

    return 0;
}
