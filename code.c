#include <stdio.h>

// Creating prototypes for used functions
void print_Report(float loanAmount, float interest, int loanYears, int loanMonths, int repetition);
void print_Block(float loanAmount, float interest, int months);
void print_Duration(int months);
void print_Amount(float amount);

int main()
{
  int loanMonths, loanYears, repetition;
  float loanAmount, interest;
  char name[30];

  printf(".............................................................");
  printf("\n.*.*.*.*.*Welcome to Loan Interest Calculation Tool*.*.*.*.*.");
  printf("\n.............................................................");

  printf("\n\nPlease Enter Your Name:");

  // Reads the entire line using '^\n%99[] format specifier' that allows taking the input with spaces
  scanf("%99[^\n]", &name);

  printf("\nLoan Amount:");
  scanf("%f", &loanAmount);

  printf("\nInterest Rate:");
  scanf("%f", &interest);

  printf("\n-> DURATION\n");

  printf("   Loan term in years:");
  scanf("%d", &loanYears);

  printf("   Loan term in months:");
  scanf("%d", &loanMonths);

  printf("   Repetition in months:");
  scanf("%d", &repetition);

  printf(".............................................................\n");

  printf("\nRepayment chart for %s:\n", name);

  // Calls the report printing function
  print_Report(loanAmount, interest, loanYears, loanMonths, repetition);

  // Clears the input buffer for 'scanf' by flushing the memory
  fflush(stdin);

  printf("\nPress Enter to exit...\n");

  // Prevents terminal from closing automatically
  getchar();
  return 0;
}

// Main function for generating the report
void print_Report(float loanAmount, float interest, int loanYears, int loanMonths, int repetition)
{
  // Calculates the total number of months by multiplying years by twelve and adding months
  int totalMonths = loanYears * 12 + loanMonths;

  printf("\n------------------------");

  // Calculates the number of report blocks in the report
  for (int month = repetition; month <= totalMonths; month += repetition)
  {
    // Calls the function to print each report block
    print_Block(loanAmount, interest, month);
    printf("\n------------------------");
  }
}

// Function to print a report block
void print_Block(float loanAmount, float interest, int months)
{
  // Calculates the total amount including interest
  float amount = loanAmount + loanAmount / 100 * interest / 12 * months;

  // Prints the Year and Month for the report block
  print_Duration(months);

  printf("\nTotal Payment:\n");
  // Calls the function to print the amount
  print_Amount(amount);

  printf("\nMonthly Payment:\n");
  // Calls the function to print the amount divided by months to get monthly payment
  print_Amount(amount / months);
}

// Function to print the duration of the report block
void print_Duration(int months)
{
  // Converts 'months' to 'years and months'
  printf("\n-> Year:%d, Month:%d", months / 12, months % 12);
}

// Function to print the formatted amount
void print_Amount(float amount)
{
  /* %.1f rounds the number either up or down as needed.
  To prevent this, multiply the number by 10, shift one decimal place to the left,
  then use type casting to take out the decimal part.
  Finally, the number divides by 10.0 to shift one decimal place back and convert to a floating point. */
  float rounded = (int)(amount * 10) / 10.0;
  printf("%.1f $", rounded);
}
