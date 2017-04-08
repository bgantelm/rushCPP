#include "header.hpp"

Enemy::Enemy(void) : Vessel() {
	this->setType(this->getRandomType());
	this->_x = 5;
	this->_y = 1;
	this->_chp = 0;
	this->_dmg = 1;
	this->_armor = 0;
	if (this->printType() == ENEMY_STRONGER)
		this->_dmg = 2;
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
	std::string type = this->printType();
	if (type == ENEMY_DEFAULT)
	{
		switch ( random() % 20 )
		{
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
	else if (type == ENEMY_FASTER)
	{
		switch ( random() % 4 )
		{
			case		1:
				if ( this->getX() - 2 > 0 )
					this->setX( this->getX() - 2 );
				break;
			case		2:
				if ( this->getX() + 2 < MAX_W )
					this->setX( this->getX() + 2 );
				break;
			default:
				break;
		}
	}
}

std::string Enemy::getRandomType()
{
	int type = random() % 3;
	switch (type)
	{
		case	0:
			return (ENEMY_DEFAULT);
		break;

		case	1:
			return (ENEMY_FASTER);
		break;

		case	2:
			return (ENEMY_STRONGER);
		break;
		
		default:
			return (ENEMY_DEFAULT);
		break;
	}
	return (ENEMY_DEFAULT);
}

std::string Enemy::printType() const
{
	return (this->type);
}

void Enemy::setType(std::string type)
{
	this->type = type;
}

void Enemy::shoot(Object *objs)
{
	col::createObject(objs, this->getX(), this->getY() + 1, "eShot");
}
