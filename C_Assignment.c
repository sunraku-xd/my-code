#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Structure to store basic student information.
    The record contains student name, their id and cgpa scores.
*/
typedef struct {
    char name[50];      //stores student name
    int id;     //stores student id
    float cgpa;     //stores cgpa score
} Student;

typedef struct {
    Student *students;      //dynamic array of students
    int capacity;       //total allocated size
    int count;      //number of valid student records
} StudentContainer;

//Function declarations
void initializeContainer(StudentContainer *sc, int initialSize);
void addStudent(StudentContainer *sc, Student s);
void deleteStudentByID(StudentContainer *sc, int id);
void sortByID(StudentContainer *sc);
void sortByName(StudentContainer *sc);
void sortByCGPA(StudentContainer *sc);
void printStudents(const StudentContainer *sc);
void freeContainer(StudentContainer *sc);

// Main function

int main() {
    StudentContainer sc;
    int initialSize, choice, id;
    Student s;

    printf("Enter initial size: ");
    scanf("%d", &initialSize);

    initializeContainer(&sc, initialSize);

    do {
        printf("\n1. Add Student");
        printf("\n2. Delete Student by ID");
        printf("\n3. Sort by ID");
        printf("\n4. Sort by Name");
        printf("\n5. Sort by CGPA");
        printf("\n6. Print Student List");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name ID CGPA: ");
                scanf("%s %d %f", s.name, &s.id, &s.cgpa);
                addStudent(&sc, s);
                break;

            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteStudentByID(&sc, id);
                break;

            case 3:
                sortByID(&sc);
                break;

            case 4:
                sortByName(&sc);
                break;

            case 5:
                sortByCGPA(&sc);
                break;

            case 6:
                printStudents(&sc);
                break;
        }
    } while (choice != 7);

    freeContainer(&sc);
    return 0;
}
// Function definitions
/*
    Allocates memory for the student container 
    based on the initial size given by the user
*/
void initializeContainer(StudentContainer *sc, int initialSize) {
    sc->students = (Student *)malloc(initialSize * sizeof(Student));
    sc->capacity = initialSize;
    sc->count = 0;
}

/*
    Adds a student to the container.
    if memory is full, the size is doubled.
*/

void addStudent(StudentContainer *sc, Student s) {
    if (sc->count == sc->capacity) {
        sc->capacity *= 2;
        sc->students = (Student *)realloc(sc->students,
                         sc->capacity * sizeof(Student));
    }
    sc->students[sc->count++] = s;
}

/*
    Deletes a student by matching the ID number.
    After deletion, elements are shifted left. 
*/

void deleteStudentByID(StudentContainer *sc, int id) {
    int index = -1;
    for (int i = 0; i < sc->count; i++) {
        if (sc->students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < sc->count - 1; i++) {
            sc->students[i] = sc->students[i + 1];
        }
        sc->count--;
    }
}

/* 
    Sorts students in ascending order of ID
    using simple bubble sort logic.
*/

void sortByID(StudentContainer *sc) {
    for (int i = 0; i < sc->count - 1; i++) {
        for (int j = 0; j < sc->count - i - 1; j++) {
            if (sc->students[j].id > sc->students[j + 1].id) {
                Student temp = sc->students[j];
                sc->students[j] = sc->students[j + 1];
                sc->students[j + 1] = temp;
            }
        }
    }
}
// Sorting students names alphabetically
void sortByName(StudentContainer *sc) {
    for (int i = 0; i < sc->count - 1; i++) {
        for (int j = 0; j < sc->count - i - 1; j++) {
            if (strcmp(sc->students[j].name,
                       sc->students[j + 1].name) > 0) {
                Student temp = sc->students[j];
                sc->students[j] = sc->students[j + 1];
                sc->students[j + 1] = temp;
            }
        }
    }
}
// Sorts students in descending order by their CGPA scores
void sortByCGPA(StudentContainer *sc) {
    for (int i = 0; i < sc->count - 1; i++) {
        for (int j = 0; j < sc->count - i - 1; j++) {
            if (sc->students[j].cgpa < sc->students[j + 1].cgpa) {
                Student temp = sc->students[j];
                sc->students[j] = sc->students[j + 1];
                sc->students[j + 1] = temp;
            }
        }
    }
}
// Displays all student records
void printStudents(const StudentContainer *sc) {
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < sc->count; i++) {
        printf("Name: %s | ID: %d | CGPA: %.2f\n",
               sc->students[i].name,
               sc->students[i].id,
               sc->students[i].cgpa);
    }
}
// Frees dynamically allocated memory
void freeContainer(StudentContainer *sc) {
    free(sc->students);
}