#include <stdio.h>

#define MAX 10

int findOptimal(int pages[], int n, int frames[], int frameCount, int index) {
    int farthest = index, res = -1;
    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) return i;  // If frame is not used again, replace it
    }
    return (res == -1) ? 0 : res;
}

void optimalPageReplacement(int pages[], int n, int frameCount) {
    int frames[MAX], hits = 0, misses = 0;

    for (int i = 0; i < frameCount; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == pages[i]) {
                hits++;
                found = 1;
                break;
            }
        }

        if (!found) {
            int replaceIndex = (i < frameCount) ? i : findOptimal(pages, n, frames, frameCount, i + 1);
            frames[replaceIndex] = pages[i];
            misses++;
        }

        printf("\nFrames: ");
        for (int j = 0; j < frameCount; j++) {
            printf("%d ", frames[j]);
        }
    }

    printf("\n\nHits: %d\nMisses: %d\n", hits, misses);
    printf("Hit Ratio: %.2f%%\n", (float)hits / n * 100);
}

int main() {
    int n, frameCount;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[MAX];
    printf("Enter page references:\n");
    for (int i = 0; i < n; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    optimalPageReplacement(pages, n, frameCount);

    return 0;
}
