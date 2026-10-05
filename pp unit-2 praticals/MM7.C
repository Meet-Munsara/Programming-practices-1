#include<stdio.h>
#include<conio.h>

void main()
{
	float r,sq,cu;
	clrscr();
	printf("R=");
	scanf("%f",&r);

	sq=r*r;
	cu=r*r*r;
	printf("Squar=%f",sq);
	printf("\nCube=%f",cu);
	getch();
}

