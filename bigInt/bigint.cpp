#include "bigint.hpp"
#include <exception>
#include <sstream>


void bigint::pushNumber(unsigned int nb)
{
	while (nb > 0)
	{
		value.push_front(nb % 10);
		nb /= 10;
	}
}
bigint::bigint(unsigned int nb){
	pushNumber(nb);
}

bigint::bigint(const std::string& nb)
{
	std::stringstream ss(nb);
	unsigned int  snb;
	ss >> snb;
	pushNumber(snb);
}

bigint bigint::operator+(const bigint& other)
{
	bigint result;
	int maxSize = this->value.size() >= other.value.size() ? this->value.size() : other.value.size();
	
	for (int)
}

const std::deque<unsigned int>& bigint::getValue() const {
	return value;
}

std::ostream& operator<<(std::ostream& out, const bigint& ob){
	const std::deque<unsigned int>& value = ob.getValue();

	for (size_t i = 0; i < value.size(); i++)
		out << value[i];
		
	return out;
}