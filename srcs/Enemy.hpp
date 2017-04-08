#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Vessel.hpp"
#include "Object.hpp"

class Enemy : public Vessel
{
	public:
		Enemy(void);
		Enemy(int x, int y);
		Enemy(Enemy const & src);
		Enemy & operator=(Enemy const & src);
		virtual ~Enemy(void);

		Enemy & operator+=(int amount);
		Enemy & operator-=(int amount);

		void collision();
		void shoot();
		void randomMoove();
		std::string printType() const;
		std::string getRandomType();
		void setType(std::string);
		void shoot(Object *objs);
	private:
		std::string type;
};

#endif
