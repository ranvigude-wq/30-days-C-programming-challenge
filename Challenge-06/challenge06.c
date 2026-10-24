
#include <stdio.h>

int main(void)
{
    int readings[12];
    int n, i, j, temp;
    int sum = 0, min, max;
    int secondLargest = 0, found = 0;
    int peaks = 0;
    int currentRun = 1, longestRun = 1;
    int k, r, d, divisibleCount = 0;

    /* Read array size */
    do
    {
        printf("Enter N (5-12): ");
        if (scanf("%d", &n) != 1)
            return 1;
    } while (n < 5 || n > 12);

    /* Read valid readings */
    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Enter reading %d (0-1000): ", i + 1);
            if (scanf("%d", &readings[i]) != 1)
                return 1;
        } while (readings[i] < 0 || readings[i] > 1000);
    }

    min = max = readings[0];

    /* Calculate statistics and detect patterns */
    for (i = 0; i < n; i++)
    {
        sum += readings[i];

        if (readings[i] < min)
            min = readings[i];

        if (readings[i] > max)
            max = readings[i];

        /* Longest increasing contiguous run */
        if (i > 0 && readings[i] > readings[i - 1])
        {
            currentRun++;

            if (currentRun > longestRun)
                longestRun = currentRun;
        }
        else if (i > 0)
        {
            currentRun = 1;
        }

        /* Count local peaks */
        if (i > 0 && i < n - 1 &&
            readings[i] > readings[i - 1] &&
            readings[i] > readings[i + 1])
        {
            peaks++;
        }
    }

    printf("\nOriginal array: ");
    for (i = 0; i < n; i++)
        printf("%d ", readings[i]);

    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", (double)sum / n);
    printf("\nMinimum = %d", min);
    printf("\nMaximum = %d", max);

    /* Find second-largest distinct value */
    for (i = 0; i < n; i++)
    {
        if (readings[i] < max &&
            (!found || readings[i] > secondLargest))
        {
            secondLargest = readings[i];
            found = 1;
        }
    }

    if (found)
        printf("\nSecond-largest distinct value = %d",
               secondLargest);
    else
        printf("\nNo second-largest distinct value exists.");

    printf("\nLocal peaks = %d", peaks);
    printf("\nLongest increasing run = %d", longestRun);

    /* Normalize K and rotate right in place */
    printf("\nEnter K: ");
    if (scanf("%d", &k) != 1)
        return 1;

    k = ((k % n) + n) % n;

    /* Reverse the whole array */
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        temp = readings[i];
        readings[i] = readings[j];
        readings[j] = temp;
    }

    /* Reverse the first K elements */
    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        temp = readings[i];
        readings[i] = readings[j];
        readings[j] = temp;
    }

    /* Reverse the remaining elements */
    for (i = k, j = n - 1; i < j; i++, j--)
    {
        temp = readings[i];
        readings[i] = readings[j];
        readings[j] = temp;
    }

    printf("Rotated array: ");
    for (i = 0; i < n; i++)
        printf("%d ", readings[i]);

    /* Personalised divisibility rule */
    printf("\nEnter R (last two registration digits): ");
    if (scanf("%d", &r) != 1 || r < 0 || r > 99)
        return 1;

    d = (r % 9) + 1;

    for (i = 0; i < n; i++)
    {
        if (readings[i] % d == 0)
            divisibleCount++;
    }

    printf("\nD = %d", d);
    printf("\nDivisible count = %d\n", divisibleCount);

    return 0;
}
