#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
    char str[10001] = { '\0' };
    while (gets(str)) {  //ע�����ﲻ��ʹ��scanf("%d",str)���������ո��ַ����ᱻ��Ϊ�������롣
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