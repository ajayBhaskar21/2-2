// SHORTEST SEEK TIME FIRST disk Scheduling Algorithm
#include <stdio.h>
#include<stdlib.h>

int sort (int a[], int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int show(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {    
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){

    int pages[] = {2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 3681};
    //int pages[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int size = sizeof(pages) / sizeof(pages[0]);

    
    sort(pages, size);
    show(pages, size);

    int headPosition = 2150;
    int totalSeek = 0;
    int l = 0;
    int r = size - 1;

    while (pages[l] < headPosition){
        l++;
    }
    while(headPosition < pages[r]){
        r--;
    }
    
    l--;
    r++;
    printf("Seek Sequence: \n");
    while (l >= 0 || r < size){
        if (l < 0){
            // only execute right.

            totalSeek += abs(headPosition - pages[r]);
            headPosition = pages[r];
            printf("%d\n", headPosition);
            r++;

        }

        else if (r > size - 1){
            // only left.
            totalSeek += abs(headPosition - pages[l]);
            headPosition = pages[l];
            printf("%d\n", headPosition);
            l--;
        }
        else{
            int a = abs(headPosition - pages[l]);
            int b = abs(headPosition - pages[r]);
            if (a <= b)
            {
                totalSeek += a;
                headPosition = pages[l];
                printf("%d\n", headPosition);
                l--;
            }
            else
            {
                totalSeek += b;
                headPosition = pages[r];
                printf("%d\n", headPosition);
                r++;
            }
        }

    }

    printf("Total number of seek operations = %d\n", totalSeek);
}
