//1. Given an array of integers, write a program to find all duplicate elements in the array.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

//HashSet data structure as an array of key-occupied pairs
typedef struct {
    int key;
    bool occupied;
} HashSet[MAX];

// Initialize all elements of the HashSet as unoccupied
void initializeHashSet(HashSet hashSet) {
    for (int i = 0; i < MAX; ++i) {
        hashSet[i].occupied = false;
    }
}

// Function to insert a key into the HashSet
void insert(HashSet hashSet, int key) {
    hashSet[key].key = key; // Store the key at the corresponding index
    hashSet[key].occupied = true; // Mark the index as occupied
}

// Function to check if a key is present in the HashSet
bool contains(HashSet hashSet, int key) {
    return hashSet[key].occupied; // Return true if the index is occupied
}

// Function to remove duplicates from an array of integers
void findDuplicates(int arr[], int *size) {
    HashSet hashSet; // Declare a HashSet to store unique elements
    initializeHashSet(hashSet); // Initialize the HashSet

    int j = 0; // Initialize a counter for the new array without duplicates
    int duplicate_ele[*size/2]; //length is size/2 bec max duplicates elements can only be size/2
    int count = 0;
    // Iterate through the original array
    for (int i = 0; i < *size; ++i) {
        // If the current element is already present in the HashSet
        if (contains(hashSet, arr[i])){
            // Add the element to the duplicate_ele array
            duplicate_ele[count++] = arr[i];
            //printf("-%d-",arr[i]);
        }
            // Insert the element into the HashSet to mark it as not present
        else{
            insert(hashSet, arr[i]);
            //printf("+%d+",arr[i]);
        }
    }
    printf("\nduplicates elements: ");
    for(int i = 0; i< count; i++)
        printf(" %d, ", duplicate_ele[i]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 3, 6, 7, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    printf("Array before removing duplicates: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]); // Print the original array
    }

    findDuplicates(arr, &size); // Remove duplicates from the array

    return EXIT_SUCCESS;
}
