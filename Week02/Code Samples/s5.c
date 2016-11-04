#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    char s[128] = "";
    char *os[2] = {"even", "odd"};

    fgets(s, 128, stdin);
    sscanf(s, "%d", &n);
    printf("%s\n", s);
    printf("%d\n", n);

    printf("%s\n", os[(n % 2)]);

    return 0;
}
