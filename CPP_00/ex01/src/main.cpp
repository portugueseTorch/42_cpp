/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:39:05 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/05/11 11:38:34 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include <iostream>
#include <algorithm>

int	main() {
	PhoneBook	phonebook;
	std::string	input;

	phonebook.showInstructions();
	while (1) {
		std::cout << "\n> ";
		std::getline(std::cin, input);
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);

		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break ;
		else {
			std::cout << RED_TEXT << "Error: Invalid input" << RESET_TEXT << std::endl;
			phonebook.showInstructions();
		}
	}
	std::cout << BLUE_TEXT << "QUITTING..." << RESET_TEXT << std::endl;
	return 0;
}