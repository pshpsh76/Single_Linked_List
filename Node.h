#ifndef SINGLE_LINKED_LIST_NODE_H
#define SINGLE_LINKED_LIST_NODE_H

template<typename T>

class Node {
public:
    T val;
    Node<T>* next;
    Node(T _val) {
        val = _val;
        next = nullptr;
    }
    Node() {
        next = nullptr;
        val = nullptr;
    }
};

#endif //SINGLE_LINKED_LIST_NODE_H
