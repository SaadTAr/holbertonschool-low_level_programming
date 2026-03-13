#include "main.h"

unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    int i;
    int found;

    while (s[count] != '\0')
    {
        found = 0;

        for (i = 0; accept[i] != '\0'; i++)
        {
            if (s[count] == accept[i])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
            break;

        count++;
    }

    return (count);
}
