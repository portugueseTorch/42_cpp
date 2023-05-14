/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:14:21 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/13 19:31:31 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main() {
	int		horde_size;
	Zombie	*horde;

	// Allocates memory for 10 Zombie instances
	horde_size = 10;
	horde = zombieHorde(horde_size, "Random horde member");

	// Free the memory allocated for the horde
	delete[] horde;

	return 0;
}
