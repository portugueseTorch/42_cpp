/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:11:10 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/18 13:32:56 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <exception>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		~Zombie();
		void	annouce( void );
		void	setName(std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif
