/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:54:38 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/05/14 18:00:52 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		const std::string	&getType();
		void				setType(std::string type);

	private:
		std::string	_type;
};

#endif
