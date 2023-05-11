/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:54:53 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/05/11 11:32:52 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

void	Contact::setFirstName(std::string first_name) {
	this->_first_name = first_name;
}

void	Contact::setLastName(std::string last_name) {
	this->_last_name = last_name;
}

void	Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number) {
	this->_phone_number = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret) {
	this->_darkest_secret = darkest_secret;
}

/* Displays the contact formatted for the PhoneBook display */
void	Contact::displayFormatted() {
	display_aux(this->_first_name);
	display_aux(this->_last_name);
	display_aux(this->_nickname);
	std::cout << std::endl;
}

void	Contact::displayContactInfo() {
	std::cout << GREEN_TEXT << "\nFirst Name: " << this->_first_name << std::endl;
	std::cout << "Last Name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest_secret << RESET_TEXT << std::endl;
}
