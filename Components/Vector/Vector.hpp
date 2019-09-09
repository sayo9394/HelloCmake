#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <cstring>

const int START_SIZE = 2;
const double K_CONSTANT = 1.5;

template <class T>
class Vector
{
public:
    Vector();
    explicit Vector(size_t size);
    Vector(const Vector<T>& data);
    ~Vector(){}

    size_t size() {return m_size;}

    Vector<T>& operator[]


private:
    T* m_data;
    size_t m_size;
};
#endif // VECTOR_HPP_
