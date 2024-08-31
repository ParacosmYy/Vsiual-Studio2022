#include <stdio.h>  
#include <math.h>  

int isNarcissisticNumber(int num) {
    int n = num;
    int sum = 0;
    int digits = 0;

    // 计算数字是几位数  
    while (n > 0) {
        digits++;
        n /= 10;
    }

    // 计算每个位上的数字的n次幂之和  
    n = num;
    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, digits);
        n /= 10;
    }

    // 如果和等于原数，则是一个水仙花数  
    return sum == num;
}

int main() {
    printf("所有的3位数水仙花数：\n");
    for (int i = 100; i < 1000; i++) {
        if (isNarcissisticNumber(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}