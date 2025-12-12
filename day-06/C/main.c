#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define LENGTH(array) (sizeof(array)/sizeof((array)[0]))
#define EPSILON 0.001

// séquences en ANSI pour les couleurs
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

#define WAIT sleep(2)

double average_weight(const int weights[], int length) {
    
    if(!length) return 0.0;
    
    double sum = 0.0;
    
    for (int _ = 0; _ < length; _++) {
        sum += weights[_]; 
    }
    return sum / length;
}

int is_equal(double a, double b) {
    if(fabs(a - b) < EPSILON)
        return 1;
    return 0;

    //là je peux aussi faire directement return (fabs(a-b) < EPSILON); Mais... question de lisibilité :p
}

void basic_test() {
    printf("\nFirst test on basic case : ");
    const int weights[] = {2, 5, 7, 10};
    int length = ((int)LENGTH(weights));

    double average = average_weight(weights, length);

    assert(is_equal(average, 6.0));
    printf(GREEN" PASSED."RESET);
    WAIT;
}

void unique_element_test() {
    printf("\nSecond test on unique element case : ");
    const int weights[] = {2};
    int length = ((int)LENGTH(weights));

    double average = average_weight(weights, length);

    assert(is_equal(average, 2.0));
    printf(GREEN" PASSED."RESET);
    WAIT;
}

void none_element_test() {
    printf("\nThird test on none element case : ");
    const int weights[] = {};
    int length = ((int)LENGTH(weights));

    double average = average_weight(weights, length);

    assert(is_equal(average, 0.0));
    printf(GREEN" PASSED."RESET);
    WAIT;
}

void average_decimal_precison_test() {
    printf("\nFourth test on average decimal precision : ");
    const int weights[] = {1, 2};
    int length = ((int)LENGTH(weights));

    double average = average_weight(weights, length);

    assert(is_equal(average, 1.5));
    printf(GREEN" PASSED."RESET);
    WAIT;
}


int main() {

    const int weights[] = {2, 5, 7, 10};
    int length = ((int)LENGTH(weights));

    system("cls");

    basic_test();
    unique_element_test();
    none_element_test();
    average_decimal_precison_test();

    printf(GREEN"\n\nAll tests run successfuly !\n"RESET);
    sleep(5);

    system("cls"); //plut^to clear pour Linux
    printf("\nAverage weight for"GREEN" %d "RESET"gifts: "GREEN"%.2f"RESET"\n\n", length, average_weight(weights, length));

    return 0;
}