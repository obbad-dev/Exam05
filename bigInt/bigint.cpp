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

const std::deque<unsigned int>& bigint::getValue() const {
	return value;
}

std::ostream& operator<<(std::ostream& out, const bigint& ob){
	const std::deque<unsigned int>& value = ob.getValue();

	for (size_t i = 0; i < value.size(); i++)
		out << value[i];
		
	return out;
}