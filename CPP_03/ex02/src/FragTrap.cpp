#include "../inc/FragTrap.hpp"

FragTrap::FragTrap(const std::string name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for "<< _name << std::endl;
}

void	FragTrap::highFivesGuys() {
	if (_hitPoints < 1 || _energyPoints < 1) {
		std::cout << _name << " can't high five anyone in this condition" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << _name << " requests the highest of fives!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_energyPoints < 1) {
		std::cout << _name << " is not strong enough to attack..." << std::endl;
		return ;
	} else if (_hitPoints < 1) {
		std::cout << _name << " is dead, he cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	if (target == _name)
		std::cout << "FragTrap " << _name << " attacked himself suffering " << _attackDamage << " points of damage. What an Idiot." << std::endl;
	else
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
