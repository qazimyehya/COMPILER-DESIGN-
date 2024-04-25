
// Create a program which reads a text file and identify the identifiers in a given string

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isIdentifier(char c) {
    return isalnum(c) || c == '_';
}

int main() {
    FILE *fp;
    char str[100];

    printf("Enter a string:");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i]; i++) {
        if (!isIdentifier(str[i])) {
            str[i] = '\n'; // Replace non-identifier characters with newline
        }
    }

    printf("%s", str); // Print the modified string

    printf("\nIdentifiers in the file are:\n");

    fp = fopen("Rules.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char identifier[100];
    while (fscanf(fp, "%99s", identifier) == 1) {
        printf("%s\n", identifier);
    }

    fclose(fp);
    return 0;
}
