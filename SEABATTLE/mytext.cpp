#include "mytext.h"
mytext::mytext(std::string str) {
	font.loadFromFile("font/ObelixPro.ttf");
	txt.setFont(font);
	txt.setFont(font);
	txt.setCharacterSize(10);
	txt.setFillColor(Color(0, 0, 0));

	instr = str;

	txt.setString(instr);
}

void mytext::setfontsize(int a)
{
	txt.setCharacterSize(a);
}

void mytext::setpos(float x, float y)
{
	txt.setPosition(x, y);
}

void mytext::mydraw(RenderWindow& window)
{
	window.draw(txt);
}

void mytext::setString(std::string name)
{
	txt.setString(name);
}

void mytext::setcolor(int R, int G, int B)
{
	txt.setFillColor(Color(R, G, B));
}
