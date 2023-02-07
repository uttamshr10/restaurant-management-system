// User will be able to set username and password concept and compare them for authentication. Password
// should be entered twice and match if both of them are correct.

#include <stdio.h>
#include <string.h>
int tableno;
void ask_prompt();
void username_prompt();
void password_prompt();
void tableNumber();
void reviews();
int main()
{
    // tableNumber();
    reviews();
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
    char words[50];
    printf("Food Quality: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &first);
    printf("Your answer is %d.\n", first);
    printf("Overall Service Quality: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &second);
    printf("Your answer is %d.\n", second);
    printf("Cleanliness: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &third);
    printf("Your answer is %d.\n", third);
    printf("Order Accuracy: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &fourth);
    printf("Your answer is %d.\n", fourth);
    printf("Speed of Service: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &fifth);
    printf("Your answer is %d.\n", fifth);
    printf("Value: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &sixth);
    printf("Your answer is %d.\n", sixth);
    printf("Overall Experience: ");
    printf("\n1. Excellent \n2. Good \n3. Average \n4. Dissatisfied\n");
    scanf("%d", &seventh);
    printf("Your answer is %d.\n", seventh);
    printf("Any comments, questions or suggestions?\n");
    scanf("%[^/n]", words);
    printf("Your review: %s", words);
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
