#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to factorize a number
void factorize(int n) {
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0 && is_prime(i) && is_prime(n / i)) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }
    printf("%d is not factorizable\n", n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        factorize(num);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
