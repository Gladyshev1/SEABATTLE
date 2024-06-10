#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
#include "mytext.h"
using namespace sf;

class button: public mytext {
public:
	
	
	button(float x, float y, float height, float width, std::string textinbutton);
	void mydraw(RenderWindow& window)override;
	void setpos(float x, float y)override;
	void setmash(int H, int W);

	bool pressed(Event& event, Vector2f  pos);
	bool mousein(Event& event, Vector2f  pos);


private:
	Texture mytexture;
	RectangleShape contour;
	float yb;
	float xb;
	float  height;
	float  width;
	bool press;
};
