// User will be able to set username and password concept and compare them for authentication. Password
// should be entered twice and match if both of them are correct.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int tableno;
void ask_prompt();
void username_prompt();
void password_prompt();
void tableNumber();
void reviews();
void menus();
void clearscreen();

void clearscreen()
{
    system("cls");
}
int main()
{
    menus();
    // tableNumber();
    // reviews();
    // username_prompt();
    // ask_prompt();
    return 0;
}

void tableNumber()
{
    printf("Enter your table no: ");
    scanf("%d", &tableno);
    printf("Your table no. is %d.", tableno);
}

void reviews()
{
    int excellent, good, average, dissatisfied, first, second, third, fourth, fifth, sixth, seventh;
    char words[500];
    printf("Food Quality: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &first);
    printf("Your answer is %d.\n", first);
    clearscreen();
    printf("Overall Service Quality: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &second);
    printf("Your answer is %d.\n", second);
    clearscreen();
    printf("Cleanliness: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &third);
    printf("Your answer is %d.\n", third);
    clearscreen();
    printf("Order Accuracy: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &fourth);
    printf("Your answer is %d.\n", fourth);
    clearscreen();
    printf("Speed of Service: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &fifth);
    printf("Your answer is %d.\n", fifth);
    clearscreen();
    printf("Value: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &sixth);
    printf("Your answer is %d.\n", sixth);
    clearscreen();
    printf("Overall Experience: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &seventh);
    printf("Your answer is %d.\n", seventh);
    clearscreen();

    printf("Any comments, questions or suggestions?\n");
    scanf("%s", &words);
    printf("Your review: %s", words);
    clearscreen();
    printf("Thank you for your response");
}

void menus()
{
    FILE *fp;
    char s[2000];
    fp = fopen("menus.txt", "r");
    if (fp == NULL)
    {
        printf("Can't open menu right now.");
    }
    else
    {
        printf("\n Your menu is: \n");
    }
    fgets(s, 2000, fp);
    printf("\n Your menu: %s \n", s);
    fclose(fp);
}

void username_prompt()
{
    char username[10];
    printf("Please enter admin username:\n");
    scanf("%s", &username);
    printf("Your username is %s.\n", username);
}

void password_prompt()
{
    char password[10];
    printf("Please enter admin password: ");
    scanf("%s", &password);
    printf("Your password is %s.\n", password);
    printf("Please keep note of your password i.e %s\n", password);
}

void ask_prompt()
{
    char character[4];
    printf("Are you sure you want to proceed?\n");
    printf("Type 'Yes' or 'yes' to proceed and 'No' or 'no' to add new one :\n");
    scanf("%s", &character);
    if (strcmp(character, "yes") == 0 || strcmp(character, "YES") == 0)
    {
        password_prompt();
    }
    else
    {
        username_prompt();
        ask_prompt();
    }
}
