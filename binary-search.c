#include <stdio.h>

// Binary search function
void binary_search(int array[], int size, int searched)
{
    int i, first, last, middle;
    first = 0;
    last = size - 1;
    middle = (first + last) / 2;

    while (first <= last)
    {
        if(searched < array[middle])
        {
            printf("First: %d. element, middle: %d. element, last: %d. element\n", first+1, middle+1, last+1);
            first = middle + 1;
            break;
        }
        else if (searched == array[middle])
        {
            printf("Number %d is at position %d of the array.\n", searched, middle+1);
        }
        else
        {
            last = middle - 1;

            middle = (first + last) / 2;
        }
    }
    if(first > last)
    {
        printf("The number %d was not found in the array.\n", searched);
    }
}

int main()
{
    int searched1 = 14, searched2 = 6, searched3 = 5;
    int array[] = { 25, 20, 14, 12, 9, 6, 2 };

    // Detect the number of elements of an array
    int size = sizeof(array) / sizeof(int);

    printf("First search process:\n");
    binary_search(array, size, searched1);
    printf("Second search process:\n");
    binary_search(array, size, searched2);
    printf("Third search process:\n");
    binary_search(array, size, searched3);

    return 0;
}
