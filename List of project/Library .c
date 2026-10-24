#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id, issued;
    char title[60], author[50], category[30];
    float price;
} Book;

int main(void) {
    Book b[MAX];
    int n = 0, choice, i, id, found;

    do {
        printf("\n--- LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1.Add 2.Display all 3.Search ID 4.Issue 5.Return\n");
        printf("6.Available 7.Issued 0.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n == MAX) { 
                printf("Library storage full.\n"); 
                continue; 
            }
            printf("Book ID: "); 
            scanf("%d", &b[n].id);
            printf("Title (use_underscores): "); 
            scanf("%59s", b[n].title);
            printf("Author (one_word): "); 
            scanf("%49s", b[n].author);
            printf("Category: "); 
            scanf("%29s", b[n].category);
            printf("Price: "); 
            scanf("%f", &b[n].price);

            b[n].issued = 0; 
            n++;
            printf("Book added.\n");

        } else if (choice == 2 || choice == 6 || choice == 7) {
            found = 0;
            for (i = 0; i < n; i++) {
                if (choice == 6 && b[i].issued) continue;
                if (choice == 7 && !b[i].issued) continue;
                
                printf("ID:%d Title:%s Author:%s Category:%s Price:%.2f Status:%s\n",
                       b[i].id, b[i].title, b[i].author, b[i].category,
                       b[i].price, b[i].issued ? "Issued" : "Available");
                found = 1;
            }
            if (!found) printf("No matching books.\n");

        } else if (choice == 3 || choice == 4 || choice == 5) {
            printf("Enter book ID: "); 
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++) {
                if (b[i].id == id) {
                    found = 1;
                    if (choice == 3) {
                        printf("%d %s by %s | %s | Rs.%.2f | %s\n",
                               b[i].id, b[i].title, b[i].author, b[i].category,
                               b[i].price, b[i].issued ? "Issued" : "Available");
                    }
                    if (choice == 4) {
                        if (!b[i].issued) { 
                            b[i].issued = 1; 
                            printf("Book issued.\n"); 
                        } else {
                            printf("Book is already issued.\n");
                        }
                    }
                    if (choice == 5) {
                        if (b[i].issued) { 
                            b[i].issued = 0; 
                            printf("Book returned.\n"); 
                        } else {
                            printf("Book was not issued.\n");
                        }
                    }
                    break;
                }
            }
            if (!found) printf("Book ID not found.\n");

        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}