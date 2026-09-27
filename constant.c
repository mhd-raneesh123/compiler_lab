#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, a, b;
    int value[26] = {0}, used[26] = {0};
    char str[100], var, x, op, rhs[50];
    char *end;

    printf("Enter number of statements: ");
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++)
    {
        printf("Enter statement: ");
        fgets(str, sizeof(str), stdin);

        sscanf(str, " %c = %s", &var, rhs);
        var = toupper(var);

        if (isdigit(rhs[0]) || rhs[0] == '-')
        {
            value[var - 'A'] = strtol(rhs, NULL, 10);
        }
        else if (sscanf(rhs, "%c%c", &x, &op) == 2 &&
                 (op == '+' || op == '-' ||
                  op == '*' || op == '/'))
        {
            x = toupper(x);
            a = value[x - 'A'];

            b = strtol(rhs + 2, &end, 10);

            if (*end == '\0')
            {
                switch (op)
                {
                    case '+': a += b; break;
                    case '-': a -= b; break;
                    case '*': a *= b; break;
                    case '/':
                        if (b != 0)
                            a /= b;
                        break;
                }
                value[var - 'A'] = a;
            }
        }
        else
        {
            x = toupper(rhs[0]);
            value[var - 'A'] = value[x - 'A'];
        }

        used[var - 'A'] = 1;
    }

    printf("\nFinal values:\n");

    for (i = 0; i < 26; i++)
    {
        if (used[i])
            printf("%c = %d\n", 'A' + i, value[i]);
    }

    return 0;
}