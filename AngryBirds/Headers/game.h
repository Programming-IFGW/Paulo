#ifndef GAME_H
#define GAME_H

#include "includes.hpp"
#include "entity.h"
#include "vector.h"

class Game: public QObject
{
	Q_OBJECT

	public:
		Game(int sceneWidth, int sceneHeight);
		Game();
		QGraphicsView *gameView();
	
	signals:	
		void gameOver();
		void restart();
		void score_changed(int score);

	private:
		Entity *main_entity;
		std::vector<Entity*> population;
		int blockSize, fps, numberOfParticles, sceneHeight, sceneWidth, score;
		float angle, speed;
		QGraphicsScene *scene;
		QGraphicsView *view;
		QTimer *timer;
	
	public slots:
		void createEntity( int numberOfParticles);
		void gameLoop();
		void handlerGameOver();
		void interact(Entity *e1, Entity *e2);
		void play();
		void setAngle(float angle){ this->angle = angle; };
		void setSceneSize(int w, int h);
		void setSpeed(float speed){ this->speed = speed; };
		void stop();
};

#endif
