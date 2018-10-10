#include<iostream.h>
#include<conio.h>
#include<process.h>

#define SQ(a) ((a)*(a))
#define CUBE(a) ((a)*(a)*(a))
class bisect
{
   unsigned int flag,iterations,i;
   float a,b,c,d,a1,b1,x,prev,f1,f2,avg;
   float f(float);
 public:
   bisect();
   void read();
   void findlimits();
   void solution();
};
bisect::bisect()
{
  iterations=flag=0;
}
void bisect::read()
{
  cout<<"ENTER THE COEFFICIENTS\n";
  cin>>a>>b>>c>>d;
}
float bisect::f(float x)
{
	return (a*CUBE(x)+b*SQ(x)+c*x+d);
}
void bisect::findlimits()
{
	while(flag==0)
	{
		f1=f(x);
		if(f1==0)
		{
			cout<<"\nTHE SOLUTION IS : "<<x;
			getch();
			exit(0);
		}
		if(f1<0)
		{
			prev=x;x++;
			f2=f(x);
			if(f2>0)
			{
				a1=prev;b1=x;
				flag=1;
			}
		}
		if(f1>0)
		{
			prev=x;x--;
			f2=f(x);
			if(f2<0)
			{
				a1=x;b1=prev;
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
void bisect::solution()
{
	cout<<"\na = "<<a1<<" where f(a) is negative";
	cout<<"\nb = "<<b1<<" where f(b) is positive";
	for(i=0;i<20;i++)
	{
		avg=(a1+b1)/2;
		f1=f(avg);
		if(f1<0)
		   a1=avg;
		else if(f1>0)
		   b1=avg;
		else
		   break;
	}
	cout<<"\nTHE SOLUTION IS: "<<avg;
	getch();
}
void main()
{
  bisect b;
  clrscr();
  b.read();
  b.findlimits();
  b.solution();
}
