/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:10:58 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/13 18:47:30 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << this->_name << " has entered the chat." << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << " out!" << std::endl;
}

void	Zombie::annouce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
