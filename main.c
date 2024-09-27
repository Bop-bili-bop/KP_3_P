#include <stdio.h>
#include "func.h"
int main()
{
    char q = ' ';
    int k = 0;
    double x = 0, y = 0, epsilon = 0;

    printf("This program calculates root with k value and x expression\n");
    k = val_int_input("Please enter root int value k (if you enter float only int part would be taken):");

    x = val_double_input("Please enter root expression (x):");
    epsilon = set_accuracy("Please enter root expression (epsilon):");
    y = calculate_root(x, k, epsilon);
    printf("The root with k value and x expression is %.10f (with accuracy = %e)\n", y, epsilon);
    return 0;
}
