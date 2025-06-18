#include <stdio.h>

int main() {
    int vec[15];
    int n1, n2, i;

    printf("Valor número 1 a buscar: ");
    scanf("%d", &n1);
    printf("Valor número 2 a buscar: ");
    scanf("%d", &n2);

    for (i = 0; i < 15; i++) {
        vec[i] = i + 1;
        if (n1 == vec[i]) {
            printf("%d Si pertenece al vector\n", n1);
        }
        if (n2 == vec[i]) {
            printf("%d Si pertenece al vector\n", n2);
        }
    }

    return 0;
}
