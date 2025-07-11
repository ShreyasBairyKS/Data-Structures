#include <stdio.h>
int count = 0; // Global variable to count steps

// Function to solve Tower of Hanoi
void toh(int n, char source, char target, char aux) {
    if (n == 1) {
        printf("Move disk from %c to %c\n", source, target);
        count++;
        return;
    }
    toh(n - 1, source, aux, target);
    printf("Move disk from %c to %c\n", source, target);
    count++;
    toh(n - 1, aux, target, source);
}

// Function to find the maximum element in an array
int findmax(int a[], int start, int end) {
    if (end == start) {
        return a[start];
    }
    int mid = (start + end) / 2;
    int x = findmax(a, start, mid);
    int y = findmax(a, mid + 1, end);
    return (x >= y) ? x : y; // Return the maximum of the two
}

int main() {
    int n;

    // Tower of Hanoi
    printf("Enter the number of disks for Tower of Hanoi: ");
    scanf("%d", &n);
    printf("Tower of Hanoi Moves:\n");
    toh(n, 'A', 'B', 'C'); // Use uppercase for clarity
    printf("Total steps: %d\n", count);

    // Find maximum in an array
    int a[5] = {1, 2, 6, 9, 5};
    int start = 0;
    int end = 4;
    int max_value = findmax(a, start, end);
    printf("The maximum value in the array is: %d\n", max_value);

    return 0;
}
