#include<stdio.h>
#include<conio.h>

void main()
{
	float a,b,c,av;
	clrscr();
	printf("A=");
	scanf("%f",&a);
	printf("B=");
	scanf("%f",&b);
	printf("C=");
	scanf("%f",&c);
	av=a+b+c/3;

	printf("Average=%f",av);
	getch();
}