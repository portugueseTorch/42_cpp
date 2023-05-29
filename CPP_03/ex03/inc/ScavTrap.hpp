#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
		std::string getName() const;

	private:
		bool _guarding;
};

std::ostream &operator<<(std::ostream &stream, const ScavTrap &obj);

#endif
