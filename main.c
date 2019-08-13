#include <stdio.h>
#include <string.h>
#include "peopledb.h"

int main()
{
    char userInput[MAX_NAMELEN];

    // Here is the magic
    addPerson(19,5.11,"Tyler Surroca\n");
    addPerson(49,5.10,"Francisco Surroca\n");
    addPerson(16,6.2,"James Bond\n");

    dumpData();

    printf("Search someone\n");
    fgets(userInput,64,stdin);
    int personIndex;
    struct person foundPerson;
    personIndex = searchPerson(userInput);
    if(personIndex >= 0)
    {
        foundPerson = getPerson(personIndex);
    }
    else
    {
        printf("Person not found.");
    }

    printf("From DB: Name: %sHeight: %f Age: %d\n", foundPerson.name, foundPerson.height, foundPerson.age);

    return(0);
}
