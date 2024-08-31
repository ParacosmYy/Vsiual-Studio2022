#include <stdio.h>
#include <math.h>
#define M_PI 3.1415926
double target_angle_1;
double target_angle_2;
double target_angle_3;
double target_angle_4;
double target_angle_5;
double target_angle_6;
void servo_angle_calculate(float target_x, float target_y, float target_z)
{
	if (target_y >= 18)
		target_y = 18;
	else if (target_y <= 3)
		target_y = 3;
	float len_1, len_2, len_3, len_4;   //a1为底部圆台高度 剩下三个为三个机械臂长度 
	float j1, j2, j3, j4;   //四个姿态角
	float L, H, bottom_r;					//	L =	a2*sin(j2) + a3*sin(j2 + j3);H = a2*cos(j2) + a3*cos(j2 + j3); P为底部圆盘半径R
	float j_sum;			//j2,j3,j4之和
	float len, high;   //总长度,总高度
	float cos_j3, sin_j3; //用来存储cosj3,sinj3数值
	float cos_j2, sin_j2;
	float k1, k2;
	int i;
	float n, m;
	n = 0;
	m = 0;

	//输入初始值
	bottom_r = 8; 		//底部圆盘半径
	len_1 = 8; 	//底部圆盘高度
	//机械臂长度
	len_2 = 10.5;
	len_3 = 9.75;
	len_4 = 17;

	if (target_x == 0)
		j1 = 90;
	else
		j1 = 90 - atan(target_x / (target_y + bottom_r)) * (57.3);


	for (i = 0; i <= 180; i++)
	{
		j_sum = 3.1415927 * i / 180;

		len = sqrt((target_y + bottom_r) * (target_y + bottom_r) + target_x * target_x);
		high = target_z;

		L = len - len_4 * sin(j_sum);
		H = high - len_4 * cos(j_sum) - len_1;

		cos_j3 = ((L * L) + (H * H) - ((len_2) * (len_2)) - ((len_3) * (len_3))) / (2 * (len_2) * (len_3));
		sin_j3 = (sqrt(1 - (cos_j3) * (cos_j3)));

		j3 = atan((sin_j3) / (cos_j3)) * (57.3);

		k2 = len_3 * sin(j3 / 57.3);
		k1 = len_2 + len_3 * cos(j3 / 57.3);

		cos_j2 = (k2 * L + k1 * H) / (k1 * k1 + k2 * k2);
		sin_j2 = (sqrt(1 - (cos_j2) * (cos_j2)));

		j2 = atan((sin_j2) / (cos_j2)) * 57.3;
		j4 = j_sum * 57.3 - j2 - j3;

		if (j2 >= 0 && j3 >= 0 && j4 >= -90 && j2 <= 180 && j3 <= 180 && j4 <= 90)
		{
			n++;
		}
	}


	for (i = 0; i <= 180; i++)
	{
		j_sum = 3.1415927 * i / 180;

		len = sqrt((target_y + bottom_r) * (target_y + bottom_r) + target_x * target_x);
		high = target_z;

		L = len - len_4 * sin(j_sum);
		H = high - len_4 * cos(j_sum) - len_1;

		cos_j3 = ((L * L) + (H * H) - ((len_2) * (len_2)) - ((len_3) * (len_3))) / (2 * (len_2) * (len_3));
		sin_j3 = (sqrt(1 - (cos_j3) * (cos_j3)));

		j3 = atan((sin_j3) / (cos_j3)) * (57.3);

		k2 = len_3 * sin(j3 / 57.3);
		k1 = len_2 + len_3 * cos(j3 / 57.3);

		cos_j2 = (k2 * L + k1 * H) / (k1 * k1 + k2 * k2);
		sin_j2 = (sqrt(1 - (cos_j2) * (cos_j2)));

		j2 = atan((sin_j2) / (cos_j2)) * 57.3;
		j4 = j_sum * 57.3 - j2 - j3;

		if (j2 >= 0 && j3 >= 0 && j4 >= -90 && j2 <= 180 && j3 <= 180 && j4 <= 90)
		{
			m++;
			if (m == n / 2 || m == (n + 1) / 2)
				break;
		}
	}
	target_angle_1 = j1;
	target_angle_2 = j2;
	target_angle_3 = j3;
	target_angle_4 = j4;

	printf("center_x: %f\r\n center_y: %f\r\n taret_angle_1: %f\r\n taret_angle_2: %f\r\n taret_angle_3: %f\r\n taret_angle_4: %f\r\n", target_x, target_y, j1, j2, j3, j4);
}

int main()
{
    servo_angle_calculate(8,8,15);
    return 0;
}