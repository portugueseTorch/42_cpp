#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
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

std::string FragTrap::getName() const {
	return _name;
}

std::ostream &operator<<(std::ostream &stream, const FragTrap &obj) {
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
