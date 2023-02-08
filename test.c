// User will be able to set username and password concept and compare them for authentication. Password
// should be entered twice and match if both of them are correct.

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
char user[10], pass[10];
void delay();
void ask_prompt();
void username_prompt();
void password_prompt();
void menus();
void authentication();
void screenclear();

void screenclear()
{
    system("cls");
}
int main()
{
    // menus();
    // tableNumber();
    // reviews();
    username_prompt();
    ask_prompt();
    authentication();
    return 0;
}
// Menu will touch down later on.

// void menus()
// {
//     FILE *fp;
//     char s[2000];
//     fp = fopen("menus.txt", "r");
//     if (fp == NULL)
//     {
//         printf("Can't open menu right now.");
//     }
//     else
//     {
//         printf("\n Your menu is: \n");
//     }
//     fgets(s, 2000, fp);
//     printf("\n Your menu: %s \n", s);
//     fclose(fp);
// }

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

void username_prompt() // Please note that first, call username_prompt then ask_prompt, ask_prompt will call password_prompt
{
    printf("\n\t\t\t\tPlease enter admin username: ");
    scanf("%s", &user);
    printf("\n\t\t\t\tYour username is %s.\n", user);
}

void password_prompt()
{
    char re_entered[10];
    printf("\n\t\t\t\tPlease enter admin password: ");
    scanf("%s", &pass);
    printf("\n\t\t\t\tPlease re-enter your password for verification: ");
    scanf("%s", &re_entered);
    if (strcmp(pass, re_entered) == 0)
    {
        printf("\n\t\t\t\tYour password is %s.\n", pass);
        printf("\n\t\t\t\tPlease keep note of your password i.e %s\n\n", pass);
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

void admin()
{
    printf("No");
}

void authentication()
{
    char username[10];
    char password[10];
    printf("\n\n\t\t\t\t||\t\t\t Enter your username:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
    scanf("%s", &username);
    if (strcmp(username, user) == 0)
    {
        printf("\n\n\t\t\t\t||\t\t\t Enter your password:\t\t\t||\n\n\t\t\t\t\t\t\t -> Password:\t");
        scanf("%s", &password);
    }

    if (strcmp(password, pass) != 0)
    {
        printf("\n\n\t\t\t\t**\t\t\t Please enter the correct credentials.\t\t\t**\n\n\n"); // Just two new line
        // authentication();
        printf("\n\n\t\t\t\t||\t\t\t Enter your password:\t\t\t||\n\n\t\t\t\t\t\t\t -> Password:\t");
        scanf("%s", &password);
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
