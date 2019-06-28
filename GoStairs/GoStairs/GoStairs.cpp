// GoStairs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//爬楼梯，树老师爬N阶楼梯，每次爬一阶或者两阶。求共有几种走法。f(n)=f(n-1)+f(n-2);

#include "pch.h"
#include <iostream>
using namespace std;
int N;
int Gostairs(int n);
int main()
{
	while (cin >> N) {
		cout << Gostairs(N) << endl;
	}
}
int Gostairs(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	
	return Gostairs(n - 1) + Gostairs(n - 2);;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
