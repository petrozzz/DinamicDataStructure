#ifndef BYNARYTREE_H
#define BYNARYTREE_H
#include <iostream>
using namespace std;

template <typename T>
struct NodeBT{
    T id;
    NodeBT<T>* left = nullptr;
    NodeBT<T>* right = nullptr;
    NodeBT<T>* parent = nullptr;
};

template <typename T>
class BynaryTree{
    NodeBT<T>* root = nullptr;
    int size = 0;
    void create(T data){
        NodeBT<T> *node = new NodeBT<T>{data};
        root = node;
    }
public:
    BynaryTree() {}
    BynaryTree(T data){
        create(data);
        size++;
    }

    void add(T data){
        if(!size){
            create(data);
        } else {
            NodeBT<T>* iter = root;
            NodeBT<T>* node = new NodeBT<T>{data};
            while(true){
                if(node->id > iter->id){
                    if(iter->right == nullptr){
                        node->parent = iter;
                        iter->right = node;
                        break;
                    } else
                        iter = iter->right;
                } else {
                    if(iter->left == nullptr){
                        node->parent = iter;
                        iter->left = node;
                        break;
                    } else
                        iter = iter->left;
                }
            }
        }
        size++;
    }

    void remove(T data){
        NodeBT<T>* node = search(data);
        if(node != nullptr){
            if(node->left == nullptr && node->right == nullptr){
                if(node->parent->left == node)
                    node->parent->left = nullptr;
                else
                    node->parent->right = nullptr;
            } else if (node->left == nullptr) {
                if(node->parent->left == node)
                    node->parent->left = node->right;
                else
                    node->parent->right = node->right;
            } else if (node->right == nullptr) {
                if(node->parent->left == node)
                    node->parent->left = node->left;
                else
                    node->parent->right = node->left;
            } else {
                if(node == root) {
                    NodeBT<T>* iter = node->right;
                    while(iter->left != nullptr){
                        iter = iter->left;
                    }
                    NodeBT<T>* tmp = node;
                    node = iter;
                    if(node->left == nullptr && node->right == nullptr)
                        node->parent->left = nullptr;
                    else if (node->left == nullptr)
                        node->parent->right = node->right;
                    node->left = tmp->left;
                    node->right = tmp->right;
                    node->left->parent = node;
                    node->right->parent = node;
                    node->parent = nullptr;
                    root = node;
                    delete tmp;
                } else if(node->id < node->parent->id) {
                    NodeBT<T>* iter = node->right;
                    while(iter->left != nullptr){
                        iter = iter->left;
                    }
                    NodeBT<T>* tmp = node;
                    node = iter;
                    if(node->left == nullptr && node->right == nullptr)
                        node->parent->left = nullptr;
                    else
                        node->parent->left = node->right;
                    node->parent = tmp->parent;
                    node->left = tmp->left;
                    node->right = tmp->right;
                    node->parent->left = node;
                    node->left->parent = node;
                    node->right->parent = node;
                    delete tmp;
                } else {
                    NodeBT<T>* iter = node->right;
                    while(iter->right != nullptr){
                        iter = iter->right;
                    }
                    NodeBT<T>* tmp = node;
                    node = iter;
                    if(node->left == nullptr && node->right == nullptr)
                        node->parent->right = nullptr;
                    else
                        node->parent->right = node->left;
                    node->parent = tmp->parent;
                    node->left = tmp->left;
                    node->right = tmp->right;
                    node->parent->right = node;
                    node->left->parent = node;
                    node->right->parent = node;
                    delete tmp;
                }
            }
            size--;
        }

    }

    NodeBT<T>* search(T data){
        NodeBT<T>* iter = root;
        while(true){
            if(data == iter->id)
                return iter;
            else if (data > iter->id){
                if(iter->right == nullptr)
                    return nullptr;
                else
                    iter = iter->right;
            } else {
                if(iter->left == nullptr)
                    return nullptr;
                else
                    iter = iter->left;
            }
        }
        return nullptr;
    }

    void print(NodeBT<T>* node = nullptr){
        if(node == nullptr)
            node = root;
        cout << node->id << " ";
        if(node->left != nullptr){
            print(node->left);
        }
        if(node->right != nullptr){
            print(node->right);
        }
    }
};

void testBynaryTree(){
    std::cout << "Strat testBynaryTree" << std::endl;
    BynaryTree<double> tree(10);
    tree.add(8);
    tree.add(6);
    tree.add(12);
    tree.add(11);
    tree.add(11.5);
    tree.add(14);
    tree.add(13);
    tree.add(20);
    tree.add(24);
    tree.add(19);
    tree.add(18);
    tree.add(19.5);
    tree.print();
    cout << endl;
    tree.remove(12);
    tree.print();
    cout << endl;
    std::cout << "end testBynaryTree" << std::endl;
}


#endif // BYNARYTREE_H
