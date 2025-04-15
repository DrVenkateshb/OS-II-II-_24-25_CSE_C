#include <stdio.h>
#include <stdbool.h>

void FCFS(int pages[], int n, int capacity) {
    int queue[capacity];
    int front = 0, count = 0, page_faults = 0, hits = 0;
    bool in_memory[100] = {false}; // Track if a page is in memory

    for (int i = 0; i < n; i++) {
        if (in_memory[pages[i]]) {
            // Page hit
            hits++;
        } else {
            // Page fault
            if (count < capacity) {
                queue[count++] = pages[i];
            } else {
                // Remove the oldest page from memory
                in_memory[queue[front]] = false;
                queue[front] = pages[i];
                front = (front + 1) % capacity;
            }
            in_memory[pages[i]] = true;
            page_faults++;
        }
    }

    int misses = page_faults;
    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Hits: %d\n", hits);
    printf("Total Misses: %d\n", misses);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3, 5, 1, 0};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    FCFS(pages, n, capacity);
    return 0;
}
/*Total Page Faults: 8
Total Hits: 2
Total Misses: 8*/
