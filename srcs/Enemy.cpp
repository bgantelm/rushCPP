#include "header.hpp"

Enemy::Enemy(void) : Vessel() {
	this->_x = 5;
	this->_y = 1;
	this->_chp = 0;
	this->_dmg = 1;
	this->_armor = 0;
}

Enemy::Enemy(int x, int y) : Vessel() {
	this->_x = x;
	this->_y = y;
	this->_chp = 0;
	this->_dmg = 1;
	this->_armor = 0;
	return ;
}

Enemy & Enemy::operator=(Enemy const & src) {
	this->_x = src.getX();
	this->_y = src.getY();
	this->_chp = src.getChp();
	this->_dmg = src.getDmg();
	this->_armor = src.getArmor();

	return (*this);
}

Enemy & Enemy::operator+=(int amount) {
	this->_y = this->_y + amount;
	return (*this);
}

Enemy & Enemy::operator-=(int amount) {
	this->_y = this->_y - amount;
	return (*this);
}

Enemy::Enemy(Enemy const & src) {
	*this = src;
}

Enemy::~Enemy(void) {
	std::cout << "Enemy die" << std::endl;
	return;
}

void Enemy::collision() {
	std::cout << "enemy: new collision action" << std::endl;
}

void Enemy::shoot() {
	std::cout << "enemy shooted" << std::endl;
}

void Enemy::randomMoove() {
	switch ( random() % 20 ) {
		case		1:
			if ( this->getX() - 1 > 0 )
				this->setX( this->getX() - 1 );
			break;
		case		2:
			if ( this->getX() + 1 < MAX_W )
				this->setX( this->getX() + 1 );
			break;
		default:
			break;
	}
}
