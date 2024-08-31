#include<conio.h>
#include<mmsystem.h>//包含多媒体接口
#pragma comment(lib,"winmm.lib")
void BGM()
{

	mciSendString("open ./ww.mp3", 0, 0, 0);//默认输出控制台
	mciSendString("play ./ww.mp3", 0, 0, 0);
	if (0)
	{
		mciSendString("close ./ww.mp3", 0, 0, 0);
	}
}
void change()
{
	HWND hand = GetHWnd();
	SetWindowText(hand, "欢迎来到我的博客");
	int i = MessageBox(hand, "请留下你的三连", "提示", MB_OKCANCEL);
	if (IDOK == i)
	{
		printf("谢谢大佬！");
	}
	else if (IDCANCEL == i)
	{
		printf("感谢您的观看！");
	}
}
int main()
{
	initgraph(500, 500, SHOWCONSOLE);
	setbkcolor(WHITE);

	cleardevice();
	change();

	getchar();
	closegraph();
	return 0;
}
