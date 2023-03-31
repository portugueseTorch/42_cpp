/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:46:42 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/30 18:01:31 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <PhoneBook.hpp>

int	main()
{
	PhoneBook	phone;
	string		input;

	phone.AddContact();
	phone.AddContact();
	phone.DisplayPhoneBook();
	return (0);
}