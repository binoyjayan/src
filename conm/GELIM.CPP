#include<iostream.h>
#include<conio.h>
#include<math.h>
class gauss
{
  float e1[4],e2[4],e3[4];
  float e4[4],e5[4],e6[4];
  float x,y,z;
  int i;
public:
  void read();
  void gauss::process();
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
////////////////////step1 begins//////////
    for(i=0;i<4;i++)
      e4[i]=e1[i]*e2[0]/e1[0];
    for(i=0;i<4;i++)
       e5[i]=e2[i]-e4[i];
    for(i=0;i<4;i++)
       e6[i]=e1[i]*e3[0]/e1[0];
    for(i=0;i<4;i++)
       e3[i]-=e6[i];
/////////////updating equations//////////
    for(i=0;i<4;i++)
      e2[i]=e5[i];
////////////////////step2 begins//////////
    for(i=0;i<4;i++)
      e4[i]=e2[i]*e3[1]/e2[1];
   ///if(e2[0])
    for(i=0;i<4;i++)
      e3[i]-=e4[i];
////////////////////////step3////////////
    z=e3[3]/e3[2];
    y=(e2[3]-e2[2]*z)/e2[1];
    x=(e1[3]-e1[2]*z-e1[1]*y)/e1[0];
}
void gauss::print()
{
   cout<<"\nTHE SOLUTION IS AS FOLLOWS:";
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