

#include<stdio.h>
#include<conio.h>

void main()
{
	float quantity,price,dis_per;
	float total_cost,dis_amo,final_amo;
	clrscr();
	printf("Enter quantity:");
	scanf("%f",&quantity);
	printf("Enter price:");
	scanf("%f",&price);
	printf("Enter discount percentage:");
	scanf("%f",&dis_per);

	total_cost=quantity*price;
	dis_amo=(dis_per/100)*total_cost;
	final_amo=total_cost-dis_amo;

	printf("\n---Receipt---");
	printf("\nTotal: %f",total_cost);
	printf("\nDiscount:%f",dis_amo);
	printf("\nFinal amount:%f",final_amo);
	getch();
}


