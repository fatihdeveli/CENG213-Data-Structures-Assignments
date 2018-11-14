#ifndef LINKEDLIST_HPP
#define	LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"

using namespace std;

/*....DO NOT EDIT BELOW....*/
template <class T>
class LinkedList {
private:
    Node<T>* head;
    int length;
public:

    LinkedList();
    LinkedList(const LinkedList<T>& ll);
    LinkedList<T>& operator=(const LinkedList<T>& ll);
    ~LinkedList();


    Node<T>* getHead() const;
    Node<T>* first() const;
    Node<T>* findPrev(const T& data) const;
    Node<T>* findNode(const T& data) const;
    void insertNode(Node<T>* prev, const T& data);
    void deleteNode(Node<T>* prevNode);
    void clear();
    size_t getLength() const;
    void print() const;
    void swap(int index1, int index2);
};

template <class T>
void LinkedList<T>::print() const {
    const Node<T>* node = first();
    while (node) {
        std::cout << node->getData();
        node = node->getNext();
    }
    cout << std::endl;
}

/*....DO NOT EDIT ABOVE....*/

/* TO-DO: method implementations below */

template <class T>
LinkedList<T>::LinkedList () {
    head = new Node<T>();
    length = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &ll) {
    head = new Node<T>();
    length = ll.length;
    if (ll.first()) {
        Node<T> *newNode = new Node<T>(ll.first()->getData());
        head->setNext(newNode);

        for (Node<T> *temp = ll.first()->getNext(); temp; temp = temp->getNext()) {
            newNode->setNext(new Node<T>(temp->getData()));
            newNode = newNode->getNext();
        }
    }
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &ll) {
    if (this != &ll) {
        clear();
        const Node<T> *r = ll.first(); // Temp node to iterate through rhs
        Node<T> *p = head;
        while(r) {
            insertNode(p, r->getData());
            p = p->getNext();
            r = r->getNext();
        }
    }
    return *this;
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
    delete head;
}

template<class T>
Node<T> *LinkedList<T>::getHead() const {
    return head;
}

template<class T>
Node<T> *LinkedList<T>::first() const {
    return head->getNext();
}

template<class T>
Node<T> *LinkedList<T>::findPrev(const T &data) const {
    Node<T>* prev = head;

    while (prev->getNext()) {
        if (prev->getNext()->getData() == data) {
            return prev;
        }
        prev = prev->getNext();
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::findNode(const T &data) const {
    Node<T> *temp = first();

    while (temp) {
        if (temp->getData() == data) return temp;
        temp = temp->getNext();
    }
    return NULL;
}

template<class T>
void LinkedList<T>::insertNode(Node<T> *prev, const T &data) {
    if (prev) {
        Node<T>* newNode = new Node<T>(data); // Create the new node
        if (prev->getNext()) { // Insert in the middle
            Node<T> *temp = prev->getNext();
            prev->setNext(newNode);
            newNode->setNext(temp);
        }
        else { // Insert at the end
            prev->setNext(newNode);
        }
        length++;
    }
}

template<class T>
void LinkedList<T>::deleteNode(Node<T> *prevNode) {
    if (prevNode) {
        if (prevNode->getNext()->getNext()) { // Deleting from the middle
            Node<T> *temp = prevNode->getNext()->getNext();
            delete prevNode->getNext();
            prevNode->setNext(temp);
        }
        else { // Deleting from the end
            delete prevNode->getNext();
            prevNode->setNext(NULL);
        }
        length--;
    }
}

template<class T>
void LinkedList<T>::clear() {
    for (Node<T> *next, *temp = first(); temp; temp = next) {
        next = temp->getNext();
        delete temp;
    }
    length = 0;
}

template<class T>
size_t LinkedList<T>::getLength() const {
    return length * sizeof(T);
}

template<class T>
void LinkedList<T>::swap(int index1, int index2) {
    Node<T> *tempNode = first(); // Node with index 0
    int i;
    for (i = 0; i < index1; i++) tempNode = tempNode->getNext(); // Find the node with index: index1
    T* data1Ptr = tempNode->getDataPtr();
    for (i = index1; i < index2; i++) tempNode = tempNode->getNext(); // Find the node with index: index2
    T data2 = tempNode->getData(); // Save the data at index2
    T* data2Ptr = tempNode->getDataPtr();
    *data2Ptr = *data1Ptr; // Change the data of the node at index2
    *data1Ptr = data2; // Change the data of the node at index1
}


/* end of your implementations*/
#endif
