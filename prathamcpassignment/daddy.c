#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SALES_MAX 999

struct storeItem {
    int item__id;
    char item__name[50];
    double item__price;
    double profit_percentage;
};

struct orderItem {
    int item__id;
    char item__name[50];
    int item__price;
    int item__quantity;
    int item__totalcost;
};

struct order {
    int order__id;
    struct orderItem orderItems[50];
    int order__total;
    double order__profit;
};

struct sales {
    struct order orders[SALES_MAX];
    double sales__total;
    double sales__profit;
};

int main() {
    struct storeItem storeItems[50];
    int finalOrderId = 0;
    // getting store items from external file
    {
        struct sales salesEl;
        FILE *file = fopen("sales.dat", "rb");

        if (file == NULL) {
            printf("No previous sales!\n");
        } else {
            fread(&salesEl, sizeof(salesEl), 1, file);

            for (int i = 0; salesEl.orders[i].order__total != 0; i++) {
                finalOrderId++;
            }
        }

        fclose(file);
    }
    {
        FILE *file = fopen("storeItems.dat", "rb");
        if (file == NULL) {
            printf("Error opening file for writing.\n");
            return 1;
        }
        fread(storeItems, sizeof(struct storeItem), 50, file);

        fclose(file);
    }

    printf("Hello!\n");
    int loop = 1;
    do {
        int choice = 0;
        loop = 1;
        printf("type 1 to show present items in the store\n"
               "type 2 to bill a new order\n"
               "type 3 to see the sales\n"
               "type 0 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 0: {
            loop = 0;
            return 0;
        }
        case 1: {
            printf("%5s\t%20s\t%3s\t%4s\n", "ID", "Name", "Price", "Profit %");
            for (int i = 0; i < 50; i++) {
                printf("%-5d\t%-20s\t%3.0lf\t%-3.2lf\n", storeItems[i].item__id,
                       storeItems[i].item__name, storeItems[i].item__price,
                       storeItems[i].profit_percentage);
            }
            break;
        }
        case 2: {
            struct sales salesEl;
            // storing previous sales' data
            {
                FILE *file = fopen("sales.dat", "rb");

                if (file == NULL) {
                    printf("No previous sales!\n");
                } else {
                    fread(&salesEl, sizeof(salesEl), 1, file);

                    for (int i = 0; salesEl.orders[i].order__total != 0; i++) {
                        finalOrderId++;
                    }
                }

                fclose(file);
            }

            struct order newOrder;
            ///@brief last item in the array that is ordered
            int finalItemId = 0;

            newOrder.order__id = ++finalOrderId;

            for (int i = 0; i < 50; i++) {
                newOrder.orderItems[i].item__id = i + 1;
                strcpy(newOrder.orderItems[i].item__name,
                       storeItems[i].item__name);
                newOrder.orderItems[i].item__price = storeItems[i].item__price;
                newOrder.orderItems[i].item__quantity = 0;
                newOrder.orderItems[i].item__totalcost = 0;
            }

            // taking order details
            while (1) {
                int newOrder__item__id, newOrder__item__quantity,
                    j = 50, input__loop = 0;
                do {
                    // notify
                    if (input__loop) {
                        printf("\nEnter a valid item id!\n");
                    }

                    // input
                    printf("Enter the item id(Enter -1 to stop): ");
                    scanf("%d", &newOrder__item__id);

                    // checking
                    if (newOrder__item__id < 0 || newOrder__item__id > 50) {
                        input__loop = 1;

                        if (newOrder__item__id == -1) {
                            input__loop = 0;
                        }
                    }

                } while (input__loop);
                input__loop = 0;

                // exit condition
                if (newOrder__item__id == -1) {
                    break;
                }
                newOrder__item__id--;

                do {
                    // notify
                    if (input__loop) {
                        printf("\nEnter a valid value!\n");
                    }

                    // input
                    printf("Enter the quantity: ");
                    scanf("%d", &newOrder__item__quantity);

                    // checking
                    if (newOrder__item__quantity <= 0) {
                        input__loop = 1;
                    }

                } while (input__loop);

                newOrder.orderItems[newOrder__item__id].item__quantity +=
                    newOrder__item__quantity;

                newOrder.orderItems[newOrder__item__id].item__totalcost =
                    newOrder.orderItems[newOrder__item__id].item__price *
                    newOrder.orderItems[newOrder__item__id].item__quantity;

                // identifying the last item from array that is ordered
                while (j--) {
                    if (newOrder.orderItems[j].item__totalcost != 0) {
                        finalItemId = newOrder.orderItems[j].item__id;
                        break;
                    }
                }
            }

            // calculating total cost and total profit
            for (int i = 0; i < finalItemId; i++) {
                printf("%d, ", newOrder.orderItems[i].item__quantity);
                if (newOrder.orderItems[i].item__quantity > 0) {
                    newOrder.order__total =
                        newOrder.order__total +
                        newOrder.orderItems[i].item__totalcost;

                    newOrder.order__profit =
                        newOrder.order__profit +
                        (newOrder.orderItems[i].item__totalcost *
                         storeItems[i].profit_percentage);
                }
            }

            printf("The order total is %d\n", newOrder.order__total);

            // adding order details to sales file
            {
                FILE *file = fopen("sales.dat", "wb");

                salesEl.orders[finalOrderId - 1] = newOrder;
                salesEl.sales__total += newOrder.order__total;
                salesEl.sales__profit += newOrder.order__profit;

                fwrite(&salesEl, sizeof(salesEl), 1, file);

                fclose(file);
            }
            break;
        }
        case 3: {
            struct sales salesEl;
            FILE *file = fopen("sales.dat", "rb");

            if (file == NULL) {
                printf("No data!\n");
                break;
            }

            fread(&salesEl, sizeof(salesEl), 1, file);

            printf("Total Revenue: %lf\n", salesEl.sales__total);
            printf("Total profits: %lf\n", salesEl.sales__profit);

            int seeorders = 0;
            printf("Type 1 to see sales' orders details\n");
            scanf("%d", &seeorders);

            if (seeorders == 1) {
                printf("%-5s %-10s %-10s\n", "Id", "Total", "Profit");
                for (int i = 0; i < finalOrderId; i++) {
                    printf("%-5d %-10lf %-10lf\n", salesEl.orders[i].order__id,
                           salesEl.sales__total, salesEl.sales__profit);
                }
            }

            fclose(file);
            break;
        }
        default: {
            loop = 1;
            break;
        }
        }
        printf("\n\n");
    } while (loop);
}
