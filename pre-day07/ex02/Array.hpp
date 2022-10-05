#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <iomanip>

template<typename T>
class Array
{
	public:
		Array(void);
		Array(const unsigned int&);
		Array(const Array<T>&);
		~Array(void);

		Array<T>&	 operator=(const Array<T>&);

		T&	operator[](const int &);
		T const &	operator[](const int &) const;		
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
std::ostream & operator<<(std::ostream &, const Array<T> &);


#include "Array.tpp"

#endif
