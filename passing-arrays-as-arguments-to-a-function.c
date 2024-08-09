#include <stdio.h>

// Function that takes the array and prints the elements to the screen
void writeArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int myArray[] = {1, 2, 3, 4, 5};

    // Passing array as argument to function
    writeArray(myArray, 5);

    return 0;
}
