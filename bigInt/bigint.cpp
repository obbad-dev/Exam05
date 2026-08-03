#include "bigint.hpp"
#include <exception>

void bigint::pushNumber(unsigned int nb)
{
	while (nb > 0)
	{
		value.push_front(nb % 10);
		nb /= 10;
	}
}
bigint::bigint(unsigned int nb){
	if (!nb)
		value.push_back(0);
	pushNumber(nb);
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

bigint bigint::operator<<(UUL shift) const
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

bigint bigint::operator>>(UUL shift) const {
	bigint copy(*this);

	if (shift >= copy.value.size())
	{	
		return bigint();
	}
	for (size_t i = 0; i < shift; i++)
		copy.value.pop_back();
	
	return copy;
}

bigint bigint::operator>>(const bigint& other) const
{
	bigint copy(*this);
	copy = copy >> other.getNb();
	return copy;
}
bigint bigint::operator<<(const bigint& other) const
{
	bigint copy(*this);
	copy = copy << other.getNb();
	return copy;
}

bigint& bigint::operator<<=(UUL shift)
{
	*this = *this << shift;
	return *this;
}

bigint& bigint::operator>>=(UUL shift)
{
	*this = *this >> shift;
	return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
    *this >>= other.getNb();
    return *this;
}

bigint& bigint::operator<<=(const bigint& other)
{
	*this <<= other.getNb();
	return *this;
}

bool bigint::operator<(const bigint& other) const {
	if (this->value.size() != other.value.size())
		return this->value.size() < other.value.size();
	return this->value < other.value;
}
bool bigint::operator>(const bigint& other) const {
	return  other < *this;
}
bool bigint::operator<=(const bigint& other) const {
	return !(other < *this);
}
bool bigint::operator>=(const bigint& other) const {
	return !(*this < other);
}
bool bigint::operator==(const bigint& other) const {

	if (this->value.size() != other.value.size())
		return false;
	return this->value == other.value;
}
bool bigint::operator!=(const bigint& other) const {
	return !(*this == other);
}

UUL bigint::getNb() const{
	UUL result = 0;
	for (size_t i = 0; i < value.size(); ++i)
	{
		result = result * 10 + value[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const bigint& ob){

	for (size_t i = 0; i < ob.value.size(); i++)
		out << ob.value[i];
		
	return out;
}
