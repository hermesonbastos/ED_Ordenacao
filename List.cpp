#include <iostream>
#include "List.h"
#include "Node.h"
using namespace std;

List::List(){
    this->m_head = new Node(0, nullptr, nullptr);
    this->size = 0;
}

List::~List() {
    if (m_head != nullptr) {
        Node* current = m_head->next;

        while (current != m_head) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        delete m_head;
    }
}

void List::append(int value) {
    Node *newNode = new Node(value, nullptr, nullptr);
    if (m_head->next == nullptr) {
        newNode->next = m_head;
        newNode->prev = m_head;
        m_head->prev = newNode;
        m_head->next = newNode;
    } else {
        newNode->next = m_head;
        m_head->prev->next = newNode;
        newNode->prev = m_head->prev;
        m_head->prev = newNode;
    }
    size++;
}

int List::begin() {
    return m_head->next->value;
}

void List::print() {
    Node *aux = this->m_head->next;
    while(aux != m_head){
        cout << aux->value << " ";
        aux = aux->next;
    }
}

// -------------------- Insertion Sort -------------------- //

void List::insertionSort() {
    Node *current = m_head->next->next;
    Node *lastSort = m_head->next;

    while(current != m_head){
        int c_value = current->value;
        lastSort = current->prev;
        while(lastSort != m_head){
            if(lastSort->value > c_value){
                lastSort->next->value = lastSort->value;
                lastSort = lastSort->prev;
            } else {
                break;
            }
        }
        
        lastSort->next->value = c_value;
        current = current->next;
    }
}


