#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
    char str[10001] = { '\0' };
    while (gets(str)) {  //注：这里不能使用scanf("%d",str)函数，含空格字符串会被视为多组输入。
        int len = strlen(str);
        int a = 0;
        scanf("%d", &a);
        for (int i = a; i <= len; i++) {
            printf("%c", str[i]);
        }
        for (int i = 0; i < a; i++)
        {
            printf("%c", str[i]);
        }
    }
    return 0;
}