#include<stdio.h>
#include<conio.h>

void main()
{
	float r,ac,pie;
	clrscr();
	printf("value of R=");
	scanf("%f",&r);
	pie=3.14f;
	ac=pie*r*r;
	printf("Area of Circle=%f",ac);
	getch();
}