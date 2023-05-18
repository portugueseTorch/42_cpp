/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:54:46 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/18 13:08:16 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::attack() {
	std::string	weapon = "bare hands";
	if (_weapon)
		weapon = _weapon->getType();
	std::cout << _name << " attacks with their " << weapon << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
