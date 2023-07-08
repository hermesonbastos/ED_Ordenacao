#include <iostream>
#include <list>
#include "List.h"
#include "Node.h"
using namespace std;

List::List(){
    this->m_head = new Node(0, nullptr, nullptr);
    this->size = 0;
}

List::~List() {
    if (m_head != nullptr){
        Node* current = m_head->next;

        while (current != m_head) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        delete m_head;
    }
}

void List::append(int value){
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

Node* List::getHead(){
    return this->m_head;
}

Node* List::begin() {
    return m_head->next;
}

Node * List::end() {
    return m_head->prev;
}

void List::swap(Node* atual, Node* aux) {
    int temp = atual->value;
    atual->value = aux->value;
    aux->value = temp;
}

void List::print(){
    Node *aux = this->m_head->next;
    while(aux != m_head){
        cout << aux->value << " ";
        aux = aux->next;
    }
}

// -------------------- Bubble Sort -------------------- //
void List::bubblesort() {
    Node* atual = m_head->next;

    while (atual != m_head) {
        Node* proxNode = atual->next;
        while (proxNode != m_head) {
            if(atual->value > proxNode->value) {
                swap(atual, proxNode);
            }
            proxNode = proxNode->next;
        }
        atual = atual->next;
    }
}

// -------------------- Insertion Sort -------------------- //

void List::insertionSort(){
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

// -------------------- Selection Sort -------------------- //
void List::selectionSort() {
    Node* atual = m_head->next;

    while (atual != m_head) {
        Node* menorNode = atual;
        Node* proxNode = atual->next;
        
        while (proxNode != m_head) {
            if(proxNode->value < menorNode->value) {
                menorNode = proxNode;
            }
            proxNode = proxNode->next;
        }
        swap(atual, menorNode);
        atual = atual->next;
    }
}

// -------------------- Merge Sort -------------------- //
Node* List::split(Node* head, Node* tail){
    Node *first = head, *second = head;

    while(first != tail && first->next != tail){
        first = first->next->next;
        second = second->next;
    }

    return second;
}

void List::merge(Node* head, Node* tail, Node* middle){
    List newList;
    Node *faux = head, *saux = middle->next;

    while(faux != middle->next && saux != tail->next){
        if(faux->value > saux->value){
            newList.append(saux->value);
            saux = saux->next;
        } else {
            newList.append(faux->value);
            faux = faux->next;
        }
    }

    while(faux != middle->next){
        newList.append(faux->value);
        faux = faux->next;
    }

    while(saux != tail->next){
        newList.append(saux->value);
        saux = saux->next;
    }

    faux = newList.m_head->next;
    saux = head;

    while(saux != tail->next){
        saux->value = faux->value;
        saux = saux->next;
        faux = faux->next;
    }
}

void List::mergeSort(Node* head, Node* tail){
  if(head != tail && head->prev != tail){
    Node* middle = split(head, tail);
    mergeSort(head, middle);
    mergeSort(middle->next, tail);
    merge(head, tail, middle);
  }
}

// -------------------- Quick Sort -------------------- //
Node* List::partition(Node* inicio, Node* fim) {
    Node* pivot = fim;
    Node* posPivot = inicio->prev;
    Node* atual = inicio;

    while (atual != fim) {  
        if(atual->value <= pivot->value) { 
            posPivot = posPivot->next;
            
            swap(posPivot, atual);
        }  
        atual = atual->next;
    }
    posPivot = posPivot->next;

    swap(posPivot, fim);

    return posPivot;
}

void List::quicksort(Node* low, Node* high) {
    if(low != high->next && low != high) {
        Node* indexPivot = partition(low, high);

        quicksort(low, indexPivot->prev);
        quicksort(indexPivot->next, high);
    }
}

// -------------------- Cocktail Sort -------------------- //
void List::cocktailSort(){
    Node *aux = this->m_head->next, *liml = m_head, *limr = m_head;
    int temp;

    while(liml->next != limr){
        while(aux->next != limr){
            if(aux->value > aux->next->value){
                swap(aux->next, aux);
            }
            aux = aux->next;
        }

        limr = aux;
        aux = aux->prev;

        while(aux->prev != liml){
            if(aux->value < aux->prev->value){
                swap(aux->prev, aux);
            }
            aux = aux->prev;
        }

        liml = aux;
        aux = aux->next;
    }
}