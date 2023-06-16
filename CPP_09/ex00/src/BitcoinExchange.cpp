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
	if (_infile.is_open())
		_infile.close();
	_infile.open(infile.c_str());
	if (!_infile.is_open())
		throw FileOpenException();
}

void BitcoinExchange::setDB(std::string db) {
	if (_db.is_open())
		_db.close();
	_db.open(db.c_str());
	if (!_db.is_open())
		throw FileOpenException();
}

///////////////////////////////////////

void BitcoinExchange::buildDataBase() {
	std::string line;
	std::string date;
	std::string value;
	float rate;
	size_t pos;

	// Check db is open
	if (!_db.is_open())
		throw FileOpenException();

	// Skip first line
	std::getline(_db, line);
	while (!_db.eof()) {
		// Read line and check not empty
		std::getline(_db, line);
		if (line.empty())
			continue ;

		// Find ',' and use substr to get date and value
		pos = line.find(",");
		if (pos == std::string::npos) {
			std::cerr << "Incomplete entry: " << line << std::endl;
			throw DBIncompleteDataException();
		}
		date = line.substr(0, pos);
		value = line.substr(pos + 1);
		if (!validDate(date)) {
			std::cerr << "Invalid date: " << date << std::endl;
			throw DBInvalidDateException();
		}
		if (!validRate(value)) {
			std::cerr << "Invalid rate: " << value << std::endl;
			throw DBInvalidRateException();
		}

		// If both valid, insert the pair
		rate = atof(value.c_str());
		_data.insert(_data.begin(), std::pair<std::string,float>(date, rate));
	}
}

void BitcoinExchange::engine() {
	std::string line;
	std::string date;
	std::string factor;
	size_t pos;
	float rate;
	float f;

	// Check infile is open
	if (!_infile.is_open())
		throw FileOpenException();

	// Skip first line
	std::getline(_infile, line);
	while (!_infile.eof()) {
		// Read line and check not empty
		std::getline(_infile, line);
		if (line.empty()) {
			std::cout << "Error: empty line." << std::endl;
			continue;
		}

		// Find " | " and use substr to get date and factor
		pos = line.find(" | ");
		if (pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, pos);
		factor = line.substr(pos + 3);
		if (!validDate(date)) {
			std::cout << "Error: not a valid date => " << date << std::endl;
			continue;
		}
		if (!validInputFactor(factor))
			continue;
		f = atof(factor.c_str());
		if (_data.find(date) != _data.end())
			rate = _data.lower_bound(date)->second;
		else if (_data.lower_bound(date) != _data.begin()) {
			rate = (--_data.lower_bound(date))->second;
		} else {
			std::cout << "Error: date older than db => " << date << std::endl;
			continue;
		}
		std::cout << date << " => " << factor << " = " << f * rate << std::endl;
	}
}

void BitcoinExchange::displayMap() {
	std::map<std::string,float>::iterator it = _data.begin();
	std::map<std::string,float>::iterator ite = _data.end();
	for (; it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;
}

//////////////  EXCEPTIONS  //////////////
const char *BitcoinExchange::FileOpenException::what() const throw() {
	return "Error: could not open file.";
}

const char *BitcoinExchange::DBInvalidDateException::what() const throw() {
	return "Error: invalid database date.";
}

const char *BitcoinExchange::DBInvalidRateException::what() const throw() {
	return "Error: invalid database exchange rate.";
}

const char *BitcoinExchange::DBIncompleteDataException::what() const throw() {
	return "Error: incomplete database entry.";
}

//////////////  VALID INPUT  //////////////
bool BitcoinExchange::validDate(std::string date) {
	struct tm time;
	if (date.size() != 10)
		return false;
	
	// Attempt to convert string into date with format YYYY-MM-DD
	if (!strptime(date.c_str(), "%Y-%m-%d", &time))
		return false;
	int year = time.tm_year + 1900;
	int month = time.tm_mon + 1;
	int day = time.tm_mday;

	// Check February in a leap year
	if (month == 2) {
		bool leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if ((leap_year && day > 29) || (!leap_year && day > 28))
			return false;
	}

	// Check 30-day months
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	return true;
}

bool BitcoinExchange::validRate(std::string rate) {
	// Check invalid characters
	if (rate.find_first_not_of("0123456789+-ef.") != std::string::npos)
		return false;

	// Check multiple +-ef.
	if (rate.find_first_of('+') != rate.find_last_of('+') || \
		rate.find_first_of('-') != rate.find_last_of('-') || \
		rate.find_first_of('e') != rate.find_last_of('e') || \
		rate.find_first_of('f') != rate.find_last_of('f') || \
		rate.find_first_of('.') != rate.find_last_of('.'))
		return false;
	return true;
}

bool BitcoinExchange::validInputFactor(std::string factor) {
	if (factor.find_first_not_of("0123456789+-ef.") != std::string::npos)
		return false;

	// Check multiple +-ef.
	if (factor.find_first_of('+') != factor.find_last_of('+') || \
		factor.find_first_of('-') != factor.find_last_of('-') || \
		factor.find_first_of('e') != factor.find_last_of('e') || \
		factor.find_first_of('f') != factor.find_last_of('f') || \
		factor.find_first_of('.') != factor.find_last_of('.'))
		return false;

	// Check bounds
	float f = atof(factor.c_str());
	if (f < 0.0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (f > 1000.0) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}
