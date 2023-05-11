/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:12:26 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/11 11:41:42 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Contact.hpp"

void	display_aux(std::string info) {
	int	length;

	length = info.length();
	if (length > 9)
		std::cout << info.substr(0, 9) << ".|";
	else
	{
		for (int i = 0; i < 10 - length; i++)
			std::cout << " ";
		std::cout << info << "|";
	}
}

int	all_whitespaces(std::string input) {
	for (int i = 0; input[i]; i++)
		if (input[i] > 32)
			return 0;
	return 1;
}

int	valid_input(std::string input) {
	if (input.empty() || all_whitespaces(input)) {
		std::cout << RED_TEXT << "Input cannot be empty" << RESET_TEXT << std::endl;
		return 0;
	}
	return 1;
}

int	valid_number(std::string input) {
	for (int i = 0; input[i]; i++) {
		if (!isdigit(input[i])) {
			std::cout << RED_TEXT << "Invalid Phone number" << RESET_TEXT << std::endl;
			return 0;
		}
	}
	return 1;
}
