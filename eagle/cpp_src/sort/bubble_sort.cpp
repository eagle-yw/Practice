#include "my_print.hpp"

template <typename T>
void bubble_sort(std::vector<T> &arr){

    for(int i=0; i<arr.size()-1; i++){
        bool flag = true;
        for(int j = 0; j < arr.size()-i-1; j++){
            if(arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if(flag){
            break;
        }
    }
}

int main(int argc, char* argv[]){

    std::cout << "--bubble_sort--" << std::endl;
    
    std::vector<int> arr = {2, 4, 5, 3, 1};
    
    my_print(arr);

    bubble_sort(arr);

    my_print(arr);
    
    return 0;
}