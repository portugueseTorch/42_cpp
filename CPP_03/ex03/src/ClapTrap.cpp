#include "../inc/ClapTrap.hpp"

////// CONSTRUCTORS AND DESTRUCTORS //////
ClapTrap::ClapTrap(): _name(""), _hitPoints(40), _energyPoints(10), _attackDamage(20) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(40), _energyPoints(10), _attackDamage(20) {
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
	*this = obj;
	std::cout << _name << " has awaken via copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
	if (this == &obj)
		return *this;
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	std::cout << _name << " has awaken via assignment operator" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for "<< _name << std::endl;
}

////// GETTERS AND SETTERS //////
std::string	ClapTrap::getName() const {
	return _name;
}

int	ClapTrap::getHitPoints() const {
	return _hitPoints;
}

int	ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

int	ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

void ClapTrap::setName(const std::string &name) {
	_name = name;
}

void ClapTrap::setHitPoints(int hitPoints) {
	_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
	_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {
	_attackDamage = attackDamage;
}

/////////////////////////////////
void ClapTrap::attack(const std::string& target) {
	if (_energyPoints < 1) {
		std::cout << _name << " is not strong enough to attack..." << std::endl;
		return ;
	} else if (_hitPoints < 1) {
		std::cout << _name << " is dead, he cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	if (target == _name)
		std::cout << _name << " attacked himself suffering " << _attackDamage << " points of damage. What an Idiot." << std::endl;
	else
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == -1) {
		std::cout << "Oh good Lord stop it, " << _name << " is already dead!" << std::endl;
		return ;
	}
	if (_hitPoints <= (signed int) amount) {
		std::cout << _name << " got hit with " << amount << " damage points and has died :c" << std::endl;
		_hitPoints = -1;
		return ;
	}
	_hitPoints -= amount;
	std::cout << _name << " has taken " << amount << " points of damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints < 1) {
		std::cout << _name << " is not strong enough to be repaired." << std::endl;
		return ;
	}
	if (_hitPoints < 1) {
		std::cout << _name << " is already dead and therefore cannot be repaired" << std::endl;
		return ;
	}
	std::cout << _name << " has received " << amount << " hit points back!" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}

std::ostream &operator<<(std::ostream &stream, const ClapTrap &obj) {
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
