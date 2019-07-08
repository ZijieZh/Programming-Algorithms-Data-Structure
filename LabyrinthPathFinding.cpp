// LabyrinthPathFinding.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stack>
int main()
{
    std::cout << "Hello World!\n"; 
}
typedef enum {AVAILABLE,ROUTE,BACKTRACKED,WALL}Status;
typedef enum {UNKNOW,EAST,SOUTH,WEST,NORTH,NO_WAY}ESWN;
inline ESWN nextESWN(ESWN eswn) { return ESWN(eswn + 1); }
struct Cell {
	int x, y; Status status;
	ESWN incoming, outgoing;
};
#define LABY_MAX 24
Cell laby[LABY_MAX][LABY_MAX];
inline Cell*neighbor(Cell* cell) {
	switch (cell->outgoing) {
	case EAST:	return cell + LABY_MAX;
	case SOUTH:	return cell + 1;
	case WEST:	return cell - LABY_MAX;
	case NORTH:	return cell - 1;
	default:exit(-1);
	}		
}

inline Cell*advanced(Cell*cell) {
	Cell* next;
	switch (cell->outgoing) {
	case EAST: next = cell + LABY_MAX;	next->incoming = WEST;	break;
	case SOUTH:next = cell + 1;			next->incoming = NORTH;	break;
	case WEST: next = cell - LABY_MAX;	next->incoming = EAST;	break;
	case NORTH:next = cell - 1;			next->incoming = SOUTH;	break;
	default:exit(-1);
	}
	return next;	
}

bool labyrinth(Cell Laby[LABY_MAX][LABY_MAX], Cell*s, Cell*t) {
	if ((AVAILABLE != s->status) || (AVAILABLE != t->status))return false;
	Stack<Cell*>path;
	s->incoming = UNKNOW; s - status = ROUTE; path.push(s);
	do {
		Cell* c = path.top();
		if (c == t)return true;
		while (NO_WAY > (c->outgoing = nextESWN(c->outgoing)))
			if (AVAILABLE == neighbor(c)->status)break;
		if (NO_WAY <= c->outgoing) {
			c->status = BACKTRACKED; c = path.pop();
		}
		else {
			path.push(c = advance(c)); c->outgoing = UNKNOW; c->status = ROUTE;
		}
	}
}while (!path.empty());
return false;
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
