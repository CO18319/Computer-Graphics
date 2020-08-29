#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>
#define MAX 100000

using namespace std;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	
	int x, y;
	int x1, y1, x2, y2;
	cout<<"\nEnter the coordinates of point (x, y) \n";
	cin>>x>>y;
	cout<<"\nEnter the points of line (x1, y1), (x2, y2)\n";
	cin>>x1>>y1>>x2>>y2;
	
	//calculate the slope and inetcept values of line
	float slope;
	
	if ( x2 - x1 == 0 ) 	slope = MAX;
	else 	slope = float( y2 - y1 ) / ( x2 - x1 );
	
	int intercept = ( y1 - round( slope * x1 ));
	
	cout<<"\nEquation of line connecting the points ("<<x1<<", "<<y1<<") and ("<<x2<<", "<<y2<<")";

	if ( slope == MAX ) 	printf("\n\t x = %d\n", x1);
	else 	printf("\n\t y = %.2f x %c %d\n",slope, (intercept<0?' ':'+'), intercept);

    //to check if point lies on the line
    //if we round slope here, we might face stair effect as in reality the point needs to be placed on the line but for decimal values the answer might vary for y
    if(round(slope * x) + intercept == y)
		cout<<"\n The point ("<<x<<", "<<y<<") lies on the line";
    else
	{
		cout<<"\n The point ("<<x<<", "<<y<<") lies in";
	    
		//to compare the point wrt to line
	  
	    // UPPER /LOWER
	    //the object closer to origin is considered at top i.e. if point is closer to origin it is top, if line closert to origin than line is upper
	    //(lx, ly) point on the line taken for comparison
	    int lx = x;
	    int ly = round(slope * x) + intercept;
	    
		if(( ly > y )&&( slope != MAX ))	cout<<" Upper";
	    else if( slope != MAX )		cout<<" Lower";
	
	    // LEFT / RIGHT
	    ly = y;
	    lx = round(( ly - intercept ) / slope);
	    if(( lx > x  )&&( slope != 0 )) 	cout<<" Left";
	    else if( slope != 0 )		cout<<" Right";
	
	}
	putpixel(x+100,y+100,RED);
	setcolor(2);
	line(x1+100,y1+100,x2+100,y2+100);

    getch();
    closegraph();
}
