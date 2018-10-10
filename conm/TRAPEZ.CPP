#include<iostream.h>
#include<conio.h>
class trapez
{
  float a,b,n,sol,h,x0,y[50];
  int i;
  float integral();
public:
  friend float f(float);
  void reed();
  void print();
};
void trapez::reed()
{
  cout<<"GIVEN:f(x)=1/(1+x)";
  cout<<"\nEnter range of integral - a,b:\n";
  cin>>a>>b;
  cout<<"Enter the no: of sub intervals:";
  cin>>n;
}
float f(float x)
{
  return (1/(1+x));
}
float trapez::integral()
{
   h=(b-a)/n;
   x0=a;
   for(i=0;i<=n;i++)
   {
      y[i]=f(x0);
      x0+=h;
   }
   for(sol=0,i=1;i<n;i++)        //y0  & yn are calculated seperately
      sol+=y[i];
   sol*=2;
   sol+=y[0]+y[n];
   sol*=h/2;
   return sol;
}
void trapez::print()
{
  cout<<"INTEGRAL = "<<integral();
  getch();
}
void main()
{
  clrscr();
  trapez t;
  t.reed();
  t.print();
}