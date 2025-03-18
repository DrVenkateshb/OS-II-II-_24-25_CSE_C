#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);  
    int shmid = shmget(key, SHM_SIZE, 0666);  
    char *str = (char*) shmat(shmid, (void*)0, 0);  
    printf("Data read from memory: %s\n", str);
    shmdt(str);  
    shmctl(shmid, IPC_RMID, NULL);  
    return 0;
}
