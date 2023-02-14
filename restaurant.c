#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>
int stringlength;
char user[10], pass[10];
void reviews();
void alreadySetLoginDetails();
void alreadySetLoginwithDetails();
void tableNumber();
void admin();
void customer();
void mainscreen();
void screenclear();
void username_prompt();
void password_prompt();
void ask_prompt();
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

void username_prompt() // Please note that first, call username_prompt then ask_prompt, ask_prompt will call password_prompt
{
    char username[10];
    printf("\n\t\t\t\t\t\t\tPlease enter admin username: ");
    scanf("%s", &user);
    printf("\n\t\t\t\t\t\t\tYour username is %s.\n", user);
}

void password_prompt()
{
    char re_entered[10];
    printf("\n\t\t\t\t\t\t\tPlease enter admin password: ");
    scanf("%s", &pass);
    printf("\n\t\t\t\t\t\t\tPlease re-enter your password for verification: ");
    scanf("%s", &re_entered);
    if (strcmp(pass, re_entered) == 0)
    {
        printf("\n\t\t\t\t\t\t\tYour password is %s.\n", pass);
        printf("\n\t\t\t\t\t\t\tPlease keep note of your password i.e %s\n\n", pass);
    }
    else
    {
        printf("\n\t\t\t\tSorry, one of your password doesn't match.\n\n");
        password_prompt();
    }
}

void ask_prompt()
{
    char character[4];
    printf("\n\t\t\t\tAre you sure you want to proceed?\n");
    printf("\n\t\t\t\tType 'YES' or 'yes' to proceed and 'NO' or 'no' to add new one : ");
    scanf("%s", &character);
    if (strcmp(character, "yes") == 0 || strcmp(character, "YES") == 0)
    {
        screenclear();
        password_prompt();
    }
    else
    {
        screenclear();
        username_prompt();
        ask_prompt();
    }
}

void authentication()
{
    char username[10];
    char password[10];
    printf("\n\n\t\t\t\t||\t\t\t Enter your username:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
    scanf("%s", &username);
    while (strcmp(username, user) != 0)
    {
        screenclear();
        printf("\n\n\t\t\t\t||\t\t\t Enter your username:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
        scanf("%s", &username);
    }
    if (strcmp(username, user) == 0)
    {
        printf("\n\n\t\t\t\t||\t\t\t Enter your password:\t\t\t||\n\n\t\t\t\t\t\t\t -> Password:\t");
        scanf("%s", &password);
    }

    while (strcmp(password, pass) != 0)
    {
        printf("\n\n\t\t\t\t**\t\t\t Please enter the correct credentials.\t\t\t**\n\n\n"); // Just two new line
        // authentication();
        printf("\n\n\t\t\t\t||\t\t\t Enter your password:\t\t\t||\n\n\t\t\t\t\t\t\t -> Password:\t");
        scanf("%s", &password);
    }
    if (strcmp(password, pass) == 0)
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
    }
}

void reaction()
{
    printf("\n\n\t1. Excellent \n\n\t2. Good \n\n\t3. Average \n\n\t4. Dissatisfied\n\n\t->\t");
}

void renew_password()
{
    char username[10];
    stringlength = strlen(user);
    if (stringlength == 0)
    {
        printf("\t\t\t\t\t\t\tPlease first add username and password.\n\n");
        username_prompt();
        ask_prompt();
    }
    else
    {
        alreadySetLoginDetails();
    }
}

void alreadySetLoginDetails()
{
    char username[10];
    printf("\n\n\t\t\t\t||\t\t\t Enter your username for verification:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
    scanf("%s", &username);
    if (strcmp(username, user) != 0)
    {
        screenclear();
        printf("\n\n\t\t\t\t\t\t\tIncorrect username, Please enter again \n\n");
        printf("\n\n\t\t\t\t||\t\t\t Enter your username:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
        scanf("%s", &username);
    }
    else if (strcmp(username, user) == 0)
    {
        password_prompt();
    }
}

void alreadySetLoginwithDetails()
{
    char username[10];
    printf("\n\n\t\t\t\t||\t\t\t Enter your username for verification:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
    scanf("%s", &username);
    if (strcmp(username, user) != 0)
    {
        screenclear();
        printf("\n\n\t\t\t\t\t\t\tIncorrect username, Please enter again \n\n");
        printf("\n\n\t\t\t\t||\t\t\t Enter your username:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
        scanf("%s", &username);
    }
    else if (strcmp(username, user) == 0)
    {
        printf("\n\t\t\t\t\t\t\tYour password is %s", pass);
        printf("\n\t\t\t\t\t\t\tPlease note your password: %s", pass);
    }
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
    char words[200];
    printf("\n\t\t\t\tAny comments, questions or suggestions?\n");
    scanf("%s", &words);
    printf("Great %s", words);
    customer();
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
    printf("\t\t\t\t\t\t\t1. Set username and password. \n"); // this is to let admin know which items are in stock.
    printf("\t\t\t\t\t\t\t2. Forgot password? \n");
    printf("\t\t\t\t\t\t\t3. View total sales. \n");
    printf("\t\t\t\t\t\t\t4. Go Back to Main Screen \n\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Preference : ");
    scanf("%d", &choice);
    printf("\n\n");
    switch (choice)
    {
    case 1:
        // printf("Set username and password.");
        screenclear();
        stringlength = strlen(user);
        if (stringlength == 0)
        {
            username_prompt();
            ask_prompt();
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\tUsername and Password is already set");
            printf("\n\n\t\t\t\t\t\t\tTo know your login details:\n");
            alreadySetLoginwithDetails();
        }
        admin();
        break;
    case 2:
        screenclear();
        renew_password();
        admin();
        break;
    case 3:
        stringlength = strlen(user);
        if (stringlength == 0)
        {
            screenclear();
            printf("\t\t\t\t\t\t\tPlease first add username and password.\n\n");
            username_prompt();
            ask_prompt();
            admin();
        }
        else
        {
            authentication();
            printf("\t\t\t\t\t\t\tView total sales.\n\n");
        }
        break;
    case 4:
        mainscreen();
        break;
    default:
        printf("\t\t\t\t\t\t\tPlease enter a valid number.\n\n");
        admin();
        break;
    }
}

void waiter()
{
    timer();
    int choice;
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n");
    printf("\n\t\t\t\t\t                      WAITER SECTION \n");
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n\n");
    printf("\t\t\t\t\t\t\t1. Display order menu. \n"); // this is to let admin know which items are in stock.
    printf("\t\t\t\t\t\t\t2. Add new items in the order. \n");
    printf("\t\t\t\t\t\t\t3. Remove items from the order. \n");
    printf("\t\t\t\t\t\t\t4. Go Back to Main Screen \n\n\n");
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
    printf("\t\t\t\t\t\t\t2. WAITER SECTION \n");
    printf("\t\t\t\t\t\t\t3. CUSTOMER SECTION \n");
    printf("\t\t\t\t\t\t\t4. Exit \n\n\n");

    printf("\t\t\t\t\t\"TAKE A TASTE. COME JOIN US, LIFE IS SO ENDLESSLY DELICIOUS.\"\n\n\n");
    printf("\t\t\t\t\t      Created and Designed by Uttam and Pratik\n\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Preference : ");
    scanf("%d", &choice);
    printf("\n\n");
    if (choice == 4)
    {
        printf("\t\t\t\t\t\t\t Thank you for checking us.\n\n\n\n");
    }
    switch (choice)
    {
    case 1:
        // authentication();
        admin();
        break;
    case 2:
        waiter();
        break;
    case 3:
        customer();
        break;
    case 4:
        break;
    default:
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
