#include <stdio.h>

int main(void) {


int no_terms, fib_no = 0, fib_res;


  printf("Enter the number of terms: ");

  scanf("%d", &no_terms);

  while (no_terms > 0) {
    
    fib_res = fib_no++;
  
    no_terms--;

  printf("%d ", fib_res);

}








return 0;

}
