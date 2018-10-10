#include<iostream.h>
#include<conio.h>
#include<math.h>
class gauss
{
  float e1[4],e2[4],e3[4];
  float x,y,z;
  int i;
public:
  void read();
  void process();
  void print();
};
void gauss::read()
{
   cout<<"\nENTER THE COEFFICIENTS OF EQ.1:\n";
   cin>>e1[0]>>e1[1]>>e1[2]>>e1[3];
   cout<<"\nENTER THE COEFFICIENTS OF EQ.2:\n";
   cin>>e2[0]>>e2[1]>>e2[2]>>e2[3];
   cout<<"\nENTER THE COEFFICIENTS OF EQ.3:\n";
   cin>>e3[0]>>e3[1]>>e3[2]>>e3[3];
}
void gauss::process()
{
   x=y=z=0;
   for(i=0;i<20;i++)
   {
       x=(e1[3]-e1[1]*y-e1[2]*z)/e1[0];
       y=(e2[3]-e2[0]*x-e2[2]*z)/e2[1];
       z=(e3[3]-e3[0]*x-e3[1]*y)/e3[2];
   }
}
void gauss::print()
{
   cout<<"\nX = "<<x;
   cout<<"\nY = "<<y;
   cout<<"\nZ = "<<z;
   getch();
}
void main()
{
  clrscr();
  gauss e;
  e.read();
  e.process();
  e.print();
}