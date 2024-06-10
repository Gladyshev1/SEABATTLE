#include "button.h"










button::button(float x, float y,float height1, float width1, std::string instr) :mytext(instr)
{

	
	contour.setOrigin({ contour.getSize().x / 2, contour.getSize().y / 2 });
	mytexture.loadFromFile("img/emptyb.png");
	contour.setTexture(&mytexture);
	width = width1;
	height = height1;
	press = false;
	contour.setPosition(x, y);
	txt.setPosition(x,y);
	contour.setSize(Vector2f(height, width));
	contour.setFillColor(Color(255,255, 255));
	contour.setTexture(&mytexture);
	xb = height1;
	yb = width1;
}

void button::mydraw(RenderWindow& window)
{
	txt.setPosition( contour.getPosition().x+xb/4,contour.getPosition().y+yb/4-5);
	
	window.draw(contour);
	window.draw(txt);

}

void button::setpos(float x, float y){
	contour.setPosition(x, y);

}




void button::setmash(int H, int W)
{
	contour.setSize(Vector2f(W, H));
	xb = W;
	yb = H;
}



bool button::pressed(Event& event, Vector2f  pos) {

	if (contour.getGlobalBounds().contains(pos.x, pos.y) && event.type == Event::MouseButtonPressed && !press) {
		if (event.key.code == Mouse::Left) {

			press = true;
			return true;
		}

	};

	if (!(press)) return false;

	if (press) {

		if (!(event.type == Event::MouseButtonPressed)) {

			press = false;

		}

		return false;


	}

}
bool button::mousein(Event& event, Vector2f  pos) {


	if (contour.getGlobalBounds().contains(pos.x, pos.y)) {

		
		
		return true;
	}

	else return false;



}
