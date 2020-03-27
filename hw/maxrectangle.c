/*
求直方图的最大的矩形面积
Given height = [2,1,5,6,2,3],
return 10.

一种很好的优化方法，就是遍历数组，每找到一个局部峰值
（只要当前的数字大于后面的一个数字，那么当前数字就看作一个局部峰值，跟前面的数字大小无关），
然后向前遍历所有的值，算出共同的矩形面积，每次对比保留最大值。
这里再说下为啥要从局部峰值处理，看题目中的例子，局部峰值为 2，6，3，
我们只需在这些局部峰值出进行处理，为啥不用在非局部峰值处统计呢，这是因为非局部峰值处的情况，
后面的局部峰值都可以包括，比如1和5，由于局部峰值6是高于1和5的，所有1和5能组成的矩形，
到6这里都能组成，并且还可以加上6本身的一部分组成更大的矩形，那么就不用费力气去再统计一个1和5处能组成的矩形了。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[1024];

int main(void)
{
    int size = 0;
    int i, j, max, temp, high;

    while(scanf("%d", &size) != EOF) {
        for(i = 0; i < size; i++) {
            scanf("%d", &array[i]);
        }
        max = 0;
        for (i = 0; i < size; i++) {
            if (((i < (size - 1)) && (array[i] > array[i + 1]))
                || (i == size - 1)) {
                high = array[i];
                for (j = i - 1; j >= 0; j--) {
                    high = array[j] < high ? array[j] : high;
                    temp = high * (i - j + 1);
                    max = max > temp ? max : temp;
                }
            }
        }
        printf("%d\n", max);
    }

}