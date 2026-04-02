#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of students we can store
#define MAX_STUDENTS 100
#define MAX_NAME 50

// Structure to hold student information
struct Student {
    char name[MAX_NAME];
    int studentNumber;
    float math;
    float english;
    float computer;
    float total;
    float average;
    char grade;
};

// Function declarations
void showMenu();
void addStudent(struct Student students[], int *count);
void viewAllStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void calculateAndShowResults(struct Student students[], int count);
void saveToFile(struct Student students[], int count);
char getGrade(float average);

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the input buffer
        
        switch(choice) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    addStudent(students, &studentCount);
                } else {
                    printf("\nSorry! Maximum student limit reached.\n");
                }
                break;
            case 2:
                viewAllStudents(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                calculateAndShowResults(students, studentCount);
                break;
            case 5:
                saveToFile(students, studentCount);
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter 1-6.\n");
        }
        
        printf("\n");
        system("pause"); // Press any key to continue
    } while(choice != 6);
    
    return 0;
}

// Display the main menu
void showMenu() {
    printf("\n==============================\n");
    printf(" STUDENT MANAGEMENT SYSTEM\n");
    printf("==============================\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Search Student\n");
    printf("4. Calculate Results\n");
    printf("5. Save Results to File\n");
    printf("6. Exit\n");
}

// Add a new student
void addStudent(struct Student students[], int *count) {
    printf("\n--- ADD NEW STUDENT ---\n");
    
    // Get student name
    printf("Enter Student Name: ");
    fgets(students[*count].name, MAX_NAME, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';
    
    // Get student number
    printf("Enter Student Number: ");
    scanf("%d", &students[*count].studentNumber);
    
    // Get marks for three subjects
    printf("Enter Math Marks: ");
    scanf("%f", &students[*count].math);
    
    printf("Enter English Marks: ");
    scanf("%f", &students[*count].english);
    
    printf("Enter Computer Studies Marks: ");
    scanf("%f", &students[*count].computer);
    getchar(); // Clear buffer
    
    // Calculate total, average and grade
    students[*count].total = students[*count].math + 
                             students[*count].english + 
                             students[*count].computer;
    students[*count].average = students[*count].total / 3;
    students[*count].grade = getGrade(students[*count].average);
    
    (*count)++; // Increase student count
    printf("\n✓ Student added successfully!\n");
}

// Display all students
void viewAllStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo students in the system yet!\n");
        return;
    }
    
    printf("\n-------------------------------------------------------\n");
    printf("Name            Student No    Math    English  Computer\n");
    printf("-------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-15s %-12d %-7.2f %-8.2f %-8.2f\n", 
               students[i].name, 
               students[i].studentNumber,
               students[i].math,
               students[i].english,
               students[i].computer);
    }
    printf("-------------------------------------------------------\n");
}

// Search for a student by number
void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo students in the system yet!\n");
        return;
    }
    
    int searchNum;
    int found = 0;
    
    printf("\n--- SEARCH STUDENT ---\n");
    printf("Enter Student Number to search: ");
    scanf("%d", &searchNum);
    getchar();
    
    // Loop through all students to find match
    for (int i = 0; i < count; i++) {
        if (students[i].studentNumber == searchNum) {
            printf("\n=== Student Found ===\n");
            printf("Name: %s\n", students[i].name);
            printf("Student Number: %d\n", students[i].studentNumber);
            printf("Math Marks: %.2f\n", students[i].math);
            printf("English Marks: %.2f\n", students[i].english);
            printf("Computer Marks: %.2f\n", students[i].computer);
            printf("Total Marks: %.2f\n", students[i].total);
            printf("Average: %.2f\n", students[i].average);
            printf("Grade: %c\n", students[i].grade);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\nStudent with number %d not found!\n", searchNum);
    }
}

// Calculate and display results for all students
void calculateAndShowResults(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo students in the system yet!\n");
        return;
    }
    
    printf("\n--- STUDENT RESULTS ---\n");
    printf("\n------------------------------------------------\n");
    printf("Name            Total     Average   Grade\n");
    printf("------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        // Calculate again to ensure accuracy
        students[i].total = students[i].math + students[i].english + students[i].computer;
        students[i].average = students[i].total / 3;
        students[i].grade = getGrade(students[i].average);
        
        printf("%-15s %-8.2f %-8.2f %c\n", 
               students[i].name,
               students[i].total,
               students[i].average,
               students[i].grade);
    }
    printf("------------------------------------------------\n");
}

// Save all data to file
void saveToFile(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo data to save!\n");
        return;
    }
    
    FILE *file = fopen("students.txt", "w");
    
    if (file == NULL) {
        printf("\nError: Cannot create file!\n");
        return;
    }
    
    // Write header to file
    fprintf(file, "=== STUDENT RECORDS ===\n\n");
    fprintf(file, "%-20s %-12s %-8s %-8s %-10s %-8s %-8s %s\n", 
            "Name", "Student No", "Math", "English", "Computer", "Total", "Average", "Grade");
    fprintf(file, "-------------------------------------------------------------------------------\n");
    
    // Write each student's data
    for (int i = 0; i < count; i++) {
        fprintf(file, "%-20s %-12d %-8.2f %-8.2f %-10.2f %-8.2f %-8.2f %c\n", 
                students[i].name,
                students[i].studentNumber,
                students[i].math,
                students[i].english,
                students[i].computer,
                students[i].total,
                students[i].average,
                students[i].grade);
    }
    
    fclose(file);
    printf("\n✓ Data successfully saved to 'students.txt'!\n");
}

// Determine grade based on average score
char getGrade(float average) {
    if (average >= 80) {
        return 'A';
    } else if (average >= 70) {
        return 'B';
    } else if (average >= 60) {
        return 'C';
    } else if (average >= 50) {
        return 'D';
    } else {
        return 'F';
    }
}