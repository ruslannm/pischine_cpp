#include "Base.hpp"

Base::~Base(void) {};

A::A(void) { std::cout << "A default constructor called" << std::endl; };

B::B(void) { std::cout << "B default constructor called" << std::endl; };

C::C(void) { std::cout << "C default constructor called" << std::endl; };

Base *generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	};
};

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return;
	}
	B *b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return;
	}
	C *c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return;
	}
	return;
};

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast &e) {};
	try
	{
		B &b = dynamic_cast<B &>(p);
		b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast &e) {};
	try
	{
		C &c = dynamic_cast<C &>(p);
		c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast &e) {};

	return;
};
