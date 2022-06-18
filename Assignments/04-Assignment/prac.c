#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *myturn()
{
    while (1)
    {
        sleep(1);
        printf("My Turn\n");
    }
}

void *yourturn()
{
    while (1)
    {
        sleep(2);
        printf("Your Turn\n");
    }
}

int main()
{
    pthread_t newthread;

    pthread_create(&newthread, NULL, myturn, NULL);
    // myturn();
    yourturn();
    // To complete our thread to complete it's execution we use the function call pthread_join
    /* What if the one operation take longer than the other if my new thread takes longer to run then the other function
    But when the nicha wla function complete it's execution the main exits and we all know when main exists the
    program closes so we are going to use the pthread_join so that our thread will complete the function
    instead that the yourturn function complete the execution and then our program exits */
    /* pthread_join waits until specific thread running completed and then it continue the execution */
    pthread_join(newthread, NULL);
    return 1;
}