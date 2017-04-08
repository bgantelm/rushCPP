#ifndef DATA_HPP

# define DATA_HPP

#include "header.hpp"

typedef enum
{
	ACTION_NONE,
	ACTION_MOVE_LEFT,
	ACTION_MOVE_RIGHT,
	ACTION_MOVE_UP,
	ACTION_MOVE_DOWN,
	ACTION_SHOOT,
} action_t;

void			data_init( void );
void			game_over( Player *p );

# define PLAYER		"<(^)>"
# define ENEMY		"<(-)>"
# define OBSTACLE	"X"
# define ESHOT		"|"
# define FSHOT		"|"
# define MAX_ENEMY 	20
# define MAX_OBJECT 80
# define FRAMERATE  40

#endif
