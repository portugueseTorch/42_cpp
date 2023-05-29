#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: virtual public FragTrap, virtual public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &obj);
		DiamondTrap &operator=(const DiamondTrap &obj);
		~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI();
		std::string getName() const;
	private:
		std::string _name;
};

std::ostream &operator<<(std::ostream &stream, const DiamondTrap &obj);

#endif
