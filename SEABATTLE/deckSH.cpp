#include "deckSH.h"

void deckSH::changet(std::string t)
{
	mytexture1.loadFromFile(t);
	el.setTexture(&mytexture1);
}

deckSH::deckSH()
{
	
	mytexture1.loadFromFile("img/deckM.png");
	el.setTexture(&mytexture1);
	el.setSize(Vector2f(64, 64));

}

void deckSH::rotate(float g)
{
	el.setRotation(g);
}

bool deckSH::pressed(Event& event, Vector2f  pos)
{
	if (el.getGlobalBounds().contains(pos.x, pos.y)  && event.type == Event::MouseButtonPressed && !press) {
		if (event.key.code == Mouse::Left) {

			press = true;
			return true;
		}

	};

	if (!(press)) return false;

	

		if (!(event.type == Event::MouseButtonPressed)) {

			press = false;

		}



		return false;


	
	
}
bool deckSH::turn(Event& event)
{
	if (event.type == Event::MouseButtonPressed && !scroll) {
		if (event.key.code == Mouse::Right) {
			
			scroll = true;
			return true;

		}
	};

	if (!(scroll)) return false;



	if (!(event.type == Event::MouseButtonPressed)) {

		scroll = false;

	}



	return false;




}

