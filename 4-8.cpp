#include <stdio.h>
#include <stdlib.h>
#define PAGE_FRAMES 3
int main() {
int page_frames[PAGE_FRAMES];
int page_faults = 0;
int pages[] = {1, 3, 0, 3, 5, 6, 3}; 
int page_count = sizeof(pages) / sizeof(pages[0]);
for (int i = 0; i < PAGE_FRAMES; i++) {
page_frames[i] = -1;
}
for (int i = 0; i < page_count; i++) {
int page = pages[i];
int found = 0;
for (int j = 0; j < PAGE_FRAMES; j++) {
if (page_frames[j] == page) {
found = 1;
for (int k = j; k > 0; k--) {
page_frames[k] = page_frames[k - 1];
}
page_frames[0] = page;

break;
}
}
if (!found) {
for (int j = PAGE_FRAMES - 1; j > 0; j--) {
page_frames[j] = page_frames[j - 1];
}
page_frames[0] = page;
page_faults++;
}
printf("Page frames after reference %d: ", page);
for (int j = 0; j < PAGE_FRAMES; j++) {
printf("%d ", page_frames[j]);
}
printf("\n");
}

printf("Total page faults: %d\n", page_faults);

return 0;
}

