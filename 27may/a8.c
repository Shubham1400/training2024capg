//8. Write a program to find all common elements in two given arrays.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

typedef struct{
    int key;
    bool occupied;
}HashSet[MAX];

void initializeHS(HashSet hs){
    for(int i = 0; i< MAX; i++)
        hs[i].occupied = false;
}

void insert(HashSet hs, int key){
    hs[key].key = key;
    hs[key].occupied = true;
}

bool contains(HashSet hs, int key){
    return hs[key].occupied;
}

void findCommon(int* a, int* a2, int l, int l2){
    HashSet hs;
    initializeHS(hs);
    //printf("%d..length l\n", l);
    for(int i = 0;i<l; i++){
        //printf("[%d]",a[i]);
        insert(hs, a[i]);
    }
    
    /*for(int i = 0;i<l+1; i++){
        printf("%d.", hs[i].key);
    }*/
    
    int count = 1;
    int *p = (int*)malloc(sizeof(int));
    for(int i = 0;i<l2; i++){
        if(contains(hs, a2[i])){
            p = (int*)realloc(p,(count)*sizeof(int));
            p[count++] = a2[i];
        }
    }
    
    printf("common elements- ");
    for(int i=1; i<count;i++){
        printf("%d, ",p[i]);
    }
    free(p);
}

int main() {
    int a[] = {1,2,3,4,6};
    int a2[] = {3,4,6,1};
    findCommon(a,a2,(sizeof(a)/sizeof(int)),(sizeof(a2)/sizeof(int)) );
    return EXIT_SUCCESS;
}
