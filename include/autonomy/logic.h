#ifndef LOGIC_H_
#define LOGIC_H_

#include "autonomy/global.h"
#include "autonomy/display.h"
#include <iostream>
#include <list>

using namespace std;

class Snake{
	private:
		list<Point> l_Body;
		bool flag = true;
	public:
		Snake();
		~Snake();
		void move();
		bool checkSimple();
		list<Point> getXDirection();
		list<Point> getBody();
		bool getFlag();
		void addBody(int num);
		void setFlag(bool b);
		void deleteBody();
		bool check();
		void LtoF();
		void update(int num);
};

#endif
