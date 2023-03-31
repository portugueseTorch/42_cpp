/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:29:37 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/31 09:36:17 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

/* Sets the first name of the Contact */
void	Contact::setFirstName(string FirstName)
{
	this->FirstName = FirstName;
}

/* Sets the last name of the Contact */
void	Contact::setLastName(string LastName)
{
	this->LastName = LastName;
}

/* Sets the nickname of the Contact */
void	Contact::setNickname(string Nickname)
{
	this->Nickname = Nickname;
}

/* Sets the phone number of the Contact */
void	Contact::setPhoneNumber(string PhoneNumber)
{
	this->PhoneNumber = PhoneNumber;
}

/* Sets the darkest secret of the Contact */
void	Contact::setDarkestSecret(string DarkestSecret)
{
	this->DarkestSecret = DarkestSecret;
}

/* Displays the contact info with one field per line */
void	Contact::DisplayContactInfo()
{
	cout << "First Name: " << this->FirstName;
	cout << "Last Name: " << this->LastName;
	cout << "Nickname: " << this->Nickname;
	cout << "Phone Number: " << this->PhoneNumber;
	cout << "Darkest Secret: " << this->DarkestSecret;
}

void	display_aux(string info)
{
	int	length;

	length = info.length();
	if (length > 10)
		cout << info.substr(0, 9) << ".|";
	else
	{
		for (int i = 0; i < 10 - length; i++)
			cout << " ";
		cout << info << "|";
	}
}

/* Displays the contact formatted for the PhoneBook display */
void	Contact::DisplayFormatted()
{
	display_aux(this->FirstName);
	display_aux(this->LastName);
	display_aux(this->Nickname);
	cout << endl;
}
