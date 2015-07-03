#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void sieve(char *a, size_t n)
{
    size_t i, j;

    memset(a, 1, n);
    memset(a, 0, 2);

    for (i=2; i*i<n; i++)
        for (j=2*i; a[i] && j<n; j+=i)
            a[j] = 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("usage: %s N\n", *argv);
        return 0;
    }

    size_t i, n = atoi(argv[1]);
    char *a = malloc(n);

    sieve(a, n);

    for (i=0; i<n; i++)
        if (a[i])
            printf("%ld\n", i);

    free(a);
    return 0;
}

