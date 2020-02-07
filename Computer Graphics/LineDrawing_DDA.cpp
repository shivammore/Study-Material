#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;


inline float D_Of(float B,float A,float D){
	return ((B-A)/D);
}


inline int sign(float B){
		return ((B<0)?-1:((B==0)?0:1));
}


int main(){
	float x1=0,y1=0,x2=50,y2=50;
	cout<<"\nLine Drawing Using DDA\nEnter X1 Y1 X2 Y2 = \t";
	cin>>x1>>y1>>x2>>y2;
	delay(2000);
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	//DDA
	{
		
		float dX,dY;
		
		dX= abs(x2-x1);
		dY= abs(y2-y1);

		float length = ((dX>=dY)?dX:dY);
		
		dX= D_Of(x2,x1,length);
		dY= D_Of(y2,y1,length);	
		
		float pX, pY;
		
		pX=x1+(0.5*sign(dX));
		pY=y1+(0.5*sign(dY));		
		
		putpixel(pX,pY,WHITE);
		
		float i=1;
		while(i<=length)
		{
			
			
			pX+=(dX);
			pY+=(dY);
			
			putpixel(pX,pY,WHITE);
			i++;
		}
		
	}
	
	delay(50000);
	closegraph();
	getch();
}
