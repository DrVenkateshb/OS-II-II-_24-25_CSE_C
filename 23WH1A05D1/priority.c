#include <stdio.h>

void priorityScheduling(int n) {
    int burst_time[n], priority[n], arrival_time[n];
    int waiting_time[n], turnaround_time[n], completion_time[n];
    int i, j;

    // Input
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter Priority for P%d (lower is higher): ", i + 1);
        scanf("%d", &priority[i]);
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    // Sort based on arrival time, then priority (Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arrival_time[j] > arrival_time[j + 1] ||
                (arrival_time[j] == arrival_time[j + 1] && priority[j] > priority[j + 1])) {
                // Swap everything associated with the processes
                int temp;

                temp = burst_time[j]; burst_time[j] = burst_time[j + 1]; burst_time[j + 1] = temp;
                temp = priority[j]; priority[j] = priority[j + 1]; priority[j + 1] = temp;
                temp = arrival_time[j]; arrival_time[j] = arrival_time[j + 1]; arrival_time[j + 1] = temp;
            }
        }
    }

    // Calculation
    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < arrival_time[i]) {
            current_time = arrival_time[i];
        }
        waiting_time[i] = current_time - arrival_time[i];
        completion_time[i] = current_time + burst_time[i];
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        current_time = completion_time[i]; // Update current time
    }

    // Output
    printf("\nProcess\tArrival\tBurst\tPriority\tWaiting\tTurnaround\tCompletion\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i], completion_time[i]);
    }

    // Average Calculation and Output
    float avg_waiting = 0, avg_turnaround = 0;
    for (i = 0; i < n; i++) {
        avg_waiting += waiting_time[i];
        avg_turnaround += turnaround_time[i];
    }
    avg_waiting /= n;
    avg_turnaround /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}

int main() {
    int num_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    priorityScheduling(num_processes); // Call function with number of processes

    return 0;
}
