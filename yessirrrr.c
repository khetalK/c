#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, sum, prod, mod;
    float quot;
    printf("Enter A Value for a: ");
    scanf("%f", &a);
    printf("Enter A Value for b: ");
    scanf("%f", &b);
    sum = a + b;
    prod = a * b;
    quot = a / b;
    mod = ((int)(a) % (int)(b));
    printf("\nTheir sum is: %.f", sum);
    printf("\nTheir product is: %.f", prod);
    printf("\nTheir quotient when %.f is divided by %.f is: %.f", a, b, quot);
    printf("\nTheir product is: %.f", mod);
    return 0;
}
