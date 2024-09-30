#include <stdio.h>
#include <conio.h>
#include "func.h"
int main()
{
    char q = ' ';
    int k = 0;
    double x = 0, y = 0, epsilon = 0;

    do {
        printf("This program calculates root with k value and x expression\n");
        k = val_int_input("Please enter root int value k (if you enter float only int part would be taken):\n");
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
        printf("The root with k value and x expression is %.10f (with accuracy = %e)\n", y, epsilon);
        printf("\nPress [Q] to quit, any other key to continue...\n");
        q = getch();

    }
    while (q != 'q' && q != 'Q');
    return 0;
}
