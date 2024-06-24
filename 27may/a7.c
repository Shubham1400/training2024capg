// 7. Write a program to rotate an array of n elements to the right by k steps.

#include <stdio.h>
#include <stdlib.h>

// Function to reverse the array from index 'start' to 'end'
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate the array to the right by 'k' steps
void rotate(int arr[], int n, int k) {
    k = k % n; // To handle cases where k > n

    // Reverse the last 'k' elements
    reverse(arr, n - k, n - 1);

    // Reverse the first 'n-k' elements
    reverse(arr, 0, n - k - 1);

    // Reverse the entire array
    reverse(arr, 0, n - 1);
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Original array: ");
    printArray(arr, n);

    rotate(arr, n, k);

    printf("Rotated array: ");
    printArray(arr, n);

    return EXIT_SUCCESS;
}
