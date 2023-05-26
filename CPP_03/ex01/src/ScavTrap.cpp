#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guarding = false;
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for "<< _name << std::endl;
}

void ScavTrap::guardGate() {
	if (_guarding == false) {
		_guarding = true;
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	}
	else {
		_guarding = false;
		std::cout << "ScavTrap " << _name << " has left Gate keeper mode" << std::endl;
	}
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints < 1) {
		std::cout << _name << " is not strong enough to attack..." << std::endl;
		return ;
	} else if (_hitPoints < 1) {
		std::cout << _name << " is dead, he cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	if (target == _name)
		std::cout << "ScavTrap " << _name << " attacked himself suffering " << _attackDamage << " points of damage. What an Idiot." << std::endl;
	else
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
