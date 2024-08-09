#include <stdio.h>

int main(void)
{
    int int_array[5] = {0};
    int *demonstrator_int = int_array;

    printf("Size of integer int_array = %lu bytes.\n", sizeof(int_array));
    printf("Each element of int_array is %lu bytes long.\n", sizeof(int_array[0]));
    printf("Size of demonstrator demonstrator_int = %lu bytes.\n\n", sizeof(demonstrator_int));

    double double_array[5] = {0};
    double *demonstrator_double = double_array;

    printf("Size of double double_array = %lu byte. \n", sizeof(double_array));
    printf("Each element of double_array is %lu bytes long.\n", sizeof(double_array[0]));
    printf("Size of demonstrator demonstrator_double = %lu bytes.\n", sizeof(demonstrator_double));

    return 0;
}
