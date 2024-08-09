#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks;

    // Get the number of weeks from the user
    printf("How many weeks have you been studying?: ");
    if (scanf("%d", &weeks) != 1 || weeks <= 0)
    {
        fprintf(stderr, "Invalid input for number of weeks.\n");
        return 1;
    }

    int hours[weeks];

    // Receive hours from the user for each week
    for (int i = 0; i < weeks; i++)
    {
        printf("Week %d HW Hours: ", i + 1);
        if (scanf("%d", &hours[i]) != 1 || hours[i] < 0)
        {
            fprintf(stderr, "Invalid input for hours.\n");
            return 1;
        }
    }

    char output;
    do
    {
        printf("Enter T for total hours, A for average hours per week: ");
        if (scanf(" %c", &output) != 1 || (output != 'T' && output != 'A'))
        {
            fprintf(stderr, "Invalid input for output type.\n");
            return 1;
        }
        output = toupper(output);
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));

    return 0;
}

// complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    int total_hours = 0;

    // Calculate total hours
    for (int i = 0; i < weeks; i++)
    {
        total_hours += hours[i];
    }

    if (output == 'T')
    {
        // Return total hours
        return (float)total_hours;
    }
    else if (output == 'A')
    {
        // Return average hours
        return (float)total_hours / weeks;
    }

    return 0.0;
}
