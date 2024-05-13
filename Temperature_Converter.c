#include <stdio.h>

int main(void) {

  float cels, fahr;
  float cels_to_fahr, fahr_to_cels;
  int submit;

    printf("Are you converting from Celsius or Fahrenheit?\n- Submit 1 for Celsius\n- Submit 2 for Fahrenheit\n  Your selection: ");
    scanf("\n%d", &submit);

      if (submit == 1) {
        printf("  Enter temperature in Celsius: ");
        scanf("%f", &cels);
        cels_to_fahr = 1.8 * cels + 32;
        printf("  Conversion to Fahrenheit: %.2f\n", cels_to_fahr);
      }
      
      else if (submit == 2) {
        printf("  Enter temperature in Fahrenheit: ");
        scanf("%f", &fahr);
        fahr_to_cels = 0.5556 * (fahr - 32);
        printf("  Conversion to Celsius: %.2f\n", fahr_to_cels);
      }
      
      else {
        printf("Incorrect input. Try again?\n");
      }

      return 0;
}
