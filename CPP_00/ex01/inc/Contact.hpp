/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:05:00 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/31 09:30:34 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

using namespace std;

class Contact
{
	private:
		string	FirstName;
		string	LastName;
		string	Nickname;
		string	PhoneNumber;
		string	DarkestSecret;

	public:
		void	setFirstName(string FirstName);
		void	setLastName(string LastName);
		void	setNickname(string Nickname);
		void	setPhoneNumber(string PhoneNumber);
		void	setDarkestSecret(string DarkestSecret);

		void	DisplayContactInfo();
		void	DisplayFormatted();
};

#endif