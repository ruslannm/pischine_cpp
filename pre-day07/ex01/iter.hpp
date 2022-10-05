#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void	iter(const T  *arr, const size_t & size, void (*fun)(T const &))
{
	for (size_t i = 0; i < size; ++i){
		fun(arr[i]);
    }
    return;
};

template<typename T>
void	printElement(const T & element)
{
	std::cout << element << std::endl;
    return;
};

#endif
