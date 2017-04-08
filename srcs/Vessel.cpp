#include "Vessel.hpp"

Vessel::Vessel(void) {
	return;
}

Vessel & Vessel::operator=(Vessel const & src) {
	this->_chp = src._chp;
	return (*this);
}

Vessel::Vessel(Vessel const & src) {
	*this = src;
	return ;
}

Vessel::~Vessel(void) {
	return ;
}

void Vessel::collision() {
	std::cout << "collision" << std::endl;
}

int Vessel::getDmg() const{
	return this->_dmg;
}

int Vessel::getArmor() const {
	return this->_armor;
}

int Vessel::getX() const {
	return this->_x;
}

int Vessel::getY() const {
	return this->_y;
}

int Vessel::getChp() const {
	return this->_chp;
}


void Vessel::setDmg(int amount) {
	this->_dmg = amount;
}

void Vessel::setArmor(int amount) {
	this->_armor = amount;
}

void Vessel::setX(int amount) {
	this->_x = amount;
}

void Vessel::setY(int amount) {
	this->_y = amount;
}

void Vessel::setChp(int amount) {
	this->_chp = amount;
}
