/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:03:54 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/31 09:59:08 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
{
	this->id = 0;
	this->num_contacts = 0;
}

void	PhoneBook::DisplayPhoneBook()
{
	cout << endl;
	cout << "/###########################################\\" << endl;
	for (int i = 0; i < this->num_contacts; i++)
	{
		cout << "|         " << i + 1 << "|";
		this->contacts[i].DisplayFormatted();
		if (i < this->num_contacts - 1)
			cout << "|-------------------------------------------|" << endl;
	}
	cout << "\\###########################################/" << endl;
	cout << endl;
}

void	set_info(string &buffer, const char *field)
{
	while (true)
	{
		cout << field << ": ";
		getline(cin, buffer);
		if (buffer.empty())
			cout << "This field cannot be left empty." << endl;
		else
			break ;
	}
}

/* Adds a contact to the Phone Book */
void	PhoneBook::AddContact()
{
	string	input;

	if (this->num_contacts == 7)
		this->id = this->num_contacts % 7;
	else
		this->num_contacts++;

	// Set first name;
	set_info(input, "First Name");
	this->contacts[this->id].setFirstName(input);

	// Set last name;
	set_info(input, "Last Name");
	this->contacts[this->id].setLastName(input);

	// Set nickname;
	set_info(input, "Nickname");
	this->contacts[this->id].setNickname(input);

	// Set phone number;
	set_info(input, "Phone Number");
	this->contacts[this->id].setPhoneNumber(input);

	// Set darkest secret;
	set_info(input, "Darkest Secret");
	this->contacts[this->id].setDarkestSecret(input);
	this->id++;
}

/*  */
void	PhoneBook::SearchContact()
{
	return ;
}
