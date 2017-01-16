//
// Created by avishay on 1/15/17.
//

#ifndef EX2CPP_DOUBLE_LINKED_H
#define EX2CPP_DOUBLE_LINKED_H


#include <iostream>


using namespace std;

/**
*template <typename T> of double linked list
*/
template <typename T>
class double_linked
{
    struct node
    {
        T data;
        node* prev;
        node* next;
        node(T t, node* p, node* n) : data(t), prev(p), next(n) {}
    };
    node* head;
    node* tail;
    size_t _size;
public:
    double_linked() : head( NULL ), tail ( NULL ), _size(0) {}
    template<int N>
    double_linked( T (&arr) [N]) : head( NULL ), tail ( NULL )
    {
        for( int i(0); i != N; ++i)
            push_back(arr[i]);
    }

    size_t get_size() const;

    bool empty() const { return ( !head || !tail ); }
    operator bool() const { return !empty(); }
    void push_back(T);
    void push_front(T);
    T pop_back();
    T pop_front();

    ~double_linked()
    {
        while(head)
        {
            node* temp(head);
            head=head->next;
            delete temp;
        }
    }
};

template <typename T>
void double_linked<T>::push_back(T data)
{
    tail = new node(data, tail, NULL);
    if( tail->prev )
        tail->prev->next = tail;

    if( empty() )
        head = tail;

    _size++;
}

template <typename T>
void double_linked<T>::push_front(T data)
{
    head = new node(data, NULL, head);
    if( head->next )
        head->next->prev = head;

    if( empty() )
        tail = head;

    _size++;
}

template<typename T>
T double_linked<T>::pop_back()
{
    if( empty() ){
       return  NULL;
        //throw("double_linked : list empty");
        //std::cout<<"double_linked : list empty"<<std::endl;
    }

    node* temp(tail);
    T data( tail->data );
    tail = tail->prev ;

    if( tail )
        tail->next = NULL;
    else
        head = NULL ;

    delete temp;
    _size--;
    return data;
}

template<typename T>
T double_linked<T>::pop_front()
{
    if( empty() )
        throw("double_linked : list empty");
    node* temp(head);
    T data( head->data );
    head = head->next ;

    if( head )
        head->prev = NULL;
    else
        tail = NULL;

    delete temp;
    _size--;
    return data;
}
template<typename T>
size_t double_linked<T>::get_size() const {
    return _size;
}


#endif //EX2CPP_DOUBLE_LINKED_H
