#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int n, frames, pages[50], frame[10], time[10], count = 0, i, j, pos, found;

    printf("Enter number of frames: ");
    scanf("%d", &frames);
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);

    for (i = 0; i < frames; i++) frame[i] = -1; // Initialize empty frames

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) { // Page hit
                time[j] = i; // Update usage time
                found = 1;
                break;
            }
        }

        if (!found) { // Page fault
            if (count < frames) {
                frame[count] = pages[i];
                time[count] = i;
                count++;
            } else {
                pos = findLRU(time, frames); // Find LRU page
                frame[pos] = pages[i];
                time[pos] = i;
            }
        }

        printf("\nFrames: ");
        for (j = 0; j < frames; j++) {
            if (frame[j] != -1) printf("%d ", frame[j]);
            else printf("- ");
        }
    }

    return 0;
}
