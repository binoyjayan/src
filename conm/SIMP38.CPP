#include<iostream.h>
#include<conio.h>
class simp
{
  float a,b,n,sol,sol1,h,x0,y[50];
  int i;
  float integral();
public:
  friend float f(float);
  void reed();
  void print();
};
void simp::reed()
{
  cout<<"GIVEN:f(x)=1/(1+x)";
  cout<<"\nENTER RANGE OF INTEGRAL - a,b:\n";
  cin>>a>>b;
  cout<<"ENTER THE VALUE OF h:";
  cin>>h;
  n=(b-a)/h;
}
float f(float x)
{
  return (1/(1+x));
}
float simp::integral()
{
   x0=a;
   for(i=0;i<=n;i++)
   {
      y[i]=f(x0);
      x0+=h;
   }
   sol=sol1=0;
   for(i=1;i<n;i++)        //y0  & yn are calculated seperately
   {
      if(i%3)
	sol+=y[i];
      else
	sol1+=y[i];
   }
   sol*=3;
   sol1*=2;
   sol+=sol1+y[0]+y[n];
   sol*=3*h/8;
   return sol;
}
void simp::print()
{
  cout<<"INTEGRAL = "<<integral();
  getch();
}
void main()
{
  clrscr();
  simp son;
  son.reed();
  son.print();
}