#include <iostream>
#include <list>
#include "global.h"
#include "display.h"
#include "logic.h"

using namespace std;

Snake::Snake(){
	Point Body = Point::Point(Body);
	Point Head = Map::getHead();
	int hx = Head.getX();
	int hy = Head.getY();
	if(hx-1<0){
		map[hy][hx-1] = Point::Point(Body);
	}else if(hx+1>0){
		map[hy][hx-1] = Point::Point(Body);
	}
	l_Body.push_back(Body);
}

list<Point> Snake::getBody(){
	return l_Body;
}

void Snake::addBody(int num){
	int length,xtemp,ytemp;
	Point ptemp;
	D d;
	for(int i=0;i<num;i++){
		length = l_Body.size();
		ptemp = l_Body[length-1].getBody();
		d = ptemp.getMoved();
		switch d{
			case Up:ptemp = Point::Point(Body);
					xtemp = l_Body[length-1].getX();
					ytemp = l_Body[length-1].getY()-1;
					map[ytemp][xtemp] = ptemp;
					l_Body.push_back(map[ytemp][xtemp]);
					break;
			case Down:ptemp = Point::Point(Body);
					  xtemp = l_Body[length-1].getX();
					  ytemp = l_Body[length-1].getY()+1;
					  map[ytemp][xtemp] = ptemp;
					  l_Body.push_back(map[ytemp][xtemp]);
					  break;
			case Left:ptemp = Point::Point(Body);
					  xtemp = l_Body[length-1].getX()-1;
					  ytemp = l_Body[length-1].getY();
					  map[ytemp][xtemp] = ptemp;
					  l_Body.push_back(map[ytemp][xtemp]);
					  break;
			case Right:ptemp = Point::Point(Body);
					   xtemp = l_Body[length-1].getX()+1;
					   ytemp = l_Body[length-1].getY();
					   map[ytemp][xtemp] = ptemp;
					   l_Body.push_back(map[ytemp][xtemp]);
					   break;
		}
	}
}

void Snake::deleteBody(){
	l_Body.pop_back();
}


