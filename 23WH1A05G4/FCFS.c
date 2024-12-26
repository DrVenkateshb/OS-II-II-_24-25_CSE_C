#include<stdio.h>

//sort processes based on burst time
void sortProcesses(int p[], int n, int b[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                // Swap burst times
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;

                // Swap process IDs
                int tempP = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempP;
            }
        }
    }
}

void waitingtime(int p[], int n, int b[], int w[]) {
    w[0] = 0;
    for (int i = 1; i < n; i++) {
        w[i] = b[i - 1] + w[i - 1];
    }
}

void turnaroundtime(int p[], int n, int tat[], int b[], int w[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = b[i] + w[i];
    }
}

void findavg(int p[], int n, int b[]) {
    int w[n], tat[n], total_wt = 0, total_tat = 0;

    // Sort processes by burst time
    sortProcesses(p, n, b);

    waitingtime(p, n, b, w);
    turnaroundtime(p, n, tat, b, w);

    printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt += w[i];
        total_tat += tat[i];

        printf(" %d\t\t%d\t\t%d\t\t%d\n", p[i], b[i], w[i], tat[i]);
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage waiting time : %.2f", avg_wt);
    printf("\nAverage turnaround time : %.2f\n", avg_tat);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int p[n], b[n];

    // Input process IDs and burst times
    for (int i = 0; i < n; i++) {
        p[i] = i + 1; // Process IDs start from 1
        printf("Enter burst time for process %d: ", p[i]);
        scanf("%d", &b[i]);
    }

    findavg(p, n, b);

    return 0;
}