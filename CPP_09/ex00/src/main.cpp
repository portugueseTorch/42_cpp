#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream in_file;
	try {
		BitcoinExchange btc("data.csv", argv[1]);
		btc.buildDataBase();
		btc.engine();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}