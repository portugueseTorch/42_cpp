#include "../inc/RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: please provide a single expression" << std::endl;
		return EXIT_FAILURE;
	}

	RPN rpn(argv[1]);
	rpn.calculate();

	// {
	// 	RPN rpn2;
	// 	rpn2.setExpression(argv[1]);
	// 	rpn2.calculate();
	// }
	return 0;
}