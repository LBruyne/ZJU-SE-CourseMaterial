#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
using namespace std;

template<class T>
class Vector {
public:
    // Vector's redefinition part
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef value_type* iterator;
    typedef size_t size_type;

//======================================================================//
// The definition from PTA.
public:
    // creates an empty vector
    Vector() : start(0), finish(0), end_of_storage(0) {
        // cout << "Here create a vector." << endl;
        m_nSize = size_type(end() - begin());
        m_nCapacity = size_type(end_of_storage - begin());
    }         
    // creates a vector for holding 'size' elements
    Vector(int size) : m_nSize(0), m_nCapacity(size){
        start = new value_type(size);
        finish = start;
        end_of_storage = start + size;
    }              
    // the copy ctor
    Vector(const Vector& r) : m_nSize(r.m_nSize), m_nCapacity(r.m_nCapacity) {
        start = new T(m_nCapacity);
        for(size_type i = 0; i < m_nSize; i++)
            *(start + i) = *(r.start + i);
        finish = start + m_nSize;
        end_of_storage = start + m_nCapacity;
    }     
    // destructs the vector 
    ~Vector() {
        // cout << "Here delete a vector." << endl;
        delete[] start;
    }            
    // accesses the specified element without bounds checking         
    reference operator[](size_type index) {
        return *(begin() + index);
    }      
    // accesses the specified element, throws an exception of type 'std::out_of_range' when index <0 or >=m_nSize
    reference at(int index) {
        if( index < 0 || index >= m_nSize){
            throw "std::out of range";
        }
        return *(begin() + index);
    }              
    // return the size of the container
    size_type size() const {
        return size_type(end() - begin());
    };		                              
    void push_back(const T& X){
        if(finish != end_of_storage) {
            // aad a elem into the tail.
            *finish = X;
            finish ++;
            m_nSize ++;
        }
        else
            insert_aux(X);

    }    
    // checks whether the container is empty 
    bool empty()  const {
        return begin() == end();
    };            
    // clears the contents
    void clear() {
        delete[] start;
        start = finish = recopy();
        end_of_storage = start + m_nCapacity;
        m_nSize = 0;
    }                 

private:
    void inflate();                      // expand the storage of the container to a new capacity, e.g. 2*m_nCapacity
    // pointer m_pElements;              // pointer to the dynamically allocated storage, replaced by "start" below.
    size_type m_nSize;                   // the number of elements in the container
    size_type m_nCapacity;               // the number of elements that can be held in currently allocated storage

//======================================================================//

private:
    // newly added private value and func.
    void insert_aux(const T& X){
        inflate();
        *finish = X;
        finish++;
        m_nSize++;
    }
    iterator recopy();
    iterator start;                // header of current using room
    iterator finish;               // tail of current using room
    iterator end_of_storage;       // tail of usable room 

public: 
    // newly added public value and func.
    iterator begin() const { return start; }
    iterator end() const { return finish; }
    size_type capalicity() const { return m_nCapacity; }

};

template<class T>
void Vector<T>::inflate()
{
    // If the capacity is 0, change it to 1;
    // else change it to 2*capacity
    size_type old_size = size();
    size_type old_capacity = capalicity();
    size_type len = (old_size != 0 ? old_size * 2 : 1);
    iterator new_start = new value_type(len);
    for(size_type i = 0; i < old_size; i++){
        *(new_start + i) = *(start + i);
    }
    delete[] start;
    start = new_start;
    m_nCapacity = len;
    finish = start + old_size;
    end_of_storage = start + len;
}

template<class T>
typename Vector<T>::iterator Vector<T>::recopy()
{
    iterator new_start = new T(m_nCapacity);
    return new_start;
}

#endif