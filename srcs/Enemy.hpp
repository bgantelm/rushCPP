#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Vessel.hpp"

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
};

#endif
