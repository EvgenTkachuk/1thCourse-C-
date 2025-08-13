#include<stdio.h>
#include<Math.h>
int main(){
    float c,d,x,y;
    printf("Input c and d:");
    scanf("%f%f",&c,&d);
    printf("Input x and y:");
    scanf("%f%f",&x,&y);
    if(d-c && x<0 && y>0)
    printf("Point is in area A");
    else
    if(d-c && x>0 && y<0)
    printf("Point is in area B");
    else printf("Point is not in areas A or B");
    return 0;
}
