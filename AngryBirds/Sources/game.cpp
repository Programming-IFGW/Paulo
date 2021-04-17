#include "Headers/includes.hpp"
#include "Headers/game.h"
#include "Headers/entity.h"

const float DEGTORAD = 0.017453f;

Game::Game(int sceneWidth, int sceneHeight)
{
	this->sceneWidth = sceneWidth;
	this->sceneHeight = sceneHeight;
	blockSize=20;
	fps=25;
	score=0;
	srand (time(NULL));

	scene = new QGraphicsScene();
	view  = new QGraphicsView(scene);
	timer = new QTimer();

	scene->setSceneRect(0,0,sceneWidth, sceneHeight);
	scene->setBackgroundBrush(QBrush(QColor(95,255,255), Qt::SolidPattern));

	std::vector<Entity*> population;

	createEntity(10);

	QObject::connect(this, &Game::gameOver, this, &Game::stop);
	QObject::connect(timer,&QTimer::timeout, this, &Game::gameLoop);
}

QGraphicsView *Game::gameView(){
	view->update(0,0,sceneWidth-200, sceneHeight);
	return this->view;
}

void Game::play(){
	main_entity->setVelocity(this->speed, this->angle);
	for(auto e:population){
		e->setX(e->pos().x());
		e->setY(e->pos().y());
	}	
	gameLoop();
}

void Game::gameLoop(){
	timer->start(fps);	
	main_entity->move();
	for (int j=0; j < static_cast<int>(population.size()); j++){
		population[j]->move();
		for (int i=0; i < static_cast<int>(population.size()); i++){
			if (i!=j) interact(population[i],population[j]);
		}
	}
}

void Game::stop() {
	timer->stop();
}

void Game::handlerGameOver(){
	emit gameOver();
}

void Game::createEntity(int numberOfParticles){
	for (auto e:population){
		scene->removeItem(e);
	}
	population.clear();

	main_entity = new Entity(blockSize);
	main_entity->setBrush(Qt::red);
	main_entity->setBoundary((sceneWidth-200-50+0.25*blockSize), sceneHeight-50+0.25*blockSize);
	main_entity->setPos(blockSize,sceneHeight-blockSize);

	scene->addItem(main_entity);
	population.push_back(main_entity);

	for(int n = 1; n<=numberOfParticles; n++){
		Entity *e = new Entity(blockSize);
		e->setBoundary((sceneWidth-200-50+0.25*blockSize), sceneHeight-50+0.25*blockSize);
		e->setPos(rand()%sceneWidth - blockSize+200,blockSize);
		e->setVelocity(rand()%25, rand()%180);
		scene->addItem(e);
		population.push_back(e);
	}
}

void Game::setSceneSize(int w, int h){
	this->sceneWidth = w;
	this->sceneHeight = h;
	scene->setSceneRect(0,0,(w-200-50), h-50);
	view->update(0,0,sceneWidth-200, sceneHeight);
	for(auto e:population) {
		e->setBoundary((w-200-50+0.25*blockSize), h-50+0.25*blockSize);
	}
}

void Game::interact(Entity *e1, Entity *e2){

	if(e1->collidesWithItem(e2)){
		if (e1==main_entity){
			population.erase(std::remove(population.begin(),population.end(),e2),population.end());	
			scene->removeItem(e2);
			score ++;
			emit score_changed(score);
		}
		else if (e2==main_entity){
			population.erase(std::remove(population.begin(),population.end(),e1),population.end());	
			scene->removeItem(e1);
			score ++;
			emit score_changed(score);
		}
		else{
			float x1, x2, y1, y2, dx, dy, angle1, angle2, speed1, speed2, tangent, normal;
			x1 = e1->pos().x();
			x2 = e2->pos().x();
			y1 = e1->pos().y();
			y2 = e2->pos().y();
			dx = x1 - x2;
			dy = y1 - y2;

			normal 	= atan2f(dy,dx)/DEGTORAD;
			tangent = normal - 90;
			
			angle1 = 2*tangent - e1->velocity.getAngle();
			angle2 = 2*tangent - e2->velocity.getAngle();

			speed1 = e2->velocity.getLength();
			speed2 = e1->velocity.getLength();

			e1->velocity.setAngle(angle1);
			e1->velocity.setLength(speed1);
			e2->velocity.setAngle(angle2);
			e2->velocity.setLength(speed2);
		}
	}
}

