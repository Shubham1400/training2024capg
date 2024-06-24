#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 256 // Assuming ASCII characters

// Define a HashSet data structure as a struct with a key and occupied flag
typedef struct {
    char key;
    bool occupied;
} HashSet;

// Function to initialize all elements of the HashSet as unoccupied
void initializeHashSet(HashSet hashSet[]) {
    for (int i = 0; i < MAX; ++i) {
        hashSet[i].occupied = false;
    }
}

// Function to insert a key into the HashSet
void insert(HashSet hashSet[], char key) {
    int index = (int)key; // Convert char to integer index
    hashSet[index].key = key; // Store the key at the corresponding index
    hashSet[index].occupied = true; // Mark the index as occupied
}

// Function to check if a key is present in the HashSet
bool contains(HashSet hashSet[], char key) {
    int index = (int)key; // Convert char to integer index
    return hashSet[index].occupied; // Return true if the index is occupied
}

// Function to check if two strings are the same
bool findsame(char* s, int l1, char* st, int l2) {
    
    if(l1 != l2) // if length is different then strings are different
        return false;
    HashSet hashSet[MAX]; // Declare an array of HashSet to store unique elements
    initializeHashSet(hashSet); // Initialize the HashSet
    
    for(int i = 0; i < l1; i++){
        insert(hashSet, s[i]);
    }
    
    for(int i = 0; i < l2; i++){
        if(!contains(hashSet, st[i]))
            return false;
    }
    return true;
}

int main() {
    char s[] = "ear"; // Use array of characters for strings
    char st[] = "are";

    bool r = findsame(s, strlen(s), st, strlen(st));
    
    if(r)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
