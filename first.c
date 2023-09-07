//%d->data;
//%s->string
#include <stdio.h>

int main()
{
    char characterName[] = "John";
    int characterAge1 = 35;
    int characterAge2 = 69;
    printf("hello  %s!\n", characterName);
    printf("You are %d years old, %d", characterAge1, characterAge2);
    return 0;
}
