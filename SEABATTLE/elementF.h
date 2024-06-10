
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
#include "element.h"
class elementF: public element
{
public:
	elementF();
	virtual void changet(std::string t) override;
	virtual bool pressed(Event& event, Vector2f  pos) override;
private:
	Texture mytexture;
	
};

