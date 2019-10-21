#include "画地图.h"
int jilu[M][N]={0};
LD kkk;
int mm;
LB *ppp[2000];//用于最后释放申请的内存
int gg=0;
void Pos(int x,int y)
{
	x+=4;
	y+=4;
	COORD pos;
	HANDLE hOutput;
	pos.X=2*x;
	pos.Y=y;
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,pos);
}
void HideCursor(void)
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void Initialize_array(MAP p[M][N])
{
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			p[i][j].ID=-1;
			p[i][j].color=0x67;
			strcpy(p[i][j].ch,"▓");
		}
}
void map_plotting(MAP p[M][N])
{
	HANDLE hOut; 
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
	for(int i=M-1;i>=0;i--)
		for(int j=0;j<N;j++)
		{
			Square_drawing(p,i,j);
		}
}
void Square_drawing(MAP p[M][N],int a,int b)//打印方块
{
	HANDLE hOut; 
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
	GYS(hOut,p[a][b].color);
	Pos(a,b);
	printf(p[a][b].ch);
}
void Other_building_A(MAP p[M][N],int a,int b)
{
	int v=10000;
	if(GET('1')& 0x8000)
		v=1;
	else
	if(GET('2'))
		v=2;
	else
	if(GET('3'))
		v=3;
	else
	if(GET('4'))
		v=4;
	else
	if(GET('5'))
		v=5;
	else
	if(GET('6'))
		v=6;
	else
	if(GET('7'))
		v=7;
	else
	if(GET('8'))
		v=8;
	else
	if(GET('E'))
		v=9;
	else
	if(GET('0'))
		v=0;
	else
	if(GET('Z'))
		v=10;
	else
	if(GET('X'))
		v=11;
	else
	if(GET('C'))
		v=12;
	else
	if(GET('V'))
		v=13;
	else
	if(GET('B'))
		v=14;
	else
	if(GET('N'))
		v=15;
	else
	if(GET('M'))
		v=16;
	else
		
	if(GET('A'))
		v=17;
	else
	if(GET('S'))
		v=18;
	else
	if(GET('D'))
		v=19;
	else
	if(GET('F'))
		v=20;
	else
	if(GET('G'))
		v=21;
	else
	if(GET('H'))
		v=22;
	else
	if(GET('J'))
		v=23;
	else
	if(GET('K'))
		v=24;
	else
	if(GET('L'))
		v=25;
	switch(v)
	{
		case 0:
		p[a][b].ID=0;
		p[a][b].color=0x94;
		strcpy(p[a][b].ch,"[]");
		break;
		case 1:
		p[a][b].ID=0;
		p[a][b].color=0xe1;
		strcpy(p[a][b].ch,"卐");
		break;
		case 2:
		p[a][b].ID=-1;
		p[a][b].color=0x69;
		strcpy(p[a][b].ch,"〓");
		break;
		case 3:
		p[a][b].ID=0;
		p[a][b].color=0xa8;
		strcpy(p[a][b].ch,"♀");
		break;
		case 9:
		p[a][b].ID=0;
		p[a][b].color=0x2a;
		strcpy(p[a][b].ch,"▓");
		break;
		case 4:
		p[a][b].ID=0;
		p[a][b].color=0x90;
		strcpy(p[a][b].ch,"※");
		break;
		case 5:
		p[a][b].ID=0;
		p[a][b].color=0xf9;
		strcpy(p[a][b].ch,"▋");
		break;
		case 6:
		p[a][b].ID=0;
		p[a][b].color=0x78;
		strcpy(p[a][b].ch,"◥");
		break;
		case 7:
		p[a][b].ID=0;
		p[a][b].color=0xc3;
		strcpy(p[a][b].ch,"∷");
		break;
		case 8:
		p[a][b].ID=-1;
		p[a][b].color=0x67;
		strcpy(p[a][b].ch,"▓");
		break;
		case 10:
		p[a][b].ID=1;
		p[a][b].color=0x8f;
		strcpy(p[a][b].ch,"教学楼");
		break;
		case 11:
		p[a][b].ID=1;
		p[a][b].color=0x6f;
		strcpy(p[a][b].ch,"饭堂");
		break;
		case 12:
		p[a][b].ID=1;
		p[a][b].color=0x1f;
		strcpy(p[a][b].ch,"宿舍楼");
		break;
		case 13:
		p[a][b].ID=1;
		p[a][b].color=0x8f;
		strcpy(p[a][b].ch,"图书馆");
		break;
		case 14:
		p[a][b].ID=1;
		p[a][b].color=0xa0;
		strcpy(p[a][b].ch,"体育场");
		break;
		case 15:
		p[a][b].ID=1;
		p[a][b].color=0x8f;
		strcpy(p[a][b].ch,"医院");
		break;
		case 16:
		p[a][b].ID=1;
		p[a][b].color=0x8f;
		strcpy(p[a][b].ch,"商业街");
		break;
		case 17:
		p[a][b].ID=0;
		p[a][b].color=0x11;
		strcpy(p[a][b].ch,"  ");
		break;
		case 18:
		p[a][b].ID=0;
		p[a][b].color=0x22;
		strcpy(p[a][b].ch,"  ");
		break;
		case 19:
		p[a][b].ID=0;
		p[a][b].color=0x33;
		strcpy(p[a][b].ch,"  ");
		break;
		case 20:
		p[a][b].ID=0;
		p[a][b].color=0x44;
		strcpy(p[a][b].ch,"  ");
		break;
		case 21:
		p[a][b].ID=0;
		p[a][b].color=0x55;
		strcpy(p[a][b].ch,"  ");
		break;
		case 22:
		p[a][b].ID=0;
		p[a][b].color=0x66;
		strcpy(p[a][b].ch,"  ");
		break;
		case 23:
		p[a][b].ID=0;
		p[a][b].color=0x77;
		strcpy(p[a][b].ch,"  ");
		break;
		case 24:
		p[a][b].ID=0;
		p[a][b].color=0x88;
		strcpy(p[a][b].ch,"  ");
		break;
		case 25:
		p[a][b].ID=0;
		p[a][b].color=0x99;
		strcpy(p[a][b].ch,"  ");
		default :
		break;
	}
}
void dudang(MAP p[M][N])
{
	bool a=false;
	FILE *fp;
	fp=fopen("地图.data","r");
	if(fread(&a,sizeof(bool),1,fp)==0)
	{
		fclose(fp);
		return ;
	}
	else
	{
		fread(p,sizeof(MAP),M*N,fp);
	}
	fclose(fp);
	
}
void cundang(MAP p[M][N])
{
	bool a=false;
	FILE *fp;
	fp=fopen("地图.data","w");
	fwrite(&a,sizeof(bool),1,fp);
	fwrite(p,sizeof(MAP),M*N,fp);
	fclose(fp);
}
void navigation(MAP map[M][N])
{
	int X=6;
	int Y=9;
	int x=6,y=9;
	HANDLE hOut; 
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	map_plotting(map);
	HideCursor();
	int a[2]={-1,-1},b[2]={-1,-1};
	char s[2][100]={"请选择您的位置<按空格结束>","请选择您的目的地<按空格结束,请不要和起点在同一条线上>"};
	for(int i=0;i<2;i++)
    {
		Pos(-4,-4);
		GYS(hOut,0xe0);
		printf("%s",s[i]);
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
			if(GET(VK_SPACE)&&(a[0]!=x||b[0]!=y)&&map[X][Y].ID==-1)
			{
				a[i]=x;
				b[i]=y;
				break;
			}
			Square_drawing(map,X,Y);
			X=x;
			Y=y;
			Pos(X,Y);
			GYS(hOut,0xff);
			printf("  ");
			Sleep(100);
		}
	//	stpcpy(map[a[0][(b[0])].ch,"起");
	}
	xunzhao(map,a,b);
	Pos(-4,-3);
	GYS(hOut,0xe0);
	if(mm!=0)
		printf("一共%d米，需要%f分钟\n",mm*2,(double)mm*2/(double)60);
	else
		printf("未找到\n");
	system("pause");
}
void xunzhao(MAP map[M][N],int a[2],int b[2])
{
	mm=0;
	for(int i=0;i<M;i++)
		for(int  j=0;j<N;j++)
		{
			if(map[i][j].ID!=-1)
			{
				jilu[i][j]=1;//不能遍历以及已经遍历的结点赋值为1；
			}
			else
			{
				jilu[i][j]=0;
			}
		}
	LB *puer;
	ppp[gg++]=puer=(LB*)malloc(sizeof(LB));
	puer->next=NULL;
	puer->x=a[0];
	puer->y=b[0];
	LB *head=NULL;
	ppp[gg++]=kkk.front=kkk.rear=(LB*)malloc(sizeof(LB));
	head=breadth_first(a[0],b[0],a[1],b[1],puer);
	map_plotting(map);
	lujing(head,0,0);
	for(int i=0;i<gg;i++)
	{
		free(ppp[i]);
	}
	gg=0;
	Pos(-4,-3);
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			jilu[i][j]=0;
		}
	
	
}
LB* breadth_first(int x,int y,int x1,int y1,LB *puer)
{
	HANDLE hOut; 
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Sleep(10);
	LB *p=NULL,*q=NULL;
	Pos(x,y);
	GYS(hOut,0xaa);
	printf("  ");
	jilu[x][y]=1;
	if(x1==x&&y1==y)
	{
		return puer;
	}
	else
	{
		/* if(jilu[x+1][y+1]==0&&x<M-1&&y<N-1)
		{
			jilu[x+1][y+1]=1;
			rudui(puer,x+1,y+1);
		} */
		if(jilu[x][y-1]==0&&y>0)
		{
			jilu[x][y-1]=1;
			rudui(puer,x,y-1);
		}
		/* if(jilu[x-1][y+1]==0&&x>0&&y<N-1)
		{
			jilu[x-1][y+1]=1;
			rudui(puer,x-1,y+1);
		} */
		if(jilu[x+1][y]==0&&x<M-1)
		{
			jilu[x+1][y]=1;
			rudui(puer,x+1,y);
		}
		/* if(jilu[x+1][y-1]==0&&x<M-1&&y>0)
		{
			jilu[x+1][y-1]=1;
			rudui(puer,x+1,y-1);
		} */
		if(jilu[x][y+1]==0&&y<N-1)
		{
			jilu[x][y+1]=1;
			rudui(puer,x,y+1);
		}
		if(jilu[x-1][y]==0&&x>0)
		{
			jilu[x-1][y]=1;
			rudui(puer,x-1,y);
		}
		/* if(jilu[x-1][y-1]==0&&x>0&&y>0)
		{
			jilu[x-1][y-1]=1;
			rudui(puer,x-1,y-1);
		} */
		while(kkk.front!=kkk.rear)
		{
			p=chudui();
			q=breadth_first(p->x,p->y,x1,y1,p);
			if(q!=NULL)
				return q;
		}
		return NULL;
	}
}
void rudui(LB *puer,int x,int y)
{
	LB *p=NULL;
	ppp[gg++]=p=(LB*)malloc(sizeof(LB));
	kkk.rear->x=x;
	kkk.rear->y=y;
	kkk.rear->next=puer;
	kkk.rear->ld_next=p;
	p->ld_next=NULL;
	p->next=NULL;
	kkk.rear=p;
}
LB* chudui(void)
{
	LB *p=kkk.front;
	kkk.front=kkk.front->ld_next;
	return p;
}
void lujing(LB *head,int x,int y)
{
	static HANDLE hOut; 
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if(head!=NULL)
	{
		mm++;
		lujing(head->next,head->x,head->y);
		GYS(hOut,0xe0);
		Pos(head->x,head->y);
		if(x==y&&x==0)
		{
			printf("终");
		}
		else
		if(head->x+1==x&&head->y==y)
		{
			printf("→");
		}
		else
		if(head->x==x&&head->y+1==y)
		{
			printf("↓");
		}
		else
		if(head->x==x&&head->y-1==y)
		{
			printf("↑");
		}
		else
		if(head->x-1==x&&head->y==y)
		{
			printf("←");
		}
	}
}
void mg_zhidongshengcheng(MAP map[M][N])
{
	Initialize_array(map);//初始化数组

	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			jilu[i][j]=0;
			map[i][j].ID=1;
		}
	map_plotting(map);//地图绘制
	int x=1,y=1;
	digui_mg(map,x,y);
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			if(map[i][j].ID==-1)
			{
				map[i][j].color=0xfe;
			}
			else
			{
				map[i][j].color=0x88;
				strcpy(map[i][j].ch,"[]");
				
			}
		}
}
unsigned int Random(int max) 
{ 
   errno_t err; 
   unsigned int number; 
   err = rand_s(&number); 
   if(err != 0) 
   { 
     return 0;
   } 
   return (unsigned int)(double)number ; 
}
int digui_mg(MAP map[M][N],int x,int y)
{
	//srand(GetCpuCycle(NULL));
	LB* puer=NULL,*p;
	map[x][y].ID=-1;
	jilu[x][y]=1;
	Pos(x,y);
	printf("  ");
	Sleep(10);
	tt:
	if((jilu[x][y-1]==0&&y>1&&jilu[x][y-2]==0&&jilu[x+1][y-1]==0&&jilu[x-1][y-1]==0&&jilu[x-1][y-2]==0&&jilu[x+1][y-2]==0)||
		(jilu[x][y+1]==0&&y<N-2&&jilu[x][y+2]==0&&jilu[x+1][y+1]==0&&jilu[x-1][y+1]==0&&jilu[x-1][y+2]==0&&jilu[x+1][y+2]==0)||
		(jilu[x+1][y]==0&&x<M-2&&jilu[x+2][y]==0&&jilu[x+1][y-1]==0&&jilu[x+1][y+1]==0&&jilu[x+2][y+1]==0&&jilu[x+2][y-1]==0)||
		(jilu[x-1][y]==0&&x>1&&jilu[x-2][y]==0&&jilu[x-1][y-1]==0&&jilu[x-1][y+1]==0&&jilu[x-2][y+1]==0&&jilu[x-2][y-1]==0)
		)
		{
			ll:
			switch(Random(10)%4)
			{
				case 0:
				if(jilu[x][y-1]==0&&y>1&&jilu[x][y-2]==0&&jilu[x+1][y-1]==0&&jilu[x-1][y-1]==0&&jilu[x-1][y-2]==0&&jilu[x+1][y-2]==0)
				{
					digui_mg(map,x,y-1);
					goto tt;
				}
				else
				{
					goto ll;
				}
				break;
				case 1:
				if(jilu[x][y+1]==0&&y<N-2&&jilu[x][y+2]==0&&jilu[x+1][y+1]==0&&jilu[x-1][y+1]==0&&jilu[x-1][y+2]==0&&jilu[x+1][y+2]==0)
				{
					digui_mg(map,x,y+1);
					goto tt;
				}
				else
				{
					goto ll;
				}
				break;
				case 2:
				if(jilu[x+1][y]==0&&x<M-2&&jilu[x+2][y]==0&&jilu[x+1][y-1]==0&&jilu[x+1][y+1]==0&&jilu[x+2][y+1]==0&&jilu[x+2][y-1]==0)
				{
					digui_mg(map,x+1,y);
					goto tt;
				}
				else
				{
					goto ll;
				}
				break;
				case 3:
				if(jilu[x-1][y]==0&&x>1&&jilu[x-2][y]==0&&jilu[x-1][y-1]==0&&jilu[x-1][y+1]==0&&jilu[x-2][y+1]==0&&jilu[x-2][y-1]==0)
				{
					digui_mg(map,x-1,y);
					goto tt;
				}
				else
				{
					goto ll;
				}
				break;
			}
		}
		else
		{
			return ;
		}
				
}

	
	
	
	
	
	
	
	

