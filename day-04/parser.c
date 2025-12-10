#include <stdio.h>
#include <stdlib.h>

#define CONVERSION_BASE 10

int Empty_lign(char *lign) {
    char matches_char;
    if(sscanf(lign, " %c", &matches_char) != 1) {
        printf("-EMPTY LIGN-\n");
        return 1;
    }
    return 0;
}

unsigned int Convert_long_to_int(unsigned long long_value) {
    
    if(long_value > UINT_MAX) {
        return 0;
    }

    return ((unsigned int) long_value);
}

unsigned int Calories_lign(char* lign) {

    unsigned long calories_value;
    calories_value = strtol(lign, NULL, CONVERSION_BASE);

    if(calories_value) {
        return Convert_long_to_int(calories_value);
    }
    //de toutes façons si la valeur convertie est vraiment de 0 on n'en a rien à faire :p .. cà n'influe pas sur le calcul
    return 0;
}

typedef struct ElfeCaloriesStruct{
    const char *elfe_name;
    unsigned int calories_sum;
}ElfeCalories;

int main(void) {

    FILE *file = NULL;
    char lign_buffer[256];

    ElfeCalories elfe_calories_table[100];
    unsigned int calories_value = 0;
    const char* elfe_name;
    int elfe_cursor = 0;


    file = fopen("./test.txt", "a+");

    if(!file){
        perror("Erreur de traitement du fichier : (fopen)");
        return EXIT_FAILURE;
    }

    while(fgets(lign_buffer, sizeof(lign_buffer), file) != NULL) {
        if(Empty_lign(lign_buffer)) {
            continue;
        }

        if(Calories_lign())
        printf("%s", lign_buffer);
    }


    fclose(file);
    return EXIT_SUCCESS;
}