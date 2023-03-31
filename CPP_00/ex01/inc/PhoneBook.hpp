/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:04:52 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/31 09:58:09 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <Contact.hpp>

using namespace std;

class PhoneBook
{
	private:
		int		id;
		int		num_contacts;
		Contact	contacts[8];

	public:
		PhoneBook();

		void	AddContact();
		void	SearchContact();
		void	ValidateInput();

		void	ShowInstructions();
		void	DisplayPhoneBook();
};

#endif
