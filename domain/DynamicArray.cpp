//
// Created by Alex on 20.03.2021.
//

#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray() {
    this->size = 0;
    this->maxSize = 2;
    this->list = (T**) malloc(sizeof(T&) * 500);
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    for (int i = 0; i < this->size; i++)
        delete this->list[i];
    free(this->list);
}

template <typename T>
int DynamicArray<T>::getSize() const {
    return this->size;
}

template <typename T>
void DynamicArray<T>::addElement(T* d) {
    this->size++;
    if (this->size > this->maxSize) {
        maxSize *= 2;
        this->list = static_cast<T **>(realloc(this->list, maxSize * sizeof(T &)));
    }

    this->list[this->size - 1] = d;
}

template <typename T>
void DynamicArray<T>::deleteElement(int id) {
    delete this->list[id];
    for (int i = id; i < this->size - 1; i++)
        this->list[i] = this->list[i+1];

    this->size--;
}

template <typename T>
T* DynamicArray<T>::getElement(int i) {
    return this->list[i];
}

template <typename T>
void DynamicArray<T>::setToZero()
{
    this->size = 0;
}

template class DynamicArray<TrenchCoat>;