#define MAX_PEOPLE 32
#define MAX_NAMELEN 32

struct person {
    int age;
    float height;
    char name[MAX_NAMELEN];
};

int addPerson(int age, float height, char name[]);

int searchPerson(char nameOfPerson[MAX_NAMELEN]);

struct person getPerson(int indexPerson);

void dumpData();
