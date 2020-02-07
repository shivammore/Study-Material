#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;

class Line{	
public:
	inline int sign(int v1,int v2)
	{
		return((v1==v2)?0:((v1>v2)?-1:1));	
	}

	void drawbline(int x1, int y1, int x2, int y2){
		int Dx, Dy, E, ICValue=0, I;
	
		int X  = x1;
		int Xs =sign(x1,x2);
		int Y  = y1;
		int Ys = sign(y1,y2);
	
		Dx = abs(x2 - x1);
		Dy = abs(y2 - y1);
	
		if(Dy>Dx)
			{
				ICValue = 1;
			
				int Temp = Dx;
				Dx = Dy;
				Dy = Temp;		
		
			}
		
		E = 2*Dy - Dx;
	
		for(I=0; I<=Dy; I++)
		{
			putpixel(X,Y,WHITE);
		
			while(E>0)
			{
				if(ICValue){	
					X+=Xs;
				}
				else{
					Y+=Ys;
				}
				E-=2*Dx;
			}
		
			if(ICValue)
				Y+=Ys;
			else
				X+=Xs;
			E+=2*Dy;
		}
	
		cout<<"\nLine Plotted Using Bresenahms Line Drawing Algorithm";
	}
};






int main()
{
	int gd = DETECT,gm;
	int x1,x2,y1,y2;
	
	cout<<"Enter X1,Y1 and X2,Y2 = ";
	cin>>x1>>y1>>x2>>y2;
	
	Line L;
	
	initgraph(&gd,&gm,NULL);
	
	L.drawbline(x1,y1,x2,y2);	
	
	delay(10000);
	closegraph();	
	getch();
}
