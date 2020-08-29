#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

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

	int x = 0, y = r; // Temp Variables for calculations
	
	// Calculating Decision Parameter
	int p = 3 - ( 2 * r ); 
	
	// Drawing Circle
	for( x = 0; x <= y; x++)
	{
		if( p < 0 )
		{
			y = y;
			p = ( p + ( 4 * x ) + 6 );
		}
		else
		{
			y = y - 1;
			p = p + ( 4 * ( x - y ) + 10);  
		}
		putpixel( xc + x , yc + y, 5);
		putpixel( xc - y , yc - x, 5);
		putpixel( xc + y , yc - x, 5);
		putpixel( xc - y , yc + x, 5);
		putpixel( xc + y , yc + x, 5);
		putpixel( xc - x , yc - y, 5);
		putpixel( xc + x , yc - y, 5);
		putpixel( xc - x , yc + y, 5);
	}
	
    getch(); 
    closegraph();
}

