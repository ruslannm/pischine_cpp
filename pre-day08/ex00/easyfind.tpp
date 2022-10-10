#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template<typename T>
typename T::const_iterator easyfind(const T &container, const int &value)
{
	typename T::const_iterator result = std::find(container.begin(),
												  container.end(), value);
	if (result == container.end())
	{
		throw NotFound();
	}
	else
	{
		return result;
	}
};

const char * NotFound::what(void) const throw()
{
	return "Value not found in container";
};

#endif