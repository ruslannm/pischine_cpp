#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::const_iterator easyfind(const T &, const int &);

class NotFound : public std::exception
{
public:
	virtual const char *what(void) const throw();
};

#include "easyfind.tpp"

#endif
