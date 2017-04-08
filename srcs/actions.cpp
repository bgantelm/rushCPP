#include "header.hpp"

void		get_action( int *action , Player *p)
{
	int		c = 0, max_y, max_x;
	*action = 0;

	while ( (c = getch() ) != ERR )
	{
			switch ( c )
			{
				case	KEY_RESIZE:
					getmaxyx(stdscr, max_y, max_x);
					p->setX(5);
					p->setY((max_y - 2));
					break;
				case KEY_LEFT:
			        *action = ACTION_MOVE_LEFT;
			        break;
			    case KEY_RIGHT:
			        *action = ACTION_MOVE_RIGHT;
			        break;
			    case KEY_UP:
			        *action = ACTION_MOVE_UP;
			        break;
			    case KEY_DOWN:
			        *action = ACTION_MOVE_DOWN;
			        break;
			    case ' ':
			        *action = ACTION_SHOOT;
			        break;
			    case 'q':
			    	exit(0);
			    default:
			    	break;
			}
	}
}

void		apply_action( int action, Player *p, Object *objs )
{
	switch ( action )
	{
		case ACTION_MOVE_LEFT:
			if ( p->getX() > 0 )
      			p->setX( p->getX() - 2 );
      		break;
	    case ACTION_MOVE_RIGHT:
	    	if ( p->getX() < MAX_W )
    	  		p->setX( p->getX() + 2 );
      		break;
      	case ACTION_MOVE_UP:
			if ( p->getY() > 0 )
      			p->setY( p->getY() - 1 );
      		break;
	    case ACTION_MOVE_DOWN:
	    	if ( p->getY() < MAX_H )
    	  		p->setY( p->getY() + 1 );
      		break;
    	case ACTION_SHOOT:
				col::createObject( objs, p->getX() + 0, p->getY() - 1, "fShot" );
    		col::createObject( objs, p->getX() + 1, p->getY() - 1, "fShot" );
    		col::createObject( objs, p->getX() + 2, p->getY() - 1, "fShot" );
    		col::createObject( objs, p->getX() + 3, p->getY() - 1, "fShot" );
				col::createObject( objs, p->getX() + 4, p->getY() - 1, "fShot" );
				col::createObject( objs, p->getX() + 5, p->getY() - 1, "fShot" );
      		break;
	    default:
	      	break;
	}
}

void		random_generate(Player *p, Enemy *horde, Object *objs )
{
	int		seed;

	int count = 0;
	switch ( rand() % 5 )
	{
		case		1:
			col::createEnemy( horde, random() % MAX_W, 0 );
			col::checkHit(p, horde, objs);
			seed = rand() % MAX_ENEMY;
			if ( horde[seed].getChp() )
			{
				col::createObject( objs, horde[seed].getX(), horde[seed].getY() + 1, "eShot" );
				col::checkHit(p, horde, objs);
			}
			break;
		case		2:
			if (count < MAX_OBJECT - 20)
			{
				count++;
				col::createObject( objs, random() % MAX_W, 0, "obstacle" );
				col::checkHit(p, horde, objs);
			}
			break;
		case		3:
			break;
		default:
			break;
	}
}

void		main_loop( Player *p, Enemy *horde, Object *objs )
{
	int				action;
	struct timeval	st;
	struct timeval	end;

	while ( 42 )
	{
		gettimeofday(&st, NULL);
		get_action( &action , p);
		apply_action( action, p, objs );
		random_generate(p,  horde, objs );
		p->setScore ( p->getScore() + 1 );
		gettimeofday(&end, NULL);
		if (st.tv_usec < end.tv_usec)
			st.tv_usec = end.tv_usec;;
		usleep( ( FRAMERATE * 1000 ) - ( end.tv_usec - st.tv_usec ) );
	    scr_upd( p, horde, objs );
	}
}
