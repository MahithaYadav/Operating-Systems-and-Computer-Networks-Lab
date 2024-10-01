#include <stdio.h>

int findOptimal(int pages[], int n, int frame[], int frameSize, int index) {
    int farthest = index, result = -1;
    for (int i = 0; i < frameSize; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == n) { // If the page is never going to be used again
            return i;
        }
    }
    return (result == -1) ? 0 : result;
}

int isPresent(int page, int frame[], int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        if (frame[i] == page) {
            return 1;
        }
    }
    return 0;
}

void optimalPageReplacement(int pages[], int n, int frameSize) {
    int frame[frameSize];
    int pageFaults = 0, index = 0;

    // Initialize the frame array with -1 (empty)
    for (int i = 0; i < frameSize; i++) {
        frame[i] = -1;
    }

    // Loop through each page in the reference string
    for (int i = 0; i < n; i++) {
        if (!isPresent(pages[i], frame, frameSize)) {  // Page fault occurs
            pageFaults++;
            if (index < frameSize) {  // Still room in the frame
                frame[index++] = pages[i];
            } else {  // Frame is full, need to replace a page
                int optimalIndex = findOptimal(pages, n, frame, frameSize, i + 1);
                frame[optimalIndex] = pages[i];
            }
        }
        // Print the current frame status
        printf("Frame after accessing page %d: ", pages[i]);
        for (int j = 0; j < frameSize; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\nTotal page faults: %d\n", pageFaults);
}

int main() {
    int n, frameSize;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    int pages[n];
    printf("Enter the reference string (pages): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    
    printf("Enter number of frames: ");
    scanf("%d", &frameSize);
    
    optimalPageReplacement(pages, n, frameSize);
    
    return 0;
}