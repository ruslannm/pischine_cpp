#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template<typename T>
MutantStack<T>::MutantStack(void) {};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack <T> &src)
{
	this->c = src.c;
	return;
};

template<typename T>
MutantStack<T>::~MutantStack(void) {};

template<typename T>
MutantStack <T> &MutantStack<T>::operator=(const MutantStack <T> &rhs)
{
	if (this != &rhs)
	{
		this->c = rhs.c;
	}
	return *this;
};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
};

#endif
