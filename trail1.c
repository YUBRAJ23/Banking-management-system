#include <stdio.h>
#include <string.h>
#include <conio.h>
// Structure to store bank account details
struct
{
    char acc_number[10];
    float balance;
    char name[20];

} Acc_details[100];
// Function Prototypes
void Bank_login(void);
void Customer_login(void);
void bank_task(void);
void customer_task(char);
void create_account(void);
void edit_account(char);
void show_account(void);
void delete_account(void);
int deposit(char);
int withdraw(char);
int balance_enquiry(char); 
int main()
{
    int choice;
    printf("=================================================");
    printf("\nWelcome to our banking Management syatem\n");
    printf("=================================================");
    printf("\n-------------Login page--------------\n");
    printf("Enter Login Type:\n1.Bank official login\n2.Customer login\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Bank_login();
        break;
    case 2:
        Customer_login();
        break;
    default:
        printf("Enter a valid choice either 1 or 2\n");
    }
}
// Handles Bank Official Authentication
void Bank_login()
{
    char u_name[10], pass[10];
    char name[] = "admin", password[] = "cgu@2026";
    printf("Enter username:\n");
    scanf("%s", u_name);
    printf("Enter Password:\n");
    scanf("%s", pass);
    if (strcmp(u_name, name) == 0 && strcmp(pass, password) == 0)
    {
        bank_task();
    }
    else
    {
        printf("Invalid Username or password\n");
        Bank_login();
    }
}
// Handles Customer Authentication using Account Number
void Customer_login()
{
    char a_num[10];
    printf("Enter your account number:\n");
    scanf("%s", &a_num);
    int i = 0;
    int res=1;
    if(strlen(a_num)<10||strlen(a_num)>10)
    {
        printf("Enter ten digit account number\n");
        Customer_login();
    }
    do{
        if (strcmp(a_num, Acc_details[i].acc_number) == 0)
        {
            printf("Hello %s \nYour account details is being fetched", Acc_details[i].name);
            res=0;
            char *c = Acc_details[i].acc_number;
            customer_task(c);
        }}while(res);
        if(res)
        {
            printf("Invalid account number");
            Customer_login();
        }
}
void bank_task()// Menu for Bank Official Tasks
{
    int choice;
    printf("Choose your task from below:\n1.Create new bank Account\n2.Edit details of an Account number\n3.Show complete datails of registered bank account\n4.Delete an account\n5.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            create_account();
            break;
        case 2:
            edit_account();
            break;
        case 3:
            show_account();
            break;
        case 4:
            delete_account();
            break;
        case 5:
            exit(0);
        default:
            printf("Enter a valid choice from 1 to 5\n");
            bank_task();
    }
}
void customer_task(char *acc_num)// Menu for Customer Operations
{
    int choice;
    printf("Choose your task from below:\n1.Deposit money\n2.Withdraw money\n3.balance enquiry\n4.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            deposit(acc_num);
            break;
        case 2:
            withdraw(acc_num);
            break;
        case 3:
            balance_enquiry(acc_num);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice from 1 to 4\n");
            customer_task(acc_num);
    }
}
// Placeholder function definitions for banking operations
void create_account()
{
    int i;
    if (total_accounts >= 100) {
        printf("Bank database is full! Cannot create more accounts.\n");
        bank_task();
        return;
    }

    char new_acc[11];
    printf("\n--- Create New Bank Account ---\n");
    printf("Enter a 10-digit Account Number: ");
    scanf("%s", new_acc);

    // Validate 10-digit length
    if (strlen(new_acc) != 10) {
        printf("Error: Account number must be exactly 10 digits.\n");
        create_account();
        return;
    }

    // Check if account number already exists
    for (i = 0; i < total_accounts; i++) {
        if (strcmp(Acc_details[i].acc_number, new_acc) == 0) {
            printf("Error: Account number already exists!\n");
            create_account();
            return;
        }
    }

    strcpy(Acc_details[total_accounts].acc_number, new_acc);

    printf("Enter Customer Name: ");
    scanf(" %[^\n]", Acc_details[total_accounts].name);

    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &Acc_details[total_accounts].balance);

    if (Acc_details[total_accounts].balance < 0) {
        Acc_details[total_accounts].balance = 0;
        printf("Negative amount not allowed. Initial balance set to 0.\n");
    }

    total_accounts++;
    printf("Account created successfully!\n\n");
    bank_task();
}

void edit_account(char acc_num){
    
}
void show_account(){
    
}
void delete_account(){
    
}
int deposit(char acc_num){
    
}
int withdraw(char acc_num){
    
}
int balance_enquiry(char acc_num){
    
}
void home(){
    main();
}
