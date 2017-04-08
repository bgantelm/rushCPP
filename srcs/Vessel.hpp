#ifndef VESSEL_HPP
#define VESSEL_HPP

#include "IEntity.hpp"

class Vessel : public IEntity
{
	public:
		Vessel(void);
		Vessel(Vessel const & src);
		Vessel & operator=(Vessel const & src);
		~Vessel(void);

		void collision();

		virtual void shoot() = 0;

		int getDmg() const;
		int getArmor() const;
		int getAmmo() const;
		int getX() const;
		int getY() const;
		int getChp() const;
		int getMhp() const;

		void setDmg(int amount);
		void setArmor(int amount);
		void setAmmo(int amount);
		void setX(int amount);
		void setY(int amount);
		void setChp(int amount);
		void setMhp(int amount);

	protected:
		int _chp;
		int _x;
		int _y;
		int _dmg;
		int _armor;

};

#endif
