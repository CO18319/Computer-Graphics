#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	
	// Input values for coordinates of the center and radius.
	int xc, yc, r;
	cout<<" Enter the coordinates of the center of the circle";
	cout<<"\n ( x,y )\n";
	cin>>xc>>yc;
	cout<<" Enter the radius of the circle\n";
	cin>>r;

	int x = xc, y = yc; // Temp Variables for calculations

	// Calculating Decision Parameter
	float d = 1.25 - r;
	y = r;
	x = 0;
	do
	{
		if(d<0.0)
		{
			x = x + 1;
			d = d + 2 * x + 1;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			d = d + 2 * x - 2 * y + 10;
		}
		putpixel( xc + x , yc + y, 5);
		putpixel( xc - y , yc - x, 5);
		putpixel( xc + y , yc - x, 5);
		putpixel( xc - y , yc + x, 5);
		putpixel( xc + y , yc + x, 5);
		putpixel( xc - x , yc - y, 5);
		putpixel( xc + x , yc - y, 5);
		putpixel( xc - x , yc + y, 5);
	}while( x < y );
	
    getch(); 
    closegraph();
}

