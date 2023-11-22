#include <stdio.h>
#include <stdlib.h>

int somefunction(int i) {
    int someoutput;
    if (i == 0) {
        someoutput = 0;
    } else if (i == 1) {
        someoutput = 1;
    } else {
        someoutput = somefunction(i - 1) + somefunction(i - 2);
    }

    return someoutput;
}

int main() {
    int inputNum;
    printf("Enter input number: ");
    scanf("%d", &inputNum);
    int printThis = somefunction(inputNum);
    printf("Fn(%d) = %d", inputNum, printThis);

    return 0;
}
