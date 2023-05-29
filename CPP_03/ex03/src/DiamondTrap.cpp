#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name) {
	_name = name + "_clap_name";
	_hitPoints = FragTrap::getHitPoints();
	_energyPoints = ScavTrap::getEnergyPoints();
	_attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::~DiamondTrap() {}
