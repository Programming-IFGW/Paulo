#include "Headers/includes.hpp"
#include "Headers/vector.h"

const float DEGTORAD = 0.017453f;

Vector::Vector(){};

Vector::Vector(float length, float angle){
	this->setAngle(angle);
	this->setLength(length);
}

void Vector::addVector(Vector b){
	this->setX(round(1000*(this->length*cosf(this->angle*DEGTORAD) + b.getLength()*cosf(b.getAngle()*DEGTORAD)))/1000.0);
	this->setY(round(1000*(this->length*sinf(this->angle*DEGTORAD) + b.getLength()*sinf(b.getAngle()*DEGTORAD)))/1000.0);	
	this->setAngle(round(atan2f(this->y,this->x)/DEGTORAD));
	this->setLength(hypotf(this->getX(),this->getY()));
}
