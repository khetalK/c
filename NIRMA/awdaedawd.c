#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void mainmenu(void);
void display_menu(void);
void contact(void);
void about_us(void);
void exit_it(void);
void menucard(void);

struct info {
    char name[50];
    int age;
    char gender;
} s[1];

int main() {
    printf("\t\t\t\t<<<-----INDIAN VEGETARIAN RESTAURANT MANAGEMENT "
           "SYSTEM------>>>");
    printf("\n\n HELLO! ENTER YOUR NAME : ");
    gets(s[1].name);
    printf("\n\n ENTER YOUR AGE : ");
    scanf("%d", &s[1].age);
    printf("\n\n ENTER YOUR GENDER ( M / F ): ");
    scanf(" %c", &s[1].gender);

    if (s[1].gender == 'M' || s[1].gender == 'm') {
        printf("\n\n\t<----WELCOME TO OUR INDIAN VEGETARIAN RESTAURANT Mr. "
               "%s---->\n\t",
               s[1].name);
    } else if (s[1].gender == 'F' || s[1].gender == 'f') {
        printf("\n\n\t<----WELCOME TO OUR INDIAN VEGETARIAN RESTAURANT Miss. "
               "%s---->\n\t",
               s[1].name);
    } else {
        printf("\n\n\t<----Invalid INPUT---->\n\t");
    }

    mainmenu();
    return 0;
}

void mainmenu(void) {
    int choice;
    printf("\n1.DISPLAY MENU \n2.CONTACT \n3.ABOUT US \n4.EXIT");
    printf("\nCHOOSE ANY OPTION YOU WANT : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        display_menu();
        break;
    case 2:
        contact();
        break;
    case 3:
        about_us();
        break;
    case 4:
        exit_it();
        break;
    default:
        printf("\nINVALID! Please choose the correct option.");
    }
}

void contact(void) {
    printf("\n\n\t<<FOR DELIVERY>>\n\n\t");
    printf("\n\tCALL US AT ---> 090-078-601");
    printf("\n\t OR VISIT OUR WEBSITE:");
    printf("\t www.ourrestaurant.com");
    printf("\n\n");
    mainmenu();
}

void about_us(void) {
    printf("\n\n\t<<<ABOUT US>>>\t");
    printf("\n<<<---WE PROVIDE DELICIOUS VEGETARIAN INDIAN CUISINE--->");
    printf("\n\n\t---TIMINGS---\n");
    printf("\nMON - FRI: 12PM - 12AM");
    printf("\nSAT - SUN: 1PM - 4AM");
    printf("\n\n\t<<---BRANCHES ALL OVER INDIA--->>");
    printf("\n\n");
    mainmenu();
}

void exit_it(void) { printf("\nHOPE TO SEE YOU AGAIN. :) "); }

void display_menu(void) {
    printf("\n\n\t<<<<<MENU>>>>>");
    printf("\n\nS# Item Price");
    printf("\nD1. Paneer Tikka \tRs.150/-");
    printf("\nD2. Vegetable Biryani \tRs.250/-");
    printf("\nD3. Aloo Gobi \tRs.180/-");
    printf("\nD4. Dal Makhani \tRs.200/-");
    printf("\nD5. Palak Paneer \tRs.220/-");
    printf("\nD6. Chole Bhature \tRs.180/-");
    printf("\nD7. Masala Dosa \tRs.160/-");
    printf("\nD8. Veg Thali \tRs.300/-");
    printf("\nD9. Gulab Jamun \tRs.80/-");

    int select;
    printf("\n\n\n<<< 1.SELECT YOUR ORDER \n\n\n<<< 2.GO BACK");
    printf("\n\nCHOOSE YOUR PREFERRED OPTION : ");
    scanf("%d", &select);

    switch (select) {
    case 1:
        menucard();
        break;
    case 2:
        mainmenu();
        break;
    default:
        printf("\n\n\t<<<INVALID INPUT>>>\n\n");
    }
}

void menucard(void) {
    int n, order[n];
    float total;
    int b, i, serial;

    printf("\nPLEASE ENTER THE NUMBER OF ITEMS YOU WANT TO ORDER : ");
    scanf("%d", &n);

    if (n <= 0)
        exit_it();
    else {
        for (i = 0; i < n; i++) {
            for (b = 1; b < 2; b++) {
                printf("\n\nPLEASE ENTER THE SERIAL NUMBER (S#) OF YOUR ITEM "
                       "NUMBER %d:\tD",
                       i + 1);
                scanf("%d", &serial);
                order[i] = serial * 100;
            }
        }

        for (i = 0; i < n; i++) {
            total += order[i];
        }

        printf("\n\n\t\t YOUR BILL WITHOUT TAX IS = %.3frs", total);
        printf("\n\n\t YOUR TOTAL AMOUNT AFTER 13 PERCENT GST AND 10 PERCENT "
               "SERVICE CHARGE = %.3frs",
               total += total * 0.23);
        printf("\n\n\n\t<<<<<YOUR ORDER HAS BEEN RECEIVED. PLEASE WAIT 30 MINS "
               "FOR YOUR ORDER>>>>>");
        printf("\n\n\n\t ---Pay your bill at the cash counter & enjoy your "
               "meal! :) \n\n\n\t\t\t");
        exit_it();
    }

    getch();
}
