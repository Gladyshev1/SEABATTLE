#include "elementF.h"

elementF::elementF():element()
{
	
	mytexture.loadFromFile("img/elem.png");
	el.setTexture(&mytexture);
	el.setSize(Vector2f(64, 64));
}

void elementF::changet(std::string t)
{
	mytexture.loadFromFile(t);
	el.setTexture(&mytexture);
}

bool elementF::pressed(Event& event, Vector2f  pos)
{
	if (el.getGlobalBounds().contains(pos.x, pos.y) && event.type == Event::MouseButtonPressed && !press) {
		if (event.key.code == Mouse::Left) {

			press = true;
			return true;
		}

	};

	if (!(press)) return false;

	if (press) {
		return false;


	}
}
