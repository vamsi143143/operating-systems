#include <stdio.h>
#include <stdlib.h>
int main() {
FILE *file;
char filename[] = "C:\\Users\\vamsi\\Documents\\ 4-1";
char buffer[100];
file = fopen(filename, "w");
if (file == NULL) {
perror("Error creating file");
exit(EXIT_FAILURE);
}
printf("File created successfully.\n");
fprintf(file, "Hello, world!\n");
printf("Data written to file.\n");
fclose(file);
printf("File closed.\n");
file = fopen(filename, "r");
if (file == NULL) {
perror("Error opening file for reading");
exit(EXIT_FAILURE);
}
printf("File opened for reading.\n");
fgets(buffer, sizeof(buffer), file);
printf("Data read from file: %s\n", buffer);
fclose(file);
printf("File closed.\n");
return 0;
}

