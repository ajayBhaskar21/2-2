// Creating thread in c

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *kill(void *arg)                     // this function is run by the thread and takes only void pointer arguments
{
    int n = *((int *)arg);                // To set the thread number
    printf("t%d started..\n", n);
    
    while (1)
    {
        printf("t%d running..\n", n);
        sleep(1);
    }
}

int main()
{
    
    pthread_t t1;                         // Declaring thread variables
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    
    printf("Main started..\n");
    
    int n = 1;
    printf("press enter to kill t%d Thread and start t%d Thread...\n", n, n + 1);
    pthread_create(&t1, NULL, &kill, (void *)&n);                                         // Function to create a Thread and run the function.
    getchar();                                                                            // waits for the user to press 'Enter'
    pthread_cancel(t1);                                                                   // if Enter is pressed then the running Thread is killed.
    pthread_join(t1, NULL);                                                               // main Thread waits until the killed Thread execution is completed.
    printf("t%d Thread stopped\n", n);
    
    
    
    n = 2;
    printf("press enter to kill t%d Thread and start t%d Thread...\n", n, n + 1);
    pthread_create(&t2, NULL, &kill, (void *)&n);
    getchar();
    pthread_cancel(t2);
    pthread_join(t2, NULL);
    printf("t%d Thread stopped\n", n);
    
   
    
    n = 3;
    printf("press enter to kill t%d Thread and start t%d Thread...\n", n, n + 1);
    pthread_create(&t3, NULL, &kill, (void *)&n);
    getchar();
    pthread_cancel(t3);
    pthread_join(t3, NULL);
    printf("t%d Thread stopped\n", n);
    
    
    
    n = 4;
    pthread_create(&t4, NULL, &kill, (void *)&n);
    pthread_join(t4, NULL);                            // Last Thread should be running for infinite times..
    
    
    
    
}
