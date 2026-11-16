#include <stdio.h>
#include <string.h>
#include <conio.h>

struct
{
    char acc_number[10];
    float balance;
    char name[20];
    char mob_number[11];


} Acc_details[100];

void Bank_login(void);
void Customer_login(void);
void bank_task(void);
void customer_task(char);
void create_account(void);
void show_account(void);
int deposit(char);
int withdraw(char);
int balance_enquiry(char); 
void load_accounts(void);
int save_accounts(void);
int valid_mobile(const char *number);
int next_account_number = 1001;
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
   if (strlen(a_num) != 4)
    {
        printf("Enter a four digit account number\n");
        Customer_login();
        return;
    }
    for (int i = 0; i < 100; ++i) {
        if (strcmp(a_num, Acc_details[i].acc_number) == 0) {
            printf("Hello %s\nYour account details are being fetched.\n", Acc_details[i].name);
            customer_task(Acc_details[i].acc_number);
            return;
        }
    }
    printf("Invalid account number\n");
    Customer_login();
}
void bank_task()
{
    int choice;
    printf("Choose your task from below:\n1.Create new bank Account\n2.Edit details of an Account number\n3.Show complete datails of registered bank account\n4.Delete an account\n5.Exit\n");
    printf("Enter your choice:\n");
    if (scanf("%d", &choice) != 1) {
            printf("Invalid input.Enter valid choice .\n");
            bank_task();
    }
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
void customer_task(char *acc_num)
{
    int choice;
    printf("Choose your task from below:\n1.Deposit money\n2.Withdraw money\n3.balance enquiry\n4.Exit\n");
    printf("Enter your choice:\n");
    if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter valid choice .\n");
            customer_task(acc_num);
    }
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
            main();
        default:
            printf("Enter a valid choice from 1 to 4\n");
            customer_task(acc_num);
    }
}
void create_account(){
    int slot=-1;
    for(int i=0;i<100;i++){
        if(Acc_details[i].acc_number[0]=='\0'){
            slot=i;
            break;
        }
    }
    if(slot==-1){
        printf("Maximum account limit reached.\n");
        return;
    }
    char anum[5], name[20], mobile[11];
    if(next_account_number > 2000) {
        printf("Maximum account limit reached. Cannot create new account.\n");
        return;
    }
    printf("Enter customer name:\n");
    scanf("%s", name);
    printf("Enter ten digit mobile number: ");
    scanf("%s", mobile);
    if(!valid_mobile(mobile)){
        printf("Mobile number must contain exactly ten digits. Account was not created.\n");
        bank_task();
    }
    printf("Enter opening balance: ");
    if (scanf("%f", &Acc_details[slot].balance) != 1 || Acc_details[slot].balance < 0) {
        Acc_details[slot].balance = 0;
        printf("Invalid opening balance. Account was not created.\n");
        bank_task();
    }
    strcpy(Acc_details[slot].acc_number, anum);
    strcpy(Acc_details[slot].name, name);
    strcpy(Acc_details[slot].mob_number, mobile);
    ++next_account_number;
    if (save_accounts()) {
        printf("Account created successfully. Account number: %s\n", number);
    } else{
        --next_account_number;
        Acc_details[slot].acc_number[0] = '\0';
        Acc_details[slot].name[0] = '\0';
        Acc_details[slot].mob_number[0] = '\0';
        Acc_details[slot].balance = 0;
        printf("Could not save account data to bank.csv.\n");
    }
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
