#include "field.h"

field::field(float x, float y)
{ 
	
	fieldG[0][0].setpos(x, y);
	
}

void field::mydraw(RenderWindow& window)//отрисовка
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			fieldG[i ][j+1].setpos(fieldG[i][j].getposx() + 64, fieldG[0][0].getposy()+ i * 64);
			fieldG[i][j].mydraw(window);
		}
		fieldG[i + 1][0].setpos(fieldG[0][0].getposx(), fieldG[0][0].getposy() +(i+1) * 64);
	}
	for (int i = 0; i < 9; i++) {
		fieldG[9][i].setpos(fieldG[8][i].getposx(), fieldG[8][i].getposy() + 64);
		fieldG[9][i].mydraw(window);
	}
	for (int i = 0; i < 10; i++) {
		fieldG[i][9].setpos(fieldG[i][8].getposx() + 64, fieldG[i][8].getposy() );
		fieldG[i][9].mydraw(window);
	}
	
}
void field::setmass(int* mass)//задать массив
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			enemySH[i][j] = mass[i * 10 + j];

		} 
	}
	
}
field::field()
{
	fieldG[0][0].setpos(0, 0);
}
bool field::dest(int l, int z)//проверка разрушения
{
	int i = l / 10;
	int j = l % 10;
	int o = 0;
	if (mvertical(l,z) == false) {
		while (o != z)
		{

			if (enemySH[i][j + o] != z) {

				return false;

			}
			o--;
		}
	}
	else
	{
		while (o != z*10)
		{

			if (enemySH[i][j + o] != z) {

				return false;

			}
			o = o - 10;
		}
	}
	return true;
}

bool field::pressed11(Event& event, Vector2f  pos)//замена спрайта при нажатии на елемент поля
{
	
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				
				
				if (fieldG[i][j].pressed(event, pos) ) {
			
					if (enemySH[i][j] == 0) {
						fieldG[i][j].changet("img/13.png");
						return true;
					}
				else
				{
					fieldG[i][j].changet("img/p.png");
					enemySH[i][j] = -enemySH[i][j];
					loc = i * 10 + j;
					obl(enemySH[i][j], loc);
					return true;
				}
					
				}
			}
		}
		return false;
}

void field::getarr(int* mass)
{

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mass[i * 10 + j]=enemySH[i][j] ;

		}
	}
	
}


bool field::mvertical(int loc, int z) //проверка ВЕРТИКАЛЬНОСТИ
{
	

	int iE = loc / 10;
	int jE = loc % 10;

	
	if (jE  == 0) {
		if (enemySH[iE][jE +1 ] != 0  || z == -1) {
			
			return false;
		}
	
	}
	else if(jE==9)
	{
		if ((enemySH[iE][jE - 1] != 0) || z == -1) {
			
			return false;
		}
	}
	else {
		if (enemySH[iE][jE + 1] != 0 || (enemySH[iE][jE - 1] != 0) || z == -1) {
			
			return false;
		}
	}
	  return true; 
}





void field::obl(int z, int l)
{
	int iE = l / 10;
	int jE = l % 10;
	if (z == -1) {
		fieldG[iE][jE].changet("img/RO.png");
		if (l == 0) {
			fieldG[iE + 1][jE + 1].changet("img/13.png");
			fieldG[iE][jE + 1].changet("img/13.png");
			fieldG[iE + 1][jE].changet("img/13.png");

		}
		else if (l == 9) {
			fieldG[iE + 1][jE - 1].changet("img/13.png");
			fieldG[iE][jE - 1].changet("img/13.png");
			fieldG[iE + 1][jE].changet("img/13.png");
		}
		else if (l == 90) {
			fieldG[iE - 1][jE + 1].changet("img/13.png");
			fieldG[iE - 1][jE].changet("img/13.png");
			fieldG[iE][jE + 1].changet("img/13.png");
		}
		else if (l == 99) {
			fieldG[iE - 1][jE - 1].changet("img/13.png");
			fieldG[iE - 1][jE].changet("img/13.png");
			fieldG[iE][jE - 1].changet("img/13.png");
		}
		else if (jE == 0) {
			fieldG[iE + 1][jE + 1].changet("img/13.png");
			fieldG[iE - 1][jE + 1].changet("img/13.png");
			fieldG[iE - 1][jE].changet("img/13.png");
			fieldG[iE][jE + 1].changet("img/13.png");
			fieldG[iE + 1][jE].changet("img/13.png");


		}
		else if (jE == 9) {
			fieldG[iE + 1][jE].changet("img/13.png");
			fieldG[iE - 1][jE - 1].changet("img/13.png");
			fieldG[iE - 1][jE].changet("img/13.png");
			fieldG[iE][jE - 1].changet("img/13.png");
			fieldG[iE + 1][jE - 1].changet("img/13.png");
		}
		else if (iE == 9) {
			fieldG[iE][jE - 1].changet("img/13.png");
			fieldG[iE - 1][jE + 1].changet("img/13.png");
			fieldG[iE - 1][jE].changet("img/13.png");
			fieldG[iE][jE + 1].changet("img/13.png");
			fieldG[iE - 1][jE - 1].changet("img/13.png");
		}
		else if (iE == 0) {
			fieldG[iE][jE - 1].changet("img/13.png");
			fieldG[iE + 1][jE + 1].changet("img/13.png");
			fieldG[iE + 1][jE].changet("img/13.png");
			fieldG[iE][jE + 1].changet("img/13.png");
			fieldG[iE + 1][jE - 1].changet("img/13.png");
		}
		else {
			fieldG[iE + 1][jE + 1].changet("img/13.png");
			fieldG[iE - 1][jE + 1].changet("img/13.png");
			fieldG[iE - 1][jE - 1].changet("img/13.png");
			fieldG[iE + 1][jE - 1].changet("img/13.png");
			fieldG[iE + 1][jE].changet("img/13.png");
			fieldG[iE - 1][jE].changet("img/13.png");
			fieldG[iE][jE + 1].changet("img/13.png");
			fieldG[iE][jE - 1].changet("img/13.png");
		}
	}
	else if(mvertical(l,z)==false) {

		while (enemySH[l / 10][l % 10 + 1] != 0 && l%10!=9)
		{
			l++;
		}


		
		iE = l / 10;
		jE = l % 10;
		
		if (l + z+1== 0) {
			
			
			int v = -z;
			
			if (dest(l, z) == true) {
				while (v != 0) {

					fieldG[iE][jE-v+1].changet("img/RGM.png");
					fieldG[iE + 1][jE - v + 1].changet("img/13.png");
					v--;
					
				}
					fieldG[iE + 1][jE + 1].changet("img/13.png");
					fieldG[iE][jE + 1].changet("img/13.png");
					fieldG[iE][jE].changet("img/RGE.png");
					fieldG[iE][jE+z+1].changet("img/RGB.png");
			}
		}
		else if (l + z +1 == 90) {
			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE][jE - v + 1].changet("img/RGM.png");

					fieldG[iE - 1][jE - v + 1].changet("img/13.png");
					v--;
					
				}
					fieldG[iE - 1][jE + 1].changet("img/13.png");
					fieldG[iE][jE + 1].changet("img/13.png");
					fieldG[iE][jE].changet("img/RGE.png");
					fieldG[iE][jE + z + 1].changet("img/RGB.png");
			}
		
		}
		else if (l  == 99) {
			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {

					fieldG[iE][jE - v + 1].changet("img/RGM.png");
					fieldG[iE - 1][jE - v + 1].changet("img/13.png");
					v--;
					
				}
					fieldG[iE - 1][jE +z].changet("img/13.png");
					fieldG[iE][jE + z ].changet("img/13.png");
					fieldG[iE][jE].changet("img/RGE.png");
					fieldG[iE][jE + z + 1].changet("img/RGB.png");
			}

		}
		else if (l  == 9) {

			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE][jE - v + 1].changet("img/RGM.png");
					fieldG[iE + 1][jE - v + 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE + 1][jE + z].changet("img/13.png");
				fieldG[iE][jE + z].changet("img/13.png");
				fieldG[iE][jE].changet("img/RGE.png");
				fieldG[iE][jE + z + 1].changet("img/RGB.png");
				
			}
		}
		else if (jE == 9 && iE != 0 && iE != 9) {
			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE][jE - v + 1].changet("img/RGM.png");
					fieldG[iE - 1][jE - v + 1].changet("img/13.png");
					fieldG[iE + 1][jE - v + 1].changet("img/13.png");
					v--;
					
				}
				
				fieldG[iE][jE + z].changet("img/13.png");
				fieldG[iE + 1][jE + z].changet("img/13.png");
				fieldG[iE - 1][jE + z].changet("img/13.png");
				fieldG[iE][jE].changet("img/RGE.png");
				fieldG[iE][jE + z + 1].changet("img/RGB.png");
			}
		}
		else if (jE+z+1 == 0 && iE != 0 && iE != 9) {
			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE][jE - v + 1].changet("img/RGM.png");
					fieldG[iE - 1][jE - v + 1].changet("img/13.png");
					fieldG[iE + 1][jE - v + 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE + 1][jE +1].changet("img/13.png");
				fieldG[iE][jE+1 ].changet("img/13.png");
				fieldG[iE][jE].changet("img/RGE.png");
				fieldG[iE - 1][jE +1].changet("img/13.png");
				fieldG[iE][jE + z + 1].changet("img/RGB.png");
			}
		}
		else if ( iE == 0 ) {
			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE][jE - v + 1].changet("img/RGM.png");
					
					fieldG[iE + 1][jE - v + 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE][jE + z].changet("img/13.png");
				fieldG[iE + 1][jE + z].changet("img/13.png");
				fieldG[iE + 1][jE + 1].changet("img/13.png");
				fieldG[iE][jE + 1].changet("img/13.png");
				fieldG[iE][jE].changet("img/RGE.png");
				fieldG[iE][jE + z + 1].changet("img/RGB.png");
			}
			}
		else if (iE == 9) {
			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {

					fieldG[iE][jE - v + 1].changet("img/RGM.png");
					fieldG[iE - 1][jE - v + 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE][jE + z].changet("img/13.png");
				fieldG[iE - 1][jE + z].changet("img/13.png");
				fieldG[iE - 1][jE + 1].changet("img/13.png");
				fieldG[iE][jE + 1].changet("img/13.png");
				fieldG[iE][jE].changet("img/RGE.png");
				fieldG[iE][jE + z + 1].changet("img/RGB.png");
			}
			}
		else
		{
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE][jE - v + 1].changet("img/RGM.png");
					fieldG[iE - 1][jE - v + 1].changet("img/13.png");
					fieldG[iE + 1][jE - v + 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE + 1][jE + 1].changet("img/13.png");
				fieldG[iE][jE + 1].changet("img/13.png");
				fieldG[iE][jE].changet("img/RGE.png");
				fieldG[iE - 1][jE + 1].changet("img/13.png");
				fieldG[iE][jE + z].changet("img/13.png");
				fieldG[iE + 1][jE + z].changet("img/13.png");
				fieldG[iE][jE + z + 1].changet("img/RGB.png");
				fieldG[iE - 1][jE + z].changet("img/13.png");
				
				
			}
		}
		counter = 0;
	}
	else {
		while (enemySH[l / 10+1][l % 10 ] != 0 && l / 10 != 9)
		{
			l=l+10;
			
		}
		
		iE = l / 10;
		jE = l % 10;
		
		if (iE + z + 1 == 0&&jE==0) {

		
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {

					fieldG[iE - v + 1][jE].changet("img/RVM.png");
					fieldG[iE - v + 1][jE+1 ].changet("img/13.png");
					v--;
				
				}
				fieldG[iE + 1][jE + 1].changet("img/13.png");
				fieldG[iE+1][jE  ].changet("img/13.png");
				fieldG[iE][jE].changet("img/RVE.png");
				fieldG[iE + z + 1][jE].changet("img/RVB.png");
			}
		}
		else if (iE + z + 1 == 10+z&& jE==0) {

		
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {

					fieldG[iE - v + 1][jE].changet("img/RVM.png");
					fieldG[iE - v + 1][jE + 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE +z][jE + 1].changet("img/13.png");
				fieldG[iE + z][jE].changet("img/13.png");
				fieldG[iE][jE].changet("img/RVE.png");
				fieldG[iE + z + 1][jE].changet("img/RVB.png");
			}
		}
		else if(iE + z + 1 == 0&&jE==9) {

			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					 
					fieldG[iE - v + 1][jE].changet("img/RVM.png");
					fieldG[iE - v + 1][jE - 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE + 1][jE - 1].changet("img/13.png");
				fieldG[iE + 1][jE].changet("img/13.png");
				fieldG[iE][jE].changet("img/RVE.png");
				fieldG[iE + z + 1][jE].changet("img/RVB.png");
			}
		}
		else if (iE + z + 1== 10 + z && jE == 9) {

			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE - v + 1][jE].changet("img/RVM.png");
					 
					fieldG[iE - v + 1][jE - 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE + z][jE - 1].changet("img/13.png");
				fieldG[iE + z][jE].changet("img/13.png");
				fieldG[iE][jE].changet("img/RVE.png");
				fieldG[iE + z + 1][jE].changet("img/RVB.png");
			}
		}
		else if (iE + z + 1 == 0 ) {

			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE - v + 1][jE].changet("img/RVM.png");
					fieldG[iE - v + 1][jE + 1].changet("img/13.png");
					fieldG[iE - v + 1][jE - 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE + 1][jE - 1].changet("img/13.png");
				fieldG[iE + 1][jE].changet("img/13.png");
				fieldG[iE][jE].changet("img/RVE.png");
				fieldG[iE + 1][jE + 1].changet("img/13.png");
				fieldG[iE + z + 1][jE].changet("img/RVB.png");
			}
		}
		else if (iE + z + 1 == 10 + z) {

			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE - v + 1][jE].changet("img/RVM.png");
					fieldG[iE - v + 1][jE + 1].changet("img/13.png");
					fieldG[iE - v + 1][jE - 1].changet("img/13.png");
					v--;
					
				}
				fieldG[iE + z][jE - 1].changet("img/13.png");
				fieldG[iE + z][jE].changet("img/13.png");
				fieldG[iE + z][jE + 1].changet("img/13.png");
				fieldG[iE][jE].changet("img/RVE.png");
				fieldG[iE + z + 1][jE].changet("img/RVB.png");
			}
		}
		else if (jE==0) {

			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {

					fieldG[iE - v + 1][jE + 1].changet("img/13.png");
					fieldG[iE - v + 1][jE].changet("img/RVM.png");
					v--;
					
				}
				fieldG[iE][jE].changet("img/RVE.png");
				fieldG[iE + z][jE].changet("img/13.png");
				fieldG[iE + z][jE + 1].changet("img/13.png");
				fieldG[iE+1 ][jE].changet("img/13.png");
				fieldG[iE+1][jE + 1].changet("img/13.png");
				fieldG[iE + z + 1][jE].changet("img/RVB.png");
			}
			}
		else if (jE == 9) {

			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					fieldG[iE - v + 1][jE].changet("img/RVM.png");
					fieldG[iE - v + 1][jE - 1].changet("img/13.png");
					 
					v--;
					
				}
				fieldG[iE][jE].changet("img/RVE.png");
				fieldG[iE + z][jE].changet("img/13.png");
				fieldG[iE + z][jE - 1].changet("img/13.png");
				fieldG[iE + 1][jE].changet("img/13.png");
				fieldG[iE + 1][jE - 1].changet("img/13.png");
				fieldG[iE + z + 1][jE].changet("img/RVB.png");
			}
			}
		else {
			
			int v = -z;

			if (dest(l, z) == true) {
				while (v != 0) {
					 
					fieldG[iE - v + 1][jE + 1].changet("img/13.png");
					fieldG[iE - v + 1][jE - 1].changet("img/13.png");
					fieldG[iE - v + 1][jE].changet("img/RVM.png");
					v--;
					
				}
				fieldG[iE][jE].changet("img/RVE.png");

				fieldG[iE + z][jE].changet("img/13.png");
				fieldG[iE + z][jE + 1].changet("img/13.png");
				fieldG[iE + 1][jE].changet("img/13.png");
				fieldG[iE + 1][jE + 1].changet("img/13.png");
				fieldG[iE + 1][jE - 1].changet("img/13.png");
				fieldG[iE + z][jE - 1].changet("img/13.png");
				fieldG[iE + z + 1][jE ].changet("img/RVB.png");
			
			}
		}
	}

}

bool field::press(Event& event, Vector2f pos)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {


			if (fieldG[i][j].pressed(event, pos) == true) {

				
				return true;




			}
		}

	}


	
	return false;

}
int field::poluchel(Event& event, Vector2f pos)
{

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (fieldG[i][j].mousein(event, pos)) {
				return enemySH[i][j];
			}
			


		}
	}

	
}
	
int field::full()
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			sum += enemySH[i][j];
	return sum;
}