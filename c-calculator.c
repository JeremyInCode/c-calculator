#include <stdio.h>
#include <math.h>

void print_menu();
double division(double a, double b);
double modulus(int a, int b);

int main()
{
    int choice;
    double firstNumber, secondNumber, result;
    while(1)
    {
    print_menu();    
    int ret = scanf("%d", &choice);
    if (ret != 1) {
    fprintf(stderr, "\nInvalid choice. Please, try again.\n");
    while (getchar() != '\n');  
    continue;
    }
    
    if (choice == 7)
    {
        printf("Thank you for using C Calculator!\n");
        break;
    }

    if (choice < 1 || choice > 7)
    {
        fprintf(stderr, "\nInvalid choice. Please, try again.\n");
        continue; 
    }
    printf("Please, enter the first number: ");
    scanf("%lf", &firstNumber);
    printf("Now, enter the second number: ");
    scanf("%lf", &secondNumber);

    switch (choice)
    {
        case 1: // Add
          result = firstNumber + secondNumber;
          break;
        case 2: // Subtract
          result = firstNumber - secondNumber;  
          break;
        case 3: // Multiply
          result = firstNumber * secondNumber;
          break;
        case 4: // Divide
          result = division(firstNumber, secondNumber);
          break;
        case 5: // Modulus
          result = modulus(firstNumber, secondNumber);
          break;
        case 6: // Power
          result = pow(firstNumber, secondNumber);
          break;
    }
   
    if (!isnan(result)) {
        printf("The result is: %.2lf\n", result);
      }
    }
    return 0;
}

double division(double a, double b)
{
  if (b == 0) 
  {
    fprintf(stderr, "Invalid Argument for division by zero\n");
    return NAN;
  } else {
    return a / b;
  }
}

double modulus(int a, int b) 
{
    if (b == 0)
  {
    fprintf(stderr, "Invalid Argument for modulus by zero\n");
    return NAN;
  } else {
    return a % b;
  }
}

void print_menu()
{
    printf("\n\033[1;34m-----------------------------------\033[0m\n");
    printf("\033[1;32mWelcome to C Calculator!\033[0m\n");
    printf("\033[1;33mChoose one of the following operations:\033[0m\n");
    printf("\n\033[1;36m1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Modulus\n6. Power\n7. Exit\033[0m\n");
    printf("\033[1;35mPlease, enter your choice: \033[0m");
}

