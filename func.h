
#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <math.h>
void clean_input()
{
    char ch = ' ';

    while ((ch = getchar()) != '\n');
}
double calculate_root(double root_exp, int root_value, double accuracy)
{
    double y = 1.0;  // Початкове значення y
    double delta = 1.0;  // Початкове значення delta
    int i = 0;

    // Ітераційний процес
    do
        {
        delta = (1.0 / root_value) * ((root_exp / pow(y, root_value - 1)) - y);
        y = y + delta;
        i++;
        printf("iteration:%d, delta=%lf, y=%lf\n", i, delta, y);
        }
    while (fabs(delta) >= accuracy);

    return y;
}

// Функція для валідації введених даних (тільки числа)

int val_int_input(const char *prompt)
{
    int value = 0;
    int input = 0;
    do
        {
        printf("%s", prompt);
        input = scanf("%d", &value);
        if (input != 1 || value == 0)
            {
            printf("Invalid input. Please enter a valid integer.\n");
            value = 0;
            fflush(stdin);
            }
        }
    while (input != 1 || value == 0);
    return value;
}

double val_double_input(const char *prompt)
{
    double value = 0 ;
    int input = 0;
    do
        {
        printf("%s", prompt);
        input = scanf("%lf", &value);
        if (input != 1)
            {
            printf("Invalid input. Please enter a valid number.\n");
            value = 0;
            clean_input();// Очищаємо буфер вводу
            }
        }
    while (input != 1);
    return value;
}

// Функція для вибору точності
double set_accuracy()
{
    int choice = 0;
    double accuracy = 0;

    do
        {
        printf("Choose the accuracy type:\n");
        printf("1. Number of decimal places (e.g., 3)\n");
        printf("2. Decimal number (e.g., 0.001)\n");
        printf("3. Exponential form (e.g., 1E-3)\n");
        printf("Enter your choice (1-3): ");
        choice = val_int_input("");

        switch (choice)
            {
                case 1:
                {
                    int decimal_places = val_int_input("Enter the number of decimal places: ");
                    accuracy = pow(10, decimal_places);  // Вираховуємо точність з кількості знаків
                }
                case 2:
                {
                    accuracy = val_double_input("Enter the decimal number (e.g., 0.001): ");
                }
                case 3:
                {
                    accuracy = val_double_input("Enter the accuracy in exponential form (e.g., 1E-3): ");
                }
                default:
                {
                    printf("Invalid choice. Please try again.\n");
                    clean_input();
                }

            }
        }
    while (choice < 1 || choice > 3);

    return accuracy;
}
#endif FUNC_H
