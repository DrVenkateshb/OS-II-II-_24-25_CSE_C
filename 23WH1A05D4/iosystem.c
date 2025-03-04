#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int file = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (file == -1) {
        perror("Open failed");
        return 1;
    }
    const char *text = "Hello, this is a test file.\n";
    write(file, text, 26);
    close(file);
    file = open("example.txt", O_RDONLY);
    if (file == -1) {
        perror("Open failed");
        return 1;
    }
    char buffer[27];
    read(file, buffer, 26);
    buffer[26] = '\0'; 
    printf("Content of example.txt: %s\n", buffer);
    lseek(file, 0, SEEK_SET);
    read(file, buffer, 26);
    buffer[26] = '\0'; 
    printf("Content of example.txt after lseek: %s\n", buffer);
    close(file);
    struct stat fileStat;
    stat("example.txt", &fileStat);
    printf("File size: %ld bytes\n", fileStat.st_size);
    DIR *dir = opendir(".");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);

    return 0;
}
