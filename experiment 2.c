#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100];
    int i = 0;

    printf("Enter a statement: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {

        if (isspace((unsigned char)str[i])) {
            i++;
        }

        else if (isalpha((unsigned char)str[i]) || str[i] == '_') {
            char word[50];
            int j = 0;

            while (isalnum((unsigned char)str[i]) || str[i] == '_') {
                word[j++] = str[i++];
            }

            word[j] = '\0';

            if (strcmp(word, "int") == 0 ||
                strcmp(word, "float") == 0 ||
                strcmp(word, "char") == 0 ||
                strcmp(word, "if") == 0 ||
                strcmp(word, "else") == 0 ||
                strcmp(word, "return") == 0) {
                printf("%s : Keyword\n", word);
            } else {
                printf("%s : Identifier\n", word);
            }
        }

        else if (isdigit((unsigned char)str[i])) {
            char num[50];
            int j = 0;

            while (isdigit((unsigned char)str[i])) {
                num[j++] = str[i++];
            }

            num[j] = '\0';
            printf("%s : Number\n", num);
        }

        else if (strchr("+-*/%=<>!", str[i]) != NULL) {
            printf("%c : Operator\n", str[i]);
            i++;
        }

        else if (strchr(";,(){}", str[i]) != NULL) {
            printf("%c : Special Symbol\n", str[i]);
            i++;
        }

        else {
            printf("%c : Unknown Symbol\n", str[i]);
            i++;
        }
    }

    return 0;
}
