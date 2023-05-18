/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:29:56 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/05/18 17:40:26 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int	main(int argc, char **argv) {
	Harl	test;

	if (argc != 2)
	{
		std::cerr << "Error: usage: ./harlFilter __complain_level__" << std::endl;
		return 1;		
	}
	test.filter(argv[1]);
	return 0;
}