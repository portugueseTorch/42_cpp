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
}

void	PhoneBook::DisplayPhoneBook()
{
	cout << endl;
	cout << "#########################################" << endl;
	for (int i = 0; i < this->id; i++)
	{
		cout << "|         " << i + 1 << "|";
		this->contacts[i].DisplayFormatted();
		if (i < this->id - 1)
			cout << "#---------------------------------------#" << endl;
	}
	cout << "#########################################" << endl;
	cout << endl;
}

/* Adds a contact to the Phone Book */
void	PhoneBook::AddContact()
{
	string	input;

	cout << "Name: ";
	getline(cin, input);
	
}
