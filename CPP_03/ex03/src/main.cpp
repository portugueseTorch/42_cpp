#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int	main() {
	ClapTrap Joca("Joca");
	ScavTrap Zeca("Zeca");
	FragTrap Lola("Lola");
	DiamondTrap Dudu("Dudu");

	std::cout << std::endl;

	std::cout << Joca << std::endl;
	std::cout << Zeca << std::endl;
	std::cout << Lola << std::endl;
	std::cout << Dudu << std::endl;

	Joca.attack(Joca.getName());
	Joca.takeDamage(Joca.getAttackDamage());
	std::cout << std::endl;

	Zeca.attack(Zeca.getName());
	Zeca.takeDamage(Zeca.getAttackDamage());
	std::cout << std::endl;

	Lola.attack(Lola.getName());
	Lola.takeDamage(Lola.getAttackDamage());
	std::cout << std::endl;

	Zeca.attack(Joca.getName());
	Joca.takeDamage(Zeca.getAttackDamage());
	Lola.attack(Zeca.getName());
	Zeca.takeDamage(Lola.getAttackDamage());
	std::cout << std::endl;

	Zeca.guardGate();
	Zeca.guardGate();
	std::cout << std::endl;

	Lola.highFivesGuys();
	std::cout << std::endl;

	std::cout << Joca << std::endl;
	std::cout << Zeca << std::endl;
	std::cout << Lola << std::endl;
	return 0;
}