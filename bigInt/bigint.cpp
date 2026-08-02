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


bigint bigint::operator+(const bigint& other) const
{
	bigint res;
	res.value.clear();

	size_t carry = 0;
	size_t i = this->value.size();
	size_t j = other.value.size();
	size_t run = (j >= i) ? j : i;
	while (run)
	{
		size_t a = (i > 0) ? this->value[--i] : 0;
		size_t b = (j > 0) ? other.value[--j] : 0;

		size_t result = a + b + carry;
		carry = result / 10;
		result = result % 10;

		res.value.push_front(result);
		run--;
	}
	if (carry)
		res.value.push_front(carry);
	return res;
}

// bigint bigint::operator+(unsigned int nb) const
// {
// 	std::cout << "2 here\n";
// 	bigint obj(nb);
// 	return bigint(*this + obj); 
// }
bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

bigint& bigint::operator++()
{
	bigint pre(1);
	*this = *this + pre;
	return *this;
}

bigint bigint::operator++(int)
{
	bigint copy(*this);
	++(*this);
	return copy;
}

bigint bigint::operator<<(size_t shift) const
{
	bigint copy(*this);
	for (size_t i = 0; i < shift; i++)
	{
		if (copy.value.size() && copy.value[0] != 0)
			copy.value.push_back(0);
		else
			break;
	}
	return copy;
}

bigint bigint::operator>>(size_t shift) const {
	bigint copy(*this);

	if (shift >= copy.value.size())
	{
		copy.value.clear();
		copy.value.push_back(0);	
		return copy;
	}
	for (size_t i = 0; i < shift; i++)
		copy.value.pop_back();
	
	return copy;
}

bigint& bigint::operator<<=(size_t shift)
{
	*this = *this << shift;
	return *this;
}

bigint& bigint::operator>>=(size_t shift)
{
	*this = *this >> shift;
	return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
    if (other.value.size() > 19 || other.getNb() >= this->value.size())
    {
        this->value.clear();
		this->value.push_back(0);
    }
    else
    {
        *this >>= other.getNb();
    }

    return *this;
}
const std::deque<unsigned int>& bigint::getValue() const {
	return value;
}

size_t bigint::getNb() const{
	size_t result = 0;
	for (size_t i = 0; i < value.size(); ++i)
	{
		result = result * 10 + value[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const bigint& ob){
	const std::deque<unsigned int>& value = ob.getValue();

	for (size_t i = 0; i < value.size(); i++)
		out << value[i];
		
	return out;
}