#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HASH 20

typedef struct hashNode
{
    char *username;
    char *password;
    struct hashNode *nextChain; //A pointer to the next node in the chain after a colision occurs
} hashNode;

int hashCode(char *user, char *password)
{
    int code = 0;
    for (int i = 0; i <= strlen(user) - 1; i++)
        code += user[i];

    for (int i = 0; i <= strlen(password) - 1; i++)
        code += password[i];

    return code % MAX_HASH;
}

void buildTable(hashNode *table, char *s)
{
    char *u = malloc(20);
    char *p = malloc(20);
    char *found;
    char *string = strdup(s);
    int hashCODE;

    while ((found = strsep(&string, "\n")) != NULL)
    {                                 //Seperate names in the database list
        sscanf(found, "%s %s", u, p); //split username and password

        hashCODE = hashCode(u, p);
        if (table[hashCODE].username == NULL)
        {
            table[hashCODE].username = strdup(u);
            table[hashCODE].password = strdup(p);
        }
        else
        {
            hashNode *current = &table[hashCODE];
            hashNode *newNode = malloc(sizeof(hashNode)); //allocate memory to the node
            while (current->nextChain != NULL)
                current = current->nextChain; //get to the end of the chain

            current->nextChain = newNode; //set the node
            newNode->username = u;
            newNode->password = p;
        }
    }

    return;
}

bool auth(hashNode *table, char *user, char *password);

int main(void)
{
    FILE *fv;
    hashNode *table = (hashNode *)malloc(sizeof(hashNode) * (MAX_HASH + 5)); //Hash Table
    //static hashNode table[MAX_HASH];

    if ((fv = fopen("passwords.txt", "r")) == NULL)
    { //check the file opens
        printf("Error! File could not be openned");
        exit(1);
    }

    char *passwordFile = malloc(sizeof(fv));
    fscanf(fv, "%[^\0]%*c", passwordFile); //Get password data

    buildTable(table, passwordFile); //build a table of the usernames and passwords

    fclose(fv);

    char inputU[20]; //Get the users input
    char inputP[20];
    printf("Username: ");
    scanf(" %s", inputU);
    printf("Password: ");
    scanf(" %s", inputP);

    if (auth(table, inputU, inputP) == true)
        printf("Authenticated, Welcome %s\n", inputU);
    else
        printf("Failure to Authenticate");
}

bool auth(hashNode *table, char *user, char *password)
{
    bool clear = false;
    int code = hashCode(user, password); // get hashcode

    if (strcmp(table[code].username, user) == 0 && strcmp(table[code].password, password) == 0)
    { //check the password
        clear = true;
    }
    else if (table[code].nextChain != NULL)
    {
        hashNode *current = &table[code];
        while (current->nextChain != NULL && clear == false)
        { //go through all the possible links in the chain
            if (table[code].username == user && table[code].password == password)
            {
                clear = true;
            }
            current = current->nextChain;
        }
    }

    return clear;
}
