#include <stdio.h>

int main() {
    int inputNum;
    printf("Enter the number X: ");
    scanf("%d", &inputNum);

    printf("The Number Of turns required is ");
    if ((inputNum) % 10 == 0) {
        printf("0");
    } else if ((inputNum * 2) % 10 == 0) {
        printf("1");
    } else {
        printf("-1");
    }

    return 0;
}
