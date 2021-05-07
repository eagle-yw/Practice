#include <iostream>
#include <vector>
#include <functional>


template <typename T>
void preorder_traversal(std::vector<T> &binary_tree, int curr_index, std::function<void(T curr)> func){
    if(binary_tree.size() == 0 || func == nullptr){
        return;
    }
    
    func(binary_tree[curr_index]);
    
    int l_son = curr_index * 2 + 1;
    if(l_son < binary_tree.size()){
        preorder_traversal(binary_tree, l_son, func);
    }

    int r_son = curr_index * 2 + 2;
    if(r_son < binary_tree.size()){
        preorder_traversal(binary_tree, r_son, func);
    }
}


int main(int argc, char* argv[]){

    std::vector<int> binary_tree = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 }; 

    preorder_traversal(binary_tree, 0, (std::function<void(int)>)[](int curr){
        std::cout << curr << " ";
    });

    std::cout << std::endl;
    return 0;
}