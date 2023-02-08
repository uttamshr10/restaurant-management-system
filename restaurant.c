#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>
void reviews();
void tableNumber();
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
        printf("\n\n\n\n\n\n\n\n\t\t\t\t||\t\t\t You are authenticated.\t\t\t||"); // I want to show this message.
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

void reaction()
{
    printf("\n\n\t1. Excellent \n\n\t2. Good \n\n\t3. Average \n\n\t4. Dissatisfied\n\n\t->\t");
}

void reviews()
{
    int first, second, third, fourth, fifth, sixth, seventh;
    printf("\n\n\t\t\t\tFood Quality: ");
    reaction();
    scanf("%d", &first);
    printf("\n\t\t\t\tOverall Service Quality: ");
    reaction();
    scanf("%d", &second);

    printf("\n\t\t\t\tCleanliness: ");
    reaction();
    scanf("%d", &third);
    printf("\n\t\t\t\tOrder Accuracy: ");
    reaction();
    scanf("%d", &fourth);

    printf("\n\t\t\t\tSpeed of Service: ");
    reaction();
    scanf("%d", &fifth);
    printf("\n\t\t\t\tValue: ");
    reaction();
    scanf("%d", &sixth);
    printf("\n\t\t\t\tOverall Experience: ");
    reaction();
    scanf("%d", &seventh);
    char words[500];
    printf("\n\t\t\t\tAny comments, questions or suggestions?\n");
    scanf("%s", &words); // string is taken but not with spaces.
    // scanf("%[^\n]",words);
    // gets(words);
    // printf("Your review: "); // Even this is also not working.
    // puts(words);
    printf("Your review: %s", words); // remove this after fixing the issue.
}

void tableNumber()
{
    int tableno;
    printf("\t\t\t\t\t\t\tEnter your table no: ");
    scanf("%d", &tableno);
    printf("\t\t\t\t\t\t\tYour table no. is %d.\n\n", tableno);
}

void admin()
{
    timer();
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
        // printf("Place your order.");
        tableNumber();
        printf("\t\t\t\t\t\t\tThank you for the order.\n\n");
        break;
    case 3:
        printf("Remove an item from the order.");
        break;
    case 4:
        printf("Display final bill.");
        break;
    case 5:
        // printf("Reviews for improvement.");
        reviews();
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
        screenclear();
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
