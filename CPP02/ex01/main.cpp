#include "Fixed.hpp"

int main(void)
{
	Fixed a(5.75f);
	a.printParts();
	Fixed b(42.42f);
	b.printParts();
	Fixed c(-3.25f);
	c.printParts();
	return 0;
}
