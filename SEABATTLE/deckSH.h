#pragma once
#include "element.h"
#include "deckSH.h"
#include <string>
#include<iostream>
class deckSH:public element
{
public:
	virtual void changet(std::string t) override;
	deckSH();
	void rotate(float g);
	//virtual bool pressed12(Event& event, Vector2f  pos) ;
	virtual bool pressed(Event& event, Vector2f  pos) override;
	virtual bool turn(Event& event) ;
private:
	Texture mytexture1;
	bool scroll =false;
	
};

