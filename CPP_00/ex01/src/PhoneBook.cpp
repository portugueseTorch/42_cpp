/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:28:35 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/11 11:35:40 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook() {
	this->i = 0;
	this->total = 0;
}

void	PhoneBook::addContact() {
	std::string	input;

	if (this->i == 8)
		this->i = 0;

	std::cout  << BLUE_TEXT << "First Name: " << RESET_TEXT;
	std::getline(std::cin, input);
	if (!valid_input(input))
		return ;
	this->contacts[i].setFirstName(input);

	std::cout << BLUE_TEXT << "Last Name: " << RESET_TEXT;
	std::getline(std::cin, input);
	if (!valid_input(input))
		return ;
	this->contacts[i].setLastName(input);

	std::cout << BLUE_TEXT << "Nickname: " << RESET_TEXT;
	std::getline(std::cin, input);
	if (!valid_input(input))
		return ;
	this->contacts[i].setNickname(input);

	std::cout << BLUE_TEXT << "Phone Number: " << RESET_TEXT;
	std::getline(std::cin, input);
	if (!valid_input(input) || !valid_number(input))
		return ;
	this->contacts[i].setPhoneNumber(input);

	std::cout << BLUE_TEXT << "Darkest Secret: " << RESET_TEXT;
	std::getline(std::cin, input);
	if (!valid_input(input))
		return ;
	this->contacts[i].setDarkestSecret(input);
	
	this->i++;
	if (this->total < 8)
		this->total++;
}

int	PhoneBook::validSearch(std::string input) {
	long	index;
	
	for (int i = 0; input[i]; i++) {
		if (!isdigit(input[i])) {
			std::cout << RED_TEXT << "Invalid index" << RESET_TEXT << std::endl;
			return 0;
		}
	}
	std::stringstream(input) >> index;
	if (index > this->total || index < 1) {
		std::cout << RED_TEXT << "Invalid index" << RESET_TEXT << std::endl;
		return 0;
	}
	this->contacts[index - 1].displayContactInfo();
	return 1;
}

void	PhoneBook::searchContact() {
	std::string	input;

	if (this->total == 0) {
		std::cout << RED_TEXT << "Your Phonebook is empty!" << RESET_TEXT << std::endl;
		return ;
	}	
	this->displayPhoneBook();
	while (1)
	{
		std::cout << BLUE_TEXT << "Select the desired index: " << RESET_TEXT;
		std::getline(std::cin, input);
		if (this->validSearch(input))
			break ;
	}
}

void	PhoneBook::displayPhoneBook() {
	std::cout << GREEN_BOLD << "\n/     INDEX|FIRST NAME| LAST NAME|  NICKNAME\\";
	std::cout << GREEN_TEXT << "\n|###########################################|" << std::endl;
	for (int i = 0; i < this->total; i++) {
		std::cout << "|         " << i + 1 << "|";
		this->contacts[i].displayFormatted();
		if (i < this->total - 1)
			std::cout << "|-------------------------------------------|" << std::endl;
	}
	std::cout << "\\###########################################/\n" << RESET_TEXT << std::endl;
}

void	PhoneBook::showInstructions() {
	std::cout << GREEN_TEXT << "INSTRUCTIONS" << "\n";
	std::cout << "\tADD - Save a new contact\n\tSEARCH - Display a \
	specific contact\n\tEXIT - Quit Phonebook"  << RESET_TEXT << std::endl;
}
