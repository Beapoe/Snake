#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <list>
#include "global.h"
#include "display.h"

using namespace std;

 void Point::Empty::display(){
	 cout<<"EMPTY";
}

void Point::Food::display(){
	cout<<"FOOD";
}

void Point::Head::display(){
	cout<<"HEAD";
}

void Point::Body::display(){
	cout<<"BODY";
}

void Point::setX(int xtemp){
	px = xtemp;
}

void Point::setY(int ytemp){
	py = ytemp;
}

void Point::setIdentify(Type itemp){
	identify = itemp;
}

void Point::setMoved(Direction d){
	moved = d;
}

int Point::getX(){
	return px;
}

int Point::getY(){
	return py;
}

Type Point::getIdentify(){
	return identify;
}

Direction Point::getMoved(){
	return moved;
}
void Point::operator=(Point x){
	Point::setIdentify(x.getIdentify());
	Point::setX(x.getX());
	Point::setY(x.getY());
}

bool Point::operator==(Point x){
	Type itemp1 = identify;
	Type itemp2 = x.getIdentify();
	if(itemp1 == itemp2){
		return true;
	}else{
		return false;
	}
}

Point::Point(Type type=Empty){
	switch (type){
		case Empty:Point::Empty::Empty();
				   identify = Empty;
				   break;
		case Food:Point::Food::Food();
				  identify = Food;
				  break;
		case Head:Point::Head::Head();
				  identify = Head;
				  break;
		case Body:Point::Body::Body();
				  identify = Body;
				  break;
	}
}

Point::display(){
	switch (identify){
		case Empty:Point::Empty::display();
				   break;
		case Food:Point::Food::display();
				  break;
		case Head:Point::Head::display();
				  break;
		case Body:Point::Body::display();
				  break;
	}
}

Map::Map(){
	int fx,fy,sx,sy;
	Point ftemp = Point::Point(Food);
	Point htemp = Point::Point(Head);
	srand(time(NULL));
	for(int i=0;i<3;i++){
		fx = rand() %11;
		fy = rand() %11;
		map[fy][fx] = ftemp;
		map[fy][fx].setX(fx);
		map[fy][fx].setY(fy);
	}
	if(Hnum != 1){
		sx = rand() %11;
		sy = rand() %11;
		map[sy][sx] = htemp;
		map[sy][sx].setX(sx);
		map[sy][sx].setY(sy);
		Hnum = 1;
	}
}

void Map::display(){
	int counter = 0;
	Type Identify;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(counter == 9){
				cout<<endl;
				counter = 0;
			}else{
				Identify = map[i][j].getIdentify();
				map[i][j].display(Identify);
				counter += 1;
			}
		}
	}
}

list<Point> Map::getFood(){
	Point ftemp;
	list<Point> ftemps;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(map[i][j].getIdentify() == Food){
				ftemp = map[i][j];
				ftemps.push_back(ftemp);
			}
		}
	}
	return ftemps;
}

Point Map::getHead(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(map[i][j].getIdentify() == Head){
				return map[i][j];
			}
		}
	}
}
