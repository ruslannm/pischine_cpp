#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main(void)
{
	{
		std::cout << "Test MutantStack" << std::endl;
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
	}

	{
		std::cout << "Test List" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << "Test Canonical Methods" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		MutantStack<int> mstack1(mstack);
		MutantStack<int>::iterator it = mstack1.begin();
		MutantStack<int>::iterator ite = mstack1.end();
		std::cout << "mstack1:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		MutantStack<int> mstack2;
		mstack2.push(0);
		mstack2.push(21);
		mstack2.push(42);
		mstack2 = mstack;
		mstack2.push(100);
		it = mstack2.begin();
		ite = mstack2.end();
		std::cout << "mstack2:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		it = mstack.begin();
		ite = mstack.end();
		std::cout << "mstack:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
