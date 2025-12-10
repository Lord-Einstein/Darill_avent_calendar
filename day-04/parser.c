#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CONVERSION_BASE 10
#define BUFFER_SIZE 256
#define MAX_ELFES 1000

int Empty_lign(char *lign) {
    char matches_char;
    if(sscanf(lign, " %c", &matches_char) != 1) {
        return 1;
    }
    return 0;
}

unsigned int Convert_long_to_int(unsigned long long_value) {
    if(long_value > UINT_MAX) {
        return 0;
    }
    return ((unsigned int)long_value);
}

unsigned int Calories_lign(char* lign) {
    unsigned long calories_value;
    char *endptr;
    
    calories_value = strtoul(lign, &endptr, CONVERSION_BASE);
    if (lign == endptr) {
        return 0;
    }

    if(calories_value) {
        return Convert_long_to_int(calories_value);
    }
    return 0;
}

typedef struct ElfeCaloriesStruct{
    char elfe_name[50];
    unsigned int calories_sum;
} ElfeCalories;

int main(void) {

    FILE *file = NULL;
    char lign_buffer[BUFFER_SIZE];

    ElfeCalories elfe_calories_table[MAX_ELFES]; 
    memset(elfe_calories_table, 0, sizeof(elfe_calories_table));

    unsigned int calories_value = 0;
    int elfe_cursor = 0;

    file = fopen("./data", "r");

    if(!file){
        perror("Erreur de traitement du fichier ");
        return EXIT_FAILURE;
    }

    while(fgets(lign_buffer, sizeof(lign_buffer), file) != NULL) {
        
        lign_buffer[strcspn(lign_buffer, "\r\n")] = 0;

        if(Empty_lign(lign_buffer)) {
            if (strlen(elfe_calories_table[elfe_cursor].elfe_name) > 0 || elfe_calories_table[elfe_cursor].calories_sum > 0) {
                elfe_cursor++;
            }
            continue;
        }

        calories_value = Calories_lign(lign_buffer);

        if(calories_value > 0){
            elfe_calories_table[elfe_cursor].calories_sum += calories_value;
        } else {
            strcpy(elfe_calories_table[elfe_cursor].elfe_name, lign_buffer);
        }
    }

    if (strlen(elfe_calories_table[elfe_cursor].elfe_name) > 0) {
        elfe_cursor++; 
    }

    for (int i = 0; i < elfe_cursor - 1; i++) {
        for (int j = 0; j < elfe_cursor - i - 1; j++) {
            if (elfe_calories_table[j].calories_sum < elfe_calories_table[j + 1].calories_sum) {
                ElfeCalories temp = elfe_calories_table[j];
                elfe_calories_table[j] = elfe_calories_table[j + 1];
                elfe_calories_table[j + 1] = temp;
            }
        }
    }

    // for (int i = 0; i < elfe_cursor; i++) {
    //     printf("%s porte %u calories.\n", elfe_calories_table[i].elfe_name, elfe_calories_table[i].calories_sum);
    // }

    
    printf("\n--- RESULTATS BATAILLE DE BISCUITS ---\n\n");

    if (elfe_cursor > 0) {
        printf("🍪 Elf of the Day: %s with %u calories!\n", elfe_calories_table[0].elfe_name, elfe_calories_table[0].calories_sum);
    }

    if (elfe_cursor > 2) {
        printf("🥈 Then comes %s (%u) and %s (%u)\n", elfe_calories_table[1].elfe_name, elfe_calories_table[1].calories_sum, elfe_calories_table[2].elfe_name, elfe_calories_table[2].calories_sum);
        
        unsigned int total_top3 = elfe_calories_table[0].calories_sum + 
                                  elfe_calories_table[1].calories_sum + 
                                  elfe_calories_table[2].calories_sum;
        
        printf("🎁 Combined snack power of Top 3: %u calories!\n\n", total_top3);
    } else {
        printf("Pas assez d'elfes pour faire un Top 3 !\n\n");
    }

    fclose(file);
    return EXIT_SUCCESS;
}