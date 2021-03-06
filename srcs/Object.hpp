#ifndef OBJECT_CLASS_HPP
#define OBJECT_CLASS_HPP

#include "IEntity.hpp"

class Object : public IEntity
{
	public:
		Object(void);
		Object(int x, int y, std::string type);
		Object(Object const & src);
		Object & operator=(Object const & src);
		virtual ~Object(void);

		void collision();

		Object & operator+=(int amount);
		Object & operator-=(int amount);

		int getChp() const;
		int getX() const;
		int getY() const;
		int getDmg() const;
		std::string getType() const;

		void setChp(int amount);
		void setX(int amount);
		void setY(int amount);
		void setDmg(int amount);
		void setType(std::string t);
	protected:
		int _chp;
		int _x;
		int _y;
		int _dmg;
		std::string _type;
};

#endif
