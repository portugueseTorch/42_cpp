#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int	main() {
	DiamondTrap Dudu("Dudu");

	std::cout << std::endl;

	std::cout << Dudu << std::endl;
	Dudu.whoAmI();
	std::cout << std::endl;
	Dudu.attack("Dudu");
	std::cout << std::endl;
	Dudu.guardGate();
	std::cout << std::endl;
	Dudu.highFivesGuys();
	std::cout << std::endl;

	return 0;
}