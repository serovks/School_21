#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void output(struct door* doors);
void zeros(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    zeros(doors);
    output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        for (int j = 0; j < DOORS_COUNT - 1; j++) {
            if (doors[j + 1].id > doors[j].id) {
                int temp = doors[j + 1].id;
                doors[j + 1].id = doors[j].id;
                doors[j].id = temp;
            }
        }
    }
}

void zeros(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void output(struct door* doors) {
    printf("%d, %d", doors[DOORS_COUNT - 1].id, doors[DOORS_COUNT - 1].status);
    for (int i = DOORS_COUNT - 2; i >= 0; i--) {
        printf("\n%d, %d", doors[i].id, doors[i].status);
    }
}
