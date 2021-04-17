#include "Headers/includes.hpp"
#include "Headers/game.h"
#include "Headers/window.h"

int main(int argc, char *argv[]){

	QApplication app(argc, argv);

	Window *mainWindow = new Window();
	mainWindow->setFocusPolicy(Qt::NoFocus);

	Window *menu = new Window();
	menu->setFixedSize(200, mainWindow->height());

	Game *game = new Game(mainWindow->width(), mainWindow->height());

	QLabel *labelAngle = new QLabel();
	labelAngle->setText("Angle");
	labelAngle->setFixedSize(50,30);

	QLabel *labelScore = new QLabel();
	labelScore->setText("Score");
	labelScore->setFixedSize(50,30);

	QLabel *labelSpeed = new QLabel();
	labelSpeed->setText("Speed");
	labelSpeed->setFixedSize(50,30);

	QLCDNumber *scoreShow = new QLCDNumber(4);
	scoreShow->setSegmentStyle(QLCDNumber::Flat);

	QSlider *sliderAngle = new QSlider(Qt::Horizontal);
	sliderAngle->setFixedSize(100,30);
	sliderAngle->setRange(0,90);	
	sliderAngle->setTickInterval(15);
	sliderAngle->setTickPosition(QSlider::TicksBelow);

	QSlider *sliderSpeed = new QSlider(Qt::Horizontal);
	sliderSpeed->setFixedSize(100,30);
	sliderSpeed->setRange(0,50);	
	sliderSpeed->setTickInterval(5);
	sliderSpeed->setTickPosition(QSlider::TicksBelow);

	QPushButton *pauseButton = new QPushButton("&Pause");
	pauseButton->setObjectName("quitButton");
	pauseButton->setFixedSize(50,30);
	pauseButton->setFocusPolicy(Qt::NoFocus);

	QPushButton *quitButton  = new QPushButton("&Quit");
	quitButton->setObjectName("quitButton");
	quitButton->setFixedSize(50,30);
	quitButton->setFocusPolicy(Qt::NoFocus);

	QPushButton *runButton 	 = new QPushButton("&Run");
	runButton->setObjectName("quitButton");
	runButton->setFixedSize(50,30);
	runButton->setFocusPolicy(Qt::NoFocus);

	menu->addWidgetWindow(labelSpeed,0,0);
	menu->addWidgetWindow(sliderSpeed,0,1);
	menu->addWidgetWindow(labelAngle,1,0);
	menu->addWidgetWindow(sliderAngle,1,1);
	menu->addWidgetWindow(labelScore,2,0);
	menu->addWidgetWindow(scoreShow,2,1);
	menu->addWidgetWindow(runButton,3,1);
	menu->addWidgetWindow(pauseButton,4,1);
	menu->addWidgetWindow(quitButton,5,1);

	mainWindow->addWidgetWindow(menu,0,0,1,1);
	mainWindow->addWidgetWindow(game->gameView(),0,1,1,2);
	
	QObject::connect(game, SIGNAL(score_changed(int)), scoreShow, SLOT(display(int)));
	QObject::connect(mainWindow, &Window::size_changed, game, &Game::setSceneSize);
	QObject::connect(pauseButton, &QPushButton::clicked, game, &Game::handlerGameOver);
	QObject::connect(quitButton, &QPushButton::clicked, QCoreApplication::quit);
	QObject::connect(runButton, &QPushButton::clicked, game, &Game::play);
	QObject::connect(sliderAngle, &QAbstractSlider::valueChanged, game, &Game::setAngle);
	QObject::connect(sliderSpeed, &QAbstractSlider::valueChanged, game, &Game::setSpeed);

	mainWindow->show();

	return app.exec();
}
