// bubblesort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
}
void swap(int a, int b) {
	int tem;
	tem = a;
	a = b;
	b = tem;
}
void bubblesort1A(int A[], int n) {
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < n; ++i) {
			swap(A[i], A[i + 1]);
			sorted = false;
		}
		n--;
	}
}
//bubblesort2浮点数和整数皆可使用
template<typename T> //该句放在要使用的后面而不是最前面
void bubblesort2(T arr[], int len) {
	int i, j; T tem;
	for (i = 0; i < len; ++i) {
		for (j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;
			}
		}
	}

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
