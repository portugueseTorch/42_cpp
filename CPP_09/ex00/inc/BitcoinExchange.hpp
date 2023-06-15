#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <map>
# include <string.h>
# include <string>
# include <fstream>
# include <cstring>

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

	private:
		std::map<std::string,float> _data;
		std::ifstream _infile;
		std::ifstream _db;
};

#endif
