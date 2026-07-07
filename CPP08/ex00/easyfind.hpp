#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
int easyfind(const T& container, int value) // I'm using const to make it attach to both
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return (*it);
}
