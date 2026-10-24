#include <stdio.h>

#define MAX 100

typedef struct {
    int roll, present, total;
    char name[50];
} Student;

float attendance(Student s) {
    if (s.total == 0) return 0;
    return (float)s.present * 100 / s.total;
}

int main(void) {
    Student s[MAX];
    int n = 0, choice, i, roll, found, high, low, eligible = 0;
    float sum;
    const float THRESHOLD = 75.0;

    do {
        printf("\n--- ATTENDANCE MANAGEMENT SYSTEM ---\n");
        printf("1.Add record 2.Display all 3.Search roll 4.Summary 5.Below threshold 0.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n == MAX) { 
                printf("Record limit reached.\n"); 
                continue; 
            }
            printf("Roll number: "); 
            scanf("%d", &s[n].roll);
            printf("Name (one word): "); 
            scanf("%49s", s[n].name);
            printf("Total classes held: "); 
            scanf("%d", &s[n].total);
            printf("Classes attended: "); 
            scanf("%d", &s[n].present);

            if (s[n].total <= 0 || s[n].present < 0 || s[n].present > s[n].total) {
                printf("Invalid attendance values; record not added.\n");
            } else { 
                n++; 
                printf("Attendance record added.\n"); 
            }

        } else if (choice == 2 || choice == 5) {
            found = 0;
            for (i = 0; i < n; i++) {
                if (choice == 5 && attendance(s[i]) >= THRESHOLD) continue;
                printf("Roll:%d Name:%s Attendance:%.2f%% Status:%s\n",
                       s[i].roll, s[i].name, attendance(s[i]),
                       attendance(s[i]) >= THRESHOLD ? "Eligible" : "Below threshold");
                found = 1;
            }
            if (!found) printf("No matching records.\n");

        } else if (choice == 3) {
            printf("Roll number: "); 
            scanf("%d", &roll); 
            found = 0;
            for (i = 0; i < n; i++) {
                if (s[i].roll == roll) {
                    printf("%s: %.2f%% attendance\n", s[i].name, attendance(s[i]));
                    found = 1; 
                    break;
                }
            }
            if (!found) printf("Student not found.\n");

        } else if (choice == 4) {
            if (n == 0) { 
                printf("Add records first.\n"); 
                continue; 
            }
            high = low = 0; 
            sum = 0; 
            eligible = 0;
            
            for (i = 0; i < n; i++) {
                sum += attendance(s[i]);
                if (attendance(s[i]) > attendance(s[high])) high = i;
                if (attendance(s[i]) < attendance(s[low])) low = i;
                if (attendance(s[i]) >= THRESHOLD) eligible++;
            }

            printf("Class average attendance: %.2f%%\n", sum / n);
            printf("Eligible: %d | Below 75%%: %d\n", eligible, n - eligible);
            printf("Maximum: %s (%.2f%%)\n", s[high].name, attendance(s[high]));
            printf("Minimum: %s (%.2f%%)\n", s[low].name, attendance(s[low]));

        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}