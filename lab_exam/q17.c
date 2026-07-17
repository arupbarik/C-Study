/* Q17. Find Pythagorean triplet in 1 to 100. */

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Pythagorean triplets from 1 to 100:\n");
    for (a = 1; a <= 100; a++) {
        for (b = a; b <= 100; b++) {
            for (c = b; c <= 100; c++) {
                if (a * a + b * b == c * c) {
                    printf("%d, %d, %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}