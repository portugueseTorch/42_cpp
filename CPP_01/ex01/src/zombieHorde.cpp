/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:10:30 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/18 14:43:22 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie	*horde;
	
	try {
		horde = new Zombie[N];
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (NULL);
	}

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
		horde[i].annouce();
	}

	return horde;
}