#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Vessel.hpp"

class Player : public Vessel
{
	public:
		Player(void);
		Player(Player const & src);
		Player & operator=(Player const & src);
		virtual ~Player(void);

		int getScore() const;

		void setScore(int amount);

		void collision();
		void shoot();

	private:
		int _score;
};

#endif
