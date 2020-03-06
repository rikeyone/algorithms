#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insert_number(int *input, int *count, int value)
{
    int i,temp;
    int target = 0;
    int size = *count;

    if (size == 0) {
        input[0] = value;
        *count = 1;
        return 0;
    }
    for (i = 0; i < size; i++) {
        if (value == input[i])
            return 0;
    }
    for (i = 0; i < size; i++) {
        if (value > input[i]) {
            temp = i + 1;
            target = (temp > target) ? temp : target;
        } else
            break;
    }
    for (i = size - 1; i >= target; i--) {
        input[i + 1] = input[i];
    }
    input[target] = value;
    (*count)++;
    return 0;
}

int main(void)
{
    int input[200];
    int num, value, i, count;
    scanf("%d", &num);
    count = 0;
    for (i = 0; i < num; i++) {
        scanf("%d", &value);
        insert_number(input, &count, value);
    }
    for (i = 0; i < count; i++) {
        printf("%d\n", input[i]);
    }
    return 0;
}
