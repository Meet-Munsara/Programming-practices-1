#include<stdio.h>
#include<conio.h>

void main ()
{
	int a,b;
	int sum,sub,mul,div;

	clrscr();
	printf("enter the value of A=");
	scanf("%d",&a);
	printf("\nenter the value of B=");
	scanf("%d",&b);
	sum=a+b;
	sub=a-b;
	mul=a*b;
	div=a/b;
	printf("\nSum=%d",sum);
	printf("\nSub=%d",sub);
	printf("\nMul=%d",mul);
	printf("\nDiv=%d",div);
	getch();
}


