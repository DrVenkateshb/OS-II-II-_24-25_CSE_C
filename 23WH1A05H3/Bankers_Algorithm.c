#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

int num_processes, num_resources;

void input_data() {
    int total_resources[MAX_RESOURCES];

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter total system resources: ");
    for (int i = 0; i < num_resources; i++) {
        scanf("%d", &total_resources[i]);
    }

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter maximum resource matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    for (int i = 0; i < num_resources; i++) {
        available[i] = total_resources[i];
    }

    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            available[j] -= allocation[i][j];
        }
    }
}

void display() {
    printf("\nProcess\tAllocation\tMax\tNeed\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < num_resources; j++) printf("%d ", allocation[i][j]);
        printf("\t");
        for (int j = 0; j < num_resources; j++) printf("%d ", max[i][j]);
        printf("\t");
        for (int j = 0; j < num_resources; j++) printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nAvailable Resources:\n");
    for (int i = 0; i < num_resources; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}

int is_safe() {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safe_sequence[MAX_PROCESSES];
    int count = 0;

    for (int i = 0; i < num_resources; i++) {
        work[i] = available[i];
    }

    while (count < num_processes) {
        int found = 0;
        for (int i = 0; i < num_processes; i++) {
            if (finish[i] == 0) {
                int can_allocate = 1;
                for (int j = 0; j < num_resources; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = 0;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < num_resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    safe_sequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nSystem is in an unsafe state! No safe sequence exists.\n");
            return 0;
        }
    }

    printf("\nSystem is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d", safe_sequence[i]);
        if (i != num_processes - 1) printf(" -> ");
    }
    printf("\n");

    return 1;
}

int main() {
    input_data();
    display();

    if (is_safe()) {
        printf("\nFinal Allocation State:\n");
        display();
    }

    return 0;
}
