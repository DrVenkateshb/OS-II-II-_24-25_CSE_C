#include <stdio.h>

int main() {
    int p, r, count = 0, i, j;

    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &r);

    // Declare arrays after getting p and r (Using Variable Length Arrays - VLAs)
    int alc[p][r], max[p][r], need[p][r], safe[p], available[r], done[p], total[r];

    printf("Enter allocation of resources for all processes (%dx%d matrix):\n", p, r);
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alc[i][j]);
        }
    }

    printf("Enter the maximum resources required by each process (%dx%d matrix):\n", p, r);
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the total number of instances for each resource: ");
    for (i = 0; i < r; i++) {
        scanf("%d", &total[i]);
    }

    // Calculate available resources
    for (i = 0; i < r; i++) {
        available[i] = total[i];
        for (j = 0; j < p; j++) {
            available[i] -= alc[j][i];
        }
    }

    printf("\nNeed resources matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < p; i++) {
        done[i] = 0;
    }

    count = 0;
    while (count < p) {
        int found = 0;
        for (i = 0; i < p; i++) {
            if (!done[i]) {
                for (j = 0; j < r; j++) {
                    if (need[i][j] > available[j])
                        break;
                }
                if (j == r) {
                    safe[count++] = i;
                    done[i] = 1;
                    for (j = 0; j < r; j++) {
                        available[j] += alc[i][j];
                    }
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nSafe sequence does not exist!\n");
            return 1;
        }
    }

    printf("\nAvailable resources after completion:\n");
    for (i = 0; i < r; i++) {
        printf("%d\t", available[i]);
    }
    printf("\nSystem in a safe state.\nSafe sequence:\n");
    for (i = 0; i < p; i++) {
        printf("P%d\t", safe[i]);
    }
    printf("\n");

    return 0;
}
