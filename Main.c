#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
    char acc_number[10];
    float balance;
    char name[20];
    char mob_number[11];
    char acc_type[10];

} Acc_details[100];

void Bank_login(void);
void Customer_login(void);
void bank_task(void);
void customer_task(char *);
void create_account(void);
void show_account(void);
int deposit(char *);
int withdraw(char *);
int balance_enquiry(char *);
int valid_mobile_number(char *);
void load_accounts(void);
int save_accounts(void);
int next_account_number = 1001;
int main()
{
    int choice;
    load_accounts();
    printf("=================================================");
    printf("\nWelcome to our banking Management syatem\n");
    printf("=================================================");
    printf("\n-------------Login page--------------\n");
    printf("Enter Login Type:\n1.Bank official login\n2.Customer login\n3.Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Bank_login();
        break;
    case 2:
        Customer_login();
        break;
    case 3:
        printf("Thank you for using our banking management system.\n");
        exit(0);
    default:
        printf("Enter a valid choice either 1, 2 or 3\n");
        main();
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
    int res = 1;
    if (strlen(a_num) != 4)
    {
        printf("Enter a four digit account number\n");
        Customer_login();
    }
    for (int i = 0; i < 100; ++i)
    {
        if (strcmp(a_num, Acc_details[i].acc_number) == 0)
        {
            printf("Hello %s\nYour account details are being fetched.\n", Acc_details[i].name);
            customer_task(Acc_details[i].acc_number);
        }
    }
    printf("Invalid account number..Back to main menu.\n");
    main();
}
void bank_task()
{
    int choice;
    printf("Choose your task from below:\n1.Create new bank Account\n2.Show complete datails of registered bank account\n3.Back to main menu\n");
    printf("Enter your choice:\n");
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input.Enter valid choice .\n");
        bank_task();
    }
    switch (choice)
    {
    case 1:
        create_account();
        break;
    case 2:
        show_account();
        break;
    case 3:
        main();
    default:
        printf("Enter a valid choice from 1 to 3\n");
        bank_task();
    }
}
void customer_task(char *acc_num)
{
    int choice;
    printf("Choose your task from below:\n1.Deposit money\n2.Withdraw money\n3.balance enquiry\n4.Back to main menu \n");
    printf("Enter your choice:\n");
    if (scanf("%d", &choice) != 1)
    {
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
        break;
    default:
        printf("Enter a valid choice from 1 to 4\n");
        customer_task(acc_num);
    }
}
void create_account()
{
    int slot = -1;
    for (int i = 0; i < 100; i++)
    {
        if (Acc_details[i].acc_number[0] == '\0')
        {
            slot = i;
            break;
        }
    }
    if (slot == -1)
    {
        printf("Maximum account limit reached.\n");
        main();
    }
    char anum[5], name[20], mobile[11];
    if (next_account_number > 2000)
    {
        printf("Maximum account limit reached. Cannot create new account.\n");
        main();
    }
    printf("Enter customer name:\n");
    scanf(" %[^\n]", name);
    printf("Enter ten digit mobile number: ");
    scanf(" %[^\n]", mobile);
    if (!valid_mobile_number(mobile))
    {
        printf("Mobile number must contain exactly ten digits. Account was not created.\n");
        bank_task();
    }
    printf("Enter opening balance: ");
    if (scanf("%f", &Acc_details[slot].balance) != 1 || Acc_details[slot].balance < 0)
    {
        Acc_details[slot].balance = 0;
        printf("Invalid opening balance. Account was not created.\n");
        bank_task();
    }
    snprintf(anum, sizeof anum, "%d", next_account_number);
    strcpy(Acc_details[slot].acc_number, anum);
    strcpy(Acc_details[slot].name, name);
    strcpy(Acc_details[slot].mob_number, mobile);
    ++next_account_number;
    if (save_accounts())
    {
        printf("Account created successfully.\nYour Account number: %s\n", anum);
    }
    else
    {
        --next_account_number;
        Acc_details[slot].acc_number[0] = '\0';
        Acc_details[slot].name[0] = '\0';
        Acc_details[slot].mob_number[0] = '\0';
        Acc_details[slot].balance = 0;
        printf("Could not save account data to bank.csv.\n");
    }
    bank_task();
}

void show_account()
{
    int found = 0;
    printf("\n%s %s %s \n", "Account Number", "Customer Name", "Balance");
    for (int i = 0; i < 100; ++i)
    {
        if (Acc_details[i].acc_number[0] != '\0')
        {
            printf("%s %s %.2f\n", Acc_details[i].acc_number, Acc_details[i].name, Acc_details[i].balance);
            found = 1;
        }
    }
    if (!found)
        printf("No accounts have been registered.\n");
    bank_task();
}
int deposit(char *acc_num)
{
    float amount;
    int i;
    for (i = 0; i < 100; i++)
    {
        if (strcmp(acc_num, Acc_details[i].acc_number) == 0)
            break;
    }
    printf("Enter amount to deposit: ");
    if (scanf("%f", &amount) != 1 || amount <= 0)
    {
        printf("Enter a valid positive amount.\n");
        deposit(acc_num);
    }
    Acc_details[i].balance += amount;
    printf("Deposit successful.\nUpdated balance: %.2f\n", Acc_details[i].balance);
    main();
}
int withdraw(char *acc_num)
{
    float amount;
    int i;
    for (i = 0; i < 100; i++)
    {
        if (strcmp(acc_num, Acc_details[i].acc_number) == 0)
            break;
    }
    printf("Enter amount to withdraw: ");
    if (scanf("%f", &amount) != 1 || amount <= 0)
    {
        printf("Enter a valid positive amount.\n");
        withdraw(acc_num);
    }
    Acc_details[i].balance -= amount;
    printf("Withdrawal successful.\nUpdated balance: %.2f\n", Acc_details[i].balance);
    main();
}
int balance_enquiry(char *acc_num)
{
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(acc_num, Acc_details[i].acc_number) == 0)
        {
            printf("Account balance: %.2f\n", Acc_details[i].balance);
            main();
        }
    }
    printf("Account not found.\n");
    main();
}
int valid_mobile_number(char *number)
{
    if (strlen(number) != 10)
        return 0;
    for (int i = 0; i < 10; i++)
        if (number[i] < '0' || number[i] > '9')
            return 0;
    return 1;
}

void load_accounts(void)
{
    FILE *file = fopen("bank.csv", "r");
    char line[256];
    int slot = 0;
    if (file == NULL)
    {
        save_accounts();
        return;
    } /* Initialize the CSV on first run. */

    while (slot < 100 && fgets(line, sizeof line, file) != NULL)
    {
        char number[5], name[20];
        char *comma = strchr(line, ',');
        if (comma == NULL)
            continue;
        size_t number_length = (size_t)(comma - line);
        if (number_length == strlen("#NEXT_ACCOUNT_NUMBER") &&
            strncmp(line, "#NEXT_ACCOUNT_NUMBER", number_length) == 0)
        {
            int saved_next = strtoull(comma + 1, NULL, 10);
            if (saved_next >= 1001 && saved_next <= 2001)
                next_account_number = saved_next;
            continue;
        }
        if (number_length != 4)
            continue; /* Account numbers are four digits. */
        memcpy(number, line, number_length);
        number[4] = '\0';
        for (int j = 0; j < 4; ++j)
            if (number[j] < '0' || number[j] > '9')
                number[0] = '\0';
        if (number[0] == '\0')
            continue;

        char *p = comma + 1;
        size_t n = 0;
        if (*p == '"')
        {
            ++p;
            while (*p && *p != '\n' && *p != '\r')
            {
                if (*p == '"' && p[1] == '"')
                {
                    if (n < sizeof name - 1)
                        name[n++] = '"';
                    p += 2;
                }
                else if (*p == '"')
                {
                    ++p;
                    break;
                }
                else
                {
                    if (n < sizeof name - 1)
                        name[n++] = *p;
                    ++p;
                }
            }
            if (*p != ',')
                continue;
            ++p;
        }
        else
        {
            char *end = strchr(p, ',');
            if (end == NULL)
                continue;
            n = (size_t)(end - p);
            if (n >= sizeof name)
                continue;
            memcpy(name, p, n);
            p = end + 1;
        }
        name[n] = '\0';
        char mobile[11] = "";
        char *mobile_end = strchr(p, ',');
        if (mobile_end != NULL && (mobile_end == p || (size_t)(mobile_end - p) == 10))
        {
            int is_mobile = mobile_end == p;
            if (mobile_end != p)
            {
                is_mobile = 1;
                for (int j = 0; j < 10; ++j)
                    if (p[j] < '0' || p[j] > '9')
                        is_mobile = 0;
            }
            if (is_mobile)
            {
                if (mobile_end != p)
                {
                    memcpy(mobile, p, 10);
                    mobile[10] = '\0';
                }
                p = mobile_end + 1;
            }
        }
        char *balance_end;
        float balance = strtof(p, &balance_end);
        if (balance_end == p || balance < 0)
            continue;
        strcpy(Acc_details[slot].acc_number, number);
        strcpy(Acc_details[slot].name, name);
        strcpy(Acc_details[slot].mob_number, mobile);
        Acc_details[slot].balance = balance;
        unsigned long long existing_number = strtoull(number, NULL, 10);
        if (existing_number >= 1001 && existing_number <= 2000 &&
            existing_number + 1 > next_account_number)
            next_account_number = existing_number + 1;
        ++slot;
    }
    fclose(file);
}

int save_accounts(void)
{
    FILE *file = fopen("bank.csv", "w");
    if (file == NULL)
        return 0;
    fputs("account_number,name,mobile_number,balance\n", file);
    if (fprintf(file, "#NEXT_ACCOUNT_NUMBER,%d\n", next_account_number) < 0)
    {
        fclose(file);
        return 0;
    }
    for (int i = 0; i < 100; ++i)
    {
        if (Acc_details[i].acc_number[0] == '\0')
            continue;
        if (fprintf(file, "%s,\"", Acc_details[i].acc_number) < 0)
        {
            fclose(file);
            return 0;
        }
        for (const char *p = Acc_details[i].name; *p; ++p)
        {
            if (*p == '"' && fputc('"', file) == EOF)
            {
                fclose(file);
                return 0;
            }
            if (fputc(*p, file) == EOF)
            {
                fclose(file);
                return 0;
            }
        }
        if (fprintf(file, "\",%s,%.2f\n", Acc_details[i].mob_number, Acc_details[i].balance) < 0)
        {
            fclose(file);
            return 0;
        }
    }
    return fclose(file) == 0;
}
