#include "Span.hpp"

Span::Span(void) : _capacity(0) {};

Span::Span(const unsigned int &capacity) : _capacity(capacity)
{
	_vector.reserve(capacity);
	return;
};

Span::Span(const Span &src) : _capacity(src._capacity)
{
	_vector.reserve(_capacity);
	_vector = src._vector;
};

Span::~Span(void) {};

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		if ((this->_capacity > 0) && (this->_capacity > rhs._capacity))
		{
			this->_vector.clear();
			this->_vector.shrink_to_fit();
		}
		this->_capacity = rhs._capacity;
		this->_vector.reserve(rhs._capacity);
		this->_vector = rhs._vector;
	}
	return *this;
};

void Span::addNumber(const int &value)
{
	_checkAdd(1);
	this->_vector.push_back(value);
	return;
};

unsigned int Span::shortestSpan(void) const
{
	_checkFind();
	std::vector<int> tmp;
	_sortedVector(tmp);
	unsigned int result = tmp.at(tmp.size() - 1) - tmp.at(0);
	if (result == 0) {
		return result;
	}
	std::vector<int>::iterator curr = tmp.begin();
	int prev = *curr;
	++curr;
	for (; curr != tmp.end(); ++curr)
	{
		unsigned int diff = *curr - prev;
		if (diff == 0)
		{
			result = diff;
			break;
		}
		if (diff < result)
		{
			result = diff;
		}
		prev = *curr;
	}
	return result;
};

unsigned int Span::longestSpan(void) const
{
	_checkFind();
	std::vector<int> tmp;
	_sortedVector(tmp);
	return tmp.at(tmp.size() - 1) - tmp.at(0);
}

void
Span::addRange(std::vector<int>::iterator begin,
			   std::vector<int>::iterator end)
{
	_checkAdd(std::distance(begin, end));
	this->_vector.insert(this->_vector.end(), begin, end);
	return;
};

const char *Span::CannotFind::what(void) const throw()
{
	return "No span can be found";
};

const char *Span::CannotAdd::what(void) const throw()
{
	return "Cannot add in Span";
};

void Span::_checkAdd(unsigned int size) const
{
	if (_vector.size() + size > _capacity)
	{
		throw Span::CannotAdd();
	}
	return;
};

void Span::_checkFind(void) const
{
	if (_vector.size() < 2)
	{
		throw Span::CannotFind();
	}
	return;
};

void Span::_sortedVector(std::vector<int> &v) const
{
	v.reserve(this->_vector.size());
	v = this->_vector;
	std::sort(v.begin(), v.end());
	return;
};
