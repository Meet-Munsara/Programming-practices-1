#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id, qty;
    char name[50], category[30];
    float price;
} Product;

int main(void) {
    Product p[MAX];
    int n = 0, choice, i, id, qty, found;
    float bill;

    do {
        printf("\n--- INVENTORY AND BILLING SYSTEM ---\n");
        printf("1.Add product 2.Display 3.Search 4.Update stock\n");
        printf("5.Generate bill 6.Low stock 0.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n == MAX) { 
                printf("Inventory full.\n"); 
                continue; 
            }
            printf("Product ID: "); 
            scanf("%d", &p[n].id);
            printf("Name (one_word): "); 
            scanf("%49s", p[n].name);
            printf("Category: "); 
            scanf("%29s", p[n].category);
            printf("Quantity: "); 
            scanf("%d", &p[n].qty);
            printf("Unit price: "); 
            scanf("%f", &p[n].price);
            n++; 
            printf("Product added.\n");

        } else if (choice == 2 || choice == 6) {
            found = 0;
            for (i = 0; i < n; i++) {
                if (choice == 6 && p[i].qty >= 5) continue;
                printf("ID:%d %s (%s) Qty:%d Price:Rs.%.2f\n",
                       p[i].id, p[i].name, p[i].category, p[i].qty, p[i].price);
                found = 1;
            }
            if (!found) printf("No matching products.\n");

        } else if (choice == 3 || choice == 4) {
            printf("Product ID: "); 
            scanf("%d", &id); 
            found = 0;
            for (i = 0; i < n; i++) {
                if (p[i].id == id) {
                    found = 1;
                    if (choice == 3) {
                        printf("%s | Qty:%d | Unit price:Rs.%.2f\n",
                               p[i].name, p[i].qty, p[i].price);
                    } else {
                        printf("Quantity to add (positive number): ");
                        scanf("%d", &qty);
                        if (qty > 0) { 
                            p[i].qty += qty; 
                            printf("Stock updated.\n"); 
                        } else {
                            printf("Invalid quantity.\n");
                        }
                    }
                    break;
                }
            }
            if (!found) printf("Product not found.\n");

        } else if (choice == 5) {
            bill = 0;
            printf("Enter product ID and quantity; enter ID 0 to finish.\n");
            do {
                printf("Product ID: "); 
                scanf("%d", &id);
                if (id == 0) break;
                
                printf("Quantity: "); 
                scanf("%d", &qty); 
                found = 0;
                
                for (i = 0; i < n; i++) {
                    if (p[i].id == id) {
                        found = 1;
                        if (qty > 0 && qty <= p[i].qty) {
                            float amount = qty * p[i].price;
                            bill += amount; 
                            p[i].qty -= qty;
                            printf("%s x %d = Rs.%.2f\n", p[i].name, qty, amount);
                        } else {
                            printf("Invalid quantity or insufficient stock.\n");
                        }
                        break;
                    }
                }
                if (!found) printf("Product not found.\n");
            } while (id != 0);

            printf("TOTAL BILL: Rs.%.2f\n", bill);

        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}