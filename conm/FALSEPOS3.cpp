////////////////////////////////////////////////////////////////////////////
/////////////////////////////FALSE POSITION METHOD//////////////////////////
////////////////////////////////////////////////////////////////////////////
#include<iostream.h>
#include<conio.h>
#include<process.h>

#define SQ(a) ((a)*(a))
#define CUBE(a) ((a)*(a)*(a))
class false
{
   unsigned int flag,iterations,i;
   float a,b,c,d,x0,x1,x,prev,f1,f2,mid;
   float f(float);
   float value(float,float);
 public:
   false();
   void read();
   void findlimits();
   void solution();
};
false::false()
{
  iterations=flag=0;
}
void false::read()
{
  cout<<"ENTER THE COEFFICIENTS\n";
  cin>>a>>b>>c>>d;
}
float false::f(float x)
{
	return (a*CUBE(x)+b*SQ(x)+c*x+d);
}
float false::value(float x0,float x1)
{
	return (x0-f(x0)*(x1-x0)/(f(x1)-f(x0)));
}
void false::findlimits()
{
	while(!flag)
	{
		f1=f(x);
		if(f1==0)
		{
			cout<<"\nTHE SOLUTION IS "<<x;
			getch();
			exit(0);
		}
		if(f1<0)
		{
			prev=x;x++;
			f2=f(x);
			if(f2>0)
			{
				x0=prev;x1=x;
				flag=1;
			}
		}
		if(f1>0)
		{
			prev=x;x--;
			f2=f(x);
			if(f2<0)
			{
				x0=x;x1=prev;
				flag=1;
			}
		}
		iterations++;
		if(iterations>100)
		{
			cout<<"\nCOMPLEX ROOTS";
			exit(0);
		}
	}
}
void false::solution()
{
	cout<<"\na = "<<x0<<" where f(a) is negative";
	cout<<"\nb = "<<x1<<" where f(b) is positive";
	for(i=0;i<20;i++)
	{
		mid=value(x0,x1);
		f1=f(mid);
		if(f1<0)
		   x0=mid;
		else if(f1>0)
		   x1=mid;
		else
		   break;
	}
	cout<<"\nTHE SOLUTION IS: "<<mid;
	getch();
}
void main()
{
  false position;
  clrscr();
  position.read();
  position.findlimits();
  position.solution();
}
