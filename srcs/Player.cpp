#include "header.hpp"

Player::Player(void) : Vessel() {
	this->_x = 5;
	this->_y = MAX_H;
	this->_chp = 3;
	this->_score = 0;
	this->_dmg = 1;
	this->_armor = 0;
}

Player & Player::operator=(Player const & src) {
	this->_x = src.getX();
	this->_y = src.getY();
	this->_chp = src.getChp();
	this->_score = src.getScore();
	this->_dmg = src.getDmg();
	this->_armor = src.getArmor();

	return (*this);
}

Player::Player(Player const & src) {
	*this = src;
}

Player::~Player(void) {
	std::cout << "Player dead" << std::endl;
	return;
}

void Player::collision() {
	std::cout << "new collison" << std::endl;
}

void Player::shoot() {
	std::cout << "player shooted" << std::endl;
}

int Player::getScore() const {
	return this->_score;
}

void Player::setScore(int amount) {
	this->_score = amount;
}
