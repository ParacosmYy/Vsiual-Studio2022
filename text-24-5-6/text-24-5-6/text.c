#include<conio.h>
#include<mmsystem.h>//������ý��ӿ�
#pragma comment(lib,"winmm.lib")
void BGM()
{

	mciSendString("open ./ww.mp3", 0, 0, 0);//Ĭ���������̨
	mciSendString("play ./ww.mp3", 0, 0, 0);
	if (0)
	{
		mciSendString("close ./ww.mp3", 0, 0, 0);
	}
}
void change()
{
	HWND hand = GetHWnd();
	SetWindowText(hand, "��ӭ�����ҵĲ���");
	int i = MessageBox(hand, "�������������", "��ʾ", MB_OKCANCEL);
	if (IDOK == i)
	{
		printf("лл���У�");
	}
	else if (IDCANCEL == i)
	{
		printf("��л���Ĺۿ���");
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
