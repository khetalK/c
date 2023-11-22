#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTRIES_LENGTH 999
#define DATA_FILE "ledger.dat"

typedef struct {
    int index;
    int index__filter;
    int date[3];
    int type;
    char category[51];
    int amount;
} ledgerEntry;

char *typeEnumToString(int typeEnum) {

    switch (typeEnum) {
    case 0:
        return "income";
    case 1:
        return "expense";
    default:
        return "N/A";
    }
}

/// @brief total number of elements/records
int i = 0;

void entriesToArray(ledgerEntry *entries);
// operations
void printEntries(ledgerEntry *entries, int entries__length);
void addEntries(ledgerEntry *entries);
void deleteEntry(ledgerEntry *entries);
int filterEntries(ledgerEntry *entries, ledgerEntry *outputEntries, int len);
int filterFurther();
void editEntries(ledgerEntry *entries);

int main() {
    ledgerEntry entries[ENTRIES_LENGTH];

    ///@brief create new file if it doesn't exist
    {
        FILE *fileptr = fopen(DATA_FILE, "a");
        fclose(fileptr);
    }

    ///@brief dummy entries
    {
        entries[0].index = 1;
        entries[0].date[0] = 01;
        entries[0].date[1] = 01;
        entries[0].date[2] = 2023;
        entries[0].type = 0;
        strcpy(entries[0].category, "sumn");
        entries[0].amount = 6969;
    }

    entriesToArray(entries);

    int choice = 0, loop = 1;

    printf("Hello!\n");
    while (loop) {

        printf("(1-> Print present entries,\n"
               "2-> Add entry,\n"
               "3-> Filter entries,\n"
               "4-> Edit an entry,\n"
               "5-> Delete an entry\n"
               "6-> Delete all entries\n"
               "7-> Exit): \n");
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            entriesToArray(entries);
            printEntries(entries, i);
            printf("\n");
            break;
        }
        case 2: {
            addEntries(entries);
            printf("\n");
            break;
        }
        case 3: {
            ledgerEntry outputEntries[ENTRIES_LENGTH];
            int filtered__len = filterEntries(entries, outputEntries, i);
            printEntries(outputEntries, filtered__len);
            if (filterFurther())
                filterEntries(entries, outputEntries, i);
            printEntries(outputEntries, filtered__len);
            printf("\n");
            break;
        }
        case 4: {
            editEntries(entries);
            printEntries(entries, i);
            printf("\n");
            break;
        }
        case 5: {
            deleteEntry(entries);
            printEntries(entries, i);
            printf("\n");
            break;
        }
        case 6: {
            FILE *fileptr = fopen(DATA_FILE, "w");
            fclose(fileptr);
            printf("\nThe file has been emptied!\n");
            break;
        }
        case 7:
            loop = 0;
            return 0;
        }
    }
}

void entriesToArray(ledgerEntry *entries) {
    FILE *fileptr = fopen(DATA_FILE, "r");

    i = 0;

    if (fileptr == NULL) {
        printf("Error!");
    }

    while (fread(&entries[i], sizeof(entries[0]), 1, fileptr)) {
        i++;
    }
    fclose(fileptr);
}

void arrayToEntries(ledgerEntry *entries) {
    FILE *fileptr = fopen(DATA_FILE, "w");
    int j = 0;

    while (j < i) {
        fwrite(&entries[j], sizeof(entries[0]), 1, fileptr);
        j++;
    }
    fclose(fileptr);
}

void printEntries(ledgerEntry *entries, int entries__length) {

    printf("\n");
    printf("there are %d records\n\n", entries__length);

    printf("%5s\t%10s\t%10s\t%10s\t%10s\n", "Index", "Date", "Type", "Category",
           "Amount");
    for (int j = 0; j < entries__length; j++) {
        printf("%5d\t%d-%d-%d  \t%10s\t%10s\t%10d\n", j + 1, entries[j].date[0],
               entries[j].date[1], entries[j].date[2],
               typeEnumToString(entries[j].type), entries[j].category,
               entries[j].amount);
    }
}

void addEntries(ledgerEntry *entries) {
    FILE *fileptr = fopen(DATA_FILE, "a");
    if (fileptr == NULL) {
        printf("Error!");
    }

    ledgerEntry newEntry;
    newEntry.index = i + 1;

    int input__loop = 0;

    ///@brief input date
    do {
        if (input__loop == 1) {
            printf("Enter A valid date!\n");
        }

        int thirtyOneDayMonths[7] = {1, 3, 5, 7, 8, 10, 12},
            thirtyOneDayMonth = 0;

        printf("Enter the date of transaction(DD-MM-YYYY): ");
        scanf("%d-%d-%d", &newEntry.date[0], &newEntry.date[1],
              &newEntry.date[2]);

        for (int j = 0; j < 7; j++) {
            if (newEntry.date[1] == thirtyOneDayMonths[j]) {
                thirtyOneDayMonth = 1;
            }
        }

        if (newEntry.date[1] < 12) {

            input__loop = 0;

            if (thirtyOneDayMonth == 1) {
                if (newEntry.date[0] > 31) {
                    input__loop = 1;
                }

            } else {
                if (newEntry.date[1] == 2) {
                    if (newEntry.date[0] > 28 && newEntry.date[2] % 4 != 0) {
                        input__loop = 1;
                    } else if (newEntry.date[0] > 29 &&
                               newEntry.date[2] % 4 == 0) {
                        input__loop = 1;
                    }

                } else {
                    if (newEntry.date[0] > 30) {
                        input__loop = 1;
                    }
                }
            }
        } else {
            input__loop = 1;
        }
    } while (input__loop);

    newEntry.index__filter = 0;

    ///@brief input transaction type
    do {
        if (input__loop == 1) {
            printf("Enter A valid Input!\n");
        }

        printf("Enter the Transaction Type (1->Income, 2->Expense): ");
        scanf("%u", &newEntry.type);

        input__loop = 0;

        if (newEntry.type != 1 && newEntry.type != 2) {
            input__loop = 1;
        }

    } while (input__loop);

    ///@brief input transaction category
    {
        printf("Enter the category: ");
        scanf("%s", newEntry.category);
    }

    ///@brief input transaction amount
    do {
        if (input__loop == 1) {
            printf("Enter A valid Input (greater than 0)!\n");
        }

        printf("Enter the Transaction Amount: ");
        scanf("%u", &newEntry.amount);

        input__loop = 0;

        if (newEntry.amount == 0) {
            input__loop = 1;
        }

    } while (input__loop);

    newEntry.type--;

    fwrite(&newEntry, sizeof(newEntry), 1, fileptr);
    fclose(fileptr);

    entriesToArray(entries);
    printEntries(entries, i);
}

int filterEntries(ledgerEntry *entries, ledgerEntry *outputEntries, int len) {
    int k = 0, o = 0, filter__loop = 0;

    {
        do {
            printf("\nSelect the field to filter for the edit: ");
            int choice = 0;
            printf("(1->Transaction Type(income/expense),"
                   "2->Category): ");
            scanf("%d", &choice);

            switch (choice) {
            case 1: {
                int filter__type = 0;

                printf("Enter the type of expense to filter(1->Income, "
                       "2->Expense): ");
                scanf("%d", &filter__type);

                filter__type--;
                printf("%d", filter__type);

                for (int j = 0; j < len; j++) {
                    if (entries[j].type == filter__type) {
                        outputEntries[k] = entries[j];
                        outputEntries[k].index__filter = k + 1;
                        k++;
                        o++;
                    }
                }
                if (o == 0) {

                    printf("No Entries!");
                    break;
                }
                filter__loop = 0;
                break;
            }
            case 2: {
                char filter__category[51];

                printf("Enter the category to filter: ");
                scanf("%s", filter__category);

                for (int j = 0; j < len; j++) {
                    if (strstr(entries[j].category, filter__category) == NULL) {
                        break;
                    }
                    outputEntries[k] = entries[j];
                    outputEntries[k].index__filter = k + 1;
                    k++;
                    o++;
                }
                if (o == 0) {

                    printf("No Entries!");
                    break;
                }
                printEntries(outputEntries, o);
                filter__loop = 0;
                break;
            }
            default: {
                printf("Invalid!");
                filter__loop = 1;
                break;
            }
            }
        } while (filter__loop);
    }
    return o;
}

int filterFurther() {
    int filter__loop = 0, furtherFilter = 0, furtherFilter__loop = 0;
    do {
        printf("\nFilter further?(1->Yes, 2->No): ");
        scanf("%d", &furtherFilter);
        switch (furtherFilter) {
        case 1: {
            filter__loop = 1;
            furtherFilter__loop = 0;
            break;
        }
        case 2: {
            filter__loop = 0;
            furtherFilter__loop = 0;
            break;
        }
        default: {
            furtherFilter__loop = 1;
            break;
        }
        }
    } while (furtherFilter__loop);
    return filter__loop;
}

void editEntries(ledgerEntry *entries) {
    ///@brief copy of i (total records/entries)
    int j = i;
    int edit__index = 0, j2 = j;

    printEntries(entries, i);

    ledgerEntry outputEntries[ENTRIES_LENGTH];

    ///@brief default entries if no filter is applied
    {
        for (int k = 0; k < ENTRIES_LENGTH; k++) {
            outputEntries[k] = entries[k];
        }
    }

    ///@brief filtered further or not
    {
        if (filterFurther()) {
            j = filterEntries(entries, outputEntries, i);
        } else {
            ///@brief indexing entries
            while (j) {
                outputEntries[j2 - j].index__filter = j2 - j + 1;
                j--;
            }
            j = i;
        };
    }

    printEntries(outputEntries, i);

    ///@brief getting filtered index of entry to be edited
    {
        printf("\nEnter the index of the entry to delete (first column): ");
        scanf("%d", &edit__index);

        while (j--) {
            if (outputEntries[j].index__filter == edit__index) {
                outputEntries[0] = outputEntries[j];
            }
        }
        j = i;
    }

    /// @brief editing the entry
    {
        int editChoice = 0, edit__loop = 0;
        do {
            printf("Enter the field you want to edit\n"
                   "(1-> Transation Type, \n"
                   "2-> Category, \n"
                   "3-> Amount): ");
            scanf("%d", &editChoice);

            FILE *fileptr = fopen(DATA_FILE, "r+");

            switch (editChoice) {
            case 1: {
                int newType = 0, loop__edit = 0;
                printf("Changing the Transaction Type...\n");
                printf("The present transaction type is %s.\n",
                       typeEnumToString(outputEntries[0].type));

                do {
                    if (loop__edit) {
                        printf("\nEnter a valid value!\n");
                    }

                    printf("Enter the new value(1->Income, 2->Expense): ");
                    scanf("%u", &newType);

                    if (newType != 1 && newType != 2) {
                        loop__edit = 1;
                    }
                } while (loop__edit);
                outputEntries[0].type = newType;

                while (j--) {
                    if (entries[j].index == outputEntries[0].index) {
                        entries[j].type = outputEntries[0].type;
                    }
                }
                break;
            }
            case 2: {
                char newCategory[51];

                printf("Changing the Category...\n");
                printf("The old category for the transaction is %s.\n",
                       outputEntries[0].category);

                printf("Enter the new category: ");
                scanf("%s", newCategory);
                strcpy(outputEntries[0].category, newCategory);

                while (j--) {
                    if (entries[j].index == outputEntries[0].index) {
                        strcpy(entries[j].category, newCategory);
                    }
                }
                break;
            }
            case 3: {
                int newAmount = 0;
                printf("Changing the Transaction Amount...\n");
                printf("The old value is %d.\n", outputEntries[0].amount);

                printf("Enter the new value(1->Income, 2->Expense): ");
                scanf("%u", &newAmount);
                outputEntries[0].amount = newAmount;

                while (j--) {
                    if (entries[j].index == outputEntries[0].index) {
                        entries[j].amount = outputEntries[0].amount;
                    }
                }
                break;
            }
            default: {
                edit__loop = 1;
                break;
            }
            }
            j = i;
            fclose(fileptr);
        } while (edit__loop);
    }

    arrayToEntries(entries);
}

void deleteEntry(ledgerEntry *entries) {
    ///@brief copy of i (total records/entries)
    int j = i;
    int delete__index = 0, j2 = j;

    printEntries(entries, i);

    ledgerEntry outputEntries[ENTRIES_LENGTH];

    ///@brief default entries if no filter is applied
    {
        for (int k = 0; k < ENTRIES_LENGTH; k++) {
            outputEntries[k] = entries[k];
        }
    }

    ///@brief filtered further or not
    {
        if (filterFurther()) {
            j = filterEntries(entries, outputEntries, i);
        } else {
            ///@brief indexing entries
            while (j) {
                outputEntries[j2 - j].index__filter = j2 - j + 1;
                j--;
            }
            j = i;
        };
    }

    printEntries(outputEntries, i);

    ///@brief getting filtered index of entry to be edited
    {
        printf("\nEnter the index of the entry to delete (first column): ");
        scanf("%d", &delete__index);

        while (j--) {
            if (outputEntries[j].index__filter == delete__index) {
                outputEntries[0] = outputEntries[j];
            }
        }
        j = i;
    }

    /// @brief deleting the entry
    {
        i--;
        j = 0;

        while (j < i) {
            if (entries[j].index < (outputEntries[0].index)) {
                break;
            }
            entries[j] = entries[j + 1];
            j++;
        }
    }

    arrayToEntries(entries);
}
