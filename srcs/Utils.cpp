#include "header.hpp"

int col::checkCol(Player * a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT])
{
	int i = 0;
	while (i < MAX_ENEMY)
	{
		if (((a->getX() + 1 == b[i].getX())  && (a->getY() == b[i].getY())) ||
				((a->getX() + 2 == b[i].getX())  && (a->getY() == b[i].getY())) ||
				((a->getX() == b[i].getX())  && (a->getY() == b[i].getY())) ||
				((a->getX() + 3 == b[i].getX())  && (a->getY() == b[i].getY())) ||
				((a->getX() + 4 == b[i].getX())  && (a->getY() == b[i].getY())) ||
				((a->getX() == b[i].getX() + 1)  && (a->getY() == b[i].getY())) ||
				((a->getX() == b[i].getX() + 2)  && (a->getY() == b[i].getY())) ||
				((a->getX() == b[i].getX() + 3)  && (a->getY() == b[i].getY())) ||
				((a->getX() == b[i].getX() + 4)  && (a->getY() == b[i].getY())))
			return (1);
		i++;
	}
	i = 0;
	while (i < MAX_OBJECT)
	{
		if (((a->getX() + 1 == c[i].getX())  && (a->getY() == c[i].getY())) ||
				((a->getX() + 2 == c[i].getX())  && (a->getY() == c[i].getY())) ||
				((a->getX()  == c[i].getX())  && (a->getY() == c[i].getY())) ||
				((a->getX() + 3 == c[i].getX())  && (a->getY() == c[i].getY())) ||
				((a->getX() + 4 == c[i].getX())  && (a->getY() == c[i].getY())))
		{
			if (c[i].getType() == "obstacle")
				return (2);
			else if (c[i].getType() == "regen" && c[i].getChp() > 0)
			{
				c[i].setChp(0);
				return (3);
			}
		}
		i++;
	}
	return (0);
}


void col::updatePos(Player *a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT])
{
	int i = 0;
	while (i < MAX_ENEMY)
	{
		if ( b[i].getChp() > 0 )
		{
			b[i] += 1;
			b[i].randomMoove();
			start_color();
			init_pair(1, COLOR_RED, COLOR_BLACK);
			attron(COLOR_PAIR(1));
			mvprintw( b[i].getY(), b[i].getX(), b[i].printType().c_str() );
			attroff(COLOR_PAIR(1));
			col::checkHit(a, b, c);
		}
		i++;
	}
	i = 0;
	while (i < MAX_OBJECT)
	{
		if ( c[i].getChp() > 0 )
		{
			if (c[i].getType() == "obstacle" || c[i].getType() == "eShot" \
				|| c[i].getType() == "regen")
			{
				c[i] += 1;
				if ( c[i].getType() == "obstacle" )
				{
					start_color();
					init_pair(3, COLOR_YELLOW, COLOR_BLACK);
					attron(COLOR_PAIR(3));
					mvprintw( c[i].getY(), c[i].getX(), OBSTACLE );
					attroff(COLOR_PAIR(3));
					col::checkHit(a, b, c);
				}
				else if (c[i].getType() == "eShot")
				{
					start_color();
					init_pair(4, COLOR_RED, COLOR_BLACK);
					attron(COLOR_PAIR(4));
					mvprintw( c[i].getY(), c[i].getX(), FSHOT );
							attroff(COLOR_PAIR(4));
					col::checkHit(a, b, c);
					mvprintw( c[i].getY(), c[i].getX(), " " );
					col::checkHit(a, b, c);
					c[i] += 1;
					start_color();
					init_pair(4, COLOR_RED, COLOR_BLACK);
					attron(COLOR_PAIR(4));
					mvprintw( c[i].getY(), c[i].getX(), FSHOT );
							attroff(COLOR_PAIR(4));
					col::checkHit(a, b, c);
				}
				else if (c[i].getType() == "regen")
				{
					start_color();
					init_pair(5, COLOR_GREEN, COLOR_BLACK);
					attron(COLOR_PAIR(5));
					mvprintw( c[i].getY(), c[i].getX(), REGEN );
					attroff(COLOR_PAIR(5));
					col::checkHit(a, b, c);
				}
			}
			else if (c[i].getType() == "fShot")
			{
				c[i] -= 1;
				start_color();
				init_pair(6, COLOR_GREEN, COLOR_BLACK);
				attron(COLOR_PAIR(6));
				mvprintw( c[i].getY(), c[i].getX(), FSHOT );
						attroff(COLOR_PAIR(6));
				col::checkHit(a, b, c);
			}
		}
		i++;
	}
}

void col::createEnemy(Enemy b[MAX_ENEMY], int x, int y)
{
	int i = 0;

	while (i < MAX_ENEMY)
	{
		if (b[i].getChp() <= 0)
		{
			b[i].setChp(1);
			b[i].setX(x);
			b[i].setY(y);
			break;
		}
		i++;
	}
}

void col::checkPos(Enemy b[MAX_ENEMY], Object c[MAX_OBJECT])
{
	int i = 0;

	while (i < MAX_ENEMY)
	{
		if (b[i].getY() > MAX_H)
			b[i].setChp(0);
		i++;
	}
	i = 0;

	while (i < MAX_OBJECT)
	{
		if (c[i].getY() > MAX_H || c[i].getY() < 0)
			c[i].setChp(0);
		i++;
	}
}

void col::createObject(Object c[MAX_OBJECT], int x, int y, std::string type)
{
	int i = 0;

	while (i < MAX_OBJECT )
	{
		if (c[i].getChp() <= 0)
		{
			c[i].setChp(1);
			c[i].setX(x);
			c[i].setY(y);
			c[i].setType(type);
			break;
		}
		i++;
	}
}

void col::checkHit(Player * a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT])
{
	int i = 0;
	int e;
	while (i < MAX_OBJECT)
	{
		if (c[i].getChp() > 0)
		{
			if (c[i].getType() == "fShot")
			{
				e = 0;
				while (e < MAX_ENEMY)
				{
					if ((c[i].getX() == b[e].getX()) &&(c[i].getY() == b[e].getY()))
					{
						b[e].setChp(b[e].getChp() - 1);
						a->setScore(a->getScore() + 10);
						c[i].setChp(0);
						break;
					}
					e++;
				}
				e = 0;
				while (e < MAX_OBJECT)
				{
					if (c[e].getType() != "fShot")
					{
						if ((c[i].getX() == c[e].getX()) && (c[i].getY() == c[e].getY()))
						{
							c[e].setChp(c[e].getChp() - 1);
							a->setScore(a->getScore() + 5);
							c[i].setChp(0);
							break ;
						}
					}
					e++;
				}
			}
		}
		i++;
	}
}
