#include "bigint.hpp"
int main ()
{
    const bigint a(55);
    bigint b(55), c, d(1337), e(d);
    c = e;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
	return 0;
}