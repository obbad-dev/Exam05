#pragma once
#include <iostream>
#include <deque>

class bigint
{
private:
	std::deque <unsigned int> value;
	void pushNumber(unsigned int nb);
	size_t getNb() const;

public:
	bigint() {value.push_back(0);};
	bigint(unsigned int );
	bigint(const std::string& );
	const std::deque<unsigned int>& getValue() const;

	bigint operator+(const bigint& other) const;

	bigint& operator+=(const bigint& other);
	bigint& operator++();
	bigint operator++(int);
	bigint operator<<(size_t shift) const;
	bigint operator>>(size_t shift) const;
	bigint &operator<<=(size_t shift) ;
	bigint &operator>>=(size_t shift) ;
	bigint &operator>>=(const bigint& other) ;

	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator>=(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;

	friend std::ostream& operator<<(std::ostream& out, const bigint& ob);
};

