#include <stdio.h>

int main(void) {

  //no_terms is 'number of terms', fib_... stores values

int no_terms, fib_no = 0, fib_res = 1, fib_temp;
int result;

  //Prompts and asks user for input
  
  printf("Enter the number of terms: ");
  result = scanf("%d", &no_terms);

  //Error handling in case user inputs negative number, zero or a string.

  if (result != 1 || no_terms <= 0) {
    printf("Error. Cannot take words, negative numbers or zero as input. Try again?");
  }

    while (getchar() != '\n');
    return 1;

  //While loop generating fibonacci numbers on each loop

  while (no_terms > 0) {
    
    fib_temp = fib_no + fib_res;
    printf("%d ", fib_res);
    fib_no = fib_res;
    fib_res = fib_temp;
  
  //Decreases terms by 1 on each iteration, ensuring users request is met. See while().
    
    no_terms--;
  
  }

  return 0;

}
