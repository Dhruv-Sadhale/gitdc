

// **Question: Implement a program to manage a student database. Each student's information should include their name, age, ID, and a variable number of course grades. The program should allow the user to perform the following operations:**

// 1. **Add Student:** Allow the user to input a new student's information, including their name, age, ID, and grades for multiple courses. Store this information using a suitable data structure.

// 2. **Display Student:** Display the information of a specific student by searching for them using their ID. Display their name, age, ID, and average grade.

// 3. **Display All Students:** Display the information of all the students in the database, including their names, ages, IDs, and average grades.

// 4. **Calculate Average:** Calculate and display the average grade of a specific student identified by their ID.

// 5. **Calculate Class Average:** Calculate and display the average grade of the entire class.

// 6. **Update Student Information:** Allow the user to update a student's information (age or grades) by searching for them using their ID.

// 7. **Delete Student:** Delete a student's information from the database using their ID.

// 8. **Exit:** Exit the program.

// **Use the following guidelines to implement the program:**

// - Define a structure to represent a student, including their name, age, ID, and an array to hold their course grades.
// - Use dynamic memory allocation to manage memory for student records and grade arrays.
// - Implement functions for each operation mentioned above, including functions to calculate averages and display information.
// - Use pointers to navigate and manipulate data within the structures.
// - Utilize arrays to store multiple student records and their associated data.
// - Implement proper input validation to ensure accurate data entry.
// - Create a menu-driven interface that allows the user to choose different operations.

// Remember to handle memory deallocation properly to avoid memory leaks.

// This question should test the student's understanding of strings, pointers, functions, arrays, structures, dynamic memory allocation, and various programming concepts while also demonstrating their ability to design and implement a functional program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char name[100];
    int age;
    char id[100];
    int grades[5];
};
void add_student(struct student s1[], int n, int val);
void display_student(struct student s1[], int n, char search_id[]);
void student_grade_avg(struct student s1[], int n, char search_id[]);
void add_student(struct student s1[], int n, int val)
{
    int first = (val == 0) ? 0 : n - 1;// note the ternary operator logic used but this will have to be changed later on
    int last = n;
    for (int i = first; i < last; i++)
    {
        scanf("%s", s1[i].name);
        scanf("%d", &s1[i].age);
        scanf("%s", s1[i].id);
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &s1[i].grades[j]);// here &
        }
    }
}

void display_student(struct student s1[], int n, char search_id[])
{
    for (int i = 0; i < n; i++)
    {
        int x = strcmp(search_id, s1[i].id);
        if (x == 0)
        {
            printf("Match found, the details of the student are:\n");
            puts(s1[i].name);
            printf("%d\n", s1[i].age);
            puts(s1[i].id);
            for (int j = 0; j < 5; j++)
            {
                printf("%d", s1[i].grades[j]);
            }
            printf("the average grades of the student are\n");
        }
        else
        {
            printf("Student with the entered id not found\n");
        }
    }
}

void student_grade_avg(struct student s1[], int n, char search_id[])
{
    float avg = 0;
    for (int i = 0; i < n; i++)
    {
        int x = strcmp(search_id, s1[i].id);
        if (x == 0)// the function returns 0 if the strings are equal, you thought its 1
        {
            printf("Match found, the details of the student are:\n");
            puts(s1[i].name);
            printf("%d\n", s1[i].age);// here no & 
            puts(s1[i].id);
            for (int j = 0; j < 5; j++)
            {
                printf("%d", s1[i].grades[j]);// here also no &
            }
            printf("the average grades of the student are\n");
            int sum = 0;
            for (int z = 0; z < 5; z++)
            {
                sum = sum + s1[i].grades[z];
            }
            avg = (float)sum / 5;// rem typecasting
            printf("%f \n", avg);
        }
        else
        {
            printf("Student with the entered id not found\n");
        }
    }
}
int main()
{
    struct student s1[100];

    int n;
    int key;
    int contin;
    printf("1. Add a student to the database:\n");
    printf("2. Display student information by searching with id:\n");
    printf("enter your choice\n");
    scanf("%d", &key);// dont use \n
    getchar();
    printf("enter number of students\n");
    scanf("%d", &n);
    getchar();// this was also added 
    if (key == 1)
    {
        add_student(s1, n, 0);
        printf("press 1 if you want to continue else press enter\n");
        scanf("%d", &contin);// here dont use \n 
        getchar();// this was also added
        int next = 1;
        while (contin == 1)// here remember it was initially an infinite loop
        {
            add_student(s1, n + (next++), 1);
            printf("press 1 if you want to continue else press enter\n");
            scanf("%d", &contin);
        }
    }
    char search_id[100];
    printf("enter id of student\n");
    fgets(search_id, 100, stdin);
    search_id[strcspn(search_id, "\n")] = '\0';// correction made
    display_student(s1, n, search_id);
    printf("for avg grades of searched student\n");
    student_grade_avg(s1, n, search_id);// careully observe what you are passing in the function

    return 0;
}