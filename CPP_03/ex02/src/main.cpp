#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main() {
	ClapTrap Joca("Joca");
	ScavTrap Zeca("Zeca");

	std::cout << std::endl;

	std::cout << Joca << std::endl;
	std::cout << Zeca << std::endl;

	Joca.attack(Joca.getName());
	Joca.takeDamage(Joca.getAttackDamage());
	std::cout << std::endl;

	Zeca.attack(Zeca.getName());
	Zeca.takeDamage(Zeca.getAttackDamage());
	std::cout << std::endl;

	Zeca.attack(Joca.getName());
	Joca.takeDamage(Zeca.getAttackDamage());
	std::cout << std::endl;

	Zeca.guardGate();
	Zeca.guardGate();
	std::cout << std::endl;

	std::cout << Joca << std::endl;
	std::cout << Zeca << std::endl;
	return 0;
}