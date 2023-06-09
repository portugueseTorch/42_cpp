/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:14:21 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/18 14:43:30 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main() {
	int		horde_size;
	Zombie	*horde;

	// Allocates memory for 10 Zombie instances
	horde_size = 10;
	horde = zombieHorde(horde_size, "Random horde member");
	if (horde == NULL)
		return 1;

	// Free the memory allocated for the horde
	delete[] horde;

	return 0;
}
