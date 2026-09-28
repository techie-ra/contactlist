#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Contact
{
    char name[50];
    int phoneNo;
};
struct ContactList
{
    struct Contact *members;
    int count;
    int capacity;
};
void intiList(struct ContactList *list)
{
    list->count = 0;
    list->capacity = 2;
    list->members = malloc(list->capacity * sizeof *list->members);
    if (list->members == 0)
    {
        printf("Error!!!!");
        return;
    }
}
void resizeList(struct ContactList *list)
{
    list->capacity *= 2;
    struct Contact *temp = realloc(
        list->members,
        list->capacity * sizeof *list->members);
    if (temp == NULL)
    {
        printf("ERROR!!!!!!");
        free(list->members);
        return;
    }
    list->members = temp;
}
void adding(struct ContactList *list)
{
    if (list->count == list->capacity)
    {
        resizeList(list);
    }
    printf("enter the name:");
    scanf("%s", list->members[list->count].name);
    printf("enter the phone no:");
    scanf("%d", &list->members[list->count].phoneNo);
    list->count++;
    printf("contact added.\n");
}
void deleting(struct ContactList *list)
{
    char name[50];
    printf("enter the name to delete:");
    scanf("%s", name);
    for (int i = 0; i < list->count; i++)
    {
        if (strcmp(list->members[i].name, name) == 0)
        {
            for (int j = i; j < list->count - 1; j++)
            {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("delete ho gaya!!\n");
            return;
        }
    }
    printf("Nahi Mil raha h !!!");
}
void searching(struct ContactList *list)
{
    char name[50];
    int found = 0;
    printf("enter the name to search:");
    scanf("%s[^\n]", name);
    for (int i = 0; i < list->count; i++)
    {
        if (strcmp(list->members[i].name, name) == 0)
        {
            printf("Found: %s - %d\n",
                   list->members[i].name,
                   list->members[i].phoneNo);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Nahi mil raha hai..\n");
    }
}
void showContacts(struct ContactList *list)
{
    if (list->count == 0)
    {
        printf("No contacts found.\n");
        return;
    }

    for (int i = 0; i < list->count; i++)
    {
        printf("%d. %s - phone No:%d\n",
               i + 1,
               list->members[i].name,
               list->members[i].phoneNo);
    }
}
int main()
{
    struct ContactList Contact;
    int choice;
    intiList(&Contact);
    do
    {
        printf("\n----Contact List-----\n");
        printf("1.Add contacts\n");
        printf("2.Delete contact\n");
        printf("3.search contact\n");
        printf("4.show all contact\n");
        printf("5.Exit\n");
        printf("Enter your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            adding(&Contact);
            break;
        case 2:
            deleting(&Contact);
            break;
        case 3:
            searching(&Contact);
            break;
        case 4:
            showContacts(&Contact);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
            break;
        }

    }while (choice!=5);
    free(Contact.members);
    Contact.members=NULL;
    return 0;
    
}