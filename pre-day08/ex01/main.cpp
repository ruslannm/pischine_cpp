#include <iostream>
#include <vector>
#include "Span.hpp"

int main(void)
{
	std::cout << "Subject test" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << "Test 20_000 element" << std::endl;
	size_t sp_size = 20000;
	sp = Span(sp_size);
	for (size_t i = 0; i < sp_size; ++i)
	{
		sp.addNumber(10000 - i);
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "Test AddRange" << std::endl;
	sp = Span(20);
	for (size_t i = 0; i < 5; ++i)
	{
		sp.addNumber(i);
	}

	std::vector<int> v;
	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(10 + i);
	}
	sp.addRange(v.begin(), v.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "Test Exceptions" << std::endl;
	sp = Span();
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	sp = Span(1);
	sp.addNumber(10);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp.addRange(v.begin(), v.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
