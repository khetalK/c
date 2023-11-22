#include <stdio.h>

void notesReqFn(int totalAmt, int *notesReq) {

    int currencyNotes[] = {100, 50, 20, 10, 5, 2, 1},
        numOfCurrencyNotes = sizeof(currencyNotes) / sizeof(currencyNotes[0]);

    for (int i = 0; i < numOfCurrencyNotes; i++) {
        if (totalAmt >= currencyNotes[i]) {
            notesReq[i] = totalAmt / currencyNotes[i];
            totalAmt %= currencyNotes[i];
        }
    }
}

int main() {
    int currencyNotes[] = {100, 50, 20, 10, 5, 2, 1},
        numOfCurrencyNotes = sizeof(currencyNotes) / sizeof(currencyNotes[0]),
        notesReq[7] = {0};

    int totalAmt;
    printf("Enter the value: ");
    scanf("%d", &totalAmt);

    notesReqFn(totalAmt, notesReq);

    for (int i = 0; i < numOfCurrencyNotes; i++) {
        if (notesReq[i] > 1) {
            printf("%d notes of %d\n", notesReq[i], currencyNotes[i]);
        } else if (notesReq[i] == 1) {
            printf("%d note of %d\n", notesReq[i], currencyNotes[i]);
        }
    }

    return 0;
}
