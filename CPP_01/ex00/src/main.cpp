/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:14:21 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/13 18:51:55 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main() {
	// Allocates memory that needs to be freed before it goes out of scope
	Zombie	*first_guy = newZombie("Dynamic Doug");
	
	// Random Chump is only alive during the duration of the function
	randomChump("Random Chump");

	// Free the memory allocated for Dynamic Doug
	delete first_guy;

	return 0;
}
