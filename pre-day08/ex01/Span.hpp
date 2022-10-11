#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>

class Span
{
public:

	Span(void);

	Span(const Span &);

	Span(const unsigned int &);

	~Span(void);

	Span &operator=(const Span &);

	void addNumber(const int &);

	unsigned int shortestSpan(void) const;

	unsigned int longestSpan(void) const;

	void
	addRange(std::vector<int>::iterator, std::vector<int>::iterator);

	class CannotFind : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

	class CannotAdd : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

private:
	unsigned int _capacity;
	std::vector<int> _vector;

	void _checkAdd(unsigned int) const;

	void _checkFind(void) const;

	void _sortedVector(std::vector<int> &) const;
};

#endif
