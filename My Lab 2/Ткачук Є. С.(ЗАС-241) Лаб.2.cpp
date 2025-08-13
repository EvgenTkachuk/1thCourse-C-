#include<stdio.h>
#include<math.h>
int main()
    {
	float a , b, x, y, xmin, xmax, dx;
	
	do
	{
	 printf("Input a(not<0):");
	 scanf("%f",&a);
	}while (a<0);
	
	do
	{
	 printf("Input b(not equal 0):");
	 scanf("%f",&b);
	}while(b<=0 );
	
	do
	{
	 printf("Input xmin<xmax:");
	 scanf("%f%f",&xmin,&xmax);
	}while(xmin>xmax || xmin==xmax);
	
	do
	{
	 printf("Input dx:");
	 scanf("%f",&dx);
	}while(dx<=0 || dx>(xmax-xmin));
	
	x=xmin;
	printf("X\t\tY\n");
	
	while (x<xmax)
{
     printf("%f\t", x);
      
	{
		y=2*(atan((25*a)/b))+(pow(cos(3),2)*((9*x*b)/b-x));
		printf("%f\n",y);
    }
    x=x+dx;
}
return 0;
}
