#include <stdio.h>
#include <math.h>
#include <assert.h>

#define LENGTH(array) sizeof(array)/sizeof((array)[0])
#define EPSILON 0.001

// séquences en ANSI pour les couleurs
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

double average_weight(const int weights[]) {
    
    double sum = 0.0;
    int length = ((int)LENGTH(weights));

    if(!length) return 0.0;
    
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
    int weights[] = {2, 5, 7, 10};
    double average = averageWeight(weights);

    assert(is_equal(average, 6.0));
    printf(GREEN" PASSED."RESET);
}

void unique_element_test() {
    printf("\nFirst test on basic case : ");
    int weights[] = {2};
    double average = averageWeight(weights);

    assert(is_equal(average, 2.0));
    printf(GREEN" PASSED."RESET);
}

void none_element_test() {
    printf("\nFirst test on basic case : ");
    int weights[] = {};
    double average = averageWeight(weights);

    assert(is_equal(average, 0.0));
    printf(GREEN" PASSED."RESET);
}

void average_decimal_precison_test() {
    printf("\nFirst test on basic case : ");
    int weights[] = {1, 2};
    double average = averageWeight(weights);

    assert(is_equal(average, 1.5));
    printf(GREEN" PASSED."RESET);
}


int main() {

    

    return 0;
}