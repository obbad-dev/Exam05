#pragma once
#include <iostream>
#include <deque>

class bigint
{
private:
	std::deque <unsigned int> value;
	void pushNumber(unsigned int nb);

public:
	bigint() {value.push_back(0);};
	bigint(unsigned int );
	bigint(const std::string& );
	const std::deque<unsigned int>& getValue() const;

	bigint operator+(const bigint& other) const;
	// bigint operator+(unsigned int) const;
	bigint& operator+=(const bigint& other);
	bigint& operator++();
	bigint operator++(int);
	bigint operator<<(size_t shift) const;
	bigint operator>>(size_t shift) const;
	bigint &operator<<=(size_t shift) ;
	bigint &operator>>=(size_t shift) ;

	friend std::ostream& operator<<(std::ostream& out, const bigint& ob);
};

