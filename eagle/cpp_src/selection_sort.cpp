#include "my_print.hpp"

template<typename T>
void selection_sort(std::vector<T> &arr){  //通过引用的方式把外部 arr的地址传进来
    
    for(int i = 0; i < arr.size()-1; i++){ //i 记录无序区的起始位置
        int min = i;
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[j] < arr[min]){ 
                min = j;   //遍历无序区找到最小值的下标
            }
        }
        std::swap(arr[i], arr[min]); 
    }
}


int main(int argc, char* argv[]){
    std::cout << "--selection_sort--" << std::endl;
    

    std::vector<int> arr = {2, 4, 5, 3, 1}; 
    

    my_print(arr);
    
    selection_sort(arr);
    
    my_print(arr);

    return 0;
}