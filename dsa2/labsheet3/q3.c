#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    int age;
} Person;

int main()
{
    int numPersons, i;
    Person *persons;

    printf("Enter the number of persons: ");
    scanf("%d", &numPersons);

    persons = calloc(numPersons, sizeof(Person));

    for (i = 0; i < numPersons; i++)
    {
        printf("Enter details for Person %d:\n", i + 1);
        printf("Enter name: ");

        getchar();

        scanf("%s", persons[i].name);

        printf("Enter age: ");
        scanf("%d", &persons[i].age);
    }

    printf("Entered details for %d persons:\n", numPersons);
    for (i = 0; i < numPersons; i++)
    {
        printf("Person %d - Name: %s, Age: %d\n", i + 1, persons[i].name, persons[i].age);
    }

    printf("Do you want to add more persons? Enter the number of additional persons: ");
    int additionalPersons;
    scanf("%d", &additionalPersons);

    persons = realloc(persons, (numPersons + additionalPersons) * sizeof(Person));

    for (i = numPersons; i < numPersons + additionalPersons; i++)
    {
        printf("Enter details for additional Person %d:\n", i - numPersons + 1);
        printf("Enter name: ");

        getchar();

        scanf("%s", persons[i].name);

        printf("Enter age: ");
        scanf("%d", &persons[i].age);
    }

    printf("Details after adding %d more persons:\n", additionalPersons);
    for (i = 0; i < numPersons + additionalPersons; i++)
    {
        printf("Person %d - Name: %s, Age: %d\n", i + 1, persons[i].name, persons[i].age);
    }

    free(persons);
}
