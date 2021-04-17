#include "Headers/includes.hpp"
#include "Headers/entity.h"

const float DEGTORAD = 0.017453f;

Entity::Entity(int size){
	this->setRect(-size/2,-size/2,size,size);
	this->setFlag(QGraphicsItem::ItemIsFocusable);
	this->setFlag(QGraphicsItem::ItemIsMovable);
	this->setBrush(Qt::black);
	gravity.setAngle(-90);
	gravity.setLength(0.5);
	elasticity=.9;
}

void Entity::setVelocity(float speed, float angle){ 
	this->velocity.setLength(speed);
	this->velocity.setAngle(angle);
}

void Entity::move() {
	this->velocity.addVector(this->gravity);
	this->x += cos(this->velocity.getAngle()*DEGTORAD)*this->velocity.getLength();
	this->y -= sin(this->velocity.getAngle()*DEGTORAD)*this->velocity.getLength();
	this->bounce();
	this->setPos(round(x*100)/100.0,round(y*100)/100.0);
}

void Entity::bounce(){
	if( this->x > w){
		this->x=w;
		this->velocity.setAngle(180 - this->velocity.getAngle());
		this->velocity.setLength(this->velocity.getLength()*elasticity);
	} 
	else if( this->x < 0){
		this->x = 0;
		this->velocity.setAngle(180 - this->velocity.getAngle());
		this->velocity.setLength(this->velocity.getLength()*elasticity);
	}
	if (this->y > h){
		this->y = h;
		this->velocity.setAngle(-this->velocity.getAngle());
		this->velocity.setLength(this->velocity.getLength()*elasticity);
	}
	else if(this->y < 0){
		this->y = 0;
		this->velocity.setAngle(-this->velocity.getAngle());
	}
}

