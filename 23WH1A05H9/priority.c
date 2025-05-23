#include <stdio.h>

int main() {
    int n, i, j, pos, temp;
    float awt = 0, tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int burst_time[n], process[n], priority[n], waiting_time[n], turnaround_time[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &priority[i]);
        process[i] = i + 1;
    }
    
    for (i = 0; i < n - 1; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (priority[j] < priority[pos])
                pos = j;
        }
        temp = priority[i];
        priority[i] = priority[pos];
        priority[pos] = temp;

        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;

        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }
    
    waiting_time[0] = 0;
  
    for (i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];
    }
    
    printf("\nProcesses    Burst Time    Waiting Time    Turn-Around Time\n");
    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        awt += waiting_time[i];
        tat += turnaround_time[i];
        printf("%d           %d             %d                %d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    
    printf("Average waiting time = %.2f\n", awt / n);
    printf("Average turn-around time = %.2f\n", tat / n);
    return 0;
}