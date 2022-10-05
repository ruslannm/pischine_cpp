#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template<typename T>
class Array
{
	public:
		Array(void);
		Array(const unsigned int&);
		Array(const Array<T>&);
		~Array(void);

		Array<T>&	 operator=(const Array<T>&);

		T&	operator[](int idx);
		
		unsigned int	size(void) const;
		class IndexOutOfBonds : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
		private:
		T* 		_array;
		unsigned int 	_size;
};


template<typename T>
void	iter(Array<T>&, void (*fun)(T const &));

template<typename T>
void	printElement(T &);

#include "Array.tpp"

#endif
