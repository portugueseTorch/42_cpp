/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:55:42 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/05/18 16:40:19 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <exception>
#include <string>

void	search_and_replace(std::string &content, std::string search, std::string replace) {
	size_t	occurence;

	occurence = content.find(search, 0);
	while (1)
	{
		if (occurence == std::string::npos)
			return ;
		content.replace(occurence, search.length(), replace);
		occurence = content.find(search, occurence + replace.length());
	}
}

int	main(int argc, char **argv) {
	std::ifstream	in_file;
	std::ofstream	out_file;
	std::string		content;
	std::string		buff;
	std::string		file_name;

	if (argc != 4) {
		std::cerr << "Error: Usage: __file_name__ __search_string__ __replace__" << std::endl;
		return 1;
	}

	// Get file name
	file_name = argv[1];
	file_name.append(".replace");
	// Attempt to open in file
	in_file.open(argv[1]);
	if (!in_file.is_open()) {
		std::cout << "Error: unable to open file " << argv[1] << std::endl;
		return 1;
	}
	// Attempt to open out_file, close infile if it fails
	out_file.open(file_name.c_str(), std::ios::trunc);
	if (!out_file.is_open()) {
		in_file.close();
		std::cout << "Error: unable to open file " << file_name << std::endl;
		return 1;
	}

	while (std::getline(in_file, buff)) {
		content += buff;
		if (!in_file.eof())
			content += "\n";
	}
	search_and_replace(content, argv[2], argv[3]);
	out_file << content;
	return 0;
}
