// 数构第二次上机.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;
#define MAXSIZE 1000
typedef struct
{
	int x;
	int y;
}Position;
typedef Position Elem;
int stackSize;
int stackTop;
Elem *stackArray;
bool  stackCreate(int maxsize)
{
	if (maxsize <= 0 || maxsize > MAXSIZE)
		return false;
	stackArray = (Elem *)malloc(maxsize * sizeof(Elem)); 
	if (!stackArray) return false;
	stackSize = maxsize;
	stackTop = 0;
	return true;
}
bool stackClear()
{
	if (stackArray)
		free(stackArray);
	stackArray = NULL;
	stackSize = 0;
	stackTop = 0;
	return true;
}
bool stackPush(const Elem &it)
{

	if (stackTop == stackSize)
		return false; 
	stackArray[stackTop++] = it; 
	return true;
}
bool stackPop(Elem &it)
{
	if (stackTop == 0)
		return false;
	it = stackArray[--stackTop]; 
	return true;
}
bool isInStack(Elem &it)
{
	int temp = stackTop;
	while (temp)
	{
		temp--;
		if ((stackArray[temp].x == it.x)&&(stackArray[temp].y==it.y))
			return true;
	}
	return false;
}
void maze(int a[][8])
{
	Position b[25] = { 0 };   //保存路径信息
	for (int i = 0; i < 8; i++)  //输出迷宫
	{
		for (int j = 0; j < 8; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	stackCreate(25);
	Position t;
	t.x = 1, t.y = 1;
	stackPush(t);
 	while (!(t.x == 6 && t.y == 6))
	{
		if (a[t.x - 1][t.y - 1] == 0)    //左上
		{
			t.x--;
			t.y--;
			if (isInStack(t))  //走到重复的路
			{
				
				a[t.x++][t.y++] = 1;//填上重复的路
			}
			else 
				stackPush(t);
		}
		else if (a[t.x][t.y - 1] == 0)   //左
		{
			t.y--;
			if (isInStack(t))  //走到重复的路
			{
				
				a[t.x][t.y++] = 1;//填上重复的路
			}
			else
				stackPush(t);
		}
		else if (a[t.x + 1][t.y - 1] == 0)//左下
		{
			t.x++;
			t.y--;
			if (isInStack(t))  //走到重复的路
			{
				
				a[t.x--][t.y++] = 1;//填上重复的路
			}
			else
				stackPush(t);
		}
		else if (a[t.x + 1][t.y] == 0)    //下
		{
			t.x++;
			if (isInStack(t))  //走到重复的路
			{
				
				a[t.x--][t.y] = 1;//填上重复的路
			}
			else
				stackPush(t);
		}
		else if (a[t.x + 1][t.y + 1]==0)   //右下
		{
			t.x++;
			t.y++;
			if (isInStack(t))  //走到重复的路
			{
				
				a[t.x--][t.y--] = 1;//填上重复的路
			}
			else
				stackPush(t);
		}
		else if (a[t.x][t.y + 1] == 0)       //右
		{
			t.y++;
			if (isInStack(t))  //走到重复的路
			{
				
				a[t.x][t.y--] = 1;//填上重复的路
			}
			else
				stackPush(t);
		}
		else if (a[t.x - 1][t.y + 1] == 0) //右上
		{
			t.x--;
			t.y++;
			if (isInStack(t))  //走到重复的路
			{
				
				a[t.x++][t.y--] = 1;//填上重复的路
			}
			else
				stackPush(t);
		}
		else if (a[t.x - 1][t.y] == 0)      //上
		{
			t.x--;
			if (isInStack(t))  //走到重复的路
			{
				
				a[t.x++][t.y] = 1;//填上重复的路
			}
			else
				stackPush(t);
		}
	}
	int m = stackTop;  //保存stackTop
	for(int i = stackTop;i>=1;i--)
	{
		stackPop(t);
		b[i] = t;
	}
	for (int i = 1; i < m; i++)
	{
		cout << "(" << b[i].x << "," << b[i].y << ")" << "->";
	}
	cout << "(" << b[m].x << "," << b[m].y << ")" << endl;
}

int main()
{
	int a[8][8] = { { 1,1,1,1,1,1,1,1 },{ 1,0,0,0,1,1,0,1 },{ 1,0,0,1,0,0,0,1 },{ 1,0,1,0,0,1,1,1 },{ 1,1,0,1,1,0,1,1 },{1,0,1,0,1,0,1,1},{1,1,0,1,0,0,0,1},{1,1,1,1,1,1,1,1} };
	maze(a);
	system("pause");
    return 0;
}

