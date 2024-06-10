#pragma once
#include "field.h"
#include <string>
#include<iostream>
#include "ship.h"
using namespace std;
class MYfield:public field
{
	friend ship;
	 

public:
	MYfield(float x, float y);
	 void mydraw(RenderWindow& window)override;
	bool infield(Event& event, Vector2f  pos);
	void setka(ship* Q);
	bool pressed11(Event& event, Vector2f  pos)override;
	bool flag = true;
	
private:

	int  z = 0;
	int  l=0;
	bool PRS = false;
	bool in = false;
	int p=0;
	int o=0;
	int pal= 0;
};

