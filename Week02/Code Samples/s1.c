#include <stdio.h>

int main()
{
    char s[128] = "";

    fgets(s, 128, stdin);

    printf("%s\n", s);

    return 0;
}
