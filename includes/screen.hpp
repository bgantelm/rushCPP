#ifndef SCREEN_HPP

# define SCREEN_HPP

# define MAX_W		70
# define MAX_H		80

#include "data.hpp"

void		print_score( int score );
void		scr_end( void );
void		scr_upd( Player *p, Enemy *horde, Object *objs );
void		scr_init( void );

#endif
