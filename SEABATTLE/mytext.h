#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
using namespace sf;
class mytext {
public:


	Text txt;
	mytext(std::string shribe);
	void setfontsize(int a);
	virtual void setpos(float x, float y);
	virtual void mydraw(RenderWindow& window);
	void setString(std::string name);
	void setcolor(int R, int G, int B);
private:

	std::string instr;
	Font font;



};