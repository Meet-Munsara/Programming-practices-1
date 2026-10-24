#include <stdio.h>
#include <string.h>

#define MAX 50
#define SUBJECTS 3

typedef struct {
    int roll;
    char name[50];
    float marks[SUBJECTS], attendance;
} Student;

float total(Student s) {
    return s.marks[0] + s.marks[1] + s.marks[2];
}

float percentage(Student s) {
    return total(s) / SUBJECTS;
}

char grade(float p) {
    if (p >= 90) return 'A';
    if (p >= 75) return 'B';
    if (p >= 60) return 'C';
    if (p >= 40) return 'D';
    return 'F';
}

void show(Student s) {
    float p = percentage(s);
    printf("\nRoll: %d | Name: %s\n", s.roll, s.name);
    printf("Total: %.2f / 300 | Percentage: %.2f%%\n", total(s), p);
    printf("Grade: %c | Result: %s | Attendance: %.1f%%\n",
           grade(p), p >= 40 ? "PASS" : "FAIL", s.attendance);
}

int main(void) {
    Student s[MAX];
    int n = 0, choice, i, key, found;

    do {
        printf("\n--- STUDENT PERFORMANCE SYSTEM ---\n");
        printf("1.Add 2.Display 3.Search 4.Analyse 0.Exit\nChoice: ");
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
            
            for (i = 0; i < SUBJECTS; i++) {
                do {
                    printf("Marks in subject %d (0-100): ", i + 1);
                    scanf("%f", &s[n].marks[i]);
                } while (s[n].marks[i] < 0 || s[n].marks[i] > 100);
            }
            
            printf("Attendance percentage: "); 
            scanf("%f", &s[n].attendance);
            n++;
            printf("Student added successfully.\n");

        } else if (choice == 2) {
            if (n == 0) printf("No records available.\n");
            for (i = 0; i < n; i++) show(s[i]);

        } else if (choice == 3) {
            printf("Enter roll number to search: "); 
            scanf("%d", &key);
            found = 0;
            for (i = 0; i < n; i++) {
                if (s[i].roll == key) { 
                    show(s[i]); 
                    found = 1; 
                }
            }
            if (!found) printf("Student not found.\n");

        } else if (choice == 4) {
            if (n == 0) { 
                printf("Add students first.\n"); 
                continue; 
            }
            int high = 0, low = 0, pass = 0;
            float sum = 0;
            for (i = 0; i < n; i++) {
                float p = percentage(s[i]);
                sum += p;
                if (p > percentage(s[high])) high = i;
                if (p < percentage(s[low])) low = i;
                if (p >= 40) pass++;
            }

            printf("Class average: %.2f%%\n", sum / n);
            printf("Pass: %d | Fail: %d\n", pass, n - pass);
            printf("Highest: %s (%.2f%%)\n", s[high].name, percentage(s[high]));
            printf("Lowest: %s (%.2f%%)\n", s[low].name, percentage(s[low]));

        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}