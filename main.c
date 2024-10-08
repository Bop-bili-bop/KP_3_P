#include <stdio.h>
#include <conio.h>
#include "func.h"
int main()
{
    int k = 0, n = 0;
    double x = 0, y = 0, epsilon = 0;

    do {
        printf("This program calculates root with k value and x expression\n");
        k = val_double_input("Please enter root int value k (if you enter float only int part would be taken):\n");
        if (k < 0)
        {
            if (k % 2 == 0)
            {
                x = rootexp_val(1);
            }
            else
            {
                x = rootexp_val(2);
            }
        }
        else
        {
            if (k % 2 == 0)
            {
                x = rootexp_val(3);
            }
            else
            {
                x = val_double_input("Please enter root expression x:\n");
            }
        }
        epsilon = set_accuracy();
        y = calculate_root(x, k, epsilon);
        n = fabs(log10(epsilon));
        printf("The root with k value and x expression is %e (with accuracy = %e)\n", y, epsilon);
        printf("The root with k value and x expression is %.*lf (with accuracy = %e)\n", n, y, epsilon);
        printf("\nPress [0] to quit, any other key to continue...\n");
        fflush(stdin);
    }
    while (getchar() != 48);
    return 0;
}
