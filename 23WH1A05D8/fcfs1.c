#include <stdio.h>
void tur(int n,int ct[n],int at[n],int tt[n]);
// Function to swap processes based on their arrival time
void swap(int n, int p[n], int at[n], int bt[n]);

// Function to calculate completion times based on burst times
void com(int n, int bt[n], int ct[n]);

void wai(int n,int tt[n],int bt[n],int wt[n]);

int main() {
    int n, i, k;

    // Input the number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], ct[n],tt[n],wt[n];  // Arrays for process ID, arrival time, burst time, and completion time

    // Initialize process IDs
    for(i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    // Input the arrival times
    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    // Input the burst times
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Sort processes based on arrival times
    swap(n, p, at, bt);

    // Calculate completion times
    com(n, bt, ct);
    
    tur(n,ct,at,tt);

    wai(n,tt,bt,wt);
    // Output the details (Process ID, Arrival Time, Burst Time, Completion Time)
    int sum,add;
    printf("\nPID\t\tAT\t\tBT\t\tCT\t\ttt\t\twt\n");
    for(k = 0; k < n; k++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[k], at[k], bt[k], ct[k],tt[k],wt[k]);
    
    
        sum = sum +  tt[k];
        add = add + wt[k];
    
    }
         int avg = sum /n;
         int avg1 = add/n;
         printf("Average turn around time is : %d\n",avg);
         printf("Average waiting time is : %d",avg1);
       
       return 0;
}

// Function to swap processes based on arrival time (sorting)
void swap(int n, int p[n], int at[n], int bt[n]) {
    int j, k, temp;
    for(j = 0; j < n - 1; j++) {
        for(k = j + 1; k < n; k++) {
            if(at[j] > at[k]) {
                // Swap arrival times
                temp = at[j];
                at[j] = at[k];
                at[k] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[k];
                bt[k] = temp;

                // Swap process IDs
                temp = p[j];
                p[j] = p[k];
                p[k] = temp;
            }
        }
    }
}

// Function to calculate completion times
void com(int n, int bt[n], int ct[n]) {
    int sum = 0, i;

    for(i = 0; i < n; i++) {
        sum += bt[i];  // Accumulate burst times to get completion times
        ct[i] = sum;   // Set the completion time for process i
    }
}

void tur(int n,int ct[n],int at[n],int tt[n])
{
    int sub = 0,i;
    
    for(i=0;i<n;i++)
    {
        sub = ct[i] -at[i];
        tt[i] = sub;
        }
}

void wai(int n,int tt[n],int bt[n],int wt[n])
{
    int su = 0,i;
    
    for(i=0;i<n;i++){
        su = tt[i] - bt[i];
        wt[i] = su;
    }
}

