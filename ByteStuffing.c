#include <stdio.h>
#include <string.h>
void main()
{
    char in[100], out[100], check[5], c[5];
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
            }
            c[j] = '\0';
            if (k == 3)
            {
                if (!strcmp(check, c))
                {
                    out[ind] = '\0';
                    strcat(out, "esc");
                    strcat(out, "esc");
                    i = i + 3;
                    ind += 6;
                }
                else
                    goto l1;
            }
            if (k == 4)
            {
                if (!strcmp(check, c))
                {
                    out[ind] = '\0';
                    strcat(out, "esc");
                    strcat(out, "flag");
                    i = i + 4;
                    ind += 7;
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
flagsnistescsnistesc
*/