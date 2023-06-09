#include <stdio.h>

int main() {
    int frames[3], pages[8], faults = 0, frame_index = 0;
    int i, j, k, found;

    // initialize frames with -1 to indicate empty
    for (i = 0; i < 3; i++) {
        frames[i] = -1;
    }

    // read page reference sequence
    printf("Enter page reference sequence: ");
    for (i = 0; i < 8; i++) {
        scanf("%d", &pages[i]);
    }

    // simulate FIFO page replacement algorithm
    for (i = 0; i < 8; i++) {
        found = 0;
        // check if page is already in a frame
        for (j = 0; j < 3; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        // if page is not in a frame, replace the oldest page
        if (!found) {
            frames[frame_index] = pages[i];
            frame_index = (frame_index + 1) % 3;
            faults++;
        }
        // print current state of frames
        printf("Frames: ");
        for (k = 0; k < 3; k++) {
            if (frames[k] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[k]);
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", faults);

    return 0;
}

