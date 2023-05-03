// Circular SCAN Disk Scheduling Algorithm
#include <stdio.h>
#include <stdlib.h>

int sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
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

int main()
{
    int pages[] = {2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 3681};
    //int pages[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int size = sizeof(pages) / sizeof(pages[0]);

    sort(pages, size);
    show(pages, size);
    int first = 0;
    int last = 4999;

    int headPosition = 2150;
    int totalSeek = 0;
    int l = 0;
    int r = size - 1;

    while (pages[l] < headPosition)
    {
        l++;
    }
    while (headPosition < pages[r])
    {
        r--;
    }

    r++;

    // right direction
    printf("Seek Sequence: \n");
    while (r < size)
    {
        totalSeek += abs(headPosition - pages[r]);
        headPosition = pages[r];
        printf("%d\n", headPosition);
        r++;
    }

    
    int i = 0;
    while (i < l)
    {

        totalSeek += abs(headPosition - pages[i]);
        headPosition = pages[i];
        printf("%d\n", headPosition);
        i++;
    }
    
    printf("Total number of seek operations = %d\n", totalSeek);
}