#include <stdio.h>

int main(void) {

float a, b, c;
char operator;

  printf("Standard Calculator.\nPress Enter to Start.");
  scanf("%*c");

  printf("Enter First Number: ");
  scanf("%f", &a);

  while(getchar() != '\n');
  
  printf("Enter Operator: ");
  scanf(" %c", &operator);

  printf("Enter Second Number: ");
  scanf("%f", &b);

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
    printf("Error. Division by zero.\n");
    return 1;
  }
    c = a / b;
  }
    else {
    printf("Invalid input.\n");
    return 1;
  }
    
  printf("%f", c);

  return 0;
}
