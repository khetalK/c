#include <stdio.h>
#include <stdlib.h>

int main() {
    char userName[] = " ";
    int age = 18;
    printf("Enter your name: ");
    scanf("%s", &userName);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your name is %s, ", userName);
    printf("stored at %p!\n", &userName);
    printf("Your age is %d, ", age);
    printf("stored at %p!", &age);
    return 0;
}
