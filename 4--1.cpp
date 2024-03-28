#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
int fd = open("C:\\Users\\vamsi\\Downloads\\sse.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
if (fd == -1) {
perror("Error opening file");
exit(EXIT_FAILURE);
}
char *text = "Hello, World!\n";
write(fd, text, strlen(text));
off_t offset = lseek(fd, 0, SEEK_SET);
if (offset == -1) {
perror("Error seeking file");
exit(EXIT_FAILURE);
}
char buffer[100];
ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
if (bytes_read == -1) {
perror("Error reading file");
exit(EXIT_FAILURE);
}
buffer[bytes_read] = '\0';
printf("File content: %s", buffer);
struct stat file_info;
if (fstat(fd, &file_info) == -1) {
perror("Error getting file info");
exit(EXIT_FAILURE);
}
printf("File size: %lld bytes\n", (long long)file_info.st_size);
DIR *dir = opendir(".");
if (dir == NULL) {
perror("Error opening directory");
exit(EXIT_FAILURE);
}
struct dirent *entry;
printf("Directory contents:\n");
while ((entry = readdir(dir)) != NULL) {
printf("%s\n", entry->d_name);
}
close(fd);
closedir(dir);

return 0;
}

