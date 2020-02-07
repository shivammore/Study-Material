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

		int sign(int v1,int v2)
		{
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
		
		
		
		void drawLine(int x1, int y1, int x2, int y2, int drawtype)
		{
			//Bressenham's Algo:
			
			int Dx, Dy, E, ICValue=0, I;
			int drawingmode = drawtype;
			initgraph(&gd,&gm,NULL);
			int X  = x1;
			int Xs =sign(x1,x2);
			int Y  = y1;
			int Ys = sign(y1,y2);
			int print;
	
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
				
			print = 0;
				
			int j=-2,k=0,l=3;	
				
			for(I=0; I<=Dy; I++)
			{	

				switch(drawingmode){
				
				case 0:
					putpixel(X,Y,WHITE);			//Simple Bresenahms Line Drawing
					break;
				
				case 1:
					if(I%2 == 0)
						putpixel(X,Y,WHITE);		//Dotted Line Drawing
					break;
				
				case 2:
					if(I%5 != 0)
						putpixel(X,Y,WHITE);		//Dashed Line
					break;
				
				case 3:
					if(!((I)%7 == 5 || (I)%7 == 0))		//Dash-Dot-Dash Line
						putpixel(X,Y,WHITE);
					break;
				
				default:
					break;
				}
		
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

int main(){

	int ch;
	Shape B;
	int x1,x2,y1,y2,dm;	

	cout<<"\nLine Drawing Algorithms\nChoose Algorithm-";
	do{
		cout<<"\n\t1)DDA\n\t2)Bressenhams\n\t3)DotLine Drawing\n\t=> ";
		cin>>ch;

		switch(ch)
		{
		case 1: 
			B.drawLine();
			break;
		case 2: 
			cout<<"\nEnter X1,Y1 and X2,Y2 Values For Line Drawing Using Bressenhams Algorithm\n\t=> ";
			cin>>x1>>y1>>x2>>y2;
			B.drawLine(x1,y1,x2,y2,0);
			break;
		case 3: 		
			cout<<"\nChoose Style :\n1)Dotted .....\n2)Dashed _ _ _\n3)Dash Dot _ . _ \n=> ";		
			cin>>dm;				
			cout<<"\nEnter X1,Y1 and X2,Y2 Values For Styled Line Drawing\n";
			cin>>x1>>y1>>x2>>y2;
			B.drawLine(x1,y1,x2,y2,dm);
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
