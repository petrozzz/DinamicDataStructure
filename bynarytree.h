#ifndef BYNARYTREE_H
#define BYNARYTREE_H
#include <iostream>
using namespace std;

template <typename T>
struct NodeBT{
    T id;
    NodeBT<T>* l = nullptr;
    NodeBT<T>* r = nullptr;
    NodeBT<T>* p = nullptr;
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
    enum State{ BALANCE = 0,  LL = 1, LR = 2, RR = -1, RL = -2, LEFT = 3, RIGHT = -3};

    void getNums(int& res, NodeBT<T> *node = nullptr){
        if(node == nullptr)
            node = root;
        ++res;
        if(node->l != nullptr){
            getNums(res, node->l);
        }
        if(node->r != nullptr){
            getNums(res, node->r);
        }
    }

    State getState(NodeBT<T> *node = nullptr){
        if(node == nullptr)
            node = root;
        int depthR = 0, depthL = 0;
        if(node->r)
            getNums(depthR, node->r);
        if(node->l)
            getNums(depthL, node->l);
        if(abs(depthL - depthR) <= 1)
            return BALANCE;
        else if(depthL == 0 && depthR == 2)
            return (node->r->r)? RR: RL;
        else if (depthL == 2 && depthR == 0)
            return (node->l->l)? LL: LR;
        else
            return (depthL > depthR)? LEFT: RIGHT;
    }

    void performBalancing(NodeBT<T> *node = nullptr){
        if(node == nullptr)
            node = root;
        State state = getState(node);
        if(state){
            NodeBT<T> buff = *node;
            if (state == LL){
                node = buff.l;
                node->r = node->p;
                node->r->p = node;
                node->r->l = nullptr;
                node->p = buff.p;
                if(node->p == nullptr)
                    root = node;
                else
                    node->p->l = node;
            } else if (state == RR){
                node = buff.r;
                node->l = node->p;
                node->l->p = node;
                node->l->r = nullptr;
                node->p = buff.p;
                if(node->p == nullptr)
                    root = node;
                else
                    node->p->r = node;
            } else if (state == LR){
                if(node->p)
                    node->l->r->p = node->p;
                else
                    root = node->l->r;
                node->l->r->p = node->p;
                node->p = node->l->r;
                node->l->r->r = node;
                node->l->p = node->l->r;
                node->l->r->l = node->l;
                node->l->r = nullptr;
                node->l->l = nullptr;
                node->l = nullptr;
            } else if (state == RL){
                if(node->p)
                    node->r->l->p = node->p;
                else
                    root = node->r->l;
                node->r->l->p = node->p;
                node->p = node->r->l;
                node->r->l->l = node;
                node->r->p = node->r->l;
                node->r->l->r = node->r;
                node->r->l = nullptr;
                node->r->r = nullptr;
                node->r = nullptr;
            } else if (state == RIGHT){
                NodeBT<T> *iter = node->r;
                while(iter->l)
                    iter = iter->l;
                iter->p->l = nullptr;
                iter->p = node->p;
                iter->l = node;
                iter->l->p = iter;
                if(iter->r == nullptr){
                    iter->r = node->r;
                    iter->r->p = iter;
                } else {
                    iter->r->r = node->r;
                    iter->r->r->p = iter->r;
                }
                node = iter;
                node->l->r = nullptr;
                if(node->p == nullptr)
                    root = node;
                else
                    node->p->r = node;
            } else {
                NodeBT<T> *iter = node->l;
                while(iter->r)
                    iter = iter->r;
                iter->p->r = nullptr;
                iter->p = node->p;
                iter->r = node;
                iter->r->p = iter;
                if(iter->l == nullptr){
                    iter->l = node->l;
                    iter->l->p = iter;
                } else {
                    iter->l->l = node->l;
                    iter->l->l->p = iter->l;
                }
                node = iter;
                node->r->l = nullptr;
                if(node->p == nullptr)
                    root = node;
                else
                    node->p->l = node;
            }
        }
    }

    void balance(NodeBT<T>* node = nullptr){
        if(node == nullptr){
            node = root;
        }
        if(getState(node)){
            performBalancing(node);
            node = root;
        }
        if(node->l != nullptr){
            balance(node->l);
        }
        if(node->r != nullptr){
            balance(node->r);
        }
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
                    if(iter->r == nullptr){
                        node->p = iter;
                        iter->r = node;
                        break;
                    } else
                        iter = iter->r;
                } else {
                    if(iter->l == nullptr){
                        node->p = iter;
                        iter->l = node;
                        break;
                    } else
                        iter = iter->l;
                }
            }
        }
        size++;
        balance();
    }

    void remove(T data){
        NodeBT<T>* node = search(data);
        if(node != nullptr){
            if(node->l == nullptr && node->r == nullptr){
                if(node->p->l == node)
                    node->p->l = nullptr;
                else
                    node->p->r = nullptr;
            } else if (node->l == nullptr) {
                if(node->p->l == node)
                    node->p->l = node->r;
                else
                    node->p->r = node->r;
            } else if (node->r == nullptr) {
                if(node->p->l == node)
                    node->p->l = node->l;
                else
                    node->p->r = node->l;
            } else {
                if(node == root) {
                    NodeBT<T>* iter = node->r;
                    while(iter->l != nullptr){
                        iter = iter->l;
                    }
                    NodeBT<T>* tmp = node;
                    node = iter;
                    if(node->l == nullptr && node->r == nullptr)
                        node->p->l = nullptr;
                    else if (node->l == nullptr)
                        node->p->r = node->r;
                    node->l = tmp->l;
                    node->r = tmp->r;
                    node->l->p = node;
                    node->r->p = node;
                    node->p = nullptr;
                    root = node;
                    delete tmp;
                } else if(node->id < node->p->id) {
                    NodeBT<T>* iter = node->r;
                    while(iter->l != nullptr){
                        iter = iter->l;
                    }
                    NodeBT<T>* tmp = node;
                    node = iter;
                    if(node->l == nullptr && node->r == nullptr)
                        node->p->l = nullptr;
                    else
                        node->p->l = node->r;
                    node->p = tmp->p;
                    node->l = tmp->l;
                    node->r = tmp->r;
                    node->p->l = node;
                    node->l->p = node;
                    node->r->p = node;
                    delete tmp;
                } else {
                    NodeBT<T>* iter = node->r;
                    while(iter->r != nullptr){
                        iter = iter->r;
                    }
                    NodeBT<T>* tmp = node;
                    node = iter;
                    if(node->l == nullptr && node->r == nullptr)
                        node->p->r = nullptr;
                    else
                        node->p->r = node->l;
                    node->p = tmp->p;
                    node->l = tmp->l;
                    node->r = tmp->r;
                    node->p->r = node;
                    node->l->p = node;
                    node->r->p = node;
                    delete tmp;
                }
            }
            size--;
            balance();
        }

    }

    NodeBT<T>* search(T data){
        NodeBT<T>* iter = root;
        while(true){
            if(data == iter->id)
                return iter;
            else if (data > iter->id){
                if(iter->r == nullptr)
                    return nullptr;
                else
                    iter = iter->r;
            } else {
                if(iter->l == nullptr)
                    return nullptr;
                else
                    iter = iter->l;
            }
        }
        return nullptr;
    }

    void print(NodeBT<T>* node = nullptr){
        if(node == nullptr){
            node = root;
            cout << "size: " << size << "   ";
        }
        cout << node->id << " ";
        if(node->l != nullptr){
            print(node->l);
        }
        if(node->r != nullptr){
            print(node->r);
        }
    }

    void prepare_canva(int canva[], int x = 5, int y = 0, NodeBT<T>* node = nullptr){
        if(node == nullptr){
            node = root;
        }
        canva[10*y + x] = node->id;
        if(node->l != nullptr){
            prepare_canva(canva, x-1, y+1, node->l);
        }
        if(node->r != nullptr){
            prepare_canva(canva, x+2, y+1, node->r);
        }
    }

    void show_canva(int canva[]){
        for(int k = 0; k < 10; k++){
            for(int n = 0; n < 10; n++)
               cout << canva[10*k + n] << "\t";
            cout << endl;
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


void testBynaryTree2(){
    std::cout << "Strat testBynaryTree" << std::endl;
    BynaryTree<double> tree(50);

    tree.add(9);
    tree.add(8);
    tree.print();
    cout << endl;
    tree.add(17);
    tree.add(6);
    tree.print();
    cout << endl;
    tree.add(63);    
    tree.print();
    cout << endl;
    tree.add(81);
    tree.print();
    cout << endl;
    tree.add(19);
    tree.print();
    cout << endl;
    tree.add(24);
    tree.print();
    cout << endl;
    tree.add(28);
    tree.print();
    cout << endl;
    tree.add(18);
    tree.print();
    cout << endl;
    std::cout << "end testBynaryTree" << std::endl;
}


#endif // BYNARYTREE_H
