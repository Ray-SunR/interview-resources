#include <iostream>
#include "stackexception.h"
#include <vector>

template <class T>
class Mystack
{
private:
    T* top;
    int size;
    std::vector<T> stack;
public:
    Mystack():top(NULL), size(0){}
    ~Mystack(){}
    void push(const T& item);
    T pop();
    const T& get_top();
    int get_size() const {return size;}
    bool is_empty();
};

template <class T>
void Mystack<T>::push(const T& item)
{
    stack.push_back(item);
    size++;
    top = &stack.at(size - 1);
}

template <class T>
T Mystack<T>::pop()
{
    if (is_empty())
        throw StackException("Empty stack!");
    T del = stack.at(stack.size() - 1);
    stack.erase(stack.end()- 1);
    if (stack.size())
        top = &stack.at(stack.size() - 1);
    else
        top = NULL;
    size = (int)stack.size();
    return del;
}

template <class T>
const T& Mystack<T>::get_top()
{
    if (is_empty())
        throw StackException("Empty stack!");
    else
        return *top;
}

template <class T>
bool Mystack<T>::is_empty()
{
    return !size? true: false;
}
