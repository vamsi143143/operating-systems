#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DISK_SIZE 1000  
#define BLOCK_SIZE 512   
#define MAX_FILES 10    
typedef struct {
int startBlock;     
int numBlocks;      
} File;
typedef struct {
bool allocated[DISK_SIZE];  
} Disk;
void initializeDisk(Disk *disk) {
for (int i = 0; i < DISK_SIZE; i++) {
disk->allocated[i] = false;
}
}
bool allocateBlocks(Disk *disk, File *file) {
int blocksNeeded = file->numBlocks;
int consecutiveBlocks = 0;
for (int i = 0; i < DISK_SIZE; i++) {
if (!disk->allocated[i]) {
consecutiveBlocks++;
if (consecutiveBlocks == blocksNeeded) {
file->startBlock = i - blocksNeeded + 1;
break;
}
} else {
consecutiveBlocks = 0;
}
}
if (consecutiveBlocks == blocksNeeded) {
for (int i = file->startBlock; i < file->startBlock + blocksNeeded; i++) {
disk->allocated[i] = true;
}
return true;
} else {
printf("Error: Not enough contiguous free blocks.\n");
return false;
}
}
void simulateFileAllocation(Disk *disk, File files[], int numFiles) {
printf("Simulating file allocation strategy...\n");
for (int i = 0; i < numFiles; i++) {
printf("File %d: Blocks [%d-%d]\n", i+1, files[i].startBlock, files[i].startBlock + files[i].numBlocks - 1);
}
}

int main() {
Disk disk;
initializeDisk(&disk);

int numFiles;
printf("Enter the number of files: ");
scanf("%d", &numFiles);

if (numFiles > MAX_FILES) {
printf("Error: Exceeded maximum number of files.\n");
return 1;
}
File files[numFiles];
for (int i = 0; i < numFiles; i++) {
printf("Enter number of blocks for File %d: ", i+1);
scanf("%d", &files[i].numBlocks);
if (files[i].numBlocks <= 0 || files[i].numBlocks > DISK_SIZE) {
printf("Error: Invalid number of blocks for File %d.\n", i+1);
return 1;
}
if (!allocateBlocks(&disk, &files[i])) {
return 1;
}
}
simulateFileAllocation(&disk, files, numFiles);
return 0;
}

