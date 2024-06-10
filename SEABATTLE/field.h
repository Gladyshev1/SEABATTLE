#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
#include "elementF.h"

using namespace std;
class field
{
public:
	field();
	field(float x, float y);
	virtual void mydraw(RenderWindow& window);
	virtual bool pressed11(Event& event, Vector2f  pos);
	virtual void getarr(int* mass);
	virtual void setmass(int* mass);
	bool press(Event& event, Vector2f pos);
	int poluchel(Event& event, Vector2f pos);
	virtual int full();
protected:
	bool dest(int l, int z);
	void obl(int z, int loc);
	
	bool mvertical(int loc, int z);
	elementF fieldG[10][10];
	int loc=0;
	int counter = 0;
    int enemySH[10][10] = {0};

	
};

