#include<stdio.h>
#include<conio.h>

void main()
{
	float p,q,r,simpleinterest;
	clrscr();
	printf("value of P=");
	scanf("%f",&p);
	printf("value of Q=");
	scanf("%f",&q);
	printf("value of R=");
	scanf("%f",&r);

	simpleinterest=p*q*r/100;
	printf("Simple Interest=%f",simpleinterest);
	getch();
}


