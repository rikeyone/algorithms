#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ip1[100];
char ip2[100];
char mask[100];
int ipsection1[4];
int ipsection2[4];
int masksection[4];


int filter_section(char *s, int *section)
{
    int i, len;
    char *s1, *s2, *s3, *s4, *pos;

    s1 = s;
    pos = s1;
    while(*pos != '.') {
        pos++;
    }
    *pos = '\0';
    sscanf(s1, "%d", &section[0]);
    s2 = pos + 1;
    pos = s2;
    while(*pos != '.') {
        pos++;
    }
    *pos = '\0';
    sscanf(s2, "%d", &section[1]);
    s3 = pos + 1;
    pos = s3;
    while(*pos != '.') {
        pos++;
    }
    *pos = '\0';
    sscanf(s3, "%d", &section[2]);
    s4 = pos + 1;
    sscanf(s4, "%d", &section[3]);
    return 0;
}

int main(void)
{
    int i, same = 1;
    while(1) {
        same = 1;
        if (scanf("%s", ip1) == EOF) {
            break;
        }
        if (scanf("%s", ip2) == EOF) {
            break;
        }
        if (scanf("%s", mask) == EOF) {
            break;
        }
        filter_section(ip1, ipsection1);
        filter_section(ip2, ipsection2);
        filter_section(mask, masksection);
        for (i = 0; i < 4; i++) {
            if ((ipsection1[i] & masksection[i]) != (ipsection2[i] & masksection[i])) {
                same = 0;
                break;
            }
        }
        if (same)
            printf("Same ip\n");
        else
        {
            printf("Not same ip\n");
        }

    }
    return 0;
}