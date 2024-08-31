#include <stdio.h>  
#include <math.h>  

int isNarcissisticNumber(int num) {
    int n = num;
    int sum = 0;
    int digits = 0;

    // ���������Ǽ�λ��  
    while (n > 0) {
        digits++;
        n /= 10;
    }

    // ����ÿ��λ�ϵ����ֵ�n����֮��  
    n = num;
    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, digits);
        n /= 10;
    }

    // ����͵���ԭ��������һ��ˮ�ɻ���  
    return sum == num;
}

int main() {
    printf("���е�3λ��ˮ�ɻ�����\n");
    for (int i = 100; i < 1000; i++) {
        if (isNarcissisticNumber(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}