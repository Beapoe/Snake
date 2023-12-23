#ifndef DISPLAY_H_
#define DISPLAY_H_
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <list>
#include "autonomy/global.h"

using namespace std;

class Point{
	private:
		Direction moved;
		Type identify;
		int px,py;
		class Empty{
			public:
				Empty();
				~Empty();
				void display();
		};
		class Food{
			public:
				Food();
				~Food();
				void display();
		};
		class Head{
			public:
				Head();
				~Head();
				void display();
		};
		class Body{
			public:
				Body();
				~Body();
				void display();
		};
	public:
		Point();
		Point(Type type);
		~Point();
		void display(Type type);
		void setX(int xtemp);
		void setY(int ytemp);
		void setIdentify(Type itemp);
		void setMoved(Direction d);
		int getX();
		int getY();
		Type getIdentify();
		Direction getMoved();
		void  operator=(Point x);
		bool operator==(Point x);
};

class Map{
	private:
		int Hnum;
	public:
		Map();
		~Map();
		list<Point> map[10][10];
		void display();
		list<Point> getFood();
		Point getHead();
};

#endif
