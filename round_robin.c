#include <stdio.h>

int main()
{
    int n, i, tq, time = 0, done;
    int bt[20], rem[20], wt[20], tat[20];

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rem[i] = bt[i];
        wt[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    do
    {
        done = 1;

        for(i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                done = 0;

                if(rem[i] > tq)
                {
                    time = time + tq;
                    rem[i] = rem[i] - tq;
                }
                else
                {
                    time = time + rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }

    } while(done == 0);

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
