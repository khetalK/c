#include <stdbool.h>
#include <stdio.h>
#include <string.h>
void create_account();
int login();
void check_bank_balance(char *);
int transfer_money();
void display(char *);
void acc_details(char *);
int logout();

struct money {
  char usernameto[50];
  char usernamefrom[50];
  int money;
};

struct pass {
  char f_name[50];
  char l_name[50];
  char father[50];
  char mother[50];
  char username[50];
  int age;
  int password;
  int date_of_birth[3];
  int mobile_number;
};

int main() {
  int choice;
  char username[50];
  struct pass u1;

  printf("*******************************Welcome to SBI Bank "
         "Account*******************************");
  printf("\n");
  printf("Enter your choice:");
  printf("\n");
  printf("1:Create Account:");
  printf("\n");
  printf("2:Login:");
  printf("\n");
  printf("*********************************************************************"
         "**********************");
  printf("\n");

  printf("Enter your choice:");
  scanf("%d", &choice);

  if (choice == 1) {
    create_account();

  }

  else if (choice == 2) {
    login();
  }

  else {
    printf("Enter a valid choice");
  }

  return 0;
}

void create_account(void) {
  char f_name[50], l_name[50], father[50], mother[50], username[50];
  int age, password, day, month, year, mobile_number;
  struct pass u1;
  printf("Enter your age:");
  scanf("%d", &age);

  FILE *fp = NULL;
  fp = fopen("accounts.txt", "rb");
  printf("Enter your first name:");
  scanf("%s", u1.f_name);
  printf("\n");
  printf("Enter your last name:");
  scanf("%s", u1.l_name);
  printf("\n");
  printf("Enter your Father's name:");
  scanf("%s", u1.father);
  printf("\n");
  printf("Enter your Mother's name:");
  scanf("%s", u1.mother);
  printf("\n");
  printf("Enter your Username:");
  scanf("%s", u1.username);
  printf("\n");
  printf("Enter your mobile number:");
  scanf("%d", &u1.mobile_number);
  printf("\n");
  printf("Enter your Date Of Birth (dd<space>mm<space>yyyy):");
  scanf("%d %d %d", &u1.date_of_birth[0], &u1.date_of_birth[1],
        &u1.date_of_birth[2]);
  printf("\n");
  printf("Enter your Password (Password Strictly must be in integers):");
  scanf("%d", &u1.password);
  fwrite(&u1, sizeof(u1), 1, fp);
  fclose(fp);
  printf("................................Account Created "
         "Successfully...............................");
  printf("\n");
  printf("Enter to the login screen!");
  login();
}

int login() {
  int choice;
  char username1[50];
  char username[50];
  char password[50];
  FILE *fp;
  struct pass u1;
  fp = fopen("accounts.txt", "rb");
  printf("\n**************************************Account "
         "Login**************************************");
  printf("\n");
  printf("Enter your Username:");
  scanf("%s", username);
  printf("\n");
  printf("Enter your Password:");
  scanf("%s", password);
  while (fread(&u1, sizeof(u1), 1, fp)) {
    if (strcmp(username, u1.username) == 0) {
      display(username);
    }
  }
  fclose(fp);
}

void display(char username1[]) {
  int choice;
  char username[50];
  char password[50];
  FILE *fp;
  struct pass u1;
  fp = fopen("accounts.txt", "rb");
  while (fread(&u1, sizeof(u1), 1, fp)) {
    if (strcmp(username1, u1.username) == 0) {
      printf("######################################### CHOICE "
             "##########################################");
      printf("\n");
      printf("Make a choice:");
      printf("\n");
      printf("1:Account Details");
      printf("\n");
      printf("2:Transfer Money");
      printf("\n");
      printf("3:Check Balance");
      printf("\n");
      printf("4:Logout");
      printf("\n");
      printf("#################################################################"
             "##########################");
      printf("\n");
      printf("Enter your choice:");
      scanf("%d", &choice);
      if (choice == 1) {
        acc_details(username1);
        break;
      } else if (choice == 2) {
        transfer_money();
        break;
      } else if (choice == 3) {
        check_bank_balance(username1);
        break;
      } else if (choice == 4) {
        logout();
        break;
      } else {
        printf("Enter a valid choice!");
        break;
      }
    }
  }
  fclose(fp);
}

int transfer_money() {
  FILE *fp, *fm;
  struct pass u1;
  struct money m1;
  char username_to[50];
  char username_from[50];
  fp = fopen("accounts.txt", "rb");
  fm = fopen("money.txt", "rb");
  printf("\n");
  printf("Enter the username name you want to send money to:");
  scanf("%s", username_to);
  printf("\n");
  printf("Enter the username you want to send money from:");
  scanf("%s", username_from);
  printf("Enter the amount of money to be transferred:");
  scanf("%d", &m1.money);
  while (fread(&u1, sizeof(u1), 1, fp)) {
    if (strcmp(username_to, u1.username) == 0) {
      strcpy(m1.usernameto, u1.username);
      strcpy(m1.usernamefrom, username_from);
    }
  }
  printf("Money being transacted................");
  printf("\n");
  printf("Amount successfully transacted........");

  fwrite(&m1, sizeof(m1), 1, fm);
  fclose(fp);
  fclose(fm);
  acc_details(username_from);
}

void check_bank_balance(char username2[]) {
  FILE *fm;
  struct money m1;
  int i = 1, sum_of_money = 0;
  fm = fopen("money.txt", "r");
  printf("Sr no: %d");
  printf("\n");
  printf("TRANSACTION ID:%s");
  printf("\n");
  printf("AMOUNT: %d");
  printf("\n");
  while (fread(&m1, sizeof(m1), 1, fm)) {
    if (strcmp(username2, m1.usernameto) == 0) {
      printf(" %d", i);
      i++;
      printf(" %s", m1.usernamefrom);
      printf("%d", m1.money);
      sum_of_money = sum_of_money + m1.money;
    }
  }
  printf("Total Amount: %d", sum_of_money);
  fclose(fm);
  // acc_details(username2);
}

void acc_details(char username2[]) { printf("yo"); }

int logout() { printf("yo"); }
