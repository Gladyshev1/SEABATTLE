#include "MYfield.h"

MYfield::MYfield(float x, float y)
{
	fieldG[0][0].setpos(x, y);
	
}

void MYfield::mydraw(RenderWindow& window)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			fieldG[i][j + 1].setpos(fieldG[i][j].getposx() + 64, fieldG[0][0].getposy() + i * 64);
			fieldG[i][j].mydraw(window);
		}
		fieldG[i + 1][0].setpos(fieldG[0][0].getposx(), fieldG[0][0].getposy() + (i + 1) * 64);
	}
	for (int i = 0; i < 9; i++) {
		fieldG[9][i].setpos(fieldG[8][i].getposx(), fieldG[8][i].getposy() + 64);
		fieldG[9][i].mydraw(window);
	}
	for (int i = 0; i < 10; i++) {
		fieldG[i][9].setpos(fieldG[i][8].getposx() + 64, fieldG[i][8].getposy());
		fieldG[i][9].mydraw(window);
	}



	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			z = enemySH[i][j];
			l = i + 10 + j;
			if (enemySH[i][j] == 1) {
				fieldG[i][j].changet("img/CO.png");
			}

			else if (enemySH[i][j] == -1) {
				fieldG[i][j].changet("img/RO.png");
			}

			else if ((enemySH[i][j - 1] == 0 && enemySH[i][j + 1] == 0 && j != 0 && j != 9) || enemySH[i][j - 1] == 0 && j == 9 || enemySH[i][j + 1] == 0 && j == 0) {
			if (enemySH[i+1][j ] != 0  && i == 0) {
				if (z > 0) {
					fieldG[i][j].changet("img/CVB.png");
				}
				else if (z < 0) {
					fieldG[i][j].changet("img/RVB.png");
				}
				
			}
			else if (enemySH[i-1][j] == 0 ) {


			

				if (z > 0) {
					fieldG[i][j].changet("img/CVB.png");
				}
				else if (z < 0) {
					fieldG[i][j].changet("img/RVB.png");
				}
				
			}


			else if (enemySH[i-1][j ] != 0 && z > 0 && i == 9) {


				

				if (z > 0) {
					fieldG[i][j].changet("img/CVE.png");
				}
				else if (z < 0) {
					fieldG[i][j].changet("img/RVE.png");

				}


				
			}
			else if (enemySH[i + 1][j ] == 0 ) {

				if (z > 0) {
					fieldG[i][j].changet("img/CVE.png");
				}
				else if (z < 0) {
					fieldG[i][j].changet("img/RVE.png");
				}
				
			}
			else if (enemySH[i-1][j] != 0 && enemySH[i + 1][j] != 0 ) {



				if (z > 0) {
					fieldG[i][j].changet("img/CVM.png");
				}
				else if (z < 0) {
					fieldG[i][j].changet("img/RVM.png");
				}

				
			}


			}
			else {
				
				 if (enemySH[i][j + 1] != 0  && j == 0) {


					 if (z > 0) {
						 fieldG[i][j].changet("img/CGB.png");
					 }
					 else if (z < 0) {
						 fieldG[i][j].changet("img/RGB.png");
					 }

					
				}
				else if (enemySH[i][j - 1] == 0 ) {

					if (z > 0) {
						 fieldG[i][j].changet("img/CGB.png");
					 }
					else if (z < 0) {
						 fieldG[i][j].changet("img/RGB.png");
					 }

					
				}


				else if (enemySH[i][j - 1] != 0 && j == 9) {


					 if (z > 0) {
						 fieldG[i][j].changet("img/CGE.png");
					 }
					 else if (z < 0) {
						 fieldG[i][j].changet("img/RGE.png");
					 }



					
				}
				else if (enemySH[i][j + 1] == 0 ) {



					 if (z > 0) {
						 fieldG[i][j].changet("img/CGE.png");
					 }
					 else if (z < 0) {
						 fieldG[i][j].changet("img/RGE.png");
					 }

					
				}
				else if (enemySH[i][j - 1] != 0 && enemySH[i][j + 1] != 0 ) {

					 if (z > 0) {
						 fieldG[i][j].changet("img/CGM.png");
					 }
					 else if(z<0){
						 fieldG[i][j].changet("img/RGM.png");
					 }


					
				}


			}
			}
			
		}
	
	
	
	
	}





bool MYfield::infield(Event& event, Vector2f pos)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (fieldG[i][j].mousein(event, pos)&& enemySH[i][j]==0) {
				
				p = i;
					o = j;
				in = true;
				return true;
				
				
				
			}
		}
	
	}
	in = false;
	
	return false;

}

void MYfield::setka(ship* Q)
{
	pal = Q->deck;
	if (in == true) {
		if (Q->vert == false) {


			if (o>10-pal)
			{
				
				Q->Y = fieldG[p][o].getposy();
				Q->X = fieldG[p][o-pal+1].getposx() ;

			}
			else {


				Q->X = fieldG[p][o].getposx();
				Q->Y = fieldG[p][o].getposy();
			}
			
			
		
		}
		else {
			


			if (p > 10 - pal)
			{

				Q->X = fieldG[p][o].getposx() + 64;
				Q->Y = fieldG[p-pal+1][o].getposy();

			}
			else {

				Q->X = fieldG[p][o].getposx() + 64;
				Q->Y = fieldG[p][o].getposy();
				
			}
				
			

		}
	}
	if (Q->insh == true && PRS == true && enemySH[p][o] == 0) {

		if (pal == 1) {
			enemySH[p][o] = pal;
		}
		else{
		if (Q->vert == false) {

			while (o > 10 - pal)
			{
				o--;
			}
			for (int i = o; i < pal + o; i++) {
				enemySH[p][i] = pal;
			}
			

		}
		else {
			while (p > 10 - pal)
			{
				p--;
			}
			for (int i = p; i < pal + p; i++) {
				enemySH[i][o] = pal;
			}
			



		}


	}

	}
	pal = 0;
	
}


bool MYfield::pressed11(Event& event, Vector2f pos)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {


			if (fieldG[i][j].pressed(event, pos)==true) {
				
				PRS = true;
				return true;




			}
		}
		
	}
	
	
	PRS = false;
	return false;

}




