#ifndef HEADER_HPP

# define HEADER_HPP

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../src/IEntity.hpp"
#include "../src/Vessel.hpp"
#include "../src/Player.hpp"
#include "../src/Enemy.hpp"
#include "../src/Object.hpp"
#include "data.hpp"
#include "screen.hpp"
#include "actions.hpp"

namespace col
{
	int  checkCol(Player * a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT]);
	void updatePos(Player *a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT]);
	void createEnemy(Enemy b[MAX_ENEMY], int x, int y);
	void createObject(Object c[MAX_OBJECT], int x, int y, std::string type);
	void checkPos(Enemy b[MAX_ENEMY], Object c[MAX_OBJECT]);
	void updateEshot( Object *eShot );
	void checkHit(Player * a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT]);
}

#endif
