
// FCFS Disk Scheduling Algorithm
#include <stdio.h>
#include <stdlib.h>

void main(){
    

    int pages[] = {2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 3681};

    int size = sizeof(pages) / sizeof(pages[0]);

    
    // To print Seek sequence and total seek operations
    int headPosition = 2150;

    int totalSeek = 0;
    printf("Seek Sequence : \n");
    for (int i = 0; i < size; i++){
        printf("%d\n", pages[i]);
        totalSeek += abs(pages[i] - headPosition);
        headPosition = pages[i];
    }
    printf("Total number of seek operations = %d\n", totalSeek);
}