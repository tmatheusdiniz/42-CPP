#include "iter.hpp"
#include <iostream>
using namespace std;

void incrementOne(int& value)
{
	value++;
}

int main()
{
	int arr[] = {1, 2, 4};
	::iter(arr, 3, &incrementOne);
	for(int i = 0; i < 3; i ++)
	{
		std::cout << "incremented value: " << arr[i] << std::endl;
	}
}
