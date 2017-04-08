#include "header.hpp"

void		game_over( Player *p )
{
	int		c = 0;

	erase();
	clear();
	start_color();
		init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	attron(COLOR_PAIR(7));
	mvprintw( MAX_H / 2, MAX_W / 2, "||||||||||||||||||||||||||||||||||||||||||	Game Over !! Score: %5d	||||||||||||||||||||||||||||||||||||||||||", p->getScore() );
	mvprintw( MAX_H / 2 + 1, MAX_W / 2, "||||||||||||||||||||||||||||||||||||||||||	Replay: r	Quit: q		||||||||||||||||||||||||||||||||||||||||||", p->getScore() );
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
	Player		*p = new Player;
	Enemy		*horde = new Enemy[MAX_ENEMY];
	Object		*objs = new Object[MAX_OBJECT];

	scr_init();
	scr_upd( p, horde, objs );
	main_loop( p, horde, objs );
}
