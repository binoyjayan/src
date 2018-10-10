#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<math.h>
class taylor
{
    int i,j,n;
    float x0,y0,x1,h,y,y1[10];
    float solution();
    void init();
 public:
    void read();
    void print();
};
void taylor::read()
{
   cout<<"\nGIVEN dy/dx = x-y^2\n";
   cout<<"\nENTER VALUES OF x0,y0 & x1:\n";
   cin>>x0>>y>>x1;
   cout<<"ENTER THE VALUE OF h:";
   cin>>h;
   n=(int)((x1-x0)/h);  // cout<<"\n n =  "<<n;
}
void taylor::init()
{
/*
   y1[1]=x0-y0;
   y1[2]=1+y1[1];
   y1[3]=y1[2];
   y1[4]=y1[3];
*/
   y1[1]=x0-y0*y0;
   y1[2]=1-2*y0*y1[1];
   y1[3]=-2*(y0*y1[2]+y1[1]*y1[1]);
   y1[4]=-2*(y0*y1[3]+y1[1]*y1[2]+2*y1[1]*y1[2]);
}
float taylor::solution()
{
    int fact=1;
    while(n--)
    {
	y0=y;
	init();
	for(i=1;i<=4;i++)
	{
		fact*=i;
		y+=pow(h,i)*y1[i]/fact;
	}
    }
    return y;
}
void taylor::print()
{
    cout<<"\nTHE SOLUTION IS :"<<solution();
    getch();
}
void main()
{
    clrscr();
    taylor t;
    t.read();
    t.print();
}