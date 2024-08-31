
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  

int main() {
    int n;
    scanf("%d", &n); // ��ȡ������n  

    int found_solution = 0; // ��־���������ڼ���Ƿ��ҵ��˽������  

    // �������п��ܵ����ˡ�Ů�˺�С�������  
    for (int men = 0; men * 3 <= n; men++) { // ��������ܰ� n/3 ��ש  
        for (int women = 0; (men * 3 + women * 2) <= n; women++) { // ʣ���������ܰ� (n - men*3)/2 ��ש  
            int children = (n - men * 3 - women * 2) * 2; // С�����������˰�һ��ש��  
            if (children >= 0 && children % 2 == 0) { // ���С�������Ƿ�Ǹ���Ϊż��  
                // ������������ķ���  
                printf("men = %d, women = %d, child = %d\n", men, women, children / 2);
                found_solution = 1; // ����ҵ��˽������  
            }
        }
    }

    // ���û���ҵ��κη��������ķ����������"None"  
    if (!found_solution) {
        printf("None\n");
    }

    return 0;
}