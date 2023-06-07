#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cstring>
# include <cmath>

# define debug(x) std::cout << x << std::endl

enum Type {
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	EXCEPTION,
	ERROR
};

class ScalarConverter
{
	public:
		~ScalarConverter();

		static void convert(std::string convert);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &obj);

		static bool isPseudoLiteral(std::string convert);
		static bool isChar(std::string convert);
		static bool isInt(std::string convert);
		static bool isFloat(std::string convert);
		static bool isDouble(std::string convert);
		static bool isError(std::string convert);
		static Type getType(std::string convert);

		static void displayError();
		static void displayChar(std::string convert);
		static void displayInt(std::string convert);
		static void displayFloat(std::string convert);
		static void displayDouble(std::string convert);
		static void displayException(std::string convert);

		static std::string pseudo_literals[6];
};

std::ostream &operator<<(std::ostream &stream, Type type);

#endif
