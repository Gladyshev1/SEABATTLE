#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
using namespace sf;

class element {
public:
	element();
	virtual void changet(std::string t)=0;
	void mydraw(RenderWindow& window);
	void setpos(float x, float y);
	void setmash(int H, int W);
	virtual bool pressed(Event& event, Vector2f  pos);
	bool mousein(Event& event, Vector2f  pos);
	float getposx();
	float getposy();
	
protected:
	RectangleShape el;
	
	bool press=false;
};



