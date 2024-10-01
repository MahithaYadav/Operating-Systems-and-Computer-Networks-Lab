#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

void printFrames(int frames[], int frameCount) {
    printf("Frames: ");
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- "); // Indicate empty frame
    }
    printf("\n");
}

int main() {
    int frames[MAX_FRAMES];
    int pageReferenceString[MAX_PAGES];
    int pageFaults = 0, frameCount, pageCount;

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &frameCount);
    
    // Input number of pages
    printf("Enter number of pages: ");
    scanf("%d", &pageCount);
    
    // Input the page reference string
    printf("Enter the page reference string (space separated): ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pageReferenceString[i]);
    }

    // Initialize frames
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1; // -1 indicates an empty frame
    }

    int nextFrameToReplace = 0;

    for (int i = 0; i < pageCount; i++) {
        int currentPage = pageReferenceString[i];
        int pageFound = 0;

        // Check if page is already in frames
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        // Page fault occurs if the page is not found
        if (!pageFound) {
            frames[nextFrameToReplace] = currentPage; // Replace the page in FIFO manner
            nextFrameToReplace = (nextFrameToReplace + 1) % frameCount; // Move to the next frame
            pageFaults++;
            printFrames(frames, frameCount);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}