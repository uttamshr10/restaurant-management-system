#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>
void admin();
void mainscreen();
void screenclear();
void delay();
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
void screenclear()
{
    system("cls");
}
void timer()
{
    time_t t;
    time(&t);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t Present Time: %s\n", ctime(&t));
}

void authentication()
{
    char username[10] = "Uttam";
    char password[10] = "Pratik";
    printf("\n\n\t\t\t\t||\t\t\t Enter your username:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
    scanf("%s", &username);
    printf("\n\n\t\t\t\t||\t\t\t Enter your password:\t\t\t||\n\n\t\t\t\t\t\t\t -> Password:\t");
    scanf("%s", &password);
    if (strcmp(username, "Uttam") != 0 || strcmp(password, "Pratik") != 0)
    {
        system("cls");
        printf("\n\n\t\t\t\t**\t\t\t Please enter the correct credentials.\t\t\t**\n\n\n"); // Just two new line
        authentication();
    }
    else
    {
        screenclear();
        printf("\n\n\n\n\n\n\n\n\t\t\t\t||\t\t\t You are authenticated.\t\t\t||\n\n"); // I want to show this message.
        int i;
        for (i = 3; i > 0; i--)
        {
            // delay of one second
            delay(1);
            screenclear();
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPlease wait for %d sec.", i);
        }
        delay(1.5);
        screenclear();
        admin();
    }
}

void admin()
{
    timer();
    // printf("\n\n\t\t\t\t\t||\t\t You are authenticated.\t\t\t||\n\n");
    int choice;
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n");
    printf("\n\t\t\t\t\t                      ADMIN SECTION \n");
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n\n");
    printf("\t\t\t\t\t\t\t1. Display order menu. \n"); // this is to let admin know which items are in stock.
    printf("\t\t\t\t\t\t\t2. Add new items in the order. \n");
    printf("\t\t\t\t\t\t\t3. Remove items from the order. \n");
    printf("\t\t\t\t\t\t\t4. View total sales. \n");
    printf("\t\t\t\t\t\t\t5. Go Back to Main Screen \n\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Preference : ");
    scanf("%d", &choice);
    printf("\n\n");
    switch (choice)
    {
    case 1:
        printf("Displaying the order.");
        break;
    case 2:
        printf("Add new items in the order.");
        break;
    case 3:
        printf("Remove items from the order.");
        break;
    case 4:
        printf("View total sales.");
        break;
    case 5:
        mainscreen();
        break;
    default:
        printf("\t\t\t\t\t\t\tPlease enter a valid number.\n\n");
        admin();
        break;
    }
}

void customer()
{
    screenclear();
    timer();
    int choice;
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n");
    printf("\n\t\t\t\t\t                   CUSTOMER SECTION \n");
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n\n");
    printf("\t\t\t\t\t\t\t1. Display order menu. \n"); // this is to let the customer know about menus
    printf("\t\t\t\t\t\t\t2. Place your order. \n");
    printf("\t\t\t\t\t\t\t3. Remove an item from the order. \n");
    printf("\t\t\t\t\t\t\t4. Display final bill. \n");
    printf("\t\t\t\t\t\t\t5. Reviews for improvement. \n");
    printf("\t\t\t\t\t\t\t6. Go Back to Main Screen \n\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Preference : ");
    scanf("%d", &choice);
    printf("\n\n");
    switch (choice)
    {
    case 1:
        printf("Displaying the order.");
        break;
    case 2:
        printf("Place your order.");
        break;
    case 3:
        printf("Remove an item from the order.");
        break;
    case 4:
        printf("Display final bill.");
        break;
    case 5:
        printf("Reviews for improvement.");
        break;
    case 6:
        mainscreen();
        break;
    default:
        printf("\t\t\t\t\t\t\tPlease enter a valid number.\n\n");
        customer();
        break;
    }
}

void mainscreen()
{
    screenclear();
    timer();
    int choice;
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n");
    printf("\n\t\t\t\t\t        WELCOME TO RESTAURANT MANAGEMENT SYSTEM \n");
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n\n");
    printf("\t\t\t\t\t\t\t1. ADMIN SECTION \n");
    printf("\t\t\t\t\t\t\t2. CUSTOMER SECTION \n");
    printf("\t\t\t\t\t\t\t3. Exit \n\n\n");

    printf("\t\t\t\t\t\"TAKE A TASTE. COME JOIN US, LIFE IS SO ENDLESSLY DELICIOUS.\"\n\n\n");
    printf("\t\t\t\t\t      Created and Designed by Uttam and Pratik\n\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Preference : ");
    scanf("%d", &choice);
    // if (choice == %d){
    //     // Then only proceed the program else stop it saying you entered character.
    // }
    printf("\n\n");
    if (choice == 3)
    {
        printf("\t\t\t\t\t\t\t Thank you for checking us.\n\n\n\n");
    }
    switch (choice)
    {
    case 1:
        authentication();
        // admin();
        // printf("\t\t\t\t\t\t\t Welcome to admin panel.\n\n");
        break;
    case 2:
        customer();
        // printf("\t\t\t\t\t\t\t Welcome to customer panel.\n\n");
        break;
    case 3:
        break;
    default:
        // if (choice == % c || choice == % s) // Why can't we compare like this??
        // {
        //     printf("Please enter a number not a character.");
        // }
        printf("\t\t\t\t\t\t\tPlease enter a valid number 1, 2 or 3.\n\n");
        mainscreen();
        break;
    }
}

int main()
{
    mainscreen();
    // authentication();
    // admin();
    // customer();
    return 0;
}
