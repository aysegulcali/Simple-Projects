#include <stdio.h>

const int N = 3;

float average(int length, int array[]);

int main(void)
{
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        printf("Score: ");
        // Receive integer input from the user
        if (scanf("%d", &scores[i]) != 1)
        {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            // Error status
            return 1;
        }
    }

    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum / (float) length;
}
