#include "Headers/includes.hpp"
#include "Headers/window.h"

Window::Window(QWidget *parent): QWidget(parent=0)
{
	grid = new QGridLayout(this);	 
	grid->setOriginCorner(Qt::TopLeftCorner);
	setLayout(grid);
}

void Window::addWidgetWindow(QWidget *widget, int x, int y, int dx, int dy){
	if (dx != 0 && dy != 0){
		grid->addWidget(widget,x,y,dx,dy);
	}else{
		grid->addWidget(widget,x,y);
	}
}

void Window::resizeEvent(QResizeEvent *event){
	emit size_changed(event->size().width(), event->size().height());	
}

