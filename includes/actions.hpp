#ifndef ACTIONS_HPP

# define ACTIONS_HPP

void		get_action( int *action );
void		print_debug( void );
void		apply_action( int action, Player *p, Object *objs );
void		main_loop( Player *p, Enemy *horde, Object *objs );
void		scroll_objects( Enemy *e );

#endif
