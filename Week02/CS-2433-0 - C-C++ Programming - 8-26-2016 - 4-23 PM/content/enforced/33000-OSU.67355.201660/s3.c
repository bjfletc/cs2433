#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    char s[128] = "";

    fgets(s, 128, stdin);
    sscanf(s, "%d", &n);
    printf("%s\n", s);
    printf("%d\n", n);

    return 0;
}
