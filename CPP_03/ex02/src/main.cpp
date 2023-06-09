#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int	main() {
	ClapTrap Joca("Joca");
	ScavTrap Zeca("Zeca");
	FragTrap Lulu("Lulu");

	std::cout << std::endl;

	std::cout << Joca << std::endl;
	std::cout << Zeca << std::endl;
	std::cout << Lulu << std::endl;

	Joca.attack(Joca.getName());
	Joca.takeDamage(Joca.getAttackDamage());
	std::cout << std::endl;

	Zeca.attack(Zeca.getName());
	Zeca.takeDamage(Zeca.getAttackDamage());
	std::cout << std::endl;

	Lulu.attack(Lulu.getName());
	Lulu.takeDamage(Lulu.getAttackDamage());
	std::cout << std::endl;

	Zeca.attack(Joca.getName());
	Joca.takeDamage(Zeca.getAttackDamage());
	Lulu.attack(Zeca.getName());
	Zeca.takeDamage(Lulu.getAttackDamage());
	std::cout << std::endl;

	Zeca.guardGate();
	Zeca.guardGate();
	std::cout << std::endl;

	Lulu.highFivesGuys();
	std::cout << std::endl;

	std::cout << Joca << std::endl;
	std::cout << Zeca << std::endl;
	std::cout << Lulu << std::endl;
	return 0;
}