#include "Object.hpp"

Object::Object(void) : _chp(0), _x(1), _y(1), _dmg(1), _type("obstacle") {
	return;
}

Object::Object(int x, int y, std::string type) : _chp(1), _x(x), _y(y), _type(type) {
	this->_dmg = 1;
	return ;
}

Object & Object::operator=(Object const & src) {
	this->_chp = src.getChp();
	this->_x = src.getX();
	this->_y = src.getY();
	this->_dmg = src.getDmg();
	this->_type = src.getType();
	return (*this);
}

Object & Object::operator+=(int amount) {
	this->_y = this->_y + amount;
	return (*this);
}

Object & Object::operator-=(int amount) {
	this->_y = this->_y - amount;
	return (*this);
}

Object::Object(Object const & src) {
	*this = src;
	return ;
}

Object::~Object(void) {
	return ;
}

void Object::collision(void)
{
	std::cout << "object collision" << std::endl;
}

int Object::getChp() const {
	 return this->_chp;
 }

int Object::getX() const {
	return this->_x;
}

int Object::getY() const {
	return this->_y;
}

int Object::getDmg() const {
	return this->_dmg;
}

std::string Object::getType() const {
	return this->_type;
}

void Object::setChp(int amount) {
	this->_chp = amount;
}

void Object::setX(int amount) {
	this->_x = amount;
}

void Object::setY(int amount) {
	this->_y = amount;
}

void Object::setDmg(int amount) {
	this->_dmg = amount;
}

void Object::setType(std::string t) {
	this->_type = t;
}
