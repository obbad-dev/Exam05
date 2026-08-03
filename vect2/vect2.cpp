#include "vect2.hpp"


std::ostream& operator<<(std::ostream& out, const vect2&  obj){
	out << "{" << obj.getVect2().first << ", " << obj.getVect2().second << "}";
	return out;
}