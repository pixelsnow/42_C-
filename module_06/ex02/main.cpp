#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	srand(time(NULL));
	int num = rand() % 3;
	switch (num)
	{
		case 0:
			std::cout << "CREATED: A" << std::endl;
			return new A;
		case 1:
			std::cout << "CREATED: B" << std::endl;
			return new B;
		case 2:
			std::cout << "CREATED: C" << std::endl;
			return new C;
		default:
			return NULL;
	}
}

static void detected(std::string typeName)
{
	std::cout << "DETECTED: " << typeName << std::endl;
	return;
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
		return (detected("A (ptr)"));
	B* b = dynamic_cast<B*>(p);
	if (b)
		return (detected("B (ptr)"));
	C* c = dynamic_cast<C*>(p);
	if (c)
		return (detected("C (ptr)"));
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void) a;
		detected("A (ref)");
	}
	catch(const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void) b;
			detected("B (ref)");
		}
		catch(const std::exception& e)
		{
			C& c = dynamic_cast<C&>(p);
			(void) c;
			detected("C (ref)");
		}
	}
}

int main(void)
{
	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);
	return (0);
}
