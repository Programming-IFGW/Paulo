#ifndef WINDOW_H
#define WINDOW_H

#include "includes.hpp"

class Window: public QWidget 
{
	Q_OBJECT

	public:
		Window(QWidget *parent=0);
		void addWidgetWindow(QWidget *widget, int x, int y, int dx=0, int dy=0);
		void resizeEvent(QResizeEvent *event);

	signals:
		void size_changed(int w, int h);

	private:	
		QGridLayout *grid;	 
};

#endif
