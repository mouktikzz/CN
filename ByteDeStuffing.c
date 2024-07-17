#include <stdio.h>
#include <string.h>

void main()
{
    char in[100], out[100], check[5], c[5], d[5];
    int count, i, k = 0, j, s, ind = 0;
    printf("enter a string:");
    scanf("%s", in);
    i = 0;
    strcpy(out, "");
    while (i < strlen(in))
    {
        strcpy(check, "");
        strcpy(c, "");
        if (in[i] == 'e')
        {
            strcpy(check, "esc");
            k = 3;
        }
        if (in[i] == 'f')
        {
            strcpy(check, "flag");
            k = 4;
        }
        if (k != 0)
        {
            for (j = 0; j < k; j++)
            {
                c[j] = in[i + j];
                d[j] = in[i + j + 3];
            }
            c[j] = '\0';
            d[j] = '\0';

            if (k == 3)
            {
                if (!strcmp(check, c) && !strcmp(check, d))
                {
                    out[ind] = '\0';
                    strcat(out, "esc");
                    i = i + 6;
                    ind += 3;
                }
                else if (!strcmp(check, c))
                {
                    out[ind] = '\0';
                    strcat(out, "flag");
                    i = i + 7;
                    ind += 4;
                }
                else
                    goto l1;
            }
            k = 0;
        }
        else
        {
        l1:
            out[ind] = in[i];
            ind += 1;
            i = i + 1;
        }
    }
    printf("%s", out);
}
/*
escescescflag
*/