/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:03:59 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/05/11 11:22:19 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include "utils.hpp"

# define RED_TEXT	"\033[0;31m"
# define GREEN_TEXT	"\033[0;32m"
# define GREEN_BOLD	"\033[1;32m"
# define BLUE_TEXT	"\033[0;34m"
# define RESET_TEXT	"\033[0m"

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
	
	public:
		void	setFirstName(std::string first_name);
		void	setLastName(std::string last_name);
		void	setNickname(std::string nickname);
		void	setPhoneNumber(std::string phone_number);
		void	setDarkestSecret(std::string darkest_secret);
		void	displayFormatted();
		void	displayContactInfo();
};

#endif