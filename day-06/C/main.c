#include <stdio.h>

#define LENGTH(array) sizeof(array)/sizeof((array)[0])

double averageWeight(const int weights[]) {
    
    double sum = 0.0;
    int length = ((int)LENGTH(weights));

    if(!length) return 0.0;
    
    for (int _ = 0; _ < length; _++) {
        sum += weights[_]; 
    }
    return sum / length;
}


int main() {
    const int weights1[] = {2, 5, 7, 10};
    const int weights2[] = {2};

    printf("Average weight for 4 gifts: %.2f\n", averageWeight(weights1, 4));
    printf("Average weight for 1 gift: %.2f\n", averageWeight(weights2, 1));

    return 0;
}