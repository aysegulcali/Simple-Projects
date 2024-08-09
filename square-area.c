#include <stdio.h>

int main()
{
    int square;
    int area;

    printf("Side length of a square = ");
    scanf("%d", &square);

    area = square * square;
    printf("Area of the square = %d\n", area);

    return 0;
}
