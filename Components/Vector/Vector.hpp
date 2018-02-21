#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>

class Vector
{
public:
	Vector();
	~Vector(){}

private:
	std::unique_ptr<double> m_data;
	int m_size;
};
#endif //VECTOR_HPP_