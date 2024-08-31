
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main() {
	int a[99];
	int i = 0;
	long long int sum = 0;
	while (scanf("%d", &a[i]) != EOF) {
		sum = sum + a[i];
		i++;
	}
	sum = sum * pow(2, i - 1);
	printf("%lld", sum);
	return 0;
}