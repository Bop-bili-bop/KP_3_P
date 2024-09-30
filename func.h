
#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
void clean_input()
{
    char ch = ' ';
    while (ch != '\n')
        {
        ch = getchar();
        }
}
double calculate_root(double root_exp, int root_value, double accuracy)
{
    double y = 1.0;
    double delta = 1.0;
    int i = 0;
    // Цикл ітерацій
    do
        {
        if (root_value < 0)
            {
            root_value = -root_value;
            root_exp = 1.0 / root_exp;
            delta = (1.0 / root_value) * (root_exp / pow(y,root_value - 1) - y);
            y = y + delta;
            i++;
            }
        else
            {
            delta = (1.0 / root_value) * (root_exp / pow(y, root_value - 1) - y);
            y = y + delta;
            i++;
            }
        }
    while (fabs(delta) >= accuracy);

    return y;
}

int val_unsigned_input(const char *prompt)
{
    unsigned value = 0;
    int input = 0;
    do
    {
        printf("%s", prompt);
        input = scanf("%u", &value);
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

double validate_input(const char* prompt, const char* error_msg, int (*condition)(double))
{
    double value = 0;
    do {
        value = val_double_input(prompt);
        if (!condition(value))
        {
            printf("%s\n", error_msg);
            clean_input();
        }
    }
    while (!condition(value));
    return value;
}

//condition funcs
bool greater_than_zero(double value)
{
    return value > 0;
}

bool not_zero(double value)
{
    return value != 0;
}

bool non_negative(double value)
{
    return value >= 0;
}
bool any_number(double value)
{
    return 1;
}

//root expression validation (depends from root value)
double rootexp_val(int var)
{
    switch (var)
    {
        case 1:
            return validate_input("Please enter root expression x (x > 0):\n", "Invalid input. Please enter a valid number.", greater_than_zero);
        case 2:
            return validate_input("Please enter root expression x (x != 0):\n", "Invalid input. Please enter a valid number.", not_zero);
        case 3:
            return validate_input("Please enter root expression x (x >= 0):\n", "Invalid input. Please enter a valid number.", non_negative);
        default:
            return validate_input("Please enter root expression x:\n", "Invalid input. Please enter a valid number.", any_number);
    }
}
// Функція для вибору точності
double set_accuracy()
{
    unsigned choice = 0;
    double accuracy = 0;

    do
        {
        printf("Choose the accuracy type:\n");
        printf("1. Number of decimal places (e.g., 3)\n");
        printf("2. Decimal number (e.g., 0.001)\n");
        printf("3. Exponential form (e.g., 1E-3)\n");
        printf("Enter your choice (1-3): ");
        choice = val_unsigned_input("");

        switch (choice)
            {
                case 1:
                {
                    unsigned decimal_places = val_unsigned_input("Enter the number of decimal places:\n");
                    accuracy = pow(10, -decimal_places);  // Вираховуємо точність з кількості знаків
                    break;
                }
                case 2:
                {
                    accuracy = val_double_input("Enter the decimal number (e.g., 0.001):\n");
                    break;
                }
                case 3:
                {
                    accuracy = val_double_input("Enter the accuracy in exponential form (e.g., 1E-3):\n");
                    break;
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
