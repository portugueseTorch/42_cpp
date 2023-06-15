#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <string.h>
# include <string>
# include <cstring>
# include <fstream>
# include <time.h>

# define debug(x) std::cout << x << std::endl;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string db, std::string infile);
		// BitcoinExchange(const BitcoinExchange &obj);
		// BitcoinExchange &operator=(const BitcoinExchange &obj);
		~BitcoinExchange();

		void parseData();
		void buildData();

		void setInfile(std::string infile);
		void setDB(std::string db);

		// EXCEPTIONS
		class FileOpenException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidDateException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidRateException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::map<std::string,float> _data;
		std::ifstream _infile;
		std::ifstream _db;

		static bool validDate(std::string date);
		static bool validRate(std::string rate);
};

#endif
