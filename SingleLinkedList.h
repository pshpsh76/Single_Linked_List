//
// Created by pbity on 20.10.2021.
//

#ifndef SINGLE_LINKED_LIST_SINGLELINKEDLIST_H
#define SINGLE_LINKED_LIST_SINGLELINKEDLIST_H

#include "Node.h"

using namespace std;

template<typename T>

class SingleLinkedList {
private:
    Node<T>* begin;
    Node<T>* end;
public:
    SingleLinkedList() {
        begin = nullptr;
        end = nullptr;
    }
    const bool is_empty() const {
        return begin == nullptr;
    }
    void push_front(T val) {
        Node<T>* pnode = new Node<T>(val);
        pnode->next = begin;
        begin = pnode;
    }
    void push_back(T val) {
        Node<T>* pnode = new Node<T>(val);
        if (is_empty()) {
            begin = pnode;
            end = pnode;
        }
        else {
            end->next = pnode;
            end = pnode;
        }
    }
    void insert(int index, T val) {
        if (is_empty()) {
            return;
        }
        Node<T>* prev = begin;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
            if (prev == nullptr) {
                return;
            }
        }
        Node<T>* aft = prev->next;
        Node<T>* pnode = new Node<T>(val);
        pnode->next = aft;
        prev->next = pnode;
    }
    void pop_front() {
        if (is_empty()) {
            return;
        }
        Node<T>* temp = begin;
        begin = begin->next;
        delete temp;
    }
    void pop_back() {
        if (is_empty()) {
            return;
        }
        Node<T>* pnode = begin;
        while (pnode->next != end) {
            pnode = pnode->next;
        }
        Node<T>* temp = end;
        end = pnode;
        end->next = nullptr;
        delete temp;
    }
    void pop(int index) {
        if (is_empty()) {
            return;
        }
        if (index == 0) {
            pop_front();
            return;
        }
        Node<T>* pnode = begin;
        for (int i = 0; i < index - 1; ++i) {
            pnode = pnode->next;
            if (pnode == nullptr) {
                return;
            }
        }
        Node<T>* prev = pnode;
        Node<T>* aft = pnode->next->next;
        pnode = pnode->next;
        delete pnode;
        prev->next = aft;
    }
    void remove(T val) {
        if (is_empty()) {
            return;
        }
        if (begin->val == val) {
            pop_front();
            return;
        }
        Node<T>* pnode = begin;
        while (pnode->next != nullptr && pnode->next->val != val) {
            pnode = pnode->next;
        }
        Node<T>* prev = pnode;
        Node<T>* aft = pnode->next->next;
        pnode = pnode->next;
        delete pnode;
        prev->next = aft;
    }
    int find(T val) {
        Node<T>* pnode = begin;
        int index = 0;
        while (pnode->next != nullptr && pnode->val != val) {
            pnode = pnode->next;
            index++;
        }
        if (pnode->val == val) {
            return index;
        }
        return -1;
    }
    T& operator[](const int index) const {
        if (is_empty()) {
            throw "List doesn't have element with such index";
        }
        Node<T>* pnode = begin;
        for (int i = 0; i < index; ++i) {
            pnode = pnode->next;
            if (pnode == nullptr) {
                throw "List doesn't have element with such index";
            }
        }
        return pnode->val;
    }
    template<typename Type> friend ostream& operator<<(ostream&, const SingleLinkedList<Type>&);
};

template<typename Type>
ostream& operator<<(ostream& out, const SingleLinkedList<Type>& list) {
    if (list.is_empty()) {
        return out;
    }
    Node<Type>* pnode = list.begin;
    while (pnode != nullptr) {
        out << pnode->val << ' ';
        pnode = pnode->next;
    }
    return out;
}

#endif //SINGLE_LINKED_LIST_SINGLELINKEDLIST_H
