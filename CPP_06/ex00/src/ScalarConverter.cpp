#include "../inc/ScalarConverter.hpp"

std::string ScalarConverter::pseudo_literals[6] = {
	"-inff", "+inff", "nanf",
	"-inf", "+inf", "nan"
};

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { (void) obj; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) { (void) obj; return *this; }

ScalarConverter::~ScalarConverter() {}

/****** CHECK TYPE ******/
bool ScalarConverter::isPseudoLiteral(std::string convert) {
	for (int i = 0; i < 6; i++) {
		if (convert == pseudo_literals[i])
			return true;
	}
	return false;
}

bool ScalarConverter::isError(std::string convert) {
	if (convert.empty() || \
		convert.find_first_of(".") != convert.find_last_of("."))
		return true;
	return false;
}

bool ScalarConverter::isChar(std::string convert) {
	if (convert.length() != 1 || isdigit(convert[0]) || !isprint(convert[0]))
		return false;
	return true;
}

bool ScalarConverter::isInt(std::string convert) {
	size_t i = (convert[0] == '+' || convert[0] == '-') ? 1 : 0;
	for (; i < convert.length(); i++) {
		if (!isdigit(convert[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(std::string convert) {
	size_t i = (convert[0] == '+' || convert[0] == '-') ? 1 : 0;
	if (convert[convert.length() - 1] != 'f')
		return false;
	for (int i = 0; i < 3; i++) {
		if (convert == pseudo_literals[i])
			return true;
	}
	for (; i < convert.length() - 1; i++) {
		if (!isdigit(convert[i]) && \
			convert[i] != '.')
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(std::string convert) {
	size_t i = (convert[0] == '+' || convert[0] == '-') ? 1 : 0;
	for (int i = 3; i < 6; i++) {
		if (convert == pseudo_literals[i])
			return true;
	}
	for (; i < convert.length(); i++) {
		if (!isdigit(convert[i]) && \
			convert[i] != '.' && \
			!(convert[i] == 'e' && isdigit(convert[i + 1])))
			return false;
	}
	return true;
}

Type ScalarConverter::getType(std::string convert) {
	if (isError(convert))
		return ERROR;
	else if (isChar(convert))
		return CHAR;
	else if (isInt(convert))
		return INT;
	else if (isFloat(convert))
		return FLOAT;
	else if (isDouble(convert))
		return DOUBLE;
	return EXCEPTION;
}

void ScalarConverter::convert(std::string convert) {
	Type type = getType(convert);
	std::cout << type << std::endl;
	switch (type) {
		case CHAR:
			displayChar(convert);
			break ;
		case INT:
			displayInt(convert);
			break;
		case FLOAT:
			displayFloat(convert);
			break;
		case DOUBLE:
			displayDouble(convert);
			break;
		case EXCEPTION:
			displayException(convert);
			break;
		default:
			displayError();
			break;
	}
}

/****** DISPLAY TYPES ******/
bool hasPoint(std::string convert) {
	for (size_t i = 0; i < convert.length(); i++) {
		if (convert[i] == '.' && convert[i + 1] != '0')
			return true;
	}
	return false;
}

void ScalarConverter::displayError() {}

void ScalarConverter::displayChar(std::string convert) {
	(void) convert;
}

void ScalarConverter::displayInt(std::string convert) {
	(void) convert;
}

void ScalarConverter::displayFloat(std::string convert) {
	float f = atof(convert.c_str());
	bool has_point = hasPoint(convert);
	if (isPseudoLiteral(convert)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << convert << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}

	// Print char
	if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min() || f < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(f) << "\'" << std::endl;

	// Print int
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "(overflowed) int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	// Print float
	if (f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::min())
		std::cout << "(overflowed) float: " << f << std::endl;
	else {
		if (has_point)
			std::cout << "float: " << f << "f" << std::endl;
		else
			std::cout << "float: " << f << ".0f" << std::endl;
	}

	// Print double
	if (f > std::numeric_limits<double>::max() || f < std::numeric_limits<double>::min())
		std::cout << "(overflowed) double: " << f << std::endl;
	else {
		if (has_point)
			std::cout << "double: " << static_cast<double>(f) << std::endl;
		else
			std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	}
}

void ScalarConverter::displayDouble(std::string convert) {
	double d = atof(convert.c_str());
	bool has_point = hasPoint(convert);
	if (isPseudoLiteral(convert)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << d << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return ;
	}

	// Print char
	if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min() || d < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(d) << "\'" << std::endl;

	// Print int
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "(overflowed) int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	
	// Print float
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		std::cout << "(overflowed) float: " << static_cast<float>(d) << std::endl;
	else {
		if (has_point)
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	}

	// Print double
	if (d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::min())
		std::cout << "(overflowed) double: " << d << std::endl;
	else {
		if (has_point)
			std::cout << "double: " << d << std::endl;
		else
			std::cout << "double: " << d << ".0" << std::endl;
	}
}

void ScalarConverter::displayException(std::string convert) {
	(void) convert;
}

std::ostream &operator<<(std::ostream &stream, Type type) {
	if (type == CHAR)
		stream << "type: char\n";
	else if (type == INT)
		stream << "type: int\n";
	else if (type == FLOAT)
		stream << "type: float\n";
	else if (type == DOUBLE)
		stream << "type: double\n";
	else if (type == EXCEPTION)
		stream << "type: exception\n";
	else if (type == ERROR)
		stream << "Invalid input\n";
	return stream;
}
