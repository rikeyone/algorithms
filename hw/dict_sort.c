#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int is_should_be_left(char *base, char *str)
{
    if (strcmp(base, str) > 0)
        return 1;
    else
        return 0;
}

int main(void)
{
    int len;
    scanf("%d", &len);
    char buf[len][100];
    char a[100];
    int i, j;

    for (i = 0; i < len; i++) {
        scanf("%s", buf[i]);
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (is_should_be_left(buf[j], buf[j+1])){
                strcpy(a,buf[j]);
                strcpy(buf[j],buf[j + 1]);
                strcpy(buf[j + 1],a);
            }
        }
    }
    for (i = 0; i < len; i++) {
        printf("%s\n", buf[i]);
    }

}