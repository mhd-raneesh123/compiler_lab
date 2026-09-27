#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[1000];
    int i = 0, j;

    printf("Enter a C program (Ctrl+D to finish):\n");

    while (fgets(str + i, sizeof(str) - i, stdin))
        i = strlen(str);

    i = 0;

    while (str[i] != '\0')
    {
        if (isspace(str[i]))
            i++;

        else if (isalpha(str[i]) || str[i] == '_')
        {
            char word[50];
            j = 0;

            while (isalnum(str[i]) || str[i] == '_')
                word[j++] = str[i++];

            word[j] = '\0';

            if (!strcmp(word, "int") ||
                !strcmp(word, "float") ||
                !strcmp(word, "char") ||
                !strcmp(word, "if") ||
                !strcmp(word, "else") ||
                !strcmp(word, "while") ||
                !strcmp(word, "return"))
                printf("%s : Keyword\n", word);
            else
                printf("%s : Identifier\n", word);
        }

        else if (isdigit(str[i]))
        {
            printf("%c : Number\n", str[i++]);
        }

        else if (strchr("+-*/=", str[i]))
        {
            printf("%c : Operator\n", str[i++]);
        }

        else if (strchr(";,(){}", str[i]))
        {
            printf("%c : Special Symbol\n", str[i++]);
        }

        else
            i++;
    }

    return 0;
}
