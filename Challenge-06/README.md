# Algorithm – Pattern Detective

1. **Start** the program.

2. Read the number of readings, `N`. If `N` is less than 5 or greater than 12, ask again until a valid value is entered.

3. Read `N` integer readings into a one-dimensional array. If any reading is less than 0 or greater than 1000, ask for that reading again.

4. Display the original array.

5. Initialize the sum to zero and set the minimum and maximum to the first array element.

6. Traverse the array to calculate the sum, minimum, and maximum. Calculate the average by dividing the sum by `N`.

7. Find the second-largest distinct value by examining elements smaller than the maximum and selecting the largest among them. If no such value exists, display a suitable message.

8. Count local peaks by checking each interior element. An element is a local peak if it is strictly greater than both its immediate neighbours.

9. Find the longest strictly increasing contiguous run by tracking the current run length and updating the longest length whenever a longer run is found. Initialize both lengths to 1.

10. Read the integer `K` and normalize it using:
    `K = ((K % N) + N) % N`

11. Rotate the array right in place without using another array:
    - Reverse the entire array.
    - Reverse the first `K` elements.
    - Reverse the remaining elements.

12. Display the rotated array.

13. Read the last two numeric digits of the registration number as `R`.

14. Calculate the personalised divisor:
    `D = (R % 9) + 1`

15. Count how many elements in the rotated array are exactly divisible by `D`.

16. Display `D` and the divisibility count.

17. **Stop** the program.
