#include<iostream>
#include<stdio.h>
#include<graphics.h>

using namespace std;
int gd = DETECT,gm;

class Pixel{
	public:
		float D_Of(float B,float A,float D){
			return ((B-A)/D);
		}
		int sign(float B){
			return ((B<0)?-1:((B==0)?0:1));
		}
		int sign(int v1,int v2){
			return((v1==v2)?0:((v1>v2)?-1:1));	
		}
};

class Shape : public Pixel
{
	public:
		void drawLine()
		{
			//DDA Algorithm
			float x1,y1,x2,y2;
			cout<<"\n\nEnter X1,Y1 and X2,Y2 Values For Line Drawing Using DDA Algorithm\n\t=> ";
			cin>>x1>>y1>>x2>>y2;
			delay(2000);
			int gd = DETECT,gm;
			initgraph(&gd,&gm,NULL);
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
			cout<<"\nLine Plotted Using DDA Line Drawing Algorithm";
			delay(20000);
			closegraph();
		}
			
		void drawLine(int x1, int y1, int x2, int y2)
		{
			int Dx, Dy, E, ICValue=0, I;
			initgraph(&gd,&gm,NULL);
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
			cout<<"\nLine Plotted Using Bressenahms Line Drawing Algorithm";
			delay(20000);
			closegraph();
		}
};

/*
void drawPoly(int Total_Sides)
{
	int Xi=50,Yi=90,Xt=90,Yt=50,Xn=90,Yn=90;
	int Sides = Total_Sides;

	if(Sides>2){
		initgraph(&gd,&gm,NULL);
		Shape D;
		

		cout<<"\nEnter Intial X And Y => ";
		cin>>Xi>>Yi;
		
		cout<<"\nEnter Next X And Y => ";
		cin>>Xt>>Yt;
				
		
			
		D.drawLine(Xi,Yi,Xt,Yt);
				
		cout<<"\nEnter Next X And Y => ";
		cin>>Xn>>Yn;
		
		D.drawLine(Xt,Yt,Xn,Yn);
		
				
		while((Sides-3)>0)
		{
			Xt = Xn;
			Yt = Yn;
			
			cout<<"\nEnter Next X And Y => ";
			cin>>Xn>>Yn;
			D.drawLine(Xt,Yt,Xn,Yn);
			Sides--;
		}
		
		D.drawLine(Xi,Yi,Xn,Yn);
		
		delay(20000);
		closegraph();	
	}
	else
		cout<<"\n#Not Polygon\n";
}
*/

int main(){

	int ch;
	cout<<"\nLine Drawing Algorithms\nChoose Algorithm-";
	do{
		cout<<"\n\t1)DDA\n\t2)Bressenhams\n\t3)Polygon Drawing\n\t=> ";
		cin>>ch;

		switch(ch)
		{
		case 1: 

			Shape D;
			D.drawLine();
			break;
		case 2: 
			Shape B;
			int x1,x2,y1,y2;
			cout<<"\nUndeveloped";
			//cout<<"\nEnter X1,Y1 and X2,Y2 Values For Line Drawing Using Bressenhams Algorithm\n\t=> ";
			//cin>>x1>>y1>>x2>>y2;
			//B.drawLine(x1,y1,x2,y2);
			break;
		case 3: 
			cout<<"\nEnter Number Of Polygon Sides\n";
			int s;
			cin>>s;
			drawPoly(s);
			break;
		default:
			cout<<"\nIncorrect Choice";
		}
		cout<<"\n#For Continue Enter 0 => ";
		cin>>ch;
	}while(ch==0);
	delay(20000);
	getch();
}
