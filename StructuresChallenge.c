/* Write a program that declares a structure and prints out it's content.
Create an employee structure with 3 members
-Name(Char Array)
-hireDate(int)
-salary(float)

Declare and initialize an instance of an employee type.
Read in a second employee from the console and store it in a structure type employee.
Print out the contents of each employee.
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct employee{

    char *name;
    int hireDate;
    float salary;

};

void main(void){

    struct employee emp1;
    emp1.name=(char*)calloc(8,sizeof(char));
    strcpy(emp1.name,"Santiago");
    emp1.hireDate=2001;
    emp1.salary=40.5;

    printf("\n(Employee 1) Name: %s, Hire date: %d, salary: %f\n",emp1.name,emp1.hireDate,emp1.salary);

    int nameLength=0;
    printf("Enter the length of your name: \n");
    scanf("%d",&nameLength);

    struct employee emp2;
    emp2.name=(char*)calloc(nameLength,sizeof(char));
    printf("Type your name: \n");
    scanf("%s",emp2.name);
    printf("Type in your hire date (year): \n");
    scanf("%d",&emp2.hireDate);
    printf("Type in your salary: \n");
    scanf("%f",&emp2.salary);

    printf("\n(Employee 2) Name: %s, Hire date: %d, salary: %f\n",emp2.name,emp2.hireDate,emp2.salary);

}