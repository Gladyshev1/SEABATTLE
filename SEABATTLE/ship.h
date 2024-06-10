#pragma once
#include "deckSH.h"

#include <string>
#include<iostream>

using namespace std;
class ship
{

	

public:
	ship(float x, float y, int deck1);
	~ship();
	void mydraw(RenderWindow& window);
	void arrangement(Event& event, Vector2f  pos);
	float X;
	float Y;
	bool vert = false;
	bool isMove = false;
	int deck = 4;
	bool insh = true;
	bool post = false;
	void zero();

private:
	float zX;
	float zY;
	int deck2;
	bool pressin = false;
	void rotateSH();
	bool inship(Event& event, Vector2f  pos);
	
	deckSH* arr = new deckSH[deck];
	bool qq = false;
	int L = 0;

};

