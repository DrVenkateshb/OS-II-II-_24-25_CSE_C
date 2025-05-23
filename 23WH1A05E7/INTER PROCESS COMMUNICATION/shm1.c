#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Shared memory size

int main() {
    key_t key;
    int shmid;
    char *shm_addr;

    // Generate a unique key
    key = ftok("shmfile", 65);
    
    // Locate shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    // Attach shared memory segment
    shm_addr = (char *) shmat(shmid, NULL, 0);
    if (shm_addr == (char *)(-1)) {
        perror("shmat failed");
        exit(1);
    }

    // Read from shared memory
    printf("Data read from shared memory: %s\n", shm_addr);

    // Detach from shared memory
    shmdt(shm_addr);

    // Destroy shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

