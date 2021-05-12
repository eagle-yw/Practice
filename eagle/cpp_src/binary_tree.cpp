#include <iostream>
#include <vector>
#include <functional>

//前序遍历
template <typename T>
void preOrderTraversal(std::vector<T> &binary_tree, int curr_index, std::function<void(T curr)> func){
    if(binary_tree.size() == 0 || func == nullptr){
        return;
    }
    
    func(binary_tree[curr_index]);
    
    int l_son = curr_index * 2 + 1;
    if(l_son < binary_tree.size()){
        preOrderTraversal(binary_tree, l_son, func);
    }

    int r_son = curr_index * 2 + 2;
    if(r_son < binary_tree.size()){
        preOrderTraversal(binary_tree, r_son, func);
    }
}

//中序遍历
template <typename T>
void inOrderTraversal(std::vector<T> &binary_tree, int curr_index, std::function<void(T curr)> func){
    if(binary_tree.size() == 0 || func == nullptr){
        return;
    }
    
    int l_son = curr_index * 2 + 1;
    if(l_son < binary_tree.size()){
        inOrderTraversal(binary_tree, l_son, func);
    }

    func(binary_tree[curr_index]);

    int r_son = curr_index * 2 + 2;
    if(r_son < binary_tree.size()){
        inOrderTraversal(binary_tree, r_son, func);
    }
}

//后序遍历
template <typename T>
void postOrderTraversal(std::vector<T> &binary_tree, int curr_index, std::function<void(T curr)> func){
    if(binary_tree.size() == 0 || func == nullptr){
        return;
    }
    
    int l_son = curr_index * 2 + 1;
    if(l_son < binary_tree.size()){
        postOrderTraversal(binary_tree, l_son, func);
    }

    int r_son = curr_index * 2 + 2;
    if(r_son < binary_tree.size()){
        postOrderTraversal(binary_tree, r_son, func);
    }
    
    func(binary_tree[curr_index]);
}



int main(int argc, char* argv[]){

    std::vector<int> binary_tree = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 

    std::function<void(int curr)> print = [](int curr){
        std::cout << curr << " ";
    };
    
    preOrderTraversal(binary_tree, 0, print);
    std::cout << std::endl;
    
    inOrderTraversal(binary_tree, 0, print);
    std::cout << std::endl;

    postOrderTraversal(binary_tree, 0, print);
    std::cout << std::endl;
    
    return 0;
}