#include<iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int suu(vector<char> &ss, int N) {
	int o_num = 0;
	for (int i = 0; i < N; i++) {

		if (ss[i] == 'x') {  //每列当遇到障碍物时，当前标志不变。统计之前的‘o’个数添加在“x”前。
			for (int ol = 1; ol < o_num + 1; ol++) {
				ss[i - ol] = 'o';
			}
			o_num = 0;
		}
		else if (ss[i] == 'o') {
			o_num = o_num + 1;
			ss[i] = '.';
		}
		else {
			ss[i] = '.';
		}
	}
	return 0;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> chessboard_N;  //输入
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		chessboard_N.push_back(s);
	}
	vector<vector<char>> chessboard_M;
	for (int j = 0; j < M; j++) {
		vector<char> ss;
		for (int k = 0; k < N; k++) {
			string tt = chessboard_N[k];
			ss.push_back(tt[j]);
		}
		suu(ss, N);  //每列查找
		chessboard_M.push_back(ss);
	}
	for (int n = 0; n < N; n++) {  //输出
		for (int m = 0; m < M; m++) {
			cout << chessboard_M[m][n];
		}
		cout << endl;
	}
	return 0;
}
