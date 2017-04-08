#include "header.hpp"

void		print_score( int score, int life )
{
	start_color();
		init_pair(6, COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(6));
	mvprintw(0, 0, "||||||||||||||||||||||||||||||||||||||||||	Score: %5d	||||||||||||||||||||||||||||||||||||||||||", score);
	mvprintw(1, 0, "||||||||||||||||||||||||||||||||||||||||||	Life : %5d	||||||||||||||||||||||||||||||||||||||||||", life);
	attroff(COLOR_PAIR(6));

}

void		scr_end( void )
{
	endwin();
}

void		scr_upd( Player *p, Enemy *horde, Object *objs )
{
	int colision;
	erase();
	start_color();
	init_pair(7, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(7));
	mvprintw( p->getY(), p->getX(), PLAYER );
	attroff(COLOR_PAIR(7));

	col::checkPos( horde, objs );

	col::checkHit( p, horde, objs );

	colision = col::checkCol( p, horde, objs );
	if (colision == 1 || colision == 2)
		p->setChp(p->getChp() - 1);
	if (p->getChp() <= 0)
	{
		game_over( p );
	}

	col::updatePos(p,  horde, objs );

	print_score( p->getScore(), p->getChp() );
	refresh();
}

void		scr_init( void )
{
	int			max_y, max_x;

	initscr();
	curs_set(0);
	start_color();
    use_default_colors();
	getmaxyx(stdscr, max_y, max_x);
	if ( max_x < MAX_W || max_y < MAX_H + 1 )
	{
		endwin();
		std::cout << "You need to be in fullscreen for play, sorry !" << std::endl;
		exit(0);
	}
	atexit( scr_end );
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
}
