#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSum(int *arr, int n)
{
	int max = arr[0];
	int sum = 0;
	int start = 0;
	int end = 0;
	int temp = 0;
	
	for (int i = 0; i <n; ++i)
	{
		if (sum > 0)
			sum += arr[i];
		else {
			sum = arr[i];    //抛弃当前子序列
			temp = i;        //开始新的子序列搜索
		}

		if (sum > max) {     //更新最大子序列
			max = sum;
			start = temp;
			end = i;           //最大和增加，此时的i一定是最右端
		}
	}

	vector<int> maxArr;
	for (int j = start; j < end + 1; j++) {
		maxArr.push_back(arr[j]);
		cout << arr[j] << " ";
	}
	return maxArr;
}
int main() {
	int ss1[] = { -1,2,-3,12,-5,-1,9,-2 };
	int ss2[] = { -1,2,3,12,5,1,9,2 };
	int ss3[] = { -1,2,3,12,-5,-1,-9,2 };

	maxSum(ss1,8);cout << endl;
	maxSum(ss2, 8); cout << endl;
	maxSum(ss3, 8);

	return 0;
}
