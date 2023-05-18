/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:29:20 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/05/18 17:32:56 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::complain(std::string level) {
	for (int i = 0; level[i]; i++)
		level[i] = tolower(level[i]);

	std::string codes[4] = { "debug", "info", "warning", "error" };
	void (Harl::*func_array[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (int i = 0; i < 4; i++)
	{
		if (codes[i] == level) {
			(this->*func_array[i])();
			return ;
		}
	}
	std::cerr << "Error: invalid level \'" << level << "\'" << std::endl;
}

void	Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put" << \
	" enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for" << \
	"years whereas you started working here since last month." << std::endl;
}

void	Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
