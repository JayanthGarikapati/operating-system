#include<stdio.h>

int main()
{
    int n=4, i, j, temp, total=0;
    float waiting_time=0, turnaround_time=0;

    int burst_time[4] = {6, 8, 7, 3};
    int process[4] = {1, 2, 3, 4};

    // sorting the processes based on their burst time
    for(i=0; i<n; i++) {
        for(j=0; j<n-i-1; j++) {
            if(burst_time[j] > burst_time[j+1]) {
                temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;

                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }

    // calculating waiting time and turnaround time for each process
    int completion_time[4] = {0};
    for(i=0; i<n; i++) {
        completion_time[i] = burst_time[i] + completion_time[i-1];
        waiting_time += completion_time[i-1];
        turnaround_time += completion_time[i];

    }

    // calculating total waiting time and total turnaround time
    for(i=0; i<n; i++) {
        total += burst_time[i];
    }
    waiting_time = waiting_time / n;
    turnaround_time = turnaround_time / n;

    // printing the results
    printf("Process\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], completion_time[i], completion_time[i]-burst_time[i], completion_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", waiting_time);
    printf("Average Turnaround Time: %.2f\n", turnaround_time);

    return 0;
}
