#pragma once
#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <stdint.h>
# include <time.h>
# include <cstdlib>
# include <exception>

# define debug(x) std::cout << x << std::endl

class A;
class B;
class C;

class Base
{
	public:
		virtual ~Base();
};

#endif
