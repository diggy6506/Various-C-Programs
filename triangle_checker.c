#include <stdio.h>

  int main(void) {

  float a, b, c;


    printf("\nRemember to only type numbers.\n\n Press Any Key to Start\n");
      scanf("%*c");
    
    printf("Enter Length of Side A: ");
      scanf("%f", &a);

    printf("Enter Length of Side B: ");
      scanf("%f", &b);
    
    printf("Enter Length of Side C: ");
      scanf("%f", &c);

    
    
    
    if (a == b && a == c) {
        printf("Your Triangle is Equilateral!");
    }

    else if (a != b && a != c) {
        printf("Your Triangle is Scalene!");
    }

    else
        printf("Your Triangle is Isoscelses!");
    
    
    

    return 0;

  }
