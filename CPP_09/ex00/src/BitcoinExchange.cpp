#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string db, std::string infile) {
	_db.open(db.c_str());
	if (!_db.is_open())
		throw FileOpenException();

	_infile.open(infile.c_str());
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
	_infile.open(infile.c_str());
	if (!_infile.is_open())
		throw FileOpenException();
}

void BitcoinExchange::setDB(std::string db) {
	_db.open(db.c_str());
	if (!_db.is_open())
		throw FileOpenException();
}

///////////////////////////////////////

void BitcoinExchange::parseData() {
	std::string line;
	char *date;
	char *value;
	float rate;
	size_t pos;

	while (!_db.eof()) {
		// Read line and check not empty
		std::getline(_db, line);
		if (line.empty())
			continue ;

		// Find ',' 
		pos = line.find(",");
		date = strtok(const_cast<char *>(line.c_str()), ",");
		value = strtok(NULL, ",");
		if (!validDate(date)) {
			std::cerr << "Invalid date: " << date << std::endl;
			throw InvalidDateException();
		}
		if (!validRate(value)) {
			std::cerr << "Invalid date: " << date << std::endl;
			throw InvalidRateException();
		}
		rate = atof(value);
		_data.insert(_data.begin(), std::pair<std::string,float>(date, rate));
	}
	std::map<std::string,float>::iterator it = _data.begin();
	std::map<std::string,float>::iterator ite = _data.end();
	for (; it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;
}

//////////////  EXCEPTIONS  //////////////
const char *BitcoinExchange::FileOpenException::what() const throw() {
	return "Error: could not open file.";
}

const char *BitcoinExchange::InvalidDateException::what() const throw() {
	return "Error: invalid database date.";
}

const char *BitcoinExchange::InvalidRateException::what() const throw() {
	return "Error: invalid database exchange rate.";
}

//////////////////////////////////////////
bool BitcoinExchange::validDate(std::string date) {
	(void) date;
	return true;
}

bool BitcoinExchange::validRate(std::string rate) {
	(void) rate;
	return true;
}

