/* Q29. Write a C program that can read any multi-word variable name (as a string) having underscore (_) as a
   separator. Now remove all non-leading underscores to convert the variable name to a camel-case variable name.
   Example: Input: rate_of_interest  Output: rateOfInterest */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100], output[100];
    int i, j = 0;
    int len;

    printf("Enter variable name (e.g. rate_of_interest): ");
    scanf("%s", input);

    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (input[i] == '_') {
            // skip underscore, capitalize next character
            i++;
            if (i < len) {
                output[j++] = toupper(input[i]);
            }
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';

    printf("Camel-case variable name: %s\n", output);
    return 0;
}