#include <stdio.h>

int main(void) {
    float a, b, c = 0;
    char operator;

    printf("Standard Calculator.\n\nPress Enter to Start");
    scanf("%*c");

    printf("\nEnter First Number: ");
    if (scanf("%f", &a) != 1) {
        printf("\nInvalid Input");
        return 1;
    }
  
    printf("\nEnter Operator: ");
    scanf(" %c", &operator);

    printf("\nEnter Second Number: ");
    if (scanf("%f", &b) != 1) {
        printf("\nInvalid Input");
        return 1;
    }

    if(operator == '+') {
        c = a + b;
    }
    else if(operator == '-') {
        c = a - b;
    }
    else if(operator == '*' || operator == 'x') {
        c = a * b;
    }
    else if(operator == '/') {
        if(b == 0) {
            printf("\nError. Division by Zero");
            return 1;
        }
        c = a / b;  
    }
    else {
        printf("\nInvalid Input");
        return 1;
    }

    printf("\nAnswer: %.g", c);

    return 0;
}
