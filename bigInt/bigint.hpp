#pragma once
#include <iostream>
#include <deque>
#define UUL unsigned long long

class bigint
{
private:
	std::deque <unsigned int> value;
	void pushNumber(unsigned int nb);
	UUL getNb() const;

public:
	bigint() {value.push_back(0);};
	bigint(unsigned int );

	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);
	bigint& operator++();
	bigint operator++(int);
	bigint operator<<(const bigint& other) const;
	bigint operator>>(const bigint& other) const;
	bigint operator<<(UUL shift) const;
	bigint operator>>(UUL shift) const;
	bigint &operator<<=(UUL shift) ;
	bigint &operator>>=(UUL shift) ;
	bigint &operator>>=(const bigint& other) ;
	bigint &operator<<=(const bigint& other) ;

	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator>=(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;

	friend std::ostream& operator<<(std::ostream& out, const bigint& ob);
};

