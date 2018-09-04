#include <iostream>
#include <vector>

using namespace std;
/*
蛇行矩阵
【问题描述】
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
【要求】
【数据输入】本题有多组数据，每组数据由一个正整数N组成。（N不大于100）
【数据输出】
对于每一组数据，输出一个N行的蛇形矩阵。两组输出之间不要额外的空行。
矩阵三角中同一行的数字用一个空格分开。行尾不要多余的空格。
【样例输入】
5
【样例输出】
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11
*/

int main()
{
	int N;
	while (cin>>N && N>=1 && N <=100) {
		//定义二维数组
		vector<vector<int> > s(N, vector<int>(N)); //容器方式
		
		int ** a = new int *[N];  //指针方式
		for (int i = 0; i < N; i++)
			a[i] = new int[N];
		int i, j;
		a[0][0] = 1;
		for (i = 0; i < N -1; ++i)
			a[i + 1][0] = a[i][0] + i + 1;

		for (j = 1; j < N; ++j) {
			for (i = 0; i < N - j; ++i)
				a[i][j] = a[i + 1][j - 1] + 1;
		}

		for (i = 0; i < N; ++i) {
			for (j = 0; j < N - i; ++j)
				cout << a[i][j]<<" ";
			cout << endl;
		}
	}
	return 0;
}
