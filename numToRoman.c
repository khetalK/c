#include <stdio.h>

int main()
{
    int numericalNum;
    char oneRomanNum = 'I';
    char fiveRomanNum = 'V';
    char tenRomanNum = 'X';
    char fiftyRomanNum = 'L';
    char hundredRomanNum = 'C';
    char fiveHundredRomanNum = 'D';
    char thousandRomanNum = 'M';
    printf("Enter the number: ");
    scanf("%i", &numericalNum);

    int numHundreds = numericalNum / 100;
    int numTens = numericalNum / 10 - numHundreds * 10;
    int numOnes = numericalNum % 10;

    if (numHundreds <= 3)
    {
        int i = 0;
        while (i < numHundreds)
        {
            printf("%c", hundredRomanNum);
            i++;
        }
    }
    else if (numHundreds <= 4)
    {
        printf("CD");
    }
    else if (numHundreds <= 8)
    {
        printf("%c", fiveHundredRomanNum);

        int i = 0;
        while (i < numHundreds - 5)
        {
            printf("%c", hundredRomanNum);
            i++;
        }
    }
    else if (numHundreds <= 9)
    {
        printf("CM");
    }
    else if (numHundreds == 10)
    {
        printf("%i", thousandRomanNum);
    }

    if (numTens <= 3)
    {
        int i = 0;
        while (i < numTens)
        {
            printf("%c", tenRomanNum);
            i++;
        }
    }
    else if (numTens <= 4)
    {
        printf("XL");
    }
    else if (numTens <= 8)
    {
        printf("%c", fiftyRomanNum);

        int i = 0;

        while (i < numTens - 5)
        {
            printf("%c", tenRomanNum);
            i++;
        }
    }
    else if (numTens <= 9)
    {
        printf("XC");
    }

    if (numOnes <= 3)
    {
        int i = 0;
        while (i < numOnes)
        {
            printf("%c", oneRomanNum);
            i++;
        }
    }
    else if (numOnes <= 4)
    {
        printf("IV");
    }
    else if (numOnes <= 8)
    {
        printf("%c", fiveRomanNum);
        int i = 0;
        while (i < numOnes - 5)
        {
            printf("%c", oneRomanNum);
            i++;
        }
    }
    else if (numOnes <= 9)
    {
        printf("IX");
    }

    return 0;
}
