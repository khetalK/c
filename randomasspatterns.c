#include <stdio.h>

int main() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= 5; j++) {
            for (int k = 0; k < j; k++) {
                if (j < 5 - i) {
                    printf("  ");
                } else {
                    printf("%d ", k);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
