#include<iostream.h>
#include<conio.h>
class euler
{
  float x0,y0,x1,y1,x,h,n;
  int i;
  float gety();
public:
  friend float f(float,float);
  void reed();
  void print();
};
void euler::reed()
{
  cout<<"GIVEN:\ndy/dx = x+2y";
  cout<<"\nEnter values for x0,y0,h\n";
  cin>>x0>>y0>>h;
  cout<<"Enter f(???...) : ";
  cin>>x;
}
float f(float x,float y)
{
  return (x +2*y);
}
float euler::gety()
{
  n=(x-x0)/h;
  for(i=0;i<n;i++)
  {
    x1=x0+h;
    y1=y0+f(x0,y0)*(x1-x0);
    x0=x1;
    y0=y1;
  }
  return y0;
}
void euler::print()
{
  cout<<"f("<<x<<") = "<<gety();
  getch();
}
void main()
{
  clrscr();
  euler method;
  method.reed();
  method.print();
}