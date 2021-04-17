#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
	public:
		Vector();
		Vector(float length, float angle);
		void setX(float x) { this->x=x; };		
		void setY(float y) { this->y=y; };		
		void setAngle(float angle) { this->angle=angle; };		
		void setLength(float length) { this->length=length; };		
		void addVector(Vector b);
		float getX(){ return this->x; };
		float getY(){ return this->y; };
		float getAngle(){ return this->angle; };
		float getLength(){ return this->length; };

	private:
		float x, y, angle, length;
};

#endif
