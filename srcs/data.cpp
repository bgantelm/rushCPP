#include "header.hpp"

void		game_over( Player *p )
{
	int		c = 0;
	int			max_y, max_x;

	getmaxyx(stdscr, max_y, max_x);
	erase();
	clear();
	start_color();
		init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	attron(COLOR_PAIR(7));
	mvprintw( max_y / 2, (max_x / 2) - 60, "||||||||||||||||||||||||||||||||||||||||||	Game Over :(    Score: %2d	||||||||||||||||||||||||||||||||||||||||||", p->getScore() );
	mvprintw( max_y / 2 + 1, (max_x / 2) - 60, "||||||||||||||||||||||||||||||||||||||||||	Replay: r	Quit: q		||||||||||||||||||||||||||||||||||||||||||", p->getScore() );
	attroff(COLOR_PAIR(7));
	refresh();
	while ( c != 'r' && c != 'q' )
	{
		c = getch();
		if ( c == 'r' || c == 'q' )
		{
			delete p;
			if (c == 'r')
				data_init();
			else
		    	exit(0);
		}
	}
}

void			data_init()
{
	int			max_y, max_x;

	Player		*p = new Player();
	Enemy		*horde = new Enemy[MAX_ENEMY];
	Object		*objs = new Object[MAX_OBJECT];

	scr_init();
	getmaxyx(stdscr, max_y, max_x);
	p->setY((max_y - 2));
	scr_upd( p, horde, objs );
	main_loop( p, horde, objs );
}
