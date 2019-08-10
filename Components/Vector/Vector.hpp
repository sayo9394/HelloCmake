#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <cstring>

namespace
{
const int START_SIZE = 2;
const double K_CONSTANT = 1.5;

template <class T>
class Vector
{
public:
    Vector();
    explicit Vector();
    ~Vector()
    {
	}

private:
    T* m_data;
    size_t m_size;
};

} // namespace
#endif // VECTOR_HPP_
