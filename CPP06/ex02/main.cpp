#include "Base.hpp"
#include <ctime>
#include <cstdlib>

struct Test : public Base
{
};

int main()
{
	srand(time(NULL));
	Base* base = generate();
	Test t;
	Test* p = &t;
	identify(base);
	identify(*base);
	identify(p);
	delete base;
	return 0;
}
