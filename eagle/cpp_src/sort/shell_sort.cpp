#include "my_print.hpp"



template <typename T>
void shell_sort(std::vector<T> &arr){
    if(arr.empty()){
        return;
    }
    int gap = arr.size() / 2;
    while(gap > 0){
        for(int i = gap; i < arr.size(); i++){
            if(arr[i] > arr[i - gap]){
                continue;
            }
            T temp = arr[i];
            int j = i - gap;
            while(j >=0 && arr[j] > temp){
                arr[j+gap] = arr[j];
                j -= gap;
            }
            arr[j+gap] = temp;
        }

        gap /= 2;
    }
}


int main(int argc, char* argv[]){

    std::cout << "--shell_sort--" << std::endl;
    
    std::vector<int> arr = {2, 4, 5, 3, 1}; 
    
    my_print(arr);
    
    shell_sort(arr);
    
    my_print(arr);


    return 0;
}