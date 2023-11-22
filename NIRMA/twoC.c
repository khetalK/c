// to swap values of vars

#include <stdio.h>

void thirdVar(int a, int b) {
    int c = 0;
    c = a;
    a = b;
    b = c;
    printf("Using Third Variable: \n");
    printf("\ta: %d\n", a);
    printf("\tb: %d\n", b);
}

void noThirdVar(int a, int b) {
    a = a + b;
    b = a - b;
    a = a - b;

    printf("Not Using Third Variable: \n");
    printf("\ta: %d\n", a);
    printf("\tb: %d\n", b);
}

int main() {

    int a;
    printf("Enter First Value: ");
    scanf("%d", &a);

    int b;
    printf("Enter Second Value: ");
    scanf("%d", &b);

    thirdVar(a, b);
    noThirdVar(a, b);

    return 0;
}
