/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:41:20 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/13 19:51:40 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main() {
	std::string	original = "HI THIS IS BRAIN";
	std::string	*stringPTR = &original;
	std::string	&stringREF = original;

	std::cout << &original << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << original << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}