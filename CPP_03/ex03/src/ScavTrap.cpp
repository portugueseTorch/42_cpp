#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
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
	} else {
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

std::string ScavTrap::getName() const {
	return _name;
}

std::ostream &operator<<(std::ostream &stream, const ScavTrap &obj) {
	if (obj.getHitPoints() < 1) {
		std::cout << obj.getName() << " is extremely dead..." << std::endl;
		return stream;
	}
	stream << "Oi bomboca, daqui fala " << obj.getName() << std::endl;
	stream << "Hit Points: " << obj.getHitPoints() << std::endl;
	stream << "Energy Points: " << obj.getEnergyPoints() << std::endl;
	stream << "Attack Damage: " << obj.getAttackDamage() << std::endl;
	return stream;
}
