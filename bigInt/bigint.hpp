#pragma once
#include <iostream>
#include <deque>

#define UUL unsigned long long

class bigint
{
private:
	std::deque <unsigned int> value;

public:
	bigint() {value.push_back(0);};
	bigint(unsigned int nb){
	
		if (!nb)
			value.push_back(0);
		while (nb > 0)
		{
			value.push_front(nb % 10);
			nb /= 10;
		}
	}

	UUL getNumber() const{
		UUL res = 0;
		for (size_t i = 0; i < value.size(); ++i)
			res = res * 10 + value[i];
		return res;
	}

	friend std::ostream& operator<< (std::ostream& out, const bigint& o)
	{
		for (unsigned int nb : o.value)
			out << nb;
		return out;
	}
	bigint operator+(const bigint& o) const
	{
		bigint res;
		res.value.clear();
		size_t j = o.value.size();
		size_t i = this->value.size();
		UUL carry = 0;
		size_t  run = std::max(i, j);
		while (run)
		{
			UUL a = (i > 0) ? this->value[--i] : 0;
			UUL b = (j > 0) ? o.value[--j] : 0;
			UUL result = a + b + carry;
			carry = result / 10;
			res.value.push_front(result % 10);
			run--;
		}
		if (carry)
			res.value.push_front(carry);
		return res;
	}

	bigint& operator+=(const bigint& o)
	{
		*this = *this + o;
		return *this;
	}
	bigint& operator++()
	{
		*this += 1;
		return *this;
	}
	bigint operator++(int) {
		bigint last(*this);
		++(*this);
		return last;
	}

	bigint operator<<(UUL shift) const
	{
		bigint res(*this);

		UUL i = 0;
		while (i < shift)
		{
			if (res.value[0] != 0)
				res.value.push_back(0);
			else
				break;
			i++;
		}
		return res;
	}

	bigint operator>>(UUL shift) const
	{
		bigint res(*this);
		if (shift >= res.value.size())
			return bigint();
		
		UUL i = 0;
		while (i < shift)
		{
			res.value.pop_back();
			i++;
		}
		return res;
	}
	bigint operator<<(const bigint& o) const
	{
		bigint res(*this);
		res = res << o.getNumber();
		return res;
	}
	bigint operator>>(const bigint& o) const
	{
		bigint res(*this);

		res = res >> o.getNumber();
		return res;
	}
	bigint& operator<<=(const bigint& o) 
	{
		*this = *this << o.getNumber();
		return *this;
	}
	bigint& operator>>=(const bigint& o) 
	{
		*this = *this >> o.getNumber();
		return *this;
	}
	
};

