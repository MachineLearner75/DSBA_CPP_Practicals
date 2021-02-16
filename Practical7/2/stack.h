#include <iostream>
#include <sstream>

#ifndef STACK_H
#define STACK_H

using std::stringstream;
using std::cout;
using std::endl;

/*
Exceptions
*/
class EmptyStackException : public std::exception {
    virtual const char* what() const throw() {
        return "Empty stack!";
    }
} EmptyStackException;


class FullStackException : public std::exception {
    virtual const char* what() const throw() {
        return "Full stack!";
    }
} FullStackException;

template <class T>
class StackNode {
  protected:
    StackNode *next;
    T value;
  public:
    StackNode(T value) : value(value) {}
    void setNext(StackNode* node) {
        next = node;
    }
    StackNode* getNext() { return next; }
    T getValue() { return value; }
};

/* Stack  ADT */
template <typename T> 
class StackI {
  public: 
    virtual void push(T t) = 0;
    virtual void pop() = 0;
    virtual T top() = 0;
    virtual void print() = 0;
};

template <typename T>
class Stack : public StackI <T> {
  protected:
    int maxSize;
    int size;
    StackNode<T> *head;

    int getNonEmpty();

  public:
    Stack<T>();
    Stack<T>(int n);
    ~Stack();

    void push(T t);
    void pop();
    T top();
    bool isEmpty();
    void print();
};

template <typename T>
Stack<T>::Stack() : maxSize(20), size(0), head(nullptr) {}

template <typename T> 
Stack<T>::Stack(int n) : maxSize(n), size(0), head(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    StackNode<T> *walk = head;
    StackNode<T> *temp = nullptr;

    while (walk != nullptr) {
        temp = walk;
        walk = walk->getNext();
        delete temp;
    }
}

template <typename T> 
void Stack<T>::push(T t) {
    if (size >= maxSize) {
        throw FullStackException;
    }

    StackNode<T> *sn = new StackNode<T>(t);
    sn->setNext(head);
    head = sn;
    size++;
}

template <class T> 
void Stack<T>::pop() {
    if (isEmpty()) {
        throw EmptyStackException;
    }

    StackNode<T> *temp = head;
    head = head->getNext();
    delete temp;
    size--;
}

template <class T> 
T Stack<T>::top(){
    if (isEmpty()) {
        throw EmptyStackException;
    }
    return head->getValue();
}
template <class T> 
bool Stack<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
void Stack<T>::print() {
    stringstream st;
    StackNode<T> *walk = head;

    while (walk != nullptr) {
        st << walk->getValue();
        walk = walk->getNext();
        if (walk != nullptr) {
            st << " ";
        }
    }
    cout << "[" << st.str() << "]" << endl;
}

#endif