#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    char name[50], designation[40];
    float basic, allowance, deduction, gross, net;
} Employee;

void calculate(Employee *e) {
    /* Allowance is 20% of basic salary; deduction is 8% of gross. */
    e->allowance = e->basic * 0.20f;
    e->gross = e->basic + e->allowance;
    e->deduction = e->gross * 0.08f;
    e->net = e->gross - e->deduction;
}

int main(void) {
    Employee e[MAX];
    int n = 0, choice, i, id, found;

    do {
        printf("\n--- EMPLOYEE PAYROLL MANAGEMENT SYSTEM ---\n");
        printf("1.Add employee 2.Display payroll 3.Search ID 4.High salary report 0.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n == MAX) { 
                printf("Employee limit reached.\n"); 
                continue; 
            }
            printf("Employee ID: "); 
            scanf("%d", &e[n].id);
            printf("Name (one word): "); 
            scanf("%49s", e[n].name);
            printf("Designation (one word): "); 
            scanf("%39s", e[n].designation);
            printf("Basic salary: "); 
            scanf("%f", &e[n].basic);

            if (e[n].basic < 0) { 
                printf("Salary cannot be negative.\n"); 
                continue; 
            }

            calculate(&e[n]);
            n++; 
            printf("Employee added and salary calculated.\n");

        } else if (choice == 2 || choice == 4) {
            found = 0;
            for (i = 0; i < n; i++) {
                if (choice == 4 && e[i].net <= 30000) continue;
                printf("\nID:%d Name:%s Designation:%s\n", 
                       e[i].id, e[i].name, e[i].designation);
                printf("Basic:Rs.%.2f Allowance:Rs.%.2f Gross:Rs.%.2f\n",
                       e[i].basic, e[i].allowance, e[i].gross);
                printf("Deduction:Rs.%.2f Net salary:Rs.%.2f\n", 
                       e[i].deduction, e[i].net);
                found = 1;
            }
            if (!found) printf("No matching employees.\n");

        } else if (choice == 3) {
            printf("Employee ID: "); 
            scanf("%d", &id); 
            found = 0;
            for (i = 0; i < n; i++) {
                if (e[i].id == id) {
                    printf("%s | Gross:Rs.%.2f | Deduction:Rs.%.2f | Net:Rs.%.2f\n",
                           e[i].name, e[i].gross, e[i].deduction, e[i].net);
                    found = 1; 
                    break;
                }
            }
            if (!found) printf("Employee not found.\n");

        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}