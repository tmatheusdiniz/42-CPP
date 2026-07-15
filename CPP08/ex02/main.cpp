#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "===== MutantStack (subject test) =====" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);
	std::cout << "\n===== Same test with std::list =====" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\n===== Extra: copy, reverse & const iterators =====" << std::endl;
	MutantStack<int> copy(mstack);
	std::cout << "copy top: " << copy.top() << std::endl;
	std::cout << "reverse order: ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;
	const MutantStack<int> cstack(mstack);
	std::cout << "const forward: ";
	for (MutantStack<int>::const_iterator cit = cstack.begin(); cit != cstack.end(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;
	std::cout << "\n===== Empty stack =====" << std::endl;
	MutantStack<int> empty;
	std::cout << "empty? " << (empty.begin() == empty.end() ? "yes" : "no") << std::endl;

	return 0;
}
