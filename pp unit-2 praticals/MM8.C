// write a program to input year and find whether your year is leap year or mot

#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b;
	int c;
	clrscr();


	printf("before swaping");
	printf("\nenter the value of a:");
	scanf("%d",&a);
	printf("enter the value of b:");
	scanf("%d",&b);

	c=b;
	b=a;
	a=c;



	printf("\nafter swaping");
	printf("\nvalue of a:%d",a);
	printf("\nvalue of b:%d",b);
	getch();
}

