#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(fabs((x1 - x2) * (x1 - x2)) + fabs((y1 - y2) * (y1 - y2)));
}
int main()
{
	double a, b, c, d, e, f,dis1,dis2,dis3,dis = 0;
	scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
	dis1 = distance(a, b, c, d);
	dis2 = distance(a, b, e, f);
	dis3 = distance(c, d, e, f);
	dis = dis1 + dis2 + dis3;
	printf("%.2lf", dis);
	return 0;
}