#include <iostream>
#include "List.h"
#include "Node.h"
using namespace std;

List::List(){
    this->m_head = new Node(0, nullptr, nullptr);
    this->m_tail = new Node(0, nullptr, nullptr);
    this->size = 0;
}

List::~List() {
    Node *atual = m_head;
    while (atual != nullptr) {
        Node *next = atual->next;
        delete atual;
        atual = next;
    }
}

void List::append(int value) {
    Node *newNode = new Node(value, nullptr, nullptr);
    if (m_head->next == nullptr) {
        // A lista está vazia
        m_head->next = newNode;
        newNode->prev = m_head;
        m_tail->prev = newNode;
        newNode->next = m_tail;
    } else {
        // A lista não está vazia
        Node *lastNode = m_tail->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = m_tail;
        m_tail->prev = newNode;
    }
    size++;
}

int List::begin() {
    return m_head->next->value;
}

void List::pop() {
    Node *aux = m_head->next;
    m_head->next = m_head->next->next;
    m_head->next->prev = m_head;
    delete aux;
}

void List::print() {
    Node *aux = this->m_head->next;
    while(aux->next != nullptr){
        cout << aux->value << " ";
        aux = aux->next;
    }
}
