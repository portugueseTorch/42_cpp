#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	std::ifstream in_file;
	BitcoinExchange btc;

	if (argc != 2)
		return 1;
	in_file.open(argv[1]);
	if (!in_file.is_open()) {
		std::cout << "Error: unable to open file " << argv[1] << std::endl;
		return 1;
	}
	btc.parseData(in_file);
}