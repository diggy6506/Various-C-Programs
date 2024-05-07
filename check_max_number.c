#include <stdio.h>

int main(void) {

int a, b, c; //Variables for user input


//Asks user for input and assigns input to corresponding variable

printf("Enter your first number: ");
scanf("%d", &a); 

printf("Enter your second number: ");
scanf("%d", &b);

printf("Enter your third number: ");
scanf("%d", &c);

/*Checks for largest integer and prints it.
 If the user inputs two of the same integer it outputs maximum anyway*/

if (a >= b && a >= c) {
  printf("The Maximum Number is: %d", a);
}

else if (b >= a && b >= c) {
  printf("The Maximum Number is: %d", b);
}

else if (c >= a && c >= b) {
  printf("The Maximum Number is: %d", c);
}


return 0;

}
