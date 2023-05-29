#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name){
	FragTrap::_hitPoints = 100;
	FragTrap::_attackDamage = 30;
	_energyPoints = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj): ClapTrap(), FragTrap(), ScavTrap() {
	*this = obj;
	std::cout << _name << " has awaken via copy constructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
	if (this == &obj)
		return *this;
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	std::cout << _name << " has awaken via assignment operator" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getName() const {
	return _name;
}

std::ostream &operator<<(std::ostream &stream, const DiamondTrap &obj) {
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
