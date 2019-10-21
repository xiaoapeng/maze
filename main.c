#include "画地图.h"
int X=0,Y=0;
int main()
{
	HANDLE hOut; 
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
	char ch;
	system("color e0");
	int x=0,y=0;
	system("mode con cols=178 lines=47");
	MAP map[M][N];
	Initialize_array(map);
	while(1)
	{
		a:
		HideCursor();
		system("cls");
		system("color e0");
		Pos(35,15);
		printf("1.开始探路");
		Pos(35,16);
		printf("2.绘制地图");
		Pos(35,17);
		printf("3.迷宫");
		Pos(35,18);
		printf("4.退出");
		fflush(stdin);
		while((ch=getch())!='1'&&ch!='2'&&ch!='3'&&ch!='4');
		dudang(map);
		switch(ch)
		{
			case '1':
			navigation(map);
			break;
			case '2':
			Pos(0-4,0-4);
			{
				printf("ESC 返回出\n");
				printf("F1 清空画布");
			}
			map_plotting(map);
			HideCursor();
			while(1)
			{
		
				if(GET(ss)&&Y>0)
					y--;
				else
				if(GET(xx)&&Y<N-1)
					y++;
				else
				if(GET(zz)&&X>0)
					x--;
				else
				if(GET(yy)&&X<M-1)
					x++;
				else
				if(GET(VK_ESCAPE))
				{
					cundang(map);
					goto a;
				}
				else
				if(GET(VK_F1))
				{
					Initialize_array(map);
					map_plotting(map);
				}
				Square_drawing(map,X,Y);
				X=x;
				Y=y;
				Pos(X,Y);
				GYS(hOut,0xff);
				printf("  ");
				//加内容Other building
				Other_building_A(map,X,Y);
				Sleep(100);
				
			}
			break;
			case '3':
			mg_zhidongshengcheng(map);
			navigation(map);
			break;
			case '4':
			exit(1);
			default :
			break;
			
		}
	}
		getch();
}