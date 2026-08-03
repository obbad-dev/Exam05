#pragma once 
#include <iostream>
#include <vector>
#include <utility>

class vect2
{
private:
	int a;
	int b;

public:
	vect2() :a(0), b(0){}
	vect2(int x, int y): a(x), b(y){};
	// vect2(int x): a(x), b(x){};
	std::pair<int, int> getVect2() const { return std::make_pair(a, b); }
	vect2(const vect2& o) : a(o.a), b(o.b){}

	vect2& operator=(const vect2& o) {
		if (&o != this)
		{
			this->a = o.a;
			this->b = o.b;
		}
		return *this;
	}

	vect2 operator++(int) {
		vect2 copy(*this);
		++(*this);
		return copy;
	}
	vect2& operator++(){
		this->a++;
		this->b++;
		return *this;
	}
	vect2 operator--(int){
		vect2 copy(*this);
		--(*this);
		return copy;
	}
	vect2& operator--(){
		this->a--;
		this->b--;
		return *this;
	}

	vect2 operator+(const vect2& o) const
	{
		return vect2(o.a + this->a, o.b + this->b);
	}
	vect2 operator-(const vect2& o) const
	{
		return vect2(this->a - o.a , this->b - o.b);
	}
	vect2 operator*(const vect2& o) const
	{
		return vect2(this->a * o.a , this->b * o.b);
	}
	
	vect2 operator+(int nb) const
	{
		return vect2(this->a + nb, nb + this->b);
	}
	vect2 operator-(int nb) const
	{
		return vect2(this->a - nb , this->b - nb);
	}
	vect2 operator*(int nb) const
	{
		return vect2(this->a * nb , this->b * nb);
	}
	friend vect2 operator*(int nb, const vect2& obj){
		return obj * nb;
	}
	vect2 operator-() const
	{
		return vect2(-this->a, -this->b);
	}

	vect2& operator+=(const vect2& o) {
		*this = *this + o;
		return *this;
	}
	vect2& operator*=(const vect2& o) {
		*this = *this * o;
		return *this;
	}	
	vect2& operator-=(const vect2& o) {
		*this = *this - o;
		return *this;
	}

	vect2& operator+=(int nb) {
		*this = *this + nb;
		return *this;
	}
	vect2& operator*=(int nb) {
		*this = *this * nb;
		return *this;
	}	
	vect2& operator-=(int nb) {
		*this = *this - nb;
		return *this;
	}

	int& operator[](size_t index){
		if (!index)
			return this->a;
		else
			return this->b;
	}
	int operator[](size_t index) const{
		if (!index)
			return this->a;
		else
			return this->b;	
	}
	bool operator==(const vect2& o) const
	{
		return (this->a == o.a && this->b == o.b);
	}
	bool operator!=(const vect2& o) const
	{
		return !(*this == o);
	}
	
};

std::ostream& operator<<(std::ostream& out, const vect2&  obj);
