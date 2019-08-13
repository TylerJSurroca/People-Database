#include <stdio.h>
#include <string.h>
#include "peopledb.h"


struct person g_people[MAX_PEOPLE];
int g_index = 0; //runs once at startup; this holds the total number of people
int g_count = 0; //runs once at startup; this holds the total number of people

/*Passing by values*/
//adds person to array g_people
int addPerson(int age, float height, char name[])
{
    g_people[g_index].age = age;
    g_people[g_index].height = height;
    strcpy(g_people[g_index].name,name);

    //Increment number of people inside the number database
    g_index++;
    g_count++;
    if(g_index > MAX_PEOPLE)
        return(-1);

    return g_index;
}

//returnType functionName (list of parameters)

// searchPerson
// Takes the name of the person to search for in char name[]
// Returns the index into g_people of the person found
int searchPerson(char nameOfPerson[MAX_NAMELEN])
{
    int placeInDatabase;
    char compareNames;

    for(placeInDatabase = 0; placeInDatabase < g_count; placeInDatabase++)
    {
        struct person tempPerson = getPerson(placeInDatabase);

        compareNames = strcmp(tempPerson.name,nameOfPerson);

        if(compareNames == 0)
        {

            //printf("DEBUG From DB: Name: %sHeight: %f Age: %d\n", tempPerson.name, tempPerson.height, tempPerson.age);
            return placeInDatabase;
        }
    }

    //printf("DEBUG Person is not in the database");
    return -1;
};

// getPerson
// Takes the integer index of a person in g_people
// Returns the person structure on the person gotten
struct person getPerson(int indexPerson)
{
    //struct person tempPerson = g_people[indexPerson];
    return g_people[indexPerson];
};


void dumpData()
{
    for (int i = 0; i < MAX_PEOPLE; i++)
    {
        printf("From DB: Name: %sHeight: %f Age: %d\n", g_people[i].name, g_people[i].height, g_people[i].age);
    }
}

