#include <stdio.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10

int partitions[MAX_PARTITIONS];
int processes[MAX_PROCESSES];

int main() {
    // Initialize memory partitions
    int num_partitions = 6;
    partitions[0] = 300;
    partitions[1] = 600;
    partitions[2] = 350;
    partitions[3] = 200;
    partitions[4] = 750;
    partitions[5] = 125;

    // Initialize processes
    int num_processes = 5;
    processes[0] = 115;
    processes[1] = 500;
    processes[2] = 358;
    processes[3] = 200;
    processes[4] = 375;

    // Allocate memory to processes using first-fit algorithm
    int i, j;
    for (i = 0; i < num_processes; i++) {
        int allocated = 0;
        for (j = 0; j < num_partitions; j++) {
            if (partitions[j] >= processes[i]) {
                // Allocate memory to process i in partition j
                partitions[j] -= processes[i];
                printf("Allocated %d KB to process %d\n", processes[i], i+1);
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            printf("Unable to allocate memory to process %d\n", i+1);
        }
    }

    return 0;
}

