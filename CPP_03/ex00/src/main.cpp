#include "../inc/ClapTrap.hpp"

int	main() {
	ClapTrap Joca("Joca");
	ClapTrap Zeca("Zeca");

	Joca.setAttackDamage(3);
	Zeca.setAttackDamage(4);

	std::cout << std::endl;

	std::cout << Joca << std::endl;
	std::cout << Zeca << std::endl;

	Joca.attack(Joca.getName());
	Joca.takeDamage(Joca.getAttackDamage());
	std::cout << std::endl;
	Zeca.attack(Joca.getName());
	Joca.takeDamage(Zeca.getAttackDamage());
	std::cout << std::endl;
	Zeca.attack(Joca.getName());
	Joca.takeDamage(Zeca.getAttackDamage());
	std::cout << std::endl;
	Zeca.attack(Joca.getName());
	Joca.takeDamage(Zeca.getAttackDamage());
	std::cout << std::endl;
	Joca.beRepaired(5);
	std::cout << std::endl;
	Joca.attack(Zeca.getName());
	Zeca.takeDamage(Joca.getAttackDamage());
	std::cout << std::endl;
	Joca.attack(Zeca.getName());
	Zeca.takeDamage(Joca.getAttackDamage());
	std::cout << std::endl;
	Joca.attack(Zeca.getName());
	Zeca.takeDamage(Joca.getAttackDamage());
	std::cout << std::endl;
	Joca.attack(Zeca.getName());
	Zeca.takeDamage(Joca.getAttackDamage());
	std::cout << std::endl;

	return 0;
}