#include "easyfind.hpp"
#include <deque>
#include <set>
#include <stdexcept>
#include <vector>

int main()
{
	std::vector<int> values;
	values.push_back(int(1));
	values.push_back(int(2));
	values.push_back(int(4));
	std::cout << "Contained value: " << easyfind(values, 4) << std::endl;
	try
	{
		std::cout << "throwing: " << easyfind(values, 3) << std::endl;
	} catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::vector<int>::iterator it =  values.begin();
	std::cout << "First value: " << *it << std::endl;
	it = values.end();
	std::cout << "Last value: " << *(--it) << std::endl;
}
