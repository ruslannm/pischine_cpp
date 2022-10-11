#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:

	MutantStack<T>(void);

	MutantStack<T>(const MutantStack<T> &);

	~MutantStack<T>(void);

	MutantStack &operator=(const MutantStack<T> &);

	typedef typename MutantStack<T>::container_type::iterator iterator;

	iterator begin(void);

	iterator end(void);
};

#include "MutantStack.tpp"

#endif
