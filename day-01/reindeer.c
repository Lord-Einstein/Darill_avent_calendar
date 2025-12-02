#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef struct ReindeersStruct {

    char name[30];
    char reindeerState[50];

}Reindeers;

int countPresentReindeers(Reindeers reindeer[], int size) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(!strcmp(reindeer[i].reindeerState, "present")) {
            count++;
        }
    }
    return count;
}

int main() {
    Reindeers reindeer[] = {
        {"Dasher", "present"},
        {"Dancer", "vétérinaire"},
        {"Prancer", "present"},
        {"Vixen", "spa"},
        {"Comet", "present"},
        {"Cupid", "parti"},
        {"Donner", "present"},
        {"Blitzen", "present"}
    };

    int presentReindeersNumber = countPresentReindeers(reindeer, ARRAY_SIZE(reindeer));

    presentReindeersNumber >= (ARRAY_SIZE(reindeer) / 2) ? 
    printf("\nHey Santa, you still have enough reindeer to get around, you have %d out of %d left in the stable.\n\n", presentReindeersNumber, ARRAY_SIZE(reindeer)) :
    printf("\nHi Santa, you only have %d out of %d reindeer left in the stable. You'll have to pull them yourself, you might be late.\n\n", presentReindeersNumber, ARRAY_SIZE(reindeer));

    return EXIT_SUCCESS;
}