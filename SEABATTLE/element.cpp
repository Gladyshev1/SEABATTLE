#include "element.h"



element::element()
{
	
	el.setPosition(0, 0);
	press = false;
	
	
	el.setSize(Vector2f(64, 64));
}

void element::mydraw(RenderWindow& window)
{
	window.draw(el);
}

void element::setpos(float x, float y)
{
	
		el.setPosition(x, y);

	
}

bool element::pressed(Event& event, Vector2f  pos) {

	if (el.getGlobalBounds().contains(pos.x, pos.y) && event.type == Event::MouseButtonPressed && !press) {
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

float element::getposx()
{
	float z= el.getPosition().x;
	return z;
}

float element::getposy()
{
	float zz = el.getPosition().y;
	return zz;
}


bool element::mousein(Event& event, Vector2f  pos) {


	if (el.getGlobalBounds().contains(pos.x, pos.y)) return true;

	else return false;



}
