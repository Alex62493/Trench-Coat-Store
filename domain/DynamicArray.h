//
// Created by Alex on 20.03.2021.
//
#include "TrenchCoat.h"
#include <cstdlib>

#ifndef A45_ALEX62493_DYNAMICARRAY_H
#define A45_ALEX62493_DYNAMICARRAY_H

template <typename T>
class DynamicArray {

private:
    int size, maxSize;
    T** list;

//private:
    //void updateArraySize(int size);

public:
    DynamicArray();
    ~DynamicArray();

    /*
     * Adds a dress at the end of the list
     */
    void addElement(T* d);

    /*
     * Returns the size of the array
     */
    int getSize() const;

    /*
     *Removes an element
     */
    void deleteElement(int id);

    /*
     * Getter for an element
     */
    T* getElement(int id);

    /*
    * It sets th size to zero, so it doesn't delete the elements, just the array
    * It is needed for the cart
    */
    void setToZero();

};


#endif //A45_ALEX62493_DYNAMICARRAY_H
