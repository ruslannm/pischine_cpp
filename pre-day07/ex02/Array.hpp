#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template<typename T>
class Array
{
	private:
		T* 		_array;
		unsigned int 	_size;
	public:
		Array (void);
		Array (unsigned int);
		Array (const Array&);
		~Array (void);

		Array&	 operator=(const Array&);

		T&	operator[](int idx);
		
		unsigned int	size(void) const;
		class IndexOutOfBonds : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
};


template<typename T>
void	iter(Array<T>, void (*fun)(T const &));

template<typename T>
void	printElement(T &);

#include "Array.tpp"

#endif
