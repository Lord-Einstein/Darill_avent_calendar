#include <stdio.h>

#define LENGTH(array) sizeof(array) / sizeof((array)[0])

double averageWeight(const int w[], const int l) {
    int s = 0;
    for (int i = 0; i < l; i++) {
        s += w[i];
    }
    return s / l;
}

int main() {
    const int weights1[] = {2, 5, 7, 10};
    const int weights2[] = {2};

    printf("Average weight for 4 gifts: %.2f\n", averageWeight(weights1, 4));
    printf("Average weight for 1 gift: %.2f\n", averageWeight(weights2, 1));

    return 0;
}