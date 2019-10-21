#ifndef _HANTITU_h_
#define _HANTITU_h_
#define _CRT_RAND_S 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#define M 80
#define N 40
#define GET(x) GetAsyncKeyState(x)
#define  ss VK_UP
#define  xx VK_DOWN
#define  zz VK_LEFT
#define  yy VK_RIGHT
#define GYS(x,y) SetConsoleTextAttribute(x,y)
#define xiahuaxian COMMON_LVB_UNDERSCORE//下划线
#define zuowangge COMMON_LVB_GRID_LVERTICAL//左网格
#define youwangge COMMON_LVB_GRID_RVERTICAL//右网格

typedef struct lailailai
{
	int ID;//是否为路还是建筑的标记
	int color;//颜色包含前景和背景
	char ch[8];//形状
	struct lailailai *next;//占位，同理
}MAP;
typedef struct hahaha//该链表用于存储广度优先搜索的路径
{
	int x,y;
	struct hahaha *next;//next
	struct hahaha *ld_next;//列队的next
}LB;
typedef struct hahahahaha//该列队用于存储广搜的先后关系
{
	LB *front;
	LB *rear;
}LD;
extern int X,Y;
extern int jilu[M][N];//该二维数组记录结点是否已经遍历
extern LD kkk;
void Pos(int x,int y);//设置光标位置
void HideCursor(void);//隐藏光标
void Initialize_array(MAP [M][N]);//初始化数组
void map_plotting(MAP p[M][N]);//地图绘制
void dudang(MAP p[M][N]);//读档
void Square_drawing(MAP p[M][N],int a,int b);//方块绘制
void Other_building_A(MAP p[M][N],int a,int b);//添加建筑
void cundang(MAP p[M][N]);//存档
void navigation(MAP p[M][N]);//导航
LB* breadth_first(int x,int y,int x1,int y1,LB *puer);//递归式广度优先搜索，传递已经遍历结点的地址方便形成链表,要寻找的结点
void rudui(LB *puer,int x,int y);
LB* chudui(void);
void lujing(LB *head,int x,int y);
void mg_zhidongshengcheng(MAP map[M][N]);

void xunzhao(MAP map[M][N],int a[2],int b[2]);
int digui_mg(MAP map[M][N],int x,int y);
unsigned int Random(int max);
#endif



