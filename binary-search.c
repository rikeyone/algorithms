#include <stdio.h>

int binary_search(int *array, int max, int target)
{
    int i, mid;
    int start = 0, end = max - 1;

    while(start <= end) {
        mid = (start + end) / 2;
        if (target == array[mid]) {
            return mid;
        } else if (target > array[mid]) {
            start = mid + 1;
        } else { //(target < array[mid])
            end = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    int num[100];
    int target, i, index;


    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &target);

    index = binary_search(num, 10, target);


    printf("index:%d ", index);

    printf("\n");
    return 0;
}