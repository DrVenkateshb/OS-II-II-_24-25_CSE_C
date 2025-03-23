#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define BUFFER_SIZE 100

struct msg_buffer {
    long msg_type;
    char msg_text[BUFFER_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }
    message.msg_type = 1;
    printf("Enter message: ");
    fgets(message.msg_text, BUFFER_SIZE, stdin);

    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }
    printf("Message sent to Reader.\n");
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 2, 0) == -1) {
        perror("msgrcv failed");
        exit(1);
    }

    printf("Received from Reader: %s", message.msg_text);
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}

