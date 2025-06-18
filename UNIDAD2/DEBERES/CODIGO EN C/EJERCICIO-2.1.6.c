#include <stdio.h>

int main() {
    int vec[10];
    int i, j;

    for (i = 0; i < 10; i++) {
        vec[i] = i + 1;
    }

    printf("===============================================================\n");
    printf("Vector ordenado de mayor a menor\n");
    printf("===============================================================\n");
    for (j = 9; j >= 0; j--) {
        printf("%d\n", vec[j]);
    }

    return 0;
}
