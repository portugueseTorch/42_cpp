#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string db, std::string infile) {
	_db.open(db);
	if (!_db.is_open())
		throw FileOpenException();

	_infile.open(infile);
	if (!_infile.is_open())
		throw FileOpenException();
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {}

// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {}

BitcoinExchange::~BitcoinExchange() {
	if (_infile.is_open())
		_infile.close();
	if (_db.is_open())
		_db.close();
}

//////////////  SETTERS  //////////////
void BitcoinExchange::setInfile(std::string infile) {
	_infile.open(infile);
	if (!_infile.is_open())
		throw FileOpenException();
}

void BitcoinExchange::setDB(std::string db) {
	_db.open(db);
	if (!_db.is_open())
		throw FileOpenException();
}

///////////////////////////////////////

void BitcoinExchange::parseData() {
	std::string line;
	char *date;
	char *value;

	while (std::getline(_db, line)) {
		date = strtok(const_cast<char *>(line.c_str()), ",");
		value = strtok(NULL, ",");
		if (!date || !value)
			continue ;
		
	}
}

//////////////  EXCEPTIONS  //////////////
const char *BitcoinExchange::FileOpenException::what() const throw() {
	return "Error: could not open file.";
}
