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
		convert.find_first_of(".") != convert.find_last_of(".") || \
		(!isdigit(convert[0]) && (convert[0] == '-' && !isdigit(convert[1]))) || \
		(!isdigit(convert[0]) && (convert[0] == '+' && !isdigit(convert[1]))))
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
bool needsPoint(float num) {
	return trunc(num) == num;
}

void ScalarConverter::displayError() {}

void ScalarConverter::displayChar(std::string convert) {
	char c = convert[0];
	std::cout << "char: \'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "float: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::displayInt(std::string convert) {
	int i = atoi(convert.c_str());

	// Print char
	if (i > std::numeric_limits<char>::max() || i < -std::numeric_limits<char>::max() || i < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;

	// Print int
	if (i > std::numeric_limits<int>::max() || i < -std::numeric_limits<int>::max())
		std::cout << "(overflowed) int: " << i << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	
	// Print float
	// debug(i);
	// debug(std::numeric_limits<float>::max());
	// debug(std::numeric_limits<float>::max());
	if (i > std::numeric_limits<float>::max() || i < -std::numeric_limits<float>::max())
		std::cout << "(overflowed) float: " << static_cast<float>(i) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;

	// Print double
	if (i > std::numeric_limits<double>::max() || i < -std::numeric_limits<double>::max())
		std::cout << "(overflowed) double: " << static_cast<double>(i) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::displayFloat(std::string convert) {
	float f = atof(convert.c_str());
	bool needs_point = needsPoint(f);
	if (isPseudoLiteral(convert)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << convert << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}

	// Print char
	if (f > std::numeric_limits<char>::max() || f < -std::numeric_limits<char>::max() || f < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(f) << "\'" << std::endl;

	// Print int
	if (f > std::numeric_limits<int>::max() || f < -std::numeric_limits<int>::max())
		std::cout << "(overflowed) int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	// Print float
	if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
		std::cout << "(overflowed) float: " << f << std::endl;
	else {
		if (!needs_point)
			std::cout << "float: " << f << "f" << std::endl;
		else
			std::cout << "float: " << f << ".0f" << std::endl;
	}

	// Print double
	if (f > std::numeric_limits<double>::max() || f < -std::numeric_limits<double>::max())
		std::cout << "(overflowed) double: " << f << std::endl;
	else {
		if (!needs_point)
			std::cout << "double: " << static_cast<double>(f) << std::endl;
		else
			std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	}
}

void ScalarConverter::displayDouble(std::string convert) {
	double d = atof(convert.c_str());
	bool needs_point = needsPoint(d);
	if (isPseudoLiteral(convert)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << d << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return ;
	}

	// Print char
	if (d > std::numeric_limits<char>::max() || d < -std::numeric_limits<char>::max() || d < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(d) << "\'" << std::endl;

	// Print int
	if (d > std::numeric_limits<int>::max() || d < -std::numeric_limits<int>::max())
		std::cout << "(overflowed) int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	
	// Print float
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "(overflowed) float: " << static_cast<float>(d) << std::endl;
	else {
		if (!needs_point)
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	}

	// Print double
	if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
		std::cout << "(overflowed) double: " << d << std::endl;
	else {
		if (!needs_point)
			std::cout << "double: " << d << std::endl;
		else
			std::cout << "double: " << d << ".0" << std::endl;
	}
}

void ScalarConverter::displayException(std::string convert) {
	float e = atof(convert.c_str());
	bool needs_point = needsPoint(e);
	if (isPseudoLiteral(convert)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << convert << std::endl;
		std::cout << "double: " << static_cast<double>(e) << std::endl;
	}

	// Print char
	if (e > std::numeric_limits<char>::max() || e < -std::numeric_limits<char>::max() || e < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(e) << "\'" << std::endl;

	// Print int
	if (e > std::numeric_limits<int>::max() || e < -std::numeric_limits<int>::max())
		std::cout << "(overflowed) int: " << static_cast<int>(e) << std::endl;
	else
		std::cout << "int: " << static_cast<int>(e) << std::endl;
	
	// Print float
	if (e > std::numeric_limits<float>::max() || e < -std::numeric_limits<float>::max())
		std::cout << "(overflowed) float: " << e << std::endl;
	else {
		if (!needs_point)
			std::cout << "float: " << e << "f" << std::endl;
		else
			std::cout << "float: " << e << ".0f" << std::endl;
	}

	// Print double
	if (e > std::numeric_limits<double>::max() || e < -std::numeric_limits<double>::max())
		std::cout << "(overflowed) double: " << e << std::endl;
	else {
		if (!needs_point)
			std::cout << "double: " << static_cast<double>(e) << std::endl;
		else
			std::cout << "double: " << static_cast<double>(e) << ".0" << std::endl;
	}
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
