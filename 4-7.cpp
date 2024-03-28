#include <stdio.h>
#include <stdlib.h>
#define PAGE_FRAMES 3
int main() {
int page_frames[PAGE_FRAMES];
int page_faults = 0;
int page_count;
int oldest_index = 0;
printf("Enter the number of pages: ");
scanf("%d", &page_count);
int pages[page_count];
printf("Enter the page reference string: ");
for (int i = 0; i < page_count; i++) {
scanf("%d", &pages[i]);
}
for (int i = 0; i < PAGE_FRAMES; i++) {
page_frames[i] = -1;
}
for (int i = 0; i < page_count; i++) {
int page = pages[i];
int found = 0;
for (int j = 0; j < PAGE_FRAMES; j++) {
if (page_frames[j] == page) {
found = 1;
break;
}
}
if (!found) {
page_frames[oldest_index] = page;
oldest_index = (oldest_index + 1) % PAGE_FRAMES; 
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

