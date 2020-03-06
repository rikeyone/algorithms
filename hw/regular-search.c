#include <stdio.h>

int main()
{
    int a[11]={1,4,6,9,13,16,19,28,40,100};
    int number,i,j;
    printf("original array is:\n");

    for(i=0;i<10;i++)
        printf("%5d",a[i]);
    printf("\n");

    printf("insert a new number:");
    scanf("%d",&number);

    for(i = 0; i < 10; i++) {
        if(a[i] > number) {
            for(j = 9; j >= i; j--) {
                a[j + 1] = a[j];
            }
            a[i] = number;
            break;
        }
    }

    for(i = 0; i < 11; i++)
        printf("%6d",a[i]);
    return 0;
}
