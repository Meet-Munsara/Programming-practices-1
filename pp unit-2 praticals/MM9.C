
#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b,c;

	clrscr();

	 printf("\n enter value a: ");
	 scanf("%d" ,&a);
	 printf("\n enter value b: ");
	 scanf("%d" ,&b);
	printf("\nbefore swapping");
	printf("\na:%d",a);
	printf("\nb: %d",b);

	a=a+b;
	b=a-b;
	a=a-b;

	printf("\nafter swapping");
	printf("\na: %d",a);
	printf("\nb: %d",b);



	getch();
}