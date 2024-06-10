#include "ship.h"

ship::ship(float x, float y, int deck1)
{
	arr[0].setpos(x, y);
	deck = deck1;
	X = x;
	Y = y;
	deck2 = deck1;
	zX = x;
	zY = y;
}

ship::~ship()
{
	
	delete[] arr;
}

void ship::mydraw(RenderWindow& window)



{
	
	if (deck == 1) {
		arr[0].changet("img/OneDeck.png");
		arr[0].mydraw(window);
	}
	else if (vert == false) {
		
		arr[0].changet("img/deckL.png");
		arr[0].mydraw(window);
		for (int i = 1; i < deck - 1; i++) {

			arr[i].setpos(arr[i - 1].getposx() + 64, arr[i - 1].getposy());
			arr[i].mydraw(window);


		}
		arr[deck - 1].setpos(arr[deck - 2].getposx() + 64, arr[deck - 2].getposy());
		arr[deck - 1].changet("img/deckR.png");
		arr[deck - 1].mydraw(window);
	}
	else {
		arr[0].setpos(arr[0].getposx(), arr[0].getposy());
		arr[0].mydraw(window);
		for (int i = 1; i < deck - 1; i++) {

			arr[i].setpos(arr[i - 1].getposx() , arr[i - 1].getposy() + 64);
			arr[i].mydraw(window);


		}
		arr[deck - 1].setpos(arr[deck - 2].getposx() , arr[deck - 2].getposy() + 64);
		arr[deck - 1].changet("img/deckR.png");
		arr[deck - 1].mydraw(window);


	}
}

void ship::arrangement(Event& event, Vector2f pos)

{
	
		if (inship(event, pos)) {
			insh = true;
		}
		else {
			insh = false;
		}


		if (isMove == false && !post) {
			for (int i = 0; i < deck; i++) {
				if (arr[i].pressed(event, pos)) {
					isMove = true;
				}


			}
		}
		else
		{
			for (int i = 0; i < deck; i++) {
				if (arr[i].pressed(event, pos)) {
					isMove = false;
					
					post = true;

				}


			}
		}





		if (isMove) {
			arr[0].setpos(X, Y);

			if (arr[0].turn(event)) {
				arr[0].setpos(X, Y);
				
				rotateSH();

			}



		}



	

	 
}

void ship::zero()
{
	pressin = false;
	X = zX;
	Y = zY;
	deck = deck2;
	vert = false;
	post = false;
	
}

void ship::rotateSH()
{

	vert = !vert;
	if (vert&& deck!=1) {
		for (int i = 0; i < deck; i++) {
			arr[i].rotate(90);


		}
	}
	else 
	{
		for (int i = 0; i < deck; i++) {
			arr[i].rotate(0);


		}
	}

	
}

bool ship::inship(Event& event, Vector2f  pos)
{
	for (int i = 0; i < deck; i++) {
		if (arr[i].mousein(event, pos)) {
			return true;

		}
		
	}
	

		return false;
		}
