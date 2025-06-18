#include <stdio.h>

int main() {
    long long vec[15];
    int i, j;

    printf("==========================================================\n");
    for (i = 0; i < 15; i++) {
        vec[i] = 1;
        for (j = 1; j <= i + 1; j++) {
            vec[i] *= j;
        }
        printf("El factorial de %d es: %lld\n", i + 1, vec[i]);
    }

    return 0;
}
