
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  

int main() {
    int n;
    scanf("%d", &n); // 读取正整数n  

    int found_solution = 0; // 标志变量，用于检查是否找到了解决方案  

    // 遍历所有可能的男人、女人和小孩的组合  
    for (int men = 0; men * 3 <= n; men++) { // 男人最多能搬 n/3 块砖  
        for (int women = 0; (men * 3 + women * 2) <= n; women++) { // 剩余的人最多能搬 (n - men*3)/2 块砖  
            int children = (n - men * 3 - women * 2) * 2; // 小孩数量（两人搬一块砖）  
            if (children >= 0 && children % 2 == 0) { // 检查小孩数量是否非负且为偶数  
                // 输出符合条件的方案  
                printf("men = %d, women = %d, child = %d\n", men, women, children / 2);
                found_solution = 1; // 标记找到了解决方案  
            }
        }
    }

    // 如果没有找到任何符合条件的方案，则输出"None"  
    if (!found_solution) {
        printf("None\n");
    }

    return 0;
}