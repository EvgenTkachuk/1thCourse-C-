#include <conio.h>
#include <stdio.h>
int main()
{
const int n=10;
float mas[n];
int counter=0, i, j;
for (i=0;i<n;i++)
{
printf("Input mas[%d]=",i+1);
scanf("%f",&mas[i]);
}
for (i=0;i<n;i++)
{
counter=0;
for (j=0;j<n;j++)
if (mas[i]==mas[j]) counter++;
printf( "\nValue %4.2f includes in an array %d times",
mas[i],counter);
}
getch();
return 0;
}

