//阿里面试在线编程 【数字串转换的最少步骤】

//给定两个长度为 n ( 0 < n <= 8 ) 的 数字串 (由1到9构成)  ，我们希望对第一个数字串做一系列如下操作：
//1、将数字串的某一位加1
//2、将数字串的某一位减1
//3、交换数字串中任意两个数字的位置
//最终使得第一个数字串变成第二个数字串， 请问最少需要多少操作。

//http://blog.csdn.net/libin_vincent/article/details/79601786

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
	char str_[8], std_[8];  //输入数字串
	cin >> str_;
	cin >> std_;

	int temp[8][8];  //定义矩阵
	int num = strlen(str_);
	for (int i = 0; i<num ; ++i) {//用两个字符串间同位差的表示矩阵
		for (int j = 0; j<num; ++j) {
			temp[i][j] = abs((int)str_[i] - (int)std_[j]);
		}
	}

	int stepNum = 0;  //操作步数
	for (int i = 0; i<num; ++i) {
		for (int j = 0; j<num; ++j) {
			if (i == j)
				continue;

			//当交换后可减少步数时进行交换操作
			if ((temp[i][j] == 0 || temp[i][j] == 1) &&
			(temp[j][j] + temp[i][i]) > (temp[j][i] + 1)) {
				for (size_t k = 0; k < num ; ++k) {
					swap(temp[i][k], temp[j][k]);
				}
				stepNum = stepNum + 1;
			}
		}
	}
	//计算对角线上的和
	for (int p = 0; p < num; ++p)
		stepNum  += temp[p][p];
	cout << stepNum << endl;
}