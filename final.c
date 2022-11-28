#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<windows.h>

struct node
{
    char firstname[20];
    char lastname[20];
    long number;
    struct node *next;
};

struct node *start=NULL;

struct node *getnode()
{
    return((struct node *)malloc(sizeof(struct node)));
}

void display(struct node *start)
{
    system("cls");
    struct node *temp;
    temp=start;
    printf("\n\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\n");
    Sleep(300);
    printf("      First Name\t       Last Name\t    Phone no.\n");
    printf("     ---------------------------------------------------------\n\n");
    while(temp!=NULL)
    {
        Sleep(300);
        printf("      %-20s",temp->firstname);
        printf("\t%-20s",temp->lastname);
        printf("%-20ld",temp->number);
        printf("\n");
        temp=temp->next;
    }
    printf("\n\n\n\n\n\n\n\n");
}

void insert()
{
    struct node *temp,*nn;
    nn=getnode();
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("Enter First name:\t");
    scanf("%s",&nn->firstname);
    Sleep(200);
    printf("Enter Last name:\t");
    scanf("%s",&nn->lastname);
    Sleep(200);
    printf("Enter phone number:\t");
    scanf("%ld",&nn->number);
    Sleep(200);
    printf("\n\n\t\t\t\t****CONTACT SUCCESSFULLY ADDED****\n\n\n\n\n\n\n\n\n");
    temp->next=nn;
    nn->next=NULL;
}

struct node *create()
{
    system("cls");
    printf("\n\t\t\t\t****TO CREATE A NEW CONTACT ADD DETAILS****\n\n\n");
    Sleep(300);
    struct node *temp,*nn;
    if(start!=NULL)
        insert();
    else
    {
    nn=getnode();
    start=nn;
    temp=start;
    printf("Enter First name:\t");
    scanf("%s",&nn->firstname);
    Sleep(200);
    printf("Enter Last name:\t");
    scanf("%s",&nn->lastname);
    Sleep(200);
    printf("Enter phone number:\t");
    scanf("%ld",&nn->number);
    Sleep(200);
    printf("\n\n\t\t\t\t****CONTACT SUCCESSFULLY ADDED****\n\n\n\n\n\n\n\n\n\n");
    nn->next=NULL;
    }
}

struct node *search()
{
    system("cls");
    printf("\n\n\t\t\t\t***CONTACT SERACHING***\n\n");
    Sleep(300);
    struct node *temp=start;
    int flag;
    char f[20];
    printf("Enter NAME to be searched:\t");
    scanf("%s",&f);
    printf("\n\n");
    while (temp != NULL)
    {
        if(strcmp(temp->firstname,f)==0)
        {
            printf("      First Name\t       Last Name\t    Phone no.\n");
            printf("     ---------------------------------------------------------\n\n");
            Sleep(200);
            printf("      %-20s",temp->firstname);
            printf("\t%-20s",temp->lastname);
            printf("%-20ld",temp->number);
            printf("\n\n\n\n\n\n\n\n\n\n\n");

            flag=1;
            break;
        }
        temp = temp->next;
    }

    if(flag!=1)
        printf("\t\t\t\t!!CONTACT NOT FOUND!!\n\n\n\n\n\n\n\n\n\n");


}

void del()
{
    system("cls");
    printf("\n\n\t\t\t\t***DELETING A CONTACT***\n\n");
    Sleep(300);
    struct node *temp;
    int flag;
    char f[20];
    printf("Enter CONTACT NAME to be deleted:\t");
    scanf("%s",&f);

    if(strcmp(start->firstname,f)==0)
    {
          temp = start;
          start = start->next;
          printf("\n\n\n\t\t\t\t**CONTACT DELETED SUCCESSFULLY**\n");
          free(temp);
    }
    else
    {
        struct node *current=start;
        while(current->next!=NULL)
        {
            if(strcmp(current->next->firstname,f)==0)
            {
                temp = current->next;
                current->next = current->next->next;
                printf("\n\n\n\t\t\t\t**CONTACT DELETED SUCCESSFULLY**\n");
                free(temp);
                flag=1;
            }
            else
                current = current->next;
        }
        if(flag!=1)
            printf("\n\n\t\t\t!!CONATCT NOT FOUND!!\n");
    }
    printf("\n\n\n\n\n\n\n\n\n\n");

}

void edit()
{
    system("cls");
    printf("\n\n\t\t\t\t***CONTACT EDITING***\n\n");
    Sleep(300);
    struct node *temp=start;
    int flag;
    char newname[20];
    int ph;
    printf("Enter CONTACT NUMBER whose details you want to edit:\t");
    scanf("%ld",&ph);
    while (temp != NULL)
    {
        if(temp->number==ph)
        {
            printf("Enter new name : ");
            scanf("%s",&newname);
            strcpy(temp->firstname,newname);
            printf("\n\n\t\t**CHANGES SUCCESSFULLY MADE**\n\n\n\n\n\n\n\n\n\n\n");
            flag=1;
            break;
        }
        temp = temp->next;
    }
    if(flag!=1)
        printf("\n\n\t\t!!CONATCT NOT FOUND!!\n\n\n\n\n\n\n\n\n\n");

}


int main()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t **** Welcome to Contact Management System ****");
    Sleep(2000);
main:
    system("cls");

    printf("\n\n\n\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t======================\n");
    Sleep(200);
    printf("\t\t\t\t\t[1] Add a new Contact\n");
    Sleep(200);
    printf("\t\t\t\t\t[2] List all Contacts\n");
    Sleep(200);
    printf("\t\t\t\t\t[3] Search for contact\n");
    Sleep(200);
    printf("\t\t\t\t\t[4] Edit a Contact\n");
    Sleep(200);
    printf("\t\t\t\t\t[5] Delete a Contact\n");
    Sleep(200);
    printf("\t\t\t\t\t[0] Exit\n\t\t\t\t\t======================\n\n");
    Sleep(600);
    printf("Enter the choice:\n");

    int ch;
    scanf("%d",&ch);


    switch(ch)
    {
        case 0:
            return 0;
        case 1: create();
            break;
        case 2: display(start);
            break;
        case 3:search();
            break;
        case 4: edit();
            break;
        case 5: del();
            break;

    }
    Sleep(1000);
    printf("\n\n\n\n\n..::Enter the Choice:\n\t[1] Main Menu\t[0] Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        goto main;
    case 0:
        return 0;
    default:
        printf("Invalid choice");
        break;
    }

    return 0;
}





