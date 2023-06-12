#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base *generate(void) {
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
	return NULL;
}

void identify(Base *p) {
	A *a = dynamic_cast<A *>(p);
	if (a) {
		std::cout << "A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B *>(p);
	if (b) {
		std::cout << "B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C *>(p);
	if (c) {
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Error!" << std::endl;
}

void identify(Base &p) {
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) { ; }
	try {
		B b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) { ; }
	try {
		C c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) { ; }
}


int main() {
	Base *base = generate();
	identify(base);
	delete base;
	base = generate();
	identify(*base);
	delete base;
}