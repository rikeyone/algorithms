#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char buf[1024];
static int **pullze;

int get_colume(char *line)
{
    int i, len, colume = 1;
    len = strlen(line) - 1;
    for (i = 0; i < len; i++) {
        if (line[i] == ' ') {
            colume++;
        }
    }
    if (line[len - 1] == ' ') {
        colume--;
    }
    return colume;
}

int main(void)
{
    char *p;
    int i, j, len, num, count, line, colume;

    line = 0;
    colume = 0;

    pullze = (int **)malloc(1024 * sizeof(int *));
    while(fgets(buf, 1024, stdin) != NULL) {
        len = strlen(buf) - 1;
        p = buf;
        count = 0;
        colume = get_colume(buf);
        pullze[line] = (int *)malloc(colume * sizeof(int));

        for (i = 0; i < len; i++) {
            if (buf[i] == ' ') {
                buf[i] = '\0';
                sscanf(p, "%d", &num);
                pullze[line][count++] = num;
                p = &buf[i + 1];
            }
        }
        if (count < colume) {
            sscanf(p, "%d", &num);
            pullze[line][count++] = num;
        }
        line++;

        for (i = 0; i < line; i++) {
            for (j = 0; j < colume; j++) {
                printf("%d ", pullze[i][j]);
            }
            printf("\n");
        }
    }
}