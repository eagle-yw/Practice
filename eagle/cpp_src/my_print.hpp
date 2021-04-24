#include <iostream>
#include <vector>

template<typename T>
static void my_print(std::vector<T> &arr){
    for(auto i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}