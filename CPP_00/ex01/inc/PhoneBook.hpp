/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:33:00 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/05/11 11:00:52 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		total;
		int		i;
	public:
		PhoneBook();
		void	addContact();
		void	searchContact();
		void	showInstructions();
		void	displayPhoneBook();
		int		validSearch(std::string input);
};

#endif
