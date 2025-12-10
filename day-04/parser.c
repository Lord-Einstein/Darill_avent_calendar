#include <stdio.h>
#include <stdlib.h>

int empty_lign(char *lign) {
    char matches_char;
    if(sscanf(lign, " %c", &matches_char) != 1) {
        printf("-EMPTY LIGN-\n");
        return 1;
    }
    return 0;
}

int main(void) {

    FILE *file = NULL;
    char lign_buffer[256];


    file = fopen("./test.txt", "a+");

    if(!file){
        perror("Erreur de traitement du fichier : (fopen)");
        return EXIT_FAILURE;
    }

    while(fgets(lign_buffer, sizeof(lign_buffer), file) != NULL) {
        if(empty_lign(lign_buffer)) {
            continue;
        }
        printf("%s", lign_buffer);
    }


    fclose(file);
    return EXIT_SUCCESS;
}