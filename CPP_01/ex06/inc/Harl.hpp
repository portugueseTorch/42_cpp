/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:29:24 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/05/18 17:35:33 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <exception>

class Harl
{
	public:
		Harl();
		~Harl();
		void complain( std::string level );
		void filter( std:: string level);
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
