#include <stdio.h>
#include <string.h>
#include <conio.h>

struct
{
    char acc_number[10];
    float balance;
    char name[20];

} Acc_details[100];

void Bank_login(void);
void Customer_login(void);
void bank_task(void);
void customer_task(char);
void create_account(void);
void edit_account(void);
void show_account(void);
void delete_account(void);
int deposit(account_number, amount);
int withdraw(account_number, amount);

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
            customer_task();
        }}while(res);
        if(res)
        {
            printf("Invalid account number");
            Customer_login();
        }
}
void bank_task()
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
void customer_task(char ){
    int choice;
    printf("Choose your task from below:\n1.Deposit money\n2.Withdraw money\n3.balance enquiry\n4.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            deposit();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            balance_enquiry();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice from 1 to 4\n");
            customer_task();
    }
}
