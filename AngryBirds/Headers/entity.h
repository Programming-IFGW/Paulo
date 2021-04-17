#ifndef ENTITY_H
#define ENTITY_H

#include "includes.hpp"
#include "vector.h"
class Entity: public QObject, public QGraphicsEllipseItem
// class Entity: public QObject, public QGraphicsRectItem 
{
	Q_OBJECT

	public:
		Entity(int size);
		Vector gravity, velocity;
		void setBoundary(int w, int h){ this->w=w; this->h=h; };
		void setX( float x){ this->x = x; };
		void setY( float y){ this->y = y; };
		int getSize(){ return this->size; };
		

	private:
		float angle, speed, elasticity;
		float x, y;
		int w=0, h=0, size=15;

	public slots:
		void bounce();	
		void move();	
		void setVelocity(float speed, float angle); 
};

#endif
