#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base
{
public:
	virtual ~Base(void);
};

class A : public Base
{
public:
	A(void);
};

class B : public Base
{
public:
	B(void);
};

class C : public Base
{
public:
	C(void);
};

Base *generate(void);

void identify(Base *);

void identify(Base &);

#endif
