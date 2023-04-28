#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <direct.h>
void mainscreen();
void customer();
void customerReviews();
void alreadySetLoginDetails();
int i, stringlength;
int first, second, third, fourth, fifth, sixth, seventh;
char words[200];
void pressEnter();
char user[10], pass[10];
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
struct node
{
    char foodname[50];
    int quantity;
    float price;
    int data;
    struct node *prev;
    struct node *next;
};
struct node *headc = NULL, *newnode, *tailc = NULL;
struct node *heada = NULL, *taila = NULL;
struct node *head_s;
void username_prompt() // Please note that first, call username_prompt then ask_prompt, ask_prompt will call password_prompt
{
    char username[10];
    printf("\n\t\t\t\t\t\t\tPlease enter admin username: ");
    scanf("%s", user);
    printf("\n\t\t\t\t\t\t\tYour username is %s.\n", user);
}

void password_prompt()
{
    char re_entered[10];
    printf("\n\t\t\t\t\t\t\tPlease enter admin password: ");
    scanf("%s", pass);
    printf("\n\t\t\t\t\t\t\tPlease re-enter your password for verification: ");
    scanf("%s", re_entered);
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
    scanf("%s", character);
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
    scanf("%s", username);
    while (strcmp(username, user) != 0)
    {
        screenclear();
        printf("\n\n\t\t\t\t||\t\t\t Enter your username:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
        scanf("%s", username);
    }
    if (strcmp(username, user) == 0)
    {
        printf("\n\n\t\t\t\t||\t\t\t Enter your password:\t\t\t||\n\n\t\t\t\t\t\t\t -> Password:\t");
        scanf("%s", password);
    }

    while (strcmp(password, pass) != 0)
    {
        printf("\n\n\t\t\t\t**\t\t\t Please enter the correct credentials.\t\t\t**\n\n\n"); // Just two new line
        // authentication();
        printf("\n\n\t\t\t\t||\t\t\t Enter your password:\t\t\t||\n\n\t\t\t\t\t\t\t -> Password:\t");
        scanf("%s", password);
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
    scanf("%s", username);
    if (strcmp(username, user) != 0)
    {
        screenclear();
        printf("\n\n\t\t\t\t\t\t\tIncorrect username, Please enter again \n\n");
        printf("\n\n\t\t\t\t||\t\t\t Enter your username:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
        scanf("%s", username);
        // there's a meme it's not a bug, it's a feature works here. haha
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
    scanf("%s", username);
    if (strcmp(username, user) != 0)
    {
        screenclear();
        printf("\n\n\t\t\t\t\t\t\tIncorrect username, Please enter again \n\n");
        printf("\n\n\t\t\t\t||\t\t\t Enter your username:\t\t\t||\n\n\t\t\t\t\t\t\t -> Username:\t");
        scanf("%s", username);
    }
    else if (strcmp(username, user) == 0)
    {
        printf("\n\t\t\t\t\t\t\tYour password is %s", pass);
        printf("\n\t\t\t\t\t\t\tPlease note your password: %s", pass);
    }
}

struct node *createadmin(struct node *head, int data, char foodname[25], float price)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->price = price;
    newnode->quantity = 0;
    strcpy(newnode->foodname, foodname);
    newnode->next = NULL;
    newnode->prev = NULL;
    struct node *temp = head;
    if (temp == NULL)
        heada = taila = newnode;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;

        newnode->prev = taila;
        taila = newnode;
    }
    return heada;
}
struct node *createcustomer(struct node *head, int data, int quantity)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp1 = heada;
    int flag = 0;
    while (temp1 != NULL)
    {
        if (temp1->data == data)
        {
            flag = 1;
            break;
        }
        temp1 = temp1->next;
    }

    if (flag == 1)
    {
        newnode->data = data;
        newnode->price = quantity * (temp1->price);
        newnode->quantity = quantity;
        strcpy(newnode->foodname, temp1->foodname);
        newnode->next = NULL;
        newnode->prev = NULL;
        struct node *temp = head;
        if (temp == NULL)
            headc = tailc = newnode;
        else
        {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = tailc;
            tailc = newnode;
        }
    }
    else
    {
        printf("\n\t\t\t\t\t\t\tThis item is not present in the menu!\n");
    }
    return headc;
}
void displayList(struct node *head)
{
    system("cls");
    struct node *temp1 = head;
    if (temp1 == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tList is empty.\n\n");
    }
    else
    {
        printf("\n");
        while (temp1 != NULL)
        {
            if (temp1->quantity == 0)

                printf("\t\t\t\t\t\t\t%d\t%s\t%0.2f\n", temp1->data, temp1->foodname, temp1->price);
            else
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t%d\t%0.2f\n", temp1->data, temp1->foodname, temp1->quantity, temp1->price);
            }
            temp1 = temp1->next;
        }
        printf("\n");
    }
}
struct node *totalsales(int data, int quantity)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    int flag = 0;
    struct node *temp1 = heada;
    while (temp1->data != data)
    {

        temp1 = temp1->next;
    }
    newnode->data = data;
    newnode->price = quantity * (temp1->price);
    newnode->quantity = quantity;
    strcpy(newnode->foodname, temp1->foodname);
    newnode->next = NULL;
    newnode->prev = NULL;
    struct node *temp = head_s;
    if (temp == NULL)
        head_s = newnode;
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data == data)
            {
                flag = 1;
                break;
            }

            temp = temp->next;
        }
        if (flag == 1)
        {
            temp->quantity += newnode->quantity;
            temp->price += newnode->price;
        }
        else
        {
            temp->next = newnode;
        }
    }
    return head_s;
}
void calculatetotsales()
{
    struct node *temp = headc;
    while (temp != NULL)
    {

        head_s = totalsales(temp->data, temp->quantity);
        temp = temp->next;
    }
}
struct node *delete(int data, struct node *head, struct node *tail)
{
    if (head == NULL)
    {
        printf("\n\t\t\t\t\t\t\tList is empty\n");
    }
    else
    {
        struct node *temp;
        if (data == head->data)
        {
            temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(temp);
        }
        else if (data == tail->data)

        {
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        else
        {
            temp = head;
            while (data != temp->data)
            {
                temp = temp->next;
            }
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}
int deleteadmin()
{

    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num;
    scanf("%d", &num);
    struct node *temp = heada;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            heada = delete (num, heada, taila);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int deletecustomer()
{
    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num;
    scanf("%d", &num);

    struct node *temp = headc;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            headc = delete (num, headc, tailc);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void displaybill()
{
    displayList(headc);
    struct node *temp = headc;
    float total_price = 0;
    while (temp != NULL)
    {
        total_price += temp->price;

        temp = temp->next;
    }
    printf("\t\t\t\t\t\t\tTotal price: %0.02f\n", total_price);
}
struct node *deleteList(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
            free(temp->prev);
        }
        free(temp);
        head = NULL;
    }
    return head;
}

void admin()
{
    timer();
    int choice;
    int flag = 0, j = 1;
    char ch;
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n");
    printf("\n\t\t\t\t\t                      ADMIN SECTION \n");
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n\n");
    printf("\t\t\t\t\t\t\t1. Set username and password. \n"); // this is to let admin know which items are in stock.
    printf("\t\t\t\t\t\t\t2. Forgot password? \n");
    printf("\t\t\t\t\t\t\t3. View total sales. \n");
    printf("\t\t\t\t\t\t\t4. Reviews \n");
    printf("\t\t\t\t\t\t\t5. Go Back to Main Screen \n\n\n");
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
            displayList(head_s);
            // printf("\t\t\t\t\t\t\tView total sales.\n\n");
            printf("\n\t\t\t\t\t\tPress any key to return to admin section:\n\t\t\t\t\t\t");
            fflush(stdin);
            ch = fgetc(stdin);
            flag = 1;
            admin();
        }
        break;
    case 4:
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
            customerReviews();
            admin();
        }
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

void waiter()
{
    timer();
    int choice;
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n");
    printf("\n\t\t\t\t\t                      WAITER SECTION \n");
    printf("\n\t\t\t\t\t---------------------------------------------------------- \n\n");
    printf("\t\t\t\t\t\t\t1. Display ordered items. \n");
    printf("\t\t\t\t\t\t\t2. Add new items in the menu. \n");
    printf("\t\t\t\t\t\t\t3. Remove items from the menu. \n");
    printf("\t\t\t\t\t\t\t4. Go Back to Main Screen \n\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Preference : ");
    scanf("%d", &choice);
    printf("\n\n");
    switch (choice)
    {
    case 1:
        screenclear();
        printf("\n\t\t\t\t\t\t\t Ordered items\n");
        displayList(headc);
        pressEnter();
        waiter();
        break;
    case 2:
        screenclear();
        printf("\n\t\t\t\t\t\t\tEnter serial no. of the food item: ");
        int num, flag = 0;
        char name[50];
        float price;
        scanf("%d", &num);

        struct node *temp = heada;
        while (temp != NULL)
        {
            if (temp->data == num)
            {
                printf("\n\t\t\t\t\t\tFood item with given serial number already exists.\n\n");
                flag = 1;
                pressEnter();
                waiter();
                break;
            }
            screenclear();
            temp = temp->next;
        }
        if (flag == 1)
            break;
        printf("\t\t\t\t\t\t\tEnter food item name: ");
        scanf("%s", name);
        printf("\t\t\t\t\t\t\tEnter price: ");
        scanf("%f", &price);
        heada = createadmin(heada, num, name, price);
        printf("\n\t\t\t\t\t\t\tNew food item added to the list.\n\n");
        pressEnter();
        waiter();
        break;
    case 3:
        screenclear();
        if (deleteadmin())
        {
            printf("\n\t\t\t\t\t\t Updated list of food items menu \n");
            displayList(heada);
            pressEnter();
            waiter();
        }
        else
            printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist.\n\n");
        pressEnter();
        waiter();
        break;
    case 4:
        mainscreen();
        break;
    default:
        printf("\t\t\t\t\t\t\tPlease enter a valid number.\n\n");
        waiter();
        break;
    }
}
void pressEnter()
{
    printf("\n\t\t\t\t\t\tPress any key to return to your section:\n\t\t\t\t\t\t");
    int flag = 0, j = 1;
    char ch;
    fflush(stdin);
    ch = fgetc(stdin);
    flag = 1;
}

void reviews()
{
    screenclear();

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
    printf("\n\t\t\t\tAny comments, questions or suggestions?\n");
    scanf("%s[^\n]", words);
    customer();
}

void customerReviews()
{
    if (first == 0)
    {
        printf("\n\t\t\t\t\t\t\t No Reviews yet!");
        pressEnter();
        admin();
    }
    else
    {
        printf("\n\t\t\t\t\t Customer Reviews: \n\n");
        printf("\t\t\t\t\t Food Quality: %d", first);
        printf("\n\t\t\t\t\t Overall Service Quality: %d", second);
        printf("\n\t\t\t\t\t Cleanliness: %d", third);
        printf("\n\t\t\t\t\t Order Accuracy: %d", fourth);
        printf("\n\t\t\t\t\t Speed of Service: %d", fifth);
        printf("\n\t\t\t\t\t Value: %d", sixth);
        printf("\n\t\t\t\t\t Overall Experience: %d", seventh);
        printf("\n\t\t\t\t\t Suggestions and questions: %s\n\n", words);
        pressEnter();
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
    printf("\t\t\t\t\t\t\t1. Place your order. \n");
    printf("\t\t\t\t\t\t\t2. Display your ordered items. \n");
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
        // printf("Place your order.");
        displayList(heada);
        printf("\n\t\t\t\t\t\tEnter number corresponding to the item you want to order: ");
        int n;
        scanf("%d", &n);
        printf("\t\t\t\t\t\tEnter quantity: ");
        int quantity;
        scanf("%d", &quantity);
        headc = createcustomer(headc, n, quantity);
        printf("\t\t\t\t\t\t\t\tThank you for the order.\n\n");
        pressEnter();
        customer();
        break;
    case 2:
        screenclear();
        printf("\n\t\t\t\t\t\t\t Ordered items\n");
        displayList(headc);
        pressEnter();
        customer();
        break;
    case 3:
        screenclear();
        if (deletecustomer())
        {
            system("cls");
            printf("\n\t\t\t\t\t\t Updated list of your ordered food items \n");
            displayList(headc);
            pressEnter();
            customer();
        }
        else
            printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist.\n");
        pressEnter();
        customer();
        break;
    case 4:
        screenclear();
        calculatetotsales();
        printf("\n\t\t\t\t\t\t\t  Final Bill \n");
        displaybill();
        headc = deleteList(headc);
        pressEnter();
        customer();
        break;
    case 5:
        // printf("Reviews for improvement.");
        reviews();
        customer();
        break;
    case 6:
        mainscreen();
        break;
    default:
        printf("\t\t\t\t\t\t\tPlease enter a valid number.\n\n");
        pressEnter();
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
    printf("\t\t\t\t\t\t\t4. Exit \n\n\n"); // Uncomment below code or remove this option at production.

    printf("\t\t\t\t\t\"TAKE A TASTE. COME JOIN US, LIFE IS SO ENDLESSLY DELICIOUS.\"\n\n\n");
    printf("\t\t\t\t\t      Created and Designed by Uttam and Pratik\n\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Preference : ");
    scanf("%d", &choice);
    printf("\n\n");
    if (choice == 4)
    {
        printf("\t\t\t\t\t\t\t Thank you for checking us.\n\n\n\n");
        int i;
        for (i = 5; i > 0; i--)
        {
            // delay of one second
            delay(1);
            screenclear();
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tBack to main menu in %d sec.", i);
        }
        printf("\n\n\n\n\n");
        screenclear();
        // mainscreen(); // Uncomment this during production
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
    heada = createadmin(heada, 1, "EGG BURGER", 300);
    heada = createadmin(heada, 2, "BEEF BURGER", 500);
    heada = createadmin(heada, 3, "CHEESE BURGER", 600);
    heada = createadmin(heada, 4, "CREAMY MUSHROOM", 700);
    heada = createadmin(heada, 5, "SPICY CHICKEN", 600);
    heada = createadmin(heada, 6, "BARBEQUE BURGER", 900);
    heada = createadmin(heada, 7, "HAWAIIAN BURGER", 1200);
    heada = createadmin(heada, 8, "FRENCH FRIES", 400);
    heada = createadmin(heada, 9, "NUGGET\t", 400);
    heada = createadmin(heada, 10, "SAUSAGE\t", 400);
    heada = createadmin(heada, 11, "CHICKEN WINGS", 700);
    heada = createadmin(heada, 12, "MELON ICECREAM", 400);
    heada = createadmin(heada, 13, "APPLE DESSERT", 400);
    heada = createadmin(heada, 14, "RED VELVET CAKE", 400);
    heada = createadmin(heada, 15, "BEEF\t", 200);
    heada = createadmin(heada, 16, "MUSHROOM", 200);
    heada = createadmin(heada, 17, "EGG\t", 200);
    heada = createadmin(heada, 18, "LEMONADE", 300);
    heada = createadmin(heada, 19, "SOFT DRINK", 500);
    heada = createadmin(heada, 20, "MILK SHAKE", 700);
    mainscreen();
}
