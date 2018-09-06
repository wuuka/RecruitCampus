#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	int *bin = new int[N];
	for (int i = 0; i < N; i++)
		cin >> bin[i];

	int max = 0;
	for (int i = 0; i < N - K; i++) {

		int flag = 0, k = 0;  //每次移动一位进行统计开头最长的串
		for (int j = i; j < N; j++) {

			if (k > K) //添加K次空
				break;

			if (bin[j] == 1)
				flag++;
			else
				k++;
		}

		if ((flag + K) > max) {
			max = flag + K;
		}	
	}
	cout << max;
	return 0;
}
