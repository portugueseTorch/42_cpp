#include "../inc/RPN.hpp"

RPN::RPN(): _expression(""), _result(0) {}

RPN::RPN(std::string expression): _expression(expression), _result(0) {}

RPN::RPN(const RPN &obj) { *this = obj; }

RPN &RPN::operator=(const RPN &obj) {
	if (this == &obj)
		return *this;
	_expression = obj.getExpression();
	_stack = obj.getStack();
	_result = obj.getResult();
	return *this;
}

RPN::~RPN() {}

///////////////////////////////////
void RPN::validateInput(std::string expression) {
	if (expression.empty())
		throw MissingExpressionException();
	if (expression.find_first_not_of("0123456789-+*/ ") != std::string::npos)
		throw ErrorException();
}

/////// GETTERS AND SETTERS ///////
std::string RPN::getExpression() const {
	return _expression;
}

std::stack<int> RPN::getStack() const {
	return _stack;
}

int RPN::getResult() const {
	return _result;
}

void RPN::setExpression(std::string expression) {
	_expression = expression;
}

/////// ENGINE ///////
void RPN::calculate() {
	try {
		validateInput(_expression);
		for (size_t i = 0; i < _expression.size(); i++) {
			if (isdigit(_expression[i]))
				_stack.push(_expression[i] - 48);
			else if (_expression[i] != ' ' && _stack.size() < 2)
				throw ErrorException();
			else
				RPN::performOperation(_expression[i]);
		}
		if (_stack.size() != 1)
			throw ErrorException();
		std::cout << _result << std::endl;
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return ;
	}
}

void RPN::performOperation(char oper) {
	if (oper == ' ')
		return ;
	int b = _stack.top();
	_stack.pop();
	int a = _stack.top();
	_stack.pop();
	switch (oper) {
		case '+':
			_stack.push(a + b);
			break;
		case '-':
			_stack.push(a - b);
			break;
		case '*':
			_stack.push(a * b);
			break;
		default:
			_stack.push(a / b);
	}
	_result = _stack.top();
}

//////////////  EXCEPTIONS  //////////////
const char *RPN::MissingExpressionException::what() const throw() {
	return "Error: missing expression";
}

const char *RPN::ErrorException::what() const throw() {
	return "Error";
}

